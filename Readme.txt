This script is software in arduino based on 'C'

It requires Arduino (, an open-source electronics platform based on easy-to-use hardware and software)
, SW-420 (vibeation Sensor Module) , HC-SR501 (PIR Sensor Module), HC-06(BlueTooth Module "5DCV"),
MQ-9(gas Sensor Module)  , and Buzze.

connecting each module to arduino digital pin, exept 0, 1 pin becouse they are serial communication pin
but gasensor connent analog 0 pin.

set pinmode is 'INPUT' linked digtal pin. but buzzer set 'INPUT', the pin linked bluetooth don't set anything. 					 

tect switch connect is one pin set pinmode is 'INPUT' with 10kohm registence.