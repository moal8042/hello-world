#include <iostream>
using namespace std;
class SuperPrime {
  public:
  	SuperPrime():number(0) {
}
  	~SuperPrime() {
	}
  	bool isSuperPrime() {
  	  split();
  	  int a = sum();
	  int b = multi();
	  int c = squareSum();
	  if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	int N[100], size;
  	bool isPrime(int n) { 
  	
  	  return false;
	}
	void split() {
// number split into N
	}
	int sum() {
	  return 0;
	}
	int multi() {
	  return 0;
	}
	int squareSum() {
	  return 0;
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
  Set ss(100, 999);

  cout << "How Many: " << ss.count() << endl;
  cout << "Sum is " << ss.sum() << endl;
  return 0;
}
