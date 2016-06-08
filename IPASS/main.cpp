#include "hwlib.hpp"

int main (void){
	WDT->WDT_MR = WDT_MR_WDDIS;
	int matrix[8][8] = {{}, 
						{}, 
						{}, 
						{}, 
						{}, 
						{}, 
						{}, 
						{}}
	int dummy[8][8];
	
	copy_matrix(matrix, dummy, 8, 8);
	
	return 0;
}

void copy_matrix(const int * tocopy, int * copy, int x, int y,){
	
}