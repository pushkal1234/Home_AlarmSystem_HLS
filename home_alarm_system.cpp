
#include "home_alarm_system.h"
#include <iostream>


void home_alarm_system(
		ap_uint<16> slide_switches,
		ap_uint<5>  push_buttons,

		ap_uint<16> &leds,
		ap_uint<8>  &sg_data,
		ap_uint<4>  &sg_enable
		) {


#pragma HLS INTERFACE ap_ctrl_none port=return

#pragma HLS INTERFACE ap_none port=slide_switches
#pragma HLS INTERFACE ap_none port=push_buttons

#pragma HLS INTERFACE ap_none port=leds
#pragma HLS INTERFACE ap_none port=sg_data
#pragma HLS INTERFACE ap_none port=sg_enable





	ap_uint<3>  window_sensors   = slide_switches.range(2, 0);
	ap_uint<2>  motion_detectors = slide_switches(7, 6);
	ap_uint<4>  switch_code      = slide_switches.range(15, 12);

	ap_uint<5>  show_fault       = push_buttons;

	leds = slide_switches;


	if (switch_code == 0b1011) {    // if the alarm system is ON

		if ( (window_sensors != 0b000) || (motion_detectors != 0b00) ) {
			security_breach(window_sensors, motion_detectors, show_fault, sg_data, sg_enable);
		} else {
			sg_data = svn_sg_code[10];  // show the letter A
			sg_enable = 0b0000;         // Activate all seven-segments
		}

	} else {      //if the alarm system is OFF
		sg_data = svn_sg_code[0];  //show the letter O
		sg_enable = 0b0000;
	}
}
