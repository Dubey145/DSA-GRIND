// problem link : gcd of highest common factor of numbers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd_noob(int a,int b)
    {
        cout<<"GCD NOOB \n";
        int res = min(a,b);
        while(res>0)
            {
                if(a%res == 0 && b%res == 0)
                    {
                        break;
                    }
                cout<<res<<" ";
                res--;
            }
        return res;
        //complexity = O(min(a,b))
    }

/*
    using euclidean 
    if b is smaller than a 
    then gcd(a,b) = gcd(a-b,b)
*/
int gcd_okay(int a, int b)
    {
        cout<<"GCD OKAY\n";
        while(a!=b)
            {
                if(a>b)
                    {
                        a=a-b;
                        cout<<a<<" "<<b<<endl;
                    }
                else 
                    {
                        b=b-a;
                        cout<<a<<" "<<b<<endl;
                    }
            }
        return a;
    }

int gcd_best(int a,int b)
    {
        cout<<a<<" "<<b<<endl;
        if(b == 0)
            return a;
        else 
            return gcd_best(b,a%b);
    }

int main()
    {
        int a = 12;
        int b = 15;
        cout<<endl;
        cout<<gcd_noob(a,b)<<endl<<endl;
        cout<<gcd_okay(a,b)<<endl<<endl;
        cout<<"GCD BEST\n";
        cout<<gcd_best(a,b)<<endl<<endl;

        return 0;
    }