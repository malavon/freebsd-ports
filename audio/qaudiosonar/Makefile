PORTNAME=	qaudiosonar
DISTVERSIONPREFIX=	v
DISTVERSION=		1.8.3
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Quick Audio Sonar
WWW=		https://github.com/hselasky/qaudiosonar

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools:build core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES= \
	bin/qaudiosonar \
	share/pixmaps/qaudiosonar.png \
	share/applications/qaudiosonar.desktop

.include <bsd.port.mk>
