/* ***********************************************************
 * This file was automatically generated on 2012-07-13.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "brick_stepper.h"

#include <string.h>

#define FUNCTION_SET_MAX_VELOCITY 1
#define FUNCTION_GET_MAX_VELOCITY 2
#define FUNCTION_GET_CURRENT_VELOCITY 3
#define FUNCTION_SET_SPEED_RAMPING 4
#define FUNCTION_GET_SPEED_RAMPING 5
#define FUNCTION_FULL_BRAKE 6
#define FUNCTION_SET_CURRENT_POSITION 7
#define FUNCTION_GET_CURRENT_POSITION 8
#define FUNCTION_SET_TARGET_POSITION 9
#define FUNCTION_GET_TARGET_POSITION 10
#define FUNCTION_SET_STEPS 11
#define FUNCTION_GET_STEPS 12
#define FUNCTION_GET_REMAINING_STEPS 13
#define FUNCTION_SET_STEP_MODE 14
#define FUNCTION_GET_STEP_MODE 15
#define FUNCTION_DRIVE_FORWARD 16
#define FUNCTION_DRIVE_BACKWARD 17
#define FUNCTION_STOP 18
#define FUNCTION_GET_STACK_INPUT_VOLTAGE 19
#define FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE 20
#define FUNCTION_GET_CURRENT_CONSUMPTION 21
#define FUNCTION_SET_MOTOR_CURRENT 22
#define FUNCTION_GET_MOTOR_CURRENT 23
#define FUNCTION_ENABLE 24
#define FUNCTION_DISABLE 25
#define FUNCTION_IS_ENABLED 26
#define FUNCTION_SET_DECAY 27
#define FUNCTION_GET_DECAY 28
#define FUNCTION_SET_MINIMUM_VOLTAGE 29
#define FUNCTION_GET_MINIMUM_VOLTAGE 30
#define FUNCTION_SET_SYNC_RECT 33
#define FUNCTION_IS_SYNC_RECT 34
#define FUNCTION_SET_TIME_BASE 35
#define FUNCTION_GET_TIME_BASE 36
#define FUNCTION_GET_ALL_DATA 37
#define FUNCTION_SET_ALL_DATA_PERIOD 38
#define FUNCTION_GET_ALL_DATA_PERIOD 39
#define FUNCTION_RESET 243
#define FUNCTION_GET_CHIP_TEMPERATURE 242


typedef void (*under_voltage_func_t)(uint16_t);

typedef void (*position_reached_func_t)(int32_t);

typedef void (*all_data_func_t)(uint16_t, int32_t, int32_t, uint16_t, uint16_t, uint16_t);

typedef void (*new_state_func_t)(uint8_t, uint8_t);

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#define ATTRIBUTE_PACKED __attribute__((packed))
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t velocity;
} ATTRIBUTE_PACKED SetMaxVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMaxVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetMaxVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetCurrentVelocity_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetCurrentVelocityReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t acceleration;
	uint16_t deacceleration;
} ATTRIBUTE_PACKED SetSpeedRamping_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetSpeedRamping_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t acceleration;
	uint16_t deacceleration;
} ATTRIBUTE_PACKED GetSpeedRampingReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED FullBrake_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t position;
} ATTRIBUTE_PACKED SetCurrentPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetCurrentPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t position;
} ATTRIBUTE_PACKED GetCurrentPositionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t position;
} ATTRIBUTE_PACKED SetTargetPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetTargetPosition_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t position;
} ATTRIBUTE_PACKED GetTargetPositionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t steps;
} ATTRIBUTE_PACKED SetSteps_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetSteps_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t steps;
} ATTRIBUTE_PACKED GetStepsReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetRemainingSteps_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t steps;
} ATTRIBUTE_PACKED GetRemainingStepsReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t mode;
} ATTRIBUTE_PACKED SetStepMode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetStepMode_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t mode;
} ATTRIBUTE_PACKED GetStepModeReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED DriveForward_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED DriveBackward_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Stop_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetStackInputVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetStackInputVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetExternalInputVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetExternalInputVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetCurrentConsumption_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current;
} ATTRIBUTE_PACKED GetCurrentConsumptionReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current;
} ATTRIBUTE_PACKED SetMotorCurrent_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMotorCurrent_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current;
} ATTRIBUTE_PACKED GetMotorCurrentReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Enable_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Disable_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED IsEnabled_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool enabled;
} ATTRIBUTE_PACKED IsEnabledReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t decay;
} ATTRIBUTE_PACKED SetDecay_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetDecay_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t decay;
} ATTRIBUTE_PACKED GetDecayReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED SetMinimumVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetMinimumVoltage_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetMinimumVoltageReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t voltage;
} ATTRIBUTE_PACKED UnderVoltageCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int32_t position;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool sync_rect;
} ATTRIBUTE_PACKED SetSyncRect_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED IsSyncRect_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	bool sync_rect;
} ATTRIBUTE_PACKED IsSyncRectReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t time_base;
} ATTRIBUTE_PACKED SetTimeBase_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetTimeBase_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t time_base;
} ATTRIBUTE_PACKED GetTimeBaseReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAllData_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current_velocity;
	int32_t current_position;
	int32_t remaining_steps;
	uint16_t stack_voltage;
	uint16_t external_voltage;
	uint16_t current_consumption;
} ATTRIBUTE_PACKED GetAllDataReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED SetAllDataPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetAllDataPeriod_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint32_t period;
} ATTRIBUTE_PACKED GetAllDataPeriodReturn_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint16_t current_velocity;
	int32_t current_position;
	int32_t remaining_steps;
	uint16_t stack_voltage;
	uint16_t external_voltage;
	uint16_t current_consumption;
} ATTRIBUTE_PACKED AllDataCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	uint8_t state_new;
	uint8_t state_previous;
} ATTRIBUTE_PACKED NewStateCallback_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED Reset_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
} ATTRIBUTE_PACKED GetChipTemperature_;

typedef struct {
	uint8_t stack_id;
	uint8_t function_id;
	uint16_t length;
	int16_t temperature;
} ATTRIBUTE_PACKED GetChipTemperatureReturn_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

int stepper_set_max_velocity(Stepper *stepper, uint16_t velocity) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetMaxVelocity_ smv;
	smv.stack_id = stepper->stack_id;
	smv.function_id = FUNCTION_SET_MAX_VELOCITY;
	smv.length = sizeof(SetMaxVelocity_);
	smv.velocity = velocity;

	ipcon_device_write(stepper, (char *)&smv, sizeof(SetMaxVelocity_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_max_velocity(Stepper *stepper, uint16_t *ret_velocity) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_MAX_VELOCITY;
	stepper->response.length = sizeof(GetMaxVelocityReturn_);
	GetMaxVelocity_ gmv;
	gmv.stack_id = stepper->stack_id;
	gmv.function_id = FUNCTION_GET_MAX_VELOCITY;
	gmv.length = sizeof(GetMaxVelocity_);

	ipcon_device_write(stepper, (char *)&gmv, sizeof(GetMaxVelocity_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetMaxVelocityReturn_ *gmvr = (GetMaxVelocityReturn_ *)stepper->response.buffer;
	*ret_velocity = gmvr->velocity;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_current_velocity(Stepper *stepper, uint16_t *ret_velocity) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_CURRENT_VELOCITY;
	stepper->response.length = sizeof(GetCurrentVelocityReturn_);
	GetCurrentVelocity_ gcv;
	gcv.stack_id = stepper->stack_id;
	gcv.function_id = FUNCTION_GET_CURRENT_VELOCITY;
	gcv.length = sizeof(GetCurrentVelocity_);

	ipcon_device_write(stepper, (char *)&gcv, sizeof(GetCurrentVelocity_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetCurrentVelocityReturn_ *gcvr = (GetCurrentVelocityReturn_ *)stepper->response.buffer;
	*ret_velocity = gcvr->velocity;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_speed_ramping(Stepper *stepper, uint16_t acceleration, uint16_t deacceleration) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetSpeedRamping_ ssr;
	ssr.stack_id = stepper->stack_id;
	ssr.function_id = FUNCTION_SET_SPEED_RAMPING;
	ssr.length = sizeof(SetSpeedRamping_);
	ssr.acceleration = acceleration;
	ssr.deacceleration = deacceleration;

	ipcon_device_write(stepper, (char *)&ssr, sizeof(SetSpeedRamping_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_speed_ramping(Stepper *stepper, uint16_t *ret_acceleration, uint16_t *ret_deacceleration) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_SPEED_RAMPING;
	stepper->response.length = sizeof(GetSpeedRampingReturn_);
	GetSpeedRamping_ gsr;
	gsr.stack_id = stepper->stack_id;
	gsr.function_id = FUNCTION_GET_SPEED_RAMPING;
	gsr.length = sizeof(GetSpeedRamping_);

	ipcon_device_write(stepper, (char *)&gsr, sizeof(GetSpeedRamping_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetSpeedRampingReturn_ *gsrr = (GetSpeedRampingReturn_ *)stepper->response.buffer;
	*ret_acceleration = gsrr->acceleration;
	*ret_deacceleration = gsrr->deacceleration;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_full_brake(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	FullBrake_ fb;
	fb.stack_id = stepper->stack_id;
	fb.function_id = FUNCTION_FULL_BRAKE;
	fb.length = sizeof(FullBrake_);

	ipcon_device_write(stepper, (char *)&fb, sizeof(FullBrake_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_current_position(Stepper *stepper, int32_t position) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetCurrentPosition_ scp;
	scp.stack_id = stepper->stack_id;
	scp.function_id = FUNCTION_SET_CURRENT_POSITION;
	scp.length = sizeof(SetCurrentPosition_);
	scp.position = position;

	ipcon_device_write(stepper, (char *)&scp, sizeof(SetCurrentPosition_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_current_position(Stepper *stepper, int32_t *ret_position) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_CURRENT_POSITION;
	stepper->response.length = sizeof(GetCurrentPositionReturn_);
	GetCurrentPosition_ gcp;
	gcp.stack_id = stepper->stack_id;
	gcp.function_id = FUNCTION_GET_CURRENT_POSITION;
	gcp.length = sizeof(GetCurrentPosition_);

	ipcon_device_write(stepper, (char *)&gcp, sizeof(GetCurrentPosition_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetCurrentPositionReturn_ *gcpr = (GetCurrentPositionReturn_ *)stepper->response.buffer;
	*ret_position = gcpr->position;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_target_position(Stepper *stepper, int32_t position) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetTargetPosition_ stp;
	stp.stack_id = stepper->stack_id;
	stp.function_id = FUNCTION_SET_TARGET_POSITION;
	stp.length = sizeof(SetTargetPosition_);
	stp.position = position;

	ipcon_device_write(stepper, (char *)&stp, sizeof(SetTargetPosition_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_target_position(Stepper *stepper, int32_t *ret_position) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_TARGET_POSITION;
	stepper->response.length = sizeof(GetTargetPositionReturn_);
	GetTargetPosition_ gtp;
	gtp.stack_id = stepper->stack_id;
	gtp.function_id = FUNCTION_GET_TARGET_POSITION;
	gtp.length = sizeof(GetTargetPosition_);

	ipcon_device_write(stepper, (char *)&gtp, sizeof(GetTargetPosition_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetTargetPositionReturn_ *gtpr = (GetTargetPositionReturn_ *)stepper->response.buffer;
	*ret_position = gtpr->position;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_steps(Stepper *stepper, int32_t steps) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetSteps_ ss;
	ss.stack_id = stepper->stack_id;
	ss.function_id = FUNCTION_SET_STEPS;
	ss.length = sizeof(SetSteps_);
	ss.steps = steps;

	ipcon_device_write(stepper, (char *)&ss, sizeof(SetSteps_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_steps(Stepper *stepper, int32_t *ret_steps) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_STEPS;
	stepper->response.length = sizeof(GetStepsReturn_);
	GetSteps_ gs;
	gs.stack_id = stepper->stack_id;
	gs.function_id = FUNCTION_GET_STEPS;
	gs.length = sizeof(GetSteps_);

	ipcon_device_write(stepper, (char *)&gs, sizeof(GetSteps_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetStepsReturn_ *gsr = (GetStepsReturn_ *)stepper->response.buffer;
	*ret_steps = gsr->steps;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_remaining_steps(Stepper *stepper, int32_t *ret_steps) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_REMAINING_STEPS;
	stepper->response.length = sizeof(GetRemainingStepsReturn_);
	GetRemainingSteps_ grs;
	grs.stack_id = stepper->stack_id;
	grs.function_id = FUNCTION_GET_REMAINING_STEPS;
	grs.length = sizeof(GetRemainingSteps_);

	ipcon_device_write(stepper, (char *)&grs, sizeof(GetRemainingSteps_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetRemainingStepsReturn_ *grsr = (GetRemainingStepsReturn_ *)stepper->response.buffer;
	*ret_steps = grsr->steps;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_step_mode(Stepper *stepper, uint8_t mode) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetStepMode_ ssm;
	ssm.stack_id = stepper->stack_id;
	ssm.function_id = FUNCTION_SET_STEP_MODE;
	ssm.length = sizeof(SetStepMode_);
	ssm.mode = mode;

	ipcon_device_write(stepper, (char *)&ssm, sizeof(SetStepMode_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_step_mode(Stepper *stepper, uint8_t *ret_mode) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_STEP_MODE;
	stepper->response.length = sizeof(GetStepModeReturn_);
	GetStepMode_ gsm;
	gsm.stack_id = stepper->stack_id;
	gsm.function_id = FUNCTION_GET_STEP_MODE;
	gsm.length = sizeof(GetStepMode_);

	ipcon_device_write(stepper, (char *)&gsm, sizeof(GetStepMode_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetStepModeReturn_ *gsmr = (GetStepModeReturn_ *)stepper->response.buffer;
	*ret_mode = gsmr->mode;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_drive_forward(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	DriveForward_ df;
	df.stack_id = stepper->stack_id;
	df.function_id = FUNCTION_DRIVE_FORWARD;
	df.length = sizeof(DriveForward_);

	ipcon_device_write(stepper, (char *)&df, sizeof(DriveForward_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_drive_backward(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	DriveBackward_ db;
	db.stack_id = stepper->stack_id;
	db.function_id = FUNCTION_DRIVE_BACKWARD;
	db.length = sizeof(DriveBackward_);

	ipcon_device_write(stepper, (char *)&db, sizeof(DriveBackward_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_stop(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	Stop_ s;
	s.stack_id = stepper->stack_id;
	s.function_id = FUNCTION_STOP;
	s.length = sizeof(Stop_);

	ipcon_device_write(stepper, (char *)&s, sizeof(Stop_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_stack_input_voltage(Stepper *stepper, uint16_t *ret_voltage) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_STACK_INPUT_VOLTAGE;
	stepper->response.length = sizeof(GetStackInputVoltageReturn_);
	GetStackInputVoltage_ gsiv;
	gsiv.stack_id = stepper->stack_id;
	gsiv.function_id = FUNCTION_GET_STACK_INPUT_VOLTAGE;
	gsiv.length = sizeof(GetStackInputVoltage_);

	ipcon_device_write(stepper, (char *)&gsiv, sizeof(GetStackInputVoltage_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetStackInputVoltageReturn_ *gsivr = (GetStackInputVoltageReturn_ *)stepper->response.buffer;
	*ret_voltage = gsivr->voltage;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_external_input_voltage(Stepper *stepper, uint16_t *ret_voltage) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE;
	stepper->response.length = sizeof(GetExternalInputVoltageReturn_);
	GetExternalInputVoltage_ geiv;
	geiv.stack_id = stepper->stack_id;
	geiv.function_id = FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE;
	geiv.length = sizeof(GetExternalInputVoltage_);

	ipcon_device_write(stepper, (char *)&geiv, sizeof(GetExternalInputVoltage_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetExternalInputVoltageReturn_ *geivr = (GetExternalInputVoltageReturn_ *)stepper->response.buffer;
	*ret_voltage = geivr->voltage;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_current_consumption(Stepper *stepper, uint16_t *ret_current) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_CURRENT_CONSUMPTION;
	stepper->response.length = sizeof(GetCurrentConsumptionReturn_);
	GetCurrentConsumption_ gcc;
	gcc.stack_id = stepper->stack_id;
	gcc.function_id = FUNCTION_GET_CURRENT_CONSUMPTION;
	gcc.length = sizeof(GetCurrentConsumption_);

	ipcon_device_write(stepper, (char *)&gcc, sizeof(GetCurrentConsumption_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetCurrentConsumptionReturn_ *gccr = (GetCurrentConsumptionReturn_ *)stepper->response.buffer;
	*ret_current = gccr->current;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_motor_current(Stepper *stepper, uint16_t current) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetMotorCurrent_ smc;
	smc.stack_id = stepper->stack_id;
	smc.function_id = FUNCTION_SET_MOTOR_CURRENT;
	smc.length = sizeof(SetMotorCurrent_);
	smc.current = current;

	ipcon_device_write(stepper, (char *)&smc, sizeof(SetMotorCurrent_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_motor_current(Stepper *stepper, uint16_t *ret_current) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_MOTOR_CURRENT;
	stepper->response.length = sizeof(GetMotorCurrentReturn_);
	GetMotorCurrent_ gmc;
	gmc.stack_id = stepper->stack_id;
	gmc.function_id = FUNCTION_GET_MOTOR_CURRENT;
	gmc.length = sizeof(GetMotorCurrent_);

	ipcon_device_write(stepper, (char *)&gmc, sizeof(GetMotorCurrent_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetMotorCurrentReturn_ *gmcr = (GetMotorCurrentReturn_ *)stepper->response.buffer;
	*ret_current = gmcr->current;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_enable(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	Enable_ e;
	e.stack_id = stepper->stack_id;
	e.function_id = FUNCTION_ENABLE;
	e.length = sizeof(Enable_);

	ipcon_device_write(stepper, (char *)&e, sizeof(Enable_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_disable(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	Disable_ d;
	d.stack_id = stepper->stack_id;
	d.function_id = FUNCTION_DISABLE;
	d.length = sizeof(Disable_);

	ipcon_device_write(stepper, (char *)&d, sizeof(Disable_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_is_enabled(Stepper *stepper, bool *ret_enabled) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_IS_ENABLED;
	stepper->response.length = sizeof(IsEnabledReturn_);
	IsEnabled_ ie;
	ie.stack_id = stepper->stack_id;
	ie.function_id = FUNCTION_IS_ENABLED;
	ie.length = sizeof(IsEnabled_);

	ipcon_device_write(stepper, (char *)&ie, sizeof(IsEnabled_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	IsEnabledReturn_ *ier = (IsEnabledReturn_ *)stepper->response.buffer;
	*ret_enabled = ier->enabled;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_decay(Stepper *stepper, uint16_t decay) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetDecay_ sd;
	sd.stack_id = stepper->stack_id;
	sd.function_id = FUNCTION_SET_DECAY;
	sd.length = sizeof(SetDecay_);
	sd.decay = decay;

	ipcon_device_write(stepper, (char *)&sd, sizeof(SetDecay_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_decay(Stepper *stepper, uint16_t *ret_decay) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_DECAY;
	stepper->response.length = sizeof(GetDecayReturn_);
	GetDecay_ gd;
	gd.stack_id = stepper->stack_id;
	gd.function_id = FUNCTION_GET_DECAY;
	gd.length = sizeof(GetDecay_);

	ipcon_device_write(stepper, (char *)&gd, sizeof(GetDecay_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetDecayReturn_ *gdr = (GetDecayReturn_ *)stepper->response.buffer;
	*ret_decay = gdr->decay;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_minimum_voltage(Stepper *stepper, uint16_t voltage) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetMinimumVoltage_ smv;
	smv.stack_id = stepper->stack_id;
	smv.function_id = FUNCTION_SET_MINIMUM_VOLTAGE;
	smv.length = sizeof(SetMinimumVoltage_);
	smv.voltage = voltage;

	ipcon_device_write(stepper, (char *)&smv, sizeof(SetMinimumVoltage_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_minimum_voltage(Stepper *stepper, uint16_t *ret_voltage) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_MINIMUM_VOLTAGE;
	stepper->response.length = sizeof(GetMinimumVoltageReturn_);
	GetMinimumVoltage_ gmv;
	gmv.stack_id = stepper->stack_id;
	gmv.function_id = FUNCTION_GET_MINIMUM_VOLTAGE;
	gmv.length = sizeof(GetMinimumVoltage_);

	ipcon_device_write(stepper, (char *)&gmv, sizeof(GetMinimumVoltage_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetMinimumVoltageReturn_ *gmvr = (GetMinimumVoltageReturn_ *)stepper->response.buffer;
	*ret_voltage = gmvr->voltage;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_sync_rect(Stepper *stepper, bool sync_rect) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetSyncRect_ ssr;
	ssr.stack_id = stepper->stack_id;
	ssr.function_id = FUNCTION_SET_SYNC_RECT;
	ssr.length = sizeof(SetSyncRect_);
	ssr.sync_rect = sync_rect;

	ipcon_device_write(stepper, (char *)&ssr, sizeof(SetSyncRect_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_is_sync_rect(Stepper *stepper, bool *ret_sync_rect) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_IS_SYNC_RECT;
	stepper->response.length = sizeof(IsSyncRectReturn_);
	IsSyncRect_ isr;
	isr.stack_id = stepper->stack_id;
	isr.function_id = FUNCTION_IS_SYNC_RECT;
	isr.length = sizeof(IsSyncRect_);

	ipcon_device_write(stepper, (char *)&isr, sizeof(IsSyncRect_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	IsSyncRectReturn_ *isrr = (IsSyncRectReturn_ *)stepper->response.buffer;
	*ret_sync_rect = isrr->sync_rect;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_time_base(Stepper *stepper, uint32_t time_base) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetTimeBase_ stb;
	stb.stack_id = stepper->stack_id;
	stb.function_id = FUNCTION_SET_TIME_BASE;
	stb.length = sizeof(SetTimeBase_);
	stb.time_base = time_base;

	ipcon_device_write(stepper, (char *)&stb, sizeof(SetTimeBase_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_time_base(Stepper *stepper, uint32_t *ret_time_base) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_TIME_BASE;
	stepper->response.length = sizeof(GetTimeBaseReturn_);
	GetTimeBase_ gtb;
	gtb.stack_id = stepper->stack_id;
	gtb.function_id = FUNCTION_GET_TIME_BASE;
	gtb.length = sizeof(GetTimeBase_);

	ipcon_device_write(stepper, (char *)&gtb, sizeof(GetTimeBase_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetTimeBaseReturn_ *gtbr = (GetTimeBaseReturn_ *)stepper->response.buffer;
	*ret_time_base = gtbr->time_base;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_all_data(Stepper *stepper, uint16_t *ret_current_velocity, int32_t *ret_current_position, int32_t *ret_remaining_steps, uint16_t *ret_stack_voltage, uint16_t *ret_external_voltage, uint16_t *ret_current_consumption) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_ALL_DATA;
	stepper->response.length = sizeof(GetAllDataReturn_);
	GetAllData_ gad;
	gad.stack_id = stepper->stack_id;
	gad.function_id = FUNCTION_GET_ALL_DATA;
	gad.length = sizeof(GetAllData_);

	ipcon_device_write(stepper, (char *)&gad, sizeof(GetAllData_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetAllDataReturn_ *gadr = (GetAllDataReturn_ *)stepper->response.buffer;
	*ret_current_velocity = gadr->current_velocity;
	*ret_current_position = gadr->current_position;
	*ret_remaining_steps = gadr->remaining_steps;
	*ret_stack_voltage = gadr->stack_voltage;
	*ret_external_voltage = gadr->external_voltage;
	*ret_current_consumption = gadr->current_consumption;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_set_all_data_period(Stepper *stepper, uint32_t period) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	SetAllDataPeriod_ sadp;
	sadp.stack_id = stepper->stack_id;
	sadp.function_id = FUNCTION_SET_ALL_DATA_PERIOD;
	sadp.length = sizeof(SetAllDataPeriod_);
	sadp.period = period;

	ipcon_device_write(stepper, (char *)&sadp, sizeof(SetAllDataPeriod_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_all_data_period(Stepper *stepper, uint32_t *ret_period) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_ALL_DATA_PERIOD;
	stepper->response.length = sizeof(GetAllDataPeriodReturn_);
	GetAllDataPeriod_ gadp;
	gadp.stack_id = stepper->stack_id;
	gadp.function_id = FUNCTION_GET_ALL_DATA_PERIOD;
	gadp.length = sizeof(GetAllDataPeriod_);

	ipcon_device_write(stepper, (char *)&gadp, sizeof(GetAllDataPeriod_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetAllDataPeriodReturn_ *gadpr = (GetAllDataPeriodReturn_ *)stepper->response.buffer;
	*ret_period = gadpr->period;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_reset(Stepper *stepper) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	Reset_ r;
	r.stack_id = stepper->stack_id;
	r.function_id = FUNCTION_RESET;
	r.length = sizeof(Reset_);

	ipcon_device_write(stepper, (char *)&r, sizeof(Reset_));

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_chip_temperature(Stepper *stepper, int16_t *ret_temperature) {
	if(stepper->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_mutex_lock(&stepper->write_mutex);

	stepper->response.function_id = FUNCTION_GET_CHIP_TEMPERATURE;
	stepper->response.length = sizeof(GetChipTemperatureReturn_);
	GetChipTemperature_ gct;
	gct.stack_id = stepper->stack_id;
	gct.function_id = FUNCTION_GET_CHIP_TEMPERATURE;
	gct.length = sizeof(GetChipTemperature_);

	ipcon_device_write(stepper, (char *)&gct, sizeof(GetChipTemperature_));

	if(ipcon_device_expect_response(stepper) != 0) {
		ipcon_mutex_unlock(&stepper->write_mutex);
		return E_TIMEOUT;
	}

	GetChipTemperatureReturn_ *gctr = (GetChipTemperatureReturn_ *)stepper->response.buffer;
	*ret_temperature = gctr->temperature;

	ipcon_mutex_unlock(&stepper->write_mutex);

	return E_OK;
}

int stepper_get_version(Stepper *stepper, char ret_name[40], uint8_t ret_firmware_version[3], uint8_t ret_binding_version[3]) {
	strncpy(ret_name, stepper->name, 40);

	ret_firmware_version[0] = stepper->firmware_version[0];
	ret_firmware_version[1] = stepper->firmware_version[1];
	ret_firmware_version[2] = stepper->firmware_version[2];

	ret_binding_version[0] = stepper->binding_version[0];
	ret_binding_version[1] = stepper->binding_version[1];
	ret_binding_version[2] = stepper->binding_version[2];

	return E_OK;
}

static int stepper_callback_wrapper_under_voltage(Stepper *stepper, const unsigned char *buffer) {
	UnderVoltageCallback_ *uvc = (UnderVoltageCallback_ *)buffer;
	((under_voltage_func_t)stepper->registered_callbacks[uvc->function_id])(uvc->voltage);
	return sizeof(UnderVoltageCallback_);
}

static int stepper_callback_wrapper_position_reached(Stepper *stepper, const unsigned char *buffer) {
	PositionReachedCallback_ *prc = (PositionReachedCallback_ *)buffer;
	((position_reached_func_t)stepper->registered_callbacks[prc->function_id])(prc->position);
	return sizeof(PositionReachedCallback_);
}

static int stepper_callback_wrapper_all_data(Stepper *stepper, const unsigned char *buffer) {
	AllDataCallback_ *adc = (AllDataCallback_ *)buffer;
	((all_data_func_t)stepper->registered_callbacks[adc->function_id])(adc->current_velocity, adc->current_position, adc->remaining_steps, adc->stack_voltage, adc->external_voltage, adc->current_consumption);
	return sizeof(AllDataCallback_);
}

static int stepper_callback_wrapper_new_state(Stepper *stepper, const unsigned char *buffer) {
	NewStateCallback_ *nsc = (NewStateCallback_ *)buffer;
	((new_state_func_t)stepper->registered_callbacks[nsc->function_id])(nsc->state_new, nsc->state_previous);
	return sizeof(NewStateCallback_);
}

void stepper_register_callback(Stepper *stepper, uint8_t id, void *callback) {
    stepper->registered_callbacks[id] = callback;
}

void stepper_create(Stepper *stepper, const char *uid) {
	ipcon_device_create(stepper, uid);

	stepper->expected_name = "Stepper Brick";

	stepper->binding_version[0] = 1;
	stepper->binding_version[1] = 0;
	stepper->binding_version[2] = 2;

	stepper->callback_wrappers[STEPPER_CALLBACK_UNDER_VOLTAGE] = stepper_callback_wrapper_under_voltage;
	stepper->callback_wrappers[STEPPER_CALLBACK_POSITION_REACHED] = stepper_callback_wrapper_position_reached;
	stepper->callback_wrappers[STEPPER_CALLBACK_ALL_DATA] = stepper_callback_wrapper_all_data;
	stepper->callback_wrappers[STEPPER_CALLBACK_NEW_STATE] = stepper_callback_wrapper_new_state;
}
