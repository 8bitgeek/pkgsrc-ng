# $NetBSD: Makefile,v 1.8 2014/03/17 17:02:55 richard Exp $

DISTNAME=	libnice-0.1.5
PKGNAME=	gst-plugins1-${DISTNAME}
CATEGORIES=	net devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nice.freedesktop.org/wiki/
COMMENT=	IETF's Interactive Connectivity Establishment standard implementation
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1

PATCHDIR=	${.CURDIR}/../../net/libnice/patches
DISTINFO_FILE=	${.CURDIR}/../../net/libnice/distinfo

CONFLICTS+=	libnice<0.0.13

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+= --with-gstreamer

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_LANGUAGES+= c99
.endif

BUILD_DIRS=	gst
INSTALL_DIRS=	gst

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wunused-but-set-variable
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
