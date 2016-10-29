#ifndef LED_GPIO_SET_H
#define LED_GPIO_SET_H

#ifdef USE_BCM2835_C_LIB

	#include<bcm2835.h>

	//
	// GPIO LED PINS SET
	//
	#define LED_DR1  RPI_BPLUS_GPIO_J8_29
	#define LED_DR2  RPI_BPLUS_GPIO_J8_33
	#define LED_DG1  
	#define LED_DG2  
	#define LED_DB1  RPI_BPLUS_GPIO_J8_31
	#define LED_DB2  RPI_BPLUS_GPIO_J8_35
	
	#define LED_A  RPI_BPLUS_GPIO_J8_37
	#define LED_B  RPI_BPLUS_GPIO_J8_36
	#define LED_C  RPI_BPLUS_GPIO_J8_38
	#define LED_D  RPI_BPLUS_GPIO_J8_40
	
	#define LED_CLK  RPI_BPLUS_GPIO_J8_11
	#define LED_LAT  RPI_BPLUS_GPIO_J8_13
	#define LED_OE   RPI_BPLUS_GPIO_J8_15

	//
	// GPIO ACCESS ACTION SET
	//
	#define GPIO_INIT()           bcm2835_init()
	#define GPIO_SET_OUTPUT(x)    bcm2835_gpio_fsel(x, BCM2835_GPIO_FSEL_OUTP)
	#define GPIO_SET_INPUT(x)     bcm2835_gpio_fsel(x, BCM2835_GPIO_FSEL_INPT)
	#define GPIO_SET_PULLUP(x)    bcm2835_gpio_set_pud(x, BCM2835_GPIO_PUD_UP)
	#define GPIO_SET_PULLDOWN(x)  bcm2835_gpio_set_pud(x, BCM2835_GPIO_PUD_DOWN)
	#define GPIO_READ(x)          bcm2835_gpio_lev(x)
	#define GPIO_WRITE(x,y)       bcm2835_gpio_write(x,y)

#elif USE_WIRINGPI_C_LIB

	#include<wiringPi.h>

	#define LED_DR1  
	#define LED_DR2  
	#define LED_DG1  
	#define LED_DG2  
	#define LED_DB1  
	#define LED_DB2  
	
	#define LED_A  
	#define LED_B  
	#define LED_C  
	#define LED_D  
	
	#define LED_CLK  
	#define LED_LAT  
	#define LED_OE   

	#define GPIO_INIT
	#define GPIO_SET_OUTPUT(x)    
	#define GPIO_SET_INPUT(x)     
	#define GPIO_SET_PULLUP(x)    
	#define GPIO_SET_PULLDOWN(x)  
	#define GPIO_READ(x)          
	#define GPIO_WRITE(x,y)       

#endif 


#endif
