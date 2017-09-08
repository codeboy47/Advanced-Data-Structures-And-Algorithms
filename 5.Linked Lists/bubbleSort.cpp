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


void bubbleSort(node* & head, int n){
	int i;
	for(i = 0; i < n-1; i++){
		node*curr = head, *prev = NULL, *next = head->next;
		while(curr && curr->next){
			if(curr->data > next->data){
				if(prev == NULL){
    				curr->next = next->next;
    				next->next = curr;
    				head = next;
    				prev = next;
    				next = curr->next;
				}
				else{
					prev->next = curr->next;
					curr->next = next->next;
					next->next = curr;
					prev = next;
					next = curr->next;
				}
			}else{
				prev = curr;
				curr = curr->next;
				next = next->next;
			}
		}
	}
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
	node *head;
	int n;
	cin>>n;
	head = takeInput(n);
	bubbleSort(head,n);
	print(head);
	cout<<endl;
	return 0;
}