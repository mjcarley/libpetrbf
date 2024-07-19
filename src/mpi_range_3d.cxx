// The MIT License (MIT)

// Copyright (c) 2015 Barba group

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Code modified by Michael Carley for incorporation into a library, 2024

// #include <mpi.h>
#include "par_3d.h"

void mpi_range_3d(MPI2 *mpi)
{
  int imin,iwork1,iwork2;
  iwork1 = (mpi->nend-mpi->nsta+1)/mpi->nprocs;
  iwork2 = (mpi->nend-mpi->nsta+1)%mpi->nprocs;
  if (mpi->myrank <= iwork2) {
    imin = mpi->myrank;
  } else {
    imin = iwork2;
  }
  mpi->ista = mpi->myrank*iwork1+mpi->nsta+imin;
  mpi->iend = mpi->ista+iwork1;
  if (mpi->myrank < iwork2) mpi->iend = mpi->iend+1;
}
