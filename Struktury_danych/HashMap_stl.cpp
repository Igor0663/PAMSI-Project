#include"map"
#include<iostream>
using namespace std;
int main()
{
	map<string, int > mapa = {{"Krzysztof", 21}, {"Emilia", 20}, {"Agatka", 18} };
	cout << mapa.size() << "\n";
	cout << mapa["Agatka"] << "\n";
	mapa["Piotrek"] = 8;
	cout << mapa["Piotrek"] << "\n";
	mapa["Emilia"] = 19;
	cout << mapa["Emilia"] << "\n";
	mapa.erase(mapa.find("Krzysztof"));
	cout << mapa["Krzysztof"];
	return 0;
}
