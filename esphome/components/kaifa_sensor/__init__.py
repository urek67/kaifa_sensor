# kaifa_sensor | ESPHome external component | 2025-04-23

from esphome.components import sensor
import esphome.config_validation as cv

CODEOWNERS = ["@urek67"]
DEPENDENCIES = ["uart"]

CONF_UART_ID = "uart_id"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(sensor.Sensor),
        cv.Required(CONF_UART_ID): cv.use_id(sensor.Sensor),
    }
)

def to_code(config):
    pass  # Kommer ersättas av C++-registret
