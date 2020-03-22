#include"inc/Stack.hh"

int main()
{
	const Stack<int> stos1= { 1, 4, 2, 3, 5};
	Stack<int> stos2 = stos1;
	Stack<std::string> stos3;

	for(auto it = stos1.cbegin(); it != stos1.cend(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	for(auto it = stos2.cbegin(); it != stos2.cend(); it++)
		std::cout << *it << " ";
	
	std::cout << "\n";
	stos2.push(8);
	for(auto it = stos2.cbegin(); it != stos2.cend(); it++)
		std::cout << *it << " ";
	stos2.pop();
	std::cout << "\n";

	for(auto it = stos2.cbegin(); it != stos2.cend(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << stos3.empty();
	stos3.push("pierwszy");
	std::cout <<  " " << stos3.empty() << "\n";
	stos3.push("drugi");
	stos3.push("trzeci");

	std::cout << stos3.top() << "\n";

	for(auto it = stos3.cbegin(); it != stos3.cend(); it++)
		std::cout << *it << " ";
	return 0;
}
