#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


int minLengthSubstring(string s, string t) {
  // Write your code here
  
  map<string,int> location;
  
  int loc = 0;
  
  for(int i=0; i< t.size();i++){
    
    
    auto temp = s.find(t[i]);
    
    if(temp  == -1) return -1;
    
    else{s.erase(s.begin()+temp);}
    
    if(temp > loc){
      cout << temp << " ";
      loc = temp;
    }
    
  }
  
  return loc+1;
}

