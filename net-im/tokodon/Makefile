PORTNAME=	tokodon
DISTVERSION=	23.02.0
CATEGORIES=	net-im kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE mastodon client
WWW=		https://apps.kde.org/tokodon/

LICENSE=	GPLv3

BUILD_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons
LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5
RUN_DEPENDS=	kirigami-addons>=0.6.1:x11-toolkits/kirigami-addons

USES=		cmake desktop-file-utils gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n jobwidgets kio kirigami2 notifications \
		qqc2-desktop-style service solid widgetsaddons windowsystem \
		itemmodels:run
USE_QT=		concurrent core dbus declarative gui multimedia network \
		quickcontrols2 websockets widgets xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

.include <bsd.port.mk>
