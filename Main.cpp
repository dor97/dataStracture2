#include"main.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------
/*
name: Dor Raba
id: 208851741
name: Ofir Nakdai
id: 318382827
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------
int main()
{

	try {
		int n, k, seed;
		int numComp1 = 0, numComp2 = 0, numComp3 = 0;
		long id;
		string name;
		Person res;
		Person* pArr = nullptr;
		Person* pArr2 = nullptr;
		Person* pArr3 = nullptr;
		char c;
		cin >> seed;
		srand(seed);
		cout << "please enter num of persons: ";
		cin >> n;

		if (n <= 0)
			throw("Invalid input");
		try {
			pArr = new Person[n];
			pArr2 = new Person[n];
			pArr3 = new Person[n];

			for (int i = 0; i < n; i++)
			{
				cout << "enter id and full name: ";
				cin >> id;
				c = getchar();
				name = makeString(pArr, pArr2, id);

				pArr[i].set_id(id);
				pArr[i].set_name(name);
				pArr2[i].set_id(id);
				pArr2[i].set_name(name);
				pArr3[i].set_id(id);
				pArr3[i].set_name(name);
			}

			cout << "please enter k: ";
			cin >> k;
			if (k <= 0 || k > n)
				throw("Invalid input");

			const Person& res3 = BST(pArr2, n, k, numComp3);
			res = RandSelection(pArr, 1, n, k, numComp1);
			const Person& res2 = selectHeap(pArr3, n, k, numComp2);

			cout << "RandSelection: " << res.get_id() << " " << res.get_name() << " " << numComp1 << " comparisons" << endl;
			cout << "selectHeap: " << res2.get_id() << " " << res2.get_name() << " " << numComp2 << " comparisons" << endl;
			cout << "BST: " << res3.get_id() << " " << res3.get_name() << " " << numComp3 << " comparisons" << endl;

		}
		catch (const char* s)
		{
			delete[] pArr;
			delete[] pArr2;
			delete[] pArr3;
			throw(s);
		}
		delete[] pArr;
		delete[]pArr2;
		delete[] pArr3;


	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function return the k in size element in an array using heap
const Person& selectHeap(Person data[], int n, int k, int& NumComp)
{
	heap h(data, n);
	for (int i = 1; i < k; i++)
		h.deleteMin();

	NumComp = h.getNumComp();
	return h.min();
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function get a first and last name frim the user, makes sure its valid and return it
string makeString(Person* pArr, Person* pArr2, int id)
{
	string s;
	int spaceCun = 0, len = 0;
	char c = getchar();
	do
	{
		if (isLetter(c) || c == ' ')
		{
			if (c == ' ')
				++spaceCun;
			s.push_back(c);
			++len;
		}
		else
			throw("Invalid input");
		c = getchar();

	} while (c != '\n');
	if (spaceCun != 1 || !isLetter(s[0]) || !isLetter(s[len - 1]))
		throw("Invalid input");
	return s;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function return True if a given char is a letter, else return False
bool isLetter(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function return the k sized element in an array using BST
const Person& BST(Person arr[], int n, int k, int& NumComp)
{
	BSTree t;
	for (int i = 0; i < n; ++i)
		t.Insert(arr[i]);
	const Person& p = t.search(k - 1);
	NumComp = t.getNumComp();
	return p;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function swap to element in the array of the RandSelection function
void swap(Person& a, Person& b)
{
	Person temp = a;
	a = b;
	b = temp;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function return the k sized element in an array using selection with random pivot
const Person& RandSelection(Person arr[], int left, int right, int k, int& NumComp)
{
	int pivot;
	int leftPart;

	pivot = rand() % (right - left + 1);
	pivot += left;

	pivot = Partition(arr, pivot - 1, right - 1, arr[pivot - 1], NumComp);
	pivot = Partition(arr, left - 1, pivot - 1, arr[pivot - 1], NumComp);

	leftPart = pivot - left + 1;

	if (k == leftPart)
		return arr[pivot - 1];
	else if (k < leftPart)
		return RandSelection(arr, left, pivot - 1, k, NumComp);
	else
		return RandSelection(arr, pivot + 1, right, k - leftPart, NumComp);

}
//-----------------------------------------------------------------------------------------------------------------------------------------------
//The function puts an element in his place in an array according to his size and return the index
int Partition(Person arr[], int left, int right, Person ptr, int& NumComp)
{
	while (left < right)
	{
		if (arr[left] > arr[right])
		{
			swap(arr[left], arr[right]);
			if (arr[left] == ptr)
				right--;
			else if (arr[right] == ptr)
				left++;

		}
		else // (arr[right] > arr[left])
		{
			if (arr[left] == ptr)
				right--;
			else if (arr[right] == ptr)
				left++;
		}
		++NumComp;
	}

	return left + 1;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------