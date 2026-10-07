/* Queue using Single Linked List - it is a linear data structure where elements are called nodes which are connected to each other using pointers.
   `	These nodes are scattered in memory unlike elements of an array which are stored in contigous memory location.
   		The node consists of 2 parts,
			1. data       - This stores the information of data(primitive,arrays,strings,user defined type)
			2. pointer    - This stores the address information of anothere node.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	  int 			data;  //this is part1(information)
	  struct node* 	next;  //this is part2(pointer)
};
struct node* head = NULL;
struct node* tail = NULL;

//creating a node
struct node* create_node(int); //param1 - input data to store the part1(data- which is information part)

//insert
void enqueue(int input_data);


//delete
void dequeue();

//traverse
void traverse();
void free_list();

//peek operations and underflow check
int is_empty(); //if list is empty return 1 else 0
void peek_front();
void peek_rear();

int main(){
	
	//insert operations - enqueue
	enqueue(10);
	peek_front();
	peek_rear();
	
	enqueue(20);
	enqueue(30);
	traverse();
	
	dequeue();
	peek_front();
	peek_rear();
	dequeue();
	dequeue();
	traverse();
	
	free_list();  //this our clean up activity to prevent memory leaks
	return 0;
}
int is_empty(){
	return (head==NULL); //return 1 if list is empty else 0
}
void peek_front(){
	if(is_empty()){
		printf("\nQ is empty!!");
	}else{
		printf("\nFRONT=%d",head->data);
	}
}
void peek_rear(){
	if(is_empty()){
		printf("\nQ is empty!!");
	}else{
		printf("\nREAR=%d",tail->data);
	}
}
void enqueue(int input_data){
	//create a new node
	struct node* new_node = create_node(input_data);
	
	if(new_node==NULL) return; //memory allocation failed
	if(tail==NULL){
		//if linked list is empty then make the new node as head and tail
		head = new_node;
		tail = new_node;
	}else{
		//if linked list is NOT empty then point tail to the new node & move tail to new node
		tail->next = new_node; //point tail to new node 
		tail = new_node;       //move tail to new node
	}
	printf("\nInserted %d (at tail)into linked list Successfully!!",input_data); 
}
void dequeue(){
	if(head==NULL){
		//linked is empty
		printf("\nLinked list is empty..cannot perform delete operation!!");
	}else{
		//step1 : store the address of head into temp
		struct node* temp = head;
		int deleted_data = head->data;
		//step2 : move the head to next node
		head = head->next;
		//step : free the temp
		free(temp);
		printf("\nDeleted %d from linked list Successfully!!",deleted_data); 
	}
	
}
struct node* create_node(int input_data){  
	//param1 - input data to store the part1(data- which is information part)
	//use malloc to create the struct node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("memory allocation failed.....");
		return NULL;
	}
	new_node->data = input_data; //store the input data into data part of the new node
	new_node->next = NULL ;      //store NULL in the pointer part
	return new_node;
}
void traverse(){
	if(is_empty()){
		printf("\nMy Queue[ empty ]");		
	}else{
		struct node* temp;
		temp=head;
		printf("\nMy Queue[");
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("null]");
	}
}

void free_list(){
	if(head!=NULL){ //if list is not empty then ONLY free all the nodes
		struct node* temp;
		temp=head;
		while(head!=NULL){
			temp = head;      //store head into temp
			head = head->next;//move head to next node
			free(temp);       //free the old head
		}
		printf("\nAll noded are freed Successully!!");
	}
}
