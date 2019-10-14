#include "bitstring.h" 
#include <iostream>
#include <cstdint>

bitstring::bitstring(uint32_t first, uint64_t second) {
    m_first = first;
    m_second = second;
}

int32_t bitstring::findOne() const { // ищет длину второго слова
    int32_t secondlen = 0;
    for (int32_t i = 0; i < 64; i++) if (((m_second >> i) & 1) == 1) secondlen = i;
    return ++secondlen;
}

int32_t bitstring::findTwo() const {
    int32_t firstlen = 0;
    for (int32_t i = 0; i < 32; i++) if (((m_first >> i) & 1) == 1) firstlen = i;
    return ++firstlen;
}

int32_t bitstring::length() const {return (findOne() + findTwo());}

bitstring bitstring::operator&(const bitstring& r) const {
    bitstring result{};
    result.m_first = m_first & r.m_first;
    result.m_second = m_second & r.m_second;
    return result;
}

bitstring bitstring::operator|(const bitstring& r) const { // побитовое "ИЛИ"
    bitstring result{};
    result.m_first = m_first | r.m_first;
    result.m_second = m_second | r.m_second;
    return result;
}

bitstring bitstring::operator^(const bitstring& r) const { // побитовое "ИСКЛ ИЛИ"
    bitstring result{};
    result.m_first = m_first ^ r.m_first;
    result.m_second = m_second ^ r.m_second;
    return result;
}

bitstring bitstring::operator~() const { // побитовое "НЕ"
    bitstring result{};
    result.m_first = ~m_first;
    result.m_second = ~m_second;
    return result;
}

void bitstring::shiftLeft(int32_t i) { // сдвиг на произвольное кол-во бит влево
    for (int32_t k=0; k<i; k++) shiftLeftOne();
}

void bitstring::shiftLeftOne() { // сдвиг влево на один бит
    const uint64_t max = 0x80000000;
    m_first <<= 1;
    if ((m_second & max) == max) m_first++;
    m_second <<= 1;
}

void bitstring::shiftRight(int32_t i) { // сдвиг вправо на i бит
    for (int32_t k=0; k<i; k++) shiftRightOne();
}

void bitstring::shiftRightOne() { // сдвиг вправо на один бит
    m_second >>= 1;
    if ((m_first & 1) == 1) m_second+= 0x80000000;
    m_first >>= 1;
}

int32_t bitstring::countone() const { // считает кол-во единиц
    int32_t count = 0;
    bitstring temp{m_first, m_second};
    for (int32_t i = 0; i < 96; i++) {
        if ((temp.getS() & 1) == 1) count++;
        temp.shiftRight(1);
    }
    return count;
}

bool bitstring::operator==(const bitstring& r) const {return(countone() == r.countone());}
bool bitstring::operator>(const bitstring& r) const {return(countone() > r.countone());}
bool bitstring::operator<(const bitstring& r) const {return(countone() < r.countone());}

std::ostream& operator<<(std::ostream& os, const bitstring& bts){
    return os << bts.getF() << " " << bts.getS();
}

std::istream& operator>>(std::istream& is, bitstring& bts){
    return is >> bts.m_first >> bts.m_second; 
}

bool bitstring::include(const bitstring& r) const {return (((m_first & r.getF()) == r.getF()) && ((m_second & r.getS()) == r.getS()));}

bitstring operator""_bitstring(const char* str, size_t) {
    std::stringstream ss(str);
    bitstring result;
    ss >> result;
    return result;
}

uint64_t bitstring::getS() const {return m_second;}
uint32_t bitstring::getF() const {return m_first;}
