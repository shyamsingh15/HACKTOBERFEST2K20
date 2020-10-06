#include <iostream>
using namespace std;
  
//Function to swap two elements. 
void swap(int* x, int* y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
/* Partition function to do Partition
elements on the left side of pivot elements would be smaller than pivot
elements on the right side of pivot would be greater than the pivot
*/
int partition (int array[], int low, int high) 
{ 
    //Pivot element selected as right most element in array each time.
    int pivot = array[high];    
    int swapIndex  = (low - 1);   //swapping index.
  
    for (int j = low; j <= high- 1; j++) 
    { 
        //Check if current element is smaller than pivot element.
        if (array[j] < pivot) 
        { 
            swapIndex ++;    //increment swapping index.
            swap(&array[swapIndex], &array[j]); 
        } 
    } 
    swap(&array[swapIndex + 1], &array[high]); 
    return (swapIndex + 1); 
} 
  
//Recursive function to apply quickSort
void quickSort(int array[], int low, int high) 
{ 
    if (low < high) 
    { 
       /* indexPI is partitioning index, partition() function will 
        return index of partition */
        int indexPI  = partition(array, low, high); 
  
        quickSort(array, low, indexPI  - 1);  //left partition
        quickSort(array, indexPI  + 1, high); //right partition
    } 
} 
  
//Function to display the array
void display(int array[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<< array[i]<<"\t"; 
} 
  
//Main function to run the program
int main() 
{ 
    int array[] = {7, 9, 1, 3, 5, 2, 6, 0, 4, 8}; 
    int size = sizeof(array)/sizeof(array[0]);
    cout<<"Before Sorting: \n";
    display(array, size);
    quickSort(array, 0, size-1); 
    cout<<"After Sorting: \n"; 
    display(array, size); 
    return 0; 
}
