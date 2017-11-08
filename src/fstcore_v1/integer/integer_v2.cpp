/*
  fstlib - A C++ library for ultra fast storage and retrieval of datasets

  Copyright (C) 2017-present, Mark AJ Klik

  This file is part of fstlib.

  fstlib is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Foobar is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with fstlib.  If not, see <http://www.gnu.org/licenses/>.

  You can contact the author at :
  - fstlib source repository : https://github.com/fstPackage/fstlib
*/


// System libraries
#include <ctime>
#include <ratio>
#include <iostream>
#include <fstream>

#include <Rcpp.h>

#include <integer/integer_v2.h>
#include <blockstreamer/blockstreamer_v1.h>
#include <compression/compression.h>
#include <compression/compressor.h>

using namespace std;
using namespace Rcpp;

// SEXP fdsReadIntVec(ifstream &myfile, SEXP &intVec, unsigned long long blockPos, unsigned startRow, unsigned length, unsigned size, unsigned int attrBlockSize)
SEXP fdsReadIntVec_v2(ifstream &myfile, SEXP &intVec, unsigned long long blockPos, unsigned startRow, unsigned length, unsigned size)
{
  char* values = (char*) INTEGER(intVec);  // output vector

  return fdsReadColumn_v1(myfile, values, blockPos, startRow, length, size, 4);
}
