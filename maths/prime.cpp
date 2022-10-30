// problem link : prime numbers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool prime_noob(int num)
    {
        if(num == 1) return false;

        for(int i = 2; i <= num; i ++)
            {
                if(num%i == 0)
                    {
                        return false;
                    }
            }
        return true;
    }

bool prime_better(int nums)
    {
        if(nums == 1) return false;
        if(nums == 2 || nums == 3) return true;
        if(nums%2 == 0) return false;

        for(int i = 3 ;  i*i <=nums; i++)
            {
                if(nums%i == 0 || nums%(i+2) == 0)
                    {
                        return false;
                    }
            }
        return true;
    }
//optimized time complexity O(sqrt(n))

int main()
    {
        vector<int> nums{};


        return 0;
    }
