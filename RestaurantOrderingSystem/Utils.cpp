#include "Utils.h"
#include <iostream>
using namespace std;
namespace Restaurant {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   int Utils::getInt()
   {
      int num{};
      bool done = false;
      char nextChar;
      //cout << "You must enter a value:";

      while (!(done)) {
         if (!(cin >> num)) {
            cout << "Invalid integer: ";
            cin.clear();
         } else {
            nextChar = cin.get();
            if (nextChar != '\n') {
               cout << "Only an integer please: ";
            } else {
               done = true;
            }
         }
      }
         if (!done) {
            cin.ignore(1000, '\n');
         }

         return num;
         
      
   }
   int Utils::getInt(int min,int max)
   {
      int num{};
      bool valid = false;

      while (!valid) {
         num = getInt();
      if (num >= min && num <= max){
         return num;
      } else {
         cout << "Invalid value: [min <= value <= max], try again: ";
      }
   }
   return num;
   }


}