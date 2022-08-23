#pragma once
#include <iostream>
#include"Person.h"

using namespace std;
class heap {
	Person* data = nullptr; //data array
	int heapSize = 0;		//current heap size
	int maxSize = 0;		//max heap size
	int allocated;			// 1 if heap allocated memory
	int numComp = 0;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	static void Swap(Person& a, Person& b);
	void fixHeap(int node);

public:
	heap(int max);		//alocate memory
	heap(Person array[], int n); //turn array[] into heap
	~heap();

	Person& min();
	Person& deleteMin();
	void insert(Person newItem);

	int getNumComp() { return this->numComp; }

};