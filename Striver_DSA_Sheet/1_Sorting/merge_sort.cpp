#include<iostream>
using namespace std;

void merge(int*, int, int, int);

void merge_sort(int *arr, int low, int high){
    if(low >= high)
        return;
    
    int mid = low+(high-low)/2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void merge(int *arr, int low, int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int leftArr[n1], rightArr[n2];

    for(int i = 0; i < n1; i++)
        leftArr[i] = arr[low+i];
    for(int i = 0; i < n2; i++)
        rightArr[i] = arr[mid+i+1];

    int i = 0, j = 0, k = low;
    
    while(i < n1 && j < n2){
        if(leftArr[i] < rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

int main(){
    int n = 6;
    int arr[n] = {13, 24, 46, 20, 9, 52};

    merge_sort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}