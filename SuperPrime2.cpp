#include <iostream>
class Prime {
public:
    Prime():number(0) {
    }
    Prime(int n):number(n) {
    }
    bool isPrime() {
        if (number==0||number==1) return false;
        for (int i=2;i<number;i++){
            if (number%i==0) return false;
        }
        //2��number-1������
        return true;
    }
private:
    const int number;
};
class PrimeSet : public Prime {
public:
    PrimeSet(int size) {
        //���ϵĹ���ʲô��
        set = new Prime*[size];
        this->size = size;
        index = 0;
    }
    ~PrimeSet() {
        for (int i = 0; i < index; ++i)  //���ٶ���
            delete set[i];
        delete[] set;
    }
    int count() {
        int count = 0;
        for (int i = 0; i < size; i++)
            if(set[i]->isPrime())
                count += 1;
        return count;
    }

    bool add(int n) {
        if(index == size)  return false;
        Prime *p = new Prime(n);
        set[index] = p;
        index += 1;
        return true;
    }
    bool isAllPrime() {
        for(int i = 0; i < index; i++)
            if (!set[i]->isPrime())
                return false;
        return true;
    }
private:
    Prime **set;
    int size, index;
};

class SuperPrime : public Prime{
public:
    SuperPrime():number(0), pset(3) {  //Ϊʲô�����У�
    }
    SuperPrime(int n):number(n), pset(3) {
        split();  //�����ǹ������
    }
    ~SuperPrime() {
    }
    bool isSuperPrime() {
        //��ôʹ��pset��
        Prime p(number);
        if (p.isPrime()&& pset.isAllPrime())
            return true;
        return false;
    }
private:
    const int number;
    PrimeSet pset;
    int size_N,N[10];
    void split() {   //�����������ģʽ
        // number split into N
        int temp = number;
        int i;
        for(i=0;temp > 0;i++) {
            int n = temp % 10;
            temp /= 10;
            N[i] = n;//��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� ��ѡ���/��/ƽ����
        }
        size_N = i;
        pset.add(sum());
        pset.add(multi());
        pset.add(squareSum());
    }
    int sum() {
        int sum_number = 0;
        for (int i=0;i<size_N;i++){
            sum_number+= N[i];
        }
        return sum_number;
    }
    int multi() {
        int multi_num = 1;
        int i;
        for(i = 0; i<size_N; i++){
            multi_num *= N[i];
        }
        return multi_num;
    }
    int squareSum() {
        int square = 0;
        int i;
        for(i = 0; i < size_N; i++)
            square += (N[i] * N[i]);
        return square;
    }

};

int main() {
    SuperPrime sp(113);
    if (sp.isSuperPrime())
        std::cout << "113 is SuperPrime" << std::endl;
    else
        std::cout << "113 is NOT SuperPrime" << std::endl;
    return 0;
}
