/*
 * File: Controller_data.c
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

/* Block parameters (default storage) */
P_Controller_T Controller_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S46>/Constant'
   */
  { 1U, 2U, 3U },

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S35>/Constant'
   */
  4U,

  /* Mask Parameter: CompareToConstant_const_k
   * Referenced by: '<S25>/Constant'
   */
  { 3U, 4U },

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S26>/Constant'
   */
  3U,

  /* Mask Parameter: CompareToConstant_const_kq
   * Referenced by: '<S27>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S3>/Constant'
   */
  3U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0U,                                /* timestamp */

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    /* actuator_cmd */
  },

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S41>/Gain1'
   */
  0.0F,

  /* Computed Parameter: cruise_throttle_Value
   * Referenced by: '<S45>/cruise_throttle'
   */
  0.5F,

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<S31>/Saturation1'
   */
  0.3F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<S31>/Saturation1'
   */
  -0.3F,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S9>/Saturation2'
   */
  1.0F,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S9>/Saturation2'
   */
  -1.0F,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S45>/Saturation'
   */
  1.0F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S45>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain_p
   * Referenced by: '<S45>/Gain1'
   */
  1000.0F,

  /* Computed Parameter: Saturation1_UpperSat_j
   * Referenced by: '<S10>/Saturation1'
   */
  999.0F,

  /* Computed Parameter: Saturation1_LowerSat_f
   * Referenced by: '<S10>/Saturation1'
   */
  0.1F,

  /* Computed Parameter: Saturation_UpperSat_e
   * Referenced by: '<S14>/Saturation'
   */
  1.0F,

  /* Computed Parameter: Saturation_LowerSat_m
   * Referenced by: '<S14>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Saturation_UpperSat_j
   * Referenced by: '<S15>/Saturation'
   */
  1.0F,

  /* Computed Parameter: Saturation_LowerSat_d
   * Referenced by: '<S15>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Saturation1_UpperSat_a
   * Referenced by: '<S9>/Saturation1'
   */
  1.0F,

  /* Computed Parameter: Saturation1_LowerSat_l
   * Referenced by: '<S9>/Saturation1'
   */
  -1.0F,

  /* Computed Parameter: Constant11_Value
   * Referenced by: '<S43>/Constant11'
   */
  0.0F,

  /* Computed Parameter: Constant10_Value
   * Referenced by: '<S43>/Constant10'
   */
  0.0F,

  /* Computed Parameter: Constant9_Value
   * Referenced by: '<S43>/Constant9'
   */
  0.0F,

  /* Computed Parameter: Constant8_Value
   * Referenced by: '<S43>/Constant8'
   */
  0.0F,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<S43>/Constant6'
   */
  0.0F,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S43>/Constant5'
   */
  0.0F,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S43>/Constant4'
   */
  0.0F,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S43>/Constant3'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S9>/Gain'
   */
  { 500.0F, 500.0F, 500.0F, 500.0F },

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S9>/Bias'
   */
  1500.0F,

  /* Computed Parameter: Gain1_Gain_h
   * Referenced by: '<S38>/Gain1'
   */
  0.0F,

  /* Computed Parameter: Saturation1_UpperSat_i
   * Referenced by: '<S30>/Saturation1'
   */
  0.3F,

  /* Computed Parameter: Saturation1_LowerSat_g
   * Referenced by: '<S30>/Saturation1'
   */
  -0.3F,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S33>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Saturation_UpperSat_i
   * Referenced by: '<S34>/Saturation'
   */
  100.0F,

  /* Computed Parameter: Saturation_LowerSat_e
   * Referenced by: '<S34>/Saturation'
   */
  0.1F,

  /* Computed Parameter: Saturation1_UpperSat_d
   * Referenced by: '<S34>/Saturation1'
   */
  100.0F,

  /* Computed Parameter: Saturation1_LowerSat_i
   * Referenced by: '<S34>/Saturation1'
   */
  0.01F,

  /* Computed Parameter: Saturation_UpperSat_b
   * Referenced by: '<S42>/Saturation'
   */
  100.0F,

  /* Computed Parameter: Saturation_LowerSat_h
   * Referenced by: '<S42>/Saturation'
   */
  0.01F,

  /* Computed Parameter: Zero_Value
   * Referenced by: '<S8>/Zero'
   */
  0.0F,

  /* Computed Parameter: g_force_Gain
   * Referenced by: '<S8>/g_force'
   */
  0.101936802F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S34>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S34>/Switch'
   */
  1.0F,

  /* Computed Parameter: Switch_Threshold_a
   * Referenced by: '<S33>/Switch'
   */
  1.0F,

  /* Computed Parameter: Switch_Threshold_o
   * Referenced by: '<S42>/Switch'
   */
  1.0F,

  /* Computed Parameter: Saturation_UpperSat_es
   * Referenced by: '<S32>/Saturation'
   */
  100.0F,

  /* Computed Parameter: Saturation_LowerSat_k
   * Referenced by: '<S32>/Saturation'
   */
  0.1F,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S32>/Gain'
   */
  0.101936802F,

  /* Computed Parameter: Gain1_Gain_f
   * Referenced by: '<S32>/Gain1'
   */
  0.101936802F,

  /* Computed Parameter: Zero_Value_b
   * Referenced by: '<S40>/Zero'
   */
  0.0F,

  /* Computed Parameter: _gainval
   * Referenced by: '<S40>/ '
   */
  0.001F,

  /* Computed Parameter: _UpperSat
   * Referenced by: '<S40>/ '
   */
  0.1F,

  /* Computed Parameter: _LowerSat
   * Referenced by: '<S40>/ '
   */
  -0.1F,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S41>/Discrete-Time Integrator1'
   */
  0.001F,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC
   * Referenced by: '<S41>/Discrete-Time Integrator1'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S41>/Gain'
   */
  188.49556F,

  /* Computed Parameter: Zero1_Value
   * Referenced by: '<S37>/Zero1'
   */
  0.0F,

  /* Computed Parameter: _gainval_l
   * Referenced by: '<S37>/ '
   */
  0.001F,

  /* Computed Parameter: _UpperSat_a
   * Referenced by: '<S37>/ '
   */
  0.1F,

  /* Computed Parameter: _LowerSat_k
   * Referenced by: '<S37>/ '
   */
  -0.1F,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainv_g
   * Referenced by: '<S38>/Discrete-Time Integrator1'
   */
  0.001F,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC_i
   * Referenced by: '<S38>/Discrete-Time Integrator1'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_in
   * Referenced by: '<S38>/Gain'
   */
  62.831852F,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S24>/Constant'
   */
  9.81F,

  /* Computed Parameter: Saturation_UpperSat_k
   * Referenced by: '<S24>/Saturation'
   */
  1.0F,

  /* Computed Parameter: Saturation_LowerSat_j
   * Referenced by: '<S24>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S16>/Constant'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S16>/Discrete-Time Integrator'
   */
  0.001F,

  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S45>/Constant1'
   */
  1000U,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0U,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S9>/Constant'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Saturation_UpperSat_o
   * Referenced by: '<S9>/Saturation'
   */
  2000U,

  /* Computed Parameter: Saturation_LowerSat_mw
   * Referenced by: '<S9>/Saturation'
   */
  1000U,

  /* Computed Parameter: Switch_Threshold_m
   * Referenced by: '<S41>/Switch'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_p
   * Referenced by: '<S38>/Switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
