PORTNAME=	mod_cfg_ldap
PORTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/modcfgldap/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to keep your virtual host configuration in a LDAP directory
WWW=		https://sourceforge.net/projects/modcfgldap/

LICENSE=	BSD3CLAUSE

USES=		apache ldap
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

LDAP_INC?=	${LOCALBASE}/include
LDAP_LIB?=	${LOCALBASE}/lib -lldap
AP_INC+=	${LDAP_INC}
AP_LIB+=	${LDAP_LIB}

PORTDOCS=	AUTHORS cfg_ldap.conf ChangeLog COPYING INSTALL \
		mod_cfg_ldap.schema README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
