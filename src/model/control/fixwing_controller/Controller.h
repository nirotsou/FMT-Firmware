/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 6.6
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue May 23 19:41:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"
#include "MW_target_hardware_resources.h"
#include "mw_cmsis.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T MatrixConcatenate[12];      /* '<S43>/Matrix Concatenate' */
  real32_T Cos1;                       /* '<S12>/Cos1' */
  real32_T phi_cmd;                    /* '<S29>/Switch' */
  real32_T Sqrt_g;                     /* '<S34>/Sqrt' */
} B_Controller_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T _DSTATE;                    /* '<S40>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S41>/Discrete-Time Integrator1' */
  real32_T _DSTATE_n;                  /* '<S37>/ ' */
  real32_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S38>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE[3];/* '<S16>/Discrete-Time Integrator' */
  uint32_T DiscreteTimeIntegrator_DSTATE_n;/* '<S4>/Discrete-Time Integrator' */
  int8_T _PrevResetState;              /* '<S40>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S41>/Discrete-Time Integrator1' */
  int8_T _PrevResetState_c;            /* '<S37>/ ' */
  int8_T DiscreteTimeIntegrator1_PrevR_b;/* '<S38>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S16>/Discrete-Time Integrator' */
} DW_Controller_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  FMS_Out_Bus FMS_Out;                 /* '<Root>/FMS_Out' */
  INS_Out_Bus INS_Out;                 /* '<Root>/INS_Out' */
} ExtU_Controller_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  Control_Out_Bus Control_Out;         /* '<Root>/Control_Out' */
} ExtY_Controller_T;

