AC_INIT([interp4cmds-2libs], [1.0], [jkowals@diablo.iiar.pwr.wroc.pl])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_PROG_AR()
LT_INIT
AC_LANG_CPLUSPLUS
AC_PROG_CXX
AC_LANG([C++])	


AC_PROG_LIBTOOL
#
# Tutaj sprawdzamy istnienie biblioteki
#
AC_CHECK_LIB([xerces-c], [_init], ,[AC_MSG_ERROR([libxerces-c not found])])
#
# Sprawdzanie, czy faktycznie jest potrzebna konsolidacja z biblioteka dl
#
gl_saved_libs=$LIBS
  AC_SEARCH_LIBS(dlopen, [dl],
		 [test "$ac_cv_search_dlopen" = "none required" ||
		  LIB_DLOPEN=$ac_cv_search_dlopen])
  AC_SUBST([LIB_DLOPEN])
LIBS=$gl_saved_libs

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 inc/Makefile
 src-lib/Makefile
])
AC_PROG_INSTALL
AC_OUTPUT
