//=================================================================================================
/*!
//  \file src/mathtest/lapack/OperationTest.cpp
//  \brief Source file for the LAPACK operation test
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
#include <blaze/util/Complex.h>
#include <blazetest/mathtest/lapack/OperationTest.h>


namespace blazetest {

namespace mathtest {

namespace lapack {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the OperationTest class test.
//
// \exception std::runtime_error Operation error detected.
*/
OperationTest::OperationTest()
{
   testGeqrf< float                  >();
   testGeqrf< double                 >();
   testGeqrf< blaze::complex<float>  >();
   testGeqrf< blaze::complex<double> >();

   testGetrf< float                  >();
   testGetrf< double                 >();
   testGetrf< blaze::complex<float>  >();
   testGetrf< blaze::complex<double> >();

   testSytrf< float                  >();
   testSytrf< double                 >();
   testSytrf< blaze::complex<float>  >();
   testSytrf< blaze::complex<double> >();

   testHetrf< blaze::complex<float>  >();
   testHetrf< blaze::complex<double> >();

   testPotrf< float                  >();
   testPotrf< double                 >();
   testPotrf< blaze::complex<float>  >();
   testPotrf< blaze::complex<double> >();

   testGetri< float                  >();
   testGetri< double                 >();
   testGetri< blaze::complex<float>  >();
   testGetri< blaze::complex<double> >();

   testSytri< float                  >();
   testSytri< double                 >();
   testSytri< blaze::complex<float>  >();
   testSytri< blaze::complex<double> >();

   testHetri< blaze::complex<float>  >();
   testHetri< blaze::complex<double> >();

   testPotri< float                  >();
   testPotri< double                 >();
   testPotri< blaze::complex<float>  >();
   testPotri< blaze::complex<double> >();

   testTrtri< float                  >();
   testTrtri< double                 >();
   testTrtri< blaze::complex<float>  >();
   testTrtri< blaze::complex<double> >();

   testGesv< float                  >();
   testGesv< double                 >();
   testGesv< blaze::complex<float>  >();
   testGesv< blaze::complex<double> >();
}
//*************************************************************************************************

} // namespace lapack

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
   std::cout << "   Running LAPACK operation test..." << std::endl;

   try
   {
      RUN_LAPACK_OPERATION_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during LAPACK operation test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
