PORTNAME=	pqrs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Command line tool for inspecting Apache Parquet files
WWW=		https://github.com/manojkarthick/pqrs

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	ld: error: undefined symbol: __atomic_load

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	manojkarthick

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.18 \
		alloc-no-stdlib-2.0.3 \
		alloc-stdlib-0.2.1 \
		arrow-12.0.0 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		brotli-3.3.4 \
		brotli-decompressor-2.3.2 \
		bstr-0.2.17 \
		byteorder-1.4.3 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		chrono-tz-0.6.1 \
		chrono-tz-build-0.0.2 \
		clap-3.1.18 \
		clap_derive-3.1.18 \
		clap_lex-0.2.0 \
		crc32fast-1.3.2 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		difflib-0.4.0 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		env_logger-0.9.0 \
		fastrand-1.7.0 \
		flatbuffers-2.1.1 \
		flate2-1.0.23 \
		float-cmp-0.9.0 \
		getrandom-0.2.6 \
		half-1.8.2 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		humantime-2.1.0 \
		indexmap-1.8.1 \
		instant-0.1.12 \
		integer-encoding-1.1.7 \
		itertools-0.10.3 \
		itoa-0.4.8 \
		itoa-1.0.1 \
		jobserver-0.1.24 \
		lazy_static-1.4.0 \
		lexical-core-0.8.3 \
		lexical-parse-float-0.8.3 \
		lexical-parse-integer-0.8.3 \
		lexical-util-0.8.3 \
		lexical-write-float-0.8.4 \
		lexical-write-integer-0.8.3 \
		libc-0.2.125 \
		log-0.4.17 \
		lz4-1.23.3 \
		lz4-sys-1.9.3 \
		memchr-2.5.0 \
		miniz_oxide-0.5.1 \
		multiversion-0.6.1 \
		multiversion-macros-0.6.1 \
		normalize-line-endings-0.3.0 \
		num-0.4.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.1 \
		num-integer-0.1.45 \
		num-iter-0.1.43 \
		num-rational-0.4.0 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		ordered-float-1.1.1 \
		os_str_bytes-6.0.0 \
		parquet-12.0.0 \
		parquet-format-4.0.0 \
		parse-zoneinfo-0.3.0 \
		phf-0.10.1 \
		phf_codegen-0.10.0 \
		phf_generator-0.10.0 \
		phf_shared-0.10.0 \
		ppv-lite86-0.2.16 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.38 \
		quote-1.0.18 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.2.13 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		serde-1.0.137 \
		serde_derive-1.0.137 \
		serde_json-1.0.81 \
		siphasher-0.3.10 \
		smallvec-1.8.0 \
		snap-1.0.5 \
		static_assertions-1.1.0 \
		strsim-0.10.0 \
		syn-1.0.94 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		termtree-0.2.4 \
		textwrap-0.15.0 \
		thiserror-1.0.31 \
		thiserror-impl-1.0.31 \
		threadpool-1.8.1 \
		thrift-0.13.0 \
		uncased-0.9.6 \
		unicode-xid-0.2.3 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zstd-0.11.2+zstd.1.5.2 \
		zstd-safe-5.0.2+zstd.1.5.2 \
		zstd-sys-2.0.1+zstd.1.5.2

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
