PORTNAME=	img2pdf
DISTVERSION=	0.4.4
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Convert images to PDF via direct JPEG inclusion
WWW=		https://gitlab.mister-muffin.de/josch/img2pdf

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pikepdf>0:textproc/py-pikepdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	${PY_NUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		convert:graphics/ImageMagick6 \
		exiftool:graphics/p5-Image-ExifTool \
		jpegtopnm:graphics/netpbm \
		pdftocairo:graphics/poppler-utils

USES=		python:3.5+ shebangfix
USE_PYTHON=	autoplist concurrent distutils pytest
# Some tests fail, see following link for more info:
# https://gitlab.mister-muffin.de/josch/img2pdf/issues/152
PYTEST_BROKEN_TESTS=	jpg_cmyk tiff_cmyk8
SHEBANG_FILES=	src/img2pdf.py

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI

GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

.include <bsd.port.mk>
