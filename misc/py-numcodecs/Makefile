PORTNAME=	numcodecs
DISTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package providing buffer compression and transformation codecs for use
WWW=		https://numcodecs.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}py-cpuinfo>0:sysutils/py-py-cpuinfo@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}entrypoints>0:devel/py-entrypoints@${PY_FLAVOR} \
		${PYNUMPY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zfp>0:devel/py-zfp@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist pytest # tests fail to find the library in the staged directory for some reason

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/numcodecs/tests

OPTIONS_DEFINE=		AVX2

AVX2_DESC=		Use AVX2 SIMD instructions
AVX2_CONFIGURE_ENV_OFF=	DISABLE_NUMCODECS_AVX2=yes
AVX2_MAKE_ENV_OFF=	DISABLE_NUMCODECS_AVX2=yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/numcodecs/*${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
