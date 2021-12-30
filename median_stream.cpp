#include <bits/stdc++.h>
#include <cmath>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

void swap(int * x, int * y){
  int temp = *x;
  *x = *y;
  *y = temp;
   
}



void addnumber(int number,priority_queue<int>& lowers, priority_queue<int> & uppers){
 if(lowers.size()==0 || number < lowers.top() ){
    lowers.push(number);
    //cout << "lowerr : " << lowers.size() <<"\n";
  }
   else{
    uppers.push(-number);
     //cout << "uppers : " << uppers.size() <<"\n";
   }
}
  
void rebalance(priority_queue<int> & lowers , priority_queue<int>& uppers){
 priority_queue<int> larger = lowers.size() > uppers.size() ? lowers :uppers;
 priority_queue<int> smaller= lowers.size() > uppers.size() ? uppers :lowers;
  
  if(larger.size()-smaller.size()>=2){
    smaller.push(-larger.top());
    larger.pop();
     
  if(smaller.top() > larger.top()){
    uppers = smaller;
    lowers = larger;
  }
  else{
    uppers = larger;
    lowers = smaller;
  }
  }
 

}

int getMedian(priority_queue<int> lowers , priority_queue<int> uppers){
 priority_queue<int> larger = lowers.size() > uppers.size() ? lowers :uppers;
 priority_queue<int> smaller= lowers.size() > uppers.size() ? uppers :lowers;
  
  if(larger.size()==smaller.size()){
    //cout<< abs((smaller.top()-larger.top())/2) << " <-- average \n";
    return abs((smaller.top()-larger.top())/2);
  }
  else {
    // cout<< abs(larger.top()) << " <-- median \n";
    return abs(larger.top());
  }
  
}


vector <int> findMedian(vector <int> arr) {
  // Write your code here
  
  vector<int> medians(arr.size());
    
  priority_queue<int> lowers; //lower heap
  
  priority_queue<int> uppers; //upper heap // min heap
  
  //MinHeap b2(arr.size()); //upper heap
  
  for(int i = 0; i< arr.size();i++){
    int number = arr[i];
    addnumber(number,lowers,uppers);
    rebalance(lowers,uppers);
    medians[i] =  getMedian(lowers,uppers);
  }
  
  
  return medians;
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
  vector <int> arr_1{5, 15, 1, 3};
  vector <int> expected_1{5, 10, 5, 4};
  vector <int> output_1 = findMedian(arr_1);
  check(expected_1, output_1);

  vector <int> arr_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{2, 3, 4, 3, 4, 3};
  vector <int> output_2 = findMedian(arr_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
