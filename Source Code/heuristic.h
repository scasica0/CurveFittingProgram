
#ifndef MYLIB3
#define MYLIB3

#include <vector>
#include "function.h"


double heuristicValue(FUNCTION_NODE function) //returns numerical value of heuristic
{
     return function.residual_squares;
}

FUNCTION_NODE heuristic(vector <FUNCTION_NODE> functions) //heuristic function to determine best fitting function from vector of functions
{
     FUNCTION_NODE bestFunction = functions.at(0);

     for (int i = 0; i < functions.size(); i++)
     {
          if (heuristicValue(functions.at(i)) < heuristicValue(bestFunction))
          {
               bestFunction = functions.at(i);
          }
     }

     return bestFunction;
}

#endif