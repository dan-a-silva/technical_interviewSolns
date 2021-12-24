#include <bits/stdc++.h>
#include <unordered_map>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int binarySearch(vector<int> & arr, int item, int low, int high){
  if(high <= low)  
    return(item > arr[low])? (low +1): low;
  int mid = (low + high)/2;
  
  if(item == arr[mid]){
    return mid+1;
  }
  if(item > arr[mid]){
    return binarySearch(arr,item,mid+1,high);
    return binarySearch(arr,item,mid-1,high);
  }
}

void BinaryInsertionSort(vector<int> & arr, int n){
  int i,loc,j,k,selected;
  for(i=1;i<n;i++){
    j =i-1;
    selected = arr[i];
    loc = binarySearch(arr,selected,0,j);
    while(j>=loc){
      arr[j+1] = arr[j];
      j--; 
    }  
    arr[j+1] = selected;
  }
}

int numberOfWays(vector<int> arr, int k) {
  // Write your code here
  
 // BinaryInsertionSort(arr,arr.size());
  
//  for(std::vector<int>::iterator it =arr.begin(); it != arr.end(); ++it){
  //  cout<< " " <<*it;
  //}
  cout <<endl;
  
  //int high=arr.size()-1,low=0;
  
  //cout<< "high " << high <<endl;
  
  int numberofways =0;
  int amountofkover2 =0;
  
for(int i=0;i<arr.size();i++){
     /* if(arr[high]+arr[low]==k && high != low && arr[high] !=k/2 ){
        
        numberofways++;
        //cout << "high: " << high << "low: " << low  << "number of ways" << numberofways<<endl;
        low++;
      }
    if(arr[high]+arr[low]<k){
      low++;
    }
      if(arr[high]+arr[low]>k){
      high--;
    }*/
  if(arr[i] == k/2){
    amountofkover2++;
  }
}
    
  int pairs = amountofkover2*(amountofkover2-1)/2;
  //cout << "number of ways" << numberofways <<endl;
  
  //numberofways += pairs;
  
  unordered_map<int,int> map;
  
  for(int i =0; i<arr.size();i++){
    map.insert({i,arr[i]});
  }
  
  for(int i =0; i<arr.size()/2+1;i++){
    
    //cout<< "key " << k-arr[i] <<endl;
    if(map.find(k-arr[i])!=map.end() && arr[i] != k/2){
      //cout<< "pair found (" << arr[map[k-arr[i]]]<< " , " << arr[i]<< " )"<<endl;
      numberofways++;
      
    }
     map[arr[i]] =i;
    
    
  }
  //cout << "Pair not found"<<endl;
  
  numberofways += pairs;


  return numberofways;

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

  int k_1 = 6;
  vector <int> arr_1{1, 2, 3, 4, 3};
  int expected_1 = 2;
  int output_1 = numberOfWays(arr_1, k_1);
  check(expected_1, output_1);

  int k_2 = 6;
  vector <int> arr_2{1, 5, 3, 3, 3};
  int expected_2 = 4;
  int output_2 = numberOfWays(arr_2, k_2);
  check(expected_2, output_2);

  
  int k_3 = 6;
  vector <int> arr_3{1, 5, 3, 3, 3, 5,4};
  int expected_3 = 5;
  int output_3 = numberOfWays(arr_3, k_3);
  check(expected_3, output_3);
  // Add your own test cases here
  
}
