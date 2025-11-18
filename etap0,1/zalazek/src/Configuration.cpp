#include "Configuration.hh"
#include "xmlinterp.hh" 

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>

using namespace std;
using namespace xercesc;

bool Configuration::LoadFromFile(const std::string& sFileName)
{
   try {
        XMLPlatformUtils::Initialize();
   }
   catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cerr << "Error during Xerces-C initialization! :\n"
             << message << "\n";
        XMLString::release(&message);
        return false;
   }

   SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(XMLUni::fgXercesSchema, true);
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);
   
   // ZMIANA: Przekazujemy 'this', czyli wskaźnik na bieżący obiekt Configuration
   DefaultHandler* pHandler = new XMLInterp4Config(*this);
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   try {
     if (!pParser->loadGrammar("config/config.xsd", Grammar::SchemaGrammarType, true)) {
       cerr << "!!! Blad: Nie mozna wczytac pliku gramatyki config/config.xsd." << endl;
       return false;
     }
     pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
     pParser->parse(sFileName.c_str());
   }
   catch (const SAXParseException& Exception) {
        char* sMessage = XMLString::transcode(Exception.getMessage());
        char* sSystemId = XMLString::transcode(Exception.getSystemId());
        cerr << "Blad parsowania XML! " << endl
             << "    Plik:  " << sSystemId << endl
             << "   Linia: " << Exception.getLineNumber() << endl
             << " Kolumna: " << Exception.getColumnNumber() << endl
             << " Informacja: " << sMessage << endl;
        XMLString::release(&sMessage);
        XMLString::release(&sSystemId);
        return false;
   }
   catch (const XMLException& Exception) {
        char* sMessage = XMLString::transcode(Exception.getMessage());
        cerr << "Wyjatek XML: \n" << "   " << sMessage << "\n";
        XMLString::release(&sMessage);
        return false;
   }
   catch (...) {
        cout << "Wystapil nieznany wyjatek podczas parsowania XML!\n" ;
        return false;
   }

   delete pParser;
   delete pHandler;
   XMLPlatformUtils::Terminate();
   return true;
}