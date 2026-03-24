PORTNAME=	msp430flasher
DISTVERSION=	1.03.20.00
CATEGORIES=	devel

MAINTAINER=	ports@malavon.eu
COMMENT=	Flasher for the MSP430/MSP432 family made by Texas Instruments
WWW=		https://www.ti.com/tool/download/MSP430-FLASHER

LIB_DEPENDS=	libmsp430.so:devel/msp430-debug-stack

USES=		compiler:c++11-lib dos2unix

USE_GITHUB=	yes
GH_ACCOUNT=	malavon
GH_PROJECT=	ti-msp430flasher

WRKSRC_SUBDIR=	Source
SUB_FILES=	mspflasher

LDFLAGS+=	-L${LOCALBASE}/lib -lmsp430

PLIST_FILES=	bin/MSP430Flasher \
		bin/mspflasher

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../MSP430Flasher ${STAGEDIR}${PREFIX}/bin/MSP430Flasher
	${INSTALL_SCRIPT} ${WRKDIR}/mspflasher ${STAGEDIR}${PREFIX}/bin/mspflasher

.include <bsd.port.mk>
