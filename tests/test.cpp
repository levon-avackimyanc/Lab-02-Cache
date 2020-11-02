//
//  Copyright 2020 Avakimyanc Levon levon.avakimyanc.01@mail.ru
//
#include <gtest/gtest.h>

#include <iostream>

#include "Cache_Exp.hpp"

TEST(Cache_Exp, Main) {
  Cache_Exp C;
  C.Direct_variation();
  std::cout << C;
  C.Reverse_variation();
  std::cout << C;
  C.Random_variation();
  std::cout << C;
}
