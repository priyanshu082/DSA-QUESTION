
#include <iostream>
#include <vector>
using namespace std;

class higharray
{
private:
    vector<double> v;
    int nelems;

public:
    higharray() : nelems(0)
    {
    }

    higharray(int max) : nelems(0)
    {
        v.resize(max);
    }

    int find(double searchkey)
    {
        int j;
        for (j = 0; j < nelems; j++)
            if (v[j] == searchkey)
                break;
        if (j == nelems)
            return 0;
        else
            return 1;
    }

    void insert(double value)
    {
        v[nelems] = value;
        nelems++;
    }

    void insert(double value, int loc)
    {
        for (int i = nelems - 1; i >= loc; i--)
        {
            v[i + 1] = v[i];
        }
        v[loc] = value;
        nelems++;
    }

    int sort()
    {
        int temp;
        for (int k = 0; k < nelems - 1; k++)
        {
            for (int j = 0; j < nelems - k - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }

    bool remove(double value)
    {
        int j;
        for (j = 0; j < nelems; j++)
            if (value == v[j])
                break;
        if (j == nelems) 
            return false;
        else
        {
            for (int k = j; k < nelems; k++)
                v[k] = v[k + 1];
            nelems--; 
            return true;
        }

    } 

    void display()
    {
        for (int j = 0; j < nelems; j++)
            cout << v[j] << " ";        
        cout << endl;
    }

    void display(int plus)
    {
        int count = 0;
        for (int j = 0; j < nelems; j++)
        {
            count += plus;
        }
        v[nelems] = count;
        nelems++;
        for (int j = 0; j < nelems; j++)
        {
            cout << v[j] << " ";
        }
    }
}; // end class.

int main()
{
    int maxsize = 100; // array size.
    higharray arr(maxsize);

    arr.insert(77);
    arr.insert(99);
    arr.insert(44);
    arr.insert(55);
    arr.insert(22);
    arr.insert(88);
    arr.insert(11);
    arr.insert(00);
    arr.insert(66);
    arr.insert(33);

    int n;
    cout << "Insert an element: " << endl;
    cin >> n;
    arr.insert(n);
    arr.display();

    double x;
    cout << "Search an element: " << endl;
    cin >> x;

    if (arr.find(x) == 1)
        cout << "Found " << x << endl;
    else
        cout << "Not found" << endl;

    int searchKey = 35;

    if (arr.find(searchKey))
        cout << "Found " << searchKey << endl;
    else
        cout << "Can't find " << searchKey << endl;

    cout << "Deleting 0, 55 and 99" << endl;
    arr.remove(0);
    arr.remove(55);
    arr.remove(99);

    arr.display();

    return 0;
}
