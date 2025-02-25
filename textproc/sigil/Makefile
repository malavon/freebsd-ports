PORTNAME=	sigil
PORTVERSION=	1.9.30
CATEGORIES=	textproc

MAINTAINER=	jonc@chen.org.nz
COMMENT=	WYSIWYG ePub editor
WWW=		https://sigil-ebook.com/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libhunspell-1.7.so:textproc/hunspell
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>=0.15.0:devel/py-dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

USES=		cmake cpe desktop-file-utils \
		minizip pkgconfig python:3.4+ qt:5 shebangfix
CPE_VENDOR=	${PORTNAME}-ebook

USE_GITHUB=	yes
GH_ACCOUNT=	Sigil-Ebook
GH_PROJECT=	Sigil

USE_LDCONFIG=	${PREFIX}/lib/sigil

USE_QT=		concurrent core declarative gui location network printsupport \
		svg webchannel webengine widgets xml xmlpatterns \
		buildtools:build linguisttools:build qmake:build \
		imageformats:run

SHEBANG_FILES=	src/Resource_Files/plugin_launchers/python/*.py \
		src/Resource_Files/python3lib/*.py

CMAKE_ARGS=	-DUSE_SYSTEM_LIBS:BOOL=1

# Upstream uses pkg-config output to pass libhunspell-1.7.so and
# libpcre16.so to the linker. pkg-config output does not include full
# paths, so add a workaround to keep the port linking for now.
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/sigil/*.so

.include <bsd.port.mk>
