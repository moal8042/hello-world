#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {
  	  size = 0;
  	}
  	SuperPrime(int n):number(n) {
  	  size = 0;
  	  split();  //它就是构造对象 
	}

  	bool isSuperPrime() {
  	  
  	  SuperPrime a(sum());   //将普通整数转变为对象 
	  SuperPrime b(multi());
	  SuperPrime c(squareSum());
	  if (isPrime() && a.isPrime() && b.isPrime() && c.isPrime())
	    return true; 
  	  return false;
	}
	
  private:
  	
  	const int number;
  	SuperPrime *N[1000];
	int size;
  	bool isPrime() { 
  	  for(int i = 2; i < number; i++){
        if (number % i == 0) 
            return false;
      }
    	return true;
	}
	void split{ 
	 else  if(number<10){
	  	size=1;
	  	return;
	  } 
	  int temp = number;
	  while(tem> 0) {
	  	int n = tem % 10;
	  	tem /= 10;
	  	N[size] = new SuperPrime(n);   //构造对象 
	  	size += 1;
	  } 
	} 
	int sum() {
	  int s=0;
	  for(int i=0;i<size;i++){
	  	s+=N[i]->number;
	  }	
	  return s;
	}
	int multi() {
	  int mul=1;
	  for(int i=0;i<size;i++){
	  	mul*=N[i]->number;
	  }
	  return mul;
	  return mul;	
	}
	int squareSum() {
	  int s2=0;
	  for(int i=0;i<size;i++){
	  	s2=s2+N[i]->number*N[i]->number;
	  }
	  return s2;	
	}
}; 
class Set {
  public:
  	Set(int from, int to) {
  	  size = 0;
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;

	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;
};
int main() {
  SuperPrime sp(113);
  if (sp.isSuperPrime())
    std::cout << "113 is SuperPrime" << std::endl;
  else
    std::cout << "113 is NOT SuperPrime" << std::endl;
  return 0;
}
