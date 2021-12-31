#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void swap(int * x, int * y){
  int temp = *x;
  *x = *y;
  *y = temp;
  
}


bool check(vector <int> arr1, vector <int> arr,int i){

  if(arr1[i]<= arr[i] ){
    return 1;
  }
  else return 0;
  
}


vector <int> findMinArray(vector <int> arr, int k) {
  // Write your code here
  
  vector<int> arr1 =arr;
  
 cout << arr.size()-1 << " ";
 // int i =0;

  for(int i = 0; i < arr.size()-1; i++){
      if(k>0){
    swap(&arr1[k],&arr1[k-1]);
    if(check(arr1,arr,k-1)){
      k--;
    }
    else{
    swap(&arr1[k],&arr1[k-1]);
      } 
  }
    else {break;}
 }
  
       // swap(&arr[0],&arr[1]);

  
  return arr1;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  int n_1 = 3, k_1 = 2;
  vector <int> arr_1{5, 3, 1};
  vector <int> expected_1{1, 5, 3};
  vector <int> output_1 = findMinArray(arr_1,k_1);
  check(expected_1, output_1);

  int n_2 = 5, k_2 = 3;
  vector <int> arr_2{8, 9 ,11, 2, 1};
  vector <int> expected_2{2, 8, 9, 11, 1};
  vector <int> output_2 = findMinArray(arr_2,k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
