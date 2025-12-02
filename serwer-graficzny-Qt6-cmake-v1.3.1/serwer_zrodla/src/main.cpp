#include <QApplication>
#include <iostream>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QStatusBar>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <thread>
#include <sstream>
#include <errno.h>
#include "gsv-CommandInterpreter.hh"
#include "gsv-WgViewer3D.hh"
#include "gsv-SceneServer.hh"
#include "gtsDebug.hh"
#include "gsv-Const.h"
#include "gsv-GraphicsWindow.hh"
#include "gsv-GeomParams.hh"
#include "gsv-ServerCommand.hh"
#include <signal.h>
#include <getopt.h>

using namespace std;
#define STR(x) #x
#define MAKE_STR(x)  STR(x)
#define VERSION        1.3.1
#define RELEASE_DATE   2025.11.30

bool  g_ContinueListen = true;
int   g_Socket4Connect;
bool  g_SocketError = false;

#define SHOW( x ) \
  case x: cout << "  Nazwa bledu: " #x << endl;  break;

void ShowError()
{
  cout << "  Error: " << errno << endl;
  switch (errno) {
    SHOW(EACCES);
    SHOW(EAFNOSUPPORT);
    SHOW(EINVAL);
    SHOW(ENFILE);
    SHOW(ENOBUFS);
    SHOW(EPROTONOSUPPORT);
    SHOW(ENOMEM);
  }
}



void Handler_SigTerminate(int SigID)
{
  cerr << "Terminated ... Signal: " << SigID << endl;
  exit(0);
}

/*!
 * Nasłuchuje nowych połączeń i jeśli się pojawi, to uruchamia jego obsługę.
 * \param[in] Port - numer portu, na którym ma być prowadzony nasłuch
 *                   nowych połączeń.
 * \param[in] pScnServ - wskaźnik na obiekt serwera sceny roboczej
 *                   wykorzystywanej do obsługi nowego połączenia. 
 * \retval  0 - zakończono poprawnie pętlę nasłuchu,
 * \retval -1 - nie może utowrzyć gniazda dla nasłuchu,
 * \retval -2 - brak możliwości dowiązania do portu,
 * \retval -3 - błąd wykonania polecenie listen,
 * \retval -4 - błąd połączenia.
 */
