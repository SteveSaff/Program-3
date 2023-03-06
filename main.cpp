/*
    Name: Stephen Saffioti
    Program 3: Using Different Sorting methods and comparing the times.
    Date: 3/2/23
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>

#define SIZE_SMALL 100
#define SIZE_LARGE 10000

using namespace std;
using namespace std::chrono;


// function to perform merge
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//function to perform the merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//function to perform the bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//function to perform the system sort
void timeSystemSort(int arr[], int n)
{
    auto start = steady_clock::now();
    sort(arr, arr + n);
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Sorting array using built-in sort: " << duration.count() << " ns" << endl;
}

int main()
{
                        //System Sort code

    //create arrays for testing

    int small_arr[100];
    int large_arr[10000];

  // Small data set
    for(int i = 0; i<100; i++) {
        small_arr[i] = rand() % 100;
    }

    for(int i = 0; i<10000; i++) {
        large_arr[i] = rand() % 10000;
    }

    //sort small array using System Sort
    auto start = steady_clock::now();
    sort(small_arr, small_arr+100);
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Using System Sort" << endl;
    cout << "Elapsed time in nanoseconds for 100 elements is: " << duration.count() << "ns\n";

    // sort large array using System Sort

    start = steady_clock::now();
    sort(large_arr, large_arr+10000);
    stop = steady_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    cout << "Elapsed time in nanoseconds for 10000 elements is: " << duration.count() << " ns\n";

    cout << endl;

                    //Bubble Sort code

    // Small data set
    start = steady_clock::now();
    bubbleSort(small_arr, 100);
    stop = steady_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    cout << "Using Bubble Sort" << endl;
    cout << "Elapsed time in nanoseconds for 100 elements is: " << duration.count() << " ns\n";

    // Large data set
    start = steady_clock::now();
    bubbleSort(large_arr, 10000);
    stop = steady_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    cout << "Elapsed time in nanoseconds for 10000 elements is: " << duration.count() << "ns\n";
    cout << endl;

                        //Merge Sort code

    // Small data set
    // sort small array using merge sort
    start = steady_clock::now();
    mergeSort(small_arr, 0, 99);
    stop = steady_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    cout << "Using Merge Sort" << endl;
    cout << "Elapsed time in nanoseconds for 100 elements is: " << duration.count() << "ns\n";

    // Large data set
    // sort small array using merge sort
    start = steady_clock::now();
    mergeSort(large_arr, 0, 9999);
    stop = steady_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);

    cout << "Elapsed time in nanoseconds for 10000 elements is: " << duration.count() << "ns\n";

    return 0;
}
