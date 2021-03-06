// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/////////////////////////////////////////////////////////////
// SpolWarnSms.hh
//
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// June 2018
//
///////////////////////////////////////////////////////////////
//
// SpolWarnSms reads status XML monitoring data from SPDB,
// for the S-band and K-band.
// It checks the status in the XML, and determines if
// a warning message should be sent
//
////////////////////////////////////////////////////////////////

#ifndef SpolWarnSms_HH
#define SpolWarnSms_HH

#include <string>
#include <vector>
#include <cstdio>

#include "Args.hh"
#include "Params.hh"
#include <toolsa/DateTime.hh>
#include <Spdb/DsSpdb.hh>

using namespace std;

////////////////////////
// This class

class SpolWarnSms {
  
public:

  // constructor

  SpolWarnSms(int argc, char **argv);

  // destructor
  
  ~SpolWarnSms();

  // run 

  int Run();

  // data members

  bool isOK;

protected:
  
private:

  string _progName;
  char *_paramsPath;
  Args _args;
  Params _params;
  
  class DailyInterval {
  public:
    DateTime startTime;
    DateTime endTime;
    vector<string> names;
    vector<string> numbers;
  };

  class WarnPeriod {
  public:
    DateTime endTime;
    vector<DailyInterval> intervals;
  };
  
  vector<WarnPeriod> _warnPeriods;
  time_t _timeLastSms;

  // functions
  
  int _readStatus(time_t now,
                  char *spdbUrl,
                  int marginSecs,
                  Params::xml_entry_t *entries,
                  int nEntries,
                  string &warningMsg);

  int _handleBooleanEntry(time_t now,
                          const string &statusXml,
                          const Params::xml_entry_t &entry,
                          string &warningMsg);
  
  int _handleNumberEntry(time_t now,
                         const string &statusXml,
                         const Params::xml_entry_t &entry,
                         string &warningMsg);

  int _writeMessageToDir(time_t now,
                         const string &warningMsg);
  
  int _writeMessageToSpdb(time_t now,
                          const string &warningMsg);
  
  int _setupWarnPeriods();

  int _setupDailyInterval(const DateTime &endTime,
                          const string &paramLine,
                          DailyInterval &interval);

  int _lookUpNumber(const string &name,
                    string &number);

  void _getSmsNumbers(time_t now,
                      vector<string> &names,
                      vector<string> &numbers);

};

#endif
