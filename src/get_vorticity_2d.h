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

#ifndef get_vorticity_2d_h
#define get_vorticity_2d_h

class Get_vorticity_2d
{
  int i,j,ic,il,ista,iend;
  double w,dx,dy;
public:
  void get_vorticity(PARTICLE *particle,CLUSTER *cluster)
  {
    for (ic=cluster->icsta; ic<cluster->icend; ic++) {
      Get_trunc_2d trunc;
      trunc.get_trunc(particle,cluster,ic);
      ista = cluster->ista[ic];
      iend = cluster->iend[ic];
      for (i=ista; i<=iend; i++) {
        w = 0;
        for (j=0; j<cluster->nptruncj; j++) {
          dx = particle->xil[i]-cluster->xjt[j];
          dy = particle->yil[i]-cluster->yjt[j];
          w += cluster->gjt[j]*exp(-(dx*dx+dy*dy)/(2*particle->sigma*particle->sigma))/
            (2*M_PI*particle->sigma*particle->sigma);
        }
        particle->wil[i] = w;
      }
    }
  }
};

#endif /*get_vorticity_2d_h*/

