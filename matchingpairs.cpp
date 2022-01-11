#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here



int matchingPairs(string s, string t) {
  // Write your code here
  int count = 0;
  
  if(s.size() != t.size()) return 0;
  
  map<char,int> matches;
  
  map<string,int> unmatches_twochars;
  
  map<char,int> unmatchesOnS;
  map<char,int> unmatchesOnT;
  
  int n = s.size();
  
  for(int i  = 0; i< n;i++){
    if(s[i]==t[i]){
      matches[s[i]]++;
      count++;
    }
    else{
      unmatches_twochars[s[i]+""+t[i]]++;
      unmatchesOnS[s[i]]++;
      unmatchesOnT[t[i]]++;
    }
  }
  
  bool repeating = false;
  if(s==t){
    for(auto it: matches)
      if(it.second>1) repeating = true;
    if(repeating) return n;
    else return n-2;
  }
  
  if(count == n-1){
    for(auto it: unmatchesOnS)
      if(matches.find(it.first) != matches.end()) repeating = true;
    if(repeating) return n-1;
    else return n-2;
  }
  
  int res = count;
  
  for(auto it  : unmatches_twochars){
    string rever = it.first;
    swap(rever[0],rever[1]);
    
    if(unmatches_twochars.find(rever)!= unmatches_twochars.end()){
      return res+2;
    }
  }
  
  for(auto it : unmatchesOnS){
    if(unmatchesOnT.find(it.first) != unmatchesOnT.end()){
      return res+1;
    }
    
  }
  
  
  return res;
  
}
