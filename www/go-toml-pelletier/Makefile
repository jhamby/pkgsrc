# $NetBSD: Makefile,v 1.27 2020/09/03 07:29:34 bsiegert Exp $

DISTNAME=	go-toml-1.0.0
PKGNAME=	${DISTNAME:S/toml/toml-pelletier/}
PKGREVISION=	22
MASTER_SITES=	${MASTER_SITE_GITHUB:=pelletier/}
CATEGORIES=	www
GITHUB_PROJECT=	go-toml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pelletier/go-toml
COMMENT=	TOML parser for Golang with reflection
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/pelletier/go-toml

REPLACE_BASH+=	test.sh
USE_TOOLS+=	bash:run

.include "../../devel/go-buffruneio/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
