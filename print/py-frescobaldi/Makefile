PORTNAME=	frescobaldi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	print kde python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Music score editor for lilypond
WWW=		https://www.frescobaldi.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-ly>=0:print/py-python-ly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-poppler-qt5>=0:graphics/py-python-poppler-qt5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qpageview>=0:graphics/py-qpageview@${PY_FLAVOR}

USES=		desktop-file-utils gettext gmake pyqt:5 python:3.5+ qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	frescobaldi
USE_PYQT=	pyqt5 sip webengine
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

OPTIONS_DEFINE=	LILYPOND

LILYPOND_DESC=	Use unstable LilyPond (lilypond-devel)

LILYPOND_RUN_DEPENDS=		lilypond:print/lilypond-devel
LILYPOND_RUN_DEPENDS_OFF=	lilypond:print/lilypond

post-patch:
	@${REINPLACE_CMD} -e 's|'share/man/man1'|'man/man1'|' \
		${WRKSRC}/setup.py
post-build:
	(cd ${WRKSRC} && ${GMAKE} -C linux)

.include <bsd.port.mk>
