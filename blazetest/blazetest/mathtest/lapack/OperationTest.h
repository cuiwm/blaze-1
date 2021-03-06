//=================================================================================================
/*!
//  \file blazetest/mathtest/lapack/OperationTest.h
//  \brief Header file for the LAPACK operation test
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

#ifndef _BLAZETEST_MATHTEST_LAPACK_OPERATIONTEST_H_
#define _BLAZETEST_MATHTEST_LAPACK_OPERATIONTEST_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <blaze/math/HermitianMatrix.h>
#include <blaze/math/LAPACK.h>
#include <blaze/math/LowerMatrix.h>
#include <blaze/math/shims/IsDefault.h>
#include <blaze/math/StaticMatrix.h>
#include <blaze/math/StaticVector.h>
#include <blaze/math/SymmetricMatrix.h>
#include <blaze/math/UniLowerMatrix.h>
#include <blaze/math/UniUpperMatrix.h>
#include <blaze/math/UpperMatrix.h>
#include <blazetest/system/LAPACK.h>


namespace blazetest {

namespace mathtest {

namespace lapack {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Auxiliary class for all tests of the LAPACK functionality.
//
// This class represents a test suite for LAPACK functionality wrapped by the Blaze library.
*/
class OperationTest
{
 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit OperationTest();
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

 private:
   //**Test functions******************************************************************************
   /*!\name Test functions */
   //@{
   template< typename Type > void testGeqrf();
   template< typename Type > void testGetrf();
   template< typename Type > void testSytrf();
   template< typename Type > void testHetrf();
   template< typename Type > void testPotrf();

   template< typename Type > void testGetri();
   template< typename Type > void testSytri();
   template< typename Type > void testHetri();
   template< typename Type > void testPotri();
   template< typename Type > void testTrtri();

   template< typename Type > void testGesv();
   //@}
   //**********************************************************************************************

   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   std::string test_;  //!< Label of the currently performed test.
   //@}
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the QR decomposition functions (geqrf).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the QR decomposition functions for various data types. In
// case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testGeqrf()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   test_ = "QR decomposition";

