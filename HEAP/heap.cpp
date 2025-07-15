#include <iostream>

using namespace std;

class Heap
{
public:
    int arr[1000];
    int size = 0;
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;
        // take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;
            int largest=i;
            if (leftIdx <= size && arr[leftIdx] > arr[largest])
            {
                largest = leftIdx;
            }

            if (rightIdx <= size && arr[rightIdx] > arr[largest])
            {
                largest = rightIdx;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }
};

void heapify(vector<int>& arr,int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left <= n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}


void heapSort(vector<int>& arr,int n){
    int t=n;
    while(t>1){
        swap(arr[t],arr[1]);
        t--;
        heapify(arr,t,1);
    }
}


int main()
{

    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(5);
    // h.print();

    vector<int> arr={-1,54,53,55,52,50};
    int n=arr.size()-1;
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;

    heapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}