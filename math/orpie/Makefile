PORTNAME=	orpie
PORTVERSION=	1.5.2
PORTREVISION=	7
CATEGORIES+=	math
MASTER_SITES=	GENTOO http://pessimization.com/software/orpie/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen RPN calculator for the console
WWW=		https://pessimization.com/software/orpie/

LICENSE=	GPLv2

BROKEN=         unfetchable
EXPIRATION_DATE=2023-04-30

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/num/META:math/ocaml-num
LIB_DEPENDS=	libgsl.so:math/gsl

USES=		gmake ncurses
USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

NOT_FOR_ARCHS=		armv6
NOT_FOR_ARCHS_REASON=	architectures with double-word alignment for doubles are not supported

PLIST_FILES=	bin/orpie bin/orpie-curses-keys etc/orpierc \
		man/man1/orpie.1.gz man/man1/orpie-curses-keys.1.gz \
		man/man5/orpierc.5.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
