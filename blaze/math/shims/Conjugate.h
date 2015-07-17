//=================================================================================================
/*!
//  \file blaze/math/shims/Conjugate.h
//  \brief Header file for the conjugate shim
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

#ifndef _BLAZE_MATH_SHIMS_CONJUGATE_H_
#define _BLAZE_MATH_SHIMS_CONJUGATE_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/system/Inline.h>
#include <blaze/util/EnableIf.h>
#include <blaze/util/typetraits/IsBuiltin.h>


namespace blaze {

//=================================================================================================
//
//  CONJUGATE SHIM
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Computing the conjugate of the given value/object.
// \ingroup math_shims
//
// \param a The given value/object.
// \return The complex conjugate of the given value.
//
// The conjugate shim represents an abstract interface for the computation of the complex
// conjugate of any given data type. In case the given value is of complex type the function
// computes the complex conjugate by reversing the sign of the imaginary part:

   \code
   const blaze::complex a( 1.0, 2.0 );
   const blaze::complex b( conj( a ) );  // Results in ( 1, -2 )
   \endcode

// Values of other data types, such as all built-in data types, are considered complex numbers
// with an imaginary part of 0. Thus the returned value corresponds to the given value. For more
// information on complex conjugates, see
//
//       https://en.wikipedia.org/wiki/Complex_conjugate
*/
template< typename T >
BLAZE_ALWAYS_INLINE typename EnableIf< IsBuiltin<T>, T >::Type
   conj( T a )
{
   return a;
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif