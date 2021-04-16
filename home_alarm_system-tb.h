
#ifndef __ALARM_SYSTEM_TB_H__
#define __ALARM_SYSTEM_TB_H__

#include "home_alarm_system.h"





void home_alarm_system(
		ap_uint<16> slide_switches,
		ap_uint<5>  push_buttons,

		ap_uint<16> &leds,
		ap_uint<8>  &sg_data,
		ap_uint<4>  &sg_enable
		);


#endif //__ALARM_SYSTEM_TB_H__
