#include "stdafx.h"

#include "EanSum.h"

CEanSum::CEanSum()
 : m_bOdd(false),
   m_nSumEven(0),
   m_nSumOdd(0)
{
}

bool CEanSum::AddDigit(int nDigit)
{
  if (nDigit<0 || nDigit>9) return false;

  if (m_bOdd) m_nSumOdd =(m_nSumOdd +nDigit)%10;
         else m_nSumEven=(m_nSumEven+nDigit)%10;

  m_bOdd=!m_bOdd;
  return true;
}

bool CEanSum::AddChar(char ch)
{
  return AddDigit(ch-'0');
}

bool CEanSum::AddChar(wchar_t wch)
{
  return AddDigit(wch-'0');
}

int CEanSum::GetCurrentSum() const
{
  return (m_nSumOdd*3+m_nSumEven)%10;
}

int CEanSum::GetCheckDigit() const
{
  return (10-GetCurrentSum())%10;
}

char CEanSum::GetCheckDigitChar() const
{
  return GetCheckDigit()+'0';
}

wchar_t CEanSum::GetCheckDigitWChar() const
{
  return GetCheckDigit()+'0';
}


bool AppendCheckDigit(string &s)
{
  CEanSum CheckSum;
  for (char ch: s)
    if (!CheckSum.AddChar(ch)) return false;

  s.append(1, CheckSum.GetCheckDigitChar());

  return true;
}

bool VerifyCheckDigit(const string &s)
{
  CEanSum CheckSum;
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
