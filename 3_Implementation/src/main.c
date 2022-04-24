#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LED1 PINC1
#define LED2 PINC0
#define LED3 PINB5
#define LED4 PINB4
#define LED5 PINB3
#define LED6 PINB2
#define LED7 PINB1

#define lcd_D7_port     PORTD
#define lcd_D7_bit      PORTD1
#define lcd_D7_ddr      DDRD

#define lcd_D6_port     PORTD 
#define lcd_D6_bit      PORTD2
#define lcd_D6_ddr      DDRD

#define lcd_D5_port     PORTD              
#define lcd_D5_bit      PORTD3
#define lcd_D5_ddr      DDRD

#define lcd_D4_port     PORTD
#define lcd_D4_bit      PORTD4
#define lcd_D4_ddr      DDRD

#define lcd_D3_port     PORTB
#define lcd_D3_bit      PORTB6
#define lcd_D3_ddr      DDRB

#define lcd_D2_port     PORTB
#define lcd_D2_bit      PORTB7
#define lcd_D2_ddr      DDRB

#define lcd_D1_port     PORTD
#define lcd_D1_bit      PORTD5
#define lcd_D1_ddr      DDRD

#define lcd_D0_port     PORTD
#define lcd_D0_bit      PORTD6
#define lcd_D0_ddr      DDRD

#define lcd_E_port      PORTD 
#define lcd_E_bit       PORTD7
#define lcd_E_ddr       DDRD

#define lcd_RS_port     PORTB
#define lcd_RS_bit      PORTB0
#define lcd_RS_ddr      DDRB

#define lcd_LineOne     0x00                    
#define lcd_LineTwo     0x40                    

#define lcd_Clear           0b00000001          
#define lcd_Home            0b00000010          
#define lcd_EntryMode       0b00000110          
#define lcd_DisplayOff      0b00001000          
#define lcd_DisplayOn       0b00001100          
#define lcd_FunctionReset   0b00110000          
#define lcd_FunctionSet8bit 0b00111000          
#define lcd_SetCursor       0b10000000          

uint8_t s0[]="No LEDs Turned ON!!!";
uint8_t s1[]="1st LED Turned ON!!!";
uint8_t s2[]="2nd LED Turned ON!!!";
uint8_t s3[]="3rd LED Turned ON!!!";
uint8_t s4[]="4th LED Turned ON!!!";
uint8_t s5[]="5th LED Turned ON!!!";
uint8_t s6[]="6th LED Turned ON!!!";
uint8_t s7[]="7th LED Turned ON!!!";

void lcd_write_8(uint8_t);
void lcd_write_instruction_8d(uint8_t);
void lcd_write_character_8d(uint8_t);
void lcd_write_string_8d(uint8_t *);
void lcd_init_8d(void);

void init_ports_mcu()
{
	DDRD=0xFFu;
	PORTD=0x00u;
	DDRB=0xFFu;
	PORTB=0x00u;
	DDRC=0xFFu;
	DDRC &= ~(1<<0);
	PORTC=0x00u;
}

int map(int x, int a, int b, int c, int d)
{
	return((x-a)*(d-c)/(b-a)+c);
}

void ADC_init()
{
	ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	ADMUX=(1<<REFS0);
}

uint16_t get_LightLevel()
{
	_delay_ms(10);
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	_delay_ms(10);
	return(ADC);
}

