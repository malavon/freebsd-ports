PORTNAME=	petsc4py
DISTVERSION=	3.18.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PETSc for Python
WWW=		https://gitlab.com/petsc/petsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BROKEN=		the upstream failed to update petsc4py on PYPI, it also breaks with pythran-0.12.0, see bug#270507

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libpetsc.so:science/PETSc
RUN_DEPENDS=	${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # tests fail to run, see https://gitlab.com/petsc/petsc/-/issues/1301

MAKE_ENV=	PETSC_DIR=${LOCALBASE}

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/petsc4py/lib/PETSc${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
