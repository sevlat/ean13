#ifndef EanSum_h_already_included
#define EanSum_h_already_included

using std::string;

// Накапливает суммы, необходимые для вычисления контрольной цифры.
// Может использоваться для EAN8, UPC12, EAN13 ... для любого количества цифр,
// .. до бесконечности, так как хранятся только последние цифры сумм
// и четность количества введенных символов, так что переполнение не наступит никогда
class CEanSum {
 public:
  CEanSum();

 public: // Последовательный ввод цифр
  bool AddDigit(int nDigit);           // в виде чисел

  bool AddChar(char ch);               // в виде символа
  bool AddChar(wchar_t wch);           // в виде символа (wchar_t)

 public:
 // Рассчитывает текущее значение контрольной суммы.
 // Если классу CEanSum скормили строку, содержащую контрольную цифру, то должна быть 0
  int GetCurrentSum() const;

 // Рассчитывает текущую контрольную цифру
  int GetCheckDigit() const;

 public: // Рассчитывает текущую контрольную цифру - в виде символа
  char GetCheckDigitChar() const;
  wchar_t GetCheckDigitWChar() const;

 private:
  bool m_bOdd; // нечетность количества добавленных символов

 private: // последние цифры сумм
  int m_nSumEven;  // четных цифр (номер считаем от 0)
  int m_nSumOdd;   // нечетный цифр
};


//////////////////////////////////////////////////////////////////////////////
// Добавляет контрольную цифру (длина строки не проверяется)
bool AppendCheckDigit(string &s);

// Проверяет контрольную цифру (длина строки не проверяется)
bool VerifyCheckDigit(const string &s);


//////////////////////////////////////////////////////////////////////////////
// Здесь - nBase - длина строки с контрольной цифрой
// То есть, в AppendCheckDigit должна передваться строка длиной на 1 меньше

// Добавляет контрольную цифру, проверяя длину строки
bool AppendCheckDigit(string &s, int nBase);

// Проверяет контрольную цифру, проверяя длину строки
bool VerifyCheckDigit(const string &s, int nBase);


//////////////////////////////////////////////////////////////////////////////
// То же, для EAN13
bool AppendCheckDigitEan13(string &s);       // строка должна быть длиной 12
bool VerifyCheckDigitEan13(const string &s); // строка должна быть длиной 13

#endif