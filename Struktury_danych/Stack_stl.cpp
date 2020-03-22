#include<stack>
#include<iostream>
using namespace std;
int main()
{
	stack<int> stos1;
	stos1.push(5);
	stos1.push(3);
	stos1.push(2);
	stos1.push(4);
	stos1.push(1);
	stack<int> stos2 = stos1;
	stack<std::string> stos3;

	stack<int> tmp = stos1;
	while(!tmp.empty())
	{
		cout<<tmp.top() << " ";
		tmp.pop();
	}
	std::cout << "\n";
	
	tmp = stos2;
	while(!tmp.empty())
	{
		cout<<tmp.top() << " ";
		tmp.pop();
	}
	std::cout << "\n";
	
	stos2.push(8);
	
	tmp = stos2;
	while(!tmp.empty())
	{
		cout<<tmp.top() << " ";
		tmp.pop();
	}
	stos2.pop();
	std::cout << "\n";

	tmp = stos2;
	while(!tmp.empty())
	{
		cout<<tmp.top() << " ";
		tmp.pop();
	}
	std::cout << "\n";

	std::cout << stos3.empty();
	stos3.push("pierwszy");
	std::cout <<  " " << stos3.empty() << "\n";
	stos3.push("drugi");
	stos3.push("trzeci");

	std::cout << stos3.top() << "\n";
	stack<string> tmp2 = stos3;
	while(!tmp2.empty())
	{
		cout<<tmp2.top() << " ";
		tmp2.pop();
	}
	return 0;
}
