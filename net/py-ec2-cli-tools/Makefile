PORTNAME=	ec2-cli-tools
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Helpful CLI utilities for querying and connecting to EC2 instances
WWW=		https://github.com/FlipPath/ec2-cli-tools

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>=1.0:devel/py-boto@${PY_FLAVOR} \
		bash:shells/bash

USE_PYTHON=	distutils autoplist
USES=		python:3.6+ shebangfix
SHEBANG_FILES=	bin/ec2getsnaps bin/ec2hostcache bin/ec2ssh

.include <bsd.port.mk>
