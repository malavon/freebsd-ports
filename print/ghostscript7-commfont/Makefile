PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	15
CATEGORIES=	print
MASTER_SITES=	# empty
PKGNAMESUFFIX=	7-commfont
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Common files for Ghostscript 7.x CJK font support

DEPRECATED=	Obsolete and unsupported upstream
EXPIRATION_DATE=2023-06-30

BUILD_DEPENDS=	${CMAPDIR}/ac15/cid2code.txt:print/adobe-cmaps
RUN_DEPENDS=	${CMAPDIR}/ac15/cid2code.txt:print/adobe-cmaps

NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message \
		Makefile template.cidfont template.ttcidfont template.font
SUB_LIST=	PORTVERSION="${PORTVERSION}" GS_RESDIR="${GS_RESDIR}"
PLIST_SUB=	GS_RESDIR="${GS_RESDIR}"
USES=		ghostscript:7,run
NO_ARCH=	yes

CONFLICTS_INSTALL= \
		ghostscript[789] \
		ghostscript[789]-nox11 \
		ghostscript9-agpl \
		ghostscript9-agpl-nox11

CMAPDIR?=	${LOCALBASE}/share/fonts/adobe-cmaps
GS_RESDIR?=	share/ghostscript/Resource

pre-build:
	@cd ${WRKDIR} && ${MV} Makefile template.* ${WRKSRC}

.include <bsd.port.mk>
