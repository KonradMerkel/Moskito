/*
** Error
***************************************************************
** (c) Konrad Merkel
** 4. Mai 2013
**************************************************************/
#ifndef ERROR_H
#define ERROR_H
#include <iostream>


using namespace std;
unsigned int warnings = 0;
unsigned int errors = 0;

class BugReport
{
public:
  BugReport() {}
  ~BugReport() {}
  
  static void error(char const* str, char const* location, bool conti=false)
  {
    cerr <<"[ERROR] : " << str << " in " << location << endl;
    errors++;
    //maybe time
    if(!conti) {
      status();
      exit(1);
    }
  }

  static void warning(char const* str, char const* location)
  {
    cerr <<"[WARNING] : " << str << " in " << location << endl;
    warnings++;
  }
  
  static char const* getBugByNum(int number)  //nummern sind nur für dieses Framework gültig
  {                                           // negative Werte sind gelten als Error, positive als Warnung
    switch(number){
      case -1: return "Speicher übergelaufen";
      case -2: return "Fehler bei der Speicheranforderung. malloc hat NULL zurückgegeben";
      case -3: return "Unmöglich Datei zu öffnen. Existiert die Datei? Haben Sie alle Rechte?";
      
      case 1: return "Speicherüberlauf konnte durch Null-Objekt abgefangen werden. Das Objekt darf aber auch keinen Fall beschrieben werden!";
      case 2: return "Dimensionsüberschreitung. Für weitere Dimensionen wird Null angenommen. Ist das nicht richtig müssten Sie vorher die Objekte größer dimensionieren!";
    }
  }
  
  static void failNumber(int number, char const* location, bool contin = false)
  {
    if (number >= 0) {warning(getBugByNum(number), location);}
    else {error(getBugByNum(number), location, contin);}
  }
  
  static unsigned int status()
  {
    if (errors)
      cout << "\n[E]  {" << errors << " errors(s)}\n";
    else
      cout << "\n[OK]  {No error.}\n";
    
    if (warnings)
      cout << "[W]   {" << warnings << " warning(s)}\n";
    else
      cout << "[OK]  {No warning.}\n";
    
    return warnings + errors;
  }
};
#endif
