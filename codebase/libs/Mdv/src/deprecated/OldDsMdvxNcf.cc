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
// OldDsMdvxNcf.cc
//
// Old NetCDF translation using the NcMdvServer - deprecated
//
// Mike Dixon, RAP, NCAR, P.O.Box 3000, Boulder, CO, 80307-3000, USA
//
// October 1999
//
///////////////////////////////////////////////////////////////

#include <toolsa/TaStr.hh>
#include <Mdv/OldDsMdvxNcf.hh>
#include <Mdv/OldDsMdvxNcfMsg.hh>
#include <dsserver/DsLocator.hh>
#include <dsserver/DmapAccess.hh>
#include <dsserver/DsClient.hh>
#include <dsserver/DsLdataInfo.hh>
using namespace std;

////////////////////////////////////////////////
// convert MDV format to NETCDF CF format
// using the NcMdvServer (deprecated)
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_convertMdv2NcfViaServer(const string &url)
  
{
  
  if (_currentFormat != FORMAT_MDV) {
    _errStr += "ERROR - OldDsMdvxNcf::convertMdv2Ncf.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_MDV));
    return -1;
  }

  // set up URL for doing conversion via NcMdvServer

  DsURL trans_url(url);
  trans_url.setProtocol("mdvp");
  trans_url.setTranslator("NcMdvServer");
  
  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::convertMdv2Ncf.\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  if (_debug) {
    cerr << "convertMdv2Ncf(): MDV to NCF" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  // assemble message packet

  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleConvertMdv2Ncf(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::convertMdv2Ncf.\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server

  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::convertMdv2Ncf.\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }

  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_CONVERT_MDV_TO_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::convertMdv2Ncf\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }

  _ncfConstrained = true;

  return 0;

}

////////////////////////////////////////////////
// convert NETCDF CF format to MDV format
// using the NcMdvServer (deprecated)
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_convertNcf2MdvViaServer(const string &url)
  
{

  if (_currentFormat != FORMAT_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::convertNcf2Mdv.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_NCF));
    return -1;
  }
  
  // save read details

  Mdvx::encoding_type_t readEncodingType = _readEncodingType;
  Mdvx::compression_type_t readCompressionType = _readCompressionType;
  Mdvx::scaling_type_t readScalingType = _readScalingType;
  double readScale = _readScale;
  double readBias = _readBias;

  // set up URL for doing conversion via NcMdvServer
  
  DsURL trans_url(url);
  trans_url.setProtocol("mdvp");
  trans_url.setTranslator("NcMdvServer");
  
  if (_debug) {
    cerr << "convertNcf2Mdv(): NCF to MDV" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::convertNcf2Mdv.\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  // assemble message packet

  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleConvertNcf2Mdv(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::convertNcf2Mdv.\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server

  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::convertNcf2Mdv.\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }

  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_CONVERT_NCF_TO_MDV) {
    _errStr += "ERROR - OldDsMdvxNcf::convertNcf2Mdv.\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }

  // convert the output fields appropriately

  for (int ii = 0; ii < (int) _fields.size(); ii++) {
    _fields[ii]->convertType(readEncodingType,
                             readCompressionType,
                             readScalingType,
                             readScale, readBias);
  }

  return 0;

}

////////////////////////////////////////////////
// read the headers from a NCF file, using the NcMdvServer
// deprecated
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_readAllHeadersNcfViaServer(const string &url)
  
{

  if (_currentFormat != FORMAT_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::readAllHeadersNcf.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_NCF));
    return -1;
  }
  
  // set up URL for doing conversion via NcMdvServer
  
  DsURL trans_url(url);
  trans_url.setProtocol("mdvp");
  trans_url.setTranslator("NcMdvServer");
  
  if (_debug) {
    cerr << "readAllHeadersNcf(): Reading headers from NCF-type file" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readAllHeadersNcf\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  // assemble message packet
  
  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleReadAllHdrsNcf(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::readAllHeadersNcf\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server
  
  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readAllHeadersNcf\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }

  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_READ_ALL_HDRS_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::readAllHeadersNcf\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }
  
  return 0;
  
}

////////////////////////////////////////////////
// read NCF file, using the NcMdvServer
// deprecated
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_readNcfViaServer(const string &url)
  
{
  
  if (_currentFormat != FORMAT_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::readNcf.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_NCF));
    return -1;
  }
  
  // save read details
  
  Mdvx::encoding_type_t readEncodingType = _readEncodingType;
  Mdvx::compression_type_t readCompressionType = _readCompressionType;
  Mdvx::scaling_type_t readScalingType = _readScalingType;
  double readScale = _readScale;
  double readBias = _readBias;

  // set up URL for doing conversion via NcMdvServer
  
  DsURL trans_url(url);
  trans_url.setProtocol("mdvp");
  trans_url.setTranslator("NcMdvServer");
  
  if (_debug) {
    cerr << "readNcf(): Reading NCF-type file" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readNcf\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  // assemble message packet
  
  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleReadNcf(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::readNcf\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server
  
  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readNcf\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }

  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_READ_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::readNcf\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }
  
  // for MDV format, convert the output fields appropriately
  
  if (_currentFormat == FORMAT_MDV) {
    for (int ii = 0; ii < (int) _fields.size(); ii++) {
      _fields[ii]->convertType(readEncodingType,
                               readCompressionType,
                               readScalingType,
                               readScale, readBias);
    }
  }

  return 0;
  
}

