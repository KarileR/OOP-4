#ifndef functions_h
#define functions_h

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>
#include <limits>
#include <ctime>
#include <ratio>
#include <list>
#include <functional>
#include <windows.h>
#include <direct.h>
#include <iterator>
#include <limits>
#include <sys/stat.h>
#include "../headers/vector.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::left;
using std::list;
using std::string;


void InsertYourself(Vector <student> &A);
void PrintData(Vector <student> &A);
void GroupStudents(Vector <student> &A);
void ReadFromFile(Vector <student> &A);
void GenerateList(int StudSK);
void InsertFromFile(Vector <student> &A);
int GetLongestString(Vector <student> &A);

#endif
