/*
 * EnergyManager.h
 *
 *  Created on: 18.11.2020
 *      Author: Igor
 */

#ifndef INC_ENERGYMANAGER_H_
#define INC_ENERGYMANAGER_H_

#include "main.h"
#include "adc.h"
#include "HallSensor.h"
#include "SectionSwitch.h"
#include "SupplyBranch.h"

#define EM_DMA_ADC_CHANNEL hadc1 //TODO: TARGET HADC2
#define EM_DMA_NUMBER_OF_CONVERSION  9 //5 HALL + 4 VOLTAGE MEASURMENTS (+ 1 internal temperature?)
#define HALL_SENSOR_NUMBER 5
#define SUPPLY_BRANCH_NUMBER 4
#define SECTION_SWITCH_NUMBER 5

#define HALL_ACS714_50A_SENSIVITY 0.04f
#define HALL_ACHS7121_SENSIVITY   0.185f

#define BRANCH_5_VOLTAGE 5.0f
#define BRANCH_3_VOLTAGE 3.3f
#define BRANCH_7_VOLTAGE 7.0f
#define NEAR_ZERO_VOLTAGE 0.5f

#define MAIN_SW_INDEX 4 //TODO: deal with this messy method (use enum or smth)


class EnergyManager {
private:

	HallSensor* hall_sensors[HALL_SENSOR_NUMBER];
	SupplyBranch* supply_branches[SUPPLY_BRANCH_NUMBER];
	SectionSwitch* section_switches[SECTION_SWITCH_NUMBER];

	uint32_t rawADC[EM_DMA_NUMBER_OF_CONVERSION];

	enum branch_index{
		branch_5_1,
		branch_5_2,
		branch_3,
		branch_7,
		motor,

	};

	void dma_init();
	void hallSensor_init();
	void supplyBranch_init();
	void sectionSwitch_init();
public:
	struct Section{
		float A; //Ampere
		float V; //Voltage
		float P; //Power
	};
	void init();

	EnergyManager();
	virtual ~EnergyManager();
};

#endif /* INC_ENERGYMANAGER_H_ */
