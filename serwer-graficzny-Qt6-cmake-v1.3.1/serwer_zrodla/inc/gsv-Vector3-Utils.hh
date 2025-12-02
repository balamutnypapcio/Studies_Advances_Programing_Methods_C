#ifndef GSV_VECTOR3_UTILS_HH
#define GSV_VECTOR3_UTILS_HH


namespace gsv {


  template <typename Vector, typename Crd1Type, typename Crd2Type, typename Crd3Type>
  inline
  void Set(Vector &rVec, Crd1Type Crd1, Crd2Type Crd2, Crd3Type Crd3)
  {
    rVec[0] = Crd1;  rVec[1] = Crd2;  rVec[2] = Crd3;
  }

}

#endif
