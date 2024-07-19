## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/src -I$(includedir)
LDADD = $(top_builddir)/src/.libs/libpetrbf.a 

DEPS = $(top_builddir)/src/libpetrbf.la

bin_PROGRAMS = \
	cylinder \
	test-3d

cylinder_SOURCES = cylinder.cxx
test_3d_SOURCES = test-3d.cxx
