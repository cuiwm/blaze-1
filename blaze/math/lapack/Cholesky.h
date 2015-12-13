//=================================================================================================
/*!
//  \file blaze/math/lapack/Cholesky.h
//  \brief Header file for LAPACK Cholesky decomposition functions
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

#ifndef _BLAZE_MATH_LAPACK_CHOLESKY_H_
#define _BLAZE_MATH_LAPACK_CHOLESKY_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <boost/cast.hpp>
#include <blaze/math/constraints/Adaptor.h>
#include <blaze/math/constraints/Computation.h>
#include <blaze/math/constraints/MutableDataAccess.h>
#include <blaze/math/expressions/DenseMatrix.h>
#include <blaze/math/typetraits/IsRowMajorMatrix.h>
#include <blaze/util/Assert.h>
#include <blaze/util/constraints/Complex.h>
#include <blaze/util/constraints/Double.h>
#include <blaze/util/constraints/Float.h>
#include <blaze/util/Exception.h>
#include <blaze/util/StaticAssert.h>


namespace blaze {

//=================================================================================================
//
//  LAPACK FORWARD DECLARATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
extern "C" {

void spotrf_( char* uplo, int* n, float*  a, int* lda, int* info );
void dpotrf_( char* uplo, int* n, double* a, int* lda, int* info );
void cpotrf_( char* uplo, int* n, float*  a, int* lda, int* info );
void zpotrf_( char* uplo, int* n, double* a, int* lda, int* info );

}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  LAPACK CHOLESKY DECOMPOSITION FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\name LAPACK Cholesky decomposition functions */
//@{
inline void spotrf( char* uplo, int* n, float* a, int* lda, int* info );

inline void dpotrf( char* uplo, int* n, double* a, int* lda, int* info );

inline void cpotrf( char* uplo, int* n, complex<float>* a, int* lda, int* info );

inline void zpotrf( char* uplo, int* n, complex<double>* a, int* lda, int* info );

template< typename MT, bool SO >
inline void spotrf( DenseMatrix<MT,SO>& A, char uplo );

template< typename MT, bool SO >
inline void dpotrf( DenseMatrix<MT,SO>& A, char uplo );

template< typename MT, bool SO >
inline void cpotrf( DenseMatrix<MT,SO>& A, char uplo );

