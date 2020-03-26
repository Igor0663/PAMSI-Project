#ifndef SORTING_ALGORITHMS_HH
#define SORTING_ALGORITHMS_HH
#include<functional>

template< typename T, class Compare = std::less<T> >
void mergesort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

template< typename T, class Compare = std::less<T> >
void quicksort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

template< typename T, class Compare = std::less<T> >
void introsort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

#include"../src/Sorting_algorithms.cpp"

#endif
