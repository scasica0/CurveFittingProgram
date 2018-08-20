
#ifndef MYLIB1
#define MYLIB1

#include <queue>
#include <vector>
#include "function.h"
using namespace std;

class BREADTH_FIRST
{
private:
     queue <FUNCTION_NODE> open;
     FUNCTION_NODE node;
     int a, b, c, d, k, e1, e2, e3, e4; //integers between 0 and 5
     char op1, op2, op3, op4; // {+,-}

public:
     BREADTH_FIRST();
     FUNCTION_NODE search(vector <double> input, vector <double> output);
     void generate_initial_level(vector <double> input, vector <double> output);
     void generate_children(FUNCTION_NODE node, vector <double> input, vector <double> output);
};

BREADTH_FIRST::BREADTH_FIRST() //initialize variables
{
     a = 0, b = 0, c = 0, d = 0, e1 = 0, e2 = 0, e3 = 0, e4 = 0, k = 0; //initialize at 0
     op1 = '+', op2 = '+', op3 = '+', op4 = '+'; // {+,-}
}

FUNCTION_NODE BREADTH_FIRST::search(vector <double> input, vector <double> output)
{
     generate_initial_level(input, output); 

     FUNCTION_NODE bestFunction = open.front(); //sets initial best fit function to first function on queue
     
     while (!open.empty()) //while the queue still has objects
     {
          node = open.front(); //"pop" a function out of queue
          open.pop();

          if (node.residual_squares < bestFunction.residual_squares) //checks to see if a better fitting function has been found
          {
               bestFunction = node; //if so change bestFunction to better fitting function
          }

          generate_children(node, input, output); // generates children of current function
     }
          return bestFunction;
}

void BREADTH_FIRST::generate_initial_level(vector <double> input, vector <double> output) //fill 'open' with level 1 expansion of variable 'a'
{
     int currentState = state_a; //set initial state to a

     for (a = 0; a < 5; a++)
     {
          open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState)); //push expansion of 'a' onto queue
     }
}

void BREADTH_FIRST::generate_children(FUNCTION_NODE node, vector <double> input, vector <double> output) //fill 'open' with expansion of variables depending on state
{
     int currentState;
     switch (node.state) //determine what to do with current state
     {
          case state_a: //expand 'e1'
          {
               currentState = state_e1;
               for (e1 = 0; e1 < 5; e1++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
          case state_e1://expand 'op1'
          {
               currentState = state_op1;
               for (int i = 0; i < 2; i++)
               {
                    if (i == 0)
                    {
                         op1 = '+';
                    }
                    else
                    {
                         op1 = '-';
                    }
               }
               open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               break;
          }
          case state_op1://expand 'b'
          {          
               currentState = state_b;
               for (b = 0; b < 5; b++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
               
          }
          case state_b://expand 'e2'
          {
               currentState = state_e2;
               for (e2 = 0; e2 < 5; e2++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
          case state_e2://expand 'op2'
          {
               currentState = state_op2;
               for (int i = 0; i < 2; i++)
               {
                    if (i == 0)
                    {
                         op2 = '+';
                    }
                    else
                    {
                         op2 = '-';
                    }
               }
               open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               break;
          }
          case state_op2://expand 'c'
          {
               currentState = state_c;
               for (c = 0; c < 5; c++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
          case state_c://expand 'e3'
          {
               currentState = state_e3;
               for (e3 = 0; e3 < 5; e3++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
          case state_e3://expand 'op3'
          {
               currentState = state_op3;
               for (int i = 0; i < 2; i++)
               {
                    if (i == 0)
                    {
                         op3 = '+';
                    }
                    else
                    {
                         op3 = '-';
                    }
               }
               open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               break;
          }
          case state_op3://expand 'd'
          {
               currentState = state_d;
               for (d = 0; d < 5; d++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
          case state_d://expand 'e4'
          {
               currentState = state_e4;
               for (e4 = 0; e4 < 5; e4++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
          case state_e4://expand 'op4'
          {
               currentState = state_op4;
               for (int i = 0; i < 2; i++)
               {
                    if (i == 0)
                    {
                         op4 = '+';
                    }
                    else
                    {
                         op4 = '-';
                    }
               }
               open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               break;
          }
          case state_op4://expand 'k'
          {
               currentState = state_k;
               for (k = 0; k < 5; k++)
               {
                    open.push(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
               }
               break;
          }
     
     }
}

#endif