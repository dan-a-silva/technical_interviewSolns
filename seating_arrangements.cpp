#include <bits/stdc++.h>
#include <cmath>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(vector<int> & arr,int low, int high)
{  
  int pivot = arr[high];
  int i = (low -1);
  
  for(int j = low; j<= high-1;j++){
    
    if(arr[j] <= pivot){
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  
  return(i+1);
   
  
}



int awkwardness(vector <int>  arr){
 // int awk =0;
  int k;
  
  int awk = abs(arr[arr.size()-1]-arr[0]);
  int prosp;
  
  for(int i =0; i< arr.size()-1;i++){
    
    /*if(i==arr.size()-1){
      k=0;
    }
    else {k=i+1;}
    //cout << abs(arr[i]-arr[k])<< " ";*/
    prosp = abs(arr[i]-arr[i+1]);
    if(prosp>awk){
      awk = prosp;
    }
  }
  
  return awk;
}


void display(vector<int> a){
  for(int i =0; i<a.size();i++){
    cout << a[i] << " ";
  }
  //cout <<endl;
  
}

void quicksort(vector<int> & arr, int low, int high){
 
  if(low < high)
  {
    int pi = partition(arr,low,high);
    
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
  }
  
}

int minOverallAwkwardness(vector <int> arr) {
  // Write your code here
  vector <int> arr1 = arr;
  
  //quick_sort(arr);
  
  int total_awkward = 0;
  
  //display(arr);
    
  int i =1;
  
  quicksort(arr,0,arr.size()-1);
  //display(arr);
  //cout << endl;
  int temp = awkwardness(arr);
  int prospect;
  
  while(next_permutation(arr.begin(),arr.end())){
    //display(arr);
    //cout<< " : " << awkwardness(arr) << endl; 
   prospect = awkwardness(arr);
   if(prospect<temp){
      temp = prospect;
    }
    //i++;
  } 

  
  return temp; 
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <int> arr_1{5, 10, 6, 8};
  int expected_1 = 4;
  int output_1 = minOverallAwkwardness(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{1, 2, 5, 3, 7};
  int expected_2 = 4;
  int output_2 = minOverallAwkwardness(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
