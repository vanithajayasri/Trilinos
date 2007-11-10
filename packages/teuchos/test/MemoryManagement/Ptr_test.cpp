// @HEADER
// ***********************************************************************
// 
//                    Teuchos: Common Tools Package
//                 Copyright (2004) Sandia Corporation
// 
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
// 
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//  
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
// Questions? Contact Michael A. Heroux (maherou@sandia.gov) 
// 
// ***********************************************************************
// @HEADER

#include "TestClasses.hpp"
#include "Teuchos_Ptr.hpp"
#include "Teuchos_GlobalMPISession.hpp"
#include "Teuchos_CommandLineProcessor.hpp"
#include "Teuchos_VerboseObject.hpp"
#include "Teuchos_StandardCatchMacros.hpp"
#include "Teuchos_Version.hpp"
#include "Teuchos_Assert.hpp"
#include "Teuchos_getConst.hpp"
#include "Teuchos_as.hpp"


int main( int argc, char* argv[] ) {

  using Teuchos::Ptr;
  using Teuchos::ptr;
  using Teuchos::constPtr;
  using Teuchos::outArg;
  using Teuchos::optInArg;
  using Teuchos::constOptInArg;
  using Teuchos::CommandLineProcessor;
	
	bool success = true;
 
  Teuchos::GlobalMPISession mpiSession(&argc,&argv);
  //const int procRank = Teuchos::GlobalMPISession::getRank();
 
  Teuchos::RCP<Teuchos::FancyOStream>
    out = Teuchos::VerboseObjectBase::getDefaultOStream();
 
	try {
    
    //
		// Read options from the commandline
    //

    CommandLineProcessor clp(false); // Don't throw exceptions

		CommandLineProcessor::EParseCommandLineReturn parse_return = clp.parse(argc,argv);

		if ( parse_return != CommandLineProcessor::PARSE_SUCCESSFUL ) {
			*out << "\nEnd Result: TEST FAILED" << std::endl;
			return parse_return;
		}

    *out << std::endl << Teuchos::Teuchos_Version() << std::endl;

    *out << "\nTesting Teuchos::Ptr class ...\n";
 
    {
      // Test null construction
      Ptr<A> a_ptr;
      TEUCHOS_ASSERT_EQUALITY( 0, a_ptr.get() );
#ifdef TEUCHOS_DEBUG
      try {
        A &a = *a_ptr; // Should throw!
        a.A_g();
        TEST_FOR_EXCEPTION( true, std::logic_error,
          "Error, Ptr::operator*() on null Ptr should have thrown exception!" );
      }
      catch( const Teuchos::NullReferenceError &except ) {
        // Caught expected exception!
      }
#endif
#ifdef TEUCHOS_DEBUG
      try {
        a_ptr->A_g(); // Should throw!
        TEST_FOR_EXCEPTION( true, std::logic_error,
          "Error, Ptr::operator->() on null Ptr should have thrown exception!" );
      }
      catch( const Teuchos::NullReferenceError &except ) {
        // Caught expected exception!
      }
#endif
    }
 
    {
      // Test basic construction of Ptr
      A a;
      Ptr<A> a_ptr(&a);
      TEUCHOS_ASSERT_EQUALITY( &a, &*a_ptr );
      TEUCHOS_ASSERT_EQUALITY( &a, a_ptr.get() );
    }
 
    {
      // Test copy constructor for Ptr
      A a;
      Ptr<A> a_ptr1(&a);
      Ptr<A> a_ptr2(a_ptr1);
      TEUCHOS_ASSERT_EQUALITY( &*a_ptr1, &*a_ptr2 );
    }
 
    {
      // Test implicit copy conversion
      C c;
      Ptr<C> c_ptr(&c);
      Ptr<A> a_ptr(c_ptr);
      TEUCHOS_ASSERT_EQUALITY( &*a_ptr, &*c_ptr );
    }
 
    {
      // Test assignment operator
      C c;
      Ptr<C> c_ptr(&c);
      Ptr<A> a_ptr;
      a_ptr = c_ptr;
      TEUCHOS_ASSERT_EQUALITY( &*a_ptr, &*c_ptr );
    }
 
    {
      // Test construction of Ptr from ptr()
      A a;
      Ptr<A> a_ptr = ptr(a);
      TEUCHOS_ASSERT_EQUALITY( &a, &*a_ptr );
      TEUCHOS_ASSERT_EQUALITY( &a, a_ptr.get() );
    }
 
    {
      // Test construction of Ptr from constPtr()
      A a;
      Ptr<const A> a_ptr = constPtr(a);
      TEUCHOS_ASSERT_EQUALITY( &a, &*a_ptr );
      TEUCHOS_ASSERT_EQUALITY( &a, a_ptr.get() );
    }
 
    {
      // Test construction of Ptr from outArg()
      A a;
      Ptr<A> a_ptr = outArg(a);
      TEUCHOS_ASSERT_EQUALITY( &a, &*a_ptr );
      TEUCHOS_ASSERT_EQUALITY( &a, a_ptr.get() );
    }
 
    {
      // Test construction of Ptr from optInArg()
      A a;
      Ptr<const A> a_ptr = optInArg(a);
      TEUCHOS_ASSERT_EQUALITY( &a, &*a_ptr );
      TEUCHOS_ASSERT_EQUALITY( &a, a_ptr.get() );
    }
 
    {
      // Test construction of Ptr from optInArg()
      A a;
      Ptr<const A> a_ptr = constOptInArg(a);
      TEUCHOS_ASSERT_EQUALITY( &a, &*a_ptr );
      TEUCHOS_ASSERT_EQUALITY( &a, a_ptr.get() );
    }
 
	}
  TEUCHOS_STANDARD_CATCH_STATEMENTS(true,std::cerr,success);
 
  if (success)
    *out << "\nEnd Result: TEST PASSED" << std::endl;
  else
    *out << "\nEnd Result: TEST FAILED" << std::endl;
 
  return ( success ? 0 : 1 );
 
}
