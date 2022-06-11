#include<iostream>
using namespace std;

class fraction
    {
        private:
            int nr;
            int dr;
        public:
            fraction(int nr, int dr)
                {
                    this->nr = nr;
                    this->dr = dr;
                }
        void print() const
            {
                cout<<nr<<"/"<<dr<<endl;  
            }
        void add_fraction(fraction f)
            {
                //result stored in f1
                this->nr = this->nr * f.dr + f.nr *this->dr;
                this->dr = this->dr * f.dr;
                this->print();
                cout<<endl;
                //the fraction is not in simplified form yet
                //to calc the GCD of nr and dr
                //simplification 
                int gcd = 1;
                int j = min(this->nr, this->dr);
                for(int i =1; i<j;i++)
                    {
                        if(this->nr % i == 0 && this->dr % i == 0)
                            gcd = i;
                    }
                this->nr /= gcd;
                this->dr /= gcd;
                this->print();
            }
        
    };

int main()
    {
        fraction f1(2,5);
        fraction f2(4,6);
        //the way we create const int we can also create const class object
        const fraction f3(12,21);//garbage assigned to memory then we are trying to assign 2 and 3 
        //through a constant object no function calls are allowed only constant functions can be called 
        //which doesn't change any property of current object
        f1.print();
        cout<<"fraction sum =" ;f1.add_fraction(f2);

        f3.print(); // works after declaring a function const  

        return 0;
    }