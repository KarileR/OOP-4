#include "../headers/student.h"
#include "../headers/console.h"
#include "../headers/main.h"
#include "../headers/functions.h"
#include "../headers/timer.h"
#include "../headers/globals.h"
#include "../headers/vector.h"

int main(int argc, const char * argv[]) 
{
    Timer clock1;
    auto h2 = clock1.elapsed(); 

    Vector <student> A;

    cout << "Paspausti atitinkamus skaicius, jeigu norite:" << endl << endl;
    cout << "1. Sukelti duomenis is esamo failo" << endl;
    cout << "2. Generuoti atsitiktini sarasa" << endl; 
    cout << "3. Ivesti duomenis ranka" << endl << endl;
    cout << "Jusu pasirinkimas: ";

    Timer clock2;
    int MainChoice = Console::GetInteger(1,3);
    auto h1 = clock2.elapsed();

    if (MainChoice == 1) 
    {
        InsertFromFile(A); 
        PrintData(A);
    }       
    else if (MainChoice == 2) 
    {
        cout << "Kiek norite sugeneruoti studentu? "; 

        Timer clock3;
        int StudSk = Console::GetInteger(1,imax);
        h2 = clock3.elapsed();

        GenerateList(StudSk);
        ReadFromFile(A);
        GroupStudents(A);
    }
    else if (MainChoice == 3)
    {
        InsertYourself(A);
        PrintData(A);
    } 

    cout << "Uztruko " << std::setprecision(7) << clock1.elapsed() - h1  - h2 << " s " << endl;

    return 0;

}