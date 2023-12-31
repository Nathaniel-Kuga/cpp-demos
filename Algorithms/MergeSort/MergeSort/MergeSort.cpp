// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <random>

void mergeFunc(int arr[], int low, int mid, int high, int temp[]) {

	int i = low; // index for left subarray
	int j = mid + 1; // index for right subarray
	int k = 0; // index for temp array

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    //While first half is not empty
    //  Move next item from it to temp
    while (i <= mid)
    {
        temp[k] = arr[i];
        ++k;
        ++i;
    }

    //While second half is not empty
    //  Move next item from it to temp
    while (j <= high)
    {
        temp[k] = arr[j];
        ++k;
        ++j;
    }

    //Copy indexes from low-high from temp back to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSortInternal(int arr[], int low, int high, int temp[]) {
    // base case: 1 or fewer elements is sorted
    if (low >= high)
        return;

    //Set mid to halfway between low and high
    int mid = (high + low) / 2;
    //Recursively sort first low to mid
    mergeSortInternal(arr, low, mid, temp);
    //Recursively sort second mid+1 to high
    mergeSortInternal(arr, mid + 1, high, temp);
    //Call mergeFunc to merge the two halves
    mergeFunc(arr, low, mid, high, temp);
}

void mergeSort(int arr[], int arrSize) {
    int* temp = new int[arrSize];
    mergeSortInternal(arr, 0, arrSize - 1, temp);
    delete[] temp;
}

int main()
{
    std::cout << "Merge Sort\n";

    const int size = 100000;
    int* arr = new int[size] ;

    // Initialize the array with arr from 1 to 100,000
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }

    // Seed a random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the array
    std::shuffle(arr, arr + size, g);

    //Sort the array
    std::cout << "First one hundred values before: ";
    for (int i = 0; i < 100; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << '\n' << "First one hundred values after: ";
	mergeSort(arr, size);
	for (int i = 0; i < 100; ++i) {
		std::cout << arr[i] << ", ";
	}
	std::cout << '\n';

	delete[] arr;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
