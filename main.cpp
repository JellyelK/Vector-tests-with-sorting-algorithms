#include <iostream>
#include <cstdlib>   // for srand and rand
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//function to swap elements
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}


//--------------------------------sort algorithms---------------------------

//+++++++++++++++++++++++merge sort++++++++++++++++++++++++++++++
void merge(vector<int> &v, int low, int high, int mid){
    int i, j, k, c[1000]; // Adjustment necessary for vectors larger than 1000 elements.
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (v[i] < v[j]){
            c[k] = v[i];
            k++;
            i++;
        }
        else{
            c[k] = v[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        c[k] = v[i];
        k++;
        i++;
    }
    while (j <= high){
        c[k] = v[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++){
        v[i] = c[i];
    }
}

void mergeSort(vector<int> &v, int low, int high){
    if(low<high){
        int mid;
        mid = (low+high)/2;
        mergeSort(v, low, mid);
        mergeSort(v, mid+1, high);
        merge(v,low,high,mid);
    }

}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++quick sort++++++++++++++++++++++++++++++
int partition(vector<int> &v, int low, int high){
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (v[j] < pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
    if (low < high) { 
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




//shell sort
void shellSort(vector<int> &v){
    /*
        Parameters:
        v = input array to be ordered
    */
    int n=v.size();
    for (int h=n/2; h>0;h/=2){
        for (int i=h;i<n;i+=1){
            int temp=v[i];
            int j;
            for (j=i;j>=h && v[j-h]>temp;j-=h)
                v[j]=v[j-h];
            v[j]=temp;
        }
    }
}

//insertion sort O(n²)
void insertionSort(vector<int> &v){
    /*
        Parameters:
        v = input array to be ordered
    */
    int n=v.size();
    int i,key,j;
    for(i=1;i<n;i++){
        key=v[i];
        j=i-1;
        while(j>=0&&v[j]>key){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=key;
    }
}


//bubble sort O(n²)
void bubbleSort(vector<int> &v){
    /*
        Parameters:
        v = input array to be ordered
    */
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            } 
        }
    }
}

//selection sort O(n²)
void selectionSort(vector<int> &v){
    /*
        Parameters:
        v = input array to be ordered
    */
    int min_idx;
    int n=v.size();
    for(int i=0;i<n-1;i++){
        min_idx=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min_idx])
                min_idx=j;
        }
        if(min_idx!=i){
            int temp=v[min_idx];
            v[min_idx]=v[i];
            v[i]=temp;
        }
    }
}

//Execution of the algorithms

int main() {
    // Random number generator 
    srand(time(nullptr));

    // Vector Size
    int size = 1000;

    // Creates a vector with random numbers
    vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;  // Numbers from 0 to 999
    }
    
    // Backup vectors for sort algorithms
    vector<int> bubble_array = array;
    vector<int> selection_array = array;
    vector<int> insertion_array = array;
    vector<int> shell_array = array;
    vector<int> quick_array = array;
    vector<int> merge_array = array;
    
    
    //Sort algorithms
    
     //Time BubbleSort
    auto start_bubble = high_resolution_clock::now();
    bubbleSort(bubble_array);
    auto end_bubble = high_resolution_clock::now();
    duration<double> time_bubble = end_bubble - start_bubble;
    
    //Time Selection Sort
    auto start_selection = high_resolution_clock::now();
    selectionSort(selection_array);
    auto end_selection = high_resolution_clock::now();
    duration<double> time_selection = end_selection - start_selection;
    
    //Time Insertion Sort
    auto start_insertion = high_resolution_clock::now();
    insertionSort(insertion_array);
    auto end_insertion = high_resolution_clock::now();
    duration<double> time_insertion = end_insertion - start_insertion;
    
    //Time Shell Sort
    auto start_shell = high_resolution_clock::now();
    shellSort(shell_array);
    auto end_shell = high_resolution_clock::now();
    duration<double> time_shell = end_shell - start_shell;
    
    //Time Quick Sort
    auto start_quick = high_resolution_clock::now();
    quickSort(quick_array, 0, quick_array.size() - 1);
    auto end_quick = high_resolution_clock::now();
    duration<double> time_quick = end_quick - start_quick;
    
    // Time Merge Sort
    auto start_merge = high_resolution_clock::now();
    mergeSort(merge_array, 0, merge_array.size() - 1);
    auto end_merge = high_resolution_clock::now();
    duration<double> time_merge = end_merge - start_merge;
    
    cout << "Time Bubble Sort: " << fixed << time_bubble.count() << " seconds" << endl;
    cout<<" "<<endl;
    cout << "Time Selection Sort: " << fixed << time_selection.count() << " seconds" << endl;
    cout<<" "<<endl;
    cout << "Time Insertion Sort: " << fixed << time_insertion.count() << " seconds" << endl;
    cout<<" "<<endl;
    cout << "Time Shell Sort: " << fixed << time_shell.count() << " seconds" << endl;
    cout<<" "<<endl;
    cout << "Time Quick Sort: " << fixed << time_quick.count() << " seconds" << endl;
    cout<<" "<<endl;
    cout << "Time Merge Sort: " << fixed << time_merge.count() << " seconds" << endl;
   
  
    

    return 0;
}
