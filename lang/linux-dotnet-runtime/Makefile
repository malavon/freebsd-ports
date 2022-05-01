# Created by: David Naylor <dbn@FreeBSD.org>

PORTNAME?=	dotnet-runtime
DISTVERSION?=	6.0.4
DISTVERSIONSUFFIX=	-linux-x64
CATEGORIES=	lang
MASTER_SITES?=	https://download.visualstudio.microsoft.com/download/pr/5b08d331-15ac-4a53-82a5-522fa45b1b99/65ae300dd160ae0b88b91dd78834ce3e/

PKGNAMEPREFIX=	linux-

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Cross-platform .NET implementation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

.if ${PORTNAME} != dotnet-cli
RUN_DEPENDS=	dotnet:lang/linux-dotnet-cli
.endif

USES=		linux:c7
USE_LINUX?=	curl icu libunwind lttng-ust openssl

DATADIR=	${PREFIX}/share/dotnet
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SLAVEDIR=	${.CURDIR}
DISTINFO_FILE?=	${SLAVEDIR}/distinfo
PLIST=		${SLAVEDIR}/pkg-plist
PLIST_SUB=	VERSION=${DISTVERSION}

BINFILES?=	shared/Microsoft.NETCore.App/${DISTVERSION}/createdump

.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/dotnet ${STAGEDIR}${DATADIR}/LICENSE.txt ${STAGEDIR}${DATADIR}/ThirdPartyNotices.txt
.for bin in ${BINFILES}
	${RM} ${STAGEDIR}${DATADIR}/${bin}
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${STAGEDIR}${DATADIR}/${bin}
.endfor
.endif

.include <bsd.port.mk>
