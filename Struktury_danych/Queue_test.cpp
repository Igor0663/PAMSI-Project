#include"inc/Queue.hh"

int main()
{
	const Queue<int> kolejka1= { 1, 4, 2, 3, 5};
	Queue<int> kolejka2 = kolejka1;
	Queue<std::string> kolejka3;

	for(auto it = kolejka1.cbegin(); it != kolejka1.cend(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	for(auto it = kolejka2.cbegin(); it != kolejka2.cend(); it++)
		std::cout << *it << " ";
	
	std::cout << "\n";
	kolejka2.push(8);
	for(auto it = kolejka2.cbegin(); it != kolejka2.cend(); it++)
		std::cout << *it << " ";
	kolejka2.pop();
	std::cout << "\n";

	for(auto it = kolejka2.cbegin(); it != kolejka2.cend(); it++)
		std::cout << *it << " ";
	std::cout << "\n";

	std::cout << kolejka3.empty();
	kolejka3.push("pierwszy");
	std::cout <<  " " << kolejka3.empty() << "\n";
	kolejka3.push("drugi");
	kolejka3.push("trzeci");

	std::cout << kolejka3.front() << "\n";

	for(auto it = kolejka3.cbegin(); it != kolejka3.cend(); it++)
		std::cout << *it << " ";
	return 0;
}
