# $NetBSD: Makefile,v 1.3 2020/08/24 08:02:33 wiz Exp $

VERSION=	2020.8.13
DISTNAME=	https-everywhere-${VERSION}-eff
PKGNAME=	tor-browser-${DISTNAME:S/-eff//}
CATEGORIES=	security www
MASTER_SITES=	https://www.eff.org/files/
EXTRACT_SUFX=	.xpi

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.eff.org/https-everywhere
COMMENT=	HTTPS Everywhere plugin for tor-browser
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	lib/tor-browser/distribution/extensions

do-build:

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/lib/tor-browser/distribution/extensions/https-everywhere-eff@eff.org.xpi

.include "../../mk/bsd.pkg.mk"
