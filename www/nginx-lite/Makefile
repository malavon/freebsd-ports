PORTNAME=	nginx
PORTREVISION=	1
PKGNAMESUFFIX=	-lite

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Robust and small WWW server (lite package)

MASTERDIR=	${.CURDIR}/../nginx

CONFLICTS=	nginx-1.* \
		nginx-devel-1.* \
                nginx-full-1.* \
                nginx-naxsi-1.*

OPTIONS_DEFAULT=FILE_AIO HTTP HTTP_CACHE \
		HTTP_REALIP HTTP_REWRITE \
		HTTP_SSL THREADS PCRE_ONE

.include "${MASTERDIR}/Makefile"
