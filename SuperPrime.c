//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。
#include<stdio.h> 
int isPrime(int x);
int splitNum(int x, int num[]);

int main()
{
	int num[4];
	int i,a,s;
	float ss,count;
	float average;
	ss=0;
	count=0;
	for(i=100;i<1000;i++){
		if (isPrime(i)==0){
			splitNum(i,num);
			a=num[0]+num[1]+num[2];
			s=num[0]*num[0]+num[1]*num[1]+num[2]*num[2];
			if((isPrime(a))==0 && (isPrime(s))==0){
				printf("%d\n",i);
				ss=ss+i;
				count++;
			}
		}
	}
	for(i=1000;i<10000;i++){
		if (isPrime(i)==0){
			splitNum(i,num);
			a=num[0]+num[1]+num[2]+num[3];
			s=num[0]*num[0]+num[1]*num[1]+num[2]*num[2]+num[3]*num[3];
			if((isPrime(a))==0 && (isPrime(s))==0){
				printf("%d\n",i);
				ss=ss+i;
				count++;
			}
		}
	}
	average=ss/count;
	printf("%f",average);
	
    return 0;
}

int isPrime(int x)
{
	int i;
	for(i=2;i<x;i++){
		if(x%i==0){
			return 1;
		}
	}
	return 0;
}
int splitNum(int x, int num[])
{
	if(x>100 && x<1000){
		num[0]=x%10;
		num[1]=(x%100-num[0])/10;
		num[2]=x/100;
	}
	else if(x>1000 && x<10000){
		num[0]=x%10;
		num[1]=(x%100-num[0])/10;
		num[2]=(x/100)%10;
		num[3]=x/1000;
	}
	return 0;
}
