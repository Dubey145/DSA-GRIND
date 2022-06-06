#include<iostream>
#include<string>
using namespace std;
// to access or modify a private property we need a public function  
class box
    {   
        private :
            int cost = 5;
            int vol;
        public: 
            int length; 
            int breadth; 
            int height;
        void volume()
            {
                vol = length*breadth*height;         
                cout<<vol;
            }
        int filling_cost() 
            {
                return vol*cost;
            }
            
    }b1;
// private values cannot be directly changed 
int main()  
    {
        cin>>b1.length>>b1.breadth>>b1.height;
        b1.volume();
        cout<<"\n cost to fill: "<<b1.filling_cost();
        return 0;
    } 