PORTNAME=	aws-checksums
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.14
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Cross-Platform HW accelerated CRC32c and CRC32
WWW=		https://github.com/awslabs/aws-checksums

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libaws-c-common.so:devel/aws-c-common

USES=		cmake:testing

USE_GITHUB=	yes
GH_ACCOUNT=	awslabs

USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=${LOCALBASE}/lib
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTING

.include <bsd.port.pre.mk>

# clang is crashing on CURRENT due an assertion
# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234232
# and https://bugs.llvm.org/show_bug.cgi?id=40985
.if ${OSVERSION} >= 1400000
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
