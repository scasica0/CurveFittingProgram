
#ifndef MYLIB2
#define MYLIB2

#include <stack>
#include <vector>
#include "function.h"

enum state { state_a = 1, state_e1, state_op1, state_b, state_e2, state_op2, state_c, state_e3, state_op3, state_d, state_e4, state_op4, state_k };

class HILL_CLIMB
{
private:
     stack <FUNCTION_NODE> open;
     FUNCTION_NODE node;
     int a, b, c, d, k, e1, e2, e3, e4; //integers between 0 and 5
     char op1, op2, op3, op4; // {+,-}

public:
     HILL_CLIMB();
     FUNCTION_NODE search(vector <double> input, vector <double> output);
     void generate_initial_level(vector <double> input, vector <double> output);
     void generate_child(FUNCTION_NODE node, vector <double> input, vector <double> output);
};

HILL_CLIMB::HILL_CLIMB()
{
     a = 0, b = 0, c = 0, d = 0, e1 = 0, e2 = 0, e3 = 0, e4 = 0, k = 0; //initialize at 0
     op1 = '+', op2 = '+', op3 = '+', op4 = '+'; // {+,-}
}

FUNCTION_NODE HILL_CLIMB::search(vector <double> input, vector <double> output)
{
     generate_initial_level(input, output); //fill 'open' with best fit function from expansion of variable 'a'

     FUNCTION_NODE bestFunction = open.top(); //sets initial best fit function to first function on queue

     while (!open.empty())
     {
          node = open.top(); //"pop" a function off of stack
          open.pop();

          if (heuristicValue(node) < heuristicValue(bestFunction)) //checks to see if a better fitting function has been found
          {
               bestFunction = node; //if so change bestFunction to better fitting function
          }
          generate_child(node, input, output); // generates child of best fit function from expansion of current variable
     }
     return bestFunction;
}

void HILL_CLIMB::generate_initial_level(vector <double> input, vector <double> output)
{
     
     vector <FUNCTION_NODE> functions;
     int currentState = state_a;
     
     for (a = 0; a < 5; a++) //expand 'a'
     {
          functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState)); //add all current level functions to an empty vector
     }

     open.push(heuristic(functions)); //run heuristic function to add best fit function from level to stack, discard the rest
}

void HILL_CLIMB::generate_child(FUNCTION_NODE node, vector <double> input, vector <double> output)
{
     int currentState;
     vector <FUNCTION_NODE> functions;
     switch (node.state)
     {
     case state_a:
     {
          currentState = state_e1;
          for (e1 = 0; e1 < 5; e1++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState)); //add all current level functions to an empty vector
          }

          open.push(heuristic(functions)); //run heuristic function to add best fit function from level to stack, discard the rest
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
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }
     case state_op1://expand 'b'
     {
          currentState = state_b;
          for (b = 0; b < 5; b++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState)); 
          }

          open.push(heuristic(functions)); 
          break;

     }
     case state_b://expand 'e2'
     {
          currentState = state_e2;
          for (e2 = 0; e2 < 5; e2++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState)); 
          }

          open.push(heuristic(functions)); 
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
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }
     case state_op2://expand 'c'
     {
          currentState = state_c;
          for (c = 0; c < 5; c++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }
     case state_c://expand 'e3'
     {
          currentState = state_e3;
          for (e3 = 0; e3 < 5; e3++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
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
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }
     case state_op3://expand 'd'
     {
          currentState = state_d;
          for (d = 0; d < 5; d++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }
     case state_d://expand 'e4'
     {
          currentState = state_e4;
          for (e4 = 0; e4 < 5; e4++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
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
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }
     case state_op4://expand 'k'
     {
          currentState = state_k;
          for (k = 0; k < 5; k++)
          {
               functions.push_back(fillFunctionNode(a, b, c, d, e1, e2, e3, e4, k, op1, op2, op3, op4, input, output, currentState));
          }

          open.push(heuristic(functions));
          break;
     }

     }
}

#endif