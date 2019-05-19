#include "../headers/student.h"
#include "../headers/console.h"
#include "../headers/functions.h"
#include "../headers/globals.h"
#include "../headers/vector.h"



std::string ListNR;

void InsertYourself(Vector <student> &A)
{
        cout << "Iveskite mokiniu skaiciu: ";
        int sk = Console::GetInteger(1,imax);

        student z;

        for (int i=1; i<=sk; i++)
        {
            cout << endl;
            cout << "Iveskite " << i << " -ojo mokinio duomenis:" << endl;
            cin >> z;
            A.push_back(z);
        }
}

void PrintData(Vector <student> &A)
{
        int num = 0; int num2 = 20; bool co = true;
        num = GetLongestString(A) + 7;

        //A.sort(Compare_by_FirstName);
        std::sort(A.begin(), A.end(), Compare_by_FirstName);

        cout << endl;
        cout<< left << setfill(' ') << setw(num) << "Pavarde";
        cout<< left << setfill(' ') << setw(num) << "Vardas";
        cout<< left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
        cout<< left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 
        
        const std::string bruksnys(num+num+20+17,'_');
        cout<<bruksnys<<endl;
        for(auto &i: A)
        {
            cout << left << setfill(' ')<< setw(num) << i.getLastName();
            cout << left << setfill(' ')<< setw(num) << i.getFirstName();

            if (i.getCorrectData() == true)
            {
                if(i.get_Med_ar_Vid() == 3)  //Spausdina ir ta, ir ta
                {
                    cout << std::fixed;
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.getFinale_suVidurkiu();
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.getFinale_suMediana();
                }

                else if(i.get_Med_ar_Vid() == 2) //Spausdina tik su vidurkiu
                {
                    cout << std::fixed;
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.getFinale_suVidurkiu();
                }

                else if (i.get_Med_ar_Vid() == 1) //Spausdina tik su mediana
                {
                    cout << std::fixed;
                    cout << "                    ";
                    cout << left << setfill(' ')<< setw(num2);
                    cout << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.getFinale_suMediana();
                }
            }

            else if (i.getCorrectData() == false)
            {
                cout << left << setfill(' ')<< setw(num2) << "Wrong Data";
                cout << left << setfill(' ')<< setw(num2) << "Wrong data";
                co = false;
            }
            cout << endl;
        }
        cout << endl << endl;
        if (co == false) cout <<"It seems you have written wrong data. Please check again your data file" << endl;
}

void GroupStudents(Vector <student> &A)
{
    //A.sort(Compare_by_Results);
    std::sort(A.begin(), A.end(), Compare_by_Results);

    //Vector <student>::iterator it = std::stable_partition (A.begin(), A.end(), Ar_Islaike);
    //Vector <student> Weak (it, A.end());
    //A.erase(it, A.end());

    Vector <student> Weak;
    Vector <student> Strong;

    for(auto &i : A)
    {
        if(i.getFinale_suVidurkiu() >= 5) Weak.push_back(i);
        else (Strong.push_back(i));
    }


    std::ofstream write1("../GeneratedLists/" + ListNR + "/kietiakai.txt");
    std::ofstream write2("../GeneratedLists/" + ListNR + "/vargsiukai.txt");
  
    int num = 15;
    int num2 = 20;
    int num3 = 5;
    
    write1 << left << setfill(' ') << setw(num) << "Pavarde";
    write1 << left << setfill(' ') << setw(num) << "Vardas";
    write1 << left << setfill(' ') << setw(num3) << "ND1";
    write1 << left << setfill(' ') << setw(num3) << "ND2";
    write1 << left << setfill(' ') << setw(num3) << "ND3";
    write1 << left << setfill(' ') << setw(num3) << "ND4";
    write1 << left << setfill(' ') << setw(num3) << "ND5";
    write1 << left << setfill(' ') << setw(7) << "EGZ";
    write1 << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    write1 << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 

    write2 << left << setfill(' ') << setw(num) << "Pavarde";
    write2 << left << setfill(' ') << setw(num) << "Vardas";
    write2 << left << setfill(' ') << setw(num3) << "ND1";
    write2 << left << setfill(' ') << setw(num3) << "ND2";
    write2 << left << setfill(' ') << setw(num3) << "ND3";
    write2 << left << setfill(' ') << setw(num3) << "ND4";
    write2 << left << setfill(' ') << setw(num3) << "ND5";
    write2 << left << setfill(' ') << setw(7) << "EGZ";
    write2 << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    write2 << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl; 

    const std::string bruksnys(num*4+num3*5+14,'_');
    write1 << bruksnys << endl;
    write2 << bruksnys << endl;

    for(auto &u : Weak)
    {
        write1 << left << setfill(' ')<< setw(num) << u.getLastName();
        write1 << left << setfill(' ')<< setw(num) << u.getFirstName();
        for (int j=0; j<5; j++)
        {
            write1 << left << setfill(' ') << setw(num3) << u.get_mark(j);
        }
        write1 << std::fixed;
        write1 << left << setfill(' ') << setw(7) << u.get_egz();
        write1 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << u.getFinale_suVidurkiu();
        write1 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << u.getFinale_suMediana();
        write1 << endl; 
    }


    for(auto &i : Strong)
    {
        write2 << left << setfill(' ')<< setw(num) << i.getLastName();
        write2 << left << setfill(' ')<< setw(num) << i.getFirstName();
        for (int j=0; j < 5; j++)
        {
            write2 << left << setfill(' ') << setw(num3) << i.get_mark(j);
        }
        write2 << std::fixed;
        write2 << left << setfill(' ') << setw(7) << i.get_egz();
        write2 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.getFinale_suVidurkiu();
        write2 << left << setfill(' ')<< setw(num2) << std::setprecision(2) << i.getFinale_suMediana();
        write2 << endl; 
    }

    write1.close();
    write2.close();

    cout << endl;
    cout << "Sugeneruotas studentu sarasas /GeneratedLists/" + ListNR << endl;
}


