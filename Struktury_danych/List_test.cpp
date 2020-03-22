#include"inc/List.hh"

int main()
{
	const List<char> lista1 = { 'a', 'b', 'b', 'a' };
	List<char> lista2 = lista1;
	List<int> lista3;

	for(unsigned int i = 0; i < lista1.size(); i++)
		std::cout << lista1[i] << " ";
	std::cout << "\n";
	lista2.push_front('d');
	lista2.push_back('e');
	lista2.insert('c', 3);
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
	
	lista3.remove_by_index(1);

	for( auto it = lista3.begin(); it != lista3.end() ; it++)
		std::cout << *it << " ";
	std::cout << "\n";

	List<std::string> lista4 = { "ala", "ma", "kota" };
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
