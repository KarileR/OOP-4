#ifndef student_h
#define student_h

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/person.h" 

class student : public Person
{
    private:
        std::vector <int> pazymiai;
        int egz;
        double Finale_suVidurkiu;
        double Finale_suMediana;
        int Med_ar_Vid;
        bool CorrectData;

    public:
        student();

        student(string a, string b):
            Person(a, b) {};

        void set_egz(int exam_mark);
        int get_egz()const;

        void set_mark(double mark);
        int get_mark(int a);
        void ClearMark();

        double getFinale_suVidurkiu()const;
        double getFinale_suMediana()const;

        double Calculate_suVidurkiu();
        double Calculate_suMediana();

        void set_Med_ar_Vid(int choice);
        int get_Med_ar_Vid();

        bool setCorrectData(bool x);
        bool getCorrectData();

        friend bool operator > (const student &a, const student &b);
        friend bool operator < (const student &a, const student &b);
        friend bool operator >= (const student &a, const student &b);
        friend bool operator <= (const student &a, const student &b);
        friend bool operator == (const student &a, const student &b);
        friend bool operator != (const student &a, const student &b);

        friend std::istream& operator >> (std::istream& in, student &a);
        friend std::ostream& operator << (std::ostream& out, student &a);
        
};

bool Compare_by_Results(const student &a, const student &b);
bool Compare_by_FirstName(const student &a, const student &b);
bool Ar_Islaike (student &a);


#endif