/* Parameters (default storage) */
struct P_Controller_T_ {
  uint8_T CompareToConstant_const[3]; /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S46>/Constant'
                                       */
  uint8_T CompareToConstant_const_o;/* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S35>/Constant'
                                     */
  uint8_T CompareToConstant_const_k[2];
                                    /* Mask Parameter: CompareToConstant_const_k
                                     * Referenced by: '<S25>/Constant'
                                     */
  uint8_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S26>/Constant'
                                      */
  uint8_T CompareToConstant_const_kq;
                                   /* Mask Parameter: CompareToConstant_const_kq
                                    * Referenced by: '<S27>/Constant'
                                    */
  uint8_T CompareToConstant_const_m;/* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S3>/Constant'
                                     */
  Control_Out_Bus Constant_Value;      /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S1>/Constant'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real32_T cruise_throttle_Value;   /* Computed Parameter: cruise_throttle_Value
                                     * Referenced by: '<S45>/cruise_throttle'
                                     */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<S31>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<S31>/Saturation1'
                                      */
  real32_T Saturation2_UpperSat;     /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S9>/Saturation2'
                                      */
  real32_T Saturation2_LowerSat;     /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S9>/Saturation2'
                                      */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S45>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S45>/Saturation'
                                       */
  real32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real32_T Saturation1_UpperSat_j; /* Computed Parameter: Saturation1_UpperSat_j
                                    * Referenced by: '<S10>/Saturation1'
                                    */
  real32_T Saturation1_LowerSat_f; /* Computed Parameter: Saturation1_LowerSat_f
                                    * Referenced by: '<S10>/Saturation1'
                                    */
  real32_T Saturation_UpperSat_e;   /* Computed Parameter: Saturation_UpperSat_e
                                     * Referenced by: '<S14>/Saturation'
                                     */
  real32_T Saturation_LowerSat_m;   /* Computed Parameter: Saturation_LowerSat_m
                                     * Referenced by: '<S14>/Saturation'
                                     */
  real32_T Saturation_UpperSat_j;   /* Computed Parameter: Saturation_UpperSat_j
                                     * Referenced by: '<S15>/Saturation'
                                     */
  real32_T Saturation_LowerSat_d;   /* Computed Parameter: Saturation_LowerSat_d
                                     * Referenced by: '<S15>/Saturation'
                                     */
  real32_T Saturation1_UpperSat_a; /* Computed Parameter: Saturation1_UpperSat_a
                                    * Referenced by: '<S9>/Saturation1'
                                    */
  real32_T Saturation1_LowerSat_l; /* Computed Parameter: Saturation1_LowerSat_l
                                    * Referenced by: '<S9>/Saturation1'
                                    */
  real32_T Constant11_Value;           /* Computed Parameter: Constant11_Value
                                        * Referenced by: '<S43>/Constant11'
                                        */
  real32_T Constant10_Value;           /* Computed Parameter: Constant10_Value
                                        * Referenced by: '<S43>/Constant10'
                                        */
  real32_T Constant9_Value;            /* Computed Parameter: Constant9_Value
                                        * Referenced by: '<S43>/Constant9'
                                        */
  real32_T Constant8_Value;            /* Computed Parameter: Constant8_Value
                                        * Referenced by: '<S43>/Constant8'
                                        */
  real32_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S43>/Constant6'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S43>/Constant5'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S43>/Constant4'
                                        */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S43>/Constant3'
                                        */
  real32_T Gain_Gain[4];               /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S9>/Gain'
                                        */
  real32_T Bias_Bias;                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S9>/Bias'
                                        */
  real32_T Gain1_Gain_h;               /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S38>/Gain1'
                                        */
  real32_T Saturation1_UpperSat_i; /* Computed Parameter: Saturation1_UpperSat_i
                                    * Referenced by: '<S30>/Saturation1'
                                    */
  real32_T Saturation1_LowerSat_g; /* Computed Parameter: Saturation1_LowerSat_g
                                    * Referenced by: '<S30>/Saturation1'
                                    */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S33>/Gain'
                                        */
  real32_T Saturation_UpperSat_i;   /* Computed Parameter: Saturation_UpperSat_i
                                     * Referenced by: '<S34>/Saturation'
                                     */
  real32_T Saturation_LowerSat_e;   /* Computed Parameter: Saturation_LowerSat_e
                                     * Referenced by: '<S34>/Saturation'
                                     */
  real32_T Saturation1_UpperSat_d; /* Computed Parameter: Saturation1_UpperSat_d
                                    * Referenced by: '<S34>/Saturation1'
                                    */
  real32_T Saturation1_LowerSat_i; /* Computed Parameter: Saturation1_LowerSat_i
                                    * Referenced by: '<S34>/Saturation1'
                                    */
  real32_T Saturation_UpperSat_b;   /* Computed Parameter: Saturation_UpperSat_b
                                     * Referenced by: '<S42>/Saturation'
                                     */
  real32_T Saturation_LowerSat_h;   /* Computed Parameter: Saturation_LowerSat_h
                                     * Referenced by: '<S42>/Saturation'
                                     */
  real32_T Zero_Value;                 /* Computed Parameter: Zero_Value
                                        * Referenced by: '<S8>/Zero'
                                        */
  real32_T g_force_Gain;               /* Computed Parameter: g_force_Gain
                                        * Referenced by: '<S8>/g_force'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S34>/Gain'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S34>/Switch'
                                        */
  real32_T Switch_Threshold_a;         /* Computed Parameter: Switch_Threshold_a
                                        * Referenced by: '<S33>/Switch'
                                        */
  real32_T Switch_Threshold_o;         /* Computed Parameter: Switch_Threshold_o
                                        * Referenced by: '<S42>/Switch'
                                        */
  real32_T Saturation_UpperSat_es; /* Computed Parameter: Saturation_UpperSat_es
                                    * Referenced by: '<S32>/Saturation'
                                    */
  real32_T Saturation_LowerSat_k;   /* Computed Parameter: Saturation_LowerSat_k
                                     * Referenced by: '<S32>/Saturation'
                                     */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S32>/Gain'
                                        */
  real32_T Gain1_Gain_f;               /* Computed Parameter: Gain1_Gain_f
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real32_T Zero_Value_b;               /* Computed Parameter: Zero_Value_b
                                        * Referenced by: '<S40>/Zero'
                                        */
  real32_T _gainval;                   /* Computed Parameter: _gainval
                                        * Referenced by: '<S40>/ '
                                        */
  real32_T _UpperSat;                  /* Computed Parameter: _UpperSat
                                        * Referenced by: '<S40>/ '
                                        */
  real32_T _LowerSat;                  /* Computed Parameter: _LowerSat
                                        * Referenced by: '<S40>/ '
                                        */
  real32_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S41>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                * Referenced by: '<S41>/Discrete-Time Integrator1'
                                */
  real32_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S41>/Gain'
                                        */
  real32_T Zero1_Value;                /* Computed Parameter: Zero1_Value
                                        * Referenced by: '<S37>/Zero1'
                                        */
  real32_T _gainval_l;                 /* Computed Parameter: _gainval_l
                                        * Referenced by: '<S37>/ '
                                        */
  real32_T _UpperSat_a;                /* Computed Parameter: _UpperSat_a
                                        * Referenced by: '<S37>/ '
                                        */
  real32_T _LowerSat_k;                /* Computed Parameter: _LowerSat_k
                                        * Referenced by: '<S37>/ '
                                        */
  real32_T DiscreteTimeIntegrator1_gainv_g;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_g
                           * Referenced by: '<S38>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC_i;
                             /* Computed Parameter: DiscreteTimeIntegrator1_IC_i
                              * Referenced by: '<S38>/Discrete-Time Integrator1'
                              */
  real32_T Gain_Gain_in;               /* Computed Parameter: Gain_Gain_in
                                        * Referenced by: '<S38>/Gain'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S24>/Constant'
                                        */
  real32_T Saturation_UpperSat_k;   /* Computed Parameter: Saturation_UpperSat_k
                                     * Referenced by: '<S24>/Saturation'
                                     */
  real32_T Saturation_LowerSat_j;   /* Computed Parameter: Saturation_LowerSat_j
                                     * Referenced by: '<S24>/Saturation'
                                     */
  real32_T Constant_Value_c[3];        /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S16>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S16>/Discrete-Time Integrator'
                            */
  uint32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S45>/Constant1'
                                        */
  uint32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S4>/Discrete-Time Integrator'
                                 */
  uint16_T Constant_Value_b[10];       /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S9>/Constant'
                                        */
  uint16_T Saturation_UpperSat_o;   /* Computed Parameter: Saturation_UpperSat_o
                                     * Referenced by: '<S9>/Saturation'
                                     */
  uint16_T Saturation_LowerSat_mw; /* Computed Parameter: Saturation_LowerSat_mw
                                    * Referenced by: '<S9>/Saturation'
                                    */
  uint8_T Switch_Threshold_m;          /* Computed Parameter: Switch_Threshold_m
                                        * Referenced by: '<S41>/Switch'
                                        */
  uint8_T Switch_Threshold_p;          /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S38>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Controller_T Controller_P;

/* Block signals (default storage) */
extern B_Controller_T Controller_B;

/* Block states (default storage) */
extern DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controller_T Controller_Y;

/* External data declarations for dependent source files */
extern const Control_Out_Bus Controller_rtZControl_Out_Bus;/* Control_Out_Bus ground */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern struct_ulVIkLBg2wNIc1YufVcJJE CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S7>/Gain'
                                                    *   '<S7>/Gain1'
                                                    *   '<S7>/balabnce_ratio2'
                                                    *   '<S7>/balance_ratio'
                                                    *   '<S7>/pitch_ff'
                                                    *   '<S7>/thorttle_ff'
                                                    *   '<S7>/ucmd2pitch'
                                                    *   '<S7>/ucmd2thor'
                                                    *   '<S7>/wcmd2pitch'
                                                    *   '<S7>/wcmd2thor'
                                                    *   '<S8>/Saturation'
                                                    *   '<S10>/FF'
                                                    *   '<S10>/FF_limit'
                                                    *   '<S10>/PI_limit'
                                                    *   '<S30>/P_control'
                                                    *   '<S31>/P_control'
                                                    *   '<S43>/Constant1'
                                                    *   '<S43>/Constant12'
                                                    *   '<S43>/Constant2'
                                                    *   '<S43>/Constant7'
                                                    *   '<S14>/trim_speed'
                                                    *   '<S15>/trim_speed'
                                                    *   '<S33>/Constant'
                                                    *   '<S34>/Constant'
                                                    *   '<S36>/Gain'
                                                    *   '<S37>/Gain3'
                                                    *   '<S39>/Gain'
                                                    *   '<S40>/Gain'
                                                    *   '<S42>/Constant'
                                                    *   '<S16>/gain1'
                                                    *   '<S16>/gain2'
                                                    *   '<S16>/gain3'
                                                    *   '<S16>/Discrete-Time Integrator'
                                                    *   '<S17>/gain1'
                                                    *   '<S17>/gain2'
                                                    *   '<S17>/gain3'
                                                    *   '<S21>/Pitch Offset'
                                                    *   '<S21>/Saturation'
                                                    *   '<S22>/Constant1'
                                                    *   '<S22>/Constant2'
                                                    */
extern struct_HQfLeQtLjxtu3IdJj406WE CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
                                                     * Referenced by: '<S4>/Constant'
                                                     */

/* Model entry point functions */
extern void Controller_init(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Logical Operator1' : Eliminated due to no operation
 * Block '<S29>/Logical Operator' : Eliminated due to no operation
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Controller'
 * '<S1>'   : 'Controller/Bus_Constructor'
 * '<S2>'   : 'Controller/Controller'
 * '<S3>'   : 'Controller/Bus_Constructor/Compare To Constant'
 * '<S4>'   : 'Controller/Bus_Constructor/timestamp'
 * '<S5>'   : 'Controller/Controller/Attitude_Control'
 * '<S6>'   : 'Controller/Controller/Signal_Select'
 * '<S7>'   : 'Controller/Controller/TECS_Core'
 * '<S8>'   : 'Controller/Controller/Velocity_Control'
 * '<S9>'   : 'Controller/Controller/mixer'
 * '<S10>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control'
 * '<S11>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control'
 * '<S12>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/Euler To Angle Rate'
 * '<S13>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control'
 * '<S14>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_scaler'
 * '<S15>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/VT_scaler'
 * '<S16>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/I_Control'
 * '<S17>'  : 'Controller/Controller/Attitude_Control/Innerloop_Rate_Control/PI_Control/P_Control'
 * '<S18>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller'
 * '<S19>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller'
 * '<S20>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select'
 * '<S21>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error'
 * '<S22>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/P_Controller'
 * '<S23>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Attitude_Controller/Error/Bus_Select'
 * '<S24>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Heading_Controller/Turning_Coordination'
 * '<S25>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant'
 * '<S26>'  : 'Controller/Controller/Attitude_Control/Outloop_Angle_Control/Signal_Select/Compare To Constant1'
 * '<S27>'  : 'Controller/Controller/Signal_Select/Compare To Constant'
 * '<S28>'  : 'Controller/Controller/TECS_Core/path_angle_control'
 * '<S29>'  : 'Controller/Controller/TECS_Core/phi_cmd'
 * '<S30>'  : 'Controller/Controller/TECS_Core/pitch_pid_out'
 * '<S31>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out'
 * '<S32>'  : 'Controller/Controller/TECS_Core/velocity_control'
 * '<S33>'  : 'Controller/Controller/TECS_Core/path_angle_control/Subsystem'
 * '<S34>'  : 'Controller/Controller/TECS_Core/path_angle_control/Subsystem1'
 * '<S35>'  : 'Controller/Controller/TECS_Core/phi_cmd/Compare To Constant'
 * '<S36>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control'
 * '<S37>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/I_control'
 * '<S38>'  : 'Controller/Controller/TECS_Core/pitch_pid_out/D_control/DT Filter'
 * '<S39>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control'
 * '<S40>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/I_control'
 * '<S41>'  : 'Controller/Controller/TECS_Core/thorttle_pid_out/D_control/DT Filter'
 * '<S42>'  : 'Controller/Controller/TECS_Core/velocity_control/speed_ax_out'
 * '<S43>'  : 'Controller/Controller/mixer/Effective_Matrix'
 * '<S44>'  : 'Controller/Controller/mixer/Signal_Select'
 * '<S45>'  : 'Controller/Controller/mixer/throttle_mapping'
 * '<S46>'  : 'Controller/Controller/mixer/Signal_Select/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
