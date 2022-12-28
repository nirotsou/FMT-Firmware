/*
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1070
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Dec 28 14:00:35 2022
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
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

#include "Controller_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T DiscreteTimeIntegrator4_DSTATE;/* '<S10>/Discrete-Time Integrator4' */
  real32_T UD_DSTATE;                  /* '<S9>/UD' */
  real32_T DiscreteTimeIntegrator5_DSTATE;/* '<S10>/Discrete-Time Integrator5' */
  real32_T UD_DSTATE_e;                /* '<S8>/UD' */
  real32_T Delay1_DSTATE;              /* '<S6>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S6>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S10>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S10>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S10>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator3_DSTATE;/* '<S10>/Discrete-Time Integrator3' */
  uint32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S5>/Discrete-Time Integrator' */
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

/* Real-time Model Data Structure */
struct tag_RTM_Controller_T {
  const char_T *errorStatus;
};

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
extern struct_aVviZl6VLYA7Cmb29q6WeC CONTROL_PARAM;/* Variable: CONTROL_PARAM
                                                    * Referenced by:
                                                    *   '<S2>/Constant'
                                                    *   '<S2>/Constant1'
                                                    *   '<S2>/Constant2'
                                                    *   '<S2>/Constant3'
                                                    *   '<S2>/Constant4'
                                                    *   '<S2>/Constant5'
                                                    *   '<S2>/Constant6'
                                                    *   '<S2>/Constant7'
                                                    */
extern struct_j3HEuq2gKBtBznker0ckFF CONTROL_EXPORT;/* Variable: CONTROL_EXPORT
                                                     * Referenced by: '<S5>/Constant'
                                                     */

/* Model entry point functions */
extern void Controller_init(void);
extern void Controller_step(void);
extern void Controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_T *const Controller_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Bias' : Eliminated nontunable bias of 0
 * Block '<S2>/Bias1' : Eliminated nontunable bias of 0
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
 * '<S4>'   : 'Controller/Bus_Constructor/Compare To Constant1'
 * '<S5>'   : 'Controller/Bus_Constructor/timestamp'
 * '<S6>'   : 'Controller/Controller/ESO_trigger_controller'
 * '<S7>'   : 'Controller/Controller/Vector Modulus'
 * '<S8>'   : 'Controller/Controller/ESO_trigger_controller/Discrete Derivative'
 * '<S9>'   : 'Controller/Controller/ESO_trigger_controller/Discrete Derivative1'
 * '<S10>'  : 'Controller/Controller/ESO_trigger_controller/ESO'
 * '<S11>'  : 'Controller/Controller/ESO_trigger_controller/control law'
 * '<S12>'  : 'Controller/Controller/ESO_trigger_controller/event trigger'
 * '<S13>'  : 'Controller/Controller/ESO_trigger_controller/ESO/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
