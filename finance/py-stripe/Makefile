# $NetBSD: Makefile,v 1.29 2020/09/08 17:44:37 adam Exp $

DISTNAME=	stripe-2.51.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stripe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stripe.com/
COMMENT=	Stripe python bindings
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
# tests require stripe-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=1.7:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.22:../../devel/py-test-xdist

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
