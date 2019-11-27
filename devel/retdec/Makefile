# $FreeBSD$

PORTNAME=		retdec
DISTVERSION=		xxx
DISTVERSIONPREFIX=	v
CATEGORIES=		devel

MAINTAINER=		benny.goemans@gmail.com
COMMENT=		RetDec is a retargetable machine-code decompiler based on LLVM.

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			cmake:noninja compiler:c++17-lang python:3.4+ shebangfix
SHEBANG_GLOB=		*.py

BUILD_DEPENDS=		aclocal:devel/automake \
			autoreconf:devel/autoconf \
			libtool:devel/libtool \
			bison:devel/bison

# RUN_DEPENDS=		libfmt.so:devel/libfmt \
# 			libre2.so:devel/re2

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
			Tencent:rapidjson:v1.1.0:rapidjson

CMAKE_ARGS=		-DCAPSTONE_LOCAL_DIR=${WRKSRC_capstone} \
			-DELFIO_LOCAL_DIR=${WRKSRC_elfio} \
			-DFMTLIB_LOCAL_DIR=${WRKSRC_fmtlib} \
			-DJSONCPP_LOCAL_DIR=${WRKSRC_jsoncpp} \
			-DKEYSTONE_LOCAL_DIR=${WRKSRC_keystone} \
			-DLIBDWARF_LOCAL_DIR=${WRKSRC_libdwarf} \
			-DLLVM_LOCAL_DIR=${WRKSRC_llvm} \
			-DRAPIDJSON_LOCAL_DIR=${WRKSRC_rapidjson} \
			-DPELIB_LOCAL_DIR=${WRKSRC_pelib} \
			-DPOG_LOCAL_DIR=${WRKSRC_pog} \
			-DTINYXML_LOCAL_DIR=${WRKSRC_tinyxml} \
			-DRE2_LOCAL_DIR=${WRKSRC_re2} \
			-DYARA_LOCAL_DIR=${WRKSRC_yara} \
			-DYARACPP_LOCAL_DIR=${WRKSRC_yaracpp} \
			-DYARAMOD_LOCAL_DIR=${WRKSRC_yaramod}

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
TESTS_CMAKE_ARGS=	-DGOOGLETEST_LOCAL_DIR=${WRKSRC_googletest}

YARA_DESC=		YARA rules compilation at installation step
YARA_CMAKE_BOOL=	RETDEC_COMPILE_YARA

.include <bsd.port.mk>
