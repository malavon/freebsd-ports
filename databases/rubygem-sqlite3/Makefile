PORTNAME=	sqlite3
PORTVERSION=	1.6.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3
WWW=		https://github.com/sparklemotion/sqlite3-ruby

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		gem

CONFIGURE_ARGS=	--enable-system-libraries --with-sqlite3-dir=${LOCALBASE}

.include <bsd.port.mk>
