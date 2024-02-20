/*
    ** observer based pattern **

    Observer is a behavioral design pattern that lets you define a subscription 
    mechanism to notify multiple objects about any events that happen to the object 
    they’re observing.

*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

class ObserverInterface{
    public:
    virtual ~ObserverInterface(){};
    virtual void Update(const string &message_from_subject) = 0;

};



class SubjectInterface{
    public:
    virtual ~SubjectInterface(){};
    virtual void Attach(ObserverInterface *observer) = 0;
    virtual void Detach(ObserverInterface *observer) = 0;
    virtual void Notify() = 0;
};


class Subject:public SubjectInterface{
    virtual ~Subject() {
        cout << "Goodbye, I was the Subject.\n";
    }
    void Attach(IObserver *observer){
        list_observer_.push_back(observer);
    }
    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }

};