find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  target_link_librairies(MyTarget PUBLIC OpenMP::OpenMP_CXX)
endif()
