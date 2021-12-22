#include <bits/stdc++.h>
#include <string>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
/*
string alphabet(int n){
  if(n>=0 && n<=26){
  return "abcdefghijklmnopqrstuvwxyz"[n-1];
  }
}
string Capitalalphabet(int n){
  if(n>=26 && n<=52){
  return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
    }
}*/

bool checkalphnum(int n){
  if( n>=65 && n<=90){
    return 1;}
  if(n>=97 && n<=122 ){
   return 1;
  }
   if(n>=48&& n<=57 ){
   return 1;
  }
  else{ return 0;}
}

string rotationalCipher(string input, int rotationFactor) {
  // Write your code here
  std::string output;
  string:: iterator it;
  char ch;
  
  int alphanewrotationFactor = rotationFactor%26;
  
  int numbernewrotationFactor =rotationFactor%10;
  
  cout << "alphanumericrotaionfactor " <<alphanewrotationFactor << endl;
  cout << "numbernewrotationFactor " <<numbernewrotationFactor << endl;

  
  for(it = input.begin(); it!= input.end();it++){
    cout << *it << " ";

  }
  
     cout <<endl;
    cout << rotationFactor<<endl;
  for(it = input.begin(); it!= input.end();it++){
    if(checkalphnum(*it)){
      if((*it+numbernewrotationFactor)>57 && (*it+numbernewrotationFactor)<65 ){
        cout<< (char) (47+(*it+numbernewrotationFactor)%57) << " ";
        ch = (char) (47+(*it+numbernewrotationFactor)%57);
        output.push_back(ch);
      }
       else if(*it>47 && *it<58){
        cout<< (char) (*it+numbernewrotationFactor) << " ";
        ch = (char) (*it+numbernewrotationFactor);
        output.push_back(ch);
      }
       else if((*it+alphanewrotationFactor)>90 && *it>65 && *it<97){
        cout<< (char) (64+(*it+alphanewrotationFactor)%90) << " ";
        ch = (char) (64+(*it+alphanewrotationFactor)%90);
        output.push_back(ch);
      }
      
       else if((*it+alphanewrotationFactor)>122 ){
        cout<< (char) (96+(*it+alphanewrotationFactor)%122) << " ";
        ch = (char) (96+(*it+alphanewrotationFactor)%122);
        output.push_back(ch);
      }
      
      else{
         cout<< (char) (*it+alphanewrotationFactor) << " ";
        ch = (char) (*it+alphanewrotationFactor);
        output.push_back(ch);
       }
      
    }
    else{
      cout <<  (char) (*it) << " ";
      ch = (char) (*it);
      output.push_back(ch);
    }

  }
  
  cout<< endl;
  
  
  return output;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string input_1 = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  string expected_1 = "Epp-gsrzsCw-3-fi:Epivx5.";
  string output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  string input_2 = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  string expected_2 = "stuvRPQrpq-999.@";
  string output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);
  

  // Add your own test cases here
  
}