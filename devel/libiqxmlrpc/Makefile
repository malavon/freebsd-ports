PORTNAME=	libiqxmlrpc
PORTVERSION=	0.13.5
PORTREVISION=	18
CATEGORIES=	devel net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free, object-oriented XML-RPC implementation written in C++
WWW=		https://libiqxmlrpc.wikidot.com/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

OPTIONS_DEFINE=	DOXYGEN DOCS

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_CMAKE_OFF=	-Dbuild_docs=off

USE_GNOME=	libxml2
USES=		cmake gnome ssl tar:bzip2
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' ${WRKSRC}/libiqxmlrpc/CMakeLists.txt
	${REINPLACE_CMD} -e 's,share/doc/libiqxmlrpc-$${Libiqxmlrpc_VERSION},${DOCSDIR_REL},' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
