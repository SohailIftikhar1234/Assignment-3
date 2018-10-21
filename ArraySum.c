#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int sum100(int*,int);
int sumYet=0,finalSum=0;
#define BufferSize 1000

int main(){
	int piped[2],array[BufferSize],sum=0;
	printf("hello ");
	int ret=pipe(piped);
	if(ret==-1){
	 perror("pipe");
	 exit(1);
	}
    for(int i=0;i<1000;i=i+100){
	  int pid=fork();
	     if(pid==0){
		sum=sum100(array,i);
		write(piped[1],&sum,sizeof(sum));
		exit(0);
	      }//if ends

	else{
		wait(NULL);
		read(piped[0],&sumYet,sizeof(sumYet));
		finalSum+=sumYet;
          }//else ends
    }//for loop ends
	printf("Sum is : %d ",finalSum);
}
	

int sum100(int *arr,const int i){
		int sum=0;
	    for(int v=i;v<i+101;v++){
		arr[v]=v;
		sum=sum+v;
	    }
	printf("%d ",sum);
  return sum;
}
