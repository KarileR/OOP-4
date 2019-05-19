#include "../headers/student.h"
#include "../headers/console.h"
#include "../headers/vector.h"



student::student()
{
    egz = 0;
    Finale_suVidurkiu = 0;
    Finale_suMediana = 0;
    CorrectData = true;
    Med_ar_Vid = 2;
}


void student::set_egz(int exam_mark){
    egz = exam_mark;
}       
int student::get_egz()const{
    return egz;
}


void student::set_mark(double mark) {
    pazymiai.push_back(mark); 
}

int student::get_mark(int a){
    return pazymiai[a];
}

void student::ClearMark(){
    pazymiai.clear();
}

bool student::setCorrectData(bool x)
{
    CorrectData = x;
}
bool student::getCorrectData()
{
    return CorrectData;
}

double student::getFinale_suVidurkiu()const{
    return Finale_suVidurkiu;
}
double student::getFinale_suMediana()const{
    return Finale_suMediana;
}

double student::Calculate_suVidurkiu()
{
    double s = 0, avr = 0;

    for (int i=0; i < pazymiai.size(); i++)
    {
        s = s + pazymiai[i];
    }

    avr = s/pazymiai.size();
    Finale_suVidurkiu = 0.4 * avr + 0.6 * egz;
}


double student::Calculate_suMediana() 
{
    std::sort(pazymiai.begin(), pazymiai.end());  //sorting an array in ascending order

    double s = 0;
    if (pazymiai.size() % 2 == 0)
    {
        s = (double)((pazymiai[pazymiai.size()/2] + pazymiai[pazymiai.size()/2])/2);
    }
    else
    {
        s =(double)pazymiai[pazymiai.size()/2]; 
    }
    Finale_suMediana = 0.4 * s + 0.6 * egz;
}

void student::set_Med_ar_Vid(int choice){
    Med_ar_Vid = choice;
}
int student::get_Med_ar_Vid(){
    return Med_ar_Vid;
}

bool Compare_by_FirstName(const student &a, const student &b) 
{
    return a.getFirstName() < b.getFirstName();
}

bool Compare_by_Results(const student &a, const student &b) 
{
    return a > b;
}

bool Ar_Islaike (student &a) 
{
    return (a.getFinale_suVidurkiu() >= 5);
}

//Operatoriai

bool operator > (const student &a, const student &b)
{
    return a.getFinale_suVidurkiu() > b.getFinale_suVidurkiu();
}
bool operator < (const student &a, const student &b)
{
    return a.getFinale_suVidurkiu() < b.getFinale_suVidurkiu();
}

bool operator >= (const student &a, const student &b)
{
    return a.getFinale_suVidurkiu() >= b.getFinale_suVidurkiu();
}
bool operator <= (const student &a, const student &b)
{
    return a.getFinale_suVidurkiu() <= b.getFinale_suVidurkiu();
}

bool operator == (const student &a, const student &b) 
{ 
    return a.getFinale_suVidurkiu() == b.getFinale_suVidurkiu(); 
}
bool operator != (const student &a, const student &b) 
{ 
    return a.getFinale_suVidurkiu() != b.getFinale_suVidurkiu(); 
}


std::istream& operator >> (std::istream& in, student &a)
{

    std::cout << "Vardas: "; 
    string name; in >> name; a.setFirstName(name);

    std::cout << "Pavarde: ";
    string sname; in >> sname; a.setLastName(sname);
    
    std::cout << std::endl;
    
    std::cout << "Pradekite vesti mokinio pazymius. Kai baigsite iveskite 0. " << std::endl;
    int j=1; int pazymys;

    while(true)
    {
        std::cout << j <<"-uju namu darbu rezultatas: ";
        pazymys = Console::GetInteger(0,10);

        if (pazymys == 0) break;
        else
        {
            a.pazymiai.push_back(pazymys);
            j++;
        }
    }

    std::cout << "Egzamino rezultatai: ";
    a.egz = Console::GetInteger(1,10);
    std::cout << std::endl;

    std::cout << "Pasirinkite skaiciuoti su mediana (1), vidurkiu (2), arba su abiem (3): ";
    a.Med_ar_Vid = Console::GetInteger(1,3);

    a.Calculate_suMediana();
    a.Calculate_suVidurkiu();
    
    return in;
}

std::ostream& operator << (std::ostream& out, student &a)
{
    out << a.getFirstName() << " ";
    out << a.getLastName() << " ";
    out << a.get_egz() << " ";
    
    for (int i=1; i <= a.pazymiai.size(); i++)
    {
        out << a.get_mark(i) << " ";
    }

    out << a.getFinale_suVidurkiu();
    out << a.getFinale_suMediana();

    return out;
}
