PORTNAME=	multimedia
PORTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt audio, video, radio and camera support module
WWW=		https://qt.io

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gl localbase:ldflags pkgconfig qt-dist:6
USE_GL=		gl opengl
USE_QT=		base declarative shadertools svg

CXXFLAGS_powerpc64=	-mvsx
CFLAGS_powerpc=	-DPFFFT_SIMD_DISABLE

OPTIONS_DEFINE=	FFMPEG GSTREAMER Q3D V4L VAAPI
OPTIONS_DEFAULT=FFMPEG GSTREAMER PULSEAUDIO Q3D V4L VAAPI
OPTIONS_SINGLE=	AUDIO
OPTIONS_SINGLE_AUDIO=	ALSA PULSEAUDIO
OPTIONS_SUB=	yes

AUDIO_DESC=		Low level Audio Backend

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	FEATURE_alsa

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	FEATURE_ffmpeg

GSTREAMER_USES=		gnome gstreamer:1
GSTREAMER_USE=		GL=egl GNOME=glib20 GSTREAMER=bad,gl,good,ugly
GSTREAMER_CMAKE_BOOL=	FEATURE_gstreamer

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	FEATURE_pulseaudio

Q3D_DESC=		Spatial Audio via Quick3D
Q3D_USE=		QT=quick3d
Q3D_CMAKE_BOOL=		FEATURE_spatialaudio_quick3d

V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_CMAKE_BOOL=		FEATURE_linux_v4l
V4L_IMPLIES=		${"${PORT_OPTIONS:MFFMPEG}":?FFMPEG:GSTREAMER}

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_USE=		GL=egl
VAAPI_CMAKE_BOOL=	FEATURE_vaapi
VAAPI_IMPLIES=		FFMPEG

.include <bsd.port.options.mk>

post-install:
.if !(${PORT_OPTIONS:MFFMPEG} || ${PORT_OPTIONS:MGSTREAMER})
	@${REINPLACE_CMD} '/MultimediaPlugins\.cmake/d' ${TMPPLIST}
.endif

.include <bsd.port.mk>
