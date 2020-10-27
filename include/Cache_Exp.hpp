//
//  Copyright 2020 Avakimyanc Levon levon.avakimyanc.01@mail.ru
//

#ifndef INCLUDE_CACHE_EXP_HPP_
#define INCLUDE_CACHE_EXP_HPP_
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const size_t Kb = 1024;
class Cache_Exp {
 public:
  Cache_Exp();
  void Direct_variation();
  void Reverse_variation();
  void Random_variation();
  friend std::ostream& operator<<(std::ostream& out, const Cache_Exp& c);

 private:
  std::string travel_variations;
  std::vector<size_t> cache_size = {128 * Kb, 521 * Kb, 3072 * Kb};
  int k;
  std::vector<size_t> buffer_size;
  std::vector<double> results;
};

#endif  // INCLUDE_CACHE_EXP_HPP_
