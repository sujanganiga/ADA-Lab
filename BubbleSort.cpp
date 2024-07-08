#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;++i){
        int flag=0;
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
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
        BubbleSort(arr,size[k]);
        clock_t end=clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken to sort " << n << " elements: " << duration << " seconds" << endl;
        k++;
    }
}