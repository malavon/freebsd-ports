PORTNAME=	django-debug-toolbar
PORTVERSION=	3.7.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj40-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurable set of panels to display debug information
WWW=		https://github.com/jazzband/django-debug-toolbar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 4.0 ends April 2023, upgrade to the Django 4.1+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=	2023-05-20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django40>=3.2.4:www/py-django40@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.0:databases/py-sqlparse@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

.include <bsd.port.mk>
