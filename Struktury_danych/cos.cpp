#include"./inc/List.hh"
#include<cstdio>

int main()
{
	 List<int> kokos;
	kokos.push_back(1);
	kokos.push_back(3);
	kokos.push_back(4);
	kokos.insert(2, 1);
	for(Iterator<int> it=kokos.begin();it!=kokos.end();it++)
		printf("%d ", *it);
	return 0;
}
