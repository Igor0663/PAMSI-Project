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
matrix<T> strassen_mult(const matrix<T>& A, const matrix<T>& B, unsigned int pow)
{
	if(pow == 1)
	{
		return A * B;
	}

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
	matrix<T> A1122 = A11 + A22, B1122 = B11 + B22;
	future< matrix<T> > resultM1 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A1122, B1122, pow/2);
	//matrix<T> M1 = strassen_mult(A1122, B1122, pow/2);
	
	matrix<T> A2122 = A21 + A22;
	future< matrix<T> > resultM2 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A2122, B11, pow/2);
	//matrix<T> M2 = strassen_mult(A2122, B11, pow/2);
	
	matrix<T> B12m22 = B12 - B22;
	future< matrix<T> > resultM3 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A11, B12m22, pow/2);
	//matrix<T> M3 = strassen_mult(A11, B12m22, pow/2);

	matrix<T> B21m11 = B21 - B11;
	future< matrix<T> > resultM4 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A22, B21m11, pow/2);
	//matrix<T> M4 = strassen_mult(A22, B21m11, pow/2);

	matrix<T> A1112 = A11 + A12;
	future< matrix<T> > resultM5 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A1112, B22, pow/2);
	//matrix<T> M5 = strassen_mult(A1112, B22, pow/2);

	matrix<T> A21m11 = A21 - A11, B1112 = B11 + B12;
	future< matrix<T> > resultM6 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A21m11, B1112, pow/2);
	//matrix<T> M6 = strassen_mult(A21m11, B1112, pow/2);

	matrix<T> A12m22 = A12 - A22, B2122 = B21 + B22;
	future< matrix<T> > resultM7 = async(launch::async, static_cast<matrix<T>(*)(const matrix<T>&, const matrix<T>&, unsigned int)>(&strassen_mult), A12m22, B2122, pow/2);
	//matrix<T> M7 = strassen_mult(A12m22, B2122, pow/2);

	matrix<T> M1 = resultM1.get();
	matrix<T> M2 = resultM2.get();
	matrix<T> M3 = resultM3.get();
	matrix<T> M4 = resultM4.get();
	matrix<T> M5 = resultM5.get();
	matrix<T> M6 = resultM6.get();
	matrix<T> M7 = resultM7.get();

	matrix<T> C11 = M1 + M4 - M5 + M7;
	matrix<T> C12 = M3 + M5;
	matrix<T> C21 = M2 + M4;
	matrix<T> C22 = M1 - M2 + M3 + M6;

	matrix<T> C(pow, pow);
	for(unsigned int i = 0; i < C.size().first; i++)
		for(unsigned int j = 0; j < C.size().second; j++)
		{
			if(i < pow/2 and j < pow/2)
				C(i, j) = C11(i, j);
			else if(i < pow/2 and j >= pow/2)
				C(i, j) = C12(i, j - pow/2);
			else if(i >= pow/2 and j < pow/2)
				C(i, j) = C21(i - pow/2, j);
			else
				C(i, j) = C22(i - pow/2, j - pow/2);
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

	std::cout << "Mult time:     " << mult_time.count() << "seconds\n";
	std::cout << "Strassen time: " << strassen_time.count() << "seconds\n";
	return 0;
}
