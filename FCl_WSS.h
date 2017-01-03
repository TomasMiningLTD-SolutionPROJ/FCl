#ifndef FCl_WSSH
#define FCl_WSSH

#include "OverbyteIcsWndControl.hpp"
#include "OverbyteIcsWSocket.hpp"
#include "OverbyteIcsWSocketS.hpp"

class TClient: public TWSocketClient
{
public:
String Rcvd;
TWSocket* RemoteSocket;
inline __fastcall ~TClient(void);
};

class TServer : public TWSocketServer
{
typedef TWSocketServer inherited;
public:
UnicodeString LocalPort;
UnicodeString RemotePort;
UnicodeString RemoteIP;
UnicodeString RemoteAddress;
UnicodeString OurLogin;
bool logging;
inline __fastcall virtual TServer(System::Classes::TComponent* AOwner) : TWSocketServer(AOwner) { }
void inline __fastcall Init(UnicodeString LocalPort,UnicodeString RemotePort,UnicodeString RemoteIP,UnicodeString RemoteAddress,UnicodeString OurLogin,bool logging);
void __fastcall WSocketServerClientConnect(TObject *Sender, TWSocketClient *Client, WORD Error);
void __fastcall RemoteSessionConnected(TObject *Sender, WORD Error);
void __fastcall RemoteDataAvailable(TObject *Sender, WORD Error);
void __fastcall ClientDataAvailable(TObject *Sender, WORD Error);
void __fastcall RemoteSessionClosed(TObject *Sender, WORD Error);
void __fastcall BgException(TObject *Sender, Exception *E, bool &CanClose);
UnicodeString __fastcall ExchangeString(UnicodeString si);
inline __fastcall virtual ~TServer(void) { }
};
#endif