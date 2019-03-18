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
///////////////////////////////////////////////////////////////
// Sprite.cc
//
// Mike Dixon, EOL, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// March 2019
//
///////////////////////////////////////////////////////////////
//
// Sprite is the time series display for IWRF data
//
///////////////////////////////////////////////////////////////

#include "Sprite.hh"
#include "ColorMap.hh"
#include "TsReader.hh"
#include "BeamMgr.hh"
#include "AScopeMgr.hh"
#include "Params.hh"

#include <toolsa/Path.hh>

#include <string>
#include <iostream>
#include <QApplication>

using namespace std;

// Constructor

Sprite::Sprite(int argc, char **argv) :
        _args("Sprite")

{
  
  OK = true;
  _ascopeManager = NULL;
  _coordShmem = NULL;
  _tsReader = NULL;
  _beamMgr = NULL;

  // set programe name

  _progName = strdup("Sprite");
  
  // get command line args
  
  if (_args.parse(argc, (const char **) argv)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with command line args" << endl;
    OK = false;
    return;
  }

  // load TDRP params from command line
  
  char *paramsPath = (char *) "unknown";
  if (_params.loadFromArgs(argc, argv,
			   _args.override.list,
			   &paramsPath)) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "Problem with TDRP parameters." << endl;
    OK = false;
    return;
  }

  // create CIDD coord shmem 
  
  _coordShmem = (coord_export_t *)
    ushm_create(_params.moments_shmem_key, sizeof(coord_export_t), 0666);
  if (_coordShmem == NULL) {
    cerr << "ERROR: " << _progName << endl;
    cerr << "  Could not attach shared memory from moments display app" << endl;
    cerr << "  shmem key: " << _params.moments_shmem_key << endl;
    OK = false;
  }

  // beam manager

  _beamMgr = new BeamMgr(_progName, _params);
  if (!_params.use_cal_from_time_series) {
    if (_beamMgr->readCalFromFile(_params.cal_file_path)) {
      cerr << "ERROR: " << _progName << endl;
      cerr << "  Cannot read cal file: " << _params.cal_file_path << endl;
      OK = false;
    }
  }
  
  // init process mapper registration

  if (_params.register_with_procmap) {
    PMU_auto_init((char *) _progName.c_str(),
                  _params.instance,
                  PROCMAP_REGISTER_INTERVAL);
  }

}

// destructor

Sprite::~Sprite()

{

  if (_ascopeManager) {
    delete _ascopeManager;
  }

  if (_tsReader) {
    delete _tsReader;
  }

}

//////////////////////////////////////////////////
// Run

int Sprite::Run(QApplication &app)
{

  // create the time series reader
  
  _tsReader = new TsReader(_progName, _params, _args);
  if (!_tsReader->OK) {
    return -1;
  }
  
  // create the ascope manager
  
  _ascopeManager = new AScopeMgr(_params, _tsReader);

  return _ascopeManager->run(app);

}
