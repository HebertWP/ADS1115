#include <ADS1115.h>
ADS1115 adc;

void setup()
{
    adc.begin();
    adc.set_data_rate(ADS1115_DATA_RATE_860_SPS);
    adc.set_mode(ADS1115_MODE_CONTINUOUS);
    adc.set_mux(ADS1115_MUX_GND_AIN1);
    adc.set_pga(ADS1115_PGA_ONE);

    if (adc.trigger_sample() != 0)
        Serial.println("adc read trigger failed (ads1115 not connected?)");
}

void loop()
{
    /* You will be oversampling if the loop takes too short a time */
    float val = adc.read_sample_float();
    Serial.print("Value read is ");
    Serial.println(val);
    delay(1000 / 860);
}