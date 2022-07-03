#include<iostream>
using namespace std;

//template is used to generalize code, The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types.

template<typename T>
class Pair
    {
        T x;
        T y;

        public:

        void set(T x, T y)
            {
                this->x = x;
                this->y = y;
            }
        void get()
            {
                cout<<x<<" "<<y<<endl;
            }
    };

//for different data types

template<typename T,typename U>

class PairDifferent
    {
        T x;
        U y;

        public:

        void set(T x, U y)
            {
                this->x = x;
                this->y = y;
            }
        // T getPair()
        //     {
        //         cout<<x<<" "<<y<<endl;
        //     }
        void get()
            {
                cout<<x<<" "<<y<<endl;
            }
    };


int main() 
    {
        Pair<int> p1;
        p1.set(1,2);

        Pair<char> p2;
        p2.set('a','b');

        Pair<float> p3;
        p3.set(1.00,2.00);

        p1.get();
        p2.get();
        p3.get();

        PairDifferent<int,char> p4;
        p4.set(1,'x');
        p4.get();

        //creating a triplet with PairDifferent class 

        // PairDifferent<PairDifferent<int,char>, float> p5;
        // PairDifferent<int,char> p6;
        // p6.set(1,'v');
        // p5.set(p6,2.0);
        // p5.get().get(); create a getx function 
        return 0;
    }