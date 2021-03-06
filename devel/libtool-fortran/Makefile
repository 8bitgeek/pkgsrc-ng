# $NetBSD: Makefile,v 1.9 2014/02/26 10:40:46 jperkin Exp $

###########################################################################
###########################################################################
#
# HEADS UP!  DO NOT CHANGE THE VERSION OR PKGREVISION WITHOUT READING THIS:
#
###########################################################################
###########################################################################
#
# This package is maintained specially in order to preserve pkgsrc
# specific OS changes that diverge from the "out of the box" libtool.
# In order to keep this package in a maintainable condition, the .m4 files
# must be manipulated in order to generate the patch-* files.
#
# See devel/libtool/patches/manual.README for instructions on how to make
# these patch files properly; otherwise your changes WILL be lost on the
# next libtool update.
#
# DO NOT MAKE CHANGES TO patch-ab OR patch-ad WITHOUT FOLLOWING THESE
# INSTRUCTIONS.  There are no exceptions to this rule.
#
###########################################################################
###########################################################################

.include "../../devel/libtool/Makefile.common"

FILESDIR=	${.CURDIR}/../libtool-base/files

PKGNAME=	${DISTNAME:S/-/-fortran-/}
PKGREVISION=	4
SVR4_PKGNAME=	ltoof

COMMENT=	Generic shared library support script (the script itself, incl. Fortran)

CONFLICTS+=	libtool<=1.3.5nb11

TEST_TARGET=	check

OVERRIDE_DIRDEPTH.install-sh=	1

.if ${OPSYS} == "AIX"

# always build libraries and executables that use the runtime linker.
# in addition, disable libtool locking, as the test is broken on AIX,
# and results in files being locked indefinitely.
LDFLAGS+=		-Wl,-brtl
CONFIGURE_ARGS+=	--disable-libtool-lock

.elif ${OPSYS} == "IRIX"

# The MIPSpro compiler doesn't support -c with -o, but the locking
# workaround is itself broken.  Disable it unconditionally.
CONFIGURE_ARGS+=	--disable-libtool-lock

.elif ${OPSYS} == "SunOS"
CFLAGS+=	${_COMPILER_ABI_FLAG.${ABI}}
.endif

# We are going to want libtool to find the same versions of the C, C++,
# and Fortran compilers.
#
USE_LANGUAGES=		c c++ fortran
CONFIGURE_ARGS+=	--disable-ltdl-install

USE_TOOLS+=		echo

INSTALLATION_DIRS+=	bin

.PHONY: fix-libtool
fix-libtool:
	cd ${WRKSRC}; for f in libtool; do				\
		${SED}	-e "s,-L${BUILDLINK_DIR}/lib *,,"		\
			-e "s,${BUILDLINK_DIR}/lib *,,"			\
			$$f > $$f.new;					\
		if [ -x $$f ]; then ${CHMOD} +x $$f.new; fi;		\
		${MV} -f $$f.new $$f;					\
	done

post-build: fix-libtool

post-build:
	@${SED}	-e "s|@PREFIX@|"${PREFIX:Q}"|g"				\
		-e "s|@SH@|"${SH:Q}"|g"					\
		${FILESDIR}/shlibtool-fortran.in > ${WRKSRC}/shlibtool-fortran

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shlibtool-fortran ${DESTDIR}${PREFIX}/bin/shlibtool-fortran
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${DESTDIR}${PREFIX}/bin/libtool-fortran

BUILDLINK_DEPMETHOD.dlcompat=	build

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
