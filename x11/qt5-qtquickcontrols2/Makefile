# $NetBSD: Makefile,v 1.26 2020/08/31 18:13:24 wiz Exp $

DISTNAME=	qtquickcontrols2-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols2-${QTVERSION}
PKGREVISION=	2
COMMENT=	Next generation user interface controls based on Qt Quick

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5QuickControls2.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
