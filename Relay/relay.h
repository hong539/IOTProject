#include <bcm2835.h>
#include <stdio.h>
#include "it_shield.h"
#define GPIO_INPUT 18

void relay_on_off(h)
{
    // If you call this, it will not actually access the GPIO

    int value;
    int h = GPIO_INPUT
    if (!bcm2835_init())
	return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(RELAY, BCM2835_GPIO_FSEL_OUTP);
   // bcm2835_gpio_fsel(LED2, BCM2835_GPIO_FSEL_OUTP);
   // bcm2835_gpio_fsel(BTN1, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(COM, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(COM, HIGH);
    // Blink
	
    while (1)
    { 
		
	// value= bcm2835_gpio_lev(BTN1);
	// printf("read from BTN1_INPUT: %d\n", value);	
		
	//if (value==1) {	
	// Turn it on

    if (h>65)
	bcm2835_gpio_write(RELAY, HIGH);
	//bcm2835_gpio_write(LED2, HIGH);
	
	//bcm2835_delay(3000);
		

   // } else {
	
	// turn it off
	else 
	bcm2835_gpio_write(RELAY, LOW);
	//bcm2835_delay(3000);
	//bcm2835_gpio_write(LED2, LOW);


   // }
	
	//bcm2835_delay(100);  //500ms
	}
    //bcm2835_close();
    return 0;
}