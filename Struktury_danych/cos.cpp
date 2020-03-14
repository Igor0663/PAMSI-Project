#include"./inc/List.hh"
#include<cstdio>

int main()
{
	List<char> kokos;
	kokos.push_back('a');
	kokos.push_back('c');
	kokos.push_back('d');
	kokos.insert('b', 1);
	for(Iterator<char> it=kokos.begin();it!=kokos.end();it++)
		printf("%c ", *it);
	return 0;
}
