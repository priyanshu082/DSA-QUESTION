#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivotElement=arr[low];
    int i=low+1;
    int j=high;
    while(i<j)
    {
        while( arr[i]<=pivotElement && i<=high-1 ) i++;
        while(arr[j]>pivotElement && j>=low+1) j--;
    
    if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high) return;

    int pivot = partition(arr, low, high); // finding the pivot

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot+1, high);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Unsorted : ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted : ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}