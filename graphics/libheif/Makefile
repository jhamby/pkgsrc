# $NetBSD: Makefile,v 1.3 2020/09/03 19:07:59 otis Exp $

DISTNAME=	libheif-1.8.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_PROJECT=	libheif
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libheif/
COMMENT=	HEIF and AVIF file format decoder and encoder library
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libheif.pc.in

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
