/*Arrays basic operations
1. insert   - insert_at_begin, insert_at_index, insert_at_end 
2. delete   - delete_at_begin, delete_at_index, delete_at_end
3. traverse 
*/
#include<stdio.h>
#define MAX_SIZE 5
int curr_index = 0; //global index for array
void insert_at_begin(int[],int);
void insert_at_index(int[],int,int);//param1-array name,param2-index (0 based) positon is 1 based,param3-value
void insert_at_end(int[],int);//param1-array name,param2=value

void delete_at_begin(int[]);//param1-array name
void delete_at_end(int[]);//param1-array name
void delete_at_index(int[],int);////param1-array name,param2=index(0 based) positon is 1 based
void display_array(int[]);//param1-array name
int get_array_value_from_user();//
int get_array_index_from_user();//

void show_menu();
int main(){
	int my_arr[MAX_SIZE]={0};//array declared and initialised to zero
	int choice = 0,index,value;
	do{
		//show menu
		show_menu();
		scanf("%d",&choice);
		
		switch(choice){
			case 1: value = get_array_value_from_user();
					insert_at_begin(my_arr,value);
					break;
			case 2: value = get_array_value_from_user();
			        index = get_array_index_from_user();
					insert_at_index(my_arr,index, value);
					break;
			case 3: value = get_array_value_from_user();
					insert_at_end(my_arr, value);
					break;
			case 4: 
					delete_at_begin(my_arr);
					break;
			case 5: 
			        index = get_array_index_from_user();
					delete_at_index(my_arr,index);
					break;
			case 6: 
					delete_at_end(my_arr);
					break;	
			case 7: display_array(my_arr);
					break;
			case 8: break;
			default: printf("\nInvalid choice please enter value between 1 to 8...");
		}
		
		//insert operations
	}while(choice!=8);
	printf("\nThank You! Exited the application successfully!!!");
	return 0;
}
int get_array_index_from_user(){
	int user_input;
	printf("\nEnter the index :");
	scanf("%d",&user_input);
	return user_input;
}
int get_array_value_from_user(){
	int user_input;
	printf("\nEnter the value :");
	scanf("%d",&user_input);
	return user_input;
}
void show_menu(){
	printf("\n****************************ARRAY OPERATIONS - TRAVERSE , INSERT, DELETE*****************************");
	printf("\nOption 1. INSERT AT BEGIN   		\tOption 4. DELETE AT BEGIN");
	printf("\nOption 2. INSERT AT INDEX   		\tOption 5. DELETE AT INDEX");
	printf("\nOption 3. INSERT AT END     		\tOption 6. DELETE AT END");
	printf("\nOption 7. TRAVERSE(DISPLAY ARRAY) \tOption 8. Exit");
	printf("\n\nEnter your choice[option 1-8]: ");
}
void delete_at_begin(int arr[]){
	delete_at_index(arr,0);
}
void delete_at_index(int arr[],int index){
	int deleted_value = arr[index];
	if(index<0 || index>=MAX_SIZE){
		printf("\nInvalid index(%d)!!!",index); //out of bound
		return;
	}
	if(curr_index<=0){
		printf("\nArray is empty...cannot delete value!!!");
		return;
	}
	for(int i=index;i<curr_index-1;i++){
		arr[i] = arr[i+1]; //left shifting
	}
	arr[curr_index]=0; //make the last element initialised to 0
	curr_index--; //decrement the size by 1
	printf("\ndeleted %d successfully...",deleted_value);
}
void delete_at_end(int arr[]){
	if(curr_index<=0){
		printf("\nArray is empty...cannot delete value!!!");
		return;
	}
	printf("\ndeleted %d successfully...",arr[curr_index-1]);
	arr[curr_index--]=0;//make last element 0(delete) and decrease the size by 1
	
}
void display_array(int arr[]){
//param1-array name
	printf("\nArray-Elements[CURR SIZE:%d] :",curr_index);
	for(int i=0;i<curr_index;i++){
		printf("%d ",arr[i]);
	}
}
void insert_at_begin(int arr[],int value){
	insert_at_index(arr,0,value);
}
void insert_at_index(int arr[],int index,int value){
	if(curr_index>=MAX_SIZE){
		printf("\nArray is full...cannot insert %d value!!!",value);
		return;
	}
	for(int i=curr_index-1;i>=index;i--){
		arr[i+1]=arr[i];//shift right
	}
	arr[index]= value;//populate the value at index
	printf("\nInserted %d value @%d index successfully.",value,index);
	curr_index++; //increment the size by 1 after insertion
}
void insert_at_end(int arr[],int value) {
//parm1-which array,param2=value
	if(curr_index>=MAX_SIZE){
		printf("\nArray is full...cannot insert %d value!!!",value);
		return;
	}
	arr[curr_index++]=value; //after inserting increment the size by 1
	printf("\nInserted %d value successfully.",value);
}
