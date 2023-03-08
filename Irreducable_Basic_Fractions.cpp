/*
    Keyword: Euler's φ Function
    source1(answer): https://knightzone.studio/2020/05/07/4929/uva%EF%BC%9A10179%EF%BC%8Dirreducable-basic-fractions/
    source2(euler): https://zh.wikipedia.org/zh-tw/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0
*/
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;

const int MAX_num = 31622; // 32000
/* version 1
class PrimeTable {
    public:
        vector<int> _primeNumber;
        PrimeTable(int size) {
            vector<bool> isPrime(size + 1, true);
            isPrime[0] = false;
            for(int i = 2; i <= size; i++) {
                if(isPrime[i]) {
                    _primeNumber.push_back(i);
                    for(int j = i + i; j <= size; j+=i)
                        isPrime[j] = false;
                }
            }
        }

        int count() const {
            return _primeNumber.size();
        }
};

long long int getEuler(const PrimeTable &primeTable, int n)
{
    int number = n;
    long long int result = n;
    int totalPrimeCount = primeTable.count();

    // euler function
    for(int i = 0; i < totalPrimeCount; i++) {
        int curr_prime = primeTable._primeNumber[i];
        if(number % curr_prime == 0) {
            result /= curr_prime;
            result *= (curr_prime - 1);

            while(number % curr_prime == 0)
                number /= curr_prime;
        }
    }

    if(number > 1) { // 有可能有大於 31622的質數
        result /= number;
        result *= (number -1);
    }
    return result;
}

int main()
{
    PrimeTable primeTable(MAX_num + 5);
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        printf("%lld\n", getEuler(primeTable, n));
    }
    return 0;
}
*/
vector<int>_primeNumber;
void PrimeTable(int size)
{
    vector<bool> isPrime(size + 1, true);
    isPrime[0] = false;
    for(int i = 2; i <= size; i++) {
        if(isPrime[i]) {
            _primeNumber.push_back(i);
            for(int j = i + i; j <= size; j+=i)
                isPrime[j] = false;
        }
    }
}

long long int getEuler(const vector<int>&_primeNumber, int n)
{
    int number = n;
    long long int result = n;
    int totalPrimeCount = _primeNumber.size();

    // euler function
    for(int i = 0; i < totalPrimeCount; i++) {
        int curr_prime = _primeNumber[i];
        if(number % curr_prime == 0) {
            result /= curr_prime;
            result *= (curr_prime - 1);

            while(number % curr_prime == 0)
                number /= curr_prime;
        }
    }

    if(number > 1) { // 有可能有大於 31622的質數
        result /= number;
        result *= (number -1);
    }
    return result;
}

int main()
{
    PrimeTable(MAX_num + 5);
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        printf("%lld\n", getEuler(_primeNumber, n));
    }
    return 0;
}