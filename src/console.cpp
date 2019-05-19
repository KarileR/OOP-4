 #include "../headers/console.h"
 #include "../headers/globals.h"

 //Vartotojas veda skaiciu tol kol, input'as bus nuo a iki b, ne string formato bei nedidesnis uz MAX
 
 int Console::GetInteger (int a, int b) 
        {
            int choice;
            std::cin >> choice;
            while (true)
            {
                if (choice >= a && choice <= b && choice < imax) break;
                do
                {
                    try
                    {
                        if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");

                    }
                    catch (...)
                    {
                            std::cin.clear();
                            std::cin.ignore(256, '\n');
                    }
                    std::cout << "Iveskite dar karta: ";
                    std::cin >> choice;
                }while(std::cin.fail());
            }
            return choice;
        }