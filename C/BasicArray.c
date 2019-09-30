#include <stdio.h>
void shiftArray(int array[], int len);
int main(){
	int array[2];
	int len = 2;
	 for(int i=0;i<len;i++){
		 array[i] = i;
	 }
	 for(int i=0; i<len; i++){
		 printf("%d\n", array[i]);
	}
	shiftArray(array, len);
	for(int i=0; i<len; i++){
		 printf("%d\n", array[i]);
	}
	
}
void shiftArray(int array[], int len){
	int temp = array[0];
	int temp2;
	for(int i=0; i<len; i++){		
		if(i == len-1) array[0] = temp;
		else{
			temp2 = array[i+1];
			array[i+1] = temp;
			temp = temp2;
			
		}
	}
}
