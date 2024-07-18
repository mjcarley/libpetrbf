// #include <mpi.h>
#include "par_2d.h"

void mpi_range_2d(MPI2 *mpi)
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
