# $FreeBSD$

PORTNAME=	restclient-cpp
PORTVERSION=	0.5.1
PORTREVISION=	0
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	devel

MAINTAINER=	@FreeBSD.org
COMMENT=	

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang

LIB_DEPENDS=  	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	mrtazz
GH_PROJECT=	restclient-cpp
GH_TAGNAME=	${PORTVERSION}

.include <bsd.port.mk>
