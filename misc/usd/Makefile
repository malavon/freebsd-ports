PORTNAME=	usd
<<<<<<< HEAD
DISTVERSIONPREFIX=	v
DISTVERSION=	21.11
PORTREVISION=	4
CATEGORIES=	misc

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	4942189cf7b1a45b23d62f4ae92a940721ec4009.patch:-p1 \
		445e3f8a473db9b1e0d1301e6ce4bf74c270f376.patch:-p1

=======
DISTVERSION=	22.03
PORTREVISION=	1
CATEGORIES=	misc

>>>>>>> caf66b722458 (usd 22.03 cannot build due to onetbb used in opensubdiv, but not in USD (uses TBB 2019))
MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal Scene Description is a scene description management system
WWW=		http://www.openusd.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=	armv6 armv7 i386 # CMakeLists.txt fails for non-64-bit architectures: Compiler does not support 64-bit builds

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake python:test

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	${PORTNAME:tu}

CMAKE_OFF=	PXR_BUILD_TESTS

# viewer requires python and imaging (how to)
OPTIONS_DEFINE=		EXAMPLES IMAGING PYTHON TOOLS TUTORIALS VIEWER
OPTIONS_DEFAULT=	EXAMPLES IMAGING PYTHON TOOLS TUTORIALS VIEWER
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	PXR_BUILD_EXAMPLES

IMAGING_DESC=		Build imaging components
IMAGING_CMAKE_BOOL=	PXR_BUILD_IMAGING
IMAGING_CMAKE_ON=	-DPTEX_INCLUDE_DIR=${LOCALBASE}/include
IMAGING_LIB_DEPENDS=	libGL.so:graphics/libglvnd \
			libosdCPU.so:graphics/opensubdiv \
			libPtex.so:graphics/ptex
#IMAGING_BROKEN=		see https://github.com/PixarAnimationStudios/USD/issues/1706

PYTHON_DESC=		Enable python bindings
PYTHON_CMAKE_BOOL=	PXR_ENABLE_PYTHON_SUPPORT PXR_USE_PYTHON_3
PYTHON_LIB_DEPENDS=	libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs
PYTHON_USES=		python

TOOLS_DESC=		Build commandline tools
TOOLS_CMAKE_BOOL=	PXR_BUILD_USD_TOOLS
TOOLS_LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

TUTORIALS_DESC=		Build and install tutorials
TUTORIALS_CMAKE_BOOL=	PXR_BUILD_TUTORIALS

# todo: does not work; searches for vulkan sdk :(
VULKAN_DESC=		Enable Vulkan support
VULKAN_CMAKE_BOOL=	PXR_ENABLE_VULKAN_SUPPORT
VULKAN_BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

VIEWER_DESC=		Build viewer application - requires IMAGING & PYTHON
VIEWER_CMAKE_BOOL=	PXR_BUILD_USDVIEW
VIEWER_CMAKE_ON=	-DPYSIDEUICBINARY=${LOCALBASE}/bin/uic-qt5
VIEWER_BUILD_DEPENDS=	pyside_tool.py:devel/pyside2-tools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.0:graphics/py-PyOpenGL@${PY_FLAVOR}
# VIEWER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>=3.1.0:graphics/py-PyOpenGL@${PY_FLAVOR}
VIEWER_LIB_DEPENDS=	libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2@${PY_FLAVOR}
# for uic-qt5
VIEWER_USE_QT=		widgets
			
VIEWER_IMPLIES=		IMAGING PYTHON

do-test: # tests are expected to be installed, see https://github.com/PixarAnimationStudios/USD/issues/1707
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DPXR_BUILD_TESTS=ON -DPYTHON_EXECUTABLE=${PYTHON_CMD} ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} install && \
		ctest -C ${CMAKE_BUILD_TYPE} ${WRKSRC}

.include <bsd.port.mk>
