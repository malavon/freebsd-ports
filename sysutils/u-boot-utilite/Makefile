PORTNAME=	u-boot
PORTVERSION=	2015.07
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/:source1 \
		http://www.compulab.co.il/wp-content/uploads/2015/10/:source2
PKGNAMESUFFIX=	-utilite
DISTFILES=	u-boot-2015.07.tar.bz2:source1 \
		cm-fx6_u-boot_2015-10-18.zip:source2

MAINTAINER=	martin@waschbuesch.de
COMMENT=	Cross-build U-Boot loader for Utilite (and Utilite Pro)
WWW=		https://www.denx.de/wiki/U-Boot

LICENSE=	GPLv2

DEPRECATED=	This port depends on the long time unsupported upstream devel/arm-none-eabi-gcc492.
EXPIRATION_DATE=	2023-04-30

BUILD_DEPENDS=	${CROSS_GCC}:devel/arm-none-eabi-gcc492

USES=		gmake

MAKE_ARGS+=     ARCH=arm \
                CC=${CROSS_GCC} \
                CROSS_COMPILE=arm-none-eabi- \
                HOSTCC=cc

EXTRA_PATCHES=	${WRKDIR}/cm-fx6-u-boot/u-boot/u-boot-2015.07-cm-fx6-3.patch:-p1

NO_ARCH=	yes

PORTSCOUT=	ignore:1

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}

do-configure:
	cd ${WRKSRC}; ${MAKE_CMD} ${MAKE_ARGS} cm_fx6_config

CROSS_GCC=	arm-none-eabi-gcc-4.9.2

# The build results in two output files: SPL, and u-boot.img.
# Combine them into a single u-boot.imx so that there is only one file to be
# copied onto the boot media starting at a 1K offset on the disk.
CM_FX6_FIRMWARE=	${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/cm-fx6-firmware
do-install:
	cd ${WRKSRC}; ./tools/mkimage -n arch/arm/imx-common/spl_sd.cfg.cfgtmp -T imximage -e 0x00908000 -d spl/u-boot-spl.bin spl.img
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	dd if=/dev/zero count=500 bs=1K | ${TR} '\000' '\377' > ${CM_FX6_FIRMWARE}
	dd if=${WRKSRC}/spl.img of=${CM_FX6_FIRMWARE} bs=1K seek=1 conv=notrunc && dd if=${WRKSRC}/u-boot.img of=${CM_FX6_FIRMWARE} bs=1K seek=64 conv=notrunc
	${INSTALL_DATA} ${DESCR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
