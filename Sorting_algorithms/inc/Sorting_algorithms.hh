#ifndef SORTING_ALGORITHMS_HH
#define SORTING_ALGORITHMS_HH
#include<functional>
#include"Priority_queue.hh"

template< typename T, class Compare = std::function<bool(T,T)> >
void mergesort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

template< typename T, class Compare = std::function<bool(T,T)> >
void quicksort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

template< typename T, class Compare = std::function<bool(T,T)> >
void introsort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

template< typename T, class Compare = std::function<bool(T,T)> >
void heapsort( T* tab_l, T* tab_r, Compare cmp = std::less<T>() );

#include"../src/Sorting_algorithms.cpp"

#endif
