#include<iostream>

template< typename T, class Compare>
void merge( T* tab_l, T* tab_r, Compare cmp)
{
	unsigned int size_tab = (tab_r - tab_l);
	unsigned int middle = (size_tab - 1) / 2;
	
	T* tab_tmp = new T[size_tab];

	unsigned int l_ptr = 0;
	unsigned int p_ptr = middle + 1;
	unsigned int tmp_ptr = 0;

	while(tmp_ptr != size_tab)
	{
		if(l_ptr == middle + 1)
		{
			tab_tmp[tmp_ptr] = tab_l[p_ptr];
			p_ptr++;
		}
		else if(p_ptr == size_tab)
		{
			tab_tmp[tmp_ptr] = tab_l[l_ptr];
			l_ptr++;
		}
		else
		{
			if(cmp(tab_l[p_ptr],tab_l[l_ptr]))
			{
				tab_tmp[tmp_ptr] = tab_l[p_ptr];
				p_ptr++;
			}
			else
			{
				tab_tmp[tmp_ptr] = tab_l[l_ptr];
				l_ptr++;
			}
		}
		tmp_ptr++;
	}

	for(unsigned int i = 0;i < size_tab;i++)
		tab_l[i] = tab_tmp[i];
	
	delete[] tab_tmp;
	return;
}


template< typename T, class Compare>
int partition(T* tab_l, T* tab_r, Compare cmp)
{
	unsigned int size_tab = (tab_r - tab_l);
	unsigned int middle = (size_tab - 1) / 2;
	T middle_value = tab_l[middle];

	T* tab_tmp = new T[size_tab];

	unsigned int l_ptr = 0;
	unsigned int p_ptr = size_tab - 1;
	for(unsigned int i = 0; i < size_tab; i++)
	{
		if(i == middle)
			continue;
		if(cmp(tab_l[i], middle_value))
		{
			tab_tmp[l_ptr] = tab_l[i];
			l_ptr++;
		}
		else
		{
			tab_tmp[p_ptr] = tab_l[i];
			p_ptr--;
		}
	}
	tab_tmp[l_ptr] = middle_value;
	for(unsigned int i = 0;i < size_tab;i++)
		tab_l[i] = tab_tmp[i];

	delete [] tab_tmp;
	return int(l_ptr);
}
template< typename T, class Compare>
void mergesort( T* tab_l, T* tab_r, Compare cmp)
{
	if( tab_r - tab_l  == 1)
		return;
	unsigned int size_tab = (tab_r - tab_l);
	unsigned int middle = (size_tab - 1) / 2;
	
	mergesort(tab_l, tab_l + middle + 1, cmp);
	mergesort(tab_l + middle + 1, tab_r, cmp);

	merge(tab_l, tab_r, cmp);
	return;
}

template< typename T, class Compare>
void quicksort( T* tab_l, T* tab_r, Compare cmp)
{
	if( tab_r - tab_l  <= 1)
		return;
	int partition_index = partition(tab_l, tab_r, cmp);

	quicksort(tab_l, tab_l + partition_index, cmp);
	quicksort(tab_l + partition_index + 1, tab_r, cmp);
	return;
}
