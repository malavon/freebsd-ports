PORTNAME=	gtick
PORTVERSION=	0.5.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.antcom.de/gtick/download/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Metronome application
WWW=		https://www.antcom.de/gtick/

LICENSE=	GPLv3

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libsndfile.so:audio/libsndfile \
		libpulse-simple.so:audio/pulseaudio

USES=		desktop-file-utils gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gtk20
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

.include <bsd.port.mk>
