PORTNAME=	icingaweb2-module-idoreports
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Host and service availability reports for Icinga
WWW=		https://github.com/Icinga/icingaweb2-module-idoreports

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		icingaweb2-module-reporting${PHP_PKGNAMESUFFIX}>=0.9:net-mgmt/icingaweb2-module-reporting@${PHP_FLAVOR}

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
