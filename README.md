# minnowmax-rgbled
WS2812B/APA102 Linux driver for Minnowboard Max
This is an experimental scholar project for the Minnowboard Max platform. The objective is to provide a Linux driver that use the SPI and DMA of the Minnowboard Max to interface with the LED strips of WS2812B and APA102 types. 

In addition, the libraries provide an Ambilight-like function just as the [Boblight](https://www.tweaking4all.com/home-theatre/xbmc/xbmc-boblight-openelec-ws2811-ws2812/) project.

## Requirements
The basic functionality to control RGB LEDs (APA102 & WS2812B) has been tested in the below platforms, BUT, it is intended to work in any Linux distribution:
* Minnowboard Max
* Xubuntu 16.04.2
* Arch Linux

The Ambilight-like function has been tested using the below desktop environments (Using X11):
* Gnome
* Xfce

As the hardware used by this driver already has an official Linux module it is needed to blacklist those modules. Add the below lines into your /etc/modprobe.d/blaklist.conf file:
```
blacklist dw_dmac_core
blacklist dw_dmac
blacklist dw_dmac_pci
blacklist pxa2xx_spi_pci
blacklist pxa2xx_spi
```
Note: Recent kernels contain dw_dmac driver as a built-in module, if it is your case, it is needed to recompile the kernel and modularize the dw_dmac driver so it can be blacklisted.
### Compilation
In the working directory there are two important files to get started:
* compile.sh
* Makefile

You would need to install some dependencies in order to compile the driver and the libraries
* Kernel headers
* Building Libraries (Ubuntu: build-esential; ArchLinux: base-devel)
* X11 dev libraries (Ubuntu: libx11-dev libxtst-dev; Archlinux: libx11 libxrender)

To compile and install the driver simply use:
```
make
make install
```
Reboot for the changes take effect, or run:
```
modprobe main_rgbled.ko
```

For the libraries, the project comes with an example main.c file containing two of the basic functions, the example main.c file is compiled by running the compile.sh script:
```
./compile.sh
```


## Usage
To use the driver is needed to include the "headers/rgbled.h" header file in your sources, this file contain the IOCTL functions to communicate with the main_rgbled Linux driver. The functions are the following:
* rgbled_init - Run this function before anything, this will create the connection to the main_rgbled driver and receive a unsigned int value containing the configuration of the driver. Use the macros provided to set the configuration in the variable. The example below will set the driver to control 239 APA102 RGB LEDs using the DMA channel 0:
```
	uint32_t ledsconfig = RGBLED_CONF_TYPEAPA102 | 
							          RGBLED_CONF_DMACH(0) | 
							          RGBLED_CONF_LEDNUM(239);

	rgbled_init(&ledsconfig);
  ```
* rgbled_function - Set a function or color preset from the ones available, the function receive one of the following values:
```
	leds_off  -  Turn off the leds
	leds_on  -  Turn on the leds (Completely white)
	leds_userdefined  -  Wait for a user custom color (See below)
	leds_warm  -  Warm yellowish color
	leds_solar  -  Sun like color
	leds_green  -  Only green leds on
	leds_red  -  Only red leds ona
	leds_blue  -  Only blue leds on
  ```
  * 

