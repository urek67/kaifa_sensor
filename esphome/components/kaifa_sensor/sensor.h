#pragma once
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace kaifa_sensor {

class KaifaSensor : public sensor::Sensor, public uart::UARTDevice {
 public:
  explicit KaifaSensor(uart::UARTComponent *parent);
  void loop() override;
  void setup() override {}

 protected:
  float parse_value_(const std::string &msg, const std::string &obis);
};

}  // namespace kaifa_sensor
}  // namespace esphome