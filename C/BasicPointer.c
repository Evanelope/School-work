#include <stdio.h>

int main(){
int num1 = 5, num2 = 15;
int *p1, *p2;
p1 = &num1;
p2 = &num2;
*p1=13;
*p2= *p1;
p1=p2;
*p1=20;
printf("the value of num1 is %d", num1);
printf("the value of num2 is %d", num2);
return 0;
}
