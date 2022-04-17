PORTNAME=	msbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	17.1.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mono/msbuild/releases/download/v16.9.0/:bootstrap
DISTFILES=	mono_msbuild_xplat-master-d094b49.zip:bootstrap

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Build platform for .NET and Visual Studio
WWW=		https://github.com/Microsoft/msbuild

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

NUGET_FEEDS=	DOTNET_CORE NUGET ROSLYN ROSLYN_TOOLS SYMREADER_CONVERTER
NUGET_LAYOUT=	dotnet

USES=		mono:nuget shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_TAGNAME=	v16.9.0
SHEBANG_FILES=	*.sh artifacts/mono-msbuild/msbuild build.sh build/*.sh

MAKE_ENV=	GIT_COMMIT=d094b49f5b5095efe15685431275b9c38fa6d845
MAKE_JOBS_UNSAFE=MSBuild has not implemented concurrent builds on non Windows platforms
ALL_TARGET=	all-mono
TEST_TARGET=	test-mono

post-extract:
	${MKDIR} ${WRKSRC}/artifacts
	${MV} ${WRKDIR}/msbuild ${WRKSRC}/artifacts/mono-msbuild

do-build:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ./build/build.sh -host mono -configuration Release -skipTests build)

do-install:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} DESTDIR=${STAGEDIR} PATH=${WRKSRC}/artifacts/mono-msbuild:$$PATH ./install-mono-prefix.sh ${PREFIX})

do-test:
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ./build/build.sh -host mono -configuration Release build)

.include <bsd.port.mk>
