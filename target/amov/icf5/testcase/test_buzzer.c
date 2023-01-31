/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <firmament.h>
#include <utest.h>

#include "drv_buzzer.h"

#define TIMER_FREQUENCY       2500000                  // Timer frequency: 2.5M
#define PWM_DEFAULT_FREQUENCY 400                       // pwm default frequqncy
#define PWM_ARR(freq)         (TIMER_FREQUENCY / freq) // CCR reload value, Timer frequency = TIMER_FREQUENCY/(PWM_ARR+1)

static uint32_t __pwm_freq = PWM_DEFAULT_FREQUENCY;

static void test_unit_1(void)
{
    timer_channel_output_pulse_value_config(TIMER4, TIMER_CH_0, PWM_ARR(__pwm_freq) * 0.5 - 1);
    timer_enable(TIMER4);

    systime_mdelay(3000);

    timer_disable(TIMER4);
}

static rt_err_t testcase_init(void)
{
    return RT_EOK;
}

static rt_err_t testcase_cleanup(void)
{
    return RT_EOK;
}

static void testcase(void)
{
    UTEST_UNIT_RUN(test_unit_1);
}
UTEST_TC_EXPORT(testcase, "utest.interface.buzzer", testcase_init, testcase_cleanup, 10000);