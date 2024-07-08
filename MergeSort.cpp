#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void Merge(int arr[],int low, int high,int mid){

    int *temp=new int[high-low+1];//temp is temperavey array where two merged array will store
    //here given array is arr[] here think like it has 2 arrays 
    //one is from low ->mid whre i iterates there
    int i=low;
    //another is from mid+1 -> high j iterates there
    int j=mid+1;
    //k iterates temp array;
    int k=0;
    //which is less push to array
    while( i<=mid && j<=high ){
        if( arr[i]< arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    //transfering back to original array
    for( i=low ,k=0 ; i<=high ; i++, k++){
        arr[i]=temp[k];
    }
    delete[]temp;
}

void MergeSort(int arr[], int low , int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,high,mid);
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
        MergeSort(arr,0,n-1);
        clock_t end=clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << duration << " seconds" << endl;
        k++;
    }
}