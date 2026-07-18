#include<iostream>
using namespace std;

void quick_sort(int *arr, int low, int high){
    if(low >= high)
        return;
    
    int pivot = low;
    int left = low+1;
    int right = high;
    int temp;

    while(left <= right){
        while(left <= high && arr[left] <= arr[pivot])
            left++;
        while(right >= low && arr[right] > arr[pivot])
            right--;

        if(left < right){
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    temp = arr[pivot];
    arr[pivot] = arr[right];
    arr[right] = temp;

    quick_sort(arr, low, right-1);
    quick_sort(arr, right+1, high);
}

int main(){
    
    int n = 6;
    int arr[n] = {13, 24, 46, 20, 9, 52};

    quick_sort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}