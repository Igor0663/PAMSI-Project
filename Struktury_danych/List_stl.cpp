#include<list>
#include<iostream>
using namespace std;

int main()
{
	const list<char> lista1 = { 'a', 'b', 'b', 'a' };
	list<char> lista2 = lista1;
	list<int> lista3;

	for(auto it = lista1.begin(); it != lista1.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	lista2.push_front('d');
	lista2.push_back('e');
	auto it = lista2.begin();
	advance(it, 3);
	lista2.insert(it, 'c');
	for( auto it = lista2.begin(); it != lista2.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << lista3.empty() << "\n";
	lista3.push_back(2);
	std::cout << lista3.empty() << "\n";
	lista3.push_front(8);
	lista3.push_front(2);
	lista3.push_front(1);
	for( auto it = lista3.begin(); it != lista3.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";
	lista3.remove(2);

	for( auto it = lista3.begin(); it != lista3.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";
	
	int a = lista3.front();
	lista3.pop_front();
	lista3.pop_front();
	lista3.push_front(a);

	for( auto it = lista3.begin(); it != lista3.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";

	list<std::string> lista4 = { "ala", "ma", "kota" };
	lista4.pop_back();


	for( auto it = lista4.begin(); it != lista4.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";
	lista4.pop_front();


	for( auto it = lista4.begin(); it != lista4.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";
	return 0;
}
