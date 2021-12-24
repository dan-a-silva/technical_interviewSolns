#include <bits/stdc++.h>
#include <unordered_map>
// Add any extra import statements you may need here

using namespace std;

int check_neighbor(vector<int> r,int i,int k,int count){
  
  
  
  if(i >= k){
    if(r[i]>r[i-k]){

    count++;
     k++;
    return check_neighbor(r,i,k,count);
    }
    else{ return count;}
  } 
  else{
   return count;
  
  }

  
  
}


int check_neighborR(vector<int> r,int i,int k,int count){
  
  
  
  if(i+k < r.size()){
    if(r[i]>r[i+k]){

    count++;
     k++;
    return check_neighborR(r,i,k,count);
    }
    else{ return count;}
  } 
  else{
   return count;
  
  }

  
  
}

// Add any helper functions you may need here


vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
  vector<int> L(arr.size(),1);
  std::unordered_map<int , int> u;
  int i = 3;
   vector<int>::iterator nextone;
   vector<int>::iterator it2;
   vector<int>::iterator it1;
  
  int right=1;
  int n=0;
  int test=0;
  int count1 = 0;
  int k =1;
 for(int i =0; i<arr.size(); i++){
   L[i] += check_neighbor(arr,i,1,count1);
   L[i] += check_neighborR(arr,i,1,count1);


  }

  
  for(std::vector<int>::iterator it= L.begin(); it!=L.end(); ++it){
    cout<< " " <<*it ;
  }
  cout <<endl;
  
  return L;
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

  vector <int> test_1{3, 4, 1, 6, 2};
  vector <int> expected_1{1, 3, 1, 5, 1};
  vector <int> output_1 = CountSubarrays(test_1);
  check(expected_1, output_1);

  vector <int> test_2{2, 4, 7, 1, 5, 3};
  vector <int> expected_2{1, 2, 6, 1, 3, 1};
  vector <int> output_2 = CountSubarrays(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
