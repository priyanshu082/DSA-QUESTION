#include <iostream>
#include <vector>
using namespace std;

// ===================== MAX HEAP IMPLEMENTATION =====================
class MaxHeap
{
public:
    int arr[1000]; // Array to store heap elements, 1-based indexing
    int size = 0;  // Current size of heap

    // Insert a new value into the max heap
    void insert(int val)
    {
        size = size + 1;      // Increase heap size
        int index = size;     // Index where new value will be inserted
        arr[index] = val;     // Insert value at the end

        // Heapify up: Move the new value up to maintain max-heap property
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

    // Print all elements of the max heap
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Delete the root element from the max heap
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size]; // Move last element to root
        size = size - 1;    // Decrease heap size

        // Heapify down: Move the root to its correct position
        int i = 1;
        while (i <= size)
        {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;
            int largest = i;
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

// ===================== MIN HEAP IMPLEMENTATION =====================
class MinHeap
{
public:
    int arr[1000]; // Array to store heap elements, 1-based indexing
    int size = 0;  // Current size of heap

    // Insert a new value into the min heap
    void insert(int val)
    {
        size = size + 1;      // Increase heap size
        int index = size;     // Index where new value will be inserted
        arr[index] = val;     // Insert value at the end

        // Heapify up: Move the new value up to maintain min-heap property
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index])
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

    // Print all elements of the min heap
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Delete the root element from the min heap
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size]; // Move last element to root
        size = size - 1;    // Decrease heap size

        // Heapify down: Move the root to its correct position
        int i = 1;
        while (i <= size)
        {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;
            int smallest = i;
            if (leftIdx <= size && arr[leftIdx] < arr[smallest])
            {
                smallest = leftIdx;
            }

            if (rightIdx <= size && arr[rightIdx] < arr[smallest])
            {
                smallest = rightIdx;
            }

            if (smallest != i)
            {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else
            {
                break;
            }
        }
    }
};

// ===================== MAX HEAPIFY FUNCTION FOR HEAP SORT =====================
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    // Check if left child exists and is greater than current largest
    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    // Check if right child exists and is greater than current largest
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    // If largest is not the current node, swap and continue heapifying
    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

// ===================== MIN HEAPIFY FUNCTION FOR HEAP SORT =====================
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    // Check if left child exists and is smaller than current smallest
    if (left <= n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    // Check if right child exists and is smaller than current smallest
    if (right <= n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    // If smallest is not the current node, swap and continue heapifying
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
    }
}

// ===================== MAX HEAP SORT IMPLEMENTATION =====================
void maxHeapSort(vector<int>& arr, int n) {
    int t = n;
    while (t > 1) {
        swap(arr[t], arr[1]); // Move max element to end
        t--;
        maxHeapify(arr, t, 1);   // Heapify reduced heap
    }
}

// ===================== MIN HEAP SORT IMPLEMENTATION =====================
void minHeapSort(vector<int>& arr, int n) {
    int t = n;
    while (t > 1) {
        swap(arr[t], arr[1]); // Move min element to end
        t--;
        minHeapify(arr, t, 1);   // Heapify reduced heap
    }
}

int main()
{
    // ===================== MAX HEAP DEMO =====================
    cout << "Max Heap Demo:" << endl;
    MaxHeap maxH;
    maxH.insert(10);
    maxH.insert(20);
    maxH.insert(15);
    maxH.insert(5);
    maxH.print();

    maxH.deleteFromHeap();
    maxH.print();

    // ===================== MIN HEAP DEMO =====================
    cout << "\nMin Heap Demo:" << endl;
    MinHeap minH;
    minH.insert(10);
    minH.insert(20);
    minH.insert(15);
    minH.insert(5);
    minH.print();

    minH.deleteFromHeap();
    minH.print();

    // ===================== MAX HEAPIFY AND HEAP SORT DEMO =====================
    cout << "\nMax Heapify and Heap Sort Demo:" << endl;
    // -1 is used as a dummy value for 1-based indexing
    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = arr.size() - 1;

    // Build max heap from array
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(arr, n, i);
    }

    // Print heapified array (max heap)
    cout << "Max Heapified array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform max heap sort
    maxHeapSort(arr, n);

    // Print sorted array (descending order)
    cout << "Max Heap Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ===================== MIN HEAPIFY AND HEAP SORT DEMO =====================
    cout << "\nMin Heapify and Heap Sort Demo:" << endl;
    // -1 is used as a dummy value for 1-based indexing
    vector<int> arr2 = {-1, 54, 53, 55, 52, 50};
    int n2 = arr2.size() - 1;

    // Build min heap from array
    for (int i = n2 / 2; i >= 1; i--) {
        minHeapify(arr2, n2, i);
    }

    // Print heapified array (min heap)
    cout << "Min Heapified array: ";
    for (int i = 1; i <= n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Perform min heap sort
    minHeapSort(arr2, n2);

    // Print sorted array (ascending order)
    cout << "Min Heap Sorted array: ";
    for (int i = 1; i <= n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}