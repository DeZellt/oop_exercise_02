#include <iostream>
#include <cstdint>
#include "bitstring.h"

int main() {

  uint32_t bitleft;
  uint32_t bitright;
  uint32_t incfirst;
  uint64_t incsecond;

  bitstring literal_test = "8928 1179048"_bitstring;
  std::cout << "Строка, сконструированная с помощью пользовательского литерала:" << literal_test << std::endl;
  
  bitstring a;
  std::cout << "Введите данные в следующем формате: *32-битовая строка* + *64-битовая строка*.\n";
  std::cin >> a;

  bitstring f;
  std::cout << "Введите данные для второй строки в следующем формате: *32-битовая строка* + *64-битовая строка*.\n";
  std::cin >> f;

  std::cout << "Сейчас будут выведены первая строка и вторая строка." << std::endl;
  std::cout << a << std::endl;
  std::cout << f << std::endl;
  
  std::cout << "Сейчас будут проведены стандартные битовые операции с вашей строкой." << std::endl;
  std::cout << a << " & " << f << " = " << (a & f) << std::endl;
  std::cout << a << " | " << f << " = " << (a | f) << std::endl;
  std::cout << a << " ^ " << f << " = " << (a ^ f) << std::endl;
  std::cout << "~(" << a << ") = " << ~a << std::endl;

  std::cout << "Введите через пробел кол-во битов, на которое требуется сделать сдвиг" << std::endl;
  std::cin >> bitleft >> bitright;
  std::cout << "Сейчас будет проведен сдвиг на " << bitleft << " битов влево и на " << bitright << " битов вправо. После сдвига будет печататься состояние строки." << std::endl;
  a.shiftLeft(bitleft);
  std::cout << a << std::endl;
  a.shiftRight(bitright);
  std::cout << a << std::endl;
  
  std::cout << "А теперь проверим еще функции. Для того, чтобы проверить функцию включения, введите еще одно число в следующем формате: *32-битовая строка* + *64-битовая строка*." << std::endl;
  std::cin >> incfirst >> incsecond;
  bitstring inc{incfirst, incsecond};
  std::cout << "Кол-во единиц равно " << a.countone() << std::endl;
  std::cout << a << " == " << inc << "? Это " << ((a == inc) ? "правда" : "неправда") << std::endl;
  std::cout << a << " > " << inc << "? Это " << ((a > inc) ? "правда" : "неправда") << std::endl;
  std::cout << a << " < " << inc << "? Это " << ((a < inc) ? "правда" : "неправда") << std::endl;
  std::cout << "В " << a << " включено " << inc.getF() << " " << inc.getS() << "? Это " << (a.include(inc) ? "правда" : "неправда") << std::endl;
  return 0;
}