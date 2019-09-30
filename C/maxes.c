//Evan Meyerhoff
// Prints maxes until no more numbers are available.
// CS306 3/22/2019
#include <stdio.h>
void find_array_maxes(int array[], int size);

int main(){	
	int array[10] = {4,7,2,6,54,78,95,12,51,85};
    int size = sizeof(array)/sizeof(int);
    find_array_maxes(array,size);
}


//input is the array and the size of the array/
//output: Print statement of the current max.
void find_array_maxes(int array[], int size){
    int max = 0;
        
        for(int i=0;i<size; i++){ 
            for(int i=0;i<size; i++){
                if(array[max] < array[i])max = i;
            }
            printf("%d ", array[max]);
            array[max] = 0;
        }
}
