#include"inc/Priority_queue.hh"

int main()
{
	Priority_queue<int> kopiec1;
	std::cout << kopiec1.empty();
	kopiec1.push(1);
	std::cout << " " << kopiec1.empty() << "\n";
	kopiec1.push(2);
	kopiec1.push(2);
	kopiec1.push(8);
	kopiec1.push(-4);
	kopiec1.push(5);
	kopiec1.push(1);
	std::cout << kopiec1.top() << "\n";

	Priority_queue<int> kopiec2 = kopiec1;

	while(!kopiec1.empty())
		std::cout << kopiec1.pop() << " ";
	std::cout << "\n";
	kopiec2.pop();
	while(kopiec2.size())
		std::cout << kopiec2.pop() << " ";
	return 0;
}
