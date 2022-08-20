// problem link : lcm of 2 numbers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcm_noob(int a,int b)
    {
        int result = max(a,b);
        while(true)
            {
                if(result % a == 0 && result % b == 0)
                    {
                        return result;
                    }
                result++;
            }
        return result;
    }

// using euclidean gcd function 
// a*b = gcd(a,b) * lcm(a,b)
int gcd(int a, int b)
    {
        if(b == 0)
            {
                return a;
            }
        return gcd(b,a%b);
        //linear time complexity -> O(a*b - max(a,b))
    }
int lcm_pro(int a, int b )
    {
        int result = a*b/gcd(a,b);
        return result;
        //logarithmic time complexity O(log(min(a,b)))
    }
int main()
    {
        int a = 12,b=15;
        cout<<lcm_noob(a,b)<<endl;
        cout<<lcm_pro(a,b)<<endl;
        return 0;
    }