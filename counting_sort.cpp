#include <iostream>

void countSort(int array[], int size) {
  int output[10];
  int count[10];
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into entered array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print sorted array
void printArray(int array[], int size) {
	cout<<"\n Output Array:";
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
  cout<<"*********************************************************";
}

int main() {
  int arr[100],n,i;
  cout<<"********************************************************";
  cout<<"\n\t\t"<<"COUNTING SORT\n";
  cout<<"********************************************************";
  cout<<"\nplease enter the how many elements you are willing to enter:";
  cin>>n;
  cout<<"Please enter numbers to the array:";
  for(i=0;i<n;i++)
  cin>>arr[i];
  countSort(arr, n);
  printArray(arr, n);
  return 0;
}
