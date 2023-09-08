#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 50 // size of the hash table

// Hash function
int hash(int key) { return key % 47; }

// Second hash function
int second_hash(int key) { return 7 - (key % 7); }

struct Node
{
    int data;
    Node *next;
};

Node *separate_chaining_table[SIZE];
int linear_probing_table[SIZE];
int quadratic_probing_table[SIZE];
int double_hashing_table[SIZE];

int search_separate_chaining(int key, Node *chain_array[]);
void insert_separate_chaining(int key, Node *chain_array[]);
void delete_separate_chaining(int key, Node *chain_array[]);

int search_linear_probing(int key, int linear[]);
int insert_linear_probing(int key, int linear[]);
void delete_linear_probing(int key, int linear[]);

int search_quadratic_probing(int key, int quadratic[]);
int insert_quadratic_probing(int key, int quadratic[]);
void delete_quadratic_probing(int key, int quadratic[]);

int search_double_hashing(int key, int double_hash[]);
int insert_double_hashing(int key, int double_hash[]);
void delete_double_hashing(int key, int double_hash[]);

void Print_HashTable(int n, int table[]);
void DisplayLL(Node *chain_array[]);

using namespace std;

int main()
{
    srand(time(0)); // every time program is executed it will generated different set of numbers.

    for (int i = 0; i < SIZE; i++)
    {
        // initialize every table
        linear_probing_table[i] = -1;
        quadratic_probing_table[i] = -1;
        double_hashing_table[i] = -1;
        separate_chaining_table[i] = nullptr;
    }

    int n;
    // Generate 40 random numbers and insert them in the hash table
    for (int i = 0; i < 40; i++)
    {
        n = rand() % 1000; // numbers generated from 0 to 999

        // number which is generated get inserted in every hashtable
        insert_separate_chaining(n, separate_chaining_table);
        insert_linear_probing(n, linear_probing_table);
        insert_quadratic_probing(n, quadratic_probing_table);
        insert_double_hashing(n, double_hashing_table);
    }

    while (true)
    {
        cout << "\nImplement hashing using different collision resolution methods.\n";

        cout << "Collision resolution methods-\n";
        cout << "1.Separate Chaining\n";
        cout << "2.Linear Probing\n";
        cout << "3.Quadratic Probing\n";
        cout << "4.Double Hashing\n";
        cout << "\nEnter 0 to exit the program\n";

        cout << "\nType the corresponding number of the method you want to implement:";
        int x;
        cin >> x;

        switch (x)
        {

        case 0:
        {
            exit(0);
        }

        case 1:
        {
            while (true)
            {
                cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display Elements\n";
                cout << "Enter the Number:";
                int y;
                cin >> y;
                switch (y)
                {
                case 1:
                {
                    cout << "Enter the element you want to insert:";
                    int data;
                    cin >> data;
                    insert_separate_chaining(data, separate_chaining_table);
                    break;
                }
                case 2:
                {
                    cout << "Enter the element you want to search: \n";
                    int data;
                    cin >> data;
                    int ans = search_separate_chaining(data, separate_chaining_table);
                    if (ans == -1)
                    {
                        cout << "The entered number was not found.\n";
                    }
                    else
                    {
                        cout << "The element is present at the " << ans << "th posititon\n";
                    }
                    break;
                }
                case 3:
                {
                    cout << "Enter the key you want to delete\n";
                    int data;
                    cin >> data;
                    delete_separate_chaining(data, separate_chaining_table);
                    break;
                }
                case 4:
                {
                    cout << "The elements in the hash table are:\n";
                    DisplayLL(separate_chaining_table);
                    break;
                }
                default:
                {
                    cout << "Invalid\n";
                    continue;
                }
                }
            }
            break;
        }

        case 2:
        {
            while (true)
            {
                cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display hashTable\n";
                cout << "Enter the Number:";
                int y;
                cin >> y;
                switch (y)
                {
                case 1:
                {
                    cout << "Enter the element you want to insert:";
                    int data;
                    cin >> data;

                    int linear_success = insert_linear_probing(data, linear_probing_table);
                    if (linear_success == -1)
                    {
                        cout << "The entered number is already present in the hash table.\n";
                    }
                    else
                    {
                        cout << "The entered number " << data << " has been inserted into the hash table.\n";
                        cout << "Number of probes: " << linear_success << "\n";
                    }
                    break;
                }
                case 2:
                {
                    cout << "Enter the element you want to search:";
                    int data;
                    cin >> data;

                    int ans = search_linear_probing(data, linear_probing_table);
                    if (ans == -1)
                    {
                        cout << "The element was not found.\n";
                    }
                    else
                    {
                        cout << "The element is present at the " << ans << "th position\n";
                    }
                    break;
                }
                case 3:
                {
                    cout << "Enter the element you want to delete:";
                    int data;
                    cin >> data;
                    delete_linear_probing(data, linear_probing_table);
                    break;
                }
                case 4:
                {
                    Print_HashTable(n, linear_probing_table);
                    break;
                }
                default:
                {
                    cout << "Invalid\n";
                    continue;
                }
                }
            }
            break;
        }

        case 3:
        {
            while (true)
            {
            cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display hashTable\n";
            cout << "Enter the Number:";
            int y;
            cin >> y;
            switch (y)
            {
            case 1:
            {
                cout << "Enter the element you want to insert:";
                int data;
                cin >> data;

                int ans = search_quadratic_probing(data, quadratic_probing_table);
                if (ans == -1)
                {
                    int quadratic_insertion = insert_quadratic_probing(data, quadratic_probing_table);
                    cout << "The entered number " << data << " has been inserted into the hash table.\n";
                    cout << "Number of probes: " << quadratic_insertion << "\n";
                }
                else
                {
                    cout << "The entered number is already present in the hash table.\n";
                }
                break;
            }
            case 2:
            {
                cout << "Enter the element you want to search: ";
                int data;
                cin >> data;

                int ans = search_quadratic_probing(data, quadratic_probing_table);
                if (ans == -1)
                {
                    cout << "The element was not found.\n";
                }
                else
                {
                    cout << "The element is present at index: " << ans << "\n";
                }
                break;
            }
            case 3:
            {
                cout << "Enter the element you want to delete: ";
                int data;
                cin >> data;
                delete_quadratic_probing(data, quadratic_probing_table);
                break;
            }
            case 4:
            {
                Print_HashTable(n, quadratic_probing_table);
                break;
            }
            default:
            {
                cout << "Invalid\n";
                continue;
            }
            }
            }
            break;
        }

        case 4:
        {
            while (true)
            {
            cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display hashTable\n";
            cout << "Enter the Number:";
            int y;
            cin >> y;
            switch (y)
            {
                case 1:
                {
                    cout << "Enter the element you want to insert:";
                    int data;
                    cin >> data;
                    int insert_success = insert_double_hashing(data, double_hashing_table);

                    if (insert_success == -1)
                    {
                        cout << "The entered number " << data << " is already present in the hash table.\n";
                    }
                    else
                    {
                        cout << "The entered number " << data << " has been inserted into the hash table.\n";
                        cout << "Number of probes: " << insert_success;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Enter the element you want to search: ";
                    int data;
                    cin >> data;

                    int ans = search_double_hashing(data, double_hashing_table);
                    if (ans == -1)
                    {
                        cout << "The element was not found.\n";
                    }
                    else
                    {
                        cout << "The element is present at index: " << ans << "\n";
                    }
                    break;
                }
                case 3:
                {
                    cout << "Enter the element you want to delete: ";
                    int data;
                    cin >> data;

                    delete_double_hashing(data, double_hashing_table);
                    break;
                }
               case 4:
                {
                    Print_HashTable(n, double_hashing_table);
                    break;
                }
                default:
                {
                    cout << "Invalid\n";
                    continue;
                }
            }
            }
                break;
        }
        default:
        {
            cout << "Please select a valid option.\n";
            continue;
        }
        }
    }

    return 0;
} // end of main::

int search_separate_chaining(int key, Node *chain_array[])
{
    int pos = ::hash(key);
    Node *start = chain_array[pos];

    while (start != nullptr)
    {
        if (start->data == key)
        {
            return pos;
        }
        start = start->next;
    }
    return -1;
}

void insert_separate_chaining(int key, Node *chain_array[])
{
    int pos = ::hash(key);

    if (chain_array[pos] == nullptr) // when no LL is present
    {
        chain_array[pos] = new Node;
        chain_array[pos]->data = key;
        chain_array[pos]->next = nullptr;
    }
    else if (chain_array[pos]->data == key) // adding an element
    {
        cout<<"Element is already present"<<endl;
        return;
    }
    else // adding another node to LL
    {
        Node *temp = new Node;
        temp->data = key;
        temp->next = chain_array[pos]; //here the linked list is inserted prepend
        chain_array[pos] = temp;
    }
}

void delete_separate_chaining(int key, Node *chain_array[])
{
    int pos = ::hash(key);

    Node *current = chain_array[pos];
    Node *prev = nullptr;

    while (current != nullptr && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "element not found";
        return;
    }

    if (prev == nullptr)
    {
        chain_array[pos] = current->next;
        delete current;
    }
    else
    {
        prev->next = current->next;
        delete current;
    }

    cout << "The element has been deleted\n";
}

int search_linear_probing(int key, int linear[])
{
    int pos = ::hash(key);

    while (linear[pos] != -1)
    {
        if (linear[pos] == key)
        {
            return pos;
        }
        pos = (pos + 1) % SIZE;
    }
    return -1;
}

int insert_linear_probing(int key, int linear[])
{
    int pos = ::hash(key);
    int probe = 0;

    if (search_linear_probing(key, linear_probing_table) != -1)
    {
        return -1;
    }

    while (linear[pos] != -1 && linear[pos] != -2)
    {
        pos = (pos + 1) % SIZE;
        probe++;
    }

    linear[pos] = key;
    return probe;
}

void delete_linear_probing(int key, int linear[])
{
    int pos = ::hash(key);

    if (search_linear_probing(key, linear_probing_table) == -1)
    {
        cout << "The entered number was not found in the hash table.\n";
        return;
    }

    while (linear[pos] != -1)
    {
        if (linear[pos] == key)
        {
            linear[pos] = -1;
            cout << "The element has been deleted.\n";
            return;
        }
        pos = (pos + 1) % SIZE;
    }
}

int search_quadratic_probing(int key, int quadratic[])
{
    int pos = ::hash(key);

    int i = 1;
    while (quadratic[pos] != -1)
    {
        if (quadratic[pos] == key)
        {
            return pos;
        }
        pos = (pos + i * i) % SIZE;
        i++;
    }
    return -1;
}

int insert_quadratic_probing(int key, int quadratic[])
{
    int pos = ::hash(key);
    int probe = 0;

    int i = 1;
    while (quadratic[pos] != -1 && quadratic[pos] != -2)
    {
        pos = (pos + i * i) % SIZE;
        probe++;
        i++;
    }

    quadratic[pos] = key;
    return probe;
}

void delete_quadratic_probing(int key, int quadratic[])
{
    int pos = ::hash(key);

    if (search_quadratic_probing(key, quadratic_probing_table) == -1)
    {
        cout << "The entered number was not found in the hash table.\n";
        return;
    }

    int i = 1;
    while (quadratic[pos] != -1)
    {
        if (quadratic[pos] == key)
        {
            quadratic[pos] = -1;
            cout << "The element has been deleted.\n";
            return;
        }
        pos = (pos + i * i) % SIZE;
        i++;
    }
}

int search_double_hashing(int key, int double_hash[])
{
    int pos = ::hash(key);
    int second = second_hash(key);
    while (double_hash[pos] != -1 && double_hash[pos] != -2)
    {
        if (double_hash[pos] == key)
        {
            return pos;
        }
        pos = (pos + second) % SIZE;
    }
    return -1;
}

int insert_double_hashing(int key, int double_hash[])
{
    int pos = ::hash(key);
    int probe = 0;
    int second = second_hash(key);

    while (double_hash[pos] != -1 && double_hash[pos] != -2)
    {
        pos = (pos + second) % SIZE;
        probe++;
    }

    double_hash[pos] = key;
    return probe;
}

void delete_double_hashing(int key, int double_hash[])
{
    int pos = ::hash(key);
    int second = second_hash(key);

    if (search_double_hashing(key, double_hash) == -1)
    {
        cout << "The entered number was not found in the hash table.\n";
        return;
    }

    while (double_hash[pos] != -1)
    {
        if (double_hash[pos] == key)
        {
            double_hash[pos] = -1;
            cout << "The element has been deleted.\n";
            return;
        }
        pos = (pos + second) % SIZE;
    }
}

// Function to display hash table
void Print_HashTable(int n, int table[])
{

    cout << "Elements in the hash table and their indices are-\n";

    cout << " Array index   \t\t  Data \n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "      " << i << "                  " << table[i] << "  \n";
    }

    cout << "NOTE: -1 denotes Empty location\n";
}

void DisplayLL(Node *chain_array[])
{
    cout << "\n\n"
         << endl;
    cout << "Array index \t\tData\t\n";

    for (int i = 0; i < SIZE; i++) // Iterate over the whole pointer array
    {
        Node *start = chain_array[i];
        Node *ptr = start;

        while (ptr != nullptr) // Check whether there's an LL
        {
            cout << "   " << i << "\t"
                 << "\t\t" << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    cout << "\n"
         << endl;
}
