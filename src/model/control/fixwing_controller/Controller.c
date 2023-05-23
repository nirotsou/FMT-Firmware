/*
 * File: Controller.c
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

#include "Controller.h"
#include "Controller_private.h"

const Control_Out_Bus Controller_rtZControl_Out_Bus = {
  0U,                                  /* timestamp */

  {
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
  /* actuator_cmd */
} ;                                    /* Control_Out_Bus ground */

/* Exported block parameters */
struct_ulVIkLBg2wNIc1YufVcJJE CONTROL_PARAM = {
  1.4F,
  0.2F,
  0.2F,
  0.6F,
  0.1F,
  0.0F,
  -1.0F,
  1.0F,
  -1.0F,
  1.0F,
  -0.15F,
  0.15F,
  -0.1F,
  0.1F,
  7.0F,
  7.0F,
  0.785398185F,
  0.1F,
  0.2F,
  0.15F,
  0.1F,
  0.1F,
  0.2F,
  0.003F,
  0.003F,
  0.001F,
  -0.1F,
  0.1F,
  -0.1F,
  0.1F,
  1.57079637F,
  3.14159274F,
  0.5F,
  13.0F,
  0.2F,
  0.3F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.052359879F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.0F,
  0.0F,
  1.0F,
  2.0F,
  2.0F,
  1.0F,
  1.0F,
  2.0F,
  0.1F,
  0.1F,
  0.1F
} ;                                    /* Variable: CONTROL_PARAM
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

struct_HQfLeQtLjxtu3IdJj406WE CONTROL_EXPORT = {
  1U,

  { 70, 105, 120, 119, 105, 110, 103, 95, 67, 111, 110, 116, 114, 111, 108, 108,
    101, 114, 32, 118, 48, 46, 48, 46, 50, 0 }
} ;                                    /* Variable: CONTROL_EXPORT
                                        * Referenced by: '<S4>/Constant'
                                        */

/* Block signals (default storage) */
B_Controller_T Controller_B;

/* Block states (default storage) */
DW_Controller_T Controller_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controller_T Controller_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controller_T Controller_Y;

/* Real-time model */
static RT_MODEL_Controller_T Controller_M_;
RT_MODEL_Controller_T *const Controller_M = &Controller_M_;

