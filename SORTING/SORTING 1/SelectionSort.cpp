#include <iostream>
#include <cmath>
// selection sort is basically selecting the particular
//  number and placing it to the other place according to the question

void selection_sort(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int mini = i;
      for (int j = i; j < n; j++)
      {
         if (arr[j] < arr[mini])
         {
            mini = j;
         }
      }
      // swap pseudo code
      int temp = arr[mini];
      arr[mini] = arr[i];
      arr[i] = temp;
   }
}

using namespace std;
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   selection_sort(arr, n);

   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " " << endl;
   }
   return 0;

   //time complexity for this is o(n@2)
}