﻿#include "led_flash.h"

//Notice UNARYACTIONSETUP and UNARYACTIONINIT have identical signatures...
UNARYACTIONSETUP(led_flash, LED pin) {
	_pin = pin;
}


//Just need the name of the class here.. You also have access to an (args) and a (trigger)
//args contains an object with the data you need, for instance - magnetic field data (see EventArgs.h)
//(trigger) may or may not contain the object that triggered the action
ACTIONEXECUTE(led_flash) {
	
	//Time* runTime = static_cast<Time*>(args);  //<-- time events contain current runTime as (args)
	_pin.toggle();
}
