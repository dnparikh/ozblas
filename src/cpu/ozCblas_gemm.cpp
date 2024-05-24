
#include "ozblas_common.h"
#include "../../include/ozCblas.h"


extern "C" int32_t ozblasRgemm_fp128_d( 
    ozblasHandle_t *oh,
    const char transA, const char transB,
    const int32_t m, const int32_t n, const int32_t k,
    const __float128  alpha,
    const __float128 *devA, const int32_t lda,
    const __float128 *devB, const int32_t ldb,
    const __float128  beta,
    __float128 *devC, const int32_t ldc
)
{
    return ozblasRgemm <__float128, double> ( oh, transA, transB, m, n, k, 
                                    alpha, devA, lda, devB, ldb, 
                                    beta, devC, ldc);

}


extern "C" void ozCblasCreate ( ozblasHandle_t *oh, uint64_t WorkSizeBytes) 
{
    ozblasCreate(oh, WorkSizeBytes);
}

extern "C" void ozCblasDestroy ( ozblasHandle_t *oh ) 
{
    ozblasDestroy(oh);
}
