#ifndef RESTAURANT_UTILS_H
#define RESTAURANT_UTILS_H
#include <cstddef>
namespace Restaurant {
   class Utils {
   public:
      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;
      static int getInt();
      static int getInt(int min,int max);
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
   
}

#endif // !RESTAURANT_UTILS_H