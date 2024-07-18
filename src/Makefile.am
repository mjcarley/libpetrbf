AM_CPPFLAGS = -I$(top_srcdir) -I$(includedir) -DG_LOG_DOMAIN=\"PETRBF\"

lib_LTLIBRARIES = libpetrbf.la

libpetrbf_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)\
	-release $(LT_RELEASE) -export-dynamic

libpetrbf_la_SOURCES = \
	mpi_range_2d.cxx \
	get_buffer_2d.h \
	get_trunc_2d.h \
	get_cluster_2d.h \
	get_vorticity_2d.h \
	par_2d.h \
	matmult_2d.cxx \
	rbf_interpolation_2d.cxx \
	vorticity_evaluation_2d.cxx


#libpetrbf.c \
#	kernel.c \
#	gtrbf.h \
#	gtrbf.c

include_HEADERS = \
	libpetrbf.h

CLEANFILES = $(BUILT_SOURCES)
