# Remotsy board

---

## DESCRIPTION

   The remotsy board is a ESP8266 infrared blaster and receiver. The board comes with a firmware to use the remosty
   cloud,but is possible to flash the board with any firmware. Here I wrote some examples.
   
  ## Example 1 RGB LED
     The board has a RGB neo pixel LED, the led is connected to the pin 14. the example use the ticker function to
     blink the led.
     
  ## Example 2 Infrared Receiver
      The board has a infrared receiver TSOP38238 that is connected to the pin 5,  Using the library IRremoteESP8266
      is possible to capture and decode an infrared code. This example is the same that exist in the library
      
  ## Example 3 Infrared Emissor  
      The board has 4 infrared led that are conntect to the pin 4,  Using the library IRremoteESP8266 is possible to
      transmite almost any infrared code. This example is the same that exist in the library
      
## Buy the board

https://www.tindie.com/products/10469/

## Flashing

   To flash the board, you need connect the serial pins (TX,RX and GND) and also connect the pin 0 to ground and 
   press the reset button. The easy way to do this is connect the pins with the yellow arrow.
      
![Connect pin 0 to ground](/images/remotsy_flash.png?raw=true "Connect pin 0 to ground")

