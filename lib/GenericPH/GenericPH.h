/**
 * @defgroup   GENERICPH Generic PH
 *
 * @brief      This file implements Generic PH.
 *
 * @author     Garrett Wells
 * @date       2022
 */
#ifndef GENERICPH_H
#define GENERICPH_H
#include <../../include/pHSensor.h>

class GenericPH: public pHSensor{
	public:
		double getpH(double voltage){
			/*
			if(voltage <= 0.93){
				return (7.86*voltage) - 3.9831;
			}else if(voltage <= 1.3){
				return (9.9189*voltage) - 5.8945;
			}else{
				return (18.5555*voltage) - 17.12215;
			}
			*/
			return ((6/5)*voltage)+3;

			//double pH = ((voltage/MAX_V) * 6) + 3; // on range 3-9 with min value of 3
			//return pH;
		}

		std::string getSensorType(){
			return "generic_pH";
		}
       	std::string toJSON(double voltage, double pH){
       		return "\"voltage\": " + std::to_string(voltage) + ", \"ph\":" + std::to_string(pH);
       	}

    private:
    	const double MIN_V = 0;
    	const double MAX_V = 2;


};

#endif

