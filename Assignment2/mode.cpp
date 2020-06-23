#include <iostream>
#include <fstream>
using namespace std;

// Here I've left the code as I found it, to show you
// a contrasting (and in my opinion, nowhere near as clear)
// style.  Many C++ coders have this style.


// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode

//I have created a merge sort which takes O(nlog(n)) time and will increase the efiiciency of my program on a large scale
void merge(long arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    long A[n1], B[n2];
    for (i = 0; i < n1; i++){        
    	A[i] = arr[l + i]; 
    }
    for (j = 0; j < n2; j++){ 
        B[j] = arr[m + 1+ j]; 
    }
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2){ 
        if (A[i] <= B[j]){ 
            arr[k] = A[i]; 
            i++; 
        } 
        else{ 
            arr[k] = B[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1){ 
        arr[k] = A[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        arr[k] = B[j]; 
        j++; 
        k++; 
    } 
} 
  
// The concept of merge sort is divind the array into two recursively and then sorting two already sorted arrays.
void mergeSort(long arr[], int l, int r){ 
    if (l < r){ 
        
        int m = l+(r-l)/2;
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

long mode (long *arr, int n) {
  // TO DO:: Fill in this function.
	if(n==0){  // in case the array is empty
		return -1;
	}
	long max_number =arr[0];  // this stores the number which occurs max
	if(n==1){ // in case there is only one element
		return arr[0];
    }// I know I didn't need this because i was saving max number as the first element but i wanted to make my code more clear
    mergeSort(arr,0,n);
    long check =arr[0];
    int number_count=1; // this counts the occurences
    int max_count=1;    //this stores which element has the maximum count in the array

    for(int i=0;i<n-1;i++){
    	
    	if(arr[i+1]==check){
    		number_count++;
    	}
    	else{
    		if(number_count>max_count){ // checks which has more count
    			max_count=number_count;
    			max_number=check;
    		}
    		check=arr[i+1];
    		number_count=1;
    	}
    }
    if(number_count>max_count){ // This is if the last element is same as the second last element then we have to check again
    			max_number=check;
    		}
	return max_number;// returns the maximum element
}







// Input is the number of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.
int main (int argc,  char* argv[]) {

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
	int n;
	long *arr;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a number:" << endl;
		cin >> arr[i];
	}

	long m = mode(arr,n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();
    // Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}
