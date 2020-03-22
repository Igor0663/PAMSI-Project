#include<queue>
#include<iostream>
using namespace std;
int main()
{
	queue<int> kolejka1;
	kolejka1.push(1);
	kolejka1.push(4);
	kolejka1.push(2);
	kolejka1.push(3);
	kolejka1.push(5);
	queue<int> kolejka2 = kolejka1;
	queue<std::string> kolejka3;

	queue<int> tmp = kolejka1;
	while(!tmp.empty())
	{
		cout<<tmp.front() << " ";
		tmp.pop();
	}
	std::cout << "\n";
	
	tmp = kolejka2;
	while(!tmp.empty())
	{
		cout<<tmp.front() << " ";
		tmp.pop();
	}
	std::cout << "\n";
	
	kolejka2.push(8);
	
	tmp = kolejka2;
	while(!tmp.empty())
	{
		cout<<tmp.front() << " ";
		tmp.pop();
	}
	kolejka2.pop();
	std::cout << "\n";

	tmp = kolejka2;
	while(!tmp.empty())
	{
		cout<<tmp.front() << " ";
		tmp.pop();
	}
	std::cout << "\n";

	std::cout << kolejka3.empty();
	kolejka3.push("pierwszy");
	std::cout <<  " " << kolejka3.empty() << "\n";
	kolejka3.push("drugi");
	kolejka3.push("trzeci");

	std::cout << kolejka3.front() << "\n";
	queue<string> tmp2 = kolejka3;
	while(!tmp2.empty())
	{
		cout<<tmp2.front() << " ";
		tmp2.pop();
	}
	return 0;
}
