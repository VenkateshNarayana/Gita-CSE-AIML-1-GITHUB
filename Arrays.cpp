/*Write a program to input and display 5 array elements.*/
#include<stdio.h> //prepocessor directives
//global declarations
void print_array(int[],int);
void accept_user_input(int[],int);
int main(){
	int arr1[5];              //method 1 - declaraing with size
//	printf("\nArray1 Elements:");
	int size = sizeof(arr1)/sizeof(int);
	//take user input
	accept_user_input(arr1,size);
	//display the output
	print_array(arr1,size);
	
	int arr2[5]={1,2,3,4,5};  //method 2 - declaring with size and initializing
	size = sizeof(arr2)/sizeof(int);
	print_array(arr2,size);
	
	int arr3[] = {10,20,30,40,50,60}; //method 3- declaring without size but initialising values
	size = sizeof(arr3)/sizeof(int);
	print_array(arr3,size);
}
//function definitions
void accept_user_input(int arr[],int size){
	printf("Enter the data for %d elements.\n",size);
	for (int i =0;i<size;i++){
		printf("Enter the %d element: ",i+1);
		scanf("%d",&arr[i]);
	}
}
void print_array(int arr[],int size){
	printf("\nArray Elements:[%d]",size);
	for (int i =0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
