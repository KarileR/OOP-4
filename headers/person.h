#ifndef person_h
#define person_h

#include <iostream>
using std::string;

class Person
{
    private:
        string FirstName;
        string LastName;
    public:

        Person () { };
        Person(string a, string b): 
            FirstName(a), LastName(b) {};

        void setFirstName(string x){
            FirstName = x;
        }
        string getFirstName()const{
            return FirstName;
        }


        void setLastName(string x){
            LastName = x;
        }
        string getLastName()const{
            return LastName;
        }

};

#endif