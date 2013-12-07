#ifndef __BTAS_STRIDE_H
#define __BTAS_STRIDE_H 1

#include <type_traits>

#include <btas/types.h>

namespace btas {

template<CBLAS_ORDER _Order> struct __normal_stride;

template<>
struct __normal_stride<CblasRowMajor>
{
   template<class _Shape>
   set (const _Shape& shape_, _Shape& stride_)
   {
      typedef typename _Shape::value_type size_type;
      size_type str = 1;
      for(size_type i = shape_.size()-1; i > 0; --i) {
         stride_[i] = str;
         str *= shape_[i];
      }
      stride_[0] = str;
   }
};

template<>
struct __normal_stride<CblasColMajor>
{
   template<class _Shape>
   set (const _Shape& shape_, _Shape& stride_)
   {
      typedef typename _Shape::value_type size_type;
      size_type str = 1;
      for(size_type i = 0; i < shape_.size(); ++i) {
         stride_[i] = str;
         str *= shape_[i];
      }
   }
};

} // namespace btas

#endif // __BTAS_STRIDE_H
