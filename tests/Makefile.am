## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/src -I$(includedir)
LDADD = $(top_builddir)/src/.libs/libpetrbf.a 

DEPS = $(top_builddir)/src/libpetrbf.la

bin_PROGRAMS = cylinder

cylinder_SOURCES = cylinder.cxx
