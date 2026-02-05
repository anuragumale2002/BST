// ==========================================
// Name: Anurag Prashant Umale              =
// Student Id: 1887255                      =
// E-mail: aumale@ucsc.edu                  =
// File: DictionaryTest.cpp					  =
// Class: CSE 101 Spring 2023               =
// ==========================================
#include <iostream>
#include <string>
#include <stdexcept>
#include "Dictionary.h"


int main()
{

   std::string s;
   int x;
   std::string S[] = {
       "plaices",
       "ambusher",
       "crosby",
       "wattles",
       "pardoner",
       "pythons",
       "second",
       "forms",
       "impales",
       "pic",
       "verticals",
       "recriminator",
       "depressants",
       "cul",
       "potables",
       "norm",
       "reinsurer",
       "deschooler",
       "recoining",
       "dissocialised",
       "cohabit",
       "hemiolia",
       "cantling",
       "glamorized",
       "millesimal",
       "glagolitic"};
   std::string T[] = {
       "second",
       "forms",
       "impales",
       "pic",
       "verticals",
       "recriminator",
       "depressants",
       "cul",
       "potables",
       "norm",
       "reinsurer",
       "deschooler",
       "recoining",
   };

   Dictionary A;
   Dictionary B;

   std::cout << std::endl;

   for (int i = 0; i < 26; i++)
   {
      A.setValue(S[i], i + 1);
   }

   B = A;

   std::cout << "A.size() = " << A.size() << std::endl
        << A << std::endl;
   std::cout << "B.size() = " << B.size() << std::endl
        << B << std::endl;

   B.setValue("deschooler", 101);
   B.setValue("reinsurer", 102);
   B.setValue("glagolitic", 103);
   B.setValue("cul", 104);
   B.setValue("ambusher", 105);

   Dictionary C = B;

   std::cout << "B.size() = " << B.size() << std::endl
        << B << std::endl;
   std::cout << "C.size() = " << C.size() << std::endl
        << C << std::endl;

   std::cout << "A==B is " << (A == B ? "true" : "false") << std::endl;
   std::cout << "B==C is " << (B == C ? "true" : "false") << std::endl;
   std::cout << "C==A is " << (C == A ? "true" : "false") << std::endl
        << std::endl;

   std::cout << "Value of 'hemiolia' in A: " << A.getValue("hemiolia") << std::endl;
   A.setValue("hemiolia", 99);
   std::cout << "Modified value of 'hemiolia' in A: " << A.getValue("hemiolia") << std::endl
        << std::endl;

   std::cout << "A.size() = " << A.size() << std::endl
        << A << std::endl;
   std::cout << "Pre-string: " << A.pre_string() << std::endl;

   for (int i = 0; i < 13; i++)
   {
      std::cout << "Removing " << T[i] << " from Dictionary A" << std::endl;
      A.remove(T[i]);
   }

   std::cout << "After remove loop" << std::endl;

   std::cout << "A.size() = " << A.size() << std::endl
        << A << std::endl;
   std::cout << "Pre-string: " << A.pre_string() << std::endl;

   std::cout << "Forward iteration on A: ";
   for (A.begin(); A.hasCurrent(); A.next())
   {
      s = A.currentKey();
      x = A.currentVal();
      std::cout << "(" + s + ", " << x << ") ";
   }
   std::cout << std::endl
        << std::endl;

   std::cout << "Reverse iteration on A: ";
   for (A.end(); A.hasCurrent(); A.prev())
   {
      s = A.currentKey();
      x = A.currentVal();
      std::cout << "(" + s + ", " << x << ") ";
   }
   std::cout << std::endl
        << std::endl;

   try
   {
      A.getValue("blah");
   }
   catch (std::logic_error &e)
   {
      std::cout << "Exception caught: " << e.what() << std::endl;
      std::cout << "Continuing without interruption" << std::endl;
   }
   try
   {
      A.remove("blah");
   }
   catch (std::logic_error &e)
   {
      std::cout << "Exception caught: " << e.what() << std::endl;
      std::cout << "Continuing without interruption" << std::endl;
   }
   try
   {
      A.currentKey();
   }
   catch (std::logic_error &e)
   {
      std::cout << "Exception caught: " << e.what() << std::endl;
      std::cout << "Continuing without interruption" << std::endl;
   }
   try
   {
      A.currentVal();
   }
   catch (std::logic_error &e)
   {
      std::cout << "Exception caught: " << e.what() << std::endl;
      std::cout << "Continuing without interruption" << std::endl;
   }
   try
   {
      A.next();
   }
   catch (std::logic_error &e)
   {
      std::cout << "Exception caught: " << e.what() << std::endl;
      std::cout << "Continuing without interruption" << std::endl;
   }
   try
   {
      A.prev();
   }
   catch (std::logic_error &e)
   {
      std::cout << "Exception caught: " << e.what() << std::endl;
      std::cout << "Continuing without interruption" << std::endl;
   }

   std::cout << std::endl;

   std::cout << "Additional test cases:" << std::endl
        << std::endl;

   Dictionary D;

   for (int i = 0; i < 5; i++)
   {
      D.setValue("Key" + std::to_string(i), i * 2);
   }

   std::cout << "D.size() = " << D.size() << std::endl
        << D << std::endl;

   for (int i = 0; i < 3; i++)
   {
      std::string key = "Key" + std::to_string(i);
      std::cout << "Removing " << key << " from Dictionary D" << std::endl;
      D.remove(key);
   }

   std::cout << "D.size() = " << D.size() << std::endl
        << D << std::endl;

   std::cout << "Forward iteration on D: ";
   for (D.begin(); D.hasCurrent(); D.next())
   {
      s = D.currentKey();
      x = D.currentVal();
      std::cout << "(" + s + ", " << x << ") ";
   }
   std::cout << std::endl
        << std::endl;

   std::cout << "Reverse iteration on D: ";
   for (D.end(); D.hasCurrent(); D.prev())
   {
      s = D.currentKey();
      x = D.currentVal();
      std::cout << "(" + s + ", " << x << ") ";
   }
   std::cout << std::endl
        << std::endl;

   std::string names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};

   Dictionary dict;

   for (int i = 0; i < 5; i++)
   {
      dict.setValue(names[i], i + 1);
   }

   std::cout << dict << std::endl;

   for (int i = 0; i < 5; i++)
   {
      std::cout << "Value of " << names[i] << ": " << dict.getValue(names[i]) << std::endl;
   }

   for (int i = 0; i < 3; i++)
   {
      std::cout << "Removing " << names[i] << " from the dictionary" << std::endl;
      dict.remove(names[i]);
   }

   for (int i = 0; i < 5; i++)
   {
      std::cout << "Contains " << names[i] << "? " << (dict.contains(names[i]) ? "Yes" : "No") << std::endl;
   }

   dict.begin();
   while (dict.hasCurrent())
   {
      std::cout << "Current key: " << dict.currentKey() << ", value: " << dict.currentVal() << std::endl;
      dict.next();
   }

   int numbers[] = {10, 20, 30, 40, 50};
   Dictionary numberDict;

   for (int i = 0; i < 5; i++)
   {
      numberDict.setValue(std::to_string(numbers[i]), (i + 1));
   }

   std::cout << numberDict << std::endl;

   for (int i = 0; i < 5; i++)
   {
      std::cout << "Value of " << numbers[i] << ": " << numberDict.getValue(std::to_string(numbers[i])) << std::endl;
   }

   for (int i = 0; i < 3; i++)
   {
      std::cout << "Removing " << numbers[i] << " from the dictionary" << std::endl;
      numberDict.remove(std::to_string(numbers[i]));
   }

   for (int i = 0; i < 5; i++)
   {
      std::cout << "Contains " << numbers[i] << "? " << (numberDict.contains(std::to_string(numbers[i])) ? "Yes" : "No") << std::endl;
   }

   numberDict.begin();
   while (numberDict.hasCurrent())
   {
      std::cout << "Current key: " << numberDict.currentKey() << ", value: " << numberDict.currentVal() << std::endl;
      numberDict.next();
   }

   float floats[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
   Dictionary floatDict;

   for (int i = 0; i < 5; i++)
   {
      floatDict.setValue(std::to_string(floats[i]), i + 1);
   }

   std::cout << floatDict << std::endl;

   for (int i = 0; i < 5; i++)
   {
      std::cout << "Value of " << floats[i] << ": " << floatDict.getValue(std::to_string(floats[i])) << std::endl;
   }

   for (int i = 0; i < 3; i++)
   {
      std::cout << "Removing " << floats[i] << " from the dictionary" << std::endl;
      floatDict.remove(std::to_string(floats[i]));
   }

   for (int i = 0; i < 5; i++)
   {
      std::cout << "Contains " << floats[i] << "? " << (floatDict.contains(std::to_string(floats[i])) ? "Yes" : "No") << std::endl;
   }

   floatDict.begin();
   while (floatDict.hasCurrent())
   {
      std::cout << "Current key: " << floatDict.currentKey() << ", value: " << floatDict.currentVal() << std::endl;
      floatDict.next();
   }

   Dictionary mixedDict;

   mixedDict.setValue("key1", 10);
   mixedDict.setValue(std::to_string(2.5f), 100);
   mixedDict.setValue(std::to_string(3), 1000);

   std::cout << mixedDict << std::endl;

   std::cout << "Value of key1: " << mixedDict.getValue("key1") << std::endl;
   std::cout << "Value of 2.5: " << mixedDict.getValue(std::to_string(2.5f)) << std::endl;
   std::cout << "Value of 3: " << mixedDict.getValue(std::to_string(3)) << std::endl;

   mixedDict.remove("key1");

   std::cout << "Contains key1? " << (mixedDict.contains("key1") ? "Yes" : "No") << std::endl;
   std::cout << "Contains 2.5? " << (mixedDict.contains(std::to_string(2.5f)) ? "Yes" : "No") << std::endl;
   std::cout << "Contains 3? " << (mixedDict.contains(std::to_string(3)) ? "Yes" : "No") << std::endl;

   mixedDict.begin();
   while (mixedDict.hasCurrent())
   {
      std::cout << "Current key: " << mixedDict.currentKey() << ", value: " << mixedDict.currentVal() << std::endl;
      mixedDict.next();
   }
   return EXIT_SUCCESS;
}
