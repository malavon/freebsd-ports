PORTNAME=	valgrind
PORTVERSION=	3.20.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/valgrind

MAINTAINER=	pjfloyd@wanadoo.fr
COMMENT=	Memory debugging and profiling tool
WWW=		https://www.valgrind.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

USES=		autoreconf cpe gmake pathfix perl5 pkgconfig shebangfix tar:bz2
USE_PERL5=	build
SHEBANG_FILES=	callgrind/callgrind_annotate.in callgrind/callgrind_control.in
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL}

SSP_UNSAFE=	yes
LIB32_PATH?=	/usr/lib32/libc.so

CONFLICTS=	valgrind-devel
PORTDOCS=	html

OPTIONS_DEFINE=		DOCS MANPAGES MPI
OPTIONS_DEFINE_amd64=	32BIT
OPTIONS_DEFAULT=	MANPAGES
.if exists(${LIB32_PATH})
OPTIONS_DEFAULT_amd64=	32BIT
.endif
OPTIONS_SUB=		yes

32BIT_DESC=	Enable debugging of 32-bit programs (requires lib32)
MPI_DESC=	Enable build of MPI wrappers

DOCS_BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MANPAGES_BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
			xsltproc:textproc/libxslt
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=		AMD64=""
. if !${PORT_OPTIONS:M32BIT}
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=		X86="@comment "
. else
.  if !exists(${LIB32_PATH})
IGNORE=			please either install the lib32 distribution or unset the 32BIT option
.  endif
PLIST_SUB+=		X86=""
. endif
.else
PLIST_SUB+=		AMD64="@comment " \
			X86=""
.endif

post-patch-DOCS-off:
	@${RM} -r ${WRKSRC}/docs/html

post-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html-docs

post-build-MANPAGES-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man-pages

.include <bsd.port.mk>
