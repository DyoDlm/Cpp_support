#include <iostream>
#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 10
int main(int, char**)
{
   Array<int> numbers(MAX_VAL);
   int* mirror = new int[MAX_VAL];
   srand(time(NULL));
   for (int i = 0; i < MAX_VAL; i++)
   {
       const int value = rand();
       numbers[i] = value;
       mirror[i] = value;
   }
   std::cout << "Numbers 0 : \n" << numbers;
   std::cout << "Mirror 0  : \n" << *mirror;
//   //SCOPE
   {
       Array<int> tmp = numbers;
       Array<int> test(tmp);
   }
   for (int i = 0; i < MAX_VAL; i++)
   {
      if (mirror[i] != numbers[i])
      {
          std::cerr << "didn't save the same value!!" << std::endl;
          return 1;
      }
   }
   std::cout << "Numbers 1 : " << numbers;
   try
   {
       numbers[-2] = 0;
   }
   catch(const std::exception& e)
   {
       std::cerr << e.what() << '\n';
   }
   try
   {
       numbers[MAX_VAL] = 0;
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }

   for (int i = 0; i < MAX_VAL; i++)
   {
       //numbers[i] = rand();
       numbers[i] = i;
   }

   std::cout << "Numbers 2 : " << numbers;

   delete [] mirror;
   return 0;
}