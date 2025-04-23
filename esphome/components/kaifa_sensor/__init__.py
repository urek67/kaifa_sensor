# kaifa_sensor | ESPHome external component | 2025-04-23

from esphome.components import sensor
from esphome.components.uart import UARTComponent
import esphome.config_validation as cv
import esphome.codegen as cg

kaifa_sensor_ns = cg.esphome_ns.namespace("kaifa_sensor")
KaifaSensor = kaifa_sensor_ns.class_("KaifaSensor", sensor.Sensor, cg.Component)

CONFIG_SCHEMA = sensor.sensor_schema(KaifaSensor).extend({
    cv.Required("uart_id"): cv.use_id(UARTComponent),
}).extend(cv.COMPONENT_SCHEMA)

def to_code(config):
    var = yield sensor.new_sensor(config)
    uart = yield cg.get_variable(config["uart_id"])
    cg.add(var.set_parent(uart))
