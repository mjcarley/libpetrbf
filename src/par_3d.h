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

#ifndef par_3d_h
#define par_3d_h

#include <petscksp.h>

struct PARAMETER{
int nt;
int memory;
double vis;
double t;
double dt;
double u_inf;
};

struct PARTICLE{
int n;
int no;
int ni;
int nj;
int nilocal;
int njlocal;
int ista;
int iend;
int jsta;
int jend;
double sigma;
double sigma0;
double overlap;
double h;
double xmin;
double xmax;
double ymin;
double ymax;
double zmin;
double zmax;
double r_grid;
Vec i;
Vec j;
Vec ii;
Vec jj;
Vec xi;
Vec yi;
Vec zi;
Vec gi;
Vec wi;
Vec xj;
Vec yj;
Vec zj;
Vec gj;
PetscScalar *il;
PetscScalar *jl;
PetscScalar *xil;
PetscScalar *yil;
PetscScalar *zil;
PetscScalar *gil;
PetscScalar *wil;
PetscScalar *xjl;
PetscScalar *yjl;
PetscScalar *zjl;
PetscScalar *gjl;
};

struct BOUNDARY{
int n;
double r;
double *x;
double *y;
double *z;
double *g;
double *ut;
double *vt;
double *vnx;
double *vny;
double *vtx;
double *vty;
};

struct CLUSTER{
int nsigma_box;
int sigma_buffer;
int sigma_trunc;
int n;
int nx;
int ny;
int nz;
int neighbor_buffer;
int neighbor_trunc;
int neighbor_ghost;
int niperbox;
int njperbox;
int nclocal;
int ncghost;
int nighost;
int njghost;
int npbufferi;
int nptruncj;
int maxbuffer;
int maxtrunc;
int maxghost;
int maxlocal;
int file;
int icsta;
int icend;
int *ista;
int *iend;
int *jsta;
int *jend;
int *ix;
int *iy;
int *iz;
int *ilocal;
int *jlocal;
int *ighost;
int *jghost;
int *idx;
int *jdx;
double xmin;
double xmax;
double ymin;
double ymax;
double zmin;
double zmax;
double box_length;
double buffer_length;
double trunc_length;
double *xc;
double *yc;
double *zc;
double *xib;
double *yib;
double *zib;
double *gib;
double *wib;
double *xjt;
double *yjt;
double *zjt;
double *gjt;
};

struct GRID{
int nx;
int ny;
int nz;
};

struct HIERARCHICAL{
int mp;
};

struct MPI2{
int nprocs;
int myrank;
int nsta;
int nend;
int ista;
int iend;
double *sendi;
double *recvi;
double *sendj;
double *recvj;
};

struct BOTH{
PARTICLE *p;
CLUSTER *c;
};

const double epsf=1e-6;

#endif /*par_3d_h*/
