##############################################

#--- System ----------------------------------
#CPU_ARCH: KNL, ICELAKE, SKYLAKE, ARM
CPU_ARCH = 
# -> If specified, compile with architecture-specific options

#LINKAGE: static, dynamic
LINKAGE = static

#--- PATH ------------------------------------
#CUDA_PATH	= /work/opt/local/x86_64/cores/cuda/12.0
CUDA_PATH	= /usr/local/cuda-12.0
LIB_PATH	= -L$(HOME)/lib/libblis/lib -L$(HOME)/lib/libmplapack/lib
INC_PATH	= -I$(HOME)/lib/libblis/include -I$(HOME)/lib/libmplapack/include/mplapack -I$(HOME)/lib/libmplapack/include
# -> installation path of external libraries

#--- Compiler --------------------------------
CXX = g++
# -> Intel Compiler (icpc) should work (but not tested)
# -> Intel LLVM Compiler (icpx) does NOT work (for quadruple-precision)

#--- CPU (OzBLAS) / CUDA (cuOzBLAS) ----------
CPU  = yes
CUDA = no
# CPU must be yes also for CUDA

#--- BLAS (CPU) ------------------------------
#CPU_BLAS: MKL, OpenBLAS, SSL2
CPU_BLAS = OpenBLAS
# CSRMV & CG require MKL because OpenBLAS does not have sparse routines.

#--- MPLAPACK (for testing) ------------------
MPLAPACK = no
# -> yes or no. 'yes' uses MPLAPACK for verifying computational result
# -> If no, binary128 (PREC_Q_D and PREC_Q_S) cannot be used.
# MPLAPACK does not work with SSL2 on Fugaku

#--- CUDA Compute Capability -----------------
CC30 = no
CC32 = no
CC35 = no
CC37 = no
CC50 = no
CC52 = no
CC53 = no
CC60 = no
CC61 = no
CC62 = no
CC70 = no
CC75 = no
CC80 = yes
CC86 = no
# -> Tested only on GPUs with CC70, CC75, and CC86

#--- Precision -------------------------------
# PREC_X_Y: X is I/O-precision, Y is compute-precision
# Q: FP128, D: FP64, S: FP32
PREC_Q_D = yes
PREC_Q_S = no
PREC_D_D = no
PREC_D_S = no
PREC_S_S = no
PREC_S_D = no

#--- Routine ---------------------------------
# level-1
DOT = no
NRM2 = no
AXPY = no

# level-2
GEMV = no
CSRMV = no
# -> CSRMV requires MKL on CPUs

# level-3
GEMM = yes

# solver
CG = no
# -> CG requires CSRMV, DOT, NRM2, and AXPY

##############################################

