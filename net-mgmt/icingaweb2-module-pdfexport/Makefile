PORTNAME=	icingaweb2-module-pdfexport
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
PORTREVISION=	0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Icinga PDF Export
WWW=		https://github.com/Icinga/icingaweb2-module-pdfexport

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		chromium>0:www/chromium

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/google-chrome|${LOCALBASE}/bin/chrome|" \
		${WRKSRC}/library/Pdfexport/ProvidedHook/Pdfexport.php
do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
