# $NetBSD: Makefile,v 1.81 2020/08/19 20:05:44 nia Exp $

DISTNAME=	libsndfile-1.0.29
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=erikd/}
GITHUB_PROJECT=	libsndfile
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mega-nerd.com/libsndfile/
COMMENT=	Library for reading and writing audio files
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	autogen-[0-9]*:../../devel/autogen

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	tool

TEST_TARGET=		check

.include "options.mk"

OPSYSVARS+=		BUILDLINK_PASSTHRU_DIRS

BUILDLINK_PASSTHRU_DIRS.Darwin+=	/Developer

.if !empty(PKGSRC_COMPILER:Msunpro)
CXXFLAGS+=		-features=extensions
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1.3
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
