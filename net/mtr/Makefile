# $NetBSD: Makefile,v 1.114 2020/08/17 20:19:49 leot Exp $

DISTNAME=	mtr-0.93
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/

PATCH_SITES=		https://github.com/traviscross/mtr/commit/
PATCH_DIST_STRIP=	-p1
# For improved errors
PATCHFILES=		919422d1dee7d35a236035f190f491a4a2113772.patch
# Fix find_source_addr
PATCHFILES+=		9fe183d61f5382bd6dae1df1db6439a27e8edde2.patch

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitwizard.nl/mtr/
COMMENT=	Traceroute and ping in a single graphical network diagnostic tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	share/doc/mtr

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__=1

.include "options.mk"

SPECIAL_PERMS=	sbin/mtr-packet ${SETUID_ROOT_PERMS}

post-install:
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DESTDIR}${PREFIX}/share/doc/mtr

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
