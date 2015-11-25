#include "stdafx.h"

#include "Accum.h"

CAccum::CAccum()
 : m_bOdd(false),
   m_nSumLEven(0),
   m_nSumLOdd(0)
{
}

bool CAccum::AddDigit(int nDigit)
{
  if (nDigit<0 || nDigit>9) return false;

  if (m_bOdd) m_nSumLOdd =(m_nSumLOdd +nDigit)%10;
         else m_nSumLEven=(m_nSumLEven+nDigit)%10;

  m_bOdd=!m_bOdd;
  return true;
}

bool CAccum::AddChar(char ch)
{
  return AddDigit(ch-'0');
}

bool CAccum::AddChar(wchar_t wch)
{
  return AddDigit(wch-'0');
}

int CalcCurrentSum(int nSumROdd, int nSumREven) // четность считаем СПРАВА, начиная с 0
{
  return (nSumROdd*3+nSumREven)%10;
}

int CalcCurrentSum(int nSumLOdd, int nSumLEven, bool bOdd) // четность считаем СЛЕВА, начиная с 0
{
  if (bOdd) return CalcCurrentSum(nSumLOdd,  nSumLEven);
            return CalcCurrentSum(nSumLEven, nSumLOdd);
}

int CAccum::GetCurrentSum() const
{
  return CalcCurrentSum(m_nSumLOdd, m_nSumLEven, m_bOdd);
}

int CAccum::GetCheckDigit() const
{
  // расчитываем сумму в предположении, что будет добавлен еще один символ, поэтому !m_bOdd
  const int nCheckDigit=CalcCurrentSum(m_nSumLOdd, m_nSumLEven, !m_bOdd);

  return (10-nCheckDigit)%10;
}

char CAccum::GetCheckDigitChar() const
{
  return GetCheckDigit()+'0';
}

wchar_t CAccum::GetCheckDigitWChar() const
{
  return GetCheckDigit()+'0';
}


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
