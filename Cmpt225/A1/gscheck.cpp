#include "char_stack.h"
#include <iostream>

using namespace std;

void print(char A[250], int j){
int tab=0,l;
j++;
// Print Function
for(int i=0; i<j; i++){ // print the error line until the error
	l= i;
	cout << A[i] ; // print out every element on the error line
	if( A[i] == '\t' ) tab++; // count the taps for every '\t'
}

cout << endl;
l++;

for (int k=0; k < tab; k++) cout << '\t'; // print tabs counted
for (int j=0; j < l; j++) cout << " ";  // print spaces counted	
for (int o=l; o < cin.gcount(); o++) cout << A[o];// print the remaining error line
cout << endl;

}

int main (){
	
  	char_stack s;
	int i,j,k,line=1,word_count;//line starts at 1 and others 0
	char c,l,g,p;
	char A[250]; //250 word per line in A
	
	if (cin.peek()!=cin.eof() ){ // make sure the next value isnt end of value input
		while(cin.getline(A,250)){	// count the characters while searching the array one by one
			
			for(i=0;i<cin.gcount();i++){ 
				
				c=A[i];	// insert every character into variable c
				if(c=='('||c=='['||c=='{'){ // push on stack when opening brackets
					s.push(c);
				}
				else if(c==')'||c==']'||c=='}'){ // when closing brackets	
					if(s.empty()){		 // if stack is empty
						cout<<"Error on line "<<line;
						cout<<": too many "<<c<<endl;		
						print(A,i);
						return 0;
					}
					l=s.pop();		// pop the top of the stack to match		
					if(l=='('&&c!=')'){ 	// when ( doesn't match )		
						p = ')';
						cout<<"Error on line "<<line; // Report error line
						cout<<": Read "<<c;
						cout<<", expected "<<p<<endl;
						print(A,i);	
						return 0;
					}
					else if(l=='['&&c!=']'){	// when [ doesn't match ]		
						p = ']';
						cout<<"Error on line "<<line;// Report error line
						cout<<": Read "<<c;
						cout<<", expected "<<p<<endl;
						//cout<<"USED IT";
						print(A,i);
						return 0;
					}
					else if(l=='{'&&c!='}'){ 	// when { doesnt match }
						p = '}';
						cout<<"Error on line "<<line;// Report error line
						cout<<": Read "<<c;
						cout<<", expected "<<p<<endl;
						print(A,i);
						return 0;
					//cout<<cin.gcount(); (for testing cin.gcount amount every loop)
					}
					
				
				}word_count=cin.gcount(); // save word count for future use
			}
		i++;	//add until error line reached
		line++;
		}
	
	}
	
	if ( !s.empty()){  // stack is not empty 
		l=s.pop();  // pop the top of stack and print it
		line--;//last loop added one more line and i
		i--;
		//cout<<"line"<<line;
		//cout<<"i"<<i;
		//cout<<"g"<<word_count;
		if(i==word_count){
		cout<<"Error at end of file";// Report error at end of file
		cout<<": Too many "<<l<<endl;
		}
		return 0;
	}
	else{

	cout<<"No Errors Found"<< endl; // No erros found
	return 1;
	}
}
