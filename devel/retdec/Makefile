# $FreeBSD$

PORTNAME=		retdec
DISTVERSION=		xxx
DISTVERSIONPREFIX=	v
CATEGORIES=		devel

MASTER_SITES=    	https://github.com/avast/retdec-support/releases/download/2019-03-08/
DISTFILES=		retdec-support_2019-03-08.tar.xz
DIST_SUBDIR=		${PORTNAME}

MAINTAINER=		benny.goemans@gmail.com
COMMENT=		RetDec is a retargetable machine-code decompiler based on LLVM.

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			cmake:noninja compiler:c++17-lang python:3.4+ shebangfix ssl
SHEBANG_GLOB=		*.py

BUILD_DEPENDS=		aclocal:devel/automake \
			autoreconf:devel/autoconf \
			libtool:devel/libtool \
			bison:devel/bison

USE_GITHUB=		yes
GH_ACCOUNT=		avast
GH_TAGNAME=		b5f06019a8577cef131c5375a843b6f9974dad43
GH_TUPLE=		avast:capstone:27c713fe4f6eaf9721785932d850b6291a6073fe:capstone \
			avast:elfio:f85f07390b756fee61408dfe0b04ae4fb86c5477:elfio \
			avast:libdwarf:85465d5e235cc2d2f90d04016d6aca1a452d0e73:libdwarf \
			avast:llvm:21dfb69c7547c525466b0c7481f4bbd9cb0dd032:llvm \
			avast:pelib:cdd54dd1b2efd61c8c6e837167b15676c4bba6fa:pelib \
			avast:yara:e3ae3848d66cdb551e149f1a87a45bcc87578f9c:yara \
			avast:yaracpp:3417c9e855ebb06096571f54175e33c5efb0f774:yaracpp \
			avast:yaramod:v3.0.0b0:yaramod \
			fmtlib:fmt:5.3.0:fmtlib \
			google:re2:2019-07-01:re2 \
			leethomason:tinyxml2:cc1745b552dd12bb1297a99f82044f83b06729e0:tinyxml \
			metthal:pog:v0.5.0:pog \
			open-source-parsers:jsoncpp:1.8.4:jsoncpp \
			Tencent:rapidjson:v1.1.0:rapidjson \
			keystone-engine:keystone:d7ba8e378e5284e6384fc9ecd660ed5f6532e922:keystone \
			google:googletest:90a443f9c2437ca8a682a1ac625eba64e1d74a8a:googletest

CMAKE_ARGS=		-D CAPSTONE_LOCAL_DIR:PATH=${WRKSRC_capstone} \
			-D ELFIO_LOCAL_DIR:PATH=${WRKSRC_elfio} \
			-D FMTLIB_LOCAL_DIR:PATH=${WRKSRC_fmtlib} \
			-D JSONCPP_LOCAL_DIR:PATH=${WRKSRC_jsoncpp} \
			-D LIBDWARF_LOCAL_DIR:PATH=${WRKSRC_libdwarf} \
			-D LLVM_LOCAL_DIR:PATH=${WRKSRC_llvm} \
			-D RAPIDJSON_LOCAL_DIR:PATH=${WRKSRC_rapidjson} \
			-D PELIB_LOCAL_DIR:PATH=${WRKSRC_pelib} \
			-D POG_LOCAL_DIR:PATH=${WRKSRC_pog} \
			-D TINYXML_LOCAL_DIR:PATH=${WRKSRC_tinyxml} \
			-D RE2_LOCAL_DIR:PATH=${WRKSRC_re2} \
			-D YARA_LOCAL_DIR:PATH=${WRKSRC_yara} \
			-D YARACPP_LOCAL_DIR:PATH=${WRKSRC_yaracpp} \
			-D YARAMOD_LOCAL_DIR:PATH=${WRKSRC_yaramod} \
			-D BSD_WRKSRC:PATH=${WRKSRC} \
			-D BSD_STAGEDIR:PATH=${STAGEDIR} # this might look suspicious, but it's used in python scripts that install files during staging

OPTIONS_DEFINE=		DOCS GRAPHVIZ TESTS UPX YARA
OPTIONS_DEFAULT=	DOCS YARA

DOCS_DESC=		add API documentation
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz

GRAPHVIZ_DESC=		enable if you want to generate call or control flow graphs
GRAPHVIZ_RUN_DEPENDS=	dot:graphics/graphviz

UPX_DESC=		use UPX unpacker in the preprocessing stage
UPX_RUN_DEPENDS=	upx:archivers/upx

TESTS_DESC=		build and execute tests
TESTS_CMAKE_BOOL=	RETDEC_TESTS
TESTS_GH_TUPLE=		google:googletest:90a443f9c2437ca8a682a1ac625eba64e1d74a8a:googletest \
			keystone-engine:keystone:d7ba8e378e5284e6384fc9ecd660ed5f6532e922:keystone
TESTS_CMAKE_ARGS=	-D GOOGLETEST_LOCAL_DIR:PATH=${WRKSRC_googletest} \
			-D KEYSTONE_LOCAL_DIR:PATH=${WRKSRC_keystone}

YARA_DESC=		YARA rules compilation at installation step
YARA_CMAKE_BOOL=	RETDEC_COMPILE_YARA

post-extract:
	# retdec-support is untarred by support/install-share.py into the stagedir
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/retdec-support_2019-03-08.tar.xz ${WRKSRC}/support


.include <bsd.port.mk>
