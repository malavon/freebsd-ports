PORTNAME=	libsigrok-devel
PORTVERSION=	0.x
# PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	TEMP@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, core library
WWW=		https://sigrok.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	doxygen:devel/doxygen
# libcheck.so:devel/check \
LIB_DEPENDS=	libftdi1.so:devel/libftdi1 \
		libhidapi.so:comms/hidapi \
		libnettle.so.8:security/nettle \
		libserialport.so:devel/libserialport \
		libvisa.so:devel/librevisa \
		libzip.so:archivers/libzip

USES=		autoreconf compiler:c11 gnome libtool pathfix pkgconfig python:build \
		shared-mime-info
USE_GITHUB=	yes
USE_GNOME=	glibmm
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	sigrokproject
GH_PROJECT=	libsigrok
GH_TAGNAME=	0bc2487778e660f4d3116729b6f4aee2b1996bb0

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
