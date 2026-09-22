/* Linked List - Single 
   A linked list is a linear data structure where elements are stored as nodes and are connected using pointers. These nodes are
   scattered in memory unlike arrays where it is contigous block. The node consists of 2 parts 
	1. data      - this stores the value using primitive data types(int,char,double,float) or it can be built in like arrays, or it can 
					user defined types like struct ,union etc.
	2. pointer   - this stores the address of another node.
*/
#include<stdio.h>
#include<stdlib.h>


struct node{
	int          data; //this stores value
	struct node* next; //this stores address of any other node
};

struct node* head=NULL;
struct node* tail=NULL;

//create node
struct node* create_node(int); //param1 = information(data part) ; returns the address of the new node 

//operations - insert
void insert_at_head(int);      //param1 = information(data part) ;
void insert_at_tail(int);      //param1 = information(data part) ;

//operations - delete
void delete_at_head();      //delete head and move head to next node in the list
void delete_at_tail();      //delete tail and move tail to prev node in the list

//traverse
void traverse_list();    //traverse the linked list from head to tail
void free_list();       //free memory of the linked list from head to tail
int main(){
	
	//perform linked list operation - insert
	//insert at head
	insert_at_head(10);
	traverse_list();
	insert_at_head(20);
	traverse_list();
	
	insert_at_tail(30);
	traverse_list();
	insert_at_tail(40);
	traverse_list();
	
	delete_at_tail();
	traverse_list();
	
	delete_at_head();
	traverse_list();
	
	free_list();
	return 0;
}
void insert_at_head(int input_data){
	//step1 create a new node
	struct node* new_node = create_node(input_data); //create the new node
	if(new_node==NULL) return; //memory allocation failed
	//step2 check if head is NULL if true make head and tail as new node
	//else make new_node next point to current head and then move head to new_node
	if(head==NULL){
		head = new_node;
		tail = new_node;
	}else{
		new_node->next = head; //new_node's next point to current head
		head = new_node; //move head to new node & dont touch tail here
	}
}
void insert_at_tail(int input_data){
	//step1 create a new node
	struct node* new_node = create_node(input_data); //create the new node
	if(new_node==NULL) return; //memory allocation failed
	//step2 check if head is NULL if true make head and tail as new node
	//else make tail's next point to new_node and then move tail to new_node
	if(head==NULL){
		head = new_node;
		tail = new_node;
	}else{
		tail->next = new_node; // tail's next point to new_node
		tail = new_node; //move tail to new node & dont touch head here
	}
}

void delete_at_tail(){
	struct node* temp = NULL;
	struct node* old_tail = NULL;
	if (head==NULL){
		//linked list is empty
		printf("Linked list is empty!!!...cannot perform delete.");
	}else{
		//delete node from head and make the next node as new head
		if (head==tail){
			head = tail = NULL;
		}else {
			// Find the node just before tail
            temp = head;
            while (temp->next != tail){
                temp = temp->next;
            }
            printf("\nNode before tail = %d", temp->data);

            // Save the old tail
            old_tail = tail;

            // Make temp the new tail
            tail = temp;

            // New tail should point to NULL
            tail->next = NULL;

            // Free the old tail
            free(old_tail);
			printf(".....Tail deleted...");
		}
	}
}
void delete_at_head(){
	struct node* temp = NULL;
	struct node* old_head = NULL;
	if (head==NULL){
		//linked list is empty
		printf("Linked list is empty!!!...cannot perform delete.");
	}else{
		//delete node from head and make the next node as new head
		
		//store the old head in temp
		temp = head;
        
		// Move to next node and make it head
		head = temp->next;

        // free the old head
        free(temp);
		if (head==NULL){
			tail=NULL;
		}
		printf("\nHead deleted...");	
	}
}

struct node* create_node(int input_data){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("memory allocation failed.....");
		return NULL;
	}
	new_node->data = input_data; //fill the data part wiht input received from the parameter
	new_node->next = NULL;       //for safety we insert NULL and make it NULL POINTER
	return new_node;
}
void traverse_list(){
	//traversal using temp node pointer
	struct node* temp = head;
	printf("\nList Traversal[ ");
	while(temp!=NULL){
		printf("%d->", temp->data);
		temp = temp->next; //move to next node
	}
	printf("NULL ]");
}
void free_list(){
	//traversal using temp node pointer
	struct node* temp = head;

	while(temp!=NULL){
		head = temp->next;
		free(temp);
		temp = head;
	}
	tail = NULL;
	printf("\nmemory freed!");
}
