#include<iostream>
using namespace std;

//we can do int c = a + b but we cant do f3 = f1+f2 because + is not defined here
//we have to improve the functionality of + so that it works for objects also this is called operator overloading 
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
        void print() 
            {
                cout<<nr<<"/"<<dr<<endl;  
            }
        fraction add_fraction(fraction &f)
            {
                //we create a reference to the argument to avoid unnecessary copying 
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
                // this->print();
                fraction fnew(nr,dr);
                return fnew;
            }
        fraction operator+(fraction f)
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
                // this->print();
                fraction fnew(nr,dr);
                return fnew;
            }
        fraction operator*(fraction f)
            {
                int n = this->nr * f.nr;
                int d = this->dr * f.dr;
                fraction fnew(n,d); 
                return fnew;
            }
        bool operator== (fraction f)
            {
                return(nr == f.nr && dr == f.dr );
            }
        
    };

int main()
    {
        fraction f1(2,5);
        fraction f2(4,6);
        cout<<(f1==f2)<<endl;
            
        
        cout<<"fraction sum =" ;

        fraction f3 = f1.add_fraction(f2);
        f3.print();
        fraction f4 = f3+f2; 
        //this will have f3 and f2 will be treated as an argument
        cout<<endl;
        f4.print();
        
        return 0;
    }