////////////////////////////////////////////////
// read the headers from a RADX file, using the NcMdvServer
// deprecated
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_readAllHeadersRadxViaServer(const string &url)
  
{

  if (_currentFormat != FORMAT_RADX) {
    _errStr += "ERROR - OldDsMdvxNcf::readAllHeadersRadx.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_RADX));
    return -1;
  }
  
  // set up URL for doing conversion via NcMdvServer
  
  DsURL trans_url(url);
  trans_url.setProtocol("mdvp");
  trans_url.setTranslator("NcMdvServer");
  
  if (_debug) {
    cerr << "readAllHeadersRadx(): Reading headers from RADX-type file" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readAllHeadersRadx\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  // assemble message packet
  
  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleReadAllHdrsRadx(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::readAllHeadersRadx\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server
  
  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readAllHeadersRadx\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }

  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_READ_ALL_HDRS_RADX) {
    _errStr += "ERROR - OldDsMdvxNcf::readAllHeadersRadx\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }
  
  return 0;
  
}

////////////////////////////////////////////////
// read RADX file, using the NcMdvServer
// deprecated
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_readRadxViaServer(const string &url)
  
{
  
  if (_currentFormat != FORMAT_RADX) {
    _errStr += "ERROR - OldDsMdvxNcf::readRadx.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_RADX));
    return -1;
  }
  
  // save read details
  
  Mdvx::encoding_type_t readEncodingType = _readEncodingType;
  Mdvx::compression_type_t readCompressionType = _readCompressionType;
  Mdvx::scaling_type_t readScalingType = _readScalingType;
  double readScale = _readScale;
  double readBias = _readBias;

  // set up URL for doing conversion via NcMdvServer
  
  DsURL trans_url(url);
  trans_url.setProtocol("mdvp");
  trans_url.setTranslator("NcMdvServer");
  
  if (_debug) {
    cerr << "readRadx(): Reading RADX-type file" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readRadx\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  // assemble message packet
  
  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleReadRadx(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::readRadx\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server
  
  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::readRadx\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }

  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_READ_RADX) {
    _errStr += "ERROR - OldDsMdvxNcf::readRadx\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }
  
  // for MDV format, convert the output fields appropriately

  if (_currentFormat == FORMAT_MDV) {
    for (int ii = 0; ii < (int) _fields.size(); ii++) {
      _fields[ii]->convertType(readEncodingType,
                               readCompressionType,
                               readScalingType,
                               readScale, readBias);
    }
  }

  return 0;

}

/////////////////////////////////////////////////////////////
// constrain NETCDF CF using read qualifiers, via NcMdvServer
// deprecated
// Used when and NC file is read, and NC data is requested
// returns 0 on success, -1 on failure

int OldDsMdvxNcf::_constrainNcfViaServer(const string &url)
  
{

  if (_currentFormat != FORMAT_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::constrainNcf.\n";
    TaStr::AddStr(_errStr, "  Incorrect format: ", format2Str(_currentFormat));
    TaStr::AddStr(_errStr, "  Should be: ", format2Str(FORMAT_NCF));
    return -1;
  }
  
  // set up URL for doing conversion via NcMdvServer
  
  DsURL trans_url(url);
  trans_url.setTranslator("NcMdvServer");
  
  if (_debug) {
    cerr << "constrainNcf(): NCF to MDV to NCF" << endl;
    cerr << "  URL: " << trans_url.getURLStr() << endl;
  }

  DsLOCATOR locator;
  bool contact_server;
  if (locator.resolve(trans_url, &contact_server, false)) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::constrainNcf.\n";
    _errStr += "  Cannot resolve URL: ";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }
  
  // assemble message packet

  OldDsMdvxNcfMsg msg;
  if (_debug) {
    msg.setDebug();
  }
  void *msgBuf =
    msg.assembleConstrainNcf(*this, trans_url.getURLStr());
  if (msgBuf == NULL) {
    _errStr += "ERROR - OldDsMdvxNcf::constrainNcf.\n";
    _errStr += "  Assembling outgoing message, URL:\n";
    _errStr += trans_url.getURLStr();
    _errStr += "\n";
    return -1;
  }

  // communicate with server
  
  if (_communicate(trans_url, msg, msgBuf, msg.lengthAssembled())) {
    _errStr += "ERROR - COMM - OldDsMdvxNcf::constrainNcf.\n";
    _errStr += "  Communicating with server\n";
    return -1;
  }
  
  if (msg.getError()) {
    return -1;
  }

  if (msg.getSubType() != OldDsMdvxNcfMsg::MDVP_CONSTRAIN_NCF) {
    _errStr += "ERROR - OldDsMdvxNcf::constrainNcf.\n";
    TaStr::AddInt(_errStr, "  Incorrect return subType: ", msg.getSubType());
    return -1;
  }

  _ncfConstrained = true;

  return 0;

}
