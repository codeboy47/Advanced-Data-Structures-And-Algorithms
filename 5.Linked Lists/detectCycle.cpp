#include <iostream>
using namespace std;

// Floyd Cycle

class node{
public:
	int data;
	node * next;
	// constructor
	node(int d) : data(d) , next(NULL) { }

	// destructor
	~node(){
		if(next!=NULL)
			delete next;
	}
};

node* isPresent(node*head, int d){ 
	node * ptr = head;
	while(ptr != NULL ){
		if(ptr->data == d)	return ptr;
		ptr = ptr->next;
	}
	return NULL;
	
}

void insertBack(node* &head, int d){
	static bool flag;
	node * temp = new node(d);
	if(head == NULL){
		flag = false;
		head = temp;
		return;
	}

	if(flag == false){
		node * ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}		
		node * n = isPresent(head,d);
		if(n != NULL){
			flag = true;
			delete temp;
			ptr->next = n;
		}else{	
			ptr->next = temp;
			//temp->next = NULL; no  need since we already created constructor
		}
	}
}

node * takeInput(){
	node * head = NULL;
	int d;
	cin>>d;
	while(d!= -1){
		insertBack(head,d);
		cin>>d;
	}

	return head; 
	//sending value of head or data(which is address of 1st node of ll) inside head to head in main
}

void detectCycle(node* head){ // no call by reference as we are not changing head
	node *slowPtr = head, *fastPtr = head->next;
	while(fastPtr && fastPtr->next){
		if(slowPtr == fastPtr)	break;
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	if(slowPtr == fastPtr){ // loop exists
		slowPtr = head;
		//node * prev = fastPtr;
		while(slowPtr != fastPtr->next){
			slowPtr = slowPtr->next;
			//prev = fastPtr;
			fastPtr = fastPtr->next;
		}
		fastPtr->next = NULL;
		//prev->next = NULL;
	} 
}

void print(node*head){ 
	node * temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	node *head;
	head = takeInput();  // head now gets address of 1st node of linked list
	detectCycle(head);
	print(head); // sending value of head
	return 0;
}