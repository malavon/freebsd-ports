PORTNAME=	UEFITool-legacy
PORTVERSION=	0.28.0
CATEGORIES=	sysutils

MAINTAINER=	TEMP@FreeBSD.org
COMMENT=	UEFI images parser
WWW=		https://github.com/LongSoft/UEFITool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

# BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++11-lang qt:6
USE_GITHUB=	yes
USE_GL=		gl opengl
USE_QT=		base

GH_ACCOUNT=	LongSoft
GH_PROJECT=	UEFITool

CONFLICTS_INSTALL=	sysutils/UEFITool

.include <bsd.port.mk>
