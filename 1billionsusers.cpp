#include <bits/stdc++.h>
#include <math.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int getBillionUsersDay(vector <float> growthRates) {
  // Write your code here
  
  
  int start = 1;
  int end = 2000;
  
  double billion = 1000000000;
  
  while(start < end ){
    double growth = 0; 
    
    int mid = start + (end - start)/2;
    
   
    for(int i =0; i< growthRates.size();i++){
      growth += pow(growthRates[i],mid);
    }
    
    if(growth == billion)
      return mid;
    
    if(growth > billion){
      end = mid;}
    else
      start = mid +1;
       
  }
   
  return start;
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

  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
