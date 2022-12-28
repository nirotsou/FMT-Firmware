/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.1069
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Dec 28 11:33:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller.h"
#include "Controller_private.h"

const Control_Out_Bus Controller_rtZControl_Out_Bus = {
  0U,                                  /* timestamp */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  /* actuator_cmd */
} ;                                    /* Control_Out_Bus ground */

/* Exported block parameters */
struct_aVviZl6VLYA7Cmb29q6WeC CONTROL_PARAM = {
  0.06F,
  0.35F,
  12.0F,
  6.0F,
  5.0F,
  3.0F,
  3.0F,
  1.5F
} ;                                    /* Variable: CONTROL_PARAM
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

struct_j3HEuq2gKBtBznker0ckFF CONTROL_EXPORT = {
  10U,

  { 85, 83, 86, 32, 67, 111, 110, 116, 114, 111, 108, 108, 101, 114, 32, 118, 48,
    46, 48, 46, 49, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S5>/Constant'
                                        */

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Model step function */
void Controller_step(void)
{
  real32_T rtb_Sqrt;
  real32_T rtb_TSamp;
  real32_T rtb_TSamp_h;
  real32_T rtb_hir_hat_dot;
  real32_T rtb_tau_iU_n;
  real32_T rtb_tau_ir_n;
  uint16_T rtb_Saturation;
  uint16_T rtb_Saturation1;
  int32_T i;

  /* Sqrt: '<S7>/Sqrt' incorporates:
   *  Inport: '<Root>/INS_Out'
   *  Math: '<S7>/Square'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtSquareInport1'
   *  Sum: '<S7>/Sum of Elements'
   */
  rtb_Sqrt = sqrtf(Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                   Controller_U.INS_Out.ve * Controller_U.INS_Out.ve);

  /* SampleTimeMath: '<S9>/TSamp' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *
   * About '<S9>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = Controller_U.FMS_Out.u_cmd * 100.0F;

  /* SampleTimeMath: '<S8>/TSamp' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *
   * About '<S8>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_h = Controller_U.FMS_Out.r_cmd * 100.0F;

  /* MATLAB Function: '<S6>/control law' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Constant: '<S2>/Constant7'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator4'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator5'
   *  Inport: '<Root>/FMS_Out'
   *  Inport: '<Root>/INS_Out'
   *  Sum: '<S8>/Diff'
   *  Sum: '<S9>/Diff'
   *  UnitDelay: '<S8>/UD'
   *  UnitDelay: '<S9>/UD'
   *
   * Block description for '<S8>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S9>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  rtb_tau_iU_n = ((rtb_Sqrt - Controller_U.FMS_Out.u_cmd) * -CONTROL_PARAM.K_I4
                  - Controller_DW.DiscreteTimeIntegrator4_DSTATE) + (rtb_TSamp -
    Controller_DW.UD_DSTATE);
  rtb_tau_ir_n = ((Controller_U.INS_Out.r - Controller_U.FMS_Out.r_cmd) *
                  -CONTROL_PARAM.K_I5 -
                  Controller_DW.DiscreteTimeIntegrator5_DSTATE) + (rtb_TSamp_h -
    Controller_DW.UD_DSTATE_e);

  /* MATLAB Function: '<S6>/event trigger' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Delay: '<S6>/Delay'
   *  Delay: '<S6>/Delay1'
   */
  if (fabsf(Controller_DW.Delay1_DSTATE - rtb_tau_iU_n) >= fabsf
      (CONTROL_PARAM.ALPHA3 * rtb_tau_iU_n)) {
    Controller_DW.Delay1_DSTATE = rtb_tau_iU_n;
  }

  if (fabsf(Controller_DW.Delay_DSTATE - rtb_tau_ir_n) >= fabsf
      (CONTROL_PARAM.ALPHA4 * rtb_tau_ir_n)) {
    Controller_DW.Delay_DSTATE = rtb_tau_ir_n;
  }

  /* End of MATLAB Function: '<S6>/event trigger' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.status == 3) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S4>/Constant'
     *  RelationalOperator: '<S4>/Compare'
     */
    if (Controller_U.FMS_Out.ctrl_mode != 1) {
      /* Outport: '<Root>/Control_Out' */
      for (i = 0; i < 16; i++) {
        Controller_Y.Control_Out.actuator_cmd[i] =
          Controller_U.FMS_Out.actuator_cmd[i];
      }
    } else {
      /* Gain: '<S2>/Gain' incorporates:
       *  Delay: '<S6>/Delay1'
       */
      rtb_tau_iU_n = fmodf(floorf(Controller_DW.Delay1_DSTATE), 65536.0F);

      /* Saturate: '<S2>/Saturation' incorporates:
       *  Gain: '<S2>/Gain'
       */
      rtb_Saturation = (uint16_T)(rtb_tau_iU_n < 0.0F ? (int32_T)(uint16_T)
        -(int16_T)(uint16_T)-rtb_tau_iU_n : (int32_T)(uint16_T)rtb_tau_iU_n);
      if (rtb_Saturation > 2000) {
        rtb_Saturation = 2000U;
      } else {
        if (rtb_Saturation < 1000) {
          rtb_Saturation = 1000U;
        }
      }

      /* End of Saturate: '<S2>/Saturation' */

      /* Gain: '<S2>/Gain1' incorporates:
       *  Delay: '<S6>/Delay'
       */
      rtb_tau_iU_n = fmodf(floorf(Controller_DW.Delay_DSTATE), 65536.0F);

      /* Saturate: '<S2>/Saturation1' incorporates:
       *  Gain: '<S2>/Gain1'
       */
      rtb_Saturation1 = (uint16_T)(rtb_tau_iU_n < 0.0F ? (int32_T)(uint16_T)
        -(int16_T)(uint16_T)-rtb_tau_iU_n : (int32_T)(uint16_T)rtb_tau_iU_n);
      if (rtb_Saturation1 > 2000) {
        rtb_Saturation1 = 2000U;
      } else {
        if (rtb_Saturation1 < 1000) {
          rtb_Saturation1 = 1000U;
        }
      }

      /* End of Saturate: '<S2>/Saturation1' */

      /* Outport: '<Root>/Control_Out' */
      Controller_Y.Control_Out.actuator_cmd[0] = rtb_Saturation;
      Controller_Y.Control_Out.actuator_cmd[1] = rtb_Saturation;
      Controller_Y.Control_Out.actuator_cmd[2] = rtb_Saturation1;
      Controller_Y.Control_Out.actuator_cmd[3] = rtb_Saturation1;
      for (i = 0; i < 12; i++) {
        Controller_Y.Control_Out.actuator_cmd[i + 4] = 0U;
      }
    }

    /* End of Switch: '<S1>/Switch1' */
  } else {
    /* Outport: '<Root>/Control_Out' */
    for (i = 0; i < 16; i++) {
      Controller_Y.Control_Out.actuator_cmd[i] =
        Controller_U.FMS_Out.actuator_cmd[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S5>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_b;

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   *  Delay: '<S6>/Delay'
   *  Delay: '<S6>/Delay1'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator1'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator2'
   *  DiscreteIntegrator: '<S10>/Discrete-Time Integrator3'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_tau_iU_n = rtb_Sqrt - Controller_DW.DiscreteTimeIntegrator3_DSTATE;
  rtb_Sqrt = (rtb_tau_iU_n * CONTROL_PARAM.KU_I1 +
              Controller_DW.DiscreteTimeIntegrator2_DSTATE) +
    Controller_DW.Delay1_DSTATE;
  rtb_tau_iU_n *= CONTROL_PARAM.KU_I2;
  rtb_hir_hat_dot = Controller_U.INS_Out.r -
    Controller_DW.DiscreteTimeIntegrator1_DSTATE;
  rtb_tau_ir_n = (rtb_hir_hat_dot * CONTROL_PARAM.KR_I1 +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE) +
    Controller_DW.Delay_DSTATE;
  rtb_hir_hat_dot *= CONTROL_PARAM.KR_I2;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator4' */
  Controller_DW.DiscreteTimeIntegrator4_DSTATE += 0.01F * rtb_tau_iU_n;

  /* Update for UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  Controller_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator5' */
  Controller_DW.DiscreteTimeIntegrator5_DSTATE += 0.01F * rtb_hir_hat_dot;

  /* Update for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  Controller_DW.UD_DSTATE_e = rtb_TSamp_h;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S5>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_b += CONTROL_EXPORT.period;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE += 0.01F * rtb_hir_hat_dot;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE += 0.01F * rtb_tau_ir_n;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator2' */
  Controller_DW.DiscreteTimeIntegrator2_DSTATE += 0.01F * rtb_tau_iU_n;

  /* Update for DiscreteIntegrator: '<S10>/Discrete-Time Integrator3' */
  Controller_DW.DiscreteTimeIntegrator3_DSTATE += 0.01F * rtb_Sqrt;
}

/* Model initialize function */
void Controller_init(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Controller_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Controller_DW, 0,
                sizeof(DW_Controller_T));

  /* external inputs */
  (void)memset(&Controller_U, 0, sizeof(ExtU_Controller_T));

  /* external outputs */
  Controller_Y.Control_Out = Controller_rtZControl_Out_Bus;
}

/* Model terminate function */
void Controller_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
