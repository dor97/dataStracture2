#include "heap.h"
//-----------------------------------------------------------------------------------------------------------
//The function return the left child
int heap::Left(int node) { return (2 * node + 1); }
//-----------------------------------------------------------------------------------------------------------
//The function return the right child
int heap::Right(int node) { return (2 * node + 2); }
//-----------------------------------------------------------------------------------------------------------
//The function return the parent
int heap::Parent(int node) { return (node - 1) / 2; }
//-----------------------------------------------------------------------------------------------------------
heap::heap(int max)
{ // constructor: allocate memory for the heap, make empty heap
	this->data = new Person[max];
	this->allocated = 1;
	this->maxSize = max;
	this->heapSize = 0;
}
//-----------------------------------------------------------------------------------------------------------
//The function creat a heap form a given array
heap::heap(Person array[], int n)
{
	heapSize = maxSize = n;

	data = array;
	allocated = 0;

	for (int i = (n / 2) - 1; i >= 0; i--)
		fixHeap(i);
}
//-----------------------------------------------------------------------------------------------------------
heap::~heap()
{
	if (allocated)
		delete[] data;
	data = nullptr;
}
//-----------------------------------------------------------------------------------------------------------
//The function swap to node in the array
void heap::Swap(Person& a, Person& b)
{
	Person temp = a;
	a = b;
	b = temp;
}
//-----------------------------------------------------------------------------------------------------------
//The function fix the heap
void heap::fixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	//Find maximum among node, left, right
	numComp++;
	if ((left < heapSize) && (data[left].get_id() < data[node].get_id()))
		min = left;
	else
		min = node;


	numComp++;
	if ((right < heapSize) && (data[right].get_id() < data[min].get_id()))
		min = right;

	//swap values if necessary, and countinue fixing heap
	if (min != node)
	{
		Swap(data[node], data[min]);
		fixHeap(min);
	}
}
//-----------------------------------------------------------------------------------------------------------
//The function return the minimal element in the heap
Person& heap::min()
{
	if (heapSize > 0)
		return data[0];
	else
		throw "Empty heap!";
}
//-----------------------------------------------------------------------------------------------------------
//The function return and delete the minimal element in the heap
Person& heap::deleteMin()
{
	if (heapSize < 1)
		throw "Empty heap!";

	Person min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	fixHeap(0);
	return min;

}
//-----------------------------------------------------------------------------------------------------------
//The function insert a new element to the heap
void heap::insert(Person newItem)
{
	if (heapSize == maxSize)
		throw "Full heap!";

	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].get_id() > newItem.get_id()))
	{
		numComp++;
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	data[i] = newItem;
}
//-----------------------------------------------------------------------------------------------------------