PORTNAME=	envconsul
PORTVERSION=	0.11.0
DISTVERSIONPREFIX=	v
PORTREVISION=	12
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Populate values from Consul into a process environment
WWW=		https://github.com/hashicorp/envconsul

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	hashicorp:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT/src/github.com/hashicorp/${PORTNAME} \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		armon:go-metrics:ec5e00d3c878:armon_go_metrics/vendor/github.com/armon/go-metrics \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:4def268fd1a4:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ca1201d0de80:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		hashicorp:consul-template:v0.25.1:hashicorp_consul_template/vendor/github.com/hashicorp/consul-template \
		hashicorp:consul:api/v1.4.0:hashicorp_consul_api/vendor/github.com/hashicorp/consul_api \
		hashicorp:consul:sdk/v0.4.0:hashicorp_consul_sdk/vendor/github.com/hashicorp/consul_sdk \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-gatedio:v0.5.0:hashicorp_go_gatedio/vendor/github.com/hashicorp/go-gatedio \
		hashicorp:go-hclog:v0.12.0:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.1.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.4:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hashicorp:golang-lru:v0.5.3:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		hashicorp:serf:v0.8.3:hashicorp_serf/vendor/github.com/hashicorp/serf \
		hashicorp:vault:0dc007d98cc8:hashicorp_vault_sdk/vendor/github.com/hashicorp/vault \
		hashicorp:vault:746c0b111519:hashicorp_vault_api \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-shellwords:v1.0.5:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pierrec:lz4:v2.2.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2

PLIST_FILES=	bin/envconsul

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md
GHTAG=		9f66f6c5

GO_BUILDFLAGS=	-ldflags='\
		-s -w \
		-X github.com/hashicorp/envconsul/version.Name=${PORTNAME} \
		-X github.com/hashicorp/envconsul/version.GitCommit=${GHTAG}'

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/vault/api
	@${RLN} ${WRKSRC_hashicorp_vault_api}/api ${WRKSRC}/vendor/github.com/hashicorp/vault/api
	@${MKDIR} ${WRKSRC}/vendor/github.com/hashicorp/consul
	@${RLN} ${WRKSRC_hashicorp_consul_api}/api ${WRKSRC}/vendor/github.com/hashicorp/consul/api
	@${RLN} ${WRKSRC_hashicorp_consul_sdk} ${WRKSRC}/vendor/github.com/hashicorp/consul/sdk

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/src/github.com/hashicorp/envconsul/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
