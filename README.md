# Desktop Wiegand Decoder

Overview
--------

Useful tool to easily display an encoded hex value of the Weigand data transmitted over the wire from an Access Control reader

Kit List
--------

*   Wiegand Based reader
    *   HID RPK40 is the best as it has the ability to read both low frequency as well as high frequency cards
*   Arduino Nano
*   Arduino OLED screen
    *   [OLED Screen](https://www.amazon.co.uk/gp/product/B08NDJ3S3Q/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
* USB C PD board
    * Fun fact. HID RPK40s boot on 5v, so no need to buy a big USB C PD compatable plug if you dont want.

Build Instructions
------------------

### Pinout

I've written the pinout from the perspective of all components to avoid mistakes and aid in troubleshooting.

#### Reader

*   Weigand Data 1 - D3 (Arduino)
*   Weigand Data 0 - D2 (Arduino)
*   +12v - +12v (USB PD Board)
*   Gnd - Gnd (USB PD Board)

#### Arduino

*   VIN - +12v (USB PD Board)
*   GND - Gnd (USB PD Board)
*   D2 - Weigand Data 0 (Reader)
*   D3 - Weigand Data 1 (Reader)
*   A4 - SDA (OLED)
*   A5 - SCL (OLED)
*   5v - VCC (OLED)
*   GND - Gnd (OLED)

#### OLED

*   SDA - A4 (Arduino)
*   SCL - A5 (Arduino)
*   VCC - 5v (Arduino)
*   Gnd - GND (Arduino)

### Optional Case

I have 3D modelled a case to use with either an RPK40 or an RP40 reader. With this I have incorporated a hole for a USB C socket jack at the rear. The case is designed to be held together using M3 bolts, these can be easily bought off amazon also.

*   [USB C PD Board](https://www.amazon.co.uk/Youmile-charge-trigger-module-voltage/dp/B09WTQC5Q4)
*   [Useful bolt pack](https://www.amazon.co.uk/gp/product/B075CKYJF6)

### Optional Wifi addon

So I also installed an RFID-Tool into the same box to add the ability to retrieve the data read via Wi-Fi also. This tool does exactly the same as the arduino code, but has a nice webgui and Wi-Fi onboard also for when you need a reader connected to your laptop as well as a standalone desktop one. This tool just connects in-line with the reader, and doesn't interfere with the arduino.

*   [RFID-Tool](https://labs.ksec.co.uk/product/esp-rfid-tool/)

### Credits
* Craig S. Blackie and Warren Houghton 
