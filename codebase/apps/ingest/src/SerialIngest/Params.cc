/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR                                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program SerialIngest
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  // return number of args consumed.
  //

  int Params::isArgValidN(const char *arg)
  {
    return (tdrpIsArgValidN(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("Reads ASCII data from a serial port or TCP/IP socket, assembles the input data into buffers and writes the buffers out as plain ASCII files at regular intervals.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING AND PROCESS CONTROL");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("instance");
    tt->descr = tdrpStrDup("Process instance");
    tt->help = tdrpStrDup("Used for registration with procmap.");
    tt->val_offset = (char *) &instance - &_start_;
    tt->single_val.s = tdrpStrDup("Test");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("SERIAL DATA INPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'connection'
    // ctype is '_connection_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("connection");
    tt->descr = tdrpStrDup("Connection type.");
    tt->help = tdrpStrDup("If serial, data will come in via a serial port. If TCP, this program will connect to a server using TCP.");
    tt->val_offset = (char *) &connection - &_start_;
    tt->enum_def.name = tdrpStrDup("connection_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("SERIAL");
      tt->enum_def.fields[0].val = SERIAL;
      tt->enum_def.fields[1].name = tdrpStrDup("TCP");
      tt->enum_def.fields[1].val = TCP;
    tt->single_val.e = SERIAL;
    tt++;
    
    // Parameter 'input_device'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_device");
    tt->descr = tdrpStrDup("Name of input serial port.");
    tt->help = tdrpStrDup("For connection SERIAL. This is the name, starting with /dev, of the serial port to be read. Make sure the permissions on the port have been set appropriately for reading from this user.");
    tt->val_offset = (char *) &input_device - &_start_;
    tt->single_val.s = tdrpStrDup("/dev/ttyS1");
    tt++;
    
    // Parameter 'baud_rate'
    // ctype is '_baud_rate_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("baud_rate");
    tt->descr = tdrpStrDup("Baud rate");
    tt->help = tdrpStrDup("For connection SERIAL. Baud rate for incoming serial data port");
    tt->val_offset = (char *) &baud_rate - &_start_;
    tt->enum_def.name = tdrpStrDup("baud_rate_t");
    tt->enum_def.nfields = 7;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("BAUD_300");
      tt->enum_def.fields[0].val = BAUD_300;
      tt->enum_def.fields[1].name = tdrpStrDup("BAUD_1200");
      tt->enum_def.fields[1].val = BAUD_1200;
      tt->enum_def.fields[2].name = tdrpStrDup("BAUD_2400");
      tt->enum_def.fields[2].val = BAUD_2400;
      tt->enum_def.fields[3].name = tdrpStrDup("BAUD_4800");
      tt->enum_def.fields[3].val = BAUD_4800;
      tt->enum_def.fields[4].name = tdrpStrDup("BAUD_9600");
      tt->enum_def.fields[4].val = BAUD_9600;
      tt->enum_def.fields[5].name = tdrpStrDup("BAUD_19200");
      tt->enum_def.fields[5].val = BAUD_19200;
      tt->enum_def.fields[6].name = tdrpStrDup("BAUD_38400");
      tt->enum_def.fields[6].val = BAUD_38400;
    tt->single_val.e = BAUD_9600;
    tt++;
    
    // Parameter 'dataIs7Bit'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("dataIs7Bit");
    tt->descr = tdrpStrDup("Flag for 7-bit data");
    tt->help = tdrpStrDup("For connection SERIAL. Set TRUE for 7-bit data, FALSE for 8-bit data.");
    tt->val_offset = (char *) &dataIs7Bit - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'twoStopBits'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("twoStopBits");
    tt->descr = tdrpStrDup("Flag for two stop bits");
    tt->help = tdrpStrDup("For connection SERIAL. If TRUE, 2 stop bits. If FALSE, 1 stop bit.");
    tt->val_offset = (char *) &twoStopBits - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'enableParity'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("enableParity");
    tt->descr = tdrpStrDup("Flag for enabling parity checking.");
    tt->help = tdrpStrDup("For connection SERIAL. If TRUE, parity generation is enabled for outgoing characters, and checking enabled for incoming characters. If FALSE, parity generation and checking is off.");
    tt->val_offset = (char *) &enableParity - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'oddParity'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("oddParity");
    tt->descr = tdrpStrDup("Flag for parity type.");
    tt->help = tdrpStrDup("For connection SERIAL. If TRUE, odd parity. If FALSE, even parity. Only applies if enableParity is TRUE.");
    tt->val_offset = (char *) &oddParity - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'tcp_server_host_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("tcp_server_host_name");
    tt->descr = tdrpStrDup("Name of TCP server host.");
    tt->help = tdrpStrDup("For connection TCP. The name of the host for the TCP server.");
    tt->val_offset = (char *) &tcp_server_host_name - &_start_;
    tt->single_val.s = tdrpStrDup("192.168.1.1");
    tt++;
    
    // Parameter 'tcp_server_port'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("tcp_server_port");
    tt->descr = tdrpStrDup("TCP server port number.");
    tt->help = tdrpStrDup("For connection TCP. The number of the port for the TCP server.");
    tt->val_offset = (char *) &tcp_server_port - &_start_;
    tt->single_val.i = 2003;
    tt++;
    
    // Parameter 'send_tcp_handshake'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("send_tcp_handshake");
    tt->descr = tdrpStrDup("Option to send TCP handshake sequence to the server to trigger the data flow.");
    tt->help = tdrpStrDup("If true, a sequence of bytes will be sent to the server to trigger the data flow. See 'tcp_handshape_bytes'.");
    tt->val_offset = (char *) &send_tcp_handshake - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'tcp_handshake_bytes'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("tcp_handshake_bytes");
    tt->descr = tdrpStrDup("List of bytes to be sent to server for handshaking.");
    tt->help = tdrpStrDup("This array of decimal integers is interpreted as a sequence of individual bytes which are to be sent to the server to trigger the data flow.");
    tt->array_offset = (char *) &_tcp_handshake_bytes - &_start_;
    tt->array_n_offset = (char *) &tcp_handshake_bytes_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(int);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].i = 13;
      tt->array_vals[1].i = 10;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("FILTERING.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'filter_ctrlm'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("filter_ctrlm");
    tt->descr = tdrpStrDup("Flag to set filtering of CONTROL-M (^M) characters.");
    tt->help = tdrpStrDup("If TRUE, ^M characters in the input stream will be filtered and will not appear in the output stream.");
    tt->val_offset = (char *) &filter_ctrlm - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'filter_nulls'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("filter_nulls");
    tt->descr = tdrpStrDup("Flag to set filtering of NULL (^@) characters.");
    tt->help = tdrpStrDup("If TRUE, null characters in the input stream will be filtered and will not appear in the output stream.");
    tt->val_offset = (char *) &filter_nulls - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'filter_non_printable'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("filter_non_printable");
    tt->descr = tdrpStrDup("Flag to set filtering of non-printable characters.");
    tt->help = tdrpStrDup("If TRUE, non-printable characters in the input stream will be filtered and will not appear in the output stream. There is an option to allow select characters through. See  allowable_non_printables.");
    tt->val_offset = (char *) &filter_non_printable - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'allowable_non_printable'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("allowable_non_printable");
    tt->descr = tdrpStrDup("List of allowable non-printable characters.");
    tt->help = tdrpStrDup("See filter_non_printable. If you have this option set, then all non-printable characters will be filtered from the output stream, EXCEPT for the characters in this list. The characters are given as decimal numbers.");
    tt->array_offset = (char *) &_allowable_non_printable - &_start_;
    tt->array_n_offset = (char *) &allowable_non_printable_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(int);
    tt->array_n = 0;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt++;
    
    // Parameter 'end_of_message_check'
    // ctype is '_end_of_message_check_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("end_of_message_check");
    tt->descr = tdrpStrDup("Option to check for end of message before closing an output file.");
    tt->help = tdrpStrDup("Some of the incoming data streams have special characters for indicating the end of a message. The following EOM conditions are used: (a) EOM_CHECK_NNNN: the 4 characters NNNN; (b) EOM_CHECK_CTRLC: Ctrl-C; (c) EOM_CHECK_CTRLKC: Ctrl-K Ctrl-C; (d) EOM_CHECK_EQUALS: an equals-sign followed by a line-feed.");
    tt->val_offset = (char *) &end_of_message_check - &_start_;
    tt->enum_def.name = tdrpStrDup("end_of_message_check_t");
    tt->enum_def.nfields = 5;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("EOM_CHECK_NONE");
      tt->enum_def.fields[0].val = EOM_CHECK_NONE;
      tt->enum_def.fields[1].name = tdrpStrDup("EOM_CHECK_NNNN");
      tt->enum_def.fields[1].val = EOM_CHECK_NNNN;
      tt->enum_def.fields[2].name = tdrpStrDup("EOM_CHECK_CTRLC");
      tt->enum_def.fields[2].val = EOM_CHECK_CTRLC;
      tt->enum_def.fields[3].name = tdrpStrDup("EOM_CHECK_CTRLKC");
      tt->enum_def.fields[3].val = EOM_CHECK_CTRLKC;
      tt->enum_def.fields[4].name = tdrpStrDup("EOM_CHECK_EQUALS");
      tt->enum_def.fields[4].val = EOM_CHECK_EQUALS;
    tt->single_val.e = EOM_CHECK_NONE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("METAR DATA FILE OUTPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_interval'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("output_interval");
    tt->descr = tdrpStrDup("Interval at which output files are created (secs).");
    tt->help = tdrpStrDup("The program reads the incoming data and stores it in a temporary file. At regular intervals, the file is renamed - see output_dir_path.");
    tt->val_offset = (char *) &output_interval - &_start_;
    tt->single_val.i = 300;
    tt++;
    
    // Parameter 'force_output_if_stalled'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("force_output_if_stalled");
    tt->descr = tdrpStrDup("Flag for forcing the file output if the input stream in stalled.");
    tt->help = tdrpStrDup("If TRUE, on output file will be written at the appropriate time, even if no data is coming in. If FALSE, the output file will only be written when message data indicates that an appropriate end-of-message condition has been met.");
    tt->val_offset = (char *) &force_output_if_stalled - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'discard_zero_length_files'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("discard_zero_length_files");
    tt->descr = tdrpStrDup("Flag for discarding 0-length files.");
    tt->help = tdrpStrDup("If TRUE, output files will be ignored if they are empty. If FALSE, files will be output even if empty.");
    tt->val_offset = (char *) &discard_zero_length_files - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'output_dir_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_dir_path");
    tt->descr = tdrpStrDup("Name of output directory.");
    tt->help = tdrpStrDup("The output files will be stored in this level directory.\nThe file path is computed as follows:\n\t output_dir_path/yyyymmdd/hhmmss.ext\n");
    tt->val_offset = (char *) &output_dir_path - &_start_;
    tt->single_val.s = tdrpStrDup(".");
    tt++;
    
    // Parameter 'output_file_ext'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_file_ext");
    tt->descr = tdrpStrDup("Extension for output file.");
    tt->help = tdrpStrDup("See output_dir_path.");
    tt->val_offset = (char *) &output_file_ext - &_start_;
    tt->single_val.s = tdrpStrDup("metar");
    tt++;
    
    // Parameter 'dataTimeout'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("dataTimeout");
    tt->descr = tdrpStrDup("If we have not received data in this long, terminate connection and retry to connect");
    tt->help = tdrpStrDup("Timeout is in seconds.  A timeout of -1 (the default) means this feature will be disabled.");
    tt->val_offset = (char *) &dataTimeout - &_start_;
    tt->single_val.i = -1;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
