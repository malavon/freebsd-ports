PORTNAME=	fluidsynth-dssi
PORTVERSION=	1.0.0
PORTREVISION=	18
CATEGORIES=	audio
MASTER_SITES=	SF/dssi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper for FluidSynth allowing it to function as a DSSI plugin
WWW=		http://dssi.sourceforge.net/

LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libfluidsynth.so:audio/fluidsynth \
		libjack.so:audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:audio/dssi

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool pkgconfig
USE_GNOME=	gtk20

.include <bsd.port.mk>
