# Zaniboni-Lighting

To begin with,
Enocean example had a blink command when the switch doesn't receive an acknowledgemnt from the server(s). 
That issue has been resolved (line 295 has been removed) and the source code is placed in Enocean after removing blink.c file. 


Enocean1.c is the source code for Enocean sewitch to control the light fixture using the LED driver with NINA module.
A single switch rocker pad is commissioned onto the driver and the switch controls the LED fixture.
We defined a variable ONOFF_LED and configured it as pin 11(Input to the driver) on the NINA module. 
Used the ONOFF_LED in place of BSP_LED_1 in the app_switch_debounce() function to control the LED fixture in lines 213 and 220.
We also need to initialize the pin 11 as an output pin which was done in the main() function in line 535.


Server Enocean.c is the source code for the servers(drivers with NINA) connected in the mesh and subscribed to Enocean switch.
We changed the variable ONOFF_SERVER_LED and configured it as pin 11(Input to the driver) on the NINA module.
We also need to initialize the pin 11 as an output pin which was done in the main() function in line 248.


These initializations and configurations are not a long term solution. We need to develop an custom board design incorporating all the future changes.
