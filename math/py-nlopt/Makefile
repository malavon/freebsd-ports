PORTNAME=	nlopt
DISTVERSION=	2.7.1
CATEGORIES=	math
#MASTER_SITES=	PYPI # https://github.com/DanielBok/nlopt-python/issues/15
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Nonlinear optimization library
WWW=		https://github.com/DanielBok/nlopt-python

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		swig:devel/swig \
		${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils # autoplist is broken, see https://github.com/DanielBok/nlopt-python/issues/17

USE_GITHUB=	yes
GH_ACCOUNT=	DanielBok
GH_PROJECT=	nlopt-python
GH_TUPLE=	stevengj:nlopt:4a0e93c:nlopt/extern/nlopt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/nlopt/_nlopt.so

do-test:
	@${SETENV} ${TEST_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
