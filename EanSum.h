#ifndef EanSum_h_already_included
#define EanSum_h_already_included

using std::string;

// ����������� �����, ����������� ��� ���������� ����������� �����.
// ����� �������������� ��� EAN8, UPC12, EAN13 ... ��� ������ ���������� ����,
// .. �� �������������, ��� ��� �������� ������ ��������� ����� ����
// � �������� ���������� ��������� ��������, ��� ��� ������������ �� �������� �������
class CEanSum {
 public:
  CEanSum();

 public: // ���������������� ���� ����
  bool AddDigit(int nDigit);           // � ���� �����

  bool AddChar(char ch);               // � ���� �������
  bool AddChar(wchar_t wch);           // � ���� ������� (wchar_t)

 public:
 // ������������ ������� �������� ����������� �����.
 // ���� ������ CEanSum �������� ������, ���������� ����������� �����, �� ������ ���� 0
  int GetCurrentSum() const;

 // ������������ ������� ����������� �����
  int GetCheckDigit() const;

 public: // ������������ ������� ����������� ����� - � ���� �������
  char GetCheckDigitChar() const;
  wchar_t GetCheckDigitWChar() const;

 private:
  bool m_bOdd; // ���������� ���������� ����������� ��������

 private: // ��������� ����� ����
  int m_nSumEven;  // ������ ���� (����� ������� �� 0)
  int m_nSumOdd;   // �������� ����
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
// �� ��, ��� EAN13
bool AppendCheckDigitEan13(string &s);       // ������ ������ ���� ������ 12
bool VerifyCheckDigitEan13(const string &s); // ������ ������ ���� ������ 13

#endif