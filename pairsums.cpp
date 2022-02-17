#include <bits/stdc++.h>
#include <unordered_map>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

vector<int> twoSum(vector<int> & nums, target){
  vector<int> target_indices;
  
  unordered_map<int,int> hash_table;
  for(int i =0; i < num.size(); i++){
    
    int second_integer = target - nums.at(i);
    
    if(hash_table.find(second_integer) !=  hash_table.end() ){
      
      target_indices.push_back(i);
      target_indices.push_back(hash_table.find(second_integer)->second);
      break;
      
    }else{
    
        hash_table[nums.at(i)] = i;
    
    }
  }
  
  
  return target_indices;
  
}
