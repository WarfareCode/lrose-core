// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// ** Copyright UCAR (c) 1992 - 2017
// ** University Corporation for Atmospheric Research(UCAR)
// ** National Center for Atmospheric Research(NCAR)
// ** Boulder, Colorado, USA
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
////////////////////////////////////////////
// RefractCalibParams.cc
//
// TDRP C++ code file for class 'RefractCalibParams'.
//
// Code for program RefractParams2Tdrp
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

#include "RefractCalibParams.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  RefractCalibParams::RefractCalibParams()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "RefractCalibParams";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  RefractCalibParams::RefractCalibParams(const RefractCalibParams& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "RefractCalibParams";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  RefractCalibParams::~RefractCalibParams()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void RefractCalibParams::operator=(const RefractCalibParams& other)

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

  int RefractCalibParams::loadFromArgs(int argc, char **argv,
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

  int RefractCalibParams::loadApplyArgs(const char *params_path,
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

  bool RefractCalibParams::isArgValid(const char *arg)
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

  int RefractCalibParams::load(const char *param_file_path,
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

  int RefractCalibParams::loadFromBuf(const char *param_source_str,
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

  int RefractCalibParams::loadDefaults(int expand_env)
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

  void RefractCalibParams::sync(void) const
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

  void RefractCalibParams::print(FILE *out, tdrp_print_mode_t mode)
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

  int RefractCalibParams::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int RefractCalibParams::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void RefractCalibParams::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void RefractCalibParams::usage(ostream &out)
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

  int RefractCalibParams::arrayRealloc(const char *param_name, int new_array_n)
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

  int RefractCalibParams::array2DRealloc(const char *param_name,
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

  void RefractCalibParams::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("RefractCalib");
    tt->comment_text = tdrpStrDup("This program creates the calibration file used by Refract.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING PARAMETERS");
    tt->comment_text = tdrpStrDup("Parameters controlling debug outputs.");
    tt++;
    
    // Parameter 'debug_level'
    // ctype is 'RefractCalib_debug_level_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug_level");
    tt->descr = tdrpStrDup("Debug level");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &debug_level - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_level_t");
    tt->enum_def.nfields = 4;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_EXTRA");
      tt->enum_def.fields[2].val = DEBUG_EXTRA;
      tt->enum_def.fields[3].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[3].val = DEBUG_VERBOSE;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'write_debug_mdv_files'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("write_debug_mdv_files");
    tt->descr = tdrpStrDup("Flag indicating whether to write debug MDV files");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &write_debug_mdv_files - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'debug_mdv_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("debug_mdv_url");
    tt->descr = tdrpStrDup("Debug MDV file URL");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &debug_mdv_url - &_start_;
    tt->single_val.s = tdrpStrDup("mdvp:://localhost::mdv/debug/RefractCalib");
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("PROCESS PARAMETERS");
    tt->comment_text = tdrpStrDup("");
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
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("INPUT DATA PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'raw_iq_in_input'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("raw_iq_in_input");
    tt->descr = tdrpStrDup("Flag indicating whether the raw I and Q values are included in the input stream.");
    tt->help = tdrpStrDup("If true, the raw fields will be read from the input stream. If false, the raw fields will be calculated from the NIQ/AIQ values which must be inluded in the input stream instead.");
    tt->val_offset = (char *) &raw_iq_in_input - &_start_;
    tt->single_val.b = pTRUE;
    tt++;
    
    // Parameter 'raw_i_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("raw_i_field_name");
    tt->descr = tdrpStrDup("Raw I field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to TRUE.");
    tt->val_offset = (char *) &raw_i_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("MeanI");
    tt++;
    
    // Parameter 'raw_q_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("raw_q_field_name");
    tt->descr = tdrpStrDup("Raw Q field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to TRUE.");
    tt->val_offset = (char *) &raw_q_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("MeanQ");
    tt++;
    
    // Parameter 'niq_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("niq_field_name");
    tt->descr = tdrpStrDup("NIQ field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to FALSE.");
    tt->val_offset = (char *) &niq_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("NIQ");
    tt++;
    
    // Parameter 'input_niq_scale'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("input_niq_scale");
    tt->descr = tdrpStrDup("Input NIQ scale value");
    tt->help = tdrpStrDup("The NIQ value from the input source is multiplied by this value before the data is used. For most radars this value should be 0.1. For SPOL this value should be 0.025.");
    tt->val_offset = (char *) &input_niq_scale - &_start_;
    tt->single_val.d = 0.1;
    tt++;
    
    // Parameter 'invert_target_angle_sign'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("invert_target_angle_sign");
    tt->descr = tdrpStrDup("Flag indicating whether to invert the sign of the target angles.");
    tt->help = tdrpStrDup("This fix should be done upstream, but is added here just in case.\nUsed only if raw_iq_in_input is set to FALSE.");
    tt->val_offset = (char *) &invert_target_angle_sign - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'aiq_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("aiq_field_name");
    tt->descr = tdrpStrDup("AIQ field name in the input stream.");
    tt->help = tdrpStrDup("Used only if raw_iq_in_input is set to FALSE.");
    tt->val_offset = (char *) &aiq_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("AIQ");
    tt++;
    
    // Parameter 'snr_field_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("snr_field_name");
    tt->descr = tdrpStrDup("Signal-to-noise ratio field name in the input stream.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &snr_field_name - &_start_;
    tt->single_val.s = tdrpStrDup("SNR");
    tt++;
    
    // Parameter 'elevation_num'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("elevation_num");
    tt->descr = tdrpStrDup("Elevation number to use from the MDV files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &elevation_num - &_start_;
    tt->single_val.l = 0;
    tt++;
    
    // Parameter 'target_id_file_list'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("target_id_file_list");
    tt->descr = tdrpStrDup("List of files to use for target identification");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_target_id_file_list - &_start_;
    tt->array_n_offset = (char *) &target_id_file_list_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 25;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804183718.KFTG_RVP.0.0.4_SUR_v368");
      tt->array_vals[1].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804183832.KFTG_RVP.0.0.4_SUR_v370");
      tt->array_vals[2].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804184738.KFTG_RVP.0.0.4_SUR_v375");
      tt->array_vals[3].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804185329.KFTG_RVP.0.0.4_SUR_v383");
      tt->array_vals[4].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804185919.KFTG_RVP.0.0.4_SUR_v391");
      tt->array_vals[5].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804190509.KFTG_RVP.0.0.4_SUR_v399");
      tt->array_vals[6].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804191100.KFTG_RVP.0.0.4_SUR_v407");
      tt->array_vals[7].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804191650.KFTG_RVP.0.0.4_SUR_v415");
      tt->array_vals[8].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804192240.KFTG_RVP.0.0.4_SUR_v423");
      tt->array_vals[9].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804192830.KFTG_RVP.0.0.4_SUR_v431");
      tt->array_vals[10].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804193420.KFTG_RVP.0.0.4_SUR_v439");
      tt->array_vals[11].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804194010.KFTG_RVP.0.0.4_SUR_v447");
      tt->array_vals[12].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804194600.KFTG_RVP.0.0.4_SUR_v455");
      tt->array_vals[13].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804195150.KFTG_RVP.0.0.4_SUR_v463");
      tt->array_vals[14].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804195740.KFTG_RVP.0.0.4_SUR_v471");
      tt->array_vals[15].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804200330.KFTG_RVP.0.0.4_SUR_v479");
      tt->array_vals[16].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804200919.KFTG_RVP.0.0.4_SUR_v487");
      tt->array_vals[17].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804201508.KFTG_RVP.0.0.4_SUR_v495");
      tt->array_vals[18].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804202058.KFTG_RVP.0.0.4_SUR_v503");
      tt->array_vals[19].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804202647.KFTG_RVP.0.0.4_SUR_v511");
      tt->array_vals[20].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804210134.KFTG_RVP.0.0.4_SUR_v517");
      tt->array_vals[21].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804210207.KFTG_RVP.0.0.4_SUR_v518");
      tt->array_vals[22].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804210756.KFTG_RVP.0.0.4_SUR_v526");
      tt->array_vals[23].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804211346.KFTG_RVP.0.0.4_SUR_v534");
      tt->array_vals[24].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/target_id/swp.1060804211936.KFTG_RVP.0.0.4_SUR_v542");
    tt++;
    
    // Parameter 'calibration_file_list'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("calibration_file_list");
    tt->descr = tdrpStrDup("List of files to use for calibration");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_calibration_file_list - &_start_;
    tt->array_n_offset = (char *) &calibration_file_list_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 9;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807000458.KFTG_RVP.0.0.5_SUR_v8");
      tt->array_vals[1].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807000602.KFTG_RVP.0.0.6_SUR_v10");
      tt->array_vals[2].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807001047.KFTG_RVP.0.0.5_SUR_v16");
      tt->array_vals[3].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807001635.KFTG_RVP.0.0.5_SUR_v24");
      tt->array_vals[4].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807002224.KFTG_RVP.0.0.5_SUR_v32");
      tt->array_vals[5].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807002813.KFTG_RVP.0.0.5_SUR_v40");
      tt->array_vals[6].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807003401.KFTG_RVP.0.0.5_SUR_v48");
      tt->array_vals[7].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807003950.KFTG_RVP.0.0.5_SUR_v56");
      tt->array_vals[8].s = tdrpStrDup("$(RAP_DATA_DIR)/apps/refractt/src/RefractCalib/KFTG/raw/calib/swp.1060807004539.KFTG_RVP.0.0.5_SUR_v64");
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("ALGORITHM PARAMETERS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'ref_file_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("ref_file_path");
    tt->descr = tdrpStrDup("Reference file path");
    tt->help = tdrpStrDup("Full path for the file containing calibration information.");
    tt->val_offset = (char *) &ref_file_path - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'num_azim'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("num_azim");
    tt->descr = tdrpStrDup("Number of azimuths used in data processing");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &num_azim - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 1;
    tt->single_val.l = 360;
    tt++;
    
    // Parameter 'num_range_bins'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("num_range_bins");
    tt->descr = tdrpStrDup("Number of range bins");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &num_range_bins - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 1;
    tt->single_val.l = 450;
    tt++;
    
    // Parameter 'beam_width'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("beam_width");
    tt->descr = tdrpStrDup("Antenna beam width in degrees");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &beam_width - &_start_;
    tt->single_val.d = 0.92;
    tt++;
    
    // Parameter 'r_min'
    // ctype is 'long'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = LONG_TYPE;
    tt->param_name = tdrpStrDup("r_min");
    tt->descr = tdrpStrDup("Min range gate of ground echo");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &r_min - &_start_;
    tt->has_min = TRUE;
    tt->min_val.l = 1;
    tt->single_val.l = 4;
    tt++;
    
    // Parameter 'side_lobe_pow'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("side_lobe_pow");
    tt->descr = tdrpStrDup("Side lobe power");
    tt->help = tdrpStrDup("Echoes below this value of integrated power are considered to be from sidelobes.");
    tt->val_offset = (char *) &side_lobe_pow - &_start_;
    tt->has_max = TRUE;
    tt->max_val.d = -10;
    tt->single_val.d = -75;
    tt++;
    
    // Parameter 'entry_type'
    // ctype is 'RefractCalib_entry_type_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("entry_type");
    tt->descr = tdrpStrDup("Type of data entry for the calibration calculation.");
    tt->help = tdrpStrDup("\tENTER_N - N is entered directly in the calib_n parameter.\n\tENTER_P_T_TD - Pressure is entered in the calib_pressure parameter, temperature is entered in the calib_temperature parameter and dew point temperature is entered in the calib_dewpoint_temperature paramtere.\n");
    tt->val_offset = (char *) &entry_type - &_start_;
    tt->enum_def.name = tdrpStrDup("entry_type_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("ENTER_N");
      tt->enum_def.fields[0].val = ENTER_N;
      tt->enum_def.fields[1].name = tdrpStrDup("ENTER_P_T_TD");
      tt->enum_def.fields[1].val = ENTER_P_T_TD;
    tt->single_val.e = ENTER_N;
    tt++;
    
    // Parameter 'calib_n'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("calib_n");
    tt->descr = tdrpStrDup("N value to use in the calibration.");
    tt->help = tdrpStrDup("Used only if entry_type is set to ENTER_N.");
    tt->val_offset = (char *) &calib_n - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'calib_pressure'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("calib_pressure");
    tt->descr = tdrpStrDup("Pressure value to use in the calibration.");
    tt->help = tdrpStrDup("This is the station pressure, NOT the sea level pressure. Used only if entry_type is set to ENTER_P_T_TD.");
    tt->val_offset = (char *) &calib_pressure - &_start_;
    tt->single_val.d = 260;
    tt++;
    
    // Parameter 'calib_temperature'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("calib_temperature");
    tt->descr = tdrpStrDup("Temperature value to use in the calibration.");
    tt->help = tdrpStrDup("Used only if entry_type is set to ENTER_P_T_TD.");
    tt->val_offset = (char *) &calib_temperature - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'calib_dewpoint_temperature'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("calib_dewpoint_temperature");
    tt->descr = tdrpStrDup("Dewpoint temperature to use in the calibration.");
    tt->help = tdrpStrDup("Unsed only if entry_type is set to ENTER_P_T_TD.");
    tt->val_offset = (char *) &calib_dewpoint_temperature - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("COLORSCALE PARAMETERS");
    tt->comment_text = tdrpStrDup("These colorscale files can be generated as a convenience to the user. They are not required for the calculating of the calibration.");
    tt++;
    
    // Parameter 'create_strength_colorscale'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("create_strength_colorscale");
    tt->descr = tdrpStrDup("Flag indicating whether to create the strength colorscale file.");
    tt->help = tdrpStrDup("This creates a CIDD colorscale file that matches the colors used by Frederic Fabry in his original n_viewcalib program.");
    tt->val_offset = (char *) &create_strength_colorscale - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'strength_colorscale_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("strength_colorscale_path");
    tt->descr = tdrpStrDup("Full path for the strength colorscale file.");
    tt->help = tdrpStrDup("Used only if create_strength_colorscale is set to true.");
    tt->val_offset = (char *) &strength_colorscale_path - &_start_;
    tt->single_val.s = tdrpStrDup("colorscales/strength.colors");
    tt++;
    
    // Parameter 'create_quality_colorscale'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("create_quality_colorscale");
    tt->descr = tdrpStrDup("Flag indicating whether to create the quality colorscale file.");
    tt->help = tdrpStrDup("This creates a CIDD colorscale file that matches the colors used by Frederic Fabry in his original n_viewcalib program.");
    tt->val_offset = (char *) &create_quality_colorscale - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'quality_colorscale_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("quality_colorscale_path");
    tt->descr = tdrpStrDup("Full path for the quality colorscale file.");
    tt->help = tdrpStrDup("Used only if create_quality_colorscale is set to true.");
    tt->val_offset = (char *) &quality_colorscale_path - &_start_;
    tt->single_val.s = tdrpStrDup("colorscales/quality.colors");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
