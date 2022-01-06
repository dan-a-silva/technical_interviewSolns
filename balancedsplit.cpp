#include<bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std; 

// Add any helper functions you may need here


bool balancedSplitExists(vector<int>& arr){
  // Write your code here
  
  
  int lsum =0;
  
  for(int i =0; i< arr.size(); i++){
     lsum += arr[i];
  }
  
  int rsum = 0;
  
  sort(arr.begin(),arr.end());
  
  //for(int i = 0; i< arr.size();i++){
    //cout << arr[i] << " ";
    
  //}
  
  for(int i = arr.size()-1 ; i>=0; i--){
    
    rsum += arr[i];
    
    lsum -= arr[i];
    
    if(rsum == lsum && arr[i] > arr[i-1])
      return 1;
  }
  
  return 0;
}
