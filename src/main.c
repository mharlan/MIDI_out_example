/*
	Author: Matthew Harlan
	Email:  mharlan@gwmail.gwu.edu
	
	Description: This program drives a MIDI output port. Send a note on event with
	button SW1. Send a note off event with button SW2.

	Other files: buttons.c buttons.h delay.c delay.h MIDI_out.c MIDI_out.h MIDI_messages.c 
	MIDI_messages.h oscillator.c oscillator.h timer.c timer.h

	Compile: Set the user include path to the include directory.

	Comments: You can get away with not using the two inverters before the MIDI out,
	but only if your microcontroller pins consistently output a current greater than 
	5 mA from each output pin. It is a good idea to use them for the buffer to be
	on the safe side and encourage compatibility with a wide variety of MIDI input
	devices. I know that for my context kit board I needed to use the inverters.
 */

#include "MIDI_out.h"
#include "oscillator.h"
#include "buttons.h"
#include "timer.h"

#include <zneo.h>
#include <stdio.h>

/*
	Intializes the hardware and loop.
 */
void main(void)
{
	DI();

	//initialize the oscillator and global timer
	init_oscillator(OSC_5_52MHZ);
	init_timer(TIMER_2MS);

	init_midi_out();
	init_buttons();

	//enable interrupts
	EI();

	//loop infinitely
	while(1) { ; }
}
