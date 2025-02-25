PORTNAME=	qrcp
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Transfer files over wifi by scanning a QR code
WWW=		https://claudiodangelis.com/qrcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	claudiodangelis
GH_TUPLE=	\
		adrg:xdg:v0.3.2:adrg_xdg/vendor/github.com/adrg/xdg \
		asaskevich:govalidator:475eaeb16496:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		eiannone:keyboard:caf4b762e807:eiannone_keyboard/vendor/github.com/eiannone/keyboard \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		glendc:go-external-ip:139229dcdddd:glendc_go_external_ip/vendor/github.com/glendc/go-external-ip \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhoonb:archivex:0488e4ce1681:jhoonb_archivex/vendor/github.com/jhoonb/archivex \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		lunixbochs:vtclean:2d01aacdc34a:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		manifoldco:promptui:v0.7.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		skip2:go-qrcode:9434209cb086:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

PLIST_FILES=	bin/qrcp
PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
