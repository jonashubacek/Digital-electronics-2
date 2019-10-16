/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-11-28
 * Last update: 2019-10-16
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Control LEDs using functions from GPIO and Timer 
 *              libraries. Do not use delay library any more.
 * TODO: Create and test functions to control 8-bit Timer/Counter0, 
 *       16-bit Timer/Counter1, and 8-bit Timer/Counter2 modules.
 * NOTE: Store timer.c and timer.h files in library/src and library/inc
 *       folders.
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include "GPIO.h"
#include "timer.h"
#include <avr/interrupt.h>

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define LED_BLUE    PB3
#define LED_RED     PB0

/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
 *  Brief:  Main program. Toggle three LEDs with the modules of internal 
 *          8- and 16-bit timers.
 *  Input:  None
 *  Return: None
 */
int main(void)
{
    /* LED_GREEN */
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write(&PORTB, LED_GREEN, PIN_LOW);
    /* LED_BLUE */
    // TODO: Configure blue LED
    GPIO_config_output(&DDRB, LED_RED);
    GPIO_write(&PORTB, LED_RED, PIN_LOW);
    /* LED_RED */
    // TODO: Configure red LED


    /* Set Timer0 */
    TIM_config_prescaler(TIM0, TIM_PRESC_1024);
    TIM_config_interrupt(TIM0, TIM_OVERFLOW_ENABLE);

    /* Set Timer1 */
    // TODO: Configure Timer1 clock source and enable overflow interrupt
    TIM_config_prescaler(TIM1, TIM_PRESC_256);
    TIM_config_interrupt(TIM1, TIM_OVERFLOW_ENABLE);
    /* Set Timer2 */
    // TODO: Configure Timer2 clock source and enable overflow interrupt
    

    /* Enable interrupts by setting the global interrupt mask */
    sei();

    /* Infinite loop */
    for (;;) {
    }

    return (0);
}

/**
 *  Brief: Timer/Counter0 overflow interrupt routine. Toggle green LED.
 */
ISR(TIMER0_OVF_vect)

{
    //TODO: Toggle green LED
 GPIO_toggle(&PORTB, LED_GREEN);
 
}

/**
 *  Brief: Timer/Counter1 overflow interrupt routine. Toggle blue LED.
 */
ISR(TIMER1_OVF_vect)
{
    // TODO: Toggle blue LED
  GPIO_toggle(&PORTB, LED_RED);  
}


/**
 *  Brief: Timer/Counter2 overflow interrupt routine. Toggle red LED.
 */
/*ISR(TIMER2_OVF_vect)
{
    // TODO: Toggle red LED
}
*/