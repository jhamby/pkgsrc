# $NetBSD: Makefile,v 1.41 2020/08/31 18:13:25 wiz Exp $

DISTNAME=	qtwebchannel-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtwebchannel-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 WebChannel module

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5WebChannel.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
