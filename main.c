#include <avr/io.h>
#include <util/delay.h>


// LCD control and data pins
#define RS PB4
#define EN PB3
#define D4 PD5
#define D5 PD4
#define D6 PD3
#define D7 PD2


void LCD_command(unsigned char cmd) {
	PORTB = cmd; // send the command to PORTB
	PORTB &= ~(1 << RS); // RS = 0 for command mode
	PORTB |= (1 << EN); // EN = 1 to enable the LCD
	_delay_ms(1);
	PORTB &= ~(1 << EN); // EN = 0 to latch the command 
	_delay_ms(2); // delay to let the LCD to process the command
}


void LCD_data(unsigned char data) {
	PORTB = data; //send data to PORTB
	PORTB |= (1 << RS); // RS = 1 for data mode
	PORTB |= (1 << EN);
	_delay_ms(1);
	PORTB &= ~(1 << EN);
	_delay_ms(2);
}


void LCD_init() {
	_delay_ms(15); // wait for VDD to rise above 4.5V
	LCD_command(0x02); // Initalize in 4-bit mode
	LCD_command(0x28); //4-bit mode, 2 line, 5x7 font
	LCD_command(0x0C); //Display ON, Cursor OFF, Blink OFF
	LCD_command(0x06); // move the cursor right after each character 
	LCD_command(0x01); //Clear the display
	_delay_ms(2); // Clear command requires at least 1.52ms
}


void LCD_clear() {
	LCD_command(0x01);
	_delay_ms(2);
}


void LCD_write_string(const char* str) {
	while (*str) {
		LCD_data(*str); // Send the current character to the LCD
		str++; // move to the next character 
	}
}


int main(void) {
	// Set the control pins as outputs 
	DDRB |= (1 << RS) | (1 << EN) | (1 << D4) | (1 << D5) | (1 << D6) | (1 << D7);

	LCD_init();

	while(1) {
		LCD_clear();
		LCD_write_string("Hello, LCD!"); // display message
		_delay_ms(2000);
	}

	return 0;
}


