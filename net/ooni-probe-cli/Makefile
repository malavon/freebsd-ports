PORTNAME=		ooni-probe-cli
DISTVERSIONPREFIX=	v
DISTVERSION=		3.15.3
PORTREVISION=	8
CATEGORIES=		net www benchmarks

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Next generation OONI Probe CLI
WWW=		https://ooni.org/about/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:1.18,modules

GO_MODULE=	github.com/ooni/probe-cli/v3
GO_TARGET=	./cmd/ooniprobe
GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static"'

PLIST_FILES=	bin/ooniprobe

.include <bsd.port.mk>
