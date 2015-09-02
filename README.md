# MCB2300 Clean Example
This program includes the most basic things to get you started. Everything is set up for uVision 4.54.

## Getting started
Pull this repository to your machine or download it from GitHub. In uVision, click Project -> Open Project... and select the uVision project that you've just downloaded.

## What's included
In this example the following things are included:
- Right configuration, no need to think about the 200kHz setting for ULINK and no need to think about include paths etc.
- General folders; general -> _/inc, _/src. This is where the basic files for this are stored (like LCD and LED).
- Program folders; /inc, /src. This is where the program itself is and where you should put your own code.
- Right LCD file (the one from BlackBoard)
- LED file (made from the Blinky example, provided by Keil), added some defines like LEDX, LED_ALL and LED_NONE (please take a look at LED.h in general/inc/LED.h)
- Timing file, this file includes a simple delay function.
- IRQ file, this file is needed for the delay function in timing.c.
- Button file, to control the INT0 button.
- Tone generator file, this file includes some basic functions to control the tone generator.

Please note, I disabled all optimizations to make the program debuggable. Check the "C/C++ Settings" under "Options for Target 'MCB2300'" in the Project menu.

## Changes
I'm planning to update this repo with new libraries as time passes. Please clone this repository (instead of downloading it), so that you can keep it up to date.
If you encounter a problem or if you do want to add something (like a file or function), don't hesitate to e-mail me at info@ljpc.nl.

#### Oh and by the way
This is written in Allman style.
