#include<iostream>
#include<ctime>
#include<cstdlib>//imp
using namespace std;

void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i;j<n-1;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int size[]={100,200,500,1000,2000,5000,10000};
    int k=0;
    while(k<7){
        int n=size[k];
        int *arr=new int[n];

        for(int i=0;i<n;i++){
            arr[i]=rand()%100000;
        }
        clock_t start=clock();
        SelectionSort(arr,n);
        clock_t end=clock();

        double duration=double(end-start)/CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << duration << " seconds" << endl;
        k++;
    }
}