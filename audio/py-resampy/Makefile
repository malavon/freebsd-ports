PORTNAME=	resampy
DISTVERSION=	0.4.2
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient signal resampling conversion in Python
WWW=		https://github.com/bmcfee/resampy

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numba>=0.53:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
