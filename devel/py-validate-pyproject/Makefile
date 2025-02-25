PORTNAME=	validate-pyproject
PORTVERSION=	0.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validation library and CLI tool for checking on pyproject.toml files using JSON schema
WWW=		https://github.com/abravalheri/validate-pyproject

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=46.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=5:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastjsonschema>=2.16.2<3_99:devel/py-fastjsonschema@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL
OPTIONS_DEFAULT=ALL
ALL_DESC=	All functions

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.4:devel/py-packaging@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2021.10.20:devel/py-trove-classifiers@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.if ${PORT_OPTIONS:MALL} && ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.2.1:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
