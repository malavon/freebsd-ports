PORTNAME=	lumina-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
PORTREVISION=	5
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lumina Desktop Environment
WWW=		https://lumina-desktop.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../../LICENSE

RUN_DEPENDS=	fluxbox>=0:x11-wm/fluxbox \
		fluxbox-tenr-styles-pack>=0:x11-themes/fluxbox-tenr-styles-pack \
		xbrightness>=0:x11/xbrightness \
		compton>=0:x11-wm/compton \
		xrandr>=0:x11/xrandr \
		numlockx>=0:x11/numlockx \
		${LOCALBASE}/share/icons/La-Capitaine/index.theme:x11-themes/la-capitaine-icon-theme
LIB_DEPENDS+=	libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-util.so:x11/xcb-util \
		libXcursor.so:x11/libXcursor

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5 xorg
USE_GL=		gl
USE_XORG=	x11 xdamage xcb
USE_LDCONFIG=	yes
USE_QT=		buildtools:build concurrent core dbus declarative gui \
		imageformats multimedia network svg widgets x11extras
USE_GITHUB=	yes
GH_ACCOUNT=	lumina-desktop
GH_PROJECT=	lumina

OPTIONS_DEFINE=		MULTIMEDIA TRUEOS NLS
OPTIONS_DEFAULT=	MULTIMEDIA
OPTIONS_SUB=		yes

MULTIMEDIA_DESC=	Install multimedia support backend (gstreamer)
TRUEOS_DESC=		Use the TrueOS system interface settings.

TRUEOS_QMAKE_ON=	DEFAULT_SETTINGS=TrueOS

MULTIMEDIA_USES=	gstreamer
MULTIMEDIA_USE=		GSTREAMER=core

NLS_USE=	QT=linguist:build
NLS_QMAKE_ON=	CONFIG+=WITH_I18N

WRKSRC_SUBDIR=	src-qt5/core

CONFIGURE_ENV+=	DESTDIR=${STAGEDIR}

CONFLICTS_INSTALL=	lumina-1.2.*

post-extract:
	@${RM} ${WRKSRC}/lumina-desktop*/extrafiles/screensavers/Warp*
	@${RM} ${WRKSRC}/lumina-desktop*/extrafiles/screensavers/*/Warp*

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/share -name "ecp.*" -delete

.include <bsd.port.mk>
