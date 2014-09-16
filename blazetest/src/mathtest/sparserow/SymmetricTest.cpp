//=================================================================================================
/*!
//  \file src/mathtest/sparserow/SymmetricTest.cpp
//  \brief Source file for the symmetric SparseRow class test
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


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/CompressedVector.h>
#include <blaze/math/DynamicVector.h>
#include <blaze/math/Views.h>
#include <blazetest/mathtest/sparserow/SymmetricTest.h>


namespace blazetest {

namespace mathtest {

namespace sparserow {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the symmetric SparseRow class test.
//
// \exception std::runtime_error Operation error detected.
*/
SymmetricTest::SymmetricTest()
   : mat_ ( 4UL )
   , tmat_( 4UL )
{
   testConstructors();
   testAssignment();
   testAddAssign();
   testSubAssign();
   testMultAssign();
   testScaling();
   testSubscript();
   testIterator();
   testNonZeros();
   testReset();
   testClear();
   testSet();
   testInsert();
   testAppend();
   testErase();
   testReserve();
   testFind();
   testLowerBound();
   testUpperBound();
   testIsDefault();
   testIsSame();
   testSubvector();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the SparseRow constructors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all constructors of the SparseRow class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testConstructors()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow constructor";

      initialize();

      // 0th matrix row
      {
         RT row0 = row( mat_, 0UL );

         checkSize    ( row0, 4UL );
         checkNonZeros( row0, 0UL );

         if( row0[0] != 0 || row0[1] != 0 || row0[2] != 0 || row0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 0th sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 1st matrix row
      {
         RT row1 = row( mat_, 1UL );

         checkSize    ( row1, 4UL );
         checkNonZeros( row1, 2UL );

         if( row1[0] != 0 || row1[1] != 1 || row1[2] != 0 || row1[3] != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 1st sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row1 << "\n"
                << "   Expected result:\n( 0 1 0 -2 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 2nd matrix row
      {
         RT row2 = row( mat_, 2UL );

         checkSize    ( row2, 4UL );
         checkNonZeros( row2, 2UL );

         if( row2[0] != 0 || row2[1] != 0 || row2[2] != 3 || row2[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 2nd sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row2 << "\n"
                << "   Expected result:\n( 0 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 3rd matrix row
      {
         RT row3 = row( mat_, 3UL );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 3UL );

         if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 3rd sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -2 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow constructor";

      initialize();

      // 0th matrix row
      {
         TRT row0 = row( tmat_, 0UL );

         checkSize    ( row0, 4UL );
         checkNonZeros( row0, 0UL );

         if( row0[0] != 0 || row0[1] != 0 || row0[2] != 0 || row0[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 0th sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 1st matrix row
      {
         TRT row1 = row( tmat_, 1UL );

         checkSize    ( row1, 4UL );
         checkNonZeros( row1, 2UL );

         if( row1[0] != 0 || row1[1] != 1 || row1[2] != 0 || row1[3] != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 1st sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row1 << "\n"
                << "   Expected result:\n( 0 1 0 -2 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 2nd matrix row
      {
         TRT row2 = row( tmat_, 2UL );

         checkSize    ( row2, 4UL );
         checkNonZeros( row2, 2UL );

         if( row2[0] != 0 || row2[1] != 0 || row2[2] != 3 || row2[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 2nd sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row2 << "\n"
                << "   Expected result:\n( 0 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // 3rd matrix row
      {
         TRT row3 = row( tmat_, 3UL );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 3UL );

         if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setup of 3rd sparse row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -2 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseRow assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all assignment operators of the SparseRow class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testAssignment()
{
   //=====================================================================================
   // Row-major copy assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseRow copy assignment";

      initialize();

      RT row1 = row( mat_, 1UL );
      row1 = row( mat_, 2UL );

      checkSize    ( row1, 4UL );
      checkNonZeros( row1, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 8UL );

      if( row1[0] != 0 || row1[1] != 0 || row1[2] != 3 || row1[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) != 0 || mat_(1,2) != 3 || mat_(1,3) != 4 ||
          mat_(2,0) != 0 || mat_(2,1) != 3 || mat_(2,2) != 3 || mat_(2,3) != 4 ||
          mat_(3,0) != 0 || mat_(3,1) != 4 || mat_(3,2) != 4 || mat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  3  3  4 )\n"
                                     "(  0  4  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector assignment";

      initialize();

      RT row1 = row( mat_, 1UL );

      blaze::DynamicVector<int,blaze::rowVector> vec1( 4UL, 0 );
      vec1[1] = 8;
      vec1[3] = 9;

      row1 = vec1;

      checkSize    ( row1, 4UL );
      checkNonZeros( row1, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row1[0] != 0 || row1[1] != 8 || row1[2] != 0 || row1[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 8 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) != 8 || mat_(1,2) != 0 || mat_(1,3) != 9 ||
          mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) != 4 ||
          mat_(3,0) != 0 || mat_(3,1) != 9 || mat_(3,2) != 4 || mat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  8  0  9 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  9  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector assignment";

      initialize();

      RT row3 = row( mat_, 3UL );

      blaze::CompressedVector<int,blaze::rowVector> vec1( 4UL );
      vec1[3] = 9;

      row3 = vec1;

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 3UL );

      if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 0 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != 0 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 3 || mat_(2,3) != 0 ||
          mat_(3,0) != 0 || mat_(3,1) !=  0 || mat_(3,2) != 0 || mat_(3,3) != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0  0 )\n"
                                     "(  0  0  3  0 )\n"
                                     "(  0  0  0  9 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major copy assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseRow copy assignment";

      initialize();

      TRT row1 = row( tmat_, 1UL );
      row1 = row( tmat_, 2UL );

      checkSize    ( row1 , 4UL );
      checkNonZeros( row1 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 8UL );

      if( row1[0] != 0 || row1[1] != 0 || row1[2] != 3 || row1[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 0 || tmat_(1,2) != 3 || tmat_(1,3) != 4 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 3 || tmat_(2,2) != 3 || tmat_(2,3) != 4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 4 || tmat_(3,2) != 4 || tmat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  3  3  4 )\n"
                                     "(  0  4  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector assignment";

      initialize();

      TRT row1 = row( tmat_, 1UL );

      blaze::DynamicVector<int,blaze::rowVector> vec1( 4UL, 0 );
      vec1[1] = 8;
      vec1[3] = 9;

      row1 = vec1;

      checkSize    ( row1 , 4UL );
      checkNonZeros( row1 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row1[0] != 0 || row1[1] != 8 || row1[2] != 0 || row1[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 8 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 8 || tmat_(1,2) != 0 || tmat_(1,3) != 9 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 9 || tmat_(3,2) != 4 || tmat_(3,3) != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  8  0  9 )\n"
                                     "(  0  0  3  4 )\n"
                                     "(  0  9  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector assignment";

      initialize();

      TRT row3 = row( tmat_, 3UL );

      blaze::CompressedVector<int,blaze::rowVector> vec1( 4UL );
      vec1[3] = 9;

      row3 = vec1;

      checkSize    ( row3 , 4UL );
      checkNonZeros( row3 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 3UL );

      if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 0 0 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
          tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) != 0 ||
          tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != 0 || tmat_(3,2) != 0 || tmat_(3,3) != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0  0 )\n"
                                     "(  0  0  3  0 )\n"
                                     "(  0  0  0  9 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseRow addition assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the addition assignment operators of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testAddAssign()
{
   //=====================================================================================
   // Row-major SparseRow addition assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseRow addition assignment";

      initialize();

      RT row2 = row( mat_, 2UL );
      row2 += row( mat_, 3UL );

      checkSize    ( row2  , 4UL );
      checkNonZeros( row2  , 3UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 9UL );

      if( row2[0] != 0 || row2[1] != -2 || row2[2] != 7 || row2[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 -2 7 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != -2 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) != -2 || mat_(2,2) !=  7 || mat_(2,3) !=  9 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=  9 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1 -2 -2 )\n"
                                     "(  0 -2  7  9 )\n"
                                     "(  0 -2  9  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector addition assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector addition assignment";

      initialize();

      RT row2 = row( mat_, 2UL );

      blaze::DynamicVector<int,blaze::rowVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      row2 += vec;

      checkSize    ( row2,  4UL );
      checkNonZeros( row2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( row2[0] != 2 || row2[1] != -4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  2 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != -4 || mat_(1,3) != -2 ||
          mat_(2,0) != 2 || mat_(2,1) != -4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector addition assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector addition assignment";

      initialize();

      RT row2 = row( mat_, 2UL );

      blaze::CompressedVector<int,blaze::rowVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      row2 += vec;

      checkSize    ( row2,  4UL );
      checkNonZeros( row2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( row2[0] != 2 || row2[1] != -4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  2 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != -4 || mat_(1,3) != -2 ||
          mat_(2,0) != 2 || mat_(2,1) != -4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseRow addition assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseRow addition assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );
      row2 += row( tmat_, 3UL );

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 3UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 9UL );

      if( row2[0] != 0 || row2[1] != -2 || row2[2] != 7 || row2[3] != 9 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 -2 7 9 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != -2 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) != -2 || tmat_(2,2) !=  7 || tmat_(2,3) !=  9 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=  9 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1 -2 -2 )\n"
                                     "(  0 -2  7  9 )\n"
                                     "(  0 -2  9  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector addition assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector addition assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::rowVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      row2 += vec;

      checkSize    ( row2 ,  4UL );
      checkNonZeros( row2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( row2[0] != 2 || row2[1] != -4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != -4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 2 || tmat_(2,1) != -4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector addition assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector addition assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::rowVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      row2 += vec;

      checkSize    ( row2 ,  4UL );
      checkNonZeros( row2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( row2[0] != 2 || row2[1] != -4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 2 -4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != -4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 2 || tmat_(2,1) != -4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Addition assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  2  0 )\n"
                                     "( 0  1 -4 -2 )\n"
                                     "( 2 -4  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseRow subtraction assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the subtraction assignment operators of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testSubAssign()
{
   //=====================================================================================
   // Row-major SparseRow subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseRow subtraction assignment";

      initialize();

      RT row2 = row( mat_, 2UL );
      row2 -= row( mat_, 3UL );

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 9UL );

      if( row2[0] != 0 || row2[1] != 2 || row2[2] != -1 || row2[3] != -1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 2 -1 -1 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  2 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  2 || mat_(2,2) != -1 || mat_(2,3) != -1 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != -1 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  2 -2 )\n"
                                     "(  0  2 -1 -1 )\n"
                                     "(  0 -2 -1  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector subtraction assignment";

      initialize();

      RT row2 = row( mat_, 2UL );

      blaze::DynamicVector<int,blaze::rowVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      row2 -= vec;

      checkSize    ( row2,  4UL );
      checkNonZeros( row2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( row2[0] != -2 || row2[1] != 4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -2 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  4 || mat_(1,3) != -2 ||
          mat_(2,0) != -2 || mat_(2,1) !=  4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector subtraction assignment";

      initialize();

      RT row2 = row( mat_, 2UL );

      blaze::CompressedVector<int,blaze::rowVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      row2 -= vec;

      checkSize    ( row2,  4UL );
      checkNonZeros( row2,  4UL );
      checkRows    ( mat_,  4UL );
      checkColumns ( mat_,  4UL );
      checkNonZeros( mat_, 11UL );

      if( row2[0] != -2 || row2[1] != 4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -2 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  4 || mat_(1,3) != -2 ||
          mat_(2,0) != -2 || mat_(2,1) !=  4 || mat_(2,2) !=  3 || mat_(2,3) !=  4 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) !=  4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseRow subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseRow subtraction assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );
      row2 -= row( tmat_, 3UL );

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 3UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 9UL );

      if( row2[0] != 0 || row2[1] != 2 || row2[2] != -1 || row2[3] != -1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 2 -1 -1 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  2 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  2 || tmat_(2,2) != -1 || tmat_(2,3) != -1 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != -1 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  2 -2 )\n"
                                     "(  0  2 -1 -1 )\n"
                                     "(  0 -2 -1  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector subtraction assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::rowVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[1] = -4;

      row2 -= vec;

      checkSize    ( row2 ,  4UL );
      checkNonZeros( row2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( row2[0] != -2 || row2[1] != 4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -2 || tmat_(2,1) !=  4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector subtraction assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector subtraction assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::rowVector> vec( 4UL );
      vec[0] =  2;
      vec[1] = -4;

      row2 -= vec;

      checkSize    ( row2 ,  4UL );
      checkNonZeros( row2 ,  4UL );
      checkRows    ( tmat_,  4UL );
      checkColumns ( tmat_,  4UL );
      checkNonZeros( tmat_, 11UL );

      if( row2[0] != -2 || row2[1] != 4 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -2 4 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -2 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  4 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -2 || tmat_(2,1) !=  4 || tmat_(2,2) !=  3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) !=  4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subtraction assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -2  0 )\n"
                                     "(  0  1  4 -2 )\n"
                                     "( -2  4  3  4 )\n"
                                     "(  0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseRow multiplication assignment operators.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the multiplication assignment operators of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testMultAssign()
{
   //=====================================================================================
   // Row-major SparseRow multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major SparseRow multiplication assignment";

      initialize();

      RT row2 = row( mat_, 2UL );
      row2 *= row( mat_, 3UL );

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 12 || row2[3] != 20 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 12 20 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 12 || mat_(2,3) != 20 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 20 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0 12 20 )\n"
                                     "(  0 -2 20  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major dense vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major dense vector multiplication assignment";

      initialize();

      RT row2 = row( mat_, 2UL );

      blaze::DynamicVector<int,blaze::rowVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[2] = -4;

      row2 *= vec;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != -12 || row2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=   0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=   0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != -12 || mat_(2,3) !=  0 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=   0 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major sparse vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Row-major sparse vector multiplication assignment";

      initialize();

      RT row2 = row( mat_, 2UL );

      blaze::CompressedVector<int,blaze::rowVector> vec( 4UL );
      vec[0] =  2;
      vec[2] = -4;

      row2 *= vec;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 5UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != -12 || row2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=   0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=   0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != -12 || mat_(2,3) !=  0 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) !=   0 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseRow multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major SparseRow multiplication assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );
      row2 *= row( tmat_, 3UL );

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 12 || row2[3] != 20 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 12 20 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 12 || tmat_(2,3) != 20 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 20 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0 12 20 )\n"
                                     "(  0 -2 20  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major dense vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major dense vector multiplication assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      blaze::DynamicVector<int,blaze::rowVector> vec( 4UL, 0 );
      vec[0] =  2;
      vec[2] = -4;

      row2 *= vec;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 5UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != -12 || row2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=   0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=   0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != -12 || tmat_(2,3) !=  0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=   0 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major sparse vector multiplication assignment
   //=====================================================================================

   {
      test_ = "Column-major sparse vector multiplication assignment";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      blaze::CompressedVector<int,blaze::rowVector> vec( 4UL );
      vec[0] =  2;
      vec[2] = -4;

      row2 *= vec;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 5UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != -12 || row2[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 -12 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=   0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=   0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != -12 || tmat_(2,3) !=  0 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) !=   0 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Multiplication assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0   0  0 )\n"
                                     "(  0  1   0 -2 )\n"
                                     "(  0  0 -12  0 )\n"
                                     "(  0 -2   0  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of all SparseRow (self-)scaling operations.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of all available ways to scale an instance of the SparseRow
// class template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testScaling()
{
   //=====================================================================================
   // Row-major self-scaling (v*=2)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v*=2)";

      initialize();

      RT row2 = row( mat_, 2UL );

      row2 *= 3;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 9 || row2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  9 || mat_(2,3) != 12 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 12 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  9 12 )\n"
                                     "(  0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=v*2)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=v*2)";

      initialize();

      RT row2 = row( mat_, 2UL );

      row2 = row2 * 3;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 9 || row2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  9 || mat_(2,3) != 12 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 12 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  9 12 )\n"
                                     "(  0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=2*v)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=2*v)";

      initialize();

      RT row2 = row( mat_, 2UL );

      row2 = 3 * row2;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 9 || row2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  9 || mat_(2,3) != 12 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 12 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  9 12 )\n"
                                     "(  0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v/=s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v/=s)";

      initialize();

      RT row2 = row( mat_, 2UL );

      row2 /= 0.5;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 6 || row2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 6 || mat_(2,3) !=  8 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  6  8 )\n"
                                     "(  0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major self-scaling (v=v/s)
   //=====================================================================================

   {
      test_ = "Row-major self-scaling (v=v/s)";

      initialize();

      RT row2 = row( mat_, 2UL );

      row2 = row2 / 0.5;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 6 || row2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 6 || mat_(2,3) !=  8 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0  0  0 )\n"
                                     "(  0  1  0 -2 )\n"
                                     "(  0  0  6  8 )\n"
                                     "(  0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major SparseRow::scale()
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::scale()";

      initialize();

      // Integral scaling the 3rd row
      {
         RT row3 = row( mat_, 3UL );
         row3.scale( 3 );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 3UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 7UL );

         if( row3[0] != 0 || row3[1] != -6 || row3[2] != 12 || row3[3] != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  0 || mat_(1,3) != -6 ||
             mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) !=  3 || mat_(2,3) != 12 ||
             mat_(3,0) != 0 || mat_(3,1) != -6 || mat_(3,2) != 12 || mat_(3,3) != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0 -6 )\n"
                                        "( 0  0  3 12 )\n"
                                        "( 0 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Floating point scaling the 3rd row
      {
         RT row3 = row( mat_, 3UL );
         row3.scale( 0.5 );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 3UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 7UL );

         if( row3[0] != 0 || row3[1] != -3 || row3[2] != 6 || row3[3] != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -3 6 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 0 || mat_(1,3) != -3 ||
             mat_(2,0) != 0 || mat_(2,1) !=  0 || mat_(2,2) != 3 || mat_(2,3) !=  6 ||
             mat_(3,0) != 0 || mat_(3,1) != -3 || mat_(3,2) != 6 || mat_(3,3) !=  7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0 -3 )\n"
                                        "( 0  0  3  6 )\n"
                                        "( 0 -3  6  7 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v*=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v*=s)";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      row2 *= 3;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 9 || row2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  9 || tmat_(2,3) != 12 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 12 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  9 12 )\n"
                                     "( 0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=v*s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=v*s)";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      row2 = row2 * 3;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 9 || row2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  9 || tmat_(2,3) != 12 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 12 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  9 12 )\n"
                                     "( 0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=s*v)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=s*v)";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      row2 = 3 * row2;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 9 || row2[3] != 12 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 9 12 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  9 || tmat_(2,3) != 12 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 12 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  9 12 )\n"
                                     "( 0 -2 12  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v/=s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v/=s)";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      row2 /= 0.5;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 6 || row2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 6 || tmat_(2,3) !=  8 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  6  8 )\n"
                                     "( 0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major self-scaling (v=v/s)
   //=====================================================================================

   {
      test_ = "Column-major self-scaling (v=v/s)";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      row2 = row2 / 0.5;

      checkSize    ( row2 , 4UL );
      checkNonZeros( row2 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 7UL );

      if( row2[0] != 0 || row2[1] != 0 || row2[2] != 6 || row2[3] != 8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 0 6 8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 0 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 6 || tmat_(2,3) !=  8 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Failed self-scaling operation\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  0 -2 )\n"
                                     "( 0  0  6  8 )\n"
                                     "( 0 -2  8  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major SparseRow::scale()
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::scale()";

      initialize();

      // Integral scaling the 3rd row
      {
         TRT row3 = row( tmat_, 3UL );
         row3.scale( 3 );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 3UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 7UL );

         if( row3[0] != 0 || row3[1] != -6 || row3[2] != 12 || row3[3] != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  0 || tmat_(1,3) != -6 ||
             tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) !=  3 || tmat_(2,3) != 12 ||
             tmat_(3,0) != 0 || tmat_(3,1) != -6 || tmat_(3,2) != 12 || tmat_(3,3) != 15 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n(  0  0  0  0 )\n"
                                        "(  0  1  0 -6 )\n"
                                        "( -2  0 -3 12 )\n"
                                        "(  7 -6 12 15 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Floating point scaling the 3rd row
      {
         TRT row3 = row( tmat_, 3UL );
         row3.scale( 0.5 );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 3UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 7UL );

         if( row3[0] != 0 || row3[1] != -3 || row3[2] != 6 || row3[3] != 7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -3 6 7 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 0 || tmat_(1,3) != -3 ||
             tmat_(2,0) != 0 || tmat_(2,1) !=  0 || tmat_(2,2) != 3 || tmat_(2,3) !=  6 ||
             tmat_(3,0) != 0 || tmat_(3,1) != -3 || tmat_(3,2) != 6 || tmat_(3,3) !=  7 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Integral scale operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0 -3 )\n"
                                        "( 0  0 -3  6 )\n"
                                        "( 0 -3  6  7 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseRow subscript operator.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of adding and accessing elements via the subscript operator
// of the SparseRow class template. In case an error is detected, a \a std::runtime_error
// exception is thrown.
*/
void SymmetricTest::testSubscript()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::operator[]";

      initialize();

      RT row2 = row( mat_, 2UL );

      // Assignment to the element at index 1
      row2[1] = 9;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != 0 || row2[1] != 9 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 9 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 9 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  9 || mat_(2,2) != 3 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 2
      row2[2] = 0;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );

      if( row2[0] != 0 || row2[1] != 9 || row2[2] != 0 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 9 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) != 9 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  9 || mat_(2,2) != 0 || mat_(2,3) !=  4 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != 4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 3
      row2[3] = -8;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );

      if( row2[0] != 0 || row2[1] != 9 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) != 0 || mat_(0,1) !=  0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
          mat_(1,0) != 0 || mat_(1,1) !=  1 || mat_(1,2) !=  9 || mat_(1,3) != -2 ||
          mat_(2,0) != 0 || mat_(2,1) !=  9 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) != 0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0 -8 )\n"
                                     "( 0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Addition assignment to the element at index 0
      row2[0] += -3;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != 9 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  9 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) !=  9 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  9 -2 )\n"
                                     "( -3  9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Subtraction assignment to the element at index 1
      row2[1] -= 6;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != 3 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 3 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) !=  3 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) !=  3 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  3 -2 )\n"
                                     "( -3  3  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Multiplication assignment to the element at index 1
      row2[1] *= -3;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != -9 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 -9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) != -9 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) != -9 || mat_(2,2) !=  0 || mat_(2,3) != -8 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -8 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Division assignment to the element at index 3
      row2[3] /= 2;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != -9 || row2[2] != 0 || row2[3] != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 -9 0 -4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat_(0,0) !=  0 || mat_(0,1) !=  0 || mat_(0,2) != -3 || mat_(0,3) !=  0 ||
          mat_(1,0) !=  0 || mat_(1,1) !=  1 || mat_(1,2) != -9 || mat_(1,3) != -2 ||
          mat_(2,0) != -3 || mat_(2,1) != -9 || mat_(2,2) !=  0 || mat_(2,3) != -4 ||
          mat_(3,0) !=  0 || mat_(3,1) != -2 || mat_(3,2) != -4 || mat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << mat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -4 )\n"
                                     "(  0 -2 -4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::operator[]";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      // Assignment to the element at index 1
      row2[1] = 9;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != 0 || row2[1] != 9 || row2[2] != 3 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 9 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  9 || tmat_(2,2) != 3 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  3  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 2
      row2[2] = 0;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );

      if( row2[0] != 0 || row2[1] != 9 || row2[2] != 0 || row2[3] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 9 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) != 9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  9 || tmat_(2,2) != 0 || tmat_(2,3) !=  4 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != 4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0  4 )\n"
                                     "( 0 -2  4  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Assignment to the element at index 3
      row2[3] = -8;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 2UL );

      if( row2[0] != 0 || row2[1] != 9 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( 0 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) != 0 || tmat_(0,1) !=  0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
          tmat_(1,0) != 0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != 0 || tmat_(2,1) !=  9 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) != 0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n( 0  0  0  0 )\n"
                                     "( 0  1  9 -2 )\n"
                                     "( 0  9  0 -8 )\n"
                                     "( 0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Addition assignment to the element at index 0
      row2[0] += -3;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != 9 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) !=  9 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  9 -2 )\n"
                                     "( -3  9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Subtraction assignment to the element at index 1
      row2[1] -= 6;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != 3 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 3 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) !=  3 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) !=  3 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1  3 -2 )\n"
                                     "( -3  3  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Multiplication assignment to the element at index 1
      row2[1] *= -3;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != -9 || row2[2] != 0 || row2[3] != -8 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 -9 0 -8 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) != -9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) != -9 || tmat_(2,2) !=  0 || tmat_(2,3) != -8 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -8 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -8 )\n"
                                     "(  0 -2 -8  5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Division assignment to the element at index 3
      row2[3] /= 2;

      checkSize    ( row2, 4UL );
      checkNonZeros( row2, 3UL );

      if( row2[0] != -3 || row2[1] != -9 || row2[2] != 0 || row2[3] != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row2 << "\n"
             << "   Expected result:\n( -3 -9 0 -4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( tmat_(0,0) !=  0 || tmat_(0,1) !=  0 || tmat_(0,2) != -3 || tmat_(0,3) !=  0 ||
          tmat_(1,0) !=  0 || tmat_(1,1) !=  1 || tmat_(1,2) != -9 || tmat_(1,3) != -2 ||
          tmat_(2,0) != -3 || tmat_(2,1) != -9 || tmat_(2,2) !=  0 || tmat_(2,3) != -4 ||
          tmat_(3,0) !=  0 || tmat_(3,1) != -2 || tmat_(3,2) != -4 || tmat_(3,3) !=  5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << tmat_ << "\n"
             << "   Expected result:\n(  0  0 -3  0 )\n"
                                     "(  0  1 -9 -2 )\n"
                                     "( -3 -9  0 -4 )\n"
                                     "(  0 -2 -4  5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the SparseRow iterator implementation.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the iterator implementation of the SparseRow class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testIterator()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      initialize();

      // Testing the Iterator default constructor
      {
         test_ = "Row-major Iterator default constructor";

         RT::Iterator it = RT::Iterator();

         if( it != RT::Iterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing the ConstIterator default constructor
      {
         test_ = "Row-major ConstIterator default constructor";

         RT::ConstIterator it = RT::ConstIterator();

         if( it != RT::ConstIterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Row-major Iterator/ConstIterator conversion";

         RT row2 = row( mat_, 2UL );
         RT::ConstIterator it( begin( row2 ) );

         if( it == end( row2 ) || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st row via Iterator
      {
         test_ = "Row-major Iterator subtraction";

         RT row1 = row( mat_, 1UL );
         const size_t number( end( row1 ) - begin( row1 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 2nd row via ConstIterator
      {
         test_ = "Row-major ConstIterator subtraction";

         RT row2 = row( mat_, 2UL );
         const size_t number( cend( row2 ) - cbegin( row2 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Row-major read-only access via ConstIterator";

         RT row2 = row( mat_, 2UL );
         RT::ConstIterator it ( cbegin( row2 ) );
         RT::ConstIterator end( cend( row2 ) );

         if( it == end || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || it->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Row-major assignment via Iterator";

         RT row3 = row( mat_, 3UL );
         int value = 6;

         for( RT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it = value++;
         }

         if( row3[0] != 0 || row3[1] != 6 || row3[2] != 7 || row3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != 0 || mat_(1,3) != 6 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) != 7 ||
             mat_(3,0) != 0 || mat_(3,1) != 6 || mat_(3,2) != 7 || mat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Row-major addition assignment via Iterator";

         RT row3 = row( mat_, 3UL );
         int value = 2;

         for( RT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it += value++;
         }

         if( row3[0] != 0 || row3[1] != 8 || row3[2] != 10 || row3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  8 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  3 || mat_(2,3) != 10 ||
             mat_(3,0) != 0 || mat_(3,1) != 8 || mat_(3,2) != 10 || mat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  8 )\n"
                                        "( 0  0  3 10 )\n"
                                        "( 0  8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Row-major subtraction assignment via Iterator";

         RT row3 = row( mat_, 3UL );
         int value = 2;

         for( RT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it -= value++;
         }

         if( row3[0] != 0 || row3[1] != 6 || row3[2] != 7 || row3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) != 0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != 0 || mat_(1,3) != 6 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) != 7 ||
             mat_(3,0) != 0 || mat_(3,1) != 6 || mat_(3,2) != 7 || mat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Row-major multiplication assignment via Iterator";

         RT row3 = row( mat_, 3UL );
         int value = 1;

         for( RT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it *= value++;
         }

         if( row3[0] != 0 || row3[1] != 6 || row3[2] != 14 || row3[3] != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) !=  0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) !=  0 || mat_(1,3) !=  6 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) !=  3 || mat_(2,3) != 14 ||
             mat_(3,0) != 0 || mat_(3,1) != 6 || mat_(3,2) != 14 || mat_(3,3) != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3 14 )\n"
                                        "( 0  6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Row-major division assignment via Iterator";

         RT row3 = row( mat_, 3UL );

         for( RT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it /= 2;
         }

         if( row3[0] != 0 || row3[1] != 3 || row3[2] != 7 || row3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 3 7 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( mat_(0,0) != 0 || mat_(0,1) != 0 || mat_(0,2) != 0 || mat_(0,3) !=  0 ||
             mat_(1,0) != 0 || mat_(1,1) != 1 || mat_(1,2) != 0 || mat_(1,3) !=  3 ||
             mat_(2,0) != 0 || mat_(2,1) != 0 || mat_(2,2) != 3 || mat_(2,3) !=  7 ||
             mat_(3,0) != 0 || mat_(3,1) != 3 || mat_(3,2) != 7 || mat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << mat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  3 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  3  7 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      initialize();

      // Testing the Iterator default constructor
      {
         test_ = "Column-major Iterator default constructor";

         TRT::Iterator it = TRT::Iterator();

         if( it != TRT::Iterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing the ConstIterator default constructor
      {
         test_ = "Column-major ConstIterator default constructor";

         TRT::ConstIterator it = TRT::ConstIterator();

         if( it != TRT::ConstIterator() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator default constructor\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing conversion from Iterator to ConstIterator
      {
         test_ = "Column-major Iterator/ConstIterator conversion";

         TRT row2 = row( tmat_, 2UL );
         TRT::ConstIterator it( begin( row2 ) );

         if( it == end( row2 ) || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Failed iterator conversion detected\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 1st row via Iterator
      {
         test_ = "Column-major Iterator subtraction";

         TRT row1 = row( tmat_, 1UL );
         const size_t number( end( row1 ) - begin( row1 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Counting the number of elements in 2nd row via ConstIterator
      {
         test_ = "Column-major ConstIterator subtraction";

         TRT row2 = row( tmat_, 2UL );
         const size_t number( cend( row2 ) - cbegin( row2 ) );

         if( number != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid number of elements detected\n"
                << " Details:\n"
                << "   Number of elements         : " << number << "\n"
                << "   Expected number of elements: 4\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing read-only access via ConstIterator
      {
         test_ = "Column-major read-only access via ConstIterator";

         TRT row2 = row( tmat_, 2UL );
         TRT::ConstIterator it ( cbegin( row2 ) );
         TRT::ConstIterator end( cend( row2 ) );

         if( it == end || it->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid initial iterator detected\n";
            throw std::runtime_error( oss.str() );
         }

         ++it;

         if( it == end || it->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator pre-increment failed\n";
            throw std::runtime_error( oss.str() );
         }

         it++;

         if( it != end ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Iterator post-increment failed\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing assignment via Iterator
      {
         test_ = "Column-major assignment via Iterator";

         TRT row3 = row( tmat_, 3UL );
         int value = 6;

         for( TRT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it = value++;
         }

         if( row3[0] != 0 || row3[1] != 6 || row3[2] != 7 || row3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) != 6 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 7 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 6 || tmat_(3,2) != 7 || tmat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing addition assignment via Iterator
      {
         test_ = "Column-major addition assignment via Iterator";

         TRT row3 = row( tmat_, 3UL );
         int value = 2;

         for( TRT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it += value++;
         }

         if( row3[0] != 0 || row3[1] != 8 || row3[2] != 10 || row3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  8 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  3 || tmat_(2,3) != 10 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 8 || tmat_(3,2) != 10 || tmat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  8 )\n"
                                        "( 0  0  3 10 )\n"
                                        "( 0  8 10 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing subtraction assignment via Iterator
      {
         test_ = "Column-major subtraction assignment via Iterator";

         TRT row3 = row( tmat_, 3UL );
         int value = 2;

         for( TRT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it -= value++;
         }

         if( row3[0] != 0 || row3[1] != 6 || row3[2] != 7 || row3[3] != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 6 7 8 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) != 0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) != 6 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) != 7 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 6 || tmat_(3,2) != 7 || tmat_(3,3) != 8 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  6  7  8 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing multiplication assignment via Iterator
      {
         test_ = "Column-major multiplication assignment via Iterator";

         TRT row3 = row( tmat_, 3UL );
         int value = 1;

         for( TRT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it *= value++;
         }

         if( row3[0] != 0 || row3[1] != 6 || row3[2] != 14 || row3[3] != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) !=  0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) !=  0 || tmat_(1,3) !=  6 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) !=  3 || tmat_(2,3) != 14 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 6 || tmat_(3,2) != 14 || tmat_(3,3) != 24 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  6 )\n"
                                        "( 0  0  3 14 )\n"
                                        "( 0  6 14 24 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Testing division assignment via Iterator
      {
         test_ = "Column-major division assignment via Iterator";

         TRT row3 = row( tmat_, 3UL );

         for( TRT::Iterator it=begin( row3 ); it!=end( row3 ); ++it ) {
            *it /= 2;
         }

         if( row3[0] != 0 || row3[1] != 3 || row3[2] != 7 || row3[3] != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 3 7 12 )\n";
            throw std::runtime_error( oss.str() );
         }

         if( tmat_(0,0) != 0 || tmat_(0,1) != 0 || tmat_(0,2) != 0 || tmat_(0,3) !=  0 ||
             tmat_(1,0) != 0 || tmat_(1,1) != 1 || tmat_(1,2) != 0 || tmat_(1,3) !=  3 ||
             tmat_(2,0) != 0 || tmat_(2,1) != 0 || tmat_(2,2) != 3 || tmat_(2,3) !=  7 ||
             tmat_(3,0) != 0 || tmat_(3,1) != 3 || tmat_(3,2) != 7 || tmat_(3,3) != 12 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Assignment via iterator failed\n"
                << " Details:\n"
                << "   Result:\n" << tmat_ << "\n"
                << "   Expected result:\n( 0  0  0  0 )\n"
                                        "( 0  1  0  3 )\n"
                                        "( 0  0  3  7 )\n"
                                        "( 0  3  7 12 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c nonZeros() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c nonZeros() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testNonZeros()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::nonZeros()";

      initialize();

      // Initialization check
      RT row3 = row( mat_, 3UL );

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 3UL );

      if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 -2 4 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse row
      row3[2] = 0;

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 2UL );

      if( row3[0] != 0 || row3[1] != -2 || row3[2] != 0 || row3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse matrix
      mat_(3,0) = 5;

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 3UL );

      if( row3[0] != 5 || row3[1] != -2 || row3[2] != 0 || row3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 5 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::nonZeros()";

      initialize();

      // Initialization check
      TRT row3 = row( tmat_, 3UL );

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 3UL );

      if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 -2 4 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse row
      row3[2] = 0;

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 2UL );

      if( row3[0] != 0 || row3[1] != -2 || row3[2] != 0 || row3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Changing the number of non-zeros via the sparse matrix
      tmat_(3,0) = 5;

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 3UL );

      if( row3[0] != 5 || row3[1] != -2 || row3[2] != 0 || row3[3] != 5 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Function call operator failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 5 -2 0 5 )\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reset() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reset() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testReset()
{
   using blaze::reset;


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::reset()";

      initialize();

      // Resetting a single element in row 3
      {
         RT row3 = row( mat_, 3UL );
         reset( row3[1] );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 2UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 5UL );

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 3rd row
      {
         RT row3 = row( mat_, 3UL );
         reset( row3 );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 2UL );

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::reset()";

      initialize();

      // Resetting a single element in row 3
      {
         TRT row3 = row( tmat_, 3UL );
         reset( row3[1] );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 2UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 5UL );

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Resetting the 3rd row
      {
         TRT row3 = row( tmat_, 3UL );
         reset( row3 );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 2UL );

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Reset operation of 3rd row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c clear() function with the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c clear() function with the SparseRow class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testClear()
{
   using blaze::clear;


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major clear() function";

      initialize();

      // Clearing a single element in row 3
      {
         RT row3 = row( mat_, 3UL );
         clear( row3[1] );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 2UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 5UL );

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Clear operation failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major clear() function";

      initialize();

      // Clearing a single element in row 3
      {
         TRT row3 = row( tmat_, 3UL );
         clear( row3[1] );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 2UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 5UL );

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Clear operation failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c set() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c set() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testSet()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::set()";

      initialize();

      RT row0 = row( mat_, 0UL );

      // Setting a non-zero element at the end of the row
      {
         RT::Iterator pos = row0.set( 3UL, 1 );

         checkSize    ( row0, 4UL );
         checkNonZeros( row0, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 0 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the beginning of the row
      {
         RT::Iterator pos = row0.set( 0UL, 2 );

         checkSize    ( row0,  4UL );
         checkNonZeros( row0,  2UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the center of the row
      {
         RT::Iterator pos = row0.set( 2UL, 3 );

         checkSize    ( row0,  4UL );
         checkNonZeros( row0,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 3 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting an already existing element
      {
         RT::Iterator pos = row0.set( 3UL, 4 );

         checkSize    ( row0,  4UL );
         checkNonZeros( row0,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 12UL );

         if( pos->value() != 4 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 3 || row0[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::set()";

      initialize();

      TRT row0 = row( tmat_, 0UL );

      // Setting a non-zero element at the end of the row
      {
         TRT::Iterator pos = row0.set( 3UL, 1 );

         checkSize    ( row0 , 4UL );
         checkNonZeros( row0 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 0 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the beginning of the row
      {
         TRT::Iterator pos = row0.set( 0UL, 2 );

         checkSize    ( row0 ,  4UL );
         checkNonZeros( row0 ,  2UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting a non-zero element at the center of the row
      {
         TRT::Iterator pos = row0.set( 2UL, 3 );

         checkSize    ( row0 ,  4UL );
         checkNonZeros( row0 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 3 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Setting an already existing element
      {
         TRT::Iterator pos = row0.set( 3UL, 4 );

         checkSize    ( row0 ,  4UL );
         checkNonZeros( row0 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 12UL );

         if( pos->value() != 4 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 3 || row0[3] != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Setting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 3 4 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c insert() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c insert() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testInsert()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::insert()";

      initialize();

      RT row0 = row( mat_, 0UL );

      // Inserting a non-zero element at the end of the row
      {
         RT::Iterator pos = row0.insert( 3UL, 1 );

         checkSize    ( row0, 4UL );
         checkNonZeros( row0, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 0 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the beginning of the row
      {
         RT::Iterator pos = row0.insert( 0UL, 2 );

         checkSize    ( row0,  4UL );
         checkNonZeros( row0,  2UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the center of the row
      {
         RT::Iterator pos = row0.insert( 2UL, 3 );

         checkSize    ( row0,  4UL );
         checkNonZeros( row0,  3UL );
         checkRows    ( mat_,  4UL );
         checkColumns ( mat_,  4UL );
         checkNonZeros( mat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 3 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to insert an already existing element
      try {
         row0.insert( 3UL, 4 );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Inserting an existing element succeeded\n"
             << " Details:\n"
             << "   Result:\n" << row0 << "\n"
             << "   Expected result:\n( 2 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::insert()";

      initialize();

      TRT row0 = row( tmat_, 0UL );

      // Inserting a non-zero element at the end of the row
      {
         TRT::Iterator pos = row0.insert( 3UL, 1 );

         checkSize    ( row0 , 4UL );
         checkNonZeros( row0 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 9UL );

         if( pos->value() != 1 || pos->index() != 3UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 1\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 0 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 0 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the beginning of the row
      {
         TRT::Iterator pos = row0.insert( 0UL, 2 );

         checkSize    ( row0 ,  4UL );
         checkNonZeros( row0 ,  2UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 10UL );

         if( pos->value() != 2 || pos->index() != 0UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 2\n"
                << "   Expected index: 0\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 0 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 0 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Inserting a non-zero element at the center of the row
      {
         TRT::Iterator pos = row0.insert( 2UL, 3 );

         checkSize    ( row0 ,  4UL );
         checkNonZeros( row0 ,  3UL );
         checkRows    ( tmat_,  4UL );
         checkColumns ( tmat_,  4UL );
         checkNonZeros( tmat_, 12UL );

         if( pos->value() != 3 || pos->index() != 2UL ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 3\n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( row0[0] != 2 || row0[1] != 0 || row0[2] != 3 || row0[3] != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Inserting a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row0 << "\n"
                << "   Expected result:\n( 2 0 3 1 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to insert an already existing element
      try {
         row0.insert( 3UL, 4 );

         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Inserting an existing element succeeded\n"
             << " Details:\n"
             << "   Result:\n" << row0 << "\n"
             << "   Expected result:\n( 2 0 3 4 )\n";
         throw std::runtime_error( oss.str() );
      }
      catch( std::invalid_argument& ) {}
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c append() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c append() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testAppend()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::append()";

      MT mat( 9UL );

      RT row1 = row( mat, 1UL );
      row1.reserve( 4UL );

      // Appending one non-zero element
      row1.append( 1UL, 1 );

      checkSize    ( row1, 9UL );
      checkCapacity( row1, 4UL );
      checkNonZeros( row1, 1UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 1UL );

      if( row1[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 1 0 0 0 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }

      // Appending three more non-zero elements
      row1.append( 3UL, 2 );
      row1.append( 4UL, 3 );
      row1.append( 8UL, 4 );

      checkSize    ( row1, 9UL );
      checkCapacity( row1, 4UL );
      checkNonZeros( row1, 4UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 7UL );

      if( row1[1] != 1 || row1[3] != 2 || row1[4] != 3 || row1[8] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Append operation failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 1 0 2 3 0 0 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 || mat(1,3) != 2 || mat(1,4) != 3 || mat(1,8) != 4 ||
          mat(3,1) != 2 || mat(4,1) != 3 || mat(8,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::append()";

      TMT mat( 9UL );

      TRT row1 = row( mat, 1UL );
      row1.reserve( 4UL );

      // Appending one non-zero element
      row1.append( 1UL, 1 );

      checkSize    ( row1, 9UL );
      checkCapacity( row1, 4UL );
      checkNonZeros( row1, 1UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 1UL );

      if( row1[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Initialization failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 1 0 0 0 0 0 0 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }

      // Appending three more non-zero elements
      row1.append( 3UL, 2 );
      row1.append( 4UL, 3 );
      row1.append( 8UL, 4 );

      checkSize    ( row1, 9UL );
      checkCapacity( row1, 4UL );
      checkNonZeros( row1, 4UL );
      checkRows    ( mat , 9UL );
      checkColumns ( mat , 9UL );
      checkNonZeros( mat , 7UL );

      if( row1[1] != 1 || row1[3] != 2 || row1[4] != 3 || row1[8] != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Append operation failed\n"
             << " Details:\n"
             << "   Result:\n" << row1 << "\n"
             << "   Expected result:\n( 0 1 0 2 3 0 0 0 4 )\n";
         throw std::runtime_error( oss.str() );
      }

      if( mat(1,1) != 1 || mat(1,3) != 2 || mat(1,4) != 3 || mat(1,8) != 4 ||
          mat(3,1) != 2 || mat(4,1) != 3 || mat(8,1) != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Assignment failed\n"
             << " Details:\n"
             << "   Result:\n" << mat << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c erase() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c erase() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testErase()
{
   //=====================================================================================
   // Row-major index-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::erase( size_t )";

      initialize();

      RT row3 = row( mat_, 3UL );

      // Erasing the non-zero element at the end of the row
      row3.erase( 3UL );

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 2UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 6UL );

      if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 -2 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the non-zero element at the beginning of the row
      row3.erase( 1UL );

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 4UL );

      if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Trying to erase an already erased element
      row3.erase( 3UL );

      checkSize    ( row3, 4UL );
      checkNonZeros( row3, 1UL );
      checkRows    ( mat_, 4UL );
      checkColumns ( mat_, 4UL );
      checkNonZeros( mat_, 4UL );

      if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Row-major iterator-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::erase( Iterator )";

      initialize();

      RT row3 = row( mat_, 3UL );

      // Erasing the non-zero element at the end of the row
      {
         RT::Iterator pos = row3.erase( row3.find( 3UL ) );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 2UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 6UL );

         if( pos != row3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -2 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the non-zero element at the beginning of the row
      {
         RT::Iterator pos = row3.erase( row3.find( 1UL ) );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 4UL );

         if( pos->value() != 4 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an already erased element
      {
         RT::Iterator pos = row3.erase( row3.find( 3UL ) );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 4UL );

         if( pos != row3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Row-major iterator-range-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::erase( Iterator, Iterator )";

      initialize();

      // Erasing the 2nd row
      {
         RT row2 = row( mat_, 2UL );

         RT::Iterator pos = row2.erase( row2.begin(), row2.end() );

         checkSize    ( row2, 4UL );
         checkNonZeros( row2, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 4UL );

         if( pos != row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row2[0] != 0 || row2[1] != 0 || row2[2] != 0 || row2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing the row failed\n"
                << " Details:\n"
                << "   Result:\n" << row2 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the first half of the 3th row
      {
         RT row3 = row( mat_, 3UL );

         RT::Iterator pos = row3.erase( row3.begin(), row3.find( 3UL ) );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 2UL );

         if( pos->value() != 5 || pos->index() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 0 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the second half of the 4th row
      {
         RT row3 = row( mat_, 3UL );

         RT::Iterator pos = row3.erase( row3.find( 3UL ), row3.end() );

         checkSize    ( row3, 4UL );
         checkNonZeros( row3, 0UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 1UL );

         if( pos != row3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an empty range
      {
         RT row1 = row( mat_, 1UL );

         RT::Iterator pos = row1.erase( row1.find( 1UL ), row1.find( 1UL ) );

         checkSize    ( row1, 4UL );
         checkNonZeros( row1, 1UL );
         checkRows    ( mat_, 4UL );
         checkColumns ( mat_, 4UL );
         checkNonZeros( mat_, 1UL );

         if( pos != row1.find( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the given end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row1[0] != 0 || row1[1] != 1 || row1[2] != 0 || row1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing an empty range failed\n"
                << " Details:\n"
                << "   Result:\n" << row1 << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major index-based erase function
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::erase( size_t )";

      initialize();

      TRT row3 = row( tmat_, 3UL );

      // Erasing the non-zero element at the end of the row
      row3.erase( 3UL );

      checkSize    ( row3 , 4UL );
      checkNonZeros( row3 , 2UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 6UL );

      if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 -2 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Erasing the non-zero element at the beginning of the row
      row3.erase( 1UL );

      checkSize    ( row3 , 4UL );
      checkNonZeros( row3 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 4UL );

      if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a non-zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }

      // Trying to erase an already erased element
      row3.erase( 3UL );

      checkSize    ( row3 , 4UL );
      checkNonZeros( row3 , 1UL );
      checkRows    ( tmat_, 4UL );
      checkColumns ( tmat_, 4UL );
      checkNonZeros( tmat_, 4UL );

      if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Erasing a zero element failed\n"
             << " Details:\n"
             << "   Result:\n" << row3 << "\n"
             << "   Expected result:\n( 0 0 4 0 )\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major iterator-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::erase( Iterator )";

      initialize();

      TRT row3 = row( tmat_, 3UL );

      // Erasing the non-zero element at the end of the row
      {
         TRT::Iterator pos = row3.erase( row3.find( 3UL ) );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 2UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 6UL );

         if( pos != row3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != -2 || row3[2] != 4 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 -2 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the non-zero element at the beginning of the row
      {
         TRT::Iterator pos = row3.erase( row3.find( 1UL ) );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 4UL );

         if( pos->value() != 4 || pos->index() != 2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 4n"
                << "   Expected index: 2\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a non-zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an already erased element
      {
         TRT::Iterator pos = row3.erase( row3.find( 3UL ) );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 4UL );

         if( pos != row3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 4 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a zero element failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 4 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major iterator-range-based erase function
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::erase( Iterator, Iterator )";

      initialize();

      // Erasing the 2nd row
      {
         TRT row2 = row( tmat_, 2UL );

         TRT::Iterator pos = row2.erase( row2.begin(), row2.end() );

         checkSize    ( row2 , 4UL );
         checkNonZeros( row2 , 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 4UL );

         if( pos != row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row2[0] != 0 || row2[1] != 0 || row2[2] != 0 || row2[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing the row failed\n"
                << " Details:\n"
                << "   Result:\n" << row2 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the first half of the 3th row
      {
         TRT row3 = row( tmat_, 3UL );

         TRT::Iterator pos = row3.erase( row3.begin(), row3.find( 3UL ) );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 2UL );

         if( pos->value() != 5 || pos->index() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Value: " << pos->value() << "\n"
                << "   Index: " << pos->index() << "\n"
                << "   Expected value: 5\n"
                << "   Expected index: 3\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 5 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 0 5 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Erasing the second half of the 4th row
      {
         TRT row3 = row( tmat_, 3UL );

         TRT::Iterator pos = row3.erase( row3.find( 3UL ), row3.end() );

         checkSize    ( row3 , 4UL );
         checkNonZeros( row3 , 0UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 1UL );

         if( pos != row3.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row3[0] != 0 || row3[1] != 0 || row3[2] != 0 || row3[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing a partial row failed\n"
                << " Details:\n"
                << "   Result:\n" << row3 << "\n"
                << "   Expected result:\n( 0 0 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Trying to erase an empty range
      {
         TRT row1 = row( tmat_, 1UL );

         TRT::Iterator pos = row1.erase( row1.find( 1UL ), row1.find( 1UL ) );

         checkSize    ( row1 , 4UL );
         checkNonZeros( row1 , 1UL );
         checkRows    ( tmat_, 4UL );
         checkColumns ( tmat_, 4UL );
         checkNonZeros( tmat_, 1UL );

         if( pos != row1.find( 1UL ) ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid iterator returned\n"
                << " Details:\n"
                << "   Expected result: the given end() iterator\n";
            throw std::runtime_error( oss.str() );
         }

         if( row1[0] != 0 || row1[1] != 1 || row1[2] != 0 || row1[3] != 0 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Erasing an empty range failed\n"
                << " Details:\n"
                << "   Result:\n" << row1 << "\n"
                << "   Expected result:\n( 0 1 0 0 )\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c reserve() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c reserve() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testReserve()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::reserve()";

      MT mat( 20UL );

      RT row0 = row( mat, 0UL );

      // Increasing the capacity of the row
      row0.reserve( 10UL );

      checkSize    ( row0, 20UL );
      checkCapacity( row0, 10UL );
      checkNonZeros( row0,  0UL );

      // Further increasing the capacity of the row
      row0.reserve( 15UL );

      checkSize    ( row0, 20UL );
      checkCapacity( row0, 15UL );
      checkNonZeros( row0,  0UL );
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::reserve()";

      TMT mat( 20UL );

      TRT row0 = row( mat, 0UL );

      // Increasing the capacity of the row
      row0.reserve( 10UL );

      checkSize    ( row0, 20UL );
      checkCapacity( row0, 10UL );
      checkNonZeros( row0,  0UL );

      // Further increasing the capacity of the row
      row0.reserve( 15UL );

      checkSize    ( row0, 20UL );
      checkCapacity( row0, 15UL );
      checkNonZeros( row0,  0UL );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c find() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c find() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testFind()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::find()";

      initialize();

      RT row2 = row( mat_, 2UL );

      // Searching for the first element
      {
         RT::Iterator pos = row2.find( 2UL );

         if( pos == row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 3\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the second element
      {
         RT::Iterator pos = row2.find( 3UL );

         if( pos == row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 4\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for a non-existing non-zero element
      {
         RT::Iterator pos = row2.find( 1UL );

         if( pos != row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Non-existing element could be found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 0\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::find()";

      initialize();

      TRT row2 = row( tmat_, 2UL );

      // Searching for the first element
      {
         TRT::Iterator pos = row2.find( 2UL );

         if( pos == row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 2 || pos->value() != 3 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 3\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for the second element
      {
         TRT::Iterator pos = row2.find( 3UL );

         if( pos == row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Element could not be found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != 4 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 4\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Searching for a non-existing non-zero element
      {
         TRT::Iterator pos = row2.find( 1UL );

         if( pos != row2.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Non-existing element could be found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 0\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c lowerBound() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c lowerBound() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testLowerBound()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::lowerBound()";

      initialize();

      RT row1 = row( mat_, 1UL );

      // Determining the lower bound for index 0
      {
         RT::Iterator pos = row1.lowerBound( 0UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 1
      {
         RT::Iterator pos = row1.lowerBound( 1UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 2
      {
         RT::Iterator pos = row1.lowerBound( 2UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::lowerBound()";

      initialize();

      TRT row1 = row( tmat_, 1UL );

      // Determining the lower bound for index 0
      {
         TRT::Iterator pos = row1.lowerBound( 0UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 1
      {
         TRT::Iterator pos = row1.lowerBound( 1UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the lower bound for index 2
      {
         TRT::Iterator pos = row1.lowerBound( 2UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Lower bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 2\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c upperBound() member function of the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c upperBound() member function of the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testUpperBound()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major SparseRow::upperBound()";

      initialize();

      RT row1 = row( mat_, 1UL );

      // Determining the upper bound for index 0
      {
         RT::Iterator pos = row1.upperBound( 0UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 1
      {
         RT::Iterator pos = row1.upperBound( 1UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 2
      {
         RT::Iterator pos = row1.upperBound( 2UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major SparseRow::upperBound()";

      initialize();

      TRT row1 = row( tmat_, 1UL );

      // Determining the upper bound for index 0
      {
         TRT::Iterator pos = row1.upperBound( 0UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 1 || pos->value() != 1 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 1\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = 1\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 1
      {
         TRT::Iterator pos = row1.upperBound( 1UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // Determining the upper bound for index 2
      {
         TRT::Iterator pos = row1.upperBound( 2UL );

         if( pos == row1.end() ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Upper bound could not be determined\n"
                << " Details:\n"
                << "   Required index = 0\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
         else if( pos->index() != 3 || pos->value() != -2 ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Wrong element found\n"
                << " Details:\n"
                << "   Required index = 3\n"
                << "   Found index    = " << pos->index() << "\n"
                << "   Expected value = -2\n"
                << "   Value at index = " << pos->value() << "\n"
                << "   Current row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isDefault() function with the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isDefault() function with the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testIsDefault()
{
   using blaze::isDefault;


   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isDefault() function";

      initialize();

      // isDefault with default row
      {
         RT row0 = row( mat_, 0UL );

         if( isDefault( row0[1] ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row element: " << row0[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( row0 ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row:\n" << row0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default row
      {
         RT row1 = row( mat_, 1UL );

         if( isDefault( row1[1] ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row element: " << row1[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( row1 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isDefault() function";

      initialize();

      // isDefault with default row
      {
         TRT row0 = row( tmat_, 0UL );

         if( isDefault( row0[1] ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row element: " << row0[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( row0 ) != true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row:\n" << row0 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isDefault with non-default row
      {
         TRT row1 = row( tmat_, 1UL );

         if( isDefault( row1[1] ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row element: " << row1[1] << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( isDefault( row1 ) != false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isDefault evaluation\n"
                << " Details:\n"
                << "   Row:\n" << row1 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isSame() function with the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isSame() function with the SparseRow class template.
// In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testIsSame()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major isSame() function";

      // isSame with matching rows
      {
         RT row1 = row( mat_, 1UL );
         RT row2 = row( mat_, 1UL );

         if( blaze::isSame( row1, row2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching rows
      {
         RT row1 = row( mat_, 1UL );
         RT row2 = row( mat_, 2UL );

         if( blaze::isSame( row1, row2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with row and matching subvector
      {
         typedef blaze::SparseSubvector<RT>  SubvectorType;

         RT row1 = row( mat_, 1UL );
         SubvectorType sv = subvector( row1, 0UL, 4UL );

         if( blaze::isSame( row1, sv ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, row1 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with row and non-matching subvector (different size)
      {
         typedef blaze::SparseSubvector<RT>  SubvectorType;

         RT row1 = row( mat_, 1UL );
         SubvectorType sv = subvector( row1, 0UL, 3UL );

         if( blaze::isSame( row1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, row1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with row and non-matching subvector (different offset)
      {
         typedef blaze::SparseSubvector<RT>  SubvectorType;

         RT row1 = row( mat_, 1UL );
         SubvectorType sv = subvector( row1, 1UL, 3UL );

         if( blaze::isSame( row1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, row1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching rows on submatrices
      {
         typedef blaze::SparseSubmatrix<MT>       SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         RowType row2 = row( sm, 1UL );

         if( blaze::isSame( row1, row2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching rows on submatrices
      {
         typedef blaze::SparseSubmatrix<MT>       SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 0UL );
         RowType row2 = row( sm, 1UL );

         if( blaze::isSame( row1, row2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching row subvectors on submatrices
      {
         typedef blaze::SparseSubmatrix<MT>       SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;
         typedef blaze::SparseSubvector<RowType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         SubvectorType sv1 = subvector( row1, 0UL, 2UL );
         SubvectorType sv2 = subvector( row1, 0UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching row subvectors on submatrices (different size)
      {
         typedef blaze::SparseSubmatrix<MT>       SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;
         typedef blaze::SparseSubvector<RowType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         SubvectorType sv1 = subvector( row1, 0UL, 2UL );
         SubvectorType sv2 = subvector( row1, 0UL, 3UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching row subvectors on submatrices (different offset)
      {
         typedef blaze::SparseSubmatrix<MT>       SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;
         typedef blaze::SparseSubvector<RowType>  SubvectorType;

         SubmatrixType sm = submatrix( mat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         SubvectorType sv1 = subvector( row1, 0UL, 2UL );
         SubvectorType sv2 = subvector( row1, 1UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major isSame() function";

      // isSame with matching rows
      {
         TRT row1 = row( tmat_, 1UL );
         TRT row2 = row( tmat_, 1UL );

         if( blaze::isSame( row1, row2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching rows
      {
         TRT row1 = row( tmat_, 1UL );
         TRT row2 = row( tmat_, 2UL );

         if( blaze::isSame( row1, row2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with row and matching subvector
      {
         typedef blaze::SparseSubvector<TRT>  SubvectorType;

         TRT row1 = row( tmat_, 1UL );
         SubvectorType sv = subvector( row1, 0UL, 4UL );

         if( blaze::isSame( row1, sv ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, row1 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with row and non-matching subvector (different size)
      {
         typedef blaze::SparseSubvector<TRT>  SubvectorType;

         TRT row1 = row( tmat_, 1UL );
         SubvectorType sv = subvector( row1, 0UL, 3UL );

         if( blaze::isSame( row1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, row1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with row and non-matching subvector (different offset)
      {
         typedef blaze::SparseSubvector<TRT>  SubvectorType;

         TRT row1 = row( tmat_, 1UL );
         SubvectorType sv = subvector( row1, 1UL, 3UL );

         if( blaze::isSame( row1, sv ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }

         if( blaze::isSame( sv, row1 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   Sparse row:\n" << row1 << "\n"
                << "   Sparse subvector:\n" << sv << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching rows on submatrices
      {
         typedef blaze::SparseSubmatrix<TMT>      SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         RowType row2 = row( sm, 1UL );

         if( blaze::isSame( row1, row2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching rows on submatrices
      {
         typedef blaze::SparseSubmatrix<TMT>      SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 0UL );
         RowType row2 = row( sm, 1UL );

         if( blaze::isSame( row1, row2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First row:\n" << row1 << "\n"
                << "   Second row:\n" << row2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with matching row subvectors on submatrices
      {
         typedef blaze::SparseSubmatrix<TMT>      SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;
         typedef blaze::SparseSubvector<RowType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         SubvectorType sv1 = subvector( row1, 0UL, 2UL );
         SubvectorType sv2 = subvector( row1, 0UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == false ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching row subvectors on submatrices (different size)
      {
         typedef blaze::SparseSubmatrix<TMT>      SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;
         typedef blaze::SparseSubvector<RowType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         SubvectorType sv1 = subvector( row1, 0UL, 2UL );
         SubvectorType sv2 = subvector( row1, 0UL, 3UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }

      // isSame with non-matching row subvectors on submatrices (different offset)
      {
         typedef blaze::SparseSubmatrix<TMT>      SubmatrixType;
         typedef blaze::SparseRow<SubmatrixType>  RowType;
         typedef blaze::SparseSubvector<RowType>  SubvectorType;

         SubmatrixType sm = submatrix( tmat_, 1UL, 1UL, 2UL, 3UL );
         RowType row1 = row( sm, 1UL );
         SubvectorType sv1 = subvector( row1, 0UL, 2UL );
         SubvectorType sv2 = subvector( row1, 1UL, 2UL );

         if( blaze::isSame( sv1, sv2 ) == true ) {
            std::ostringstream oss;
            oss << " Test: " << test_ << "\n"
                << " Error: Invalid isSame evaluation\n"
                << " Details:\n"
                << "   First subvector:\n" << sv1 << "\n"
                << "   Second subvector:\n" << sv2 << "\n";
            throw std::runtime_error( oss.str() );
         }
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c subvector() function with the SparseRow class template.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c subvector() function used with the SparseRow class
// template. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void SymmetricTest::testSubvector()
{
   //=====================================================================================
   // Row-major matrix tests
   //=====================================================================================

   {
      test_ = "Row-major subvector() function";

      initialize();

      typedef blaze::SparseSubvector<RT>  SubvectorType;

      RT row1 = row( mat_, 1UL );
      SubvectorType sv = subvector( row1, 0UL, 4UL );

      if( sv[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator access failed\n"
             << " Details:\n"
             << "   Result: " << sv[1] << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }

      if( sv.begin()->value() != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << sv.begin()->value() << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Column-major matrix tests
   //=====================================================================================

   {
      test_ = "Column-major subvector() function";

      initialize();

      typedef blaze::SparseSubvector<TRT>  SubvectorType;

      TRT row1 = row( tmat_, 1UL );
      SubvectorType sv = subvector( row1, 0UL, 4UL );

      if( sv[1] != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Subscript operator access failed\n"
             << " Details:\n"
             << "   Result: " << sv[1] << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }

      if( sv.begin()->value() != 1 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Iterator access failed\n"
             << " Details:\n"
             << "   Result: " << sv.begin()->value() << "\n"
             << "   Expected result: 1\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Initialization of all member matrices.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function initializes all member matrices to specific predetermined values.
*/
void SymmetricTest::initialize()
{
   // Initializing the symmetric row-major matrix
   mat_.reset();
   mat_(1,1) =  1;
   mat_(1,3) = -2;
   mat_(2,2) =  3;
   mat_(2,3) =  4;
   mat_(3,3) =  5;

   // Initializing the symmetric column-major matrix
   tmat_.reset();
   tmat_(1,1) =  1;
   tmat_(1,3) = -2;
   tmat_(2,2) =  3;
   tmat_(2,3) =  4;
   tmat_(3,3) =  5;
}
//*************************************************************************************************

} // namespace sparserow

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running symmetric SparseRow class test..." << std::endl;

   try
   {
      RUN_SPARSEROW_CLASS_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during symmetric SparseRow class test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
