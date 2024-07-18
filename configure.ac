AC_INIT([petrbf],[1.0.0])
AC_CONFIG_SRCDIR([src/libpetrbf.h])
AM_INIT_AUTOMAKE([subdir-objects])

PETRBF_MAJOR_VERSION=1
PETRBF_MINOR_VERSION=0
PETRBF_MICRO_VERSION=0
PETRBF_INTERFACE_AGE=0
PETRBF_BINARY_AGE=0
PETRBF_VERSION=$PETRBF_MAJOR_VERSION.$PETRBF_MINOR_VERSION.$PETRBF_MICRO_VERSION

AC_SUBST(PETRBF_MAJOR_VERSION)
AC_SUBST(PETRBF_MINOR_VERSION)
AC_SUBST(PETRBF_MICRO_VERSION)
AC_SUBST(PETRBF_VERSION)

# libtool versioning
LT_RELEASE=$PETRBF_MAJOR_VERSION.$PETRBF_MINOR_VERSION
LT_CURRENT=`expr $PETRBF_MICRO_VERSION - $PETRBF_INTERFACE_AGE`
LT_REVISION=$PETRBF_INTERFACE_AGE
LT_AGE=`expr $PETRBF_BINARY_AGE - $PETRBF_INTERFACE_AGE`
AC_SUBST(LT_RELEASE)
AC_SUBST(LT_CURRENT)
AC_SUBST(LT_REVISION)
AC_SUBST(LT_AGE)

# For automake.
VERSION=$PETRBF_VERSION
PACKAGE=libpetrbf

AC_SUBST(PACKAGE)
AC_SUBST(VERSION)

# Specify a configuration file
AC_CONFIG_HEADERS(config.h)

AC_DEFINE_UNQUOTED(PETRBF_MAJOR_VERSION, $PETRBF_MAJOR_VERSION, [Major version])
AC_DEFINE_UNQUOTED(PETRBF_MINOR_VERSION, $PETRBF_MINOR_VERSION, [Minor version])
AC_DEFINE_UNQUOTED(PETRBF_MICRO_VERSION, $PETRBF_MICRO_VERSION, [Micro version])
AC_DEFINE_UNQUOTED(PETRBF_INTERFACE_AGE, $PETRBF_INTERFACE_AGE, [Interface age])
AC_DEFINE_UNQUOTED(PETRBF_BINARY_AGE, $PETRBF_BINARY_AGE, [Binary age])

dnl Initialize libtool
LT_INIT

#AC_PROG_CC
#AM_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_CXX_C_O

if test x$GXX = xyes ; then
  CFLAGS="$CFLAGS -Wall -Werror-implicit-function-declaration -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations"
fi

AC_PROG_AWK
AC_SEARCH_LIBS([strerror],[cposix])

PKG_CHECK_MODULES([PETSC], [petsc >= 3.17],
		  AC_DEFINE([HAVE_PETSC], [1], [Have PETSc]),
		  [
  echo \#################################################################
  echo \# 
  echo \# PETSc solver library \>= 3.17 not found, exiting
  echo \#
  echo \# You can get PETSc from
  echo \#
  echo \# https://www.petsc.org/
  echo \#
  echo \#################################################################
  exit 
]
)

AX_GCC_X86_CPU_SUPPORTS(avx, hasavx=yes) 
AX_GCC_X86_CPU_SUPPORTS(avx2, hasavx2=yes) 
AX_GCC_X86_CPU_SUPPORTS(fma, hasfma=yes) 

if test x$hasavx = xyes; then
 SIMD_FLAGS="$SIMD_FLAGS -mavx -DWBFMM_USE_AVX"
fi
if test x$hasfma = xyes; then
 SIMD_FLAGS="$SIMD_FLAGS -mfma -DWBFMM_USE_AVX"
fi

AC_CHECK_LIB(m, cos)
AC_CONFIG_MACRO_DIR([m4])

AC_OPENMP
AC_PROG_F77
AC_F77_LIBRARY_LDFLAGS
AC_F77_DUMMY_MAIN
AC_F77_WRAPPERS

CFLAGS="$CFLAGS $OPENMP_CFLAGS $SIMD_FLAGS $PETSC_CFLAGS"
LIBS="$GLIB_LIBS $LIBS $PETSC_LIBS"

AC_SUBST(CFLAGS)
AC_SUBST(LIBS)
AC_SUBST(LDFLAGS)

AC_CONFIG_FILES([
Makefile
src/Makefile
])
#tools/Makefile
#doc/Makefile
#doc/html/Makefile])

AC_OUTPUT

