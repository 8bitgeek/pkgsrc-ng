# $NetBSD: Makefile,v 1.22 2013/05/31 12:41:35 wiz Exp $
#

DISTNAME=	DNS-ZoneParse-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5dzp
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DNS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DNS-ZoneParse/
COMMENT=	Perl5 module for parsing DNS zone files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/DNS/ZoneParse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
