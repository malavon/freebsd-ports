PORTNAME=	rgbpaint
PORTVERSION=	0.8.7
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	SF/mtpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very basic painting program
WWW=		http://mtpaint.sourceforge.net/rgbpaint.html

LICENSE=	GPLv2+

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: brcosa_pal
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: brcosa_pal

USES=		gettext gnome pkgconfig tar:bzip2
USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--locale=${PREFIX}/share/locale cflags slow intl man

DESKTOP_ENTRIES="rgbPaint" "" "" "${PORTNAME}" "" true

post-patch:
	@${REINPLACE_CMD} '/if \[/s|==|=|g ; \
		 /gcc/s|^|#| ; \
		 /GTK_LIB/s| -s||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|$$(MT_MAN_DEST)|$$(DESTDIR)&|g' \
		${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} 's|$$(MT_LANG_DEST)|$$(DESTDIR)&|g' \
		${WRKSRC}/po/Makefile
	@${REINPLACE_CMD} 's|$$(BIN_INSTALL)|$$(DESTDIR)&|g ; \
		 /^LDFLAGS/s|$$| -lX11 -lm -lintl|' \
		${WRKSRC}/src/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rgbpaint

.include <bsd.port.mk>