   {
      blaze::StaticMatrix<Type,2UL,5UL,blaze::rowMajor> A;
      randomize( A );

      blaze::StaticMatrix<Type,5UL,2UL,blaze::columnMajor> B( trans( A ) );

      blaze::StaticVector<Type,2UL,blaze::rowVector> tauA;
      blaze::StaticVector<Type,2UL,blaze::rowVector> tauB;

      blaze::geqrf( A, tauA.data() );
      blaze::geqrf( B, tauB.data() );

      if( A != trans( B ) || tauA != tauB ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: LU decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Row-major projectors:\n" << tauA << "\n"
             << "   Column-major decomposition:\n" << B << "\n"
             << "   Column-major projectors:\n" << tauB << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::StaticMatrix<Type,5UL,2UL,blaze::rowMajor> A;
      randomize( A );

      blaze::StaticMatrix<Type,2UL,5UL,blaze::columnMajor> B( trans( A ) );

      blaze::StaticVector<Type,2UL,blaze::rowVector> tauA;
      blaze::StaticVector<Type,2UL,blaze::rowVector> tauB;

      blaze::geqrf( A, tauA.data() );
      blaze::geqrf( B, tauB.data() );

      if( A != trans( B ) || tauA != tauB ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: LU decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Row-major projectors:\n" << tauA << "\n"
             << "   Column-major decomposition:\n" << B << "\n"
             << "   Column-major projectors:\n" << tauB << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the LU decomposition functions (getrf).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the LU decomposition functions for various data types. In
// case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testGetrf()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   test_ = "LU decomposition";

   {
      blaze::StaticMatrix<Type,2UL,5UL,blaze::rowMajor> A;
      randomize( A );

      blaze::StaticMatrix<Type,5UL,2UL,blaze::columnMajor> B( trans( A ) );

      blaze::StaticVector<int,2UL,blaze::columnVector> ipivA;
      blaze::StaticVector<int,2UL,blaze::columnVector> ipivB;

      blaze::getrf( A, ipivA.data() );
      blaze::getrf( B, ipivB.data() );

      if( A != trans( B ) || ipivA != ipivB ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: LU decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Row-major pivot elements:\n" << ipivA << "\n"
             << "   Column-major decomposition:\n" << B << "\n"
             << "   Column-major pivot elements:\n" << ipivB << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::StaticMatrix<Type,5UL,2UL,blaze::rowMajor> A;
      randomize( A );

      blaze::StaticMatrix<Type,2UL,5UL,blaze::columnMajor> B( trans( A ) );

      blaze::StaticVector<int,2UL,blaze::columnVector> ipivA;
      blaze::StaticVector<int,2UL,blaze::columnVector> ipivB;

      blaze::getrf( A, ipivA.data() );
      blaze::getrf( B, ipivB.data() );

      if( A != trans( B ) || ipivA != ipivB ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: LU decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Row-major pivot elements:\n" << ipivA << "\n"
             << "   Column-major decomposition:\n" << B << "\n"
             << "   Column-major pivot elements:\n" << ipivB << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the Bunch-Kaufman decomposition functions for symmetric matrices (sytrf).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the Bunch-Kaufman decomposition functions for symmetric
// indefinite matrices for various data types. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
template< typename Type >
void OperationTest::testSytrf()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   test_ = "Symmetric matrix decomposition";

   {
      blaze::SymmetricMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > S;
      randomize( S );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor>    A( S );
      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( S );

      blaze::StaticVector<int,3UL,blaze::rowVector> ipivA;
      blaze::StaticVector<int,3UL,blaze::rowVector> ipivB;

      blaze::sytrf( A, 'L', ipivA.data() );
      blaze::sytrf( B, 'U', ipivB.data() );

      if( A != trans( B ) || ipivA != ipivB ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Symmetric matrix decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Row-major pivot elements:\n" << ipivA << "\n"
             << "   Column-major decomposition:\n" << B << "\n"
             << "   Column-major pivot elements:\n" << ipivB << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the Bunch-Kaufman decomposition functions for Hermitian matrices (hetrf).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the Bunch-Kaufman decomposition functions for Hermitian
// indefinite matrices for various data types. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
template< typename Type >
void OperationTest::testHetrf()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   test_ = "Hermitian matrix decomposition";

   {
      blaze::HermitianMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > H;
      randomize( H );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor>    A( H );
      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( H );

      blaze::StaticVector<int,3UL,blaze::rowVector> ipivA;
      blaze::StaticVector<int,3UL,blaze::rowVector> ipivB;

      blaze::hetrf( A, 'L', ipivA.data() );
      blaze::hetrf( B, 'U', ipivB.data() );

      if( A != ctrans( B ) || ipivA != ipivB ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Hermitian matrix decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Row-major pivot elements:\n" << ipivA << "\n"
             << "   Column-major decomposition:\n" << B << "\n"
             << "   Column-major pivot elements:\n" << ipivB << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the Cholesky decomposition functions (potrf).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the Cholesky decomposition functions for various data types.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testPotrf()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   test_ = "Cholesky decomposition";

   {
      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> A( Type(1), Type( 2), Type( 4),
                                                           Type(2), Type(13), Type(23),
                                                           Type(4), Type(23), Type(77) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::potrf( A, 'L' );
      blaze::potrf( B, 'L' );

      if( A != B ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Cholesky decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Column-major decomposition:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> A( Type(1), Type( 2), Type( 4),
                                                           Type(2), Type(13), Type(23),
                                                           Type(4), Type(23), Type(77) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::potrf( A, 'U' );
      blaze::potrf( B, 'U' );

      if( A != B ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Cholesky decomposition failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Row-major decomposition:\n" << A << "\n"
             << "   Column-major decomposition:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the LU-based matrix inversion functions (getri).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the LU-based matrix inversion functions for various data
// types. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testGetri()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major LU-based matrix inversion";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> A;

      do {
         randomize( A );
      }
      while( blaze::isDefault( det( A ) ) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> Ainv( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::getrf( Ainv, ipiv.data() );
      blaze::getri( Ainv, ipiv.data() );

      if( !blaze::isIdentity( Ainv * A ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: LU-based matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << Ainv << "\n"
             << "   Ainv * A = " << ( Ainv * A ) << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major LU-based matrix inversion";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> A;

      do {
         randomize( A );
      }
      while( blaze::isDefault( det( A ) ) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> Ainv( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::getrf( Ainv, ipiv.data() );
      blaze::getri( Ainv, ipiv.data() );

      if( !blaze::isIdentity( Ainv * A ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: LU-based matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << Ainv << "\n"
             << "   Ainv * A = " << ( Ainv * A ) << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the Bunch-Kaufman-based matrix inversion functions for symmetric matrices (sytri).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the Bunch-Kaufman-based matrix inversion functions for
// symmetric indefinite matrices for various data types. In case an error is detected, a
// \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testSytri()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major symmetric matrix inversion (lower part)";

      blaze::SymmetricMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::sytrf( B, 'L', ipiv.data() );
      blaze::sytri( B, 'L', ipiv.data() );

      B(0,1) = B(1,0);
      B(0,2) = B(2,0);
      B(1,2) = B(2,1);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Symmetric matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major symmetric matrix inversion (upper part)";

      blaze::SymmetricMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::sytrf( B, 'U', ipiv.data() );
      blaze::sytri( B, 'U', ipiv.data() );

      B(1,0) = B(0,1);
      B(2,0) = B(0,2);
      B(2,1) = B(1,2);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Symmetric matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major symmetric matrix inversion (lower part)";

      blaze::SymmetricMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::sytrf( B, 'L', ipiv.data() );
      blaze::sytri( B, 'L', ipiv.data() );

      B(0,1) = B(1,0);
      B(0,2) = B(2,0);
      B(1,2) = B(2,1);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Symmetric matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major symmetric matrix inversion (upper part)";

      blaze::SymmetricMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::sytrf( B, 'U', ipiv.data() );
      blaze::sytri( B, 'U', ipiv.data() );

      B(1,0) = B(0,1);
      B(2,0) = B(0,2);
      B(2,1) = B(1,2);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Symmetric matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the Bunch-Kaufman-based matrix inversion functions for Hermitian matrices (hetri).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the Bunch-Kaufman-based matrix inversion functions for
// Hermitian indefinite matrices for various data types. In case an error is detected, a
// \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testHetri()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major Hermitian matrix inversion (lower part)";

      blaze::HermitianMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::hetrf( B, 'L', ipiv.data() );
      blaze::hetri( B, 'L', ipiv.data() );

      B(0,1) = conj( B(1,0) );
      B(0,2) = conj( B(2,0) );
      B(1,2) = conj( B(2,1) );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Hermitian matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major Hermitian matrix inversion (upper part)";

      blaze::HermitianMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::hetrf( B, 'U', ipiv.data() );
      blaze::hetri( B, 'U', ipiv.data() );

      B(1,0) = conj( B(0,1) );
      B(2,0) = conj( B(0,2) );
      B(2,1) = conj( B(1,2) );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Hermitian matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major Hermitian matrix inversion (lower part)";

      blaze::HermitianMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::hetrf( B, 'L', ipiv.data() );
      blaze::hetri( B, 'L', ipiv.data() );

      B(0,1) = conj( B(1,0) );
      B(0,2) = conj( B(2,0) );
      B(1,2) = conj( B(2,1) );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Hermitian matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major Hermitian matrix inversion (upper part)";

      blaze::HermitianMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );
      blaze::StaticVector<int,3UL,blaze::rowVector> ipiv;

      blaze::hetrf( B, 'U', ipiv.data() );
      blaze::hetri( B, 'U', ipiv.data() );

      B(1,0) = conj( B(0,1) );
      B(2,0) = conj( B(0,2) );
      B(2,1) = conj( B(1,2) );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Hermitian matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the Cholesky-based matrix inversion functions (potri).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the Cholesky-based matrix inversion functions for various
// data types. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testPotri()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major Cholesky-based matrix inversion (lower part)";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> A( Type(1), Type(1), Type(1),
                                                           Type(1), Type(2), Type(2),
                                                           Type(1), Type(2), Type(4) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );

      blaze::potrf( A, 'L' );
      blaze::potri( A, 'L' );

      A(0,1) = A(1,0);
      A(0,2) = A(2,0);
      A(1,2) = A(2,1);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Cholesky-based matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << A << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major Cholesky-based matrix inversion (upper part)";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> A( Type(1), Type(1), Type(1),
                                                           Type(1), Type(2), Type(2),
                                                           Type(1), Type(2), Type(4) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );

      blaze::potrf( A, 'U' );
      blaze::potri( A, 'U' );

      A(1,0) = A(0,1);
      A(2,0) = A(0,2);
      A(2,1) = A(1,2);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Cholesky-based matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << A << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major Cholesky-based matrix inversion (lower part)";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> A( Type(1), Type(1), Type(1),
                                                              Type(1), Type(2), Type(2),
                                                              Type(1), Type(2), Type(4) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::potrf( A, 'L' );
      blaze::potri( A, 'L' );

      A(0,1) = A(1,0);
      A(0,2) = A(2,0);
      A(1,2) = A(2,1);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Cholesky-based matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << A << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major Cholesky-based matrix inversion (upper part)";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> A( Type(1), Type(1), Type(1),
                                                              Type(1), Type(2), Type(2),
                                                              Type(1), Type(2), Type(4) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::potrf( A, 'U' );
      blaze::potri( A, 'U' );

      A(1,0) = A(0,1);
      A(2,0) = A(0,2);
      A(2,1) = A(1,2);

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Cholesky-based matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << A << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the triangular matrix inversion functions (trtri).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the triangular matrix inversion functions for various data
// types. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testTrtri()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major lower triangular matrix inversion";

      blaze::LowerMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );

      blaze::trtri( B, 'L', 'N' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Lower triangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major lower unitriangular matrix inversion";

      blaze::UniLowerMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );

      blaze::trtri( B, 'L', 'U' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Lower unitriangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major upper triangular matrix inversion";

      blaze::UpperMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );

      blaze::trtri( B, 'U', 'N' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Upper triangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Row-major upper unitriangular matrix inversion";

      blaze::UniUpperMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::rowMajor> B( A );

      blaze::trtri( B, 'U', 'U' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Upper unitriangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major lower triangular matrix inversion";

      blaze::LowerMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::trtri( B, 'L', 'N' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Lower triangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major lower unitriangular matrix inversion";

      blaze::UniLowerMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::trtri( B, 'L', 'U' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Lower unitriangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major upper triangular matrix inversion";

      blaze::UpperMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::trtri( B, 'U', 'N' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Upper triangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Column-major upper unitriangular matrix inversion";

      blaze::UniUpperMatrix< blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> > A;
      randomize( A );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> B( A );

      blaze::trtri( B, 'U', 'U' );

      if( !blaze::isIdentity( A * B ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Upper unitriangular matrix inversion failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   Result:\n" << B << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the general matrix linear system solver functions (gesv).
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the general matrix linear system solver functions for various
// data types. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename Type >
void OperationTest::testGesv()
{
#if BLAZETEST_MATHTEST_LAPACK_MODE

   {
      test_ = "Linear system of equations (single right-hand side)";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> A, LU;

      do {
         randomize( A );
      }
      while( blaze::isDefault( det( A ) ) );

      blaze::StaticVector<Type,3UL,blaze::columnVector> rhs, result;
      randomize( rhs );

      blaze::StaticVector<int,3UL,blaze::columnVector> ipiv;

      LU = A;
      result = rhs;

      blaze::gesv( LU, result, ipiv.data() );

      if( ( A * result ) != rhs ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Solving the linear system of equations failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   System matrix:\n" << A << "\n"
             << "   Right-hand side:\n" << rhs << "\n"
             << "   Result:\n" << result << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      test_ = "Linear system of equations (multiple right-hand side vectors)";

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> A, LU;

      do {
         randomize( A );
      }
      while( blaze::isDefault( det( A ) ) );

      blaze::StaticMatrix<Type,3UL,3UL,blaze::columnMajor> rhs, result;
      randomize( rhs );

      blaze::StaticVector<int,3UL,blaze::columnVector> ipiv;

      LU = A;
      result = rhs;

      blaze::gesv( LU, result, ipiv.data() );

      if( ( A * result ) != rhs ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Solving the linear system of equations failed\n"
             << " Details:\n"
             << "   Element type:\n"
             << "     " << typeid( Type ).name() << "\n"
             << "   System matrix:\n" << A << "\n"
             << "   Right-hand side:\n" << rhs << "\n"
             << "   Result:\n" << result << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

#endif
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Testing the LAPACK functionality.
//
// \return void
*/
void runTest()
{
   OperationTest();
}
//*************************************************************************************************




//=================================================================================================
//
//  MACRO DEFINITIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Macro for the execution of the LAPACK operation test.
*/
#define RUN_LAPACK_OPERATION_TEST \
   blazetest::mathtest::lapack::runTest()
/*! \endcond */
//*************************************************************************************************

} // namespace lapack

} // namespace mathtest

} // namespace blazetest

#endif
