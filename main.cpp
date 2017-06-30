#include <iostream>
#include <algorithm>
#include "MergeSort.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    //arr[l+1...i)<=v;arr(j...r]>=v; make balance!
    int i = l+1,j=r;
    while(true){
        while(i<=j && arr[i]<v)
            i++;
        while(j>=i && arr[j]>v)
            j--;

        if(i>j)  //i>=j also works. Since arr[i]>=v and arr[j]<=v, when i=j, arr[i]=arr[j]=v
            break;

        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);
    return j;
}

template<typename T>
void __quickSort2(T arr[], int l, int r){
    if(r-l<=15){
        insertionSort(arr,l,r);
        return;
    }
    int p = __partition2(arr, l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}

template<typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}
template<typename T>
int __partition(T arr[], int l,int r){
    swap(arr[l],arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    //arr[l+1...j]<v;arr[j+1...i)>=v
    int j=l;
    for(int i=l+1;i<=r;i++){
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r){
//    if(l>=r)
//        return;
    if(r-l<=15){
        insertionSort(arr,l,r);
        return;
    }
    int p = __partition(arr,l,r);
    __quickSort(arr, l,p-1);
    __quickSort(arr,p+1,r);

}

template <typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}

int main(){
    int n = 1000321;

    // 测试3 测试存在包含大量相同元素的数组
    // 使用双快速排序后, 我们的快速排序算法可以轻松的处理包含大量元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,10);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;




    return 0;
}