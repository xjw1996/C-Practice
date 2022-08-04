#include<stdio.h>
#include<stdlib.h>


//1,1,2,3,5,8,13,21,34,55,89,144,233

int fun(int n){

	if(n<0)
		return -1;
	if(n==1 || n==2)
		return 1;
	
	return fun(n-1)+fun(n-2);
}


int main(){

	int n,res;
	
	scanf("%d",&n);

	res=fun(n);

	printf("Fib[%d]",res);

	return 0;
	
}