/* Model step function */
void Controller_step(void)
{
  int32_T i;
  real32_T rtb_Add;
  real32_T rtb_Add1;
  real32_T rtb_Add2;
  real32_T rtb_E_err;
  real32_T rtb_Gain;
  real32_T rtb_Gain_h;
  real32_T rtb_Multiply4;
  real32_T rtb_Multiply5;
  real32_T rtb_Saturation_b;
  real32_T rtb_Saturation_n;
  real32_T rtb_Sqrt;
  real32_T rtb_Switch;
  real32_T rtb_V;
  real32_T rtb_Vdotg;
  uint16_T rtb_throttle_cmd;

  /* Trigonometry: '<S8>/Atan' incorporates:
   *  Constant: '<S8>/Zero'
   *  Gain: '<S8>/g_force'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S8>/Minus'
   */
  Controller_B.Cos1 = (real32_T)atan((Controller_U.FMS_Out.ay_cmd -
    Controller_P.Zero_Value) * Controller_P.g_force_Gain);

  /* Saturate: '<S8>/Saturation' */
  if (Controller_B.Cos1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    Controller_B.Cos1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (Controller_B.Cos1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    Controller_B.Cos1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S35>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S35>/Compare'
   */
  if (Controller_U.FMS_Out.ctrl_mode == Controller_P.CompareToConstant_const_o)
  {
    Controller_B.phi_cmd = Controller_U.FMS_Out.phi_cmd;
  } else {
    Controller_B.phi_cmd = Controller_B.Cos1;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant'
   */
  if (CONTROL_PARAM.FW_TECS_SWITCH > Controller_P.Switch_Threshold) {
    /* Saturate: '<S34>/Saturation' incorporates:
     *  Inport: '<Root>/INS_Out'
     */
    if (Controller_U.INS_Out.airspeed > Controller_P.Saturation_UpperSat_i) {
      Controller_B.Sqrt_g = Controller_P.Saturation_UpperSat_i;
    } else if (Controller_U.INS_Out.airspeed <
               Controller_P.Saturation_LowerSat_e) {
      Controller_B.Sqrt_g = Controller_P.Saturation_LowerSat_e;
    } else {
      Controller_B.Sqrt_g = Controller_U.INS_Out.airspeed;
    }

    /* End of Saturate: '<S34>/Saturation' */
  } else {
    /* Sqrt: '<S34>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S34>/Square'
     *  Math: '<S34>/Square1'
     *  Math: '<S34>/Square2'
     *  Sum: '<S34>/Add'
     */
    mw_arm_sqrt_f32((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                     Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                    Controller_U.INS_Out.vd * Controller_U.INS_Out.vd,
                    &Controller_B.Sqrt_g);

    /* Saturate: '<S34>/Saturation1' */
    if (Controller_B.Sqrt_g > Controller_P.Saturation1_UpperSat_d) {
      Controller_B.Sqrt_g = Controller_P.Saturation1_UpperSat_d;
    } else if (Controller_B.Sqrt_g < Controller_P.Saturation1_LowerSat_i) {
      Controller_B.Sqrt_g = Controller_P.Saturation1_LowerSat_i;
    }

    /* End of Saturate: '<S34>/Saturation1' */
  }

  /* End of Switch: '<S34>/Switch' */

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant'
   *  Inport: '<Root>/INS_Out'
   *  Trigonometry: '<S33>/Asin'
   */
  if (CONTROL_PARAM.FW_TECS_ANSW > Controller_P.Switch_Threshold_a) {
    /* Sqrt: '<S33>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S33>/Square'
     *  Math: '<S33>/Square1'
     *  Math: '<S33>/Square2'
     *  Sum: '<S33>/Add'
     */
    mw_arm_sqrt_f32((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                     Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                    Controller_U.INS_Out.vd * Controller_U.INS_Out.vd, &rtb_V);

    /* Product: '<S33>/Divide' incorporates:
     *  Gain: '<S33>/Gain'
     *  Inport: '<Root>/INS_Out'
     */
    rtb_Sqrt = 1.0F / rtb_V * (Controller_P.Gain_Gain_f *
      Controller_U.INS_Out.vd);

    /* Trigonometry: '<S33>/Asin' */
    if (rtb_Sqrt > 1.0F) {
      rtb_Sqrt = 1.0F;
    } else if (rtb_Sqrt < -1.0F) {
      rtb_Sqrt = -1.0F;
    }

    rtb_Switch = (real32_T)asin(rtb_Sqrt);
  } else {
    rtb_Switch = Controller_U.INS_Out.theta;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Sum: '<S28>/Minus' incorporates:
   *  Gain: '<S34>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S34>/Divide'
   */
  Controller_B.Sqrt_g = Controller_P.Gain_Gain_m * Controller_U.FMS_Out.w_cmd /
    Controller_B.Sqrt_g - rtb_Switch;

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant'
   *  Inport: '<Root>/INS_Out'
   */
  if (CONTROL_PARAM.FW_TECS_SWITCH > Controller_P.Switch_Threshold_o) {
    rtb_Sqrt = Controller_U.INS_Out.airspeed;
  } else {
    /* Sqrt: '<S42>/Sqrt' incorporates:
     *  Inport: '<Root>/INS_Out'
     *  Math: '<S42>/Square'
     *  Math: '<S42>/Square1'
     *  Math: '<S42>/Square2'
     *  Sum: '<S42>/Add'
     */
    mw_arm_sqrt_f32((Controller_U.INS_Out.vn * Controller_U.INS_Out.vn +
                     Controller_U.INS_Out.ve * Controller_U.INS_Out.ve) +
                    Controller_U.INS_Out.vd * Controller_U.INS_Out.vd, &rtb_Sqrt);

    /* Saturate: '<S42>/Saturation' */
    if (rtb_Sqrt > Controller_P.Saturation_UpperSat_b) {
      rtb_Sqrt = Controller_P.Saturation_UpperSat_b;
    } else if (rtb_Sqrt < Controller_P.Saturation_LowerSat_h) {
      rtb_Sqrt = Controller_P.Saturation_LowerSat_h;
    }

    /* End of Saturate: '<S42>/Saturation' */
  }

  /* End of Switch: '<S42>/Switch' */

  /* Gain: '<S32>/Gain1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Vdotg = Controller_P.Gain1_Gain_f * Controller_U.INS_Out.ax;

  /* Saturate: '<S32>/Saturation' */
  if (rtb_Sqrt > Controller_P.Saturation_UpperSat_es) {
    rtb_Sqrt = Controller_P.Saturation_UpperSat_es;
  } else if (rtb_Sqrt < Controller_P.Saturation_LowerSat_k) {
    rtb_Sqrt = Controller_P.Saturation_LowerSat_k;
  }

  /* End of Saturate: '<S32>/Saturation' */

  /* Sum: '<S32>/Minus1' incorporates:
   *  Gain: '<S32>/Gain'
   *  Inport: '<Root>/FMS_Out'
   *  Sum: '<S32>/Minus'
   */
  rtb_Sqrt = (Controller_U.FMS_Out.u_cmd - rtb_Sqrt) * Controller_P.Gain_Gain_a
    - rtb_Vdotg;

  /* Sum: '<S7>/Add' incorporates:
   *  Gain: '<S7>/ucmd2thor'
   *  Gain: '<S7>/wcmd2thor'
   */
  rtb_E_err = CONTROL_PARAM.FW_TECS_W2T * Controller_B.Sqrt_g +
    CONTROL_PARAM.FW_TECS_U2T * rtb_Sqrt;

  /* DiscreteIntegrator: '<S40>/ ' incorporates:
   *  Constant: '<S40>/Zero'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState != 0))
  {
    Controller_DW._DSTATE = Controller_P.Zero_Value_b;
    if (Controller_DW._DSTATE >= Controller_P._UpperSat) {
      Controller_DW._DSTATE = Controller_P._UpperSat;
    } else if (Controller_DW._DSTATE <= Controller_P._LowerSat) {
      Controller_DW._DSTATE = Controller_P._LowerSat;
    }
  }

  if (Controller_DW._DSTATE >= Controller_P._UpperSat) {
    Controller_DW._DSTATE = Controller_P._UpperSat;
  } else if (Controller_DW._DSTATE <= Controller_P._LowerSat) {
    Controller_DW._DSTATE = Controller_P._LowerSat;
  }

  /* DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTATE =
      Controller_P.DiscreteTimeIntegrator1_IC;
  }

  /* Gain: '<S41>/Gain' incorporates:
   *  DiscreteIntegrator: '<S41>/Discrete-Time Integrator1'
   *  Sum: '<S41>/Sum5'
   */
  rtb_Gain = (rtb_E_err - Controller_DW.DiscreteTimeIntegrator1_DSTATE) *
    Controller_P.Gain_Gain_i;

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  Logic: '<S20>/Logical Operator'
   *  RelationalOperator: '<S25>/Compare'
   */
  if ((Controller_U.FMS_Out.ctrl_mode == Controller_P.CompareToConstant_const_k
       [0]) || (Controller_U.FMS_Out.ctrl_mode ==
                Controller_P.CompareToConstant_const_k[1])) {
    Controller_B.Cos1 = Controller_U.FMS_Out.phi_cmd;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Sum: '<S7>/Minus1' incorporates:
   *  Gain: '<S7>/ucmd2pitch'
   *  Gain: '<S7>/wcmd2pitch'
   */
  rtb_V = CONTROL_PARAM.FW_TECS_W2P * Controller_B.Sqrt_g -
    CONTROL_PARAM.FW_TECS_U2P * rtb_Sqrt;

  /* DiscreteIntegrator: '<S37>/ ' incorporates:
   *  Constant: '<S37>/Zero1'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) || (Controller_DW._PrevResetState_c != 0))
  {
    Controller_DW._DSTATE_n = Controller_P.Zero1_Value;
    if (Controller_DW._DSTATE_n >= Controller_P._UpperSat_a) {
      Controller_DW._DSTATE_n = Controller_P._UpperSat_a;
    } else if (Controller_DW._DSTATE_n <= Controller_P._LowerSat_k) {
      Controller_DW._DSTATE_n = Controller_P._LowerSat_k;
    }
  }

  if (Controller_DW._DSTATE_n >= Controller_P._UpperSat_a) {
    Controller_DW._DSTATE_n = Controller_P._UpperSat_a;
  } else if (Controller_DW._DSTATE_n <= Controller_P._LowerSat_k) {
    Controller_DW._DSTATE_n = Controller_P._LowerSat_k;
  }

  /* DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator1_PrevR_b != 0)) {
    Controller_DW.DiscreteTimeIntegrator1_DSTAT_o =
      Controller_P.DiscreteTimeIntegrator1_IC_i;
  }

  /* Gain: '<S38>/Gain' incorporates:
   *  DiscreteIntegrator: '<S38>/Discrete-Time Integrator1'
   *  Sum: '<S38>/Sum5'
   */
  rtb_Gain_h = (rtb_V - Controller_DW.DiscreteTimeIntegrator1_DSTAT_o) *
    Controller_P.Gain_Gain_in;

  /* Switch: '<S20>/Switch1' incorporates:
   *  Constant: '<S26>/Constant'
   *  DiscreteIntegrator: '<S37>/ '
   *  Gain: '<S30>/P_control'
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/balabnce_ratio2'
   *  Gain: '<S7>/pitch_ff'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S26>/Compare'
   *  Sum: '<S30>/Add'
   *  Sum: '<S7>/Add3'
   *  Sum: '<S7>/Minus'
   *  Sum: '<S7>/Sum'
   *  Switch: '<S38>/Switch'
   */
  if (Controller_U.FMS_Out.ctrl_mode == Controller_P.CompareToConstant1_const) {
    rtb_Sqrt = Controller_U.FMS_Out.theta_cmd;
  } else {
    if (Controller_U.FMS_Out.reset > Controller_P.Switch_Threshold_p) {
      /* Switch: '<S38>/Switch' incorporates:
       *  Gain: '<S38>/Gain1'
       */
      rtb_Multiply5 = Controller_P.Gain1_Gain_h * rtb_Gain_h;
    } else {
      /* Switch: '<S38>/Switch' */
      rtb_Multiply5 = rtb_Gain_h;
    }

    /* Gain: '<S36>/Gain' */
    rtb_Sqrt = CONTROL_PARAM.FW_TECS_PITCH_D * rtb_Multiply5;

    /* Saturate: '<S30>/Saturation1' */
    if (rtb_Sqrt > Controller_P.Saturation1_UpperSat_i) {
      rtb_Sqrt = Controller_P.Saturation1_UpperSat_i;
    } else if (rtb_Sqrt < Controller_P.Saturation1_LowerSat_g) {
      rtb_Sqrt = Controller_P.Saturation1_LowerSat_g;
    }

    /* End of Saturate: '<S30>/Saturation1' */
    rtb_Sqrt = (((2.0F - CONTROL_PARAM.FW_TECS_RATIO) * rtb_Switch - rtb_Vdotg) *
                CONTROL_PARAM.FW_TECS_PITCH_F + ((CONTROL_PARAM.FW_TECS_PITCH_P *
      rtb_V + Controller_DW._DSTATE_n) + rtb_Sqrt)) + CONTROL_PARAM.FW_TECS_R2P *
      Controller_B.phi_cmd;
  }

  /* End of Switch: '<S20>/Switch1' */

  /* Bias: '<S21>/Pitch Offset' */
  rtb_Sqrt += CONTROL_PARAM.FW_PITCH_OFFSET;

  /* Product: '<S24>/Divide' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Add1 = Controller_P.Constant_Value_a / Controller_U.INS_Out.airspeed;

  /* Saturate: '<S24>/Saturation' */
  if (rtb_Add1 > Controller_P.Saturation_UpperSat_k) {
    rtb_Add1 = Controller_P.Saturation_UpperSat_k;
  } else if (rtb_Add1 < Controller_P.Saturation_LowerSat_j) {
    rtb_Add1 = Controller_P.Saturation_LowerSat_j;
  }

  /* End of Saturate: '<S24>/Saturation' */

  /* Sum: '<S19>/Sum' incorporates:
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S24>/Multiply'
   *  Product: '<S24>/Multiply1'
   *  Trigonometry: '<S24>/Cos'
   *  Trigonometry: '<S24>/Tan'
   */
  rtb_Multiply4 = (real32_T)tan(Controller_U.FMS_Out.phi_cmd) * arm_cos_f32
    (Controller_U.FMS_Out.theta_cmd) * rtb_Add1 +
    Controller_U.FMS_Out.psi_rate_cmd;

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Sqrt > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Sqrt = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (rtb_Sqrt < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    rtb_Sqrt = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  }

  /* Reshape: '<S11>/Reshape' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S22>/Multiply'
   *  Sum: '<S21>/Sum'
   */
  Controller_B.Sqrt_g = (rtb_Sqrt - Controller_U.INS_Out.theta) *
    CONTROL_PARAM.PITCH_P;

  /* Saturate: '<S21>/Saturation' */
  if (Controller_B.Cos1 > CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    Controller_B.Cos1 = CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  } else if (Controller_B.Cos1 < -CONTROL_PARAM.ROLL_PITCH_CMD_LIM) {
    Controller_B.Cos1 = -CONTROL_PARAM.ROLL_PITCH_CMD_LIM;
  }

  /* Sum: '<S12>/Add' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Inport: '<Root>/INS_Out'
   *  Product: '<S12>/Multiply'
   *  Product: '<S22>/Multiply'
   *  Reshape: '<S11>/Reshape'
   *  Sum: '<S21>/Sum'
   *  Trigonometry: '<S12>/Sin1'
   */
  rtb_Add = (Controller_B.Cos1 - Controller_U.INS_Out.phi) *
    CONTROL_PARAM.ROLL_P - arm_sin_f32(Controller_U.INS_Out.theta) *
    rtb_Multiply4;

  /* Trigonometry: '<S12>/Sin' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Sqrt = arm_sin_f32(Controller_U.INS_Out.phi);

  /* Trigonometry: '<S12>/Cos1' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  Controller_B.Cos1 = arm_cos_f32(Controller_U.INS_Out.theta);

  /* Trigonometry: '<S12>/Cos' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  rtb_Multiply5 = arm_cos_f32(Controller_U.INS_Out.phi);

  /* Sum: '<S12>/Add1' incorporates:
   *  Product: '<S12>/Multiply1'
   *  Product: '<S12>/Multiply3'
   *  Reshape: '<S11>/Reshape'
   */
  rtb_Add1 = rtb_Sqrt * Controller_B.Cos1 * rtb_Multiply4 + rtb_Multiply5 *
    Controller_B.Sqrt_g;

  /* Sum: '<S12>/Add2' incorporates:
   *  Product: '<S12>/Multiply4'
   *  Product: '<S12>/Multiply5'
   *  Reshape: '<S11>/Reshape'
   */
  rtb_Add2 = rtb_Multiply5 * Controller_B.Cos1 * rtb_Multiply4 - rtb_Sqrt *
    Controller_B.Sqrt_g;

  /* Sum: '<S10>/Minus2' incorporates:
   *  Inport: '<Root>/INS_Out'
   */
  Controller_B.Cos1 = rtb_Add - Controller_U.INS_Out.p;
  Controller_B.Sqrt_g = rtb_Add1 - Controller_U.INS_Out.q;
  rtb_Multiply4 = rtb_Add2 - Controller_U.INS_Out.r;

  /* DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/FMS_Out'
   */
  if ((Controller_U.FMS_Out.reset != 0) ||
      (Controller_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
      Controller_P.Constant_Value_c[0];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
      Controller_P.Constant_Value_c[1];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
    }

    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
      Controller_P.Constant_Value_c[2];
    if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >=
        CONTROL_PARAM.RATE_I_MAX) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
    } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
               CONTROL_PARAM.RATE_I_MIN) {
      Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
    }
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/FMS_Out'
   *  RelationalOperator: '<S3>/Compare'
   */
  if (Controller_U.FMS_Out.status == Controller_P.CompareToConstant_const_m) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S43>/Constant10'
     *  Constant: '<S43>/Constant11'
     *  Constant: '<S43>/Constant12'
     *  Constant: '<S43>/Constant2'
     *  Constant: '<S43>/Constant3'
     *  Constant: '<S43>/Constant4'
     *  Constant: '<S43>/Constant5'
     *  Constant: '<S43>/Constant6'
     *  Constant: '<S43>/Constant7'
     *  Constant: '<S43>/Constant8'
     *  Constant: '<S43>/Constant9'
     *  Inport: '<Root>/INS_Out'
     *  RelationalOperator: '<S27>/Compare'
     *  Saturate: '<S10>/Saturation1'
     */
    if (Controller_U.FMS_Out.ctrl_mode ==
        Controller_P.CompareToConstant_const_kq) {
      /* Outport: '<Root>/Control_Out' */
      for (i = 0; i < 16; i++) {
        Controller_Y.Control_Out.actuator_cmd[i] =
          Controller_U.FMS_Out.actuator_cmd[i];
      }
    } else {
      if (Controller_U.INS_Out.airspeed > Controller_P.Saturation1_UpperSat_j) {
        /* Saturate: '<S10>/Saturation1' */
        rtb_Saturation_b = Controller_P.Saturation1_UpperSat_j;
      } else if (Controller_U.INS_Out.airspeed <
                 Controller_P.Saturation1_LowerSat_f) {
        /* Saturate: '<S10>/Saturation1' */
        rtb_Saturation_b = Controller_P.Saturation1_LowerSat_f;
      } else {
        /* Saturate: '<S10>/Saturation1' incorporates:
         *  Inport: '<Root>/INS_Out'
         */
        rtb_Saturation_b = Controller_U.INS_Out.airspeed;
      }

      /* Product: '<S14>/Divide' incorporates:
       *  Constant: '<S14>/trim_speed'
       *  Inport: '<Root>/INS_Out'
       *  Math: '<S14>/Square'
       *  Math: '<S14>/Square1'
       *  Saturate: '<S10>/Saturation1'
       */
      rtb_Saturation_n = CONTROL_PARAM.FW_AIRSPEED_TRIM *
        CONTROL_PARAM.FW_AIRSPEED_TRIM / (rtb_Saturation_b * rtb_Saturation_b);

      /* Saturate: '<S14>/Saturation' */
      if (rtb_Saturation_n > Controller_P.Saturation_UpperSat_e) {
        rtb_Saturation_n = Controller_P.Saturation_UpperSat_e;
      } else if (rtb_Saturation_n < Controller_P.Saturation_LowerSat_m) {
        rtb_Saturation_n = Controller_P.Saturation_LowerSat_m;
      }

      /* End of Saturate: '<S14>/Saturation' */

      /* Product: '<S15>/Divide' incorporates:
       *  Constant: '<S15>/trim_speed'
       */
      rtb_Saturation_b = CONTROL_PARAM.FW_AIRSPEED_TRIM / rtb_Saturation_b;

      /* Saturate: '<S15>/Saturation' */
      if (rtb_Saturation_b > Controller_P.Saturation_UpperSat_j) {
        rtb_Saturation_b = Controller_P.Saturation_UpperSat_j;
      } else if (rtb_Saturation_b < Controller_P.Saturation_LowerSat_d) {
        rtb_Saturation_b = Controller_P.Saturation_LowerSat_d;
      }

      /* End of Saturate: '<S15>/Saturation' */
      Controller_B.MatrixConcatenate[11] = CONTROL_PARAM.FW_YAW_EFFC;
      Controller_B.MatrixConcatenate[10] = Controller_P.Constant11_Value;
      Controller_B.MatrixConcatenate[9] = Controller_P.Constant10_Value;
      Controller_B.MatrixConcatenate[8] = Controller_P.Constant9_Value;
      Controller_B.MatrixConcatenate[7] = Controller_P.Constant8_Value;
      Controller_B.MatrixConcatenate[6] = CONTROL_PARAM.FW_PITCH_EFFC;
      Controller_B.MatrixConcatenate[5] = Controller_P.Constant6_Value;
      Controller_B.MatrixConcatenate[4] = Controller_P.Constant5_Value;
      Controller_B.MatrixConcatenate[3] = Controller_P.Constant4_Value;
      Controller_B.MatrixConcatenate[2] = Controller_P.Constant3_Value;
      Controller_B.MatrixConcatenate[1] = CONTROL_PARAM.FW_ROLL_EFFC;
      Controller_B.MatrixConcatenate[0] = CONTROL_PARAM.FW_ROLL_EFFC;

      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S43>/Constant1'
       *  Constant: '<S43>/Constant10'
       *  Constant: '<S43>/Constant11'
       *  Constant: '<S43>/Constant12'
       *  Constant: '<S43>/Constant2'
       *  Constant: '<S43>/Constant3'
       *  Constant: '<S43>/Constant4'
       *  Constant: '<S43>/Constant5'
       *  Constant: '<S43>/Constant6'
       *  Constant: '<S43>/Constant7'
       *  Constant: '<S43>/Constant8'
       *  Constant: '<S43>/Constant9'
       *  Constant: '<S45>/Constant1'
       *  Constant: '<S46>/Constant'
       *  DataTypeConversion: '<S45>/Data Type Conversion'
       *  Gain: '<S45>/Gain1'
       *  Logic: '<S44>/Logical Operator'
       *  RelationalOperator: '<S46>/Compare'
       *  Sum: '<S45>/Sum1'
       *  Switch: '<S41>/Switch'
       */
      if ((Controller_U.FMS_Out.ctrl_mode ==
           Controller_P.CompareToConstant_const[0]) ||
          (Controller_U.FMS_Out.ctrl_mode ==
           Controller_P.CompareToConstant_const[1]) ||
          (Controller_U.FMS_Out.ctrl_mode ==
           Controller_P.CompareToConstant_const[2])) {
        rtb_throttle_cmd = Controller_U.FMS_Out.throttle_cmd;
      } else {
        if (Controller_U.FMS_Out.reset > Controller_P.Switch_Threshold_m) {
          /* Switch: '<S41>/Switch' incorporates:
           *  Gain: '<S41>/Gain1'
           */
          rtb_Multiply5 = Controller_P.Gain1_Gain * rtb_Gain;
        } else {
          /* Switch: '<S41>/Switch' */
          rtb_Multiply5 = rtb_Gain;
        }

        /* Gain: '<S39>/Gain' */
        rtb_Sqrt = CONTROL_PARAM.FW_TECS_THOR_D * rtb_Multiply5;

        /* Saturate: '<S31>/Saturation1' */
        if (rtb_Sqrt > Controller_P.Saturation1_UpperSat) {
          rtb_Sqrt = Controller_P.Saturation1_UpperSat;
        } else if (rtb_Sqrt < Controller_P.Saturation1_LowerSat) {
          rtb_Sqrt = Controller_P.Saturation1_LowerSat;
        }

        /* End of Saturate: '<S31>/Saturation1' */

        /* Sum: '<S7>/Sum1' incorporates:
         *  DiscreteIntegrator: '<S40>/ '
         *  Gain: '<S31>/P_control'
         *  Gain: '<S7>/Gain1'
         *  Gain: '<S7>/balance_ratio'
         *  Gain: '<S7>/thorttle_ff'
         *  Sum: '<S31>/Add4'
         *  Sum: '<S7>/Add1'
         *  Sum: '<S7>/Add2'
         */
        rtb_Sqrt = (((CONTROL_PARAM.FW_TECS_THOR_P * rtb_E_err +
                      Controller_DW._DSTATE) + rtb_Sqrt) +
                    (CONTROL_PARAM.FW_TECS_RATIO * rtb_Vdotg + rtb_Switch) *
                    CONTROL_PARAM.FW_TECS_THOR_FF) + CONTROL_PARAM.FW_TECS_R2T *
          Controller_B.phi_cmd;

        /* Saturate: '<S9>/Saturation2' */
        if (rtb_Sqrt > Controller_P.Saturation2_UpperSat) {
          rtb_Sqrt = Controller_P.Saturation2_UpperSat;
        } else if (rtb_Sqrt < Controller_P.Saturation2_LowerSat) {
          rtb_Sqrt = Controller_P.Saturation2_LowerSat;
        }

        /* End of Saturate: '<S9>/Saturation2' */

        /* Sum: '<S45>/Sum' incorporates:
         *  Constant: '<S45>/cruise_throttle'
         */
        rtb_Sqrt += Controller_P.cruise_throttle_Value;

        /* Saturate: '<S45>/Saturation' */
        if (rtb_Sqrt > Controller_P.Saturation_UpperSat) {
          rtb_Sqrt = Controller_P.Saturation_UpperSat;
        } else if (rtb_Sqrt < Controller_P.Saturation_LowerSat) {
          rtb_Sqrt = Controller_P.Saturation_LowerSat;
        }

        /* End of Saturate: '<S45>/Saturation' */

        /* Gain: '<S45>/Gain1' */
        rtb_Multiply5 = (real32_T)fmod((real32_T)floor(Controller_P.Gain1_Gain_p
          * rtb_Sqrt), 4.294967296E+9);
        rtb_throttle_cmd = (uint16_T)((rtb_Multiply5 < 0.0F ? (uint32_T)
          -(int32_T)(uint32_T)-rtb_Multiply5 : (uint32_T)rtb_Multiply5) +
          Controller_P.Constant1_Value);
      }

      /* End of Switch: '<S44>/Switch' */

      /* Gain: '<S10>/FF' incorporates:
       *  Product: '<S10>/Multiply1'
       */
      rtb_Sqrt = CONTROL_PARAM.FW_FF * rtb_Add * rtb_Saturation_b;
      Controller_B.phi_cmd = CONTROL_PARAM.FW_FF * rtb_Add1 * rtb_Saturation_b;
      rtb_Switch = CONTROL_PARAM.FW_FF * rtb_Add2 * rtb_Saturation_b;

      /* Product: '<S17>/Multiply' incorporates:
       *  Constant: '<S17>/gain1'
       *  Constant: '<S17>/gain2'
       *  Constant: '<S17>/gain3'
       *  DiscreteIntegrator: '<S16>/Discrete-Time Integrator'
       *  Product: '<S10>/Multiply'
       *  Sum: '<S13>/Add1'
       */
      rtb_Add1 = (CONTROL_PARAM.ROLL_RATE_P * Controller_B.Cos1 +
                  Controller_DW.DiscreteTimeIntegrator_DSTATE[0]) *
        rtb_Saturation_n;
      rtb_Multiply5 = (CONTROL_PARAM.PITCH_RATE_P * Controller_B.Sqrt_g +
                       Controller_DW.DiscreteTimeIntegrator_DSTATE[1]) *
        rtb_Saturation_n;
      rtb_Vdotg = (CONTROL_PARAM.YAW_RATE_P * rtb_Multiply4 +
                   Controller_DW.DiscreteTimeIntegrator_DSTATE[2]) *
        rtb_Saturation_n;

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Sqrt > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Sqrt = CONTROL_PARAM.FW_FF_LIMIT;
      } else if (rtb_Sqrt < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Sqrt = -CONTROL_PARAM.FW_FF_LIMIT;
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Add1 > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add1 = CONTROL_PARAM.FW_PI_LIMIT;
      } else if (rtb_Add1 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Add1 = -CONTROL_PARAM.FW_PI_LIMIT;
      }

      /* Saturate: '<S9>/Saturation1' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Sqrt += rtb_Add1;
      if (rtb_Sqrt > Controller_P.Saturation1_UpperSat_a) {
        rtb_Sqrt = Controller_P.Saturation1_UpperSat_a;
      } else if (rtb_Sqrt < Controller_P.Saturation1_LowerSat_l) {
        rtb_Sqrt = Controller_P.Saturation1_LowerSat_l;
      }

      /* Saturate: '<S10>/FF_limit' */
      if (Controller_B.phi_cmd > CONTROL_PARAM.FW_FF_LIMIT) {
        Controller_B.phi_cmd = CONTROL_PARAM.FW_FF_LIMIT;
      } else if (Controller_B.phi_cmd < -CONTROL_PARAM.FW_FF_LIMIT) {
        Controller_B.phi_cmd = -CONTROL_PARAM.FW_FF_LIMIT;
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Multiply5 > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply5 = CONTROL_PARAM.FW_PI_LIMIT;
      } else if (rtb_Multiply5 < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Multiply5 = -CONTROL_PARAM.FW_PI_LIMIT;
      }

      /* Saturate: '<S9>/Saturation1' incorporates:
       *  Sum: '<S10>/Add'
       */
      rtb_Add1 = Controller_B.phi_cmd + rtb_Multiply5;
      if (rtb_Add1 > Controller_P.Saturation1_UpperSat_a) {
        rtb_Add1 = Controller_P.Saturation1_UpperSat_a;
      } else if (rtb_Add1 < Controller_P.Saturation1_LowerSat_l) {
        rtb_Add1 = Controller_P.Saturation1_LowerSat_l;
      }

      /* Saturate: '<S10>/FF_limit' */
      if (rtb_Switch > CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Switch = CONTROL_PARAM.FW_FF_LIMIT;
      } else if (rtb_Switch < -CONTROL_PARAM.FW_FF_LIMIT) {
        rtb_Switch = -CONTROL_PARAM.FW_FF_LIMIT;
      }

      /* Saturate: '<S10>/PI_limit' */
      if (rtb_Vdotg > CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Vdotg = CONTROL_PARAM.FW_PI_LIMIT;
      } else if (rtb_Vdotg < -CONTROL_PARAM.FW_PI_LIMIT) {
        rtb_Vdotg = -CONTROL_PARAM.FW_PI_LIMIT;
      }

      /* Saturate: '<S9>/Saturation1' incorporates:
       *  Sum: '<S10>/Add'
       */
      Controller_B.phi_cmd = rtb_Switch + rtb_Vdotg;
      if (Controller_B.phi_cmd > Controller_P.Saturation1_UpperSat_a) {
        Controller_B.phi_cmd = Controller_P.Saturation1_UpperSat_a;
      } else if (Controller_B.phi_cmd < Controller_P.Saturation1_LowerSat_l) {
        Controller_B.phi_cmd = Controller_P.Saturation1_LowerSat_l;
      }

      /* Outport: '<Root>/Control_Out' incorporates:
       *  Reshape: '<S9>/Reshape'
       */
      Controller_Y.Control_Out.actuator_cmd[0] = rtb_throttle_cmd;
      Controller_Y.Control_Out.actuator_cmd[1] = rtb_throttle_cmd;
      for (i = 0; i < 4; i++) {
        /* Saturate: '<S9>/Saturation' incorporates:
         *  Bias: '<S9>/Bias'
         *  Concatenate: '<S43>/Matrix Concatenate'
         *  Gain: '<S9>/Gain'
         *  Product: '<S9>/Multiply'
         */
        rtb_Switch = Controller_P.Gain_Gain[i] *
          (Controller_B.MatrixConcatenate[i + 8] * Controller_B.phi_cmd +
           (Controller_B.MatrixConcatenate[i + 4] * rtb_Add1 +
            Controller_B.MatrixConcatenate[i] * rtb_Sqrt)) +
          Controller_P.Bias_Bias;
        if (rtb_Switch > Controller_P.Saturation_UpperSat_o) {
          rtb_Switch = Controller_P.Saturation_UpperSat_o;
        } else if (rtb_Switch < Controller_P.Saturation_LowerSat_mw) {
          rtb_Switch = Controller_P.Saturation_LowerSat_mw;
        }

        rtb_Multiply5 = (real32_T)fmod((real32_T)floor(rtb_Switch), 65536.0);

        /* Outport: '<Root>/Control_Out' incorporates:
         *  Gain: '<S9>/Gain'
         *  Reshape: '<S9>/Reshape'
         *  Saturate: '<S9>/Saturation'
         */
        Controller_Y.Control_Out.actuator_cmd[i + 2] = (uint16_T)(rtb_Multiply5 <
          0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Multiply5 :
          (int32_T)(uint16_T)rtb_Multiply5);
      }

      /* Outport: '<Root>/Control_Out' incorporates:
       *  Constant: '<S9>/Constant'
       *  Reshape: '<S9>/Reshape'
       */
      for (i = 0; i < 10; i++) {
        Controller_Y.Control_Out.actuator_cmd[i + 6] =
          Controller_P.Constant_Value_b[i];
      }
    }

    /* End of Switch: '<S6>/Switch' */
  } else {
    /* Outport: '<Root>/Control_Out' */
    for (i = 0; i < 16; i++) {
      Controller_Y.Control_Out.actuator_cmd[i] =
        Controller_U.FMS_Out.actuator_cmd[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Outport: '<Root>/Control_Out' incorporates:
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   */
  Controller_Y.Control_Out.timestamp =
    Controller_DW.DiscreteTimeIntegrator_DSTATE_n;

  /* Update for DiscreteIntegrator: '<S40>/ ' incorporates:
   *  Gain: '<S40>/Gain'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE += CONTROL_PARAM.FW_TECS_THOR_I * rtb_E_err *
    Controller_P._gainval;
  if (Controller_DW._DSTATE >= Controller_P._UpperSat) {
    Controller_DW._DSTATE = Controller_P._UpperSat;
  } else if (Controller_DW._DSTATE <= Controller_P._LowerSat) {
    Controller_DW._DSTATE = Controller_P._LowerSat;
  }

  Controller_DW._PrevResetState = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S40>/ ' */

  /* Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE +=
    Controller_P.DiscreteTimeIntegrator1_gainval * rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S37>/ ' incorporates:
   *  Gain: '<S37>/Gain3'
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW._DSTATE_n += CONTROL_PARAM.FW_TECS_PITCH_I * rtb_V *
    Controller_P._gainval_l;
  if (Controller_DW._DSTATE_n >= Controller_P._UpperSat_a) {
    Controller_DW._DSTATE_n = Controller_P._UpperSat_a;
  } else if (Controller_DW._DSTATE_n <= Controller_P._LowerSat_k) {
    Controller_DW._DSTATE_n = Controller_P._LowerSat_k;
  }

  Controller_DW._PrevResetState_c = (int8_T)(Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S37>/ ' */

  /* Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' incorporates:
   *  Inport: '<Root>/FMS_Out'
   */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o +=
    Controller_P.DiscreteTimeIntegrator1_gainv_g * rtb_Gain_h;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/gain1'
   *  Constant: '<S16>/gain2'
   *  Constant: '<S16>/gain3'
   *  Inport: '<Root>/FMS_Out'
   *  Product: '<S16>/Multiply'
   */
  rtb_Multiply5 = Controller_DW.DiscreteTimeIntegrator_DSTATE[0];
  rtb_Gain = Controller_DW.DiscreteTimeIntegrator_DSTATE[1];
  rtb_E_err = Controller_DW.DiscreteTimeIntegrator_DSTATE[2];
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.ROLL_RATE_I *
    Controller_B.Cos1 * Controller_P.DiscreteTimeIntegrator_gainval +
    rtb_Multiply5;
  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.PITCH_RATE_I *
    Controller_B.Sqrt_g * Controller_P.DiscreteTimeIntegrator_gainval + rtb_Gain;
  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.YAW_RATE_I *
    rtb_Multiply4 * Controller_P.DiscreteTimeIntegrator_gainval + rtb_E_err;
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
  }

  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    (Controller_U.FMS_Out.reset > 0);

  /* End of Update for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n += CONTROL_EXPORT.period;
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

  /* InitializeConditions for DiscreteIntegrator: '<S40>/ ' incorporates:
   *  Constant: '<S40>/Zero'
   */
  Controller_DW._DSTATE = Controller_P.Zero_Value_b;
  if (Controller_DW._DSTATE >= Controller_P._UpperSat) {
    Controller_DW._DSTATE = Controller_P._UpperSat;
  } else if (Controller_DW._DSTATE <= Controller_P._LowerSat) {
    Controller_DW._DSTATE = Controller_P._LowerSat;
  }

  Controller_DW._PrevResetState = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S40>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTATE =
    Controller_P.DiscreteTimeIntegrator1_IC;
  Controller_DW.DiscreteTimeIntegrator1_PrevRes = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S37>/ ' incorporates:
   *  Constant: '<S37>/Zero1'
   */
  Controller_DW._DSTATE_n = Controller_P.Zero1_Value;
  if (Controller_DW._DSTATE_n >= Controller_P._UpperSat_a) {
    Controller_DW._DSTATE_n = Controller_P._UpperSat_a;
  } else if (Controller_DW._DSTATE_n <= Controller_P._LowerSat_k) {
    Controller_DW._DSTATE_n = Controller_P._LowerSat_k;
  }

  Controller_DW._PrevResetState_c = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S37>/ ' */

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator1' */
  Controller_DW.DiscreteTimeIntegrator1_DSTAT_o =
    Controller_P.DiscreteTimeIntegrator1_IC_i;
  Controller_DW.DiscreteTimeIntegrator1_PrevR_b = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S16>/Constant'
   */
  Controller_DW.DiscreteTimeIntegrator_DSTATE[0] =
    Controller_P.Constant_Value_c[0];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[0] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[0] = CONTROL_PARAM.RATE_I_MIN;
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[1] =
    Controller_P.Constant_Value_c[1];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[1] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[1] = CONTROL_PARAM.RATE_I_MIN;
  }

  Controller_DW.DiscreteTimeIntegrator_DSTATE[2] =
    Controller_P.Constant_Value_c[2];
  if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] >= CONTROL_PARAM.RATE_I_MAX)
  {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MAX;
  } else if (Controller_DW.DiscreteTimeIntegrator_DSTATE[2] <=
             CONTROL_PARAM.RATE_I_MIN) {
    Controller_DW.DiscreteTimeIntegrator_DSTATE[2] = CONTROL_PARAM.RATE_I_MIN;
  }

  Controller_DW.DiscreteTimeIntegrator_PrevRese = 0;

  /* End of InitializeConditions for DiscreteIntegrator: '<S16>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  Controller_DW.DiscreteTimeIntegrator_DSTATE_n =
    Controller_P.DiscreteTimeIntegrator_IC;
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
