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
        void print()
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
        f1.print();
        cout<<"fraction sum =" ;f1.add_fraction(f2);
        return 0;
    }