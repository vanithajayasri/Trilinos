# Helper function
MACRO(TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD  VAR_NAME  VAR_VALUE)
  IF ("${${VAR_NAME}}" STREQUAL "")
    MESSAGE("-- " "Setting ${VAR_NAME}='${VAR_VALUE}' by default for standard PT CI build")
    SET(${VAR_NAME} ${VAR_VALUE} CACHE BOOL
      "Set in MpiReleaseDebugSharedPtSettings.cmake")
  ENDIF()
ENDMACRO()

TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(TPL_ENABLE_MPI ON)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(CMAKE_BUILD_TYPE RELEASE)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(Trilinos_ENABLE_DEBUG ON)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(BUILD_SHARED_LIBS ON)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(Trilinos_ENABLE_DEBUG_SYMBOLS ON)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(Trilinos_ENABLE_EXPLICIT_INSTANTIATION ON)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(Trilinos_ENABLE_SECONDARY_TESTED_CODE OFF)
TRIL_SET_BOOL_CACHE_VAR_FOR_PT_BUILD(Teuchos_ENABLE_DEFAULT_STACKTRACE OFF)
