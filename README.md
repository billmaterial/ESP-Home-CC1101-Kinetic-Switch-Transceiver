# IMPORTANT
--> make sure to copy both `tranceiver.yaml` and `cc1101.h` <--

![image](https://esphome.io/_images/made-for-esphome-black-on-white.svg)
# CC1101 support for ESPHome
![image](./cc1101.jpg)
# CC1101 Module used

# Usage
See `tranceiver.yaml` and `cc1101.h`
Some tweaking may be needed for your hardware and different switches!

You will need to change the "code[]" lines to reflect your actual codes!

Enable the raw output in the yaml and copy the data output to the code[] lines.

# Info
Whilst developing this project I found that the basic 433MHz receivers have a limited data rate and do not work with these switches.

The basic transmitters do seem to work at the required minimum pulse width of around 20uS.

This is the reason why a TI cc1101 based tranceiver is needed.

# Parts Used
The Kinetic switches that this project has been written for are: DieseRC Wireless Kinetic Light Switchs.

https://www.amazon.co.uk/DieseRC-Wireless-Receiver-Controller-Self-generating/dp/B0BMKJ8Q4Q/ref=sr_1_8?dib=eyJ2IjoiMSJ9.Kn6m9z_pT4bN5Ukgc0zMqtHgPiE9LCabYvOqONV5QcbFFcthhBMcwjsC3xZpb1jiGz9eLl5NsHhaXmgOcCJE-e4Y5vJGQ4EEUYKJjUJp2ze6HON96gnuDFJ10JAJCccV8dXcTkrMd8spQScyHOlEprRlVfAXQKYBhEcYpckVoxz9E-nqW_0lkafFP5L0KiUJA3fN9-8piblSpABj_xBKN_yaMtSoX9f3IX-Kg5y14sr_MfyJxWyRQCUfkZ1LYB3l8a9simAz7kMDrCDR_tSCUWDocxmoelvmB-vsx1MJ80Y.Lw8pDJO79pT6h6-eS1KGAlB1W8MfqGEYTb5IdnVVB98&dib_tag=se&keywords=kinetic%2Bswitch&qid=1724415744&sr=8-8&th=1

CC1101 Module used: Elecbee CC1101 Wireless Module 433 MHz Long-Distance Industrial Grade Wireless Transceiver Module,Wireless RF Transceiver with SMA Antenna, Support 2-FSK, GFSK and MSK Modulation

https://www.amazon.co.uk/CC1101-Long-Distance-Industrial-Wireless-Transceiver/dp/B09WKGYFPV/ref=sr_1_1?crid=34GH249JYDVC3&dib=eyJ2IjoiMSJ9.rZF_1XR_B5UfL6OWvDqd1Se7CME1Nqu-KToK0kNVD9ajKwuqykK596peUFK_2ch5Cs7Ya2BhRnNvbd1YzX13VTm17nrslididn9ySTmqr8imGTawf3zuP24zGrCkB9T_DCyOfJ5rgvdD6Eq2fWhkTzWFDTq87gbAnA8iWM4uf5lPVLiWdS9yatXXT7g7JH1WZpraQ3P5400imwm-IlaElcLBCeYZ6yQujmXMRjHUNBU.JEauVkOR33hbUlYXB-nhGYhWRqPrSit60-3YH6_HwXo&dib_tag=se&keywords=elecbee+cc1101+433mhz&qid=1724416727&sprefix=elecbee+cc1101+433mhz%2Caps%2C48&sr=8-1

# Raw signal visualizer
https://github.com/dbuezas/esphome-remote_receiver-oscilloscope

# Based on the excellent work of dbuezas/esphome-cc1101
https://github.com/dbuezas/esphome-cc1101
