#ifndef GSV_UTILS_HH
#define GSV_UTILS_HH


/*!
 * \file
 * \brief Zawiera defincje pomocniczych szblonów.
 */



namespace gsv {


  /*!
   * \brief Wartość z nadzorem kontrolującym modyfikację.
   */
  template <typename ValType>
  class WatchedValue {
    ValType  _Val;
    bool     _Changed = false;
   public:
    WatchedValue() {}
    WatchedValue(ValType Val) { _Val = Val; }
    
    void Reset() { _Changed = false; }
    bool IsChanged() const { return _Changed; }
    const ValType &Get() const { return _Val; }
    /*!
     * \brief Dostęp do pola z możliwością modyfikacji.
     *
     * Dostęp do pola z możliwością modyfikacji.
     * Zakłada się, że w takiej sytuacji zawsze następuje modyfikacja wartości.
     */
    ValType &Use() { _Changed = true; return _Val; }
  };  

}


#endif
