PORTNAME=	placekey
PORTVERSION=	0.0.12
CATEGORIES=	misc geography python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities for working with Placekeys
WWW=		https://github.com/Placekey/placekey-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backoff>=0:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h3>=0:graphics/py-h3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ratelimiter>=0:devel/py-ratelimiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Shapely>=0:devel/py-shapely@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
