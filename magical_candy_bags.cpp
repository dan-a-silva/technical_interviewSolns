#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void swap(int * x, int * y){
  int temp = *x;
  *x = *y;
  *y = temp;
  
}


class MinHeap{
  int capacity;
  int heap_size;
  int *harr;
  
  public: 
  MinHeap(int cap);
  
  void Minheapify(int );
  
  int parent(int i){ return (i-1)/2;}
  
  int left(int i){ return (2*i+1);}
  
  int right(int i){return (2*i+2);}
  
  int extract_Max();
  
  void increaseKey(int i, int new_val);
  
  int getMax(){return harr[0];}
  
  void deleteKey(int i);
  
  void insertKey(int k);
};

MinHeap::MinHeap(int cap){
  
  heap_size = 0;
  capacity = cap;
  harr = new int[cap];
  
}

void MinHeap::insertKey(int k){
  
  if(heap_size == capacity)
  {
    cout << "\n Overflow could not insert Key \n";
    return;
    
  }
  
  heap_size++;
  int i= heap_size-1;
  harr[i] = k;
  
  while(i!=0 && harr[parent(i)]<harr[i])
  {
    swap(&harr[i],&harr[parent(i)]);
    i=parent(i);
  }
  
}

void MinHeap::increaseKey(int i, int new_val){
  harr[i] = new_val;
  while(i!=0 && harr[parent(i)]<harr[i]){
    swap(&harr[i],&harr[parent(i)]);
    i = parent(i);
    
  }  
}

int MinHeap::extract_Max(){
  
  if(heap_size<=0)
    return INT_MAX;
  if(heap_size==1){
    heap_size--;
    return harr[0];
  }
  
  int root = harr[0];
  harr[0] = harr[heap_size-1];
  heap_size--;
  Minheapify(0);

  return root;
}

void MinHeap::deleteKey(int i){
  increaseKey(i, INT_MAX);
  extract_Max();
  
}

void MinHeap::Minheapify(int i){
  int l = left(i);
  int r = right(i);
  int largest = i;
  
  if(l<heap_size && harr[l] > harr[i])
    largest = l;
  if(r<heap_size && harr[r] > harr[largest])
    largest = r;
  if(largest != i)
  {
    swap(&harr[i],&harr[largest]);
    Minheapify(largest);
    
  }
  
}



int maxCandies(vector <int> arr, int k) {
  // Write your code here
  int output = 0;
  int arr1[arr.size()];
  
  MinHeap h(arr.size());
  
  for(int i = 0; i< arr.size();i++){
    h.insertKey(arr[i]);
  }
  
  int tempKey;
  for(int i =0; i<k;i++){
    tempKey = h.getMax();
    cout << tempKey << " ";
    output +=h.getMax();
    h.deleteKey(0);
    h.insertKey(tempKey/2);
     
  }

  

  
  
  return output;
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

  int k_1 = 3;
  vector <int> arr_1{2, 1, 7, 4, 2};
  int expected_1 = 14;
  int output_1 = maxCandies(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 3;
  vector <int> arr_2{19, 78, 76, 72, 48, 8, 24, 74, 29};
  int expected_2 = 228;
  int output_2 = maxCandies(arr_2, k_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
