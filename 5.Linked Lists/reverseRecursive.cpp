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

node * takeInput(int n){
	node * head = NULL;
	int d;
	int i = 0;
	while(i < n){
		cin>>d;
		insertBack(head,d);
		i++;
	}

	return head; 
	//sending value of head or data(which is address of 1st node of ll) inside head to head in main
}

void reverseRecursive(node* &head, node*first, node *rest){
	if(head == NULL){
		return ;
	}
	if(rest->next == NULL){
		head = rest;
		rest->next = first;
		return;
	}
	reverseRecursive(head,rest,rest->next);
	rest->next = first;
	first->next = NULL;
}

void print(node*head){
    if(head == NULL)    return;
	node * temp = head;
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data;
}

int main(){
	int n;
	cin>>n;
	node *head;
	head = takeInput(n); 
	reverseRecursive(head,head,head);
	print(head);
	return 0;
}