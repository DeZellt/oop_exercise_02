#ifndef D_BITSTRING_H_
#define D_BITSTRIGN_H_ 1

#include <iostream>
#include <cstdint>
#include <sstream>

class bitstring {

private:
    uint32_t m_first;
    uint64_t m_second;
    void shiftLeftOne();
    void shiftRightOne();
    void shiftLeft(int32_t i);
    void shiftRight(int32_t i);
    int32_t findOne() const;
    int32_t findTwo() const;
    int32_t length() const;

public:
    bitstring(uint32_t first=0, uint64_t second=0);
    bitstring operator&(const bitstring& r) const;
    bitstring operator|(const bitstring& r) const;
    bitstring operator^(const bitstring& r) const;
    bitstring operator~() const;
    int32_t countone() const;
    bool equal(const bitstring& r) const;
    bool operator==(const bitstring& r) const;
    bool operator>(const bitstring& r) const;
    bool operator<(const bitstring& r) const;
    bitstring operator>>(const int32_t i) const;
    bitstring operator<<(const int32_t i) const;
    friend std::ostream& operator<<(std::ostream& os, const bitstring& bts);
    friend std::istream& operator>>(std::istream& is, bitstring& bts);
    bool include(const bitstring& r) const;
    uint64_t getS() const;
    uint32_t getF() const;
};

bitstring operator""_bitstring(const char* str, size_t);

#endif