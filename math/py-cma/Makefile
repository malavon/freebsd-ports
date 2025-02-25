PORTNAME=	cma
PORTVERSION=	3.3.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CMA-ES for non-linear numerical optimization in Python
WWW=		https://github.com/CMA-ES/pycma

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/cma/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CONSTRAINED_SOLUTION_TRACKING PLOTTING
CONSTRAINED_SOLUTION_TRACKING_DESC=	Convergence tracking support
PLOTTING_DESC=	Plotting support

CONSTRAINED_SOLUTION_TRACKING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}moarchiving>=0:math/py-moarchiving@${PY_FLAVOR}
PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

.include <bsd.port.mk>
