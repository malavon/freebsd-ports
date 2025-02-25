PORTNAME=	kalker
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scientific calculator that supports math-like syntax
WWW=		https://kalker.xyz/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpc.so:math/mpc

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	PaddiM8
CARGO_CRATES=	aho-corasick-0.7.20 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		az-1.2.1 \
		bitflags-1.3.2 \
		bumpalo-3.12.0 \
		cc-1.0.78 \
		cfg-if-1.0.0 \
		console_error_panic_hook-0.1.7 \
		dirs-3.0.2 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		fs2-0.4.3 \
		getrandom-0.2.8 \
		gmp-mpfr-sys-1.5.0 \
		hermit-abi-0.1.19 \
		js-sys-0.3.60 \
		lazy_static-1.4.0 \
		libc-0.2.139 \
		log-0.4.17 \
		memchr-2.5.0 \
		nix-0.19.1 \
		once_cell-1.17.0 \
		proc-macro2-1.0.50 \
		quote-1.0.23 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		regex-1.7.1 \
		regex-syntax-0.6.28 \
		rug-1.19.0 \
		rustyline-7.1.0 \
		scoped-tls-1.0.1 \
		scopeguard-1.1.0 \
		seahorse-1.1.2 \
		serde-1.0.152 \
		syn-1.0.107 \
		test-case-1.2.3 \
		thiserror-1.0.38 \
		thiserror-impl-1.0.38 \
		toml-0.5.11 \
		unicode-ident-1.0.6 \
		unicode-segmentation-1.10.0 \
		unicode-width-0.1.10 \
		utf8parse-0.2.0 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-futures-0.4.33 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		wasm-bindgen-test-0.3.33 \
		wasm-bindgen-test-macro-0.3.33 \
		web-sys-0.3.60 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1 \
		winres-0.1.12
CARGO_CARGOTOML=	${WRKSRC}/cli/Cargo.toml
CARGO_INSTALL_PATH=	./cli
PLIST_FILES=	bin/kalker

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC_crate_gmp-mpfr-sys}/build.rs

.include <bsd.port.mk>
