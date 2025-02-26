#include <iostream>
#include <vector>

// Use the standard namespace to avoid prefixing standard library elements
using namespace std;

// Define constants for the maximum number of processes and resources
const int MAX_PROC = 10;  // Maximum number of processes
const int MAX_RES = 10;   // Maximum number of resources

// Function to display a matrix with a label
/**
 * Displays a matrix with a given label.
 * 
 * @param mat The matrix to be displayed.
 * @param process The number of processes (rows in the matrix).
 * @param resources The number of resources (columns in the matrix).
 * @param label The label to be displayed before the matrix.
 */
void displayMatrix(int mat[MAX_PROC][MAX_RES], int process, int resources, const string &label) {
    cout << label << " Matrix:" << endl;
    cout<<"     ";
     for(int i=0;i<resources;i++){
        cout<<"R"<<i<<"      ";
    }

    cout<<endl;
    for (int i = 0; i < process; ++i) {
        cout<<"P"<<i<<"   ";
        for (int j = 0; j < resources; ++j) {
            cout << mat[i][j] << "       ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to display a vector with a label
/**
 * Displays a vector with a given label.
 * 
 * @param vec The vector to be displayed.
 * @param size The size of the vector.
 * @param label The label to be displayed before the vector.
 */


void displayVector(int vec[MAX_RES], int size, const string &label) {
    cout << label << ": ";
   


    for (int i = 0; i < size; ++i) {
        cout << vec[i] << "      ";
    }
    cout << endl << endl;
}


bool bankersAlgorithm(int process, int resources,
                      int available[MAX_RES],
                      int maxNeed[MAX_PROC][MAX_RES],
                      int allocated[MAX_PROC][MAX_RES],
                      int seq[MAX_PROC]) {
    int needed[MAX_PROC][MAX_RES];  
    bool completed[MAX_PROC] = {false}; 
    int remaining[MAX_RES]; 

    // Initialize the remaining resources
    for (int i = 0; i < resources; ++i) {
        remaining[i] = available[i];
    }

    // Step 1: Compute the need matrix
    cout << "Calculating the Need Matrix:" << endl;
    for (int i = 0; i < process; ++i) {
        for (int j = 0; j < resources; ++j) {
            needed[i][j] = maxNeed[i][j] - allocated[i][j];
        }
    }

    displayMatrix(needed, process, resources, "Need");

    // Step 2: Find a safe sequence
    int index = 0;
    cout << "Searching for a Safe Sequence:" << endl;
    for (int k = 0; k < process; ++k) {
        bool foundProcess = false;
        for (int i = 0; i < process; ++i) {
            if (!completed[i]) {
                bool canAllocate = true;
                for (int j = 0; j < resources; ++j) {
                    if (needed[i][j] > remaining[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    cout << "Process " << i  << " can safely run." << endl;
                    for (int j = 0; j < resources; ++j) {
                        remaining[j] += allocated[i][j];
                    }


                    seq[index++] = i + 1;
                    completed[i] = true;
                    foundProcess = true;
               
                }
            }
        }
        if (!foundProcess && index!=process ) {
            cout << "No safe sequence found in this iteration." << endl;
            return false;
        }
    }
    return true;
}

// Main function
int main() {
    int process, resources;  // The number of processes and resources

    // Input the total number of processes and resources
    cout << "Enter the total number of processes (Max " << MAX_PROC << "): ";
    cin >> process;
    cout << "Enter the total number of resources (Max " << MAX_RES << "): ";
    cin >> resources;

    int available[MAX_RES];  // The available resources
    int maxNeed[MAX_PROC][MAX_RES];  // The maximum resources required by each process
    int allocated[MAX_PROC][MAX_RES];  // The resources allocated to each process

    // Input the available resources
    cout << "Input available resources: ";
    for (int i = 0; i < resources; ++i) {
        cin >> available[i];
    }

    // Input the maximum resources required by each process
    cout << "Enter the maximum resources required by each process:" << endl;
    for (int i = 0; i < process; ++i) {
        for (int j = 0; j < resources; ++j) {
            cin >> maxNeed[i][j];
        }
    }

    // Input the resources allocated to each process
    cout << "Enter the resources allocated to each process:" << endl;
    for (int i = 0; i < process; ++i) {
        for (int j = 0; j < resources; ++j) {
            cin >> allocated[i][j];
        }
    }

    // Display the initial resource status
    cout << "\nInitial Resource Status:" << endl;
    displayVector(available, resources, "Available Resources");
    displayMatrix(maxNeed, process, resources, "Maximum Resource");
    displayMatrix(allocated, process, resources, "Allocated Resource");

    int seq[MAX_PROC] = {0};  // The sequence of processes

    bankersAlgorithm(process, resources, available, maxNeed, allocated, seq);

    return 0;
}