PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.7
CATEGORIES=	net-mgmt python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	IP address management tool
WWW=		https://github.com/netbox-community/netbox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# NetBox has fixed Python package dependencies listed in "requirements.txt"
# which are not checked during build/runtime because they're usually installed
# via devel/py-pip.
#
# As a rule, slight deviations are usually not a problem, but there are a few
# Django packages that are known for regressions in conjunction with NetBox and
# should therefore only be updated with caution.
#
# - devel/py-dj41-django-rq
# - www/py-dj41-django-filter
# - www/py-dj41-django-tables2
# - www/py-dj41-djangorestframework (in conjunction with www/py-dj41-drf-yasg)
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>=4.1.7<4.2:www/py-django41@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-cors-headers>=3.14.0<4:www/py-dj41-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-debug-toolbar>=3.7.0<4:www/py-dj41-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-filter>=23.1<24:www/py-dj41-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-graphiql-debug-toolbar>=0.2.0<1:www/py-dj41-django-graphiql-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-mptt>=0.14.0<0.15:www/py-dj41-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-prometheus>=2.2.0<2.3:www/py-dj41-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-redis>=5.2.0<6:www/py-dj41-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-rich>=1.5.0<2:www/py-dj41-django-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-rq>=2.7.0<2.8:devel/py-dj41-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-tables2>=2.5.3<2.6:www/py-dj41-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-taggit>=3.1.0<4:www/py-dj41-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-django-timezone-field>=5.0<6:www/py-dj41-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-djangorestframework>=3.14.0<3.15.0:www/py-dj41-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-drf-yasg>=1.21.5<1.22:www/py-dj41-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj41-graphene-django>=3.0.0<4:devel/py-dj41-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4<1.1:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=5.0.1<6:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7<3.4:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-include>=0.7.0<1:textproc/py-markdown-include@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>=9.1.4<10:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=0.17.0<1:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.8.0<1:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.4.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.5<3:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.5.12<2:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-app-django>=5.0.0<6:www/py-social-auth-app-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core>=4.3.0<5:security/py-social-auth-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.3<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.3.0<4:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2023.2:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=6.0<7:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=20.1.0<21:www/py-gunicorn@${PY_FLAVOR}

USES=		cpe pgsql:11+ python:3.8+
CPE_VENDOR=	netbox_project
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	850.netbox-housekeeping.sample netbox_rq.sample netboxrc.sample pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER} WWWOWN=${WWWOWN}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

do-install:
	cd ${WRKSRC}/netbox ; \
	for src in $$( ${FIND} . ! -name '*.bak' ) ; do \
		dst=${STAGEDIR}${DATADIR}$${src#.} ; \
		if ${TEST} -d "$$src" ; then \
			${MKDIR} "$$dst" ; \
		else \
			${INSTALL_DATA} "$$src" "$$dst" ; \
		fi \
	done
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mkdocs.yml ${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/850.netbox-housekeeping.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/netbox_rq.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/netboxrc.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/apache.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/gunicorn.py ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/nginx.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
