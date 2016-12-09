#include <iostream>
#include <list>




void show_list(std::list<int>& intList)
{
	std::cout << "The list contains: \n";
	for (int elem : intList)
	{
		std::cout << elem << "\n";
	}
}

void bubble_sort_list(std::list<int>& intList)
{
	int i, j, flag = 1;    // set flag to 1 to start first pass
	int temp;             // holding variable
	int numLength = intList.size;

	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (intList[j + 1] > intList[j])      // ascending order simply changes to <
			{
				temp = intList[j];             // swap elements
				intList[j] = intList[j + 1];
				intList[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}
	return;
}

void insertion_sort(std::list<int>& intList) 
{
	int j, temp;
	int length = intList.size();
	for (int i = 0; i < length; i++) {
		j = i;

		while (j > 0 && intList[j] < intList[j - 1]) {
			temp = intList[j];
			intList[j] = intList[j - 1];
			intList[j - 1] = temp;
			j--;
		}
	}
}

int partition(std::list<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j<q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			std::swap(A[i], A[j]);
		}

	}

	std::swap(A[i], A[p]);
	return i;
}

void quickSort(std::list<int>& A, int p, int q)
{
	int r;
	if (p<q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}

void sort_list(std::list<int>& intList)
{
	/*bubble_sort_list(std::list<int>& intList);
	quickSort(std::list<int>& A, int p, int q);
	insertion_sort(std::list<int>& intList);*/
}


int main()
{

	std::list<int> intList =
	{
		4,
		2,
		3,
		6,
		5,
		1
	};
	std::cout << "Before the sort: \n";
	show_list(intList);

	sort_list(intList);

	std::cout << "After the sort: \n";
	show_list(intList);

	//Windows specifics
	system("pause");
	return 0;
}