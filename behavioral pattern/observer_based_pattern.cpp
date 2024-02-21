/*
    ** observer based pattern **

    Observer is a behavioral design pattern that lets you define a subscription 
    mechanism to notify multiple objects about any events that happen to the object 
    they’re observing.

*/
#include <iostream>
#include <list>
#include <string>
#include <set>

using namespace std;


class observer{
    public:
    string user_id;
    set<observable> 
    observer(string s){
        user_id = s;
    }
    void subs(observable* prod){
        prod->add_sub()
    }
    void ping(string product_key){
        cout<<product_key<<" noticed"<<endl;
    }

};

class observable{
    public:
    string product_key;
    set<observer*> list_of_subscribers;

    observable(string s){
        product_key = s;
    }
    void add_sub(observer* obj){
        cout<<obj->user_id<<" added"<<endl;
        list_of_subscribers.insert(obj);
    }
    void rem_sub(observer* obj){
        cout<<obj->user_id<<" removed"<<endl;
        list_of_subscribers.erase(obj);
    }
    void notify(){
        for(observer* x:list_of_subscribers){
            cout<<x->user_id<<" notified"<<endl;
            x->ping(product_key);
        }

    }
};

int main(){
    observable* a = new observable("PlayStation");
    observer* obj1 = new observer("ekamsingh"); 
    observer* obj2 = new observer("ramsingh");
    observer* obj3 = new observer("john");

    a->add_sub(obj1);
    a->add_sub(obj2);
    a->add_sub(obj3);

    a->rem_sub(obj1);

    cout<<"pings"<<endl;
    a->notify();




}


