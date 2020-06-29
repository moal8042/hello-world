#include <iostream>
#include<cmath>
class BigPrime {
public:
	 BigPrime(long long n) : num(n){
  }
  virtual bool isPrime() const {
  	  for(int i=5;i<sqrt(num);i+=6){
  	  	if(num%i==0 || num%(i+2)==0)
  	  		return false; 
	  }
    return true;
  }
private:
  const int num;
}; 
class Set {
public:
  Set(long int sz);
  ~Set();
  bool add(BigPrime *bp);
//  bool remove(BigPrime *bp);
  int count() const {
  	int r = 0;
  	for (int i = 0; i < index; i++) {
  	  if (pset[i]->isPrime())
  	    r += 1;
	  }
  	return r;
  }
private:
  BigPrime **pset;
  int size, index;
};
class BigSuperPrime : public BigPrime {
public:
  BigSuperPrime(long long n = 0) : BigPrime(n), num(n){
  	//Split
  	long long tem = n;
  	long long tsum=0,tmulti=1,tsquaresum=0;
	  while(tem > 0) {
	  	long long t = tem % 10;
	  	tem /= 10;
	    //Set.add(t);  
	  	tsum+=t;
		tmulti*=t;
		tsquaresum+=(t*t);
	  } 
	  psum=new BigPrime(tsum);
	  pset->add(psum);
	  pmulti=new BigPrime(tmulti);
	  pset->add(pmulti);
	  psquaresum=new BigPrime(tsquaresum); 
	  pset->add(psquaresum);
  }
  virtual bool isPrime() const {
  	if (psum->isPrime()&&pmulti->isPrime()&psquaresum->isPrime())
	    return true; 
  	return false;
  }
private:
  long long num;
  Set *pset;
  BigPrime *psum;
  BigPrime *pmulti;
  BigPrime *psquaresum;
};

int main() {
  Set (1000);
  BigSuperPrime bp(1284792492104), bp1(364293419);
  Set.add(&bp);
  Set.add(&bp1);
  std::cout << Set.count() << std::endl;
  return 0;
}
