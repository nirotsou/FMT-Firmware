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

static void rcu_config(void)
{
    /* enable GPIOA clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    /* enable ADC clock */
    rcu_periph_clock_enable(RCU_ADC0);
    /* config ADC clock */
    adc_clock_config(ADC_ADCCK_PCLK2_DIV8);
}

static void gpio_config(void)
{
    /* config the GPIO as analog mode */
    gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_0);
    // gpio_mode_set(GPIOC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_3);
}

static void adc_config(void)
{
    /* reset ADC */
    adc_deinit();
    /* ADC mode config */
    adc_sync_mode_config(ADC_SYNC_MODE_INDEPENDENT);
    /* ADC contineous function disable */
    adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, DISABLE);
    /* ADC scan mode disable */
    adc_special_function_config(ADC0, ADC_SCAN_MODE, DISABLE);
    /* ADC data alignment config */
    adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
    /* ADC channel length config */
    adc_channel_length_config(ADC0, ADC_REGULAR_CHANNEL, ADC_CHANNEL_10);

    /* ADC trigger config */
    // adc_external_trigger_source_config(ADC0, ADC_REGULAR_CHANNEL, ADC_EXTTRIG_ROUTINE_T0_CH0);
    adc_external_trigger_config(ADC0, ADC_REGULAR_CHANNEL, EXTERNAL_TRIGGER_DISABLE);

    /* enable ADC interface */
    adc_enable(ADC0);
    systime_mdelay(1);
    /* ADC calibration and reset calibration */
    adc_calibration_enable(ADC0);
}

static uint16_t adc_channel_sample(uint8_t channel)
{
    /* ADC routine channel config */
    adc_regular_channel_config(ADC0, 0U, channel, ADC_SAMPLETIME_3);
    /* ADC software trigger enable */
    adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);

    /* wait the end of conversion flag */
    while(!adc_flag_get(ADC0, ADC_FLAG_EOC));
    /* clear the end of conversion flag */
    adc_flag_clear(ADC0, ADC_FLAG_EOC);
    /* return regular channel sample value */
    return (adc_regular_data_read(ADC0));
}

static void test_unit_1(void)
{
    printf("ADC0_IN10:%d\n", adc_channel_sample(ADC_CHANNEL_10));
}

static rt_err_t testcase_init(void)
{
    rcu_config();
    gpio_config();
    adc_config();
    
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
UTEST_TC_EXPORT(testcase, "utest.interface.adc", testcase_init, testcase_cleanup, 50000);