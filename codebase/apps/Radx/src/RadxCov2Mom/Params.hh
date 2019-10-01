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
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program RadxCov2Mom
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    DEBUG_OFF = 0,
    DEBUG_NORM = 1,
    DEBUG_VERBOSE = 2,
    DEBUG_EXTRA = 3
  } debug_t;

  typedef enum {
    REALTIME = 0,
    ARCHIVE = 1,
    FILELIST = 2
  } mode_t;

  typedef enum {
    LAG0_HC_DB = 0,
    LAG0_HX_DB = 1,
    LAG0_VC_DB = 2,
    LAG0_VX_DB = 3,
    LAG0_HCVX_DB = 4,
    LAG0_HCVX_PHASE = 5,
    LAG0_VCHX_DB = 6,
    LAG0_VCHX_PHASE = 7,
    LAG0_VXHX_DB = 8,
    LAG0_VXHX_PHASE = 9,
    LAG1_HC_DB = 10,
    LAG1_HC_PHASE = 11,
    LAG1_VC_DB = 12,
    LAG1_VC_PHASE = 13,
    LAG1_HCVC_DB = 14,
    LAG1_HCVC_PHASE = 15,
    LAG1_VCHC_DB = 16,
    LAG1_VCHC_PHASE = 17,
    LAG1_VXHX_DB = 18,
    LAG1_VXHX_PHASE = 19,
    LAG2_HC_DB = 20,
    LAG2_HC_PHASE = 21,
    LAG2_VC_DB = 22,
    LAG2_VC_PHASE = 23,
    LAG3_HC_DB = 24,
    LAG3_HC_PHASE = 25,
    LAG3_VC_DB = 26,
    LAG3_VC_PHASE = 27,
    RVVHH0_DB = 28,
    RVVHH0_PHASE = 29
  } covariance_id_t;

  typedef enum {
    NOISE_RAY_BY_RAY = 0,
    NOISE_RUNNING_MEDIAN = 1
  } noise_method_t;

  typedef enum {
    SINGLE_POL = 0,
    SINGLE_POL_V = 1,
    DUAL_POL_ALT_HV_CO_ONLY = 2,
    DUAL_POL_ALT_HV_CO_CROSS = 3,
    DUAL_POL_SIM_HV = 4,
    DUAL_POL_H_ONLY = 5,
    DUAL_POL_V_ONLY = 6
  } xmit_rcv_mode_t;

  typedef enum {
    ATMOS_ATTEN_NONE = 0,
    ATMOS_ATTEN_CONSTANT = 1,
    ATMOS_ATTEN_CRPL = 2
  } atmos_atten_method_t;

  typedef enum {
    FIR_LEN_125 = 0,
    FIR_LEN_60 = 1,
    FIR_LEN_40 = 2,
    FIR_LEN_30 = 3,
    FIR_LEN_20 = 4,
    FIR_LEN_10 = 5
  } fir_filter_len_t;

  typedef enum {
    DBZ = 0,
    DBZHC = 1,
    DBZVC = 2,
    DBZHX = 3,
    DBZVX = 4,
    DBZ_NO_ATMOS_ATTEN = 5,
    VEL = 6,
    VEL_ALT = 7,
    VEL_HV = 8,
    VEL_ALT_FOLD_INTERVAL = 9,
    VEL_ALT_FOLD_CONFIDENCE = 10,
    VEL_DIFF = 11,
    VEL_UNFOLD_INTERVAL = 12,
    VEL_H_ONLY = 13,
    VEL_V_ONLY = 14,
    WIDTH = 15,
    WIDTH_H_ONLY = 16,
    WIDTH_V_ONLY = 17,
    NCP = 18,
    NCP_H_ONLY = 19,
    NCP_V_ONLY = 20,
    NCP_H_MINUS_V = 21,
    ZDRM = 22,
    ZDR = 23,
    ZDR_BIAS = 24,
    LDRHM = 25,
    LDRH = 26,
    LDRVM = 27,
    LDRV = 28,
    LDR_DIFF = 29,
    LDR_MEAN = 30,
    RHOHV = 31,
    RHOHV_NNC = 32,
    RHO_HCVX = 33,
    RHO_VCHX = 34,
    RHO_VXHX = 35,
    PHIDP0 = 36,
    PHIDP = 37,
    PHIDP_FILT = 38,
    PHIDP_COND = 39,
    KDP = 40,
    PSOB = 41,
    SNR = 42,
    SNRHC = 43,
    SNRHX = 44,
    SNRVC = 45,
    SNRVX = 46,
    DBM = 47,
    DBMHC = 48,
    DBMHX = 49,
    DBMVC = 50,
    DBMVX = 51,
    PHASE_FOR_NOISE = 52,
    ACCUM_PHASE_CHANGE = 53,
    PHASE_CHANGE_ERROR = 54,
    DBM_SDEV = 55,
    NCP_MEAN = 56,
    NOISE_FLAG = 57,
    SIGNAL_FLAG = 58,
    NOISE_BIAS_DB_HC = 59,
    NOISE_BIAS_DB_HX = 60,
    NOISE_BIAS_DB_VC = 61,
    NOISE_BIAS_DB_VX = 62,
    DBZ_ATTEN_CORRECTION = 63,
    ZDR_ATTEN_CORRECTION = 64,
    DBZ_ATTEN_CORRECTED = 65,
    ZDR_ATTEN_CORRECTED = 66,
    DBZ_FOR_KDP = 67,
    ZDR_FOR_KDP = 68,
    RHOHV_FOR_KDP = 69,
    SNR_FOR_KDP = 70,
    PHIDP_SDEV_FOR_KDP = 71,
    PHIDP_JITTER_FOR_KDP = 72,
    ZDR_SDEV_FOR_KDP = 73,
    TEST = 74,
    TEST2 = 75,
    TEST3 = 76,
    TEST4 = 77,
    TEST5 = 78
  } output_field_id_t;

  typedef enum {
    OUTPUT_ENCODING_FL32 = 0,
    OUTPUT_ENCODING_INT32 = 1,
    OUTPUT_ENCODING_INT16 = 2,
    OUTPUT_ENCODING_INT08 = 3
  } output_encoding_t;

  typedef enum {
    OUTPUT_SCALING_DYNAMIC = 0,
    OUTPUT_SCALING_SPECIFIED = 1
  } output_scaling_t;

  typedef enum {
    CENSORING_NONE = 0,
    CENSORING_BY_NOISE_FLAG = 1,
    CENSORING_BY_SNR_AND_NCP = 2
  } censoring_mode_t;

  typedef enum {
    OUTPUT_FORMAT_CFRADIAL = 0,
    OUTPUT_FORMAT_DORADE = 1,
    OUTPUT_FORMAT_FORAY = 2,
    OUTPUT_FORMAT_NEXRAD = 3,
    OUTPUT_FORMAT_UF = 4,
    OUTPUT_FORMAT_MDV_RADIAL = 5
  } output_format_t;

  typedef enum {
    CLASSIC = 0,
    NC64BIT = 1,
    NETCDF4 = 2,
    NETCDF4_CLASSIC = 3
  } netcdf_style_t;

  typedef enum {
    START_AND_END_TIMES = 0,
    START_TIME_ONLY = 1,
    END_TIME_ONLY = 2,
    SPECIFY_FILE_NAME = 3
  } filename_mode_t;

  // struct typedefs

  typedef struct {
    covariance_id_t field_id;
    char* field_name;
  } input_covar_t;

  typedef struct {
    double value;
    double interest;
  } interest_map_point_t;

  typedef struct {
    double pulse_width_us;
    char* cal_file_path;
  } cal_file_t;

  typedef struct {
    output_field_id_t id;
    char* name;
    char* long_name;
    char* standard_name;
    char* units;
    output_encoding_t encoding;
    output_scaling_t scaling;
    double scale;
    double offset;
  } output_field_t;

  typedef struct {
    char* input_field_name;
    char* output_field_name;
    char* long_name;
    char* standard_name;
    char* output_units;
    output_encoding_t encoding;
    output_scaling_t output_scaling;
    double output_scale;
    double output_offset;
  } echo_field_t;

  typedef struct {
    char* input_field_name;
    char* output_field_name;
    char* long_name;
    char* standard_name;
    char* output_units;
    output_encoding_t encoding;
  } merge_field_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

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

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

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

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  // return number of args consumed.
  //

  static int isArgValidN(const char *arg);

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

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

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

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

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

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

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

  int arrayRealloc(const char *param_name,
                   int new_array_n);

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

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  debug_t debug;

  char* instance;

  tdrp_bool_t use_multiple_threads;

  int n_compute_threads;

  char* input_dir;

  mode_t mode;

  int max_realtime_data_age_secs;

  tdrp_bool_t aggregate_sweep_files_on_read;

  tdrp_bool_t ignore_idle_scan_mode_on_read;

  tdrp_bool_t optimize_surveillance_transitions;

  double optimized_transitions_max_elev_error;

  tdrp_bool_t trim_surveillance_sweeps_to_360deg;

  tdrp_bool_t remove_rays_with_antenna_transitions;

  int transition_nrays_margin;

  tdrp_bool_t compute_sweep_fixed_angles_from_rays;

  tdrp_bool_t compute_sweep_modes_from_ray_angles;

  tdrp_bool_t set_max_range;

  double max_range_km;

  tdrp_bool_t set_ngates_constant;

  tdrp_bool_t set_fixed_angle_limits;

  double lower_fixed_angle_limit;

  double upper_fixed_angle_limit;

  tdrp_bool_t set_sweep_num_limits;

  int lower_sweep_num;

  int upper_sweep_num;

  tdrp_bool_t check_min_rays_in_sweep;

  int min_rays_in_sweep;

  tdrp_bool_t override_radar_location;

  double radar_latitude_deg;

  double radar_longitude_deg;

  double radar_altitude_meters;

  input_covar_t *_input_covars;
  int input_covars_n;

  tdrp_bool_t compute_vol_noise_stats;

  double vol_noise_stats_min_elev_deg;

  double vol_noise_stats_max_elev_deg;

  int noise_ngates_kernel;

  int noise_min_ngates_for_ray_median;

  noise_method_t noise_method;

  int noise_ngates_for_running_median;

  interest_map_point_t *_phase_change_error_for_noise_interest_map;
  int phase_change_error_for_noise_interest_map_n;

  double phase_change_error_for_noise_interest_weight;

  interest_map_point_t *_dbm_sdev_for_noise_interest_map;
  int dbm_sdev_for_noise_interest_map_n;

  double dbm_sdev_for_noise_interest_weight;

  interest_map_point_t *_ncp_mean_for_noise_interest_map;
  int ncp_mean_for_noise_interest_map_n;

  double ncp_mean_for_noise_interest_weight;

  double interest_threshold_for_noise;

  interest_map_point_t *_phase_change_error_for_signal_interest_map;
  int phase_change_error_for_signal_interest_map_n;

  double phase_change_error_for_signal_interest_weight;

  interest_map_point_t *_dbm_sdev_for_signal_interest_map;
  int dbm_sdev_for_signal_interest_map_n;

  double dbm_sdev_for_signal_interest_weight;

  double interest_threshold_for_signal;

  xmit_rcv_mode_t xmit_rcv_mode;

  tdrp_bool_t use_estimated_noise_for_noise_subtraction;

  tdrp_bool_t correct_for_system_phidp;

  tdrp_bool_t change_velocity_sign;

  tdrp_bool_t use_hybrid_for_width;

  double min_snr_db_for_zdr;

  double min_snr_db_for_ldr;

  cal_file_t *_cal_files;
  int cal_files_n;

  tdrp_bool_t override_cal_system_phidp;

  double system_phidp_deg;

  tdrp_bool_t change_phidp_sign;

  tdrp_bool_t override_cal_dbz_correction;

  double dbz_correction;

  tdrp_bool_t override_cal_ldr_correction;

  double ldr_correction_db_h;

  double ldr_correction_db_v;

  tdrp_bool_t override_cal_zdr_correction;

  double zdr_correction_db;

  tdrp_bool_t use_temperature_based_zdr_correction;

  char* site_temp_spdb_url;

  char* site_temp_station_name;

  int site_temp_search_margin_secs;

  double temp_based_zdr_correction_slope;

  double temp_based_zdr_correction_intercept;

  tdrp_bool_t adjust_calibration_for_measured_xmit_power;

  double min_valid_measured_xmit_power_dbm;

  double max_valid_measured_xmit_power_dbm;

  double measured_xmit_power_correction_db;

  tdrp_bool_t swap_measured_xmit_power_channels;

  atmos_atten_method_t atmos_atten_method;

  double atmos_atten_db_per_km;

  tdrp_bool_t apply_precip_attenuation_correction;

  tdrp_bool_t specify_coefficients_for_attenuation_correction;

  double dbz_attenuation_coefficient;

  double dbz_attenuation_exponent;

  double zdr_attenuation_coefficient;

  double zdr_attenuation_exponent;

  fir_filter_len_t KDP_fir_filter_len;

  int KDP_n_filt_iterations_unfolded;

  int KDP_n_filt_iterations_conditioned;

  tdrp_bool_t KDP_use_iterative_filtering;

  double KDP_phidp_difference_threshold;

  int KDP_ngates_for_stats;

  double KDP_phidp_sdev_max;

  double KDP_phidp_jitter_max;

  double KDP_min_valid_abs_kdp;

  tdrp_bool_t KDP_check_snr;

  double KDP_snr_threshold;

  tdrp_bool_t KDP_check_rhohv;

  double KDP_rhohv_threshold;

  tdrp_bool_t KDP_check_zdr_sdev;

  double KDP_zdr_sdev_max;

  tdrp_bool_t KDP_debug;

  tdrp_bool_t KDP_write_ray_files;

  char* KDP_ray_files_dir;

  tdrp_bool_t load_alt_vel_alt_test_fields;

  output_field_t *_output_fields;
  int output_fields_n;

  tdrp_bool_t add_echo_fields_to_output;

  echo_field_t *_echo_fields;
  int echo_fields_n;

  tdrp_bool_t add_merged_fields_to_output;

  char* merge_input_dir;

  merge_field_t *_merge_fields;
  int merge_fields_n;

  double merge_file_time_tolerance_sec;

  double merge_ray_time_tolerance_sec;

  double merge_ray_elevation_tolerance_deg;

  double merge_ray_azimuth_tolerance_deg;

  tdrp_bool_t merge_ray_check_fixed_angle;

  censoring_mode_t censoring_mode;

  double censoring_snr_threshold;

  double censoring_ncp_threshold;

  tdrp_bool_t write_censor_flag_to_output;

  output_format_t output_format;

  netcdf_style_t netcdf_style;

  tdrp_bool_t output_native_byte_order;

  tdrp_bool_t output_compressed;

  tdrp_bool_t output_force_ngates_vary;

  int compression_level;

  char* output_dir;

  filename_mode_t output_filename_mode;

  char* output_filename;

  tdrp_bool_t append_day_dir_to_output_dir;

  tdrp_bool_t append_year_dir_to_output_dir;

  tdrp_bool_t write_individual_sweeps;

  tdrp_bool_t override_missing_metadata_values;

  double missing_metadata_double;

  float missing_metadata_float;

  int missing_metadata_int;

  int missing_metadata_char;

  tdrp_bool_t override_missing_field_values;

  double missing_field_fl64;

  double missing_field_fl32;

  int missing_field_si32;

  int missing_field_si16;

  int missing_field_si08;

  tdrp_bool_t write_status_to_spdb;

  char* status_spdb_output_url;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[176];

  const char *_className;

  bool _exitDeferred;

};

#endif

