#include <iostream>
using namespace std;

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

void insertBack(node* &head, int d){
	node * temp = new node(d);
	if(head == NULL){
		head = temp;
		return;
	}
	node * ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	//temp->next = NULL; no  need since we already created constructor
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

node* &takeInputReference(){
	node * head = NULL;
	int d;
	cin>>d;
	while(d!= -1){
		insertBack(head,d);
		cin>>d;
	}

	//cout<<&head<<endl;
	return head;
}

void print(node*head){
	node * temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

int main(){

	node* head = takeInput();  // head now gets address of 1st node of linked list
	print(head); // sending value of head

	// this is a wrong, it will work here but this not the right way to implement because
	// we making a reference variable(head_ref) of that variable(head) whose scope is inside
	// the function takeInputReference()
	// When memory allocated for head gets freed after takeInputReference() execution, it makes no sense to make reference
     // pointer variable head_ref of that pointer variable head that does not exist any more.
	node* &head_ref = takeInputReference();
	cout<<&head_ref<<endl;
	print(head_ref); // sending value of head
	return 0;
}
