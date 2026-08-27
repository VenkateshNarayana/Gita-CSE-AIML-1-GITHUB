/*Write a program to input and display sum of elements.*/
#include<stdio.h> //prepocessor directives
//global declarations
void print_array(int[],int);
void accept_user_input(int[],int);
int sum_array_elements(int[],int);
int main(){
	int arr1[5];              //method 1 - declaraing with size
	int size = sizeof(arr1)/sizeof(int);
	//take user input
	accept_user_input(arr1,size);
	//display the output
	print_array(arr1,size);
	//sum array
	printf("\nSum of the array elements is %d",sum_array_elements(arr1,size));
}
//function definitions
int sum_array_elements(int arr[],int size){
	int sum=0;
	for (int i =0;i<size;i++){
		sum +=arr[i]; //sum = sum + arr[i]
	}
	return sum;
}
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
