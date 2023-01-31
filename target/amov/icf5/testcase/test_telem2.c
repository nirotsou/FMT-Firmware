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
#include <string.h>
#include <utest.h>


#define TEST_STRING "Hello FMT!"

static void test_unit_1(void)
{
    uint8_t rx_buffer[50] = { 0 };
    rt_device_t dev = rt_device_find("serial2");
    uassert_not_null(dev);

    rt_device_close(dev);
    rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX);

    rt_device_write(dev, 0, TEST_STRING, strlen(TEST_STRING));
    systime_mdelay(10);
    rt_device_read(dev, 0, rx_buffer, sizeof(rx_buffer));

    uassert_str_equal(TEST_STRING, rx_buffer);
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
UTEST_TC_EXPORT(testcase, "utest.interface.telem2", testcase_init, testcase_cleanup, 10000);