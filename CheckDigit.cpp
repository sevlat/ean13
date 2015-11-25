#include "stdafx.h"

#include "CheckDigit.h"

#include "Accum.h"

bool AppendCheckDigit(string &s)
{
  CAccum CheckSum;
  for (char ch: s)
    if (!CheckSum.AddChar(ch)) return false;

  s.append(1, CheckSum.GetCheckDigitChar());

  return true;
}

bool VerifyCheckDigit(const string &s)
{
  CAccum CheckSum;
  for (char ch: s) {
    if (!CheckSum.AddChar(ch)) return false;
  }

  return CheckSum.GetCurrentSum()==0;
}

////////////////////////////////////////////////////
bool AppendCheckDigit(string &s, int nBase)
{
  if (s.length()!=(nBase-1)) return false;
  return AppendCheckDigit(s);
}

bool VerifyCheckDigit(const string &s, int nBase)
{
  if (s.length()!=nBase) return false;
  return VerifyCheckDigit(s);
}


////////////////////////////////////////////////////
bool AppendCheckDigitEan13(string &s)
{
  return AppendCheckDigit(s, 13);
}

bool VerifyCheckDigitEan13(const string &s)
{
  return VerifyCheckDigit(s, 13);
}

////////////////////////////////////////////////////
bool AppendCheckDigitEan8(string &s)
{
  return AppendCheckDigit(s, 8);
}

bool VerifyCheckDigitEan8(const string &s)
{
  return VerifyCheckDigit(s, 8);
}

//////////////////////////////////////////////////////////////////////////////
bool AppendCheckDigitUpc12(string &s)
{
  return AppendCheckDigit(s, 12);
}

bool VerifyCheckDigitUpc12(const string &s)
{
  return VerifyCheckDigit(s, 12);
}