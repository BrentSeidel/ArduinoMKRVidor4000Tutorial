# Tutorial For Using the Arduino MKR Vidor 4000 FPGA
I struggled a bit figuring out how to get started.  The tutorials on the
Arduino site were quite helpful (primarily https://docs.arduino.cc/tutorials/mkr-vidor-4000/vidor-gsvhdl), but some bits of information seemed to be
missing.  I could build the tutorial project and get it to work, but starting
my own project was a struggle.  The most important items were getting the
device correct and getting the pin definition loaded.  Once I got those,
I could copy the tutorial files into my project, build/modify them, load them,
and run them.

## Basic Steps
Here are the steps that I used.
1. Download the Intel Quartus Prime software.  I am using version 21.1.1
Build 850 06/23/2022 SJ Lite Edition
2. Create your directory structure and an empty project file.
3. Set the device to Cyclone 10 LP: 10CL016YU256C8G (this has bit me more than once).
4. From the "Device and Pin Options..." selection, go to Dual-Purpose Pins and
set them all to "Use as regular I/O".
5. Also in "Device and Pin Options...", go to "Programming Files" and select "Tabular Text File (.ttf)".
6. Get the file vidor_s_pins.qsf from https://github.com/wd5gnr/VidorFPGA/blob/master/vidordemo/constraints/MKRVIDOR4000/vidor_s_pins.qsf
7. In Quartus, go to "Assignments..."->"Import Assigments".  Select vidor_s_pins.qsf and then select
"Catagories" and only select "Pin & Location Assignments".
8. Now your project should be ready for you to add files and use it.

Note that the produced .ttf file is around 603kB.  If your file size is signifiantly
different from this, you may have the wrong device selected.  See item 3 above.

The Verilog and VHDL tutorials are just some simple logic gates (AND/OR/XOR/NOT).
The Arduino sketch runs through the four possible inputs and prints the results
from the FPGA.  Consider this to be the equivalent of a "Hello World" program to
verify that you have the toolchain setup and can load and run things.

## Pinout
One other thing that I have seen documented anywhere is pins to use on the FPGA
side and the CPU side.  The table below is what I've found.

| FPGA Pin | CPU Pin |
| -------- | ------- |
| `bMKR_D[0]` | 0 |
| `bMKR_D[1]` | 1 |
| `bMKR_D[2]` | 2 |
| `bMKR_D[3]` | 3 |
| `bMKR_D[4]` | 4 |
| `bMKR_D[5]` | 5 |
| `bMKR_D[6]` | 6 |
| `bMKR_D[7]` | 7 |
| `bMKR_D[8]` | 8 |
| `bMKR_D[9]` | 9 |
| `bMKR_D[10]` | 10 |
| `bMKR_D[11]` | 11 |
| `bMKR_D[12]` | 12 |
| `bMKR_D[13]` | 13 |
| `bMKR_D[14]` | 14 |
| `bMKR_A[0]` | 15 |
| `bMKR_A[1]` | 16 |
| `bMKR_A[2]` | 17 |
| `bMKR_A[3]` | 18 |
| `bMKR_A[4]` | 19 |
| `bMKR_A[5]` | 20 |
| `bMKR_A[6]` | 21 |
| `bMKR_AREF` | unknown |
| `iCLK` | Seems to be a 48MHz input |
 
 ## Other interesting bits
 I decided to install modelsim for simulating my models.  I searched online for it and found an Intel
 version.  Since I'm using Intel software, I figured that would be the one to use.  After installing
 it, I discovered that in Quartus Prime, it is called Questa Intel FPGA, not modelsim as one would
 expect.  After installing it, you have to go into your model settings and select the proper simulator
 before you can use it.  This is as far as I have gotten so far.
 
 ## Final Notes
 This will hopefully be enough to get you started.  The main intent is to get to the point where you
 can build a FPGA model and use it with an Arduino sketch.  Once you get to this point, you can start
 learing FPGA design instead of how to setup the tools.
 