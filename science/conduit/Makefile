PORTNAME=	conduit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simplified data exchange for HPC simulations
WWW=		https://github.com/LLNL/conduit

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsiloh5.so:science/silo \
		libsz.so:science/libaec

USES=		cmake:testing compiler:c++11-lang fortran
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_TUPLE=	LLNL:blt:86a7d6b:blt/blt \
		Alpine-DAV:spack_configs:85f7382:spack_configs/../scripts/uberenv_configs/spack_configs \
		LLNL:uberenv:105e384:LLNL_uberenv/../scripts/uberenv

WRKSRC_SUBDIR=	src

CMAKE_ON=	ENABLE_FORTRAN
CMAKE_OFF=	CONDUIT_ENABLE_TESTS ENABLE_DOCS ENABLE_EXAMPLES ENABLE_GIT ENABLE_TESTS ENABLE_VALGRIND
CMAKE_ARGS=	-DHDF5_DIR=${LOCALBASE} \
		-DSILO_DIR=${LOCALBASE} \
		-DFREEBSD_EXAMPLESDIR=${EXAMPLESDIR} # complete list of optional dependencies (enabled with *_DIR): https://llnl-conduit.readthedocs.io/en/latest/building.html
#CMAKE_ARGS+=	-DADIOS_DIR=${LOCALBASE} # broken, see https://github.com/LLNL/conduit/issues/841
CMAKE_TESTING_ON=	ENABLE_TESTS

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	NOMPI MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH
OPTIONS_SUB=		yes

NOMPI_DESC=		Build without parallel processing support

MPICH_USES=		mpi:mpich
MPICH_CMAKE_ON=		-DENABLE_MPI=ON

OPENMPI_USES=		mpi:openmpi
OPENMPI_CMAKE_ON=	-DENABLE_MPI=ON

.include <bsd.port.mk>
