#include <iostream>
class BigPrime {
public:
  BigPrime(long int n) : num(n){
  }
  virtual bool isPrime() const {
    return false;
  }
private:
  const int num;
}; 
class BigSuperPrime : public BigPrime {
public:
  BigSuperPrime(int n) : BigPrime(n), num(n){
  }
  virtual bool isPrime() const {
    return true;
  }
private:
  const int num;
};
template <class T>
class Set {
public:
  Set(int sz);
  ~Set();
 
  bool add(T *bp);
  bool remove(T *bp);
  int count() const {
  	int ret = 0;
  	for (int i = 0; i < index; i++) {
  if (pset[i]->isPrime())
  	    ret += 1;
	  }
  	return ret;
  }
  int sum() const {
  	return 0;
  } 
private:

  T **pset;
  int size, index;
};
int main() {
 
  Set<BigPrime> set(1000);
  BigSuperPrime bp(2), bp1(3);
  set.add(&bp);
  set.add(&bp1);
  std::cout << set.count() << std::endl;
  return 0;
} 


template <class T>
Set<T>::Set(int sz):size(sz) {
  index = 0;

  pset = new T*[size];  //分配存储空间 
}


template <class T>
Set<T>::~Set() {
  delete[] pset;  //回收 
}


template <class T>
bool Set<T>::add(T *bp) {
  pset[index++] = bp;
  return true;
}
