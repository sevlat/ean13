#ifndef Accum_h_already_included
#define Accum_h_already_included

using std::string;

// ����������� �����, ����������� ��� ���������� ����������� �����.
// ����� �������������� ��� EAN8, UPC12, EAN13 ... ��� ������ ���������� ����,
// .. �� �������������, ��� ��� �������� ������ ��������� ����� ����
// � �������� ���������� ��������� ��������, ��� ��� ������������ �� �������� �������
class CAccum {
 public:
  CAccum();

 public: // ���������������� ���� ����
  bool AddDigit(int nDigit);           // � ���� �����

  bool AddChar(char ch);               // � ���� �������
  bool AddChar(wchar_t wch);           // � ���� ������� (wchar_t)

 public:
 // ������������ ������� �������� ����������� �����.
 // ���� ������ CAccum �������� ������, ���������� ����������� �����, �� ������ ���� 0
  int GetCurrentSum() const;

 // ������������ ������� ����������� �����
  int GetCheckDigit() const;

 public: // ������������ ������� ����������� ����� - � ���� �������
  char GetCheckDigitChar() const;
  wchar_t GetCheckDigitWChar() const;

 private:
  bool m_bOdd; // ���������� ���������� ����������� ��������

 private: // ��������� ����� ����
  int m_nSumLEven;  // ������ ���� (����� ������� �����, ������� � 0)
  int m_nSumLOdd;   // �������� ����
};


//////////////////////////////////////////////////////////////////////////////
// ��������� ����������� ����� (����� ������ �� �����������)
bool AppendCheckDigit(string &s);

// ��������� ����������� ����� (����� ������ �� �����������)
bool VerifyCheckDigit(const string &s);


//////////////////////////////////////////////////////////////////////////////
// ����� - nBase - ����� ������ � ����������� ������
// �� ����, � AppendCheckDigit ������ ����������� ������ ������ �� 1 ������

// ��������� ����������� �����, �������� ����� ������
bool AppendCheckDigit(string &s, int nBase);

// ��������� ����������� �����, �������� ����� ������
bool VerifyCheckDigit(const string &s, int nBase);


//////////////////////////////////////////////////////////////////////////////
// �� ��, ��� EAN-13
bool AppendCheckDigitEan13(string &s);       // ������ ������ ���� ������ 12
bool VerifyCheckDigitEan13(const string &s); // ������ ������ ���� ������ 13

//////////////////////////////////////////////////////////////////////////////
// �� ��, ��� EAN-8
bool AppendCheckDigitEan8(string &s);       // ������ ������ ���� ������ 7
bool VerifyCheckDigitEan8(const string &s); // ������ ������ ���� ������ 8

//////////////////////////////////////////////////////////////////////////////
// �� ��, ��� UPC-12
bool AppendCheckDigitUpc12(string &s);       // ������ ������ ���� ������ 11
bool VerifyCheckDigitUpc12(const string &s); // ������ ������ ���� ������ 12

#endif