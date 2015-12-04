// EAN13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "CheckDigit.h"

using std::cin;
using std::cout;
using std::endl;

// s may be of any length and should contain check digit
bool TestThorough(const string &s)
{
  if (s.empty()) return false;
  string s1=s.substr(0, s.length()-1); // Trim check digit

  AppendCheckDigit(s1);
  return (s==s1) && VerifyCheckDigit(s1);
}

bool TestEan13(const string &s, bool bExpected)
{
  const bool bVerified=VerifyCheckDigitEan13(s) && TestThorough(s);
  const bool bResult=(bExpected==bVerified);
  if (!bResult) cout << "Error in Ean13 " << s << endl;
  return bResult;
}

bool TestEan8(const string &s, bool bExpected)
{
  const bool bVerified=VerifyCheckDigitEan8(s) && TestThorough(s);
  const bool bResult=(bExpected==bVerified);
  if (!bResult) cout << "Error in Ean8 " << s << endl;
  return bResult;
}

bool TestUpc12(const string &s, bool bExpected)
{
  const bool bVerified=VerifyCheckDigitUpc12(s) && TestThorough(s);
  const bool bResult=(bExpected==bVerified);
  if (!bResult) cout << "Error in Upc12 " << s << endl;
  return bResult;
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

bool TestRandomCaseEan13()
{
  string s;

  for (int i=0; i<12; ++i) {
    const char ch='0'+rand()%10;
    s+=ch;
  }

  if (!AppendCheckDigitEan13(s)) return false;
  if (!TestEan13(s, true))       return false;

  return true;
}

// Random string length
bool TestRandomCase()
{
  string s;

  const int nLength=1+rand()%500;

  for (int i=0; i<nLength; ++i) {
    const char ch='0'+rand()%10;
    s+=ch;
  }

  if (!AppendCheckDigit(s)) return false;
  if (!TestThorough(s))     return false;

  return true;
}

bool TestRandomCases(int nCount)
{
  srand((unsigned int)time(0));

  for (int i=0; i<nCount; ++i) {
    if (!TestRandomCaseEan13()) {
      cout << "Random test Ean13 failed!!! Count: " << i << endl;
      return false;
    }

    if (!TestRandomCase()) {
      cout << "Random test failed!!! Count: " << i << endl;
      return false;
    }
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

/////////////////////////////////////////////////////////////////////////////////////
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

