#include "sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace kaifa_sensor {

static const char *const TAG = "kaifa_sensor";

KaifaSensor::KaifaSensor(uart::UARTComponent *parent)
    : uart::UARTDevice(parent) {}

void KaifaSensor::loop() {
  std::string msg;
  while (available()) {
    char c;
    read_byte(&c);
    msg += c;
  }

  if (!msg.empty()) {
    float value = parse_value_(msg, "1.0.1.8.0");
    if (!std::isnan(value)) {
      publish_state(value);
      ESP_LOGD(TAG, "Import Energi: %.3f kWh", value);
    }
  }
}

float KaifaSensor::parse_value_(const std::string &msg, const std::string &obis) {
  size_t p = msg.find(obis);
  if (p == std::string::npos) return NAN;
  size_t s = msg.find('(', p);
  size_t e = msg.find('*', s);
  if (s == std::string::npos || e == std::string::npos) return NAN;
  return std::stof(msg.substr(s + 1, e - s - 1));
}

}  // namespace kaifa_sensor
}  // namespace esphome

ESPHOME_REGISTER_SENSOR(esphome::kaifa_sensor::KaifaSensor, kaifa_sensor, kaifa_sensor)