void ReadFromFile(Vector <student> &A)
{
    string FirstName;
    string LastName;
    int pazymys;
    int egz;
    int Med_ar_Vid;

    std::ifstream read("../GeneratedLists/" + ListNR + "/Full_list.txt");

    if(!read)
	{
		cout << "Cannot open the File!"<< endl;
	}

    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));
    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));

    student z;

    while(!read.eof())
    {
        z.ClearMark();

        read >> FirstName;
        z.setFirstName(FirstName);

        read >> LastName;
        z.setLastName(LastName);

        for (int j=1; j<=5; j++)
        {
            read >> pazymys;
            z.set_mark(pazymys);
        }

        read >> egz;
        z.set_egz(egz);

        z.set_Med_ar_Vid(3);

        z.Calculate_suMediana();
        z.Calculate_suVidurkiu();
        A.push_back(z);
    }

    A.pop_back();
    read.close();
}


void GenerateList(int StudSK)
{
    std::srand (std::time(NULL));
    int NR = 1;

    struct stat st;
    if(stat("../GeneratedLists", &st) != 0)
    {
        const int dir_err = mkdir("../GeneratedLists");
        if (-1 == dir_err)
        {
            printf("Error creating directory!n");
            exit(1);
        }
    }
    
    while (true)
    {
        std::string t = std::to_string(NR);

        std::ifstream check("../GeneratedLists/List" + t + "/Full_list.txt");
        if(check)
        {
            check.close();
            NR++;
        }
        if(!check)
        {
            check.close();
            break;
        }
    }

    string k = std::to_string(NR);
    ListNR = "List" + k;
    string h = "../GeneratedLists/List" + k;
    char const* ca = h.c_str();
    const int fullDir = mkdir(ca);

    std::ofstream write("../GeneratedLists/"+ ListNR +"/Full_list.txt");
    
    int num = 15; int num2 = 20; int num3 = 5;

    write << left << setfill(' ') << setw(num) << "Pavarde";
    write << left << setfill(' ') << setw(num) << "Vardas";
    write << left << setfill(' ') << setw(num3) << "ND1";
    write << left << setfill(' ') << setw(num3) << "ND2";
    write << left << setfill(' ') << setw(num3) << "ND3";
    write << left << setfill(' ') << setw(num3) << "ND4";
    write << left << setfill(' ') << setw(num3) << "ND5";
    write << left << setfill(' ') << setw(8) << "EGZ" << endl;

    const std::string bruksnys(num*2+num3*5+3.5,'_');
    write << bruksnys;

    for(int i=0; i<StudSK; i++)
    {  
        write << endl;
        std::string sk = std::to_string(i+1);

        std::string vardas = "Vardas" + sk;
        std::string pavarde = "Pavarde" + sk;

        write << left << setfill(' ')<< setw(num) << vardas;
        write << left << setfill(' ')<< setw(num) << pavarde;

        for(int j=0; j<5; j++)
        {
            write << left << setfill(' ') << setw(num3) << rand() % 10 + 1;
        }

        write << std::fixed;
        write << left << setfill(' ') << setw(8) << rand() % 10 + 1;
    }
    write.close();
}


void InsertFromFile(Vector <student> &A)
{
    std::ifstream read("../data/kursiokai.txt");
     
    if(!read)
	{
		cout << "Cannot open the File! Make sure that your file is in 'data' folder and is named kursiokai.txt "<< endl;
	}

    string FirstName;
    string LastName;
    int egz;
    double Finale_suVidurkiu;
    double Finale_suMediana;
    int Med_ar_Vid;
    int pazymys;

    student z;

    while(!read.eof())
    {
        z.ClearMark();

        read >> FirstName;
        z.setFirstName(FirstName);
        read >> LastName;
        z.setLastName(LastName);

        bool CorrectND = true;
        bool CorrectEGZ = true;

        for (int j=1; j<=5; j++)
        {
            read >> pazymys;
                if(read.fail())
                {
                    read.clear();
                    read.ignore(256,' ');
                    pazymys = 1;
                    CorrectND = false;
                }
                else if (pazymys <= 0 || pazymys > 10) CorrectND = false;
                
            z.set_mark(pazymys);
        }
        read >> egz;
        z.set_egz(egz);

                if(read.fail())
                {
                    read.clear();
                    read.ignore(256,' ');
                    z.set_egz(1);
                    CorrectEGZ = false;
                }
                else if (z.get_egz() <= 0 || z.get_egz() > 10)
                {
                    CorrectEGZ = false;
                }
                else CorrectEGZ = true;

        z.set_Med_ar_Vid(3);

        if (CorrectEGZ == false || CorrectND == false) z.setCorrectData(false);
        else z.setCorrectData(true);

        z.Calculate_suVidurkiu();
        z.Calculate_suMediana();

        A.push_back(z);
    }
    read.close();
}

int GetLongestString(Vector <student> &A) 
{
    int ln=0, max=0;
    for(auto &i: A)
    {
        ln = i.getFirstName().size();
        if (ln > max) max = ln;
    }
    for(auto &i: A)
    {
        ln = i.getLastName().size();
        if (ln > max) max = ln;
    }
    return max;
}