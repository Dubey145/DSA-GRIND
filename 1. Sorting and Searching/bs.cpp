// problem link : https://leetcode.com/problems/binary-search/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start<=end)
            {
                mid = start +(end-start)/2;
                if(nums[mid] == target)
                    {
                        return mid;
                    }
                else if(nums[mid]>target)
                    {
                        end = mid-1;
                    }
                else
                    {
                        start = mid+1;
                    }
            }
        return -1;
    }
int main()
    {
        vector<int> nums{-1,0,3,5,9,12};
        cout<<search(nums,9)<<endl;

        return 0;
    }