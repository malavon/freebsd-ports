PORTNAME=	psutil
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	121

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Process utilities module for Python
WWW=		https://pypi.org/project/psutil/

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}psutil

PORTSCOUT=	limit:^1\.2\.

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
