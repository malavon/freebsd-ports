PORTNAME=	ipinfo
DISTVERSIONPREFIX=	ipinfo-
DISTVERSION=	2.10.1
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Official Command Line Interface for the IPinfo API
WWW=		https://github.com/ipinfo/cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_PROJECT=	cli
GH_TUPLE=	golang:sys:v0.5.0:golang_sys \

GO_TARGET=	./ipinfo

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} ${WRKSRC}/vendor/modules.txt
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