int main(void)
{
	lcd_D7_ddr |= (1<<lcd_D7_bit);                  
	lcd_D6_ddr |= (1<<lcd_D6_bit);
	lcd_D5_ddr |= (1<<lcd_D5_bit);
	lcd_D4_ddr |= (1<<lcd_D4_bit);
	lcd_D3_ddr |= (1<<lcd_D3_bit);
	lcd_D2_ddr |= (1<<lcd_D2_bit);
	lcd_D1_ddr |= (1<<lcd_D1_bit);
	lcd_D0_ddr |= (1<<lcd_D0_bit);

	lcd_E_ddr |= (1<<lcd_E_bit);                    
	lcd_RS_ddr |= (1<<lcd_RS_bit);                  

	lcd_init_8d();                                  

	init_ports_mcu();
	ADC_init();
	
	while(1)
	{
		switch(map(get_LightLevel(),0,1000,0,3))
		{
			case 0:
				lcd_write_string_8d(s0);
				//PORTC &= ~(1<<PINC2);
				//PORTC &= ~(1<<PINC1);
				//PORTB &= ~(1<<PINB5);
				//PORTB &= ~(1<<PINB4);
				PORTB &= ~(1<<PINB3);
				PORTB &= ~(1<<PINB2);
				PORTB &= ~(1<<PINB1);
				_delay_us(80);
			break;
			case 1:
				lcd_write_string_8d(s1);
				//PORTC = (1<<PINC2);
				//PORTC &= ~(1<<PINC1);
				//PORTB &= ~(1<<PINB5);
				//PORTB &= ~(1<<PINB4);
				PORTB = (1<<PINB3);
				PORTB &= ~(1<<PINB2);
				PORTB &= ~(1<<PINB1);
				_delay_us(80);
			break;
			case 2:
				
				lcd_write_string_8d(s2);
				//PORTC &= ~(1<<PINC2);
				//PORTC = (1<<PINC1);
				//PORTB &= ~(1<<PINB5);
				//PORTB &= ~(1<<PINB4);
				PORTB &= ~(1<<PINB3);
				PORTB = (1<<PINB2);
				PORTB &= ~(1<<PINB1);
				_delay_us(80);
			break;
			case 3:
				
				lcd_write_string_8d(s3);
				//PORTC &= ~(1<<PINC2);
				//PORTC &= ~(1<<PINC1);
				//PORTB = (1<<PINB5);
				//PORTB &= ~(1<<PINB4);
				PORTB &= ~(1<<PINB3);
				PORTB &= ~(1<<PINB2);
				PORTB = (1<<PINB1);
				_delay_us(80);
			break;
			/*case 4:
				
				lcd_write_string_8d(s4);
				PORTC &= ~(1<<PINC2);
				PORTC &= ~(1<<PINC1);
				PORTB &= ~(1<<PINB5);
				PORTB = (1<<PINB4);
				PORTB &= ~(1<<PINB3);
				PORTB &= ~(1<<PINB2);
				PORTB &= ~(1<<PINB1);
				_delay_us(80);
			break;
			case 5:
				
				lcd_write_string_8d(s5);
				PORTC &= ~(1<<PINC2);
				PORTC &= ~(1<<PINC1);
				PORTB &= ~(1<<PINB5);
				PORTB &= ~(1<<PINB4);
				PORTB = (1<<PINB3);
				PORTB &= ~(1<<PINB2);
				PORTB &= ~(1<<PINB1);
				_delay_us(80);
			break;
			case 6:
				
				lcd_write_string_8d(s6);
				PORTC &= ~(1<<PINC2);
				PORTC &= ~(1<<PINC1);
				PORTB &= ~(1<<PINB5);
				PORTB &= ~(1<<PINB4);
				PORTB &= ~(1<<PINB3);
				PORTB = (1<<PINB2);
				PORTB &= ~(1<<PINB1);
				_delay_us(80);
			break;
			case 7:
				
				lcd_write_string_8d(s7);
				PORTC &= ~(1<<PINC2);
				PORTC &= ~(1<<PINC1);
				PORTB &= ~(1<<PINB5);
				PORTB &= ~(1<<PINB4);
				PORTB &= ~(1<<PINB3);
				PORTB &= ~(1<<PINB2);
				PORTB = (1<<PINB1);
				_delay_us(80);
			break;*/
		}
    }
	return(0);
}

void lcd_init_8d(void)
{
	_delay_ms(100);
	lcd_write_instruction_8d(lcd_FunctionReset);
	_delay_ms(10);
	lcd_write_instruction_8d(lcd_FunctionReset);
	_delay_us(200);
	lcd_write_instruction_8d(lcd_FunctionReset);
	_delay_us(200);
	lcd_write_instruction_8d(lcd_FunctionSet8bit);
	_delay_us(80);
	lcd_write_instruction_8d(lcd_DisplayOff);
	_delay_us(80);
	lcd_write_instruction_8d(lcd_Clear);
	_delay_ms(4);
	lcd_write_instruction_8d(lcd_EntryMode);
	_delay_us(80);
	lcd_write_instruction_8d(lcd_DisplayOn);
	_delay_us(80);
}

void lcd_write_string_8d(uint8_t theString[])
{
	volatile int i = 0;
	while (theString[i] != 0)
	{
		lcd_write_character_8d(theString[i]);
		i++;
		_delay_us(80);
	}
}

void lcd_write_character_8d(uint8_t theData)
{
	lcd_RS_port |= (1<<lcd_RS_bit);
	lcd_E_port &= ~(1<<lcd_E_bit);
	lcd_write_8(theData);
}

void lcd_write_instruction_8d(uint8_t theInstruction)
{
	lcd_RS_port &= ~(1<<lcd_RS_bit);
	lcd_E_port &= ~(1<<lcd_E_bit);
	lcd_write_8(theInstruction);
}

void lcd_write_8(uint8_t theByte)
{
	lcd_D7_port &= ~(1<<lcd_D7_bit);
	if (theByte & 1<<7) lcd_D7_port |= (1<<lcd_D7_bit);

	lcd_D6_port &= ~(1<<lcd_D6_bit);
	if (theByte & 1<<6) lcd_D6_port |= (1<<lcd_D6_bit);

	lcd_D5_port &= ~(1<<lcd_D5_bit);
	if (theByte & 1<<5) lcd_D5_port |= (1<<lcd_D5_bit);

	lcd_D4_port &= ~(1<<lcd_D4_bit);
	if (theByte & 1<<4) lcd_D4_port |= (1<<lcd_D4_bit);

	lcd_D3_port &= ~(1<<lcd_D3_bit);
	if (theByte & 1<<3) lcd_D3_port |= (1<<lcd_D3_bit);

	lcd_D2_port &= ~(1<<lcd_D2_bit);
	if (theByte & 1<<2) lcd_D2_port |= (1<<lcd_D2_bit);

	lcd_D1_port &= ~(1<<lcd_D1_bit);
	if (theByte & 1<<1) lcd_D1_port |= (1<<lcd_D1_bit);

	lcd_D0_port &= ~(1<<lcd_D0_bit);
	if (theByte & 1<<0) lcd_D0_port |= (1<<lcd_D0_bit);

	lcd_E_port |= (1<<lcd_E_bit);
	_delay_us(1);
	lcd_E_port &= ~(1<<lcd_E_bit);
	_delay_us(1);
}

