PORTNAME=	cliphist
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland clipboard manager
WWW=		https://github.com/sentriz/cliphist

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	sentriz
GH_TUPLE=	etcd-io:bbolt:v1.3.7:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		golang:sys:v0.4.0:golang_sys/vendor/golang.org/x/sys \
		matryer:is:v1.4.0:matryer_is/vendor/github.com/matryer/is
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	FZF
OPTIONS_DEFAULT=FZF

FZF_DESC=		Script with only unique lines and previews
FZF_RUN_DEPENDS=	fzf:textproc/fzf \
			wl-copy:x11/wl-clipboard
FZF_PLIST_FILES=	bin/${PORTNAME}-fzf

post-install-FZF-on:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/${FZF_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
