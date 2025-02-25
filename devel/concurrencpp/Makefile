PORTNAME=	concurrencpp
DISTVERSIONPREFIX=	v.
DISTVERSION=	0.1.6
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ concurrency library: tasks, executors, timers, C++20 coroutines
WWW=		https://github.com/David-Haim/concurrencpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++20-lang

USE_GITHUB=	yes
GH_ACCOUNT=	David-Haim

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.options.mk>

.if (${ARCH} == powerpc64le || ${ARCH} == powerpc64 || ${ARCH} == powerpc) && ${OSVERSION} < 1300523
BUILD_DEPENDS=	llvm13>0:devel/llvm13
CPP=		${LOCALBASE}/bin/clang-cpp13
CC=		${LOCALBASE}/bin/clang13
CXX=		${LOCALBASE}/bin/clang++13
.endif

do-test: # same as recommended in https://github.com/David-Haim/concurrencpp#building-installing-and-testing
	# test async_lock_tests never finishes, see https://github.com/David-Haim/concurrencpp/issues/85
	@cd ${WRKSRC} && \
		${CMAKE_BIN} -S test -B build/test && \
		${CMAKE_BIN} --build build/test && \
		cd build/test && ctest .

.include <bsd.port.mk>
