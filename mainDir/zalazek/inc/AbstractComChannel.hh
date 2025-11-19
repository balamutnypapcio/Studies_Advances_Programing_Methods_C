#ifndef ABSTRACTCOMCHANNEL_HH
#define ABSTRACTCOMCHANNEL_HH

/*!
 * \file 
 * \brief Zawiera definicję klasy abstrakcyjnej AbstractComChannel
 *
 *  Zawiera definicję klasy abstrakcyjnej AbstractComChannel.
 *  Wyznacza ona niezbędny interfejs klas pochodnych.
 */


#include <mutex>
#include <string>

   /*!
    * \brief Definiuje interfejs kanału komunikacyjnego z serwerem graficznym.
    *
    * Definiuje interfejs kanału komunikacyjnego z serwerem graficznym.
    * Interfejs ma pozwalać na bezpieczną komunikację w programie wielowątkowym.
    */
    class AbstractComChannel {
     public:

      virtual ~AbstractComChannel();
      
      /*!
       * \brief Inicjalizuje destryptor gniazda.
       *
       * Inicjalizuje destryptora pliku skojarzonego z połączeniem sieciowym z serwerem.
       * \param[in] Socket - zawiera poprawny deskryptor.
       */
       virtual void Init(int Socket) = 0;
      /*!
       * \brief Udostępnia deskryptor pliku skojarzonego z połączeniem sieciowym z serwerem.
       *
       *  Udostępnia deskryptor skojarzonego z połączeniem sieciowym z serwerem.
       * \return Deskryptor pliku.
       */
       virtual int GetSocket() const = 0;
      /*!
       * \brief Zamyka dostęp gniazda.
       */
       virtual void LockAccess() = 0;
      /*!
       * \brief Otwiera dostęp do gniazda.
       */
       virtual void UnlockAccess() = 0;
       /*!
        * \brief Udostępnia mutex w trybie modyfikacji.
        *
        *  Udostępnia mutex w trybie modyfikacji.
        *  Jest to przydatne, gdy planowany jest inny typ zamknięcie,
        *  np. poprzez klasę std::lock_gaurd, która daje możliwość
        *  bezpieczniejszego zamknięcia.
        */
       virtual std::mutex &UseGuard() = 0;



      // --- NOWA METODA W INTERFEJSIE ---
      /*!
         * \brief Wysyła wiadomość tekstową przez kanał.
         * \param msg - Wiadomość do wysłania.
         * \return true - jeśli wysłanie się powiodło.
         */
      virtual bool Send(const std::string& msg) const = 0;
    };


#endif
