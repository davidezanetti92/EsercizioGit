#include <stdio.h>
#include <stdlib.h>


int main(){

printf("Quanti numeri Vuoi sommare: ");
int da_sommare;
scanf("%d",&da_sommare);
int count =0;

int *array;
array=malloc(da_sommare*sizeof(int));

int sum=0;
while(count<da_sommare){
printf("[%d] : ",count+1);
scanf("%d",&array[count]);
sum = sum + array[count];
count++;
}

count=0;

while(count<da_sommare){
printf("%d - ",array[count]);
count++;
}

printf("\n%d\n",sum);

}
