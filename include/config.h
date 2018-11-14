#ifndef __LIQUID_CONFIG_H__
#define __LIQUID_CONFIG_H__

/* Support AVX (Advanced Vector Extensions) instructions */
#define HAVE_AVX TRUE

/* Define to 1 if you have the <complex.h> header file. */
#define HAVE_COMPLEX_H 1

/* Define to 1 if you have the <emmintrin.h> header file. */
#define HAVE_EMMINTRIN_H 1

/* Define to 1 if you have the <fec.h> header file. */
/* #undef HAVE_FEC_H */

/* Define to 1 if you have the <fftw3.h> header file. */
/* #undef HAVE_FFTW3_H */

/* Define to 1 if you have the <float.h> header file. */
#define HAVE_FLOAT_H 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the <immintrin.h> header file. */
#define HAVE_IMMINTRIN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `fec' library (-lfec). */
/* #undef HAVE_LIBFEC */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <mmintrin.h> header file. */
#define HAVE_MMINTRIN_H 1

/* Support MMX instructions */
#define HAVE_MMX TRUE

/* Define to 1 if you have the <pmmintrin.h> header file. */
#define HAVE_PMMINTRIN_H 1

/* Define to 1 if you have the <smmintrin.h> header file. */
#define HAVE_SMMINTRIN_H 1

/* Support SSE (Streaming SIMD Extensions) instructions */
#define HAVE_SSE TRUE

/* Support SSE2 (Streaming SIMD Extensions 2) instructions */
#define HAVE_SSE2 TRUE

/* Support SSE3 (Streaming SIMD Extensions 3) instructions */
#define HAVE_SSE3 TRUE

/* Support SSE4.1 (Streaming SIMD Extensions 4.1) instructions */
#define HAVE_SSE41 TRUE

/* Support SSE4.2 (Streaming SIMD Extensions 4.2) instructions */
#define HAVE_SSE42 TRUE

/* Support SSSE3 (Supplemental Streaming SIMD Extensions 3) instructions */
#define HAVE_SSSE3 TRUE

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
/* #undef HAVE_SYS_RESOURCE_H */

/* Define to 1 if you have the <tmmintrin.h> header file. */
#define HAVE_TMMINTRIN_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <xmmintrin.h> header file. */
#define HAVE_XMMINTRIN_H 1

/* Force internal FFT even if libfftw is available */
/* #undef LIQUID_FFTOVERRIDE */

/* Force overriding of SIMD (use portable C code) */
/* #undef LIQUID_SIMDOVERRIDE */

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `unsigned int', as computed by sizeof. */
#define SIZEOF_UNSIGNED_INT 4

/* Define to 1 if <math.h> contains single-precision fp. */
#define HAVE_SINGLE_FP 1

#endif // __LIQUID_CONFIG_H__
