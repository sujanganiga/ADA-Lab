#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int  Partition(int arr[],int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    do{
        do{
            i++;
        }while(arr[i]<=pivot&&i<high);
        do{
            j--;
        }while(pivot<arr[j]);
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }while(i<j);
    swap(arr[low],arr[j]);
    return j;
}

void QuickSort(int arr[],int low, int high){
    if(low<high){
        int pivot=Partition(arr,low,high);
        QuickSort(arr,low,pivot);
        QuickSort(arr,pivot+1,high);
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
        QuickSort(arr,0,n);
        clock_t end=clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << duration << " seconds" << endl;
        k++;
    }
}