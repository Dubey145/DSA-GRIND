#include<iostream>
using namespace std;

/*

Ternary operator
(condition)? if true then  : if false then
int c = (a>b)? a : b

if a >b then c = a 
else c = b

if variable names change then code has to be repeated
so we can declare a function that return an inline result

*/

inline int max(int a, int b)
    {
        return (a > b )? a : b;
    }
/*a problem is that everytime we execute max we have to allocate memory
// for a and b
// to solve this declare max to be inline and at comple time the 
code will be copied wherever it is being used
only small functions are made inline
*/
int main()
    {
        int a = 2, b = 3;
        //int c = (a>b)? a : b;
        int c = max(a,b);
        cout<<c<<endl;
        int x = 20,y = 19;
        int z = max(x, y);
        cout<<z;
        return 0;
    }