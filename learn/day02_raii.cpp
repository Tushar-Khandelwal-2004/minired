/*
class Noisy
{
    std::string name_;
public:
    ...
};

implement:

Constructor prints created NAME
Destructor prints destroyed NAME
Block scope experiment
Early return experiment
new leak experiment

*/
#include<bits/stdc++.h>
using namespace std;

class Noisy{
    string name_;
    public:
    Noisy(string name){
        this->name_=name;
        cout<<"created "<<this->name_<<endl;
    }
    ~Noisy(){
        cout<<"destroyed "<<this->name_<<endl;
    }
};

void solve(){
    Noisy a("alice");
    Noisy *b=new Noisy("bob");
    delete b;
    return;
//     Noisy a("alice");
//     Noisy c = a;
//     cout << &a << endl;
// cout << &c << endl;
}

int main(){
        // Noisy a("alice");
        // {Noisy b("bob");}
        // Noisy c("cat");
        solve();

}