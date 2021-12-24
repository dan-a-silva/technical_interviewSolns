#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int swap(int& x, int& y){
  int temp =x;
  x=y;
  y=temp;
}

class MinHeap{
  int size;
  std::vector<int>::iterator arr;
  
  public:
    MinHeap(int size, vector<int> &input );
    void makee_heap(int i);
    void build_heap();
  
};

MinHeap::MinHeap(int size,vector<int> & input ){
  this->size= size;
  this->arr = input.begin();
  
  build_heap();
  
}

void MinHeap::makee_heap(int i){
  if(i>=size/2)
    return;
  
  int smallest;
  
  int left =2*i+1;
  int right = 2*i+2;
  
  smallest = arr[left] <arr[i] ? left :i;
  
  if(right <size)
    smallest = arr[right] < arr[smallest] ? right :smallest;
   
  if(smallest != i){
    swap(arr[i],arr[smallest]);
    makee_heap(smallest);
  }
  
}

void MinHeap::build_heap(){
  
  for (int i = (size/2) -1; i>=0; i--){
    makee_heap(i);
    //cout << "i is in build heap function " << i <<" size/2 is  " << size/2 <<endl;
  }
  
}

int FirstKelements(vector<int>& arr,int size,int k){
  MinHeap* m = new MinHeap(k,arr);
  int result=1;
  
  for(int i =k; i< size ;i++){
    if (arr[0] > arr[i]){
      continue;
    }
    else{
      arr[0] = arr[i];
      m -> makee_heap(0);
    }
  }
  
  for(int i=0;i<k;i++){
    //cout  <<arr[i] << " ";
    result = result*arr[i];
  }
 return result;
}



vector <int> findMaxProduct(vector<int> arr) {
  // Write your code here
  vector <int> output(arr.size());
  
 
 
  //make_heap(arr.begin(),arr.begin());
  //cout<< "The maximum element is : " << arr.front() <<endl;
  
  //std::heap<int> my_heap;
  /*int i =0;
  for(int i=0;i<=arr.size();i++){
    input[i] = arr[i];
  }*/
  
  for(int i =0; i<arr.size();i++){
    if(i<2){
      output[i]=-1;
    }
    else{
      vector<int> input(arr.begin(),arr.begin()+i+1);
      output[i]=FirstKelements(input,input.size(),3);
     // cout<<endl;
      
    }
  }
  
  //int size = sizeof(input)/sizeof(input[0]);
  
  
  
  
  
  /* vector<int> arr1 = { 11, 3, 2, 1, 15, 5, 4,
                           45, 88, 96, 50, 45 };
 
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
  
  // cout << "size1 is " << size1 <<endl;
 // cout << "arr size is "<< arr1.size()<<endl;
    // Size of Min Heap
    int k = 3; 
 
    FirstKelements(arr1,arr1.size(),k);*/
  
  return output;
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
  vector <int> arr_1{1, 2, 3, 4, 5};
  vector <int> expected_1{-1, -1, 6, 24, 60};
  vector <int> output_1 = findMaxProduct(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{-1, -1, 56, 56, 140, 140};
  vector <int> output_2 = findMaxProduct(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
