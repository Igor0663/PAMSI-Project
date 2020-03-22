#include"inc/HashMap.hh"

int main()
{
	HashMap<std::string, int > mapa = {{"Krzysztof", 21}, {"Emilia", 20}, {"Agatka", 18} };
	std::cout << mapa.size() << " " << mapa.number_of_buckets() << "\n";
	std::cout << mapa["Agatka"] << "\n";
	mapa.insert("Piotrek", 8 );
	std::cout << mapa["Piotrek"] << "\n";
	mapa["Emilia"] = 19;
	std::cout << mapa["Emilia"] << "\n";
	mapa.remove("Krzysztof");
	std::cout << mapa["Krzysztof"];
	return 0;
}
