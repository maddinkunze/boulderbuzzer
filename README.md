# boulderbuzzer - Buzzers that can be mounted to a portable boulder wall

This repository contains information, source code, pcb designs, assembly instructions, etc for building the following buzzers:


Those buzzers are designed around hollow M10 bolts that can be used to simultaneously mount the buzzer to a (in my case portable) boulder wall whilst allowing power cables to pass through the back and neatly hidden away.


## Buzzer

The [buzzer subdirectory](buzzer) contains some docs, the pcb design, the source code, some 3d-printable files and a few words about assembly, disassembly and repair for/of an individual buzzer.

## Station

The [station subdirectory](station) contains the documentation and source code for the base station to which all buzzers connect.


## Troubleshooting

1. **General:** What seems to be faulty?
   - Power Supply: Replace your power supply. It should provide 4.5V-5.5V and at least 0.5A + anything you want to switch on when pressing a buzzer (external ports). If possible, only connect one thing per power supply
   - Station: Repair the station as described here: [TODO]
   - All Buzzers: It is probably the station, do what the option "Station" says
   - One Buzzer: Go to step 2 (Buzzer/Startup)
2. **Buzzer/Startup:** Which color(s) does the buzzer have when power is supplied?
   - None: The buzzer (specifically the power plug/cable, the voltage regulator or the microcontroller) is probably faulty, go to step 3 (Buzzer/Faulty)
   - Blue (pulsating): Try to restart the station by unplugging it. It still does not work? The station is probably faulty, go back to step 1 (General)
   - Green (3 blinks): The buzzer is connected, go to step 4 (Buzzer/Press)
3. **Buzzer/Faulty:** Unplug everything and only plug in the station and the one "faulty" buzzer. Try to use the power cable of a different buzzer. Does the buzzer behave differently?
   - Yes: Go to step 2 (Buzzer/Startup). You have been here already and are going around in circles? Do what the option "No" says.
   - No: The buzzer is probably faulty. Repair the buzzer as described [here](buzzer#disassembly-and-repair)
4. **Buzzer/Press:** Press the buzzer after it is connected. What happens?
   - Nothing: the buzzer (specifically the microcontroller or button) is probably faulty, go to step 3 (Buzzer/Faulty)
   - It blinks red for half a second and turns off: There is probably another buzzer active and the game is working as intended. You have checked that already and it is not the intended behaviour (i.e. only one buzzer connected)? Then go to step 3 (Buzzer/Faulty)
   - It or another buzzer turned on or changed color: The buzzer probably works as intended. Go to step 5 (Buzzer/Working)
5. **Buzzer/Working:** Try to connect everything back one by one. Does it stop working at some point?
   - Yes: Inspect the last thing you've connected before it stopped working. Try to fix the last thing you've connected before it stopped working by going to step 1 (General). Did you try this with multiple things and at some random point it stopped working but it could not be associated with one specific device? Your power supply is probably not powerful enough. Go back to step 1 (General) and assume the power supply is the fault.
   - No: You've fixed it by restarting it i guess. Yay