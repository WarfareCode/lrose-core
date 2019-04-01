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
// Code for program Sprite
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
    REALTIME_FMQ_MODE = 0,
    REALTIME_TCP_MODE = 1,
    ARCHIVE_TIME_MODE = 2,
    FILE_LIST_MODE = 3,
    FOLLOW_MOMENTS_MODE = 4
  } input_mode_t;

  typedef enum {
    LEGEND_TOP_LEFT = 0,
    LEGEND_TOP_RIGHT = 1,
    LEGEND_BOTTOM_LEFT = 2,
    LEGEND_BOTTOM_RIGHT = 3
  } legend_pos_t;

  typedef enum {
    DBZ = 0,
    VEL = 1,
    WIDTH = 2,
    NCP = 3,
    SNR = 4,
    DBM = 5,
    ZDR = 6,
    LDR = 7,
    RHOHV = 8,
    PHIDP = 9,
    KDP = 10
  } moment_type_t;

  typedef enum {
    WIDTH_METHOD_R0R1 = 0,
    WIDTH_METHOD_R1R2 = 1,
    WIDTH_METHOD_HYBRID = 2
  } spectrum_width_method_t;

  typedef enum {
    FIR_LEN_125 = 0,
    FIR_LEN_60 = 1,
    FIR_LEN_40 = 2,
    FIR_LEN_30 = 3,
    FIR_LEN_20 = 4,
    FIR_LEN_10 = 5
  } fir_filter_len_t;

  typedef enum {
    WINDOW_RECT = 0,
    WINDOW_VONHANN = 1,
    WINDOW_BLACKMAN = 2,
    WINDOW_BLACKMAN_NUTTALL = 3,
    WINDOW_TUKEY_10 = 4,
    WINDOW_TUKEY_20 = 5,
    WINDOW_TUKEY_30 = 6,
    WINDOW_TUKEY_50 = 7
  } window_t;

  // struct typedefs

  typedef struct {
    tdrp_bool_t azimuth;
    tdrp_bool_t elevation;
    tdrp_bool_t fixed_angle;
    tdrp_bool_t volume_number;
    tdrp_bool_t sweep_number;
    tdrp_bool_t n_samples;
    tdrp_bool_t n_gates;
    tdrp_bool_t gate_length;
    tdrp_bool_t pulse_width;
    tdrp_bool_t prf_mode;
    tdrp_bool_t prf;
    tdrp_bool_t nyquist;
    tdrp_bool_t max_range;
    tdrp_bool_t unambiguous_range;
    tdrp_bool_t measured_power_h;
    tdrp_bool_t measured_power_v;
    tdrp_bool_t scan_name;
    tdrp_bool_t scan_mode;
    tdrp_bool_t polarization_mode;
    tdrp_bool_t latitude;
    tdrp_bool_t longitude;
    tdrp_bool_t altitude;
    tdrp_bool_t sun_elevation;
    tdrp_bool_t sun_azimuth;
  } show_status_t;

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

  tdrp_bool_t register_with_procmap;

  char* instance;

  tdrp_bool_t check_alloc;

  input_mode_t input_mode;

  char* input_fmq_url;

  tdrp_bool_t seek_to_start_of_fmq;

  char* input_tcp_address;

  int input_tcp_port;

  char* archive_data_dir;

  char* archive_start_time;

  double archive_time_span_secs;

  int moments_shmem_key;

  double moments_max_search_angle_error;

  show_status_t show_status_in_gui;

  double max_range_km;

  int main_window_width;

  int main_window_height;

  int main_window_start_x;

  int main_window_start_y;

  int main_window_title_margin;

  int main_title_font_size;

  char* main_title_color;

  int main_label_font_size;

  char* main_background_color;

  int main_window_panel_divider_line_width;

  char* main_window_panel_divider_color;

  int main_color_scale_width;

  int click_cross_size;

  int spectra_n_rows;

  int spectra_n_columns;

  int spectra_top_margin;

  int spectra_bottom_margin;

  int spectra_left_margin;

  int spectra_right_margin;

  tdrp_bool_t spectra_axis_tick_labels_inside;

  int spectra_axis_tick_len;

  int spectra_n_ticks_ideal;

  int spectra_title_text_margin;

  int spectra_legend_text_margin;

  int spectra_axis_text_margin;

  double spectra_time_span_secs;

  double spectra_min_amplitude;

  double spectra_max_amplitude;

  double spectra_min_secs_between_rendering;

  int spectra_title_font_size;

  int spectra_axis_label_font_size;

  int spectra_tick_values_font_size;

  int spectra_legend_font_size;

  char* spectra_title_color;

  char* spectra_axes_color;

  char* spectra_grid_color;

  char* spectra_labels_color;

  tdrp_bool_t spectra_y_grid_lines_on;

  tdrp_bool_t spectra_x_grid_lines_on;

  tdrp_bool_t spectra_draw_instrument_height_line;

  legend_pos_t spectra_main_legend_pos;

  tdrp_bool_t spectra_plot_legend1;

  legend_pos_t spectra_legend1_pos;

  legend_pos_t spectra_legend2_pos;

  tdrp_bool_t spectra_plot_legend2;

  int ascope_n_panels_in_spectra_window;

  moment_type_t *_ascope_moments;
  int ascope_moments_n;

  int ascope_width_in_spectra_window;

  int ascope_left_margin;

  int ascope_bottom_margin;

  char* ascope_axis_label_color;

  char* ascope_line_color;

  char* ascope_fill_color;

  char* ascope_title_color;

  tdrp_bool_t apply_residue_correction_in_adaptive_filter;

  double min_snr_db_for_residue_correction;

  tdrp_bool_t use_polynomial_regression_clutter_filter;

  int regression_filter_polynomial_order;

  tdrp_bool_t regression_filter_interp_across_notch;

  tdrp_bool_t use_simple_notch_clutter_filter;

  double simple_notch_filter_width_mps;

  int staggered_prt_median_filter_len;

  spectrum_width_method_t spectrum_width_method;

  fir_filter_len_t KDP_fir_filter_len;

  int KDP_n_filt_iterations_unfolded;

  int KDP_n_filt_iterations_conditioned;

  tdrp_bool_t KDP_use_iterative_filtering;

  double KDP_phidp_difference_threshold;

  int KDP_ngates_for_stats;

  double KDP_phidp_sdev_max;

  double KDP_phidp_jitter_max;

  tdrp_bool_t KDP_check_snr;

  double KDP_snr_threshold;

  tdrp_bool_t KDP_check_rhohv;

  double KDP_rhohv_threshold;

  tdrp_bool_t KDP_check_zdr_sdev;

  double KDP_zdr_sdev_max;

  double KDP_min_valid_abs_kdp;

  tdrp_bool_t KDP_debug;

  int n_samples;

  tdrp_bool_t indexed_beams;

  double indexed_resolution_ppi;

  double indexed_resolution_rhi;

  tdrp_bool_t invert_hv_flag;

  tdrp_bool_t prt_is_for_previous_interval;

  tdrp_bool_t check_for_missing_pulses;

  tdrp_bool_t swap_receiver_channels;

  tdrp_bool_t override_radar_name;

  char* radar_name;

  tdrp_bool_t override_radar_location;

  double radar_latitude_deg;

  double radar_longitude_deg;

  double radar_altitude_meters;

  tdrp_bool_t override_gate_geometry;

  double gate_spacing_meters;

  double start_range_meters;

  tdrp_bool_t override_radar_wavelength;

  double radar_wavelength_cm;

  window_t window;

  char* cal_file_path;

  tdrp_bool_t use_cal_from_time_series;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[137];

  const char *_className;

  bool _exitDeferred;

};

#endif

