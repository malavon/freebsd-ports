PORTNAME=	h2o
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0-dev.20220519
CATEGORIES=	www
PKGNAMESUFFIX=	-devel

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Optimized HTTP/2 server including support for TLS 1.3 and HTTP/1.x
WWW=		https://github.com/h2o/h2o

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi

BROKEN_armv6=		fails to compile: asm_arm.inc:139:36: '.syntax divided' arm assembly not supported
BROKEN_armv7=		fails to compile: asm_arm.inc:139:36: '.syntax divided' arm assembly not supported
BROKEN_FreeBSD_12_powerpc64=	fails to link on powerpc64 elfv1: unrecognized option '-Wl,-rpath=/usr/local/lib/gcc6'

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake:noninja compiler:c11 cpe perl5 shebangfix ssl pkgconfig
CPE_VENDOR=	dena
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_TAGNAME=	cf59e67
CONFLICTS=	h2o

SHEBANG_FILES=	share/h2o/start_server

PORTDOCS=	README.md

SUB_FILES=	${PORTNAME} ${PORTNAME}.conf.sample
SUB_LIST+=	H2O_USER=${H2O_USER} \
		H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR}

PLIST_SUB=	H2O_USER=${H2O_USER} \
		H2O_GROUP=${H2O_GROUP} \
		H2O_LOGDIR=${H2O_LOGDIR}

H2O_USER?=	www
H2O_GROUP?=	www

H2O_LOGDIR=	/var/log/${PORTNAME}/

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		MRUBY DOCS
OPTIONS_DEFAULT=	MRUBY
OPTIONS_SUB=		yes
MRUBY_DESC=		Build with embedded mruby handler support

CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=OFF -DWITH_BUNDLED_SSL=OFF

MRUBY_CMAKE_BOOL=	WITH_MRUBY
MRUBY_USES=		bison ruby:build

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|exec perl|exec ${LOCALBASE}/bin/perl|' \
		${WRKSRC}/share/h2o/annotate-backtrace-symbols \
		${WRKSRC}/share/h2o/fastcgi-cgi \
		${WRKSRC}/share/h2o/fetch-ocsp-response \
		${WRKSRC}/share/h2o/kill-on-close \
		${WRKSRC}/share/h2o/setuidgid \
		${WRKSRC}/share/h2o/start_server

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${H2O_LOGDIR}
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
