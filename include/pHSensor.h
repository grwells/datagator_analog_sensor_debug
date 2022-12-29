/**
 * @defgroup   PHSENSOR p H Sensor
 *
 * @brief      Implements an interface for converting a voltage (analog reading)
 *             into a pH value according to the conversion or calibration for a
 *             specific sensor.
 *
 * @author     Garrett Wells
 * @date       2022
 */
#ifndef PHSENSOR_H
#define PHSENSOR_H

class pHSensor {
	public:
		virtual double getpH(double voltage);

        virtual std::string getSensorType();
        virtual std::string toJSON(double voltage);
};

#endif
