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

void append(node* &head,int k, int n){
	if(n <= 0)	return;
	else if(k <= 0){
		//head = NULL;
		return;
	}
	else if(head == NULL)	return;
	else if(k >= n){
		k = k%n;
	}
	node * temp = head;
	int i = 0;
	while(i < k){
		temp = temp->next;
		i++;
	}
	node * slowTemp = head;
	while(temp->next != NULL){
		slowTemp = slowTemp->next;
		temp = temp->next;
	}
	temp->next = head;
	head = slowTemp->next;
	slowTemp->next = NULL;
}

void print(node*head){
    //if(n <= 0 || k >= n || k <= 0)  return;
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
	int k;
	cin>>k;
	append(head,k,n);
	print(head);
	return 0;
}