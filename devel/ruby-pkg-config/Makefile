# $NetBSD: Makefile,v 1.28 2020/09/13 15:58:56 taca Exp $

DISTNAME=	pkg-config-1.4.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-gnome/pkg-config
COMMENT=	Pure Ruby implementation of pkg-config
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	${RUBY_PKGPREFIX}-gnome2-glib<0.90.0

USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

#do-test:
#		cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
