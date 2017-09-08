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

node* merge(node* a,node *b){
	node*c = NULL;
	if(a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}
	if(a->data <= b->data){
		c = merge(a->next,b);
		a->next = c;
		c = a;	
	}
	else if(a->data > b->data){
		c = merge(a,b->next);
		b->next = c;
		c = b;
	}
	return c;
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
	int t;
	cin>>t;
	node *head1,*head2;
	while(t--){
		int n1,n2;
		cin>>n1;
		head1 = takeInput(n1);
		cin>>n2;
		head2 = takeInput(n2);
		head1 = merge(head1,head2);
		print(head1);
		cout<<endl;
	}
	return 0;
}