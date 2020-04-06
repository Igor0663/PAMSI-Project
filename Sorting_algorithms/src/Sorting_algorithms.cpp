#include<iostream>
#include<cmath>

template<typename T, class Compare>
void merge(T* tab_l, T* tab_r, Compare cmp)
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


template<typename T, class Compare>
int partition(T* tab_l, T* tab_r, Compare cmp)
{
	unsigned int size_tab = (tab_r - tab_l);
//	unsigned int middle = (size_tab - 1) / 2;
	unsigned int middle = (uintptr_t)(tab_l)%size_tab;
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
template<typename T, class Compare>
void mergesort(T* tab_l, T* tab_r, Compare cmp)
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

template<typename T, class Compare>
void quicksort(T* tab_l, T* tab_r, Compare cmp)
{
	if( tab_r - tab_l  <= 1)
		return;
	int partition_index = partition(tab_l, tab_r, cmp);

	quicksort(tab_l, tab_l + partition_index, cmp);
	quicksort(tab_l + partition_index + 1, tab_r, cmp);
	return;
}

template<typename T, class Compare >
void heapsort(T* tab_l, T* tab_r, Compare cmp)
{
	Priority_queue<T, Compare>* heap = new Priority_queue<T, Compare>(cmp);
	unsigned int size_tab = tab_r - tab_l;

	for(unsigned int i = 0;i < size_tab;i++)
		heap->push(tab_l[i]);
	for(unsigned int i = 0;i < size_tab;i++)
		tab_l[i] = heap->pop();
	delete heap;
	return;
}

template<typename T, class Compare>
void insertion_sort(T* tab_l, T* tab_r, Compare cmp)
{
	unsigned int size_tab = tab_r - tab_l;
	for(unsigned int i = 1; i < size_tab;i++)
	{
		unsigned int j = i;
		while(cmp(tab_l[j], tab_l[j-1]))
		{
			std::swap(tab_l[j], tab_l[j-1]);
			j--;
			if(j == 0) break;
		}
	}	
	return;
}

template<typename T, class Compare>
void intro_routine(T* tab_l, T* tab_r, Compare cmp, unsigned int max_depth)
{
	unsigned int size_tab = tab_r - tab_l;
	if(size_tab <= 10)
	{
		insertion_sort(tab_l, tab_r, cmp);
		return;
	}
	if(max_depth == 0)
	{
		heapsort(tab_l, tab_r, cmp);
		return;
	}

	int partition_index = partition(tab_l, tab_r, cmp);

	intro_routine(tab_l, tab_l + partition_index, cmp, max_depth - 1);
	intro_routine(tab_l + partition_index + 1, tab_r, cmp, max_depth - 1);
	return;
}

template<typename T, class Compare>
void introsort(T* tab_l, T* tab_r, Compare cmp)
{
	unsigned int size_tab = tab_r - tab_l;
	intro_routine( tab_l, tab_r, cmp, (unsigned int)(2 * std::log2(size_tab)));
	return;
}

