#include <iostream>
#include "MyString.h"


int main() {
   MyString a,b,c,d,e,all;
   a = "Hello world";
   b ="Hello";
   std::cout<<a.in(b)<<std::endl;
   std::cout<<b.in("lo")<<std::endl;

   c="my name";
   d = "Roma";
   all = c + " is " + d;
   all.Print();
   d.UP().Print();
   d.reverse().Print();

   a+=all;
   a.Print();

   (all*3).Print();
   std::cout<<d[2]<<d[-1]<<std::endl;

    return 0;
}
