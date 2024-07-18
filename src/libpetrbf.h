#ifndef __LIBPETRBF_H_INCLUDED__
#define __LIBPETRBF_H_INCLUDED__


PetscErrorCode rbf_interpolation_2d(Vec xi, Vec yi, Vec gi, Vec wi,
				    double sigma, int nsigma_box,
				    int sigma_buffer, int sigma_trunc,
				    int *its) ;
PetscErrorCode rbf_vorticity_evaluation_2d(Vec xi, Vec yi, Vec wi,
					   Vec xj, Vec yj, Vec gj,
					   double sigma, int nsigma_box,
					   int sigma_buffer, int sigma_trunc) ;

#endif /*__LIBPETRBF_H_INCLUDED__*/
