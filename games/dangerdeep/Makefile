PORTNAME=	dangerdeep
PORTVERSION=	0.3.0
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/danger_from_the_deep-src/${PORTVERSION}:game \
		SF/${PORTNAME}/danger_from_the_deep-data/${PORTVERSION}:data
DISTFILES=	${DISTNAME}.tar.gz:game \
		${PORTNAME}-data-${DISTVERSIONPREFIX}${DISTVERSION}.zip:data
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@malavon.eu
COMMENT=	Open source World War II German submarine simulation

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libtinyxml.so:textproc/tinyxml

USES=		compiler:c++11-lang gl scons sdl
USE_GL=		gl glu
USE_SDL=	sdl mixer image net

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
MAKE_ARGS=	installbindir=${PREFIX}/bin installdatadir=${DATADIR}
MAKE_ENV=	X11BASE=${LOCALBASE}

PORTDOCS=	CREDITS README

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
MAKE_ARGS+=	usex86sse=-1	# disable MMX/SSE on the build cluster
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/dangerdeep|${DATADIR}|; \
		s|Linux|"Danger from the Deep"|' ${WRKSRC}/doc/man/dangerdeep.6
	@${REINPLACE_CMD} -e 's|/usr/X11BASE|${LOCALBASE}|g' \
	    ${WRKSRC}/SConstruct

do-install:
	@cd ${WRKSRC}/build/freebsd && \
		${INSTALL_PROGRAM} dangerdeep crosssection damagemodel oceantest \
			portal viewmodel ${STAGEDIR}${PREFIX}/bin

	cd ${WRKDIR}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man6
	${INSTALL_MAN} ${WRKSRC}/doc/man/dangerdeep.6 ${STAGEDIR}${PREFIX}/share/man/man6
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/man/man6/dangerdeep.6
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
