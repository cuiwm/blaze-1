//=================================================================================================
/*!
//  \file blaze/math/traits/TSVecSVecMultExprTrait.h
//  \brief Header file for the TSVecSVecMultExprTrait class template
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_TRAITS_TSVECSVECMULTEXPRTRAIT_H_
#define _BLAZE_MATH_TRAITS_TSVECSVECMULTEXPRTRAIT_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/traits/MultTrait.h>
#include <blaze/math/typetraits/IsColumnVector.h>
#include <blaze/math/typetraits/IsRowVector.h>
#include <blaze/math/typetraits/IsSparseVector.h>
#include <blaze/util/InvalidType.h>
#include <blaze/util/mpl/And.h>
#include <blaze/util/mpl/If.h>
#include <blaze/util/mpl/Or.h>
#include <blaze/util/typetraits/IsConst.h>
#include <blaze/util/typetraits/IsReference.h>
#include <blaze/util/typetraits/IsVolatile.h>
#include <blaze/util/typetraits/RemoveCV.h>
#include <blaze/util/typetraits/RemoveReference.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Auxiliary helper struct for the TSVecSVecMultExprTrait.
// \ingroup math_traits
*/
template< typename VT1
        , typename VT2
        , bool Valid >
struct TSVecSVecMultExprTraitHelper
{
   //**********************************************************************************************
   typedef INVALID_TYPE  Type;
   //**********************************************************************************************
};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the TSVecSVecMultExprTrait auxiliary helper struct.
// \ingroup math_traits
*/
template< typename VT1
        , typename VT2 >
struct TSVecSVecMultExprTraitHelper<VT1,VT2,true>
{
   //**********************************************************************************************
   typedef typename MultTrait<typename VT1::ElementType,typename VT2::ElementType>::Type  Type;
   //**********************************************************************************************
};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Evaluation of the expression type of a transpose sparse vector/sparse vector multiplication.
// \ingroup math_traits
//
// Via this type trait it is possible to evaluate the resulting expression type of a transpose
// sparse vector/sparse vector multiplication (inner product). Given the transpose sparse vector
// type \a VT1 and the non-transpose sparse vector type \a VT2, the nested type \a Type corresponds
// to the resulting expression type. In case either \a VT1 is not a transpose sparse vector
// type or \a VT2 is not a non-transpose sparse vector type, the resulting \a Type is set to
// \a INVALID_TYPE.
*/
template< typename VT1    // Type of the left-hand side transpose sparse vector
        , typename VT2 >  // Type of the right-hand side non-transpose sparse vector
struct TSVecSVecMultExprTrait
{
 private:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   enum { valid = IsSparseVector<VT1>::value && IsRowVector<VT1>::value &&
                  IsSparseVector<VT2>::value && IsColumnVector<VT2>::value };
   /*! \endcond */
   //**********************************************************************************************

   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   typedef TSVecSVecMultExprTraitHelper<VT1,VT2,valid>  Tmp;

   typedef typename RemoveReference< typename RemoveCV<VT1>::Type >::Type  Type1;
   typedef typename RemoveReference< typename RemoveCV<VT2>::Type >::Type  Type2;
   /*! \endcond */
   //**********************************************************************************************

 public:
   //**********************************************************************************************
   /*! \cond BLAZE_INTERNAL */
   typedef typename If< Or< IsConst<VT1>, IsVolatile<VT1>, IsReference<VT1>
                          , IsConst<VT2>, IsVolatile<VT2>, IsReference<VT2> >
                      , TSVecSVecMultExprTrait<Type1,Type2>, Tmp >::Type::Type  Type;
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************

} // namespace blaze

#endif
