#include <iostream>
#include "Deque.h"
using namespace std;

Deque::Deque(){		// constructor
  left_p=right_p=NULL;
  current_size=0;
  cursor=NULL;
}

Deque::~Deque(){		//destructor
if(left_p==NULL) return;
node* pointer = left_p;	//set pointer
while(pointer!=NULL){
	node* next = pointer->next;
	delete pointer;
	pointer=next;
	}
current_size = 0;		//empty Deque size
}

Deque::Deque( const Deque& dq ){	// copy constructor
    
    node* qf_value = new node(0,NULL,NULL);
    qf_value -> data = dq.left_p -> data;
    left_p = qf_value;
    if(dq.left_p ==  NULL){
        left_p = NULL;
	right_p= NULL;
        cursor = NULL;
        return;
    }
    current_size = 1;
    node* current = new node(0,NULL,NULL);
    current = dq.left_p;
   
    node*a = left_p;
    cursor = left_p;
    while(current->next != NULL){
	if(dq.cursor==current){cursor=right_p;}
        right_p = new node(current->next->data,right_p,NULL);
        a->next = right_p;
        current = current->next;
        a = a->next;
        current_size++;
    }

    
    
    return;   
}


int Deque::peek_left(){ 	//return the first value
	if(left_p!=NULL) return left_p->data ;
	return 0;
}

int Deque::peek_right(){				//return rear opinter for TESTING
  if(right_p!=NULL)return right_p->data;
  else return 0;
}


bool Deque::empty(){	//check if empty
	if(left_p==NULL) return 1;
	else return 0;
}

int Deque::size(){	//return size of Deque
	return current_size;
}


void Deque::push_right(int item){
	  if(left_p==NULL){ 
		  node* temp = new node (item,NULL,NULL); //set Deque item to temp
		  left_p=temp;   
		  right_p = temp;
		  cursor=right_p;		       
		  current_size++;	//size implementation
		  
		  }
	  else{	
		  node* temp= new node (item,right_p,NULL);		
		  right_p->next = temp; //traverse the Deque
		  right_p = right_p->next;			       
		  current_size++;// Deque as long as Deque is not empty
		  
		  }
}
void Deque::push_left(int item){

	  if(left_p==NULL){ 
		  node* temp = new node (item,NULL,NULL); //set Deque item to temp
		  left_p=temp;   
		  right_p = temp;
	          cursor=left_p;		       
		  current_size++;
		 
		  }
	
	  else{	
		node* temp = new node (item,NULL,left_p); //set Deque item to temp
		left_p->prev= temp;
		left_p = left_p->prev;
		current_size++;
		
	}
	
	
}

int Deque::pop_left(){
	  if( cursor == left_p) cursor= left_p->next;
 	  if(left_p->next==NULL){ 
		  int data = right_p->data;
		  cursor=right_p = left_p = NULL;
		  current_size--;
		  return data;
	  }
	  else {
		  int data = left_p->data; //saved data value for return
		  node* pointer = left_p;  //cursor to front			
		  left_p=left_p->next;    //set front to its next
		  current_size--;	    //size incrementation
		  delete pointer;	    //delete pointer with its oringal front	
		  return data;			
		  }
}

int Deque::pop_right(){
	  if( cursor == right_p) cursor= right_p->prev;
	  if(left_p->next==NULL){ 
		  int data = right_p->data;
		  right_p = left_p = NULL;
		  cursor=NULL;
		  current_size--;
		  return data;
	  }
	  else{
		  int data = right_p->data; //saved data value for return
		  node* pointer = right_p;  //cursor to front			
		  right_p=right_p->prev;    //set front to its next
		  current_size--;	    //size incrementation  	  
		  right_p->next=NULL;
		  delete pointer;	    //delete pointer with its oringal front	
		  return data;	
		}  		
}


bool Deque::cursor_left(){
	if(cursor->prev!=NULL){cursor=cursor->prev; return 1;}
	else {return 0;}
}
bool Deque::cursor_right(){
	if(cursor->next!=NULL){cursor=cursor->next; return 1;}
	else{return 0;}
}
int Deque::get_cursor(){
	return cursor->data;
}
void Deque::set_cursor(int i){
	cursor->data= i;
	
}

		  



void Deque::display(){ 
  	node *p = left_p;
        if(p ==NULL){
		cout<<"[]";
		cout << " size="<< size();
		cout << ", cursor=NULL"<<endl;
	}
        else{
  	cout << "["; //Nice format!
  	// Traverse the list
  	while (p != NULL){
  		cout << p -> data; // Print data
  		p = p -> next; // Go to next node
  		
  			cout << ";"; // Print a comma unless at the end of the list
  		
  	}
  	cout << "]";
	cout << " size="<< size();
	cout << ", cursor="<<get_cursor()<<endl; 
	}
  }

void Deque::verbose_display(){
     node *p = left_p;
        if(p ==NULL){
		cout<<"[]";
		cout << " size="<< size();
		cout << ", cursor=NULL";
		cout << ", address=NULL"<<endl;
	}
        else{
  	cout << "["<<endl; 
  	// Traverse the list
  	while (p != NULL){
  		cout << "value :" <<p -> data;
		cout << ", address:"<< p  ; // Print data
  		p = p -> next; // Go to next node
  			cout << ";"<<endl; // Print a comma unless at the end of the list
  		
  	}
  	cout << "]" <<endl;
	cout << "size="<< size();
	cout << ", cursor="<<get_cursor()<<endl; 
	

	}

} // like display, but includes node addresses and pointer values.

