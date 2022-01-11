#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

// Add any helper functions you may need here

void leftview(Node * node, int level, auto & map){
  if(node == nullptr) return;
  
  if(map.find(level) == map.end()){
    map[level] = node->data;
  }
  
  leftview(node->left,level+1,map);
  leftview(node->right,level+1,map);
  
}


int visibleNodes(Node* root) {
  // Write your code here
  
  int cnt = 0;
  
  unordered_map<int,int> map;
  
  leftview(root,1,map);
    
  for(int i = 1; i<= map.size();i++)
    cout << map[i] << " ";
  
  
  return map.size();
  
}

