/*
** Test 
***************************************************************
** (c) Konrad Merkel
** 4. Mai 2013
**************************************************************/
#ifndef TEST_H
#define TEST_H

#include<iostream>
#include"error.h"

using namespace std;

/*
 * Dies ist ein Teil der Framework von Konrad Merkel.
 * Jedoch wurden die übernommenen Dateien etwas geändert um
 * Kompatibel zum Moskito-Projekt zu sein.
 *
*/

using namespace std;
unsigned long int count = 0;
unsigned int anyBug = 0;

template< typename T>
class Test : public BugReport
{
public:
  Test()  {}
  ~Test() {}
  
  bool comp(char const* label, T const& a, T const& should, T const& difference)
  {
    extern unsigned long int count;
    count++;
    if((a >= should - difference) && (a <= should + difference)){
      cout << count << ": [OK] " << label << " " << a << " == " << should << endl;
      return true;
    }else{
      cout << count << ": [FAIL] " << label << " value = " << a << " should be " << should << endl;
      anyBug++;
      return false;
    }
  }
  bool comp(char const* label, T const& a, T const& should)
  {
    extern unsigned long int count;

    count++;
    if(a == should){
      cout << count << ": [OK] " << label << " " << a << " == " << should << endl;
      return true;
    }else{
      cout << count << ": [FAIL] " << label << " value = " << a << " should be " << should << endl;
      anyBug++;
      return false;
    }
  }
  static unsigned int isAnyBug()
  {
    status();
    if (anyBug)
      cout << "[B]   {" << anyBug << " bug(s)}\n";
    else
      cout << "[OK]  {No bugs.}\n";
    return anyBug;
  }
};


#endif
