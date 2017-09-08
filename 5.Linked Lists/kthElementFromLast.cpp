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

int kthElementFromLast(node*head, int k){

	if(head == NULL)	return 0;

	node*slow = head, *fast = head;
	int i = 0;
	while(i < k){
		i++;
		fast = fast->next;
	}
	while(fast ){
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}

void print(node*head){ 
	node * temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}

int main(){
	node *head;
	head = takeInput();  // head now gets address of 1st node of linked list
	int k;
	cin>>k;
	cout<<kthElementFromLast(head,k);
	return 0;
}