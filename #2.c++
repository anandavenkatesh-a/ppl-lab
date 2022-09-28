#include<iostream>
using namespace std;

template <class T> void sort(T* arr,int n){
    if(n == 1){
        return;
    }
    
    int size1 = n/2;
    int size2 = n - (n/2);
    sort<T>(arr,size1);
    sort<T>(arr+size1,size2);

    int i = 0,j = size1,index = 0;
    T* temp = new T[n];
    while(index < n){
       if(i == size1){
         temp[index++] = arr[j++]; 
       }
       else if(j == n){
         temp[index++] = arr[i++];
       }
       else if(arr[i] > arr[j]){
         temp[index++] = arr[j++]; 
       }
       else if(arr[i] < arr[j]){
         temp[index++] = arr[i++];
       }
       else{
         temp[index++] = arr[i++];
         temp[index++] = arr[j++];
       }
    }

    for(int i = 0;i < n;i++){
        arr[i] = temp[i];
    }
    delete [] temp;
}

int main(){
    int arr_int[] = {2,1,4,6,16,8,9};
    float arr_float[] = {2.2,4.2,6.7,8.22,9.753,8.23,1.24};
    char arr_chr[] = "helloworld";

    sort<int>(arr_int,7);
    sort<float>(arr_float,7);
    sort<char>(arr_chr,10);

    for(int i = 0;i < 7;i++){
        cout << arr_int[i] << ' ';
    } 
    cout << endl;

    for(int i = 0;i < 7;i++){
        cout << arr_float[i] << ' ';
    }
    cout << endl;

    cout << arr_chr << endl;
    return 0;
}