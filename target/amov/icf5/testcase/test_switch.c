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

#include "led.h"

static void test_unit_1(void)
{
    struct device_pin_status pin_sta = { .pin = GET_PIN(A, 10) };
    rt_device_t dev = rt_device_find("pin");
    uassert_not_null(dev);

    led_init((struct device_pin_mode) { .pin = GET_PIN(A, 8), .mode = PIN_MODE_OUTPUT, .otype = PIN_OUT_TYPE_PP });
    led_init((struct device_pin_mode) { .pin = GET_PIN(A, 10), .mode = PIN_MODE_INPUT });

    uint32_t time_start = systime_now_ms();
    while (systime_now_ms() - time_start < 10000) {
        dev->read(dev, 0, (void*)&pin_sta, sizeof(&pin_sta));

        if (pin_sta.status == 1) {
            uassert_true(1);
            return;
        }

        LED_TOGGLE(GET_PIN(A, 8));

        systime_mdelay(500);
    }

    uassert_true(0);
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
UTEST_TC_EXPORT(testcase, "utest.interface.switch", testcase_init, testcase_cleanup, 10000);