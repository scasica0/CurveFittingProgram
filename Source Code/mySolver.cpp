

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <cmath>

#include "heuristic.h"
#include "hill_algorithm.h"
#include "bfs_algorithm.h"
#include "function.h"


using namespace std;

int main()
{
     char temp;
     fstream fin, fout;
     string InFileName;
     vector <double> input, output;
     FUNCTION_NODE bfsFunction, hillFunction;
     BREADTH_FIRST BFS;
     HILL_CLIMB hill;

     double x, y;

     cout << "\n\tName:\t\tStephen Casica\n\tCourse:\t\tCS 481\n\tDate:\t\tMarch 15, 2016\n\tCompiler:\tVisual Studio 2015\n\tAssignment:\t1\n\n"; 
     cout << "Please enter the file name of the data (File must be in program's directory): \n";
     cin >> InFileName;

     fin.open(InFileName, ios::in);

     if (fin.is_open())
     {
          while (fin >> x >> temp >> y) // read data
          {
               input.push_back(x);
               output.push_back(y);
          }

          fin.close(); // close file

          cout << "Data Read Successfully\n\n";
          
          // run hill climb algorithm
          cout << "Running Hill Climbing Algorithm...\n";
          hillFunction = hill.search(input, output);
          cout << "\tBest function found with Hill Climbing is:\n";
          printFunction(hillFunction);

          // run bfs algorithm
          cout << "Running BFS Algorithm...\n";
          bfsFunction = BFS.search(input, output);
          cout << "\tBest function found with BFS is:\n";
          printFunction(bfsFunction);

          //write results to file
          fout.open("assignment_1(casica)_results.txt", ios::out);
          fout << "\n\tRESULTS OF FUNCTION SEARCH\n\n";
          fout << "Best function found with Hill Climbing is:\n";
          writeFunction(hillFunction,fout);
          fout << "Best function found with BFS is:\n";
          writeFunction(bfsFunction,fout);
          fout.close();
     }

     else
     {
          cout << "ERROR: Unable to open input file" << endl;
     }

     return 0;
}

