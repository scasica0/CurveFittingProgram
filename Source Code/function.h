
#ifndef MYLIB4
#define MYLIB4

#include <vector>
#include "heuristic.h"

using namespace std;

//structure to hold each function
struct FUNCTION_NODE
{
     int a, b, c, d, k, e1, e2, e3, e4; //integers between 0 and 5
     int state; //contains information about next level of search
     char op1, op2, op3, op4; // {+,-}
     double residual_squares; //sum of (y - value1)^2 + (y - value2)^2...
};

void printFunction(FUNCTION_NODE function) //prints f(x)
{
     cout << "\tf(x) = " << function.a << "x^" << function.e1 << " " << function.op1 << " " << function.b << "x^" << function.e2;
     cout << " " << function.op2 << " " << function.c << "x^" << function.e3;
     cout << " " << function.op3 << " " << function.d << "x^" << function.e4;
     cout << " " << function.op4 << " " << function.k << endl;
     cout << "\tResidual Squares = " << function.residual_squares << endl << endl;
}

void writeFunction(FUNCTION_NODE function, fstream& fout)
{
     fout << "f(x) = " << function.a << "x^" << function.e1 << " " << function.op1 << " " << function.b << "x^" << function.e2;
     fout << " " << function.op2 << " " << function.c << "x^" << function.e3;
     fout << " " << function.op3 << " " << function.d << "x^" << function.e4;
     fout << " " << function.op4 << " " << function.k << endl;
     cout << "Residual Squares = " << function.residual_squares << endl << endl;
}

FUNCTION_NODE fillFunctionNode(int a, int b, int c, int d, int e1, int e2, int e3, int e4, int k, char op1, char op2, char op3, char op4, vector<double> input, vector <double> output,int state) // fills in a function
{
     double x, y;
     FUNCTION_NODE node;

     node.state = state;
     node.a = a;
     node.b = b;
     node.c = c;
     node.d = d;
     node.e1 = e1;
     node.e2 = e2;
     node.e3 = e3;
     node.e4 = e4;
     node.k = k;
     node.op1 = op1;
     node.op2 = op2;
     node.op3 = op3;
     node.op4 = op4;
     node.residual_squares = 0;

     for (int i = 0; i < input.size(); i++)
     {
          x = input.at(i);
          y = output.at(i);

          if (op1 == '+')
          {
               if (op2 == '+')
               {
                    if (op3 == '+')
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) + c*pow(x, e3) + d*pow(x, e4) + k),2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) + c*pow(x, e3) + d*pow(x, e4) - k), 2);
                         }
                    }
                    else
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) + c*pow(x, e3) - d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) + c*pow(x, e3) - d*pow(x, e4) - k), 2);
                         }
                    }
               }
               else
               {
                    if (op3 == '+')
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) - c*pow(x, e3) + d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) - c*pow(x, e3) + d*pow(x, e4) - k), 2);
                         }
                    }
                    else
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) - c*pow(x, e3) - d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) + b*pow(x, e2) - c*pow(x, e3) - d*pow(x, e4) - k), 2);
                         }
                    }
               }
          }
          else
               if (op2 == '+')
               {
                    if (op3 == '+')
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) + c*pow(x, e3) + d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) + c*pow(x, e3) + d*pow(x, e4) - k), 2);
                         }
                    }
                    else
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) + c*pow(x, e3) - d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) + c*pow(x, e3) - d*pow(x, e4) - k), 2);
                         }
                    }
               }
               else
               {
                    if (op3 == '+')
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) - c*pow(x, e3) + d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) - c*pow(x, e3) + d*pow(x, e4) - k), 2);
                         }
                    }
                    else
                    {
                         if (op4 == '+')
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) - c*pow(x, e3) - d*pow(x, e4) + k), 2);
                         }
                         else
                         {
                              node.residual_squares += pow((y - a*pow(x, e1) - b*pow(x, e2) - c*pow(x, e3) - d*pow(x, e4) - k), 2);
                         }
                    }
               }
     }

     return node;
     
}

#endif