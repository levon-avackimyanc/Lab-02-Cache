//
//  Copyright 2020 Avakimyanc Levon levon.avakimyanc.01@mail.ru
//

#include "Cache_Exp.hpp"

#include <algorithm>
#include <random>
const size_t sixteen = 16;
const size_t thousand = 1000;

Cache_Exp::Cache_Exp() {
  for (size_t i = 1.0 / 2 * cache_size[0]; i < 3.0 / 2 * cache_size[2];
       i *= 2) {
    buffer_size.push_back(i);
  }
  buffer_size.push_back(3.0 / 2 * cache_size[2]);
}
void Cache_Exp::Direct_variation() {
  travel_variations = "Direct";
  if (!results.empty()) {
    results.clear();
  }
  for (const size_t &i : buffer_size) {
    int *arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += sixteen) {
      k = arr[j];
    }
    clock_t start = clock();
    for (size_t count = 0; count < thousand; ++count) {
      for (size_t j = 0; j < i / 4; j += sixteen) {
        k = arr[j];
      }
    }
    clock_t end = clock();
    results.push_back(static_cast<double>(end - start) / CLOCKS_PER_SEC *
                      thousand);
    delete[] arr;
  }
}
void Cache_Exp::Reverse_variation() {
  travel_variations = "Reverse";
  if (!results.empty()) {
    results.clear();
  }
  for (const size_t &i : buffer_size) {
    int *arr = new int[i / 4];
    for (size_t j = i / 4; j > 0; j -= sixteen) {
      k = arr[j - 1];
    }
    clock_t start = clock();
    for (size_t count = 0; count < thousand; ++count) {
      for (size_t j = i / 4; j > 0; j -= sixteen) {
        k = arr[j - 1];
      }
    }
    clock_t end = clock();
    results.push_back(static_cast<double>(end - start) / CLOCKS_PER_SEC *
                      thousand);
    delete[] arr;
  }
}
void Cache_Exp::Random_variation() {
  travel_variations = "Random";
  if (!results.empty()) {
    results.clear();
  }
  for (const size_t &i : buffer_size) {
    int *arr = new int[i / 4];
    std::vector<size_t> random_numbers;
    for (size_t j = 0; j < i / 4; j += sixteen) {
      k = arr[j];
      random_numbers.push_back(j);
    }
    std::random_device rd;
    std::minstd_rand rnd(rd());
    std::shuffle(random_numbers.begin(), random_numbers.end(), rnd);
    clock_t start = clock();
    for (size_t count = 0; count < thousand; ++count) {
      for (const size_t &j : random_numbers) {
        k = arr[j];
      }
    }
    clock_t end = clock();
    results.push_back(static_cast<double>(end - start) / CLOCKS_PER_SEC *
                      thousand);
    delete[] arr;
  }
}
std::ostream &operator<<(std::ostream &out, const Cache_Exp &C) {
  out << "investigation:\n"
      << "\ttravel_order: " << C.travel_variations << "\n"
      << "\texperiments:\n";
  for (size_t i = 0; i < C.buffer_size.size(); ++i) {
    out << "\t- experiment: \n"
        << "\t\tnumber: " << i + 1 << "\n"
        << "\t\tinput_data:\n"
        << "\t\t\tbuffer_size: " << C.buffer_size[i] / Kb << "KB\n"
        << "\t\tresults:\n"
        << "\t\t\tduration: " << C.results[i] << "ns\n";
  }
  return out;
}
