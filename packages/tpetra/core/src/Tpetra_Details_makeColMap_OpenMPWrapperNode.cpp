/*
// @HEADER
// ***********************************************************************
//
//          Tpetra: Templated Linear Algebra Services Package
//                 Copyright (2008) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact Michael A. Heroux (maherou@sandia.gov)
//
// ************************************************************************
// @HEADER
*/

#include "TpetraCore_config.h"

// Don't bother compiling anything, or even including anything else,
// unless KokkosOpenMPWrapperNode is enabled.
#if defined(HAVE_TPETRA_EXPLICIT_INSTANTIATION) && defined(HAVE_TPETRA_INST_OPENMP)

#include "Tpetra_Details_makeColMap_decl.hpp"
#include "TpetraCore_ETIHelperMacros.h"
#include "Tpetra_Details_makeColMap_def.hpp"
#include "KokkosCompat_ClassicNodeAPI_Wrapper.hpp"

// The first macro instantiates just the graph stuff.  The second
// instantiates CrsGraph methods templated on Scalar type that
// CrsMatrix needs.  The two must be handled separately, to avoid link
// errors resulting from redundant instantiations.

// Macro for instantiating Tpetra::Details::makeColMap for this Node type.

#define TPETRA_DETAILS_MAKECOLMAP_INSTANT_OPENMPWRAPPERNODE( LO, GO ) \
  TPETRA_DETAILS_MAKECOLMAP_INSTANT( LO, GO, Kokkos::Compat::KokkosOpenMPWrapperNode )

namespace Tpetra {
namespace Details {

  TPETRA_ETI_MANGLING_TYPEDEFS()

  TPETRA_INSTANTIATE_LG(TPETRA_DETAILS_MAKECOLMAP_INSTANT_OPENMPWRAPPERNODE)

} // namespace Details
} // namespace Tpetra

#endif // defined(HAVE_TPETRA_EXPLICIT_INSTANTIATION) && defined(HAVE_TPETRA_INST_OPENMP)
