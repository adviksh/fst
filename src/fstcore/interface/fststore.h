/*
  fstlib - A C++ library for ultra fast storage and retrieval of datasets

  Copyright (C) 2017-present, Mark AJ Klik

  BSD 3-Clause (https://opensource.org/licenses/BSD-3-Clause)

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.

  3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  You can contact the author at :
  - fstlib source repository : https://github.com/fstPackage/fstlib
*/


#ifndef FST_STORE_H
#define FST_STORE_H


#include <vector>
#include <memory>

#include <interface/icolumnfactory.h>
#include <interface/ifsttable.h>


class FstStore
{
  std::string fstFile;
  std::unique_ptr<char[]> metaDataBlockP;
  std::unique_ptr<IStringColumn> blockReaderP;

  public:
    IStringColumn* blockReader;

    unsigned long long* p_nrOfRows;
    int* keyColPos;

    char* metaDataBlock;

  	// column info
    unsigned short int* colTypes;
    unsigned short int* colBaseTypes;
    unsigned short int* colAttributeTypes;
    unsigned short int* colScales;

    //unsigned int version;
    int nrOfCols, keyLength;

    FstStore(std::string fstFile);

    ~FstStore() { }

	/**
     * \brief Stream a data table
     * \param fstTable Table to stream, implementation of IFstTable interface
     * \param compress Compression factor with a value 0-100
     */
    void fstWrite(IFstTable &fstTable, int compress) const;

    void fstMeta(IColumnFactory* columnFactory);

    void fstRead(IFstTable &tableReader, IStringArray* columnSelection, long long startRow, long long endRow,
      IColumnFactory* columnFactory, std::vector<int> &keyIndex, IStringArray* selectedCols);
};


#endif  // FST_STORE_H
