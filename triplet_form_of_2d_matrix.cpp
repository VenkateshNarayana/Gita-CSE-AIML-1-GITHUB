/*
2D Matrix in triplet form
Algorithm to convert matrix to triplet form
step1 : create the triplet matrix with dimensions 
	rows = no of non zero elements + 1(header)
	cols = 3

step2: add the header information from the original matrix
	col1 = orignal matrix rows  
	col2 = orignal matrix cols
	col3 = non zero element count
step3: add the (r,c,v)
		r- non zero elements row 
		c- non zero elements col 
		v - value of the non zero element
*/
#include<stdio.h>
int display_2d_matrix(int[][3],int,int);//param1=2d array name, param2=row dimension(2d), param3= col dimension(2d)
int main(){
	int mat_1[3][3]={
					{0,2,0},
					{0,0,1},
					{1,0,0}
					}; 
	int rows=3;
	int cols=3;
	int non_zero_count=0;
	//find the non zero element count
	non_zero_count = display_2d_matrix(mat_1,rows,cols);
	//step1: create the triplet matrix
	int trip_mat1[non_zero_count+1][3];
	//step2: add header
	trip_mat1[0][0] = rows; //original matrix rows
	trip_mat1[0][1]  = cols; //original matrix cols
	trip_mat1[0][2] = non_zero_count;//original non zero element count
	int k = 1; //row counter for the triplet matrix
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			//step3: add the (r,c,v)
			if(mat_1[i][j]!=0){
				trip_mat1[k][0] = i; //original matrix row
				trip_mat1[k][1] = j; //original matrix col
				trip_mat1[k][2] = mat_1[i][j];//original non zero element
				k++; //increment k by 1 for next row
			}
		}
	}
	//Step4: display the triplet form
	display_2d_matrix(trip_mat1,non_zero_count+1,3);
}
int display_2d_matrix(int mat[][3],int rows,int cols){
	int counter=0;
	printf("\nMATRIX:\n");
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			printf("%d ",mat[i][j]);
			if(mat[i][j]!=0){
				counter++;
			}
		}
		printf("\n");
	}
	return counter; //count of non zero elements
}
