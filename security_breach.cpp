// SECURITY BREACH CPP FILE
#include "home_alarm_system.h"


void display_window(
		ap_uint<3>  window_sensors,
		ap_uint<5>  show_fault,

		ap_uint<8> &sg_data,
		ap_uint<4> &sg_enable
		)
{
	sg_data = svn_sg_code[14];  // show the letter E
	sg_enable = 0b0000;         // Activate all seven-segments
	if (show_fault[0] && window_sensors[0]) {

		sg_data   = svn_sg_code[1];
		sg_enable = 0b1110;

	} else if (show_fault[1] && window_sensors[1]) {

		sg_data   = svn_sg_code[2];
		sg_enable = 0b1110;

	} else if (show_fault[2] && window_sensors[2]) {

		sg_data   = svn_sg_code[3];
		sg_enable = 0b1110;
	}

}



void display_motion (
		ap_uint<2>  motion_detectors,
		ap_uint<5>  show_fault,

		ap_uint<8> &sg_data,
		ap_uint<4> &sg_enable)
{
	sg_data = svn_sg_code[14];  // show the letter E
	sg_enable = 0b0000;         // Activate all seven-segments
	if (show_fault[3] && motion_detectors[0]) {

		sg_data   = svn_sg_code[1];
		sg_enable = 0b1101;

	} else if (show_fault[4] && motion_detectors[1]) {

		sg_data   = svn_sg_code[2];
		sg_enable = 0b1101;

	}

}



void security_breach(
		ap_uint<3>  window_sensors,
		ap_uint<2>  motion_detectors,
		ap_uint<5>  show_fault,

		ap_uint<8> &sg_data,
		ap_uint<4> &sg_enable)
{


	sg_data = svn_sg_code[14];  // show the letter E
	sg_enable = 0b0000;         // Activate all seven-segments

	if (show_fault != 0b00000) {


		if (window_sensors != 0b000) {
			display_window(window_sensors, show_fault,sg_data, sg_enable);
		}
		if (motion_detectors != 0b00) {
			display_motion(motion_detectors, show_fault, sg_data, sg_enable);
		}

	}
}
