// EAN13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Accum.h"

using std::cin;
using std::cout;
using std::endl;


bool TestEan13(const string &s, bool bCorrect)
{
  bool b=(bCorrect==VerifyCheckDigitEan13(s));
  if (!b) cout << "Error in Ean13 " << s << endl;
  return b;
}

bool TestEan8(const string &s, bool bCorrect)
{
  bool b=(bCorrect==VerifyCheckDigitEan8(s));
  if (!b) cout << "Error in Ean8 " << s << endl;
  return b;
}

bool TestUpc12(const string &s, bool bCorrect)
{
  bool b=(bCorrect==VerifyCheckDigitUpc12(s));
  if (!b) cout << "Error in Upc12 " << s << endl;
  return b;
}

bool TestSpecialCases()
{
// проверяем корректные значения
  if (!TestEan13("4607071770328", true)) return false;
  if (!TestEan13("4620001053575", true)) return false;
  if (!TestEan13("4601892006963", true)) return false;

  if (!TestEan13("4600051000057", true)) return false; // сигареты «Прима»
  if (!TestEan8 ("46009333",      true)) return false; // папиросы «Беломорканал»
  if (!TestUpc12("041689300494",  true)) return false; // бензин для зажигалки «Zippo»

// проверяем некорректные значения
  if (!TestEan13("12345679",      false)) return false;
  if (!TestEan13("5555555555555", false)) return false;

  return true;
}

bool TestRandomCase()
{
  string s;

  for (int i=0; i<12; ++i) {
    const char ch='0'+rand()%10;
    s+=ch;
  }

  return AppendCheckDigitEan13(s) && TestEan13(s, true);
}

bool TestRandomCases(int nCount)
{
  srand((unsigned int)time(0));

  for (int i=0; i<nCount; ++i) {
    if (!TestRandomCase()) return false;
  }

  return true;
}

// Если 12 символов - добавляем контрольный
// Если 13 символов - проверяем контрольный
void ProcessEan13(string s)
{
  cout << s << ": ";

  if (s.length()==12) {
    if (AppendCheckDigitEan13(s)) {
      cout << "Added check digit: " << s << endl;
    } else {
      cout << "Error in code !!!" << endl;
    }
  } else if (s.length()==13) {
    if (VerifyCheckDigitEan13(s)) {
      cout << "OK! CheckDigit verified" << endl;
    } else {
      cout << "Error!!!" << endl;
    }
  }
}

bool TestAll()
{
  if (!TestSpecialCases())   return false;
  if (!TestRandomCases(100)) return false;

  return true;
}

// Если без аргументов - выполняется тест
// Для аргументов вычисляется или проверяется контрольная цифра
// Если 12 цифр - то вычисляется
// Если 13 цифр - то проверяется
int main(int argc, char* argv[])
{
  if (argc==1) {
    if (TestAll()) {
      cout << "Test OK" << endl;
      return EXIT_SUCCESS;
    } else {
      cout << "Test failed!!!" << endl;
      return EXIT_FAILURE;
    }
  }

  for (int i=1; i<argc; ++i) {
    ProcessEan13(argv[i]);
  }

  return EXIT_SUCCESS;
}

