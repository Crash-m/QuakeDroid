#
# $Id: Makefile.am,v 1.47 2007-11-17 10:22:45 bagder Exp $
#

AUTOMAKE_OPTIONS = foreign nostdinc

EXTRA_DIST = README Makefile.example makefile.dj $(COMPLICATED_EXAMPLES)

INCLUDES = -I$(top_srcdir)/include

LIBDIR = $(top_builddir)/lib

if STATICLIB
# we need this define when building with a static lib on Windows
STATICCPPFLAGS = -DCURL_STATICLIB
endif

CPPFLAGS = -DCURL_NO_OLDIES $(STATICCPPFLAGS)

# Dependencies
LDADD = $(LIBDIR)/libcurl.la

# These are all libcurl example programs to be test compiled
noinst_PROGRAMS = 10-at-a-time anyauthput cookie_interface \
  debug fileupload fopen ftpget ftpgetresp ftpupload \
  getinfo getinmemory http-post httpput \
  https multi-app multi-debugcallback multi-double \
  multi-post multi-single persistant post-callback \
  postit2 sepheaders simple simplepost simplessl

# These examples require external dependencies that may not be commonly
# available on POSIX systems, so don't bother attempting to compile them here.
COMPLICATED_EXAMPLES = \
 curlgtk.c curlx.c htmltitle.cc cacertinmem.c ftpuploadresume.c \
 ghiper.c hiperfifo.c htmltidy.c multithread.c \
 opensslthreadlock.c sampleconv.c synctime.c

