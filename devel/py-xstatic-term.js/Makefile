PORTNAME=	xstatic-term.js
PORTVERSION=	0.0.7.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XStatic-term.js-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	term.js (XStatic packaging standard)
WWW=		https://github.com/chjj/term.js

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xstatic>=0:devel/py-xstatic@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
