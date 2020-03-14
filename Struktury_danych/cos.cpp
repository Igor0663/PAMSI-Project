#include"./inc/List.hh"
#include<cstdio>

int main()
{
	 List<int> kokos;
	kokos.push_back(1);
	kokos.push_back(3);
	kokos.push_back(4);
	kokos.insert(2, 1);
	kokos.pop_front();
	for(int i=0;i<kokos.size();i++)
		printf("%d ", kokos[i]);
	return 0;
}
