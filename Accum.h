#ifndef Accum_h_already_included
#define Accum_h_already_included

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

#endif