template< typename MT, bool SO >
inline void zpotrf( DenseMatrix<MT,SO>& A, char uplo );
//@}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense single precision matrix.
// \ingroup lapack
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the matrix \f$[0..\infty)\f$.
// \param a Pointer to the first element of the matrix.
// \param lda The total number of elements between two rows/columns of the matrix \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK spotrf() function. The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The resulting
// decomposition is stored within \a A: In case \a uplo is set to \c 'L' the result is stored in
// the lower part of the matrix and the upper part remains untouched, in case \a uplo is set to
// \c 'U' the result is stored in the upper part and the lower part remains untouched.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The decomposition finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//   - > 0: If info = i, the leading minor of order i is not positive definite.
//
// For more information on the spotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
inline void spotrf( char* uplo, int* n, float* a, int* lda, int* info )
{
   spotrf_( uplo, n, a, lda, info );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense double precision matrix.
// \ingroup lapack
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the matrix \f$[0..\infty)\f$.
// \param a Pointer to the first element of the matrix.
// \param lda The total number of elements between two rows/columns of the matrix \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK dpotrf() function. The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The resulting
// decomposition is stored within \a A: In case \a uplo is set to \c 'L' the result is stored in
// the lower part of the matrix and the upper part remains untouched, in case \a uplo is set to
// \c 'U' the result is stored in the upper part and the lower part remains untouched.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The decomposition finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//   - > 0: If info = i, the leading minor of order i is not positive definite.
//
// For more information on the dpotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
inline void dpotrf( char* uplo, int* n, double* a, int* lda, int* info )
{
   dpotrf_( uplo, n, a, lda, info );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense single precision complex
//        matrix.
// \ingroup lapack
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the matrix \f$[0..\infty)\f$.
// \param a Pointer to the first element of the matrix.
// \param lda The total number of elements between two rows/columns of the matrix \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK cpotrf() function. The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The resulting
// decomposition is stored within \a A: In case \a uplo is set to \c 'L' the result is stored in
// the lower part of the matrix and the upper part remains untouched, in case \a uplo is set to
// \c 'U' the result is stored in the upper part and the lower part remains untouched.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The decomposition finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//   - > 0: If info = i, the leading minor of order i is not positive definite.
//
// For more information on the cpotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
inline void cpotrf( char* uplo, int* n, complex<float>* a, int* lda, int* info )
{
   BLAZE_STATIC_ASSERT( sizeof( complex<float> ) == 2UL*sizeof( float ) );

   cpotrf_( uplo, n, reinterpret_cast<float*>( a ), lda, info );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense double precision complex
//        matrix.
// \ingroup lapack
//
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \param n The number of rows/columns of the matrix \f$[0..\infty)\f$.
// \param a Pointer to the first element of the matrix.
// \param lda The total number of elements between two rows/columns of the matrix \f$[0..\infty)\f$.
// \param info Return code of the function call.
// \return void
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK cpotrf() function. The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The resulting
// decomposition is stored within \a A: In case \a uplo is set to \c 'L' the result is stored in
// the lower part of the matrix and the upper part remains untouched, in case \a uplo is set to
// \c 'U' the result is stored in the upper part and the lower part remains untouched.
//
// The \a info argument provides feedback on the success of the function call:
//
//   - = 0: The decomposition finished successfully.
//   - < 0: If info = -i, the i-th argument had an illegal value.
//   - > 0: If info = i, the leading minor of order i is not positive definite.
//
// For more information on the zpotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
inline void zpotrf( char* uplo, int* n, complex<double>* a, int* lda, int* info )
{
   BLAZE_STATIC_ASSERT( sizeof( complex<double> ) == 2UL*sizeof( double ) );

   zpotrf_( uplo, n, reinterpret_cast<double*>( a ), lda, info );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense single precision matrix.
// \ingroup lapack
//
// \param A The matrix to be decomposed.
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \return void
// \exception std::invalid_argument Invalid argument provided.
// \exception std::invalid_argument Decomposition of singular matrix failed.
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK spotrf() function. Note that the function only works for general,
// non-adapted matrices with \c float element type. The attempt to call the function with any
// adapted matrix or matrices of any other element type results in a compile time error!\n
//
// The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The Cholesky
// decomposition fails if the given matrix \a A is not a positive definite matrix. In this case
// a \a std::std::invalid_argument exception is thrown.
//
// For more information on the spotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function does not provide any exception safety guarantee, i.e. in case an exception
// is thrown \a A may already have been modified.
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
template< typename MT  // Type of the dense matrix
        , bool SO >    // Storage order of the dense matrix
inline void spotrf( DenseMatrix<MT,SO>& A, char uplo )
{
   using boost::numeric_cast;

   BLAZE_CONSTRAINT_MUST_NOT_BE_ADAPTOR_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_NOT_BE_COMPUTATION_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_HAVE_MUTABLE_DATA_ACCESS( MT );
   BLAZE_CONSTRAINT_MUST_BE_FLOAT_TYPE( typename MT::ElementType );

   if( !IsSquare<MT>::value && !isSquare( ~A ) ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid non-square matrix provided" );
   }

   if( uplo != 'L' && uplo != 'U' ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid uplo argument provided" );
   }

   int n   ( boost::numeric_cast<int>( (~A).rows()    ) );
   int lda ( boost::numeric_cast<int>( (~A).spacing() ) );
   int info( 0 );

   if( IsRowMajorMatrix<MT>::value ) {
      ( uplo == 'L' )?( uplo = 'U' ):( uplo = 'L' );
   }

   spotrf( &uplo, &n, (~A).data(), &lda, &info );

   BLAZE_INTERNAL_ASSERT( info >= 0, "Invalid argument for Cholesky decomposition" );

   if( info > 0 ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Decomposition of non-positive-definite matrix failed" );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense double precision matrix.
// \ingroup lapack
//
// \param A The matrix to be decomposed.
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \return void
// \exception std::invalid_argument Invalid argument provided.
// \exception std::invalid_argument Decomposition of singular matrix failed.
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK dpotrf() function. Note that the function only works for general,
// non-adapted matrices with \c double element type. The attempt to call the function with any
// adapted matrix or matrices of any other element type results in a compile time error!\n
//
// The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The Cholesky
// decomposition fails if the given matrix \a A is not a positive definite matrix. In this case
// a \a std::std::invalid_argument exception is thrown.
//
// For more information on the dpotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function does not provide any exception safety guarantee, i.e. in case an exception
// is thrown \a A may already have been modified.
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
template< typename MT  // Type of the dense matrix
        , bool SO >    // Storage order of the dense matrix
inline void dpotrf( DenseMatrix<MT,SO>& A, char uplo )
{
   using boost::numeric_cast;

   BLAZE_CONSTRAINT_MUST_NOT_BE_ADAPTOR_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_NOT_BE_COMPUTATION_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_HAVE_MUTABLE_DATA_ACCESS( MT );
   BLAZE_CONSTRAINT_MUST_BE_DOUBLE_TYPE( typename MT::ElementType );

   if( !IsSquare<MT>::value && !isSquare( ~A ) ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid non-square matrix provided" );
   }

   if( uplo != 'L' && uplo != 'U' ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid uplo argument provided" );
   }

   int n   ( boost::numeric_cast<int>( (~A).rows()    ) );
   int lda ( boost::numeric_cast<int>( (~A).spacing() ) );
   int info( 0 );

   if( IsRowMajorMatrix<MT>::value ) {
      ( uplo == 'L' )?( uplo = 'U' ):( uplo = 'L' );
   }

   dpotrf( &uplo, &n, (~A).data(), &lda, &info );

   BLAZE_INTERNAL_ASSERT( info >= 0, "Invalid argument for Cholesky decomposition" );

   if( info > 0 ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Decomposition of non-positive-definite matrix failed" );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense single precision complex
//        matrix.
// \ingroup lapack
//
// \param A The matrix to be decomposed.
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \return void
// \exception std::invalid_argument Invalid argument provided.
// \exception std::invalid_argument Decomposition of singular matrix failed.
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK cpotrf() function. Note that the function only works for general,
// non-adapted matrices with \c complex<float> element type. The attempt to call the function with
// any adapted matrix or matrices of any other element type results in a compile time error!\n
//
// The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The Cholesky
// decomposition fails if the given matrix \a A is not a positive definite matrix. In this case
// a \a std::std::invalid_argument exception is thrown.
//
// For more information on the cpotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function does not provide any exception safety guarantee, i.e. in case an exception
// is thrown \a A may already have been modified.
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
template< typename MT  // Type of the dense matrix
        , bool SO >    // Storage order of the dense matrix
inline void cpotrf( DenseMatrix<MT,SO>& A, char uplo )
{
   using boost::numeric_cast;

   BLAZE_CONSTRAINT_MUST_NOT_BE_ADAPTOR_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_NOT_BE_COMPUTATION_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_HAVE_MUTABLE_DATA_ACCESS( MT );
   BLAZE_CONSTRAINT_MUST_BE_COMPLEX_TYPE( typename MT::ElementType );
   BLAZE_CONSTRAINT_MUST_BE_FLOAT_TYPE( typename MT::ElementType::value_type );

   if( !IsSquare<MT>::value && !isSquare( ~A ) ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid non-square matrix provided" );
   }

   if( uplo != 'L' && uplo != 'U' ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid uplo argument provided" );
   }

   int n   ( boost::numeric_cast<int>( (~A).rows()    ) );
   int lda ( boost::numeric_cast<int>( (~A).spacing() ) );
   int info( 0 );

   if( IsRowMajorMatrix<MT>::value ) {
      ( uplo == 'L' )?( uplo = 'U' ):( uplo = 'L' );
   }

   cpotrf( &uplo, &n, (~A).data(), &lda, &info );

   BLAZE_INTERNAL_ASSERT( info >= 0, "Invalid argument for Cholesky decomposition" );

   if( info > 0 ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Decomposition of non-positive-definite matrix failed" );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief LAPACK kernel for the Cholesky decomposition of the given dense double precision complex
//        matrix.
// \ingroup lapack
//
// \param A The matrix to be decomposed.
// \param uplo \c 'L' to use the lower part of the matrix, \c 'U' to use the upper part.
// \return void
// \exception std::invalid_argument Invalid argument provided.
// \exception std::invalid_argument Decomposition of singular matrix failed.
//
// This function performs the dense matrix Cholesky decomposition of a symmetric positive definite
// matrix based on the LAPACK zpotrf() function. Note that the function only works for general,
// non-adapted matrices with \c complex<double> element type. The attempt to call the function
// with any adapted matrix or matrices of any other element type results in a compile time error!\n
//
// The decomposition has the form

                      \f[ A = U**T * U, if uplo = 'U', \f] or\n
                      \f[ A = L * L**T, if uplo = 'L', \f]

// where \c U is an upper triangular matrix and \c L is a lower triangular matrix. The Cholesky
// decomposition fails if the given matrix \a A is not a positive definite matrix. In this case
// a \a std::std::invalid_argument exception is thrown.
//
// For more information on the zpotrf() function, see the LAPACK online documentation browser:
//
//        http://www.netlib.org/lapack/explore-html/
//
// \note This function does not provide any exception safety guarantee, i.e. in case an exception
// is thrown \a A may already have been modified.
// \note This function can only be used if the fitting LAPACK library is available and linked to
// the executable. Otherwise a call to this function will result in a linker error.
*/
template< typename MT  // Type of the dense matrix
        , bool SO >    // Storage order of the dense matrix
inline void zpotrf( DenseMatrix<MT,SO>& A, char uplo )
{
   using boost::numeric_cast;

   BLAZE_CONSTRAINT_MUST_NOT_BE_ADAPTOR_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_NOT_BE_COMPUTATION_TYPE( MT );
   BLAZE_CONSTRAINT_MUST_HAVE_MUTABLE_DATA_ACCESS( MT );
   BLAZE_CONSTRAINT_MUST_BE_COMPLEX_TYPE( typename MT::ElementType );
   BLAZE_CONSTRAINT_MUST_BE_DOUBLE_TYPE( typename MT::ElementType::value_type );

   if( !IsSquare<MT>::value && !isSquare( ~A ) ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid non-square matrix provided" );
   }

   if( uplo != 'L' && uplo != 'U' ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Invalid uplo argument provided" );
   }

   int n   ( boost::numeric_cast<int>( (~A).rows()    ) );
   int lda ( boost::numeric_cast<int>( (~A).spacing() ) );
   int info( 0 );

   if( IsRowMajorMatrix<MT>::value ) {
      ( uplo == 'L' )?( uplo = 'U' ):( uplo = 'L' );
   }

   zpotrf( &uplo, &n, (~A).data(), &lda, &info );

   BLAZE_INTERNAL_ASSERT( info >= 0, "Invalid argument for Cholesky decomposition" );

   if( info > 0 ) {
      BLAZE_THROW_INVALID_ARGUMENT( "Decomposition of non-positive-definite matrix failed" );
   }
}
//*************************************************************************************************

} // namespace blaze

#endif