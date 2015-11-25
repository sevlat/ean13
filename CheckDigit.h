#ifndef CheckDigit_h_already_included
#define CheckDigit_h_already_included

using std::string;

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
// То же, для EAN-13
bool AppendCheckDigitEan13(string &s);       // строка должна быть длиной 12
bool VerifyCheckDigitEan13(const string &s); // строка должна быть длиной 13

//////////////////////////////////////////////////////////////////////////////
// То же, для EAN-8
bool AppendCheckDigitEan8(string &s);       // строка должна быть длиной 7
bool VerifyCheckDigitEan8(const string &s); // строка должна быть длиной 8

//////////////////////////////////////////////////////////////////////////////
// То же, для UPC-12
bool AppendCheckDigitUpc12(string &s);       // строка должна быть длиной 11
bool VerifyCheckDigitUpc12(const string &s); // строка должна быть длиной 12


#endif
