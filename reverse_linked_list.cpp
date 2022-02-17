struct Node{
  
  int data;
  
  Node * link;
  
  
};

Node * head == NULL;


Void reverseList(){
  
 Node *p, *c, *n;
  
 p = NULL:
  
 c = head;
  
  while(c != NULL){
    
    n = c -> link;
    
    c->link = p;
    
    p = c;
    
    c = n;
    
  }
  
  head = p;
  
  
}
