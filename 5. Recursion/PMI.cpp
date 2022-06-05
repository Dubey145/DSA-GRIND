#include<iostream>
using namespace std;
/*
recursion is based on PMI - principle of mathematical induction

in PMI we prove certain facts 
steps :
to prove that f(n) is true for all natural numbers  
1. prove that f(0) or f(1) is true 
2. assume that f(k) is true 
3. using 2 prove that f(k+1) is true  

Q. Fibonacci series using recursion 
series - 0 1 1 2 3 5 8 ...
fib(n) = fib(n-1) + fib(n-2)
*/

int fibonacci(int n) 
    {
        if(n == 0) 
            return 0;
        if(n == 1) 
            return 1;
        int result1 = fibonacci(n-1);
        int result2 = fibonacci(n-2);
        return result1+result2;
    }

int main()
    {
        int n;
        cin>>n;
        cout<<fibonacci(n)<<endl;
        return 0;
    }