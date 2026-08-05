#include "lcd.h"                     // LCD driver header
#include "kpm.h"                     // Keypad driver header
#include "i2c.h"                     // I2C driver header
#include "i2c_eeprom.h"              // EEPROM driver header
#include "uart.h"                    // UART driver header
#include "r305.h"                    // Fingerprint sensor header
#include "delay.h"                   // Delay functions
#include "exint_menu.h"              // External interrupt header
#include "i2c_eeprom.h"              // EEPROM header
#include "types.h"                   // User defined data types
#include "l293d.h"                   // Motor driver header

extern u8 menu_flag;                 // External menu flag variable

int main()
{
	//char ch;
        init_lcd();                  // Initialize LCD

        init_kpm();                  // Initialize keypad

        init_uart0();                // Initialize UART0

        init_i2c();                  // Initialize I2C

        init_eint2();                // Initialize external interrupt

       // init_ids();                  // Initialize stored IDs

       init_l293d();                // Initialize motor driver

       title();                     // Display first project title
       delay_ms(1000);  	// Delay
	while(1)
        {
               if(menu_flag==1)      // Check menu interrupt flag
                {
                        menu();       // Open menu
                }
						
                login();              // Perform login operation
					
        }
}
