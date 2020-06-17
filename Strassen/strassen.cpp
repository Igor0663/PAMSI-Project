#include<iostream>
#include<thread>
#include<future>
#include<chrono>
#include"matrix.hh"

using namespace std;


template<typename T>
void read_input(matrix<T>& A, matrix<T>& B)
{
	unsigned int N, M;
	cin >> N >> M;
	A = matrix<T>(N, M);
	for(unsigned int i = 0; i < N; i++)
		for(unsigned int j = 0; j < M; j++)
			cin >> A(i, j);	

	cin >> N >> M;
	B = matrix<T>(N, M);
	for(unsigned int i = 0; i < N; i++)
		for(unsigned int j = 0; j < M; j++)
			cin >> B(i, j);
	return;
}

template<typename T>
matrix<T> strassen_mult(const matrix<T>& A, const matrix<T>& B, unsigned int pow, bool top = true)
{
	if(pow <= 32)
		return A * B;

	matrix<T> A11(pow/2, pow/2);
	matrix<T> A12(pow/2, pow/2);
	matrix<T> A21(pow/2, pow/2);
	matrix<T> A22(pow/2, pow/2);

	matrix<T> B11(pow/2, pow/2);
	matrix<T> B12(pow/2, pow/2);
	matrix<T> B21(pow/2, pow/2);
	matrix<T> B22(pow/2, pow/2);

	for(unsigned int i = 0; i < pow/2; i++)
		for(unsigned int j = 0; j < pow/2; j++)
		{
			A11(i, j) = A(i, j);
			A12(i, j) = A(i, j + pow/2);
			A21(i, j) = A(i + pow/2, j);
			A22(i, j) = A(i + pow/2, j + pow/2);

			B11(i, j) = B(i, j);
			B12(i, j) = B(i, j + pow/2);
			B21(i, j) = B(i + pow/2, j);
			B22(i, j) = B(i + pow/2, j + pow/2);
		}
	matrix<T> M1;
	matrix<T> M2;
	matrix<T> M3;
	matrix<T> M4;
	matrix<T> M5;
	matrix<T> M6;
	matrix<T> M7;
	
	matrix<T> A1122 = A11 + A22, B1122 = B11 + B22;
	matrix<T> A2122 = A21 + A22;
	matrix<T> B12m22 = B12 - B22;
	matrix<T> B21m11 = B21 - B11;
	matrix<T> A1112 = A11 + A12;
	matrix<T> A21m11 = A21 - A11, B1112 = B11 + B12;
	matrix<T> A12m22 = A12 - A22, B2122 = B21 + B22;
	
	if(top)
	{
		auto resultM1 = async(&strassen_mult<T>, A1122, B1122, pow/2, false);
		auto resultM2 = async(&strassen_mult<T>, A2122, B11, pow/2, false);
		auto resultM3 = async(&strassen_mult<T>, A11, B12m22, pow/2, false);
		auto resultM4 = async(&strassen_mult<T>, A22, B21m11, pow/2, false);
		auto resultM5 = async(&strassen_mult<T>, A1112, B22, pow/2, false);
		auto resultM6 = async(&strassen_mult<T>, A21m11, B1112, pow/2, false);
		auto resultM7 = async(&strassen_mult<T>, A12m22, B2122, pow/2, false);

		M1 = resultM1.get();
		M2 = resultM2.get();
		M3 = resultM3.get();
		M4 = resultM4.get();
		M5 = resultM5.get();
		M6 = resultM6.get();
		M7 = resultM7.get();
	}
	else
	{
		M1 = strassen_mult(A1122, B1122, pow/2, false);
		M2 = strassen_mult(A2122, B11, pow/2, false);
		M3 = strassen_mult(A11, B12m22, pow/2, false);
		M4 = strassen_mult(A22, B21m11, pow/2, false);
		M5 = strassen_mult(A1112, B22, pow/2, false);
		M6 = strassen_mult(A21m11, B1112, pow/2, false);
		M7 = strassen_mult(A12m22, B2122, pow/2, false);
	}

	matrix<T> C(pow, pow);
	for(unsigned int i = 0; i < C.size().first; i++)
		for(unsigned int j = 0; j < C.size().second; j++)
		{
			if(i < pow/2 and j < pow/2)
				C(i, j) = M1(i, j) + M4(i, j) - M5(i, j) + M7(i, j);
			else if(i < pow/2 and j >= pow/2)
				C(i, j) = M3(i, j - pow/2) + M5(i, j - pow/2);
			else if(i >= pow/2 and j < pow/2)
				C(i, j) = M2(i - pow/2, j) + M4(i - pow/2, j);
			else
				C(i, j) = M1(i - pow/2, j - pow/2) - M2(i - pow/2, j - pow/2) + M3(i - pow/2, j - pow/2) + M6(i - pow/2, j - pow/2);

		}
	return C;
}

template<typename T>
matrix<T> strassen( matrix<T> A, matrix<T> B)
{
	if(A.size().second != B.size().first)
	{
		cerr << "Dimensions don't match! Cannot multiply";
		return A;
	}
	unsigned int max_dim = max(max(A.size().first, A.size().second), max(B.size().first, B.size().second));
	unsigned int pow2 = 1;
	pair<unsigned int, unsigned int> C_dim = {A.size().first, B.size().second};

	while( pow2 < max_dim)
		pow2 *= 2;

	A.resize(pow2, pow2);
	B.resize(pow2, pow2);
	matrix<T> C = strassen_mult(A, B, pow2);
	C.resize(C_dim.first, C_dim.second);
	return C;
}


int main()
{
	matrix<int> A, B, C_strassen, C;
	read_input(A, B);

	cout << "Multiplying...\n";	
	
	auto strassen_start = chrono::steady_clock::now();
	C_strassen = strassen(A, B);
	auto strassen_end = chrono::steady_clock::now();
	
	auto mult_start = chrono::steady_clock::now();
	C = A * B;
	auto mult_end = chrono::steady_clock::now();

	auto strassen_time = chrono::duration_cast<chrono::seconds>(strassen_end - strassen_start);
	auto mult_time = chrono::duration_cast<chrono::seconds>(mult_end - mult_start);

	cout << "Mult time:     " << mult_time.count() << "seconds\n";
	cout << "Strassen time: " << strassen_time.count() << "seconds\n";
	//cout << "\n" << C_strassen;
	return 0;
}