int StartListening(int Port, gsv::SceneServer  *pScnServ)
{
  int  Socket4Listening; 
  int  Socket4Connect;

  struct sockaddr_in    cli_addr, serv_addr;
  socklen_t  ClAddrLen;



  if ((Socket4Listening = socket(AF_INET,SOCK_STREAM | SOCK_NONBLOCK,0)) < 0) {
    cerr << " Blad otwarcia gniazda do nasluchu." << endl;
    g_SocketError = true;
    return -1;
  }

  bzero((char *)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(Port);

  if (bind(Socket4Listening,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    cerr << " Blad powiazania gniazda z adresem" << endl;
    close(Socket4Listening);
    g_SocketError = true;
    return -2;
  }

  ClAddrLen = sizeof(cli_addr);

  if (listen(Socket4Listening,5) < 0) {
    cerr << " Blad rozpoczecia nasluchiwania." << endl;
    close(Socket4Listening);
    g_SocketError = true;
    return -3;
  }

   while (g_ContinueListen) {
    Socket4Connect = accept(Socket4Listening,(struct sockaddr *)&cli_addr,&ClAddrLen);
    if (Socket4Connect < 0) {
      if (errno == EAGAIN ) {
         usleep(10000); continue;
      }
      close(Socket4Listening);
      g_SocketError = true;
      return -4;
    }
    cout << " Nowe polaczenie" << endl;
    pScnServ->Listing4InterpCmds(Socket4Connect);

    shutdown(Socket4Connect,SHUT_RDWR);
    close(Socket4Connect);
   }

  int err = shutdown(Socket4Listening,SHUT_RDWR);
  if (err) {
    cerr << " Shutdown err: " << errno << endl;
  }
  err = close(Socket4Listening);
  if (err) {
    cerr << " Close err: " << errno << endl;
  }
  return 0;
}



/*!
 * Funkcja wątku nasłuchiwania nowych połączeń.
 * \param[in] pScnServ - wskaźnik na obiekt serwera sceny roboczej
 *                   wykorzystywanej do obsługi nowego połączenia. 
 */
void Listen4Connect(void *pScnServ,int Port)
{
  StartListening(Port,reinterpret_cast<gsv::SceneServer*>(pScnServ));
}


/*!
 * Funkcja wątku obsługi poleceń, których efekt realizacji
 * ma być przekazany do serwera graficznego. Efektem tym
 * są nowe współrzędne obiektów sceny.
 * \param[in] pScnServ - wskaźnik na obiekt serwera sceny roboczej
 *                   wykorzystywanej, na które modyfikowane są położenia
 *                   obiektów sceny.
 */
void Fun_CmdsExecutor(gsv::SceneServer  *pScnServ)
{
  pScnServ->ExecCmds();
}


void SetSignalHandler(int SigID)
{
  signal(SigID,Handler_SigTerminate);
}




void Help(const char *sProgName)
{
  cout << "\n"
          "  Wywolanie programu:\n"
          "    " << sProgName << " [-h|--help] [-v|--version] {[-p|--port] NrPortu} {[-b|--bg] NazwaPliku.png}\n"
          "\n"
          "   Opcje:\n"
          "      -h, --help      - wyswietla niniejsza pomoc i konczy dzialanie,\n"
          "      -v, --version   - wyswietla aktualna wersje programu i konczy dzialanie.\n"
          "      -p, --port Port - ustawia nowy port nasluchiwania polaczen przez serwer,\n"
          "      -b, --bg  NazwaPliku,png  - zmianie plik tekstury tla. Plik musi byc w formacie PNG.\n"
          "\n"
	  "    Przykladowe wywolanie:\n"
          "          serwer_graficzny -p 6020 -b /tmp/obraz_tla.png\n"
	  "\n";
}



void ShowVersion()
{
  cout << "\n"
          "  Serwer graficzny wykorzystywany na potrzeby zajec"
          "  z kursu: \"Zaawansowane metody programowania\""
          "\n"
          "            Wersja: " MAKE_STR(VERSION) "\n"
          "   Data publikacji: " MAKE_STR(RELEASE_DATE) "\n"
          "\n"
       << endl;
}



const char *sBgFileName = nullptr;

void SetBgImage(const char* FileName)
{
  sBgFileName = FileName;
}


#define NO_ARGUMENT        0
#define REQUIRED_ARGUMENT  1


/*!
 * \brief Processes program options
 *
 * Processes program options.
 * \retval true - otions has been processed successfully.
 * \retval false - otherwise.
 */	     
bool OptionProcessing( int argc, char * argv[], int &rPort )
{
 struct option long_options[] = {
                   {"help",  NO_ARGUMENT,       0,  'h' },
                   {"port",  REQUIRED_ARGUMENT, 0,  'p' },
		   {"version", NO_ARGUMENT,       0,  'v' },
		   {"bg", REQUIRED_ARGUMENT,       0,  'b' },		   
                   {0,         0,                 0,  0 }
               };
 int  Ind;
 int  option_index;

 while ((Ind = getopt_long(argc, argv, "hp:vb:",
			   long_options, &option_index)) != -1) {
   switch (Ind) {
    case 'h':
      Help(argv[0]);
      return false;

    case 'p':
      {
       int          PortX;
       std::size_t  Idx;

       PortX=stoi(optarg,&Idx);
       if (strlen(optarg) != Idx) {
	 CErr_1("\n:(  Blad w zapisie numeru portu.\n\n");
	 return false;
       }
       rPort = PortX;
      }
      break;
      
    case 'v':
      ShowVersion();
      return false;

    case 'b':
      SetBgImage(optarg);
      break;
      
    case '?':
      CErr_1("\n:(  Nieznana opcja wywolania programu.\n\n");
      return false;
      
    case ':':
      CErr_1("\n:(  Brak argumentu opcji wywolania programu.\n\n");
      return false;
   }
 }
 return true;
}





int main( int argc, char * argv[] ) 
{
  int  Port = PORT;

  if (!OptionProcessing(argc,argv,Port)) return 1;
  
  cout << "Port nasluchiwania: " << Port << endl;

  SetSignalHandler(SIGTERM);
  SetSignalHandler(SIGURG);
  SetSignalHandler(SIGPIPE);
  
  
  gsv::SceneServer    ScnServ;

  std::thread          Th4CmdInterp(Fun_CmdsExecutor,&ScnServ);
  std::thread          Th4Receiving(Listen4Connect,&ScnServ,Port);
  //pthread_t            Thread_Receiving;
  
  // pthread_create(&Thread_Receiving,NULL,Listen4Connect,&ScnServ);

  usleep(400000);
  if (g_SocketError) {
    cerr << " Problem z rozpoczeciem nasluchiwania." << endl;
    g_ContinueListen = false;

    ScnServ.FinishLooping();
    if (Th4CmdInterp.joinable())Th4CmdInterp.join();
    if (Th4Receiving.joinable()) Th4Receiving.join();
    //    pthread_join(Thread_Receiving,NULL);
    return 100;
  }
  
  QApplication             App(argc,argv);
  gsv::MainWindow4Server   Win4Serv(&ScnServ.UseBuffScn());
  Win4Serv.setWindowTitle(QObject::tr("Serwer Graficzny - wersja " MAKE_STR(VERSION)));
  if (sBgFileName) {
    gsv::WgViewer3D::Use_Viewer()->Check_SetBgImageFileName(sBgFileName);
  }
  Win4Serv.show();
  int Result = App.exec();
  
  ScnServ.FinishLooping();
  
  g_ContinueListen = false;
  if (Th4CmdInterp.joinable()) Th4CmdInterp.join();
  // pthread_join(Thread_Receiving,NULL);
  if (Th4Receiving.joinable()) Th4Receiving.join();

  return Result;
}
