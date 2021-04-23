# Blinky Project In Action
## OFF
![image](https://github.com/274699/Emb-C/blob/823933e35c7921b2ce0e29233b4086412dc4da0d/simulation/OFF.png)
	* When seat is vaccant.
## PROMT
![image](https://github.com/274699/Emb-C/blob/5cd574e5e2fa230c62d52ad7ba47eecd4959a91f/simulation/PROMT.png)
	* This will promt the passanger to turn on the heater

## Code 
```
	for(;;)
	{
        change_led_state(HIGH);
		delay_ms(LED_ON_TIME);
        change_led_state(LOW);
		delay_ms(LED_OFF_TIME);	
	}
```
