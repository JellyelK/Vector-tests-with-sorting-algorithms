#include <iostream>
#include <cstdlib>   // for srand e rand
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//function just to print the array
void printArray(vector<int> &v){
	int n=v.size();
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

//function to swap elements
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}


//--------------------------------sort algorithms---------------------------

//+++++++++++++++++++++++merge sort++++++++++++++++++++++++++++++
void merge(vector<int> &v, int low, int high, int mid){
	int i, j, k, c[1000];
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

    // Vetor Size
    int tamanho = 1000;

    // Creates a vector with random numbers
    vector<int> vetor(tamanho);
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;  // Numbers from 0 to 999
    }
    
    //Vetors Backup for sort algorithms
    vector<int> v_buble = vetor;
    vector<int> v_selection = vetor;
    vector<int> v_insertion = vetor;
    vector<int> v_shell = vetor;
    vector<int> v_quick = vetor;
    vector<int> v_merge = vetor;
    
    
    //Sort algorithms
    
     //Time BubbleSort
    auto inicio_bubble = high_resolution_clock::now();
    bubbleSort(v_buble);
    auto fim_bubble = high_resolution_clock::now();
    duration<double> tempo_bubble = fim_bubble - inicio_bubble;
    
    //Time Selection Sort
    auto inicio_selection = high_resolution_clock::now();
    selectionSort(v_selection);
    auto fim_selection = high_resolution_clock::now();
    duration<double> tempo_selection = fim_selection - inicio_selection;
    
    //Time Insertion Sort
    auto inicio_insertion = high_resolution_clock::now();
    insertionSort(v_insertion);
    auto fim_insertion = high_resolution_clock::now();
    duration<double> tempo_insertion = fim_insertion - inicio_insertion;
    
    //Time Shell Sort
    auto inicio_shell = high_resolution_clock::now();
    shellSort(v_shell);
    auto fim_shell = high_resolution_clock::now();
    duration<double> tempo_shell = fim_shell - inicio_shell;
    
    //Time Quick Sort
    auto inicio_quick = high_resolution_clock::now();
    quickSort(v_quick, 0, v_quick.size() - 1);
    auto fim_quick = high_resolution_clock::now();
    duration<double> tempo_quick = fim_quick - inicio_quick;
    
    // Tempo Merge Sort
    auto inicio_mergin = high_resolution_clock::now();
    mergeSort(v_merge, 0, v_merge.size() - 1);
    auto fim_mergin = high_resolution_clock::now();
    duration<double> tempo_merge = fim_mergin - inicio_mergin;
    
    cout << "Tempo Bubble Sort: " << fixed << tempo_bubble.count() << " segundos" << endl;
    cout<<" "<<endl;
    cout << "Tempo Selection Sort: " << fixed << tempo_selection.count() << " segundos" << endl;
    cout<<" "<<endl;
    cout << "Tempo Insertion Sort: " << fixed << tempo_insertion.count() << " segundos" << endl;
    cout<<" "<<endl;
    cout << "Tempo Shell Sort: " << fixed << tempo_shell.count() << " segundos" << endl;
    cout<<" "<<endl;
    cout << "Tempo Quick Sort: " << fixed << tempo_quick.count() << " segundos" << endl;
    cout<<" "<<endl;
    cout << "Tempo Merge Sort: " << fixed << tempo_merge.count() << " segundos" << endl;
   
  
    

    return 0;
}
