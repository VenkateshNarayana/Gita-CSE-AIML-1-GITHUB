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

int main(){
	struct node node1, node2, node3, node4;
	//lets insert data into each node
	//node1 is my head
	node1.data  = 10;
	node1.next  = &node2; //use & operator(addres of) to store the address of node2
	
	node2.data = 20;
	node2.next = &node3; //store address of node3
	
	node3.data = 30;
	node3.next = &node4; //store address of node4
	
	//node4 is my tail
	node4.data = 40;
	node4.next = NULL; //becuause node4 is the tail it will not be connected to any other node. This is my terminating node
	
	//let us travers the linked list
	printf("My Linked list[ ");
	printf("%d->",node1.data);       //fetch data of node1 using "." dot operator
	printf("%d->",node1.next->data); //fetch node2 data using next (pointer)
	printf("%d->",node1.next->next->data); //fetch node3 data using next (pointer)
	printf("%d->",node1.next->next->next->data); //fetch node4 data using next (pointer)
	printf("null ]\n");
	
	//traversal using temp node pointer
	struct node* temp = &node1;
	printf("\nList Traversal[ ");
	while(temp!=NULL){
		printf("%d->", temp->data);
		temp = temp->next; //move to next node
	}
	printf("NULL ]");
	
	
	return 0;
}

