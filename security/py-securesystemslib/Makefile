PORTNAME=	securesystemslib
PORTVERSION=	0.27.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Cryptographic and general-purpose routines
WWW=		https://github.com/secure-systems-lab/securesystemslib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=3.3.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>1.2.0:security/py-pynacl@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/bin/gpg:security/gnupg

USES=		python:3.7+ pytest shebangfix
USE_PYTHON=	autoplist pep517
PYTEST_ARGS=	tests

SHEBANG_FILES=	securesystemslib/settings.py \
	securesystemslib/schema.py \
	securesystemslib/_vendor/test-ed25519-upstream.sh \
	securesystemslib/keys.py \
	securesystemslib/rsa_keys.py \
	securesystemslib/hash.py \
	securesystemslib/formats.py

NO_ARCH=	yes

.include <bsd.port.mk>
