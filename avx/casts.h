/*  This file is part of the Vc library.

    Copyright (C) 2009-2012 Matthias Kretz <kretz@kde.org>

    Vc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as
    published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    Vc is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Vc.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef AVX_CASTS_H
#define AVX_CASTS_H

#include "intrinsics.h"
#include "types.h"

namespace Vc
{
namespace AVX
{
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(param128  v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(param128i v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(param128d v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(param256  v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(param256i v) Vc_INTRINSIC_R;
    template<typename T> static inline Vc_INTRINSIC_L T avx_cast(param256d v) Vc_INTRINSIC_R;

    // 128 -> 128
    template<> inline __m128  Vc_INTRINSIC avx_cast(param128  v) { return v; }
    template<> inline __m128  Vc_INTRINSIC avx_cast(param128i v) { return _mm_castsi128_ps(v); }
    template<> inline __m128  Vc_INTRINSIC avx_cast(param128d v) { return _mm_castpd_ps(v); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(param128  v) { return _mm_castps_si128(v); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(param128i v) { return v; }
    template<> inline __m128i Vc_INTRINSIC avx_cast(param128d v) { return _mm_castpd_si128(v); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(param128  v) { return _mm_castps_pd(v); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(param128i v) { return _mm_castsi128_pd(v); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(param128d v) { return v; }

    // 128 -> 256
    template<> inline __m256  Vc_INTRINSIC avx_cast(param128  v) { return _mm256_castps128_ps256(v); }
    template<> inline __m256  Vc_INTRINSIC avx_cast(param128i v) { return _mm256_castps128_ps256(_mm_castsi128_ps(v)); }
    template<> inline __m256  Vc_INTRINSIC avx_cast(param128d v) { return _mm256_castps128_ps256(_mm_castpd_ps(v)); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(param128  v) { return _mm256_castsi128_si256(_mm_castps_si128(v)); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(param128i v) { return _mm256_castsi128_si256(v); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(param128d v) { return _mm256_castsi128_si256(_mm_castpd_si128(v)); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(param128  v) { return _mm256_castpd128_pd256(_mm_castps_pd(v)); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(param128i v) { return _mm256_castpd128_pd256(_mm_castsi128_pd(v)); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(param128d v) { return _mm256_castpd128_pd256(v); }

    // 256 -> 128
    template<> inline __m128  Vc_INTRINSIC avx_cast(param256  v) { return _mm256_castps256_ps128(v); }
    template<> inline __m128  Vc_INTRINSIC avx_cast(param256i v) { return _mm256_castps256_ps128(_mm256_castsi256_ps(v)); }
    template<> inline __m128  Vc_INTRINSIC avx_cast(param256d v) { return _mm256_castps256_ps128(_mm256_castpd_ps(v)); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(param256  v) { return _mm256_castsi256_si128(_mm256_castps_si256(v)); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(param256i v) { return _mm256_castsi256_si128(v); }
    template<> inline __m128i Vc_INTRINSIC avx_cast(param256d v) { return _mm256_castsi256_si128(_mm256_castpd_si256(v)); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(param256  v) { return _mm256_castpd256_pd128(_mm256_castps_pd(v)); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(param256i v) { return _mm256_castpd256_pd128(_mm256_castsi256_pd(v)); }
    template<> inline __m128d Vc_INTRINSIC avx_cast(param256d v) { return _mm256_castpd256_pd128(v); }

    // 256 -> 256
    template<> inline __m256  Vc_INTRINSIC avx_cast(param256  v) { return v; }
    template<> inline __m256  Vc_INTRINSIC avx_cast(param256i v) { return _mm256_castsi256_ps(v); }
    template<> inline __m256  Vc_INTRINSIC avx_cast(param256d v) { return _mm256_castpd_ps(v); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(param256  v) { return _mm256_castps_si256(v); }
    template<> inline __m256i Vc_INTRINSIC avx_cast(param256i v) { return v; }
    template<> inline __m256i Vc_INTRINSIC avx_cast(param256d v) { return _mm256_castpd_si256(v); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(param256  v) { return _mm256_castps_pd(v); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(param256i v) { return _mm256_castsi256_pd(v); }
    template<> inline __m256d Vc_INTRINSIC avx_cast(param256d v) { return v; }

    // simplify splitting 256-bit registers in 128-bit registers
    inline __m128  Vc_INTRINSIC lo128(param256  v) { return avx_cast<__m128>(v); }
    inline __m128d Vc_INTRINSIC lo128(param256d v) { return avx_cast<__m128d>(v); }
    inline __m128i Vc_INTRINSIC lo128(param256i v) { return avx_cast<__m128i>(v); }
    inline __m128  Vc_INTRINSIC hi128(param256  v) { return _mm256_extractf128_ps(v, 1); }
    inline __m128d Vc_INTRINSIC hi128(param256d v) { return _mm256_extractf128_pd(v, 1); }
    inline __m128i Vc_INTRINSIC hi128(param256i v) { return _mm256_extractf128_si256(v, 1); }

    // simplify combining 128-bit registers in 256-bit registers
    inline __m256  Vc_INTRINSIC concat(param128  a, param128  b) { return _mm256_insertf128_ps   (avx_cast<__m256 >(a), b, 1); }
    inline __m256d Vc_INTRINSIC concat(param128d a, param128d b) { return _mm256_insertf128_pd   (avx_cast<__m256d>(a), b, 1); }
    inline __m256i Vc_INTRINSIC concat(param128i a, param128i b) { return _mm256_insertf128_si256(avx_cast<__m256i>(a), b, 1); }

    template<typename From, typename To> struct StaticCastHelper {};
    template<> struct StaticCastHelper<float         , int           > { static __m256i  cast(param256  v) { return _mm256_cvttps_epi32(v); } };
    template<> struct StaticCastHelper<double        , int           > { static __m256i  cast(param256d v) { return avx_cast<_M256I>(_mm256_cvttpd_epi32(v)); } };
    template<> struct StaticCastHelper<int           , int           > { static __m256i  cast(param256i v) { return v; } };
    template<> struct StaticCastHelper<unsigned int  , int           > { static __m256i  cast(param256i v) { return v; } };
    template<> struct StaticCastHelper<short         , int           > { static __m256i  cast(param128i   v) { return concat(_mm_srai_epi32(_mm_unpacklo_epi16(v, v), 16), _mm_srai_epi32(_mm_unpackhi_epi16(v, v), 16)); } };
    template<> struct StaticCastHelper<float         , unsigned int  > { static __m256i  cast(param256  v) {
        return _mm256_castps_si256(_mm256_blendv_ps(
                _mm256_castsi256_ps(_mm256_cvttps_epi32(v)),
                _mm256_castsi256_ps(_mm256_add_epi32(__m256i(_mm256_cvttps_epi32(_mm256_sub_ps(v, _mm256_set2power31_ps()))), _mm256_set2power31_epu32())),
                _mm256_cmpge_ps(v, _mm256_set2power31_ps())
                ));

    } };
    template<> struct StaticCastHelper<double        , unsigned int  > { static __m256i  cast(param256d v) { return avx_cast<_M256I>(_mm256_cvttpd_epi32(v)); } };
    template<> struct StaticCastHelper<int           , unsigned int  > { static __m256i  cast(param256i v) { return v; } };
    template<> struct StaticCastHelper<unsigned int  , unsigned int  > { static __m256i  cast(param256i v) { return v; } };
    template<> struct StaticCastHelper<unsigned short, unsigned int  > { static __m256i  cast(param128i   v) { return concat(_mm_srli_epi32(_mm_unpacklo_epi16(v, v), 16), _mm_srli_epi32(_mm_unpackhi_epi16(v, v), 16)); } };
    template<> struct StaticCastHelper<float         , float         > { static __m256   cast(param256  v) { return v; } };
    template<> struct StaticCastHelper<double        , float         > { static __m256   cast(param256d v) { return avx_cast<_M256>(_mm256_cvtpd_ps(v)); } };
    template<> struct StaticCastHelper<int           , float         > { static __m256   cast(param256i v) { return _mm256_cvtepi32_ps(v); } };
    template<> struct StaticCastHelper<unsigned int  , float         > { static __m256   cast(param256i v) {
        return _mm256_blendv_ps(
                _mm256_cvtepi32_ps(v),
                _mm256_add_ps(_mm256_cvtepi32_ps(_mm256_sub_epi32(v, _mm256_set2power31_epu32())), _mm256_set2power31_ps()),
                _mm256_castsi256_ps(_mm256_cmplt_epi32(v, _mm256_setzero_si256()))
                );
    } };
    template<> struct StaticCastHelper<short         , float         > { static __m256  cast(param128i v) { return _mm256_cvtepi32_ps(StaticCastHelper<short, int>::cast(v)); } };
    template<> struct StaticCastHelper<unsigned short, float         > { static __m256  cast(param128i v) { return _mm256_cvtepi32_ps(StaticCastHelper<unsigned short, unsigned int>::cast(v)); } };
    template<> struct StaticCastHelper<float         , double        > { static __m256d cast(param256  v) { return _mm256_cvtps_pd(avx_cast<__m128>(v)); } };
    template<> struct StaticCastHelper<double        , double        > { static __m256d cast(param256d v) { return v; } };
    template<> struct StaticCastHelper<int           , double        > { static __m256d cast(param256i v) { return _mm256_cvtepi32_pd(avx_cast<__m128i>(v)); } };
    template<> struct StaticCastHelper<unsigned int  , double        > { static __m256d cast(param256i v) { return _mm256_cvtepi32_pd(avx_cast<__m128i>(v)); } };
    template<> struct StaticCastHelper<int           , short         > { static __m128i cast(param256i v) { return _mm_packs_epi32(lo128(v), hi128(v)); } };
    template<> struct StaticCastHelper<float         , short         > { static __m128i cast(param256  v) { return StaticCastHelper<int, short>::cast(StaticCastHelper<float, int>::cast(v)); } };
    template<> struct StaticCastHelper<short         , short         > { static __m128i cast(param128i v) { return v; } };
    template<> struct StaticCastHelper<unsigned short, short         > { static __m128i cast(param128i v) { return v; } };
    template<> struct StaticCastHelper<unsigned int  , unsigned short> { static __m128i cast(param256i v) { return _mm_packus_epi32(lo128(v), hi128(v)); } };
    template<> struct StaticCastHelper<float         , unsigned short> { static __m128i cast(param256  v) { return StaticCastHelper<unsigned int, unsigned short>::cast(StaticCastHelper<float, unsigned int>::cast(v)); } };
    template<> struct StaticCastHelper<short         , unsigned short> { static __m128i cast(param128i v) { return v; } };
    template<> struct StaticCastHelper<unsigned short, unsigned short> { static __m128i cast(param128i v) { return v; } };
    template<> struct StaticCastHelper<sfloat        , short         > { static __m128i cast(param256  v) { return StaticCastHelper<int, short>::cast(StaticCastHelper<float, int>::cast(v)); } };
    template<> struct StaticCastHelper<sfloat        , unsigned short> { static __m128i cast(param256  v) { return StaticCastHelper<unsigned int, unsigned short>::cast(StaticCastHelper<float, unsigned int>::cast(v)); } };
    template<> struct StaticCastHelper<short         , sfloat        > { static __m256  cast(param128i v) { return _mm256_cvtepi32_ps(StaticCastHelper<short, int>::cast(v)); } };
    template<> struct StaticCastHelper<unsigned short, sfloat        > { static __m256  cast(param128i v) { return _mm256_cvtepi32_ps(StaticCastHelper<unsigned short, unsigned int>::cast(v)); } };
} // namespace AVX
} // namespace Vc

#endif // AVX_CASTS_H
