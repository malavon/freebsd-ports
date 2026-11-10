PORTNAME=	smuview
DISTVERSION=	0.x
CATEGORIES=	science

MAINTAINER=	TODO@bla.com
COMMENT=	
WWW=		

LICENSE=	GPLv3

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libpython3.12.so:lang/python312 \
		libsigrokcxx.so:devel/libsigrok-devel \
		libqwt.so:x11-toolkits/qwt6@qt6

USES=		cmake compiler:c++11-lang gettext-runtime gnome gl qt:6

USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf glibmm glib20 gtk30 libsigc++20
USE_GL+=	gl opengl
# USE_QT=		core gui svg widgets
USE_QT=		base svg

GH_ACCOUNT=	knarfS
GH_PROJECT=	smuview
GH_TAGNAME=	117ba6c8604076e5831b4265e5bf0f54f353b245

.include <bsd.port.options.mk>

.include <bsd.port.mk>
