#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child
    if (left < n && arr[left] > arr[largest])
        largest = left; // If left child is larger than root
    if (right < n && arr[right] > arr[largest])
        largest = right; // If right child is larger than largest so far

    if (largest != i)
    {
        swap(arr[i], arr[largest]); // If largest is not root
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int size[]={100,200,500,1000,2000,5000,10000};
    int k=0;
    while(k<7){
        int n=size[k];
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=rand()%10000;
        }
        clock_t start=clock();
        heapSort(arr,n);
        clock_t end=clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << duration << " seconds" << endl;
        k++;
    }
}
