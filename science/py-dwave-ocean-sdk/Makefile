PORTNAME=	dwave-ocean-sdk
DISTVERSION=	6.2.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Meta-package for D-Wave's Ocean tools
WWW=		https://docs.ocean.dwavesys.com/en/stable/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dimod>=0.12.3:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-cloud-client>=0.10.4:science/py-dwave-cloud-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-greedy>=0.3.0:science/py-dwave-greedy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-hybrid>=0.6.10:science/py-dwave-hybrid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-inspector>=0.4.0:science/py-dwave-inspector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-neal>=0.6.0:science/py-dwave-neal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-networkx>=0.8.13:science/py-dwave-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-preprocessing>=0.5.4:science/py-dwave-preprocessing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-samplers>=1.0.0:science/py-dwave-samplers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-system>=1.18.0:science/py-dwave-system@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-tabu>=0.5.0:science/py-dwave-tabu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwavebinarycsp>=0.2.0:science/py-dwavebinarycsp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}minorminer>=0.2.10:math/py-minorminer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}penaltymodel>=1.0.2:science/py-penaltymodel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqubo>=1.4.0:science/py-pyqubo@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	dwavesystems

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
