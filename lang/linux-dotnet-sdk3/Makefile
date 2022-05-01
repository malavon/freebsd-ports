PORTNAME?=	dotnet-sdk
DISTVERSION?=	3.1.418
DISTVERSIONSUFFIX=	-linux-x64
CATEGORIES=	lang
MASTER_SITES?=	https://download.visualstudio.microsoft.com/download/pr/9be72f63-270d-4b1f-9725-4dab8973c69d/62681fb4630de36e15011fa543c90908/
PKGNAMEPREFIX=	linux-

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Cross-platform .NET implementation (Software Development Kit)
WWW=		https://www.microsoft.com/net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS?=	linux-dotnet-runtime>=3.1.24:lang/linux-dotnet-runtime

USES=		linux:c7 python:build

DATADIR=	${PREFIX}/share/dotnet
DESCR=		${.CURDIR}/../linux-dotnet-runtime/pkg-descr
EXTRACT_AFTER_ARGS=	--no-same-owner --no-same-permissions \
			--include LICENSE.txt --include sdk ${EXTRACT_EXTRA_ARGS}
# EXTRACT_EXTRA_ARGS?=	--include additionalDeps --include store
NO_WRKSUBDIR=	yes

SLAVEDIR=	${.CURDIR}
DISTINFO_FILE=	${SLAVEDIR}/distinfo
PLIST=		${SLAVEDIR}/pkg-plist
PLIST_SUB=	VERSION=${DISTVERSION}

BINFILES?=
SCRIPTFILES?=

do-build:
# 	${LOCALBASE}/bin/lzma d ${WRKSRC}/sdk/${DISTVERSION}/nuGetPackagesArchive.lzma \
# 		${WRKSRC}/sdk/${DISTVERSION}/nuGetPackagesArchive.zip
# 	${PYTHON_CMD} ${FILESDIR}/extract.py \
# 		${WRKSRC}/sdk/${DISTVERSION}/nuGetPackagesArchive.zip \
# 		${WRKSRC}/sdk/NuGetFallbackFolder
# 	${RM} ${WRKSRC}/sdk/${DISTVERSION}/nuGetPackagesArchive.lzma \
# 		${WRKSRC}/sdk/${DISTVERSION}/nuGetPackagesArchive.zip
# 	${TOUCH} ${WRKSRC}/sdk/NuGetFallbackFolder/${DISTVERSION}.dotnetSentinel

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.for bin in ${BINFILES}
	${RM} ${STAGEDIR}${DATADIR}/${bin}
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${STAGEDIR}${DATADIR}/${bin}
.endfor
.for bin in ${SCRIPTFILES}
	${RM} ${STAGEDIR}${DATADIR}/${bin}
	${INSTALL_SCRIPT} ${WRKSRC}/${bin} ${STAGEDIR}${DATADIR}/${bin}
.endfor
	${RM} ${STAGEDIR}${DATADIR}/LICENSE.txt

.include <bsd.port.mk>
