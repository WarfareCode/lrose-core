// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c)
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program Tstorms2Xml
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
using namespace std;

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
        << "   [ -check_params] check which params are not set\n"
        << "   [ -print_params [mode]] print parameters\n"
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
    tt->comment_hdr = tdrpStrDup("Tstorms2Xml program");
    tt->comment_text = tdrpStrDup("Tstorms2Xml reads native TITAN data files, converts the data into XML format, and writes the data out to XML files or SPDB.");
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
    tt->single_val.s = tdrpStrDup("test");
    tt++;
    
    // Parameter 'input_mode'
    // ctype is '_input_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("input_mode");
    tt->descr = tdrpStrDup("Operational mode");
    tt->help = tdrpStrDup("In REALTIME mode, the program is run on output from each volume scan as it becomes available. In ARCHIVE mode, all of the scans in a series of track files are processed. In FILELIST mode, the program processes a list of files specified on the command line. In XML mode, an XML string is specified on the command line, along with a valid time, and this string is stored to SPDB. XML mode is used to take XML data stored in plain files and store it into SPDB.");
    tt->val_offset = (char *) &input_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("input_mode_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ARCHIVE");
      tt->enum_def.fields[0].val = ARCHIVE;
      tt->enum_def.fields[1].name = tdrpStrDup("REALTIME");
      tt->enum_def.fields[1].val = REALTIME;
      tt->enum_def.fields[2].name = tdrpStrDup("FILELIST");
      tt->enum_def.fields[2].val = FILELIST;
      tt->enum_def.fields[3].name = tdrpStrDup("XML");
      tt->enum_def.fields[3].val = XML;
    tt->single_val.e = REALTIME;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("DATA INPUT.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'input_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_dir");
    tt->descr = tdrpStrDup("Directory for input TITAN storm data.");
    tt->help = tdrpStrDup("If this path is not absolute (starts with /) or relative (starts with .) it will be taken relative to $RAP_DATA_DIR or $DATA_DIR.");
    tt->val_offset = (char *) &input_dir - &_start_;
    tt->single_val.s = tdrpStrDup("titan/storms");
    tt++;
    
    // Parameter 'max_realtime_valid_age'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("max_realtime_valid_age");
    tt->descr = tdrpStrDup("Max valid age of input data in realtime mode (secs).");
    tt->help = tdrpStrDup("REALTIME mode only. This the max valid age for input data. In REALTIME mode, the program will wait for data more recent than this.");
    tt->val_offset = (char *) &max_realtime_valid_age - &_start_;
    tt->single_val.i = 360;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("XML DETAILS");
    tt->comment_text = tdrpStrDup("Details for the XML file.");
    tt++;
    
    // Parameter 'xml_format'
    // ctype is '_xml_format_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("xml_format");
    tt->descr = tdrpStrDup("Formal of XML output.");
    tt->help = tdrpStrDup("TSTORMS_FORMAT is a simple format. WXML is the Australian BOM output format.");
    tt->val_offset = (char *) &xml_format - &_start_;
    tt->enum_def.name = tdrpStrDup("xml_format_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("TSTORMS_FORMAT");
      tt->enum_def.fields[0].val = TSTORMS_FORMAT;
      tt->enum_def.fields[1].name = tdrpStrDup("WXML_FORMAT");
      tt->enum_def.fields[1].val = WXML_FORMAT;
    tt->single_val.e = WXML_FORMAT;
    tt++;
    
    // Parameter 'xml_indent_per_level'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("xml_indent_per_level");
    tt->descr = tdrpStrDup("Indent per level (spaces).");
    tt->help = tdrpStrDup("Number of spaces per indent level");
    tt->val_offset = (char *) &xml_indent_per_level - &_start_;
    tt->single_val.i = 2;
    tt++;
    
    // Parameter 'schema_instance'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("schema_instance");
    tt->descr = tdrpStrDup("XML schema instance.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &schema_instance - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.w3.org/2001/XMLSchema-instance");
    tt++;
    
    // Parameter 'version'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("version");
    tt->descr = tdrpStrDup("XML version.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &version - &_start_;
    tt->single_val.s = tdrpStrDup("3.0");
    tt++;
    
    // Parameter 'schema_location'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("schema_location");
    tt->descr = tdrpStrDup("XML schema location.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &schema_location - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.cawcr.gov.au/WxML http://www.cawcr.gov.au/WxML/wxml.3.0.xsd");
    tt++;
    
    // Parameter 'namespace_location'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("namespace_location");
    tt->descr = tdrpStrDup("XML namespace location.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &namespace_location - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.cawcr.gov.au/WxML");
    tt++;
    
    // Parameter 'operational_mode'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("operational_mode");
    tt->descr = tdrpStrDup("operational-mode - experimental, operational etc.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &operational_mode - &_start_;
    tt->single_val.s = tdrpStrDup("experimental");
    tt++;
    
    // Parameter 'product_description'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("product_description");
    tt->descr = tdrpStrDup("product -> description");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &product_description - &_start_;
    tt->single_val.s = tdrpStrDup("TITAN");
    tt++;
    
    // Parameter 'refresh_frequency'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("refresh_frequency");
    tt->descr = tdrpStrDup("product -> refresh-frequency");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &refresh_frequency - &_start_;
    tt->single_val.s = tdrpStrDup("PT10M");
    tt++;
    
    // Parameter 'radar_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("radar_name");
    tt->descr = tdrpStrDup("Radar site name.");
    tt->help = tdrpStrDup("Sets radar name for output to XML file.");
    tt->val_offset = (char *) &radar_name - &_start_;
    tt->single_val.s = tdrpStrDup("not-set");
    tt++;
    
    // Parameter 'radar_latitude_deg'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("radar_latitude_deg");
    tt->descr = tdrpStrDup("Radar latitude (deg)");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &radar_latitude_deg - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'radar_longitude_deg'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("radar_longitude_deg");
    tt->descr = tdrpStrDup("Radar laongitude (deg)");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &radar_longitude_deg - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'more_information'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("more_information");
    tt->descr = tdrpStrDup("product-source -> more-information");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &more_information - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.cawcr.gov.au/WxML");
    tt++;
    
    // Parameter 'production_center'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("production_center");
    tt->descr = tdrpStrDup("product-source -> production-center");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &production_center - &_start_;
    tt->single_val.s = tdrpStrDup("Australian Bureau of Meteorology<sub-center>Centre for Australian Weather and Climate Research</sub-center>");
    tt++;
    
    // Parameter 'disclaimer'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("disclaimer");
    tt->descr = tdrpStrDup("product-source -> disclaimer");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &disclaimer - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.bom.gov.au/other/disclaimer.shtml");
    tt++;
    
    // Parameter 'credit'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("credit");
    tt->descr = tdrpStrDup("product-source -> credit");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &credit - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.bom.gov.au");
    tt++;
    
    // Parameter 'credit_logo'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("credit_logo");
    tt->descr = tdrpStrDup("product-source -> credit-logo");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &credit_logo - &_start_;
    tt->single_val.s = tdrpStrDup("http://www.bom.gov.au/images/bom_logo.gif");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("ELLIPSES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'include_ellipse'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_ellipse");
    tt->descr = tdrpStrDup("Option to include ellipse data.");
    tt->help = tdrpStrDup("Ellipses are used for a simple storm shape and size description.");
    tt->val_offset = (char *) &include_ellipse - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("POLYGONS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'include_polygon'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_polygon");
    tt->descr = tdrpStrDup("Option to include polygon data.");
    tt->help = tdrpStrDup("Polygons are used for a more complex storm shape and size description.");
    tt->val_offset = (char *) &include_polygon - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'smooth_polygon'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("smooth_polygon");
    tt->descr = tdrpStrDup("Smooth the storm polygon");
    tt->help = tdrpStrDup("If TRUE, the storm polygon will be smoothed within the boundaries defined by polygon_smooth_inner_mult and polygon_smooth_outer_mult.");
    tt->val_offset = (char *) &smooth_polygon - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'polygon_smooth_inner_mult'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("polygon_smooth_inner_mult");
    tt->descr = tdrpStrDup("Inner boundary multiplier for storm polygon smoothing");
    tt->help = tdrpStrDup("Multipliers less than 1.0 produce an inner boundary smaller than the original storm. Multipliers greater than 1.0 produce an inner boundary larger than the original storm. inner_mult must be <= outer_mult");
    tt->val_offset = (char *) &polygon_smooth_inner_mult - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'polygon_smooth_outer_mult'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("polygon_smooth_outer_mult");
    tt->descr = tdrpStrDup("Outer boundary multiplier for storm smoothing");
    tt->help = tdrpStrDup("Multipliers less than 1.0 produce an outer boundary smaller than the original storm. Multipliers greater than 1.0 produce an outer boundary larger than the original storm. outer_bnd_multiplier must be >= inner_bnd_multiplier");
    tt->val_offset = (char *) &polygon_smooth_outer_mult - &_start_;
    tt->has_min = TRUE;
    tt->min_val.d = 0;
    tt->single_val.d = 3;
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("HISTORY");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'include_history'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_history");
    tt->descr = tdrpStrDup("Option to include history data");
    tt->help = tdrpStrDup("If true, storm data from the past will be included. The program will look back in time from the valid time, by 'history_secs'.");
    tt->val_offset = (char *) &include_history - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'history_secs'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("history_secs");
    tt->descr = tdrpStrDup("How far to look for history (secs)");
    tt->help = tdrpStrDup("If set to 0, the program only considers the latest scan. If greater than 0, we look back by that number of seconds.");
    tt->val_offset = (char *) &history_secs - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("FORECASTS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'generate_forecasts'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("generate_forecasts");
    tt->descr = tdrpStrDup("Option to generate forecast shapes");
    tt->help = tdrpStrDup("If true, forecast shape data will be produced. These will be polygons, ellipses or both, depending on the settings above.");
    tt->val_offset = (char *) &generate_forecasts - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'forecast_lead_times'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("forecast_lead_times");
    tt->descr = tdrpStrDup("Lead times for forecasts - secs.");
    tt->help = tdrpStrDup("Array of forecast lead times. Forecast shapes will be produced at each of these times. See 'generate_forecasts'.");
    tt->array_offset = (char *) &_forecast_lead_times - &_start_;
    tt->array_n_offset = (char *) &forecast_lead_times_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(int);
    tt->array_n = 2;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].i = 1800;
      tt->array_vals[1].i = 3600;
    tt++;
    
    // Parameter 'forecast_growth_and_decay'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("forecast_growth_and_decay");
    tt->descr = tdrpStrDup("Allow growth and decay on forecasts");
    tt->help = tdrpStrDup("If true, forecast shapes will be allowed to grow and decay according to TITAN trends. If false, the shapes will stay the same size.");
    tt->val_offset = (char *) &forecast_growth_and_decay - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 8'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 8");
    tt->comment_hdr = tdrpStrDup("DATA OUTPUT");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'write_to_xml_files'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_to_xml_files");
    tt->descr = tdrpStrDup("Option to write XML files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_to_xml_files - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'xml_dir'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("xml_dir");
    tt->descr = tdrpStrDup("Dir for XML files. See write_to_xml_files.");
    tt->help = tdrpStrDup("Files will be written to dated subdirectories. See xml_name");
    tt->val_offset = (char *) &xml_dir - &_start_;
    tt->single_val.s = tdrpStrDup("./output/xml");
    tt++;
    
    // Parameter 'xml_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("xml_name");
    tt->descr = tdrpStrDup("Name used to create the file name.");
    tt->help = tdrpStrDup("Files name will be yyyymmdd/yyyymmdd_hhmmss_{xml_name}.xml.");
    tt->val_offset = (char *) &xml_name - &_start_;
    tt->single_val.s = tdrpStrDup("titan");
    tt++;
    
    // Parameter 'write_to_spdb'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_to_spdb");
    tt->descr = tdrpStrDup("Option to write data to SPDB data base.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_to_spdb - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'spdb_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("spdb_url");
    tt->descr = tdrpStrDup("URL for TITAN XML SPDB data.");
    tt->help = tdrpStrDup("The XML will be stored in SPDB in exactly the same format as is written to XML files.");
    tt->val_offset = (char *) &spdb_url - &_start_;
    tt->single_val.s = tdrpStrDup("./output/spdb/tstorms_xml");
    tt++;
    
    // Parameter 'include_prec_flux_xml'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("include_prec_flux_xml");
    tt->descr = tdrpStrDup("Option to publish precipitation flux to otuput Xml");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &include_prec_flux_xml - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
