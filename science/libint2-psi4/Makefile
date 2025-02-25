PORTNAME=	libint2-psi4
DISTVERSION=	0.1
CATEGORIES=	science
MASTER_SITES=	https://github.com/loriab/libint/releases/download/v${DISTVERSION}/
DISTFILES=	Libint2-export-5-4-3-6-5-4_mm4f12ob2.tgz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory (psi4)
WWW=		https://github.com/evaleev/libint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libgmpxx.so:math/gmp

USES=		cmake:testing eigen:3 python:build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libint-2.7.1

CMAKE_ARGS=	-DLIBINT2_SHGAUSS_ORDERING=gaussian \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_ON=	BUILD_SHARED_LIBS \
		REQUIRE_CXX_API
CMAKE_OFF=	ENABLE_FORTRAN \
		REQUIRE_CXX_API_COMPILED

CONFLICTS=	libint2

post-configure: # workaround for clang hanging on unity_1935_cxx.cxx, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265809
	@cd ${BUILD_WRKSRC} && \
		${SED} -e 's|%%BUILD_WRKSRC%%|${BUILD_WRKSRC}|g ; s|%%WRKDIR%%|${WRKDIR}|g' < ${FILESDIR}/build.patch | tee p | ${PATCH}

.include <bsd.port.mk>
