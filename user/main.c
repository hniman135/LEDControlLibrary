
/*====================================================================================
 * 								INCLUDE FILES
=================================================================================== */

#include "at32f403a_407_board.h"
#include "at32f403a_407_clock.h"

/*====================================================================================
 * 								GLOBAL FUNTIONS
====================================================================================*/
int main(void)
{
/*The system clock is configured as follow:
  *         system clock (sclk)   = hext / 2 * pll_mult
  *         system clock source   = pll (hext)
  *         - hext                = HEXT_VALUE
  *         - sclk                = 240000000
  *         - ahbdiv              = 1
  *         - ahbclk              = 240000000
  *         - apb2div             = 2
  *         - apb2clk             = 120000000
  *         - apb1div             = 2
  *         - apb1clk             = 120000000
  *         - pll_mult            = 60
  *         - pll_range           = GT72MHZ (greater than 72 mhz)*/
  system_clock_config();
/*Config and init LEDs, buttons*/
  at32_board_init();

  while(1)
  {
	  /*If press the button, the 3 LEDs will toggle*/
	  if (at32_button_press()==0)
	  {
		  at32_led_toggle(LED2);
		  delay_ms(200);
		  at32_led_toggle(LED3);
		  delay_ms(200);
		  at32_led_toggle(LED4);
		  delay_ms(200);
	  }
  }
}
