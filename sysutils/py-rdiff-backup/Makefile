PORTNAME=	rdiff-backup
DISTVERSION=	2.2.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Easy to use and efficient backup and restore utility
WWW=		https://rdiff-backup.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
LIB_DEPENDS=	librsync.so:net/librsync
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		localbase:ldflags python:3.5+
USE_LDCONFIG=	yes
USE_PYTHON=	autoplist concurrent distutils

CONFLICTS=	rdiff-backup-devel rdiff-backup-1.0*

PORTSCOUT=	limitw:1,even

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rdiff_backup/_librsync*.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/rdiff_backup/C*.so

do-test:
	cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m tox

.include <bsd.port.mk>
