#include<queue>
#include<iostream>
using namespace std;

int main()
{
	priority_queue<int> kopiec1;
	cout << kopiec1.empty();
	kopiec1.push(1);
	cout << " " << kopiec1.empty() << "\n";
	kopiec1.push(2);
	kopiec1.push(2);
	kopiec1.push(8);
	kopiec1.push(-4);
	kopiec1.push(5);
	kopiec1.push(1);
	cout << kopiec1.top() << "\n";

	priority_queue<int> kopiec2 = kopiec1;

	while(!kopiec1.empty())
	{
		cout << kopiec1.top() << " ";
		kopiec1.pop();
	}
	cout << "\n";
	kopiec2.pop();
	while(kopiec2.size())
	{
		cout << kopiec2.top() << " ";
		kopiec2.pop();
	}
	return 0;
}
