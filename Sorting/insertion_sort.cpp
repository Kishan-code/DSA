#include<iostream>
using namespace std;

void insertion_sort(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        int j = i+1;
        while(j != 0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main(){
    
    int n = 6;
    int arr[n] = {13, 24, 46, 20, 9, 52};

    insertion_sort(arr, n);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}