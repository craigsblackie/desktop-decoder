# Desktop Wiegand Decoder

Overview
--------

Useful tool to easily display an encoded hex value of the Wiegand data transmitted over the wire from an Access Control reader.
Aimed as a visual aid for confirming effective credential clones, and technology downgrade attacks.
Also capable of easily retrieving PACS data from "secure" credentials making use of default encryptions keys, such as HID SEOS.

![HIDRP40](https://github.com/craigsblackie/desktop-decoder/blob/main/Images/Desktop_Decoder4.jpg?raw=true)

Kit List
--------

*   Wiegand Based reader
    *   HID RP40 or RPK40 Multiclass SE is the best as it has the ability to read both low frequency as well as high frequency cards
*   Arduino Nano
*   Arduino OLED screen
    *   [OLED Screen](https://www.amazon.co.uk/gp/product/B08NDJ3S3Q/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
* USB-C PD board
    * Fun fact. HID RPK40s boot on 5v, so no need to buy a big USB-C PD compatible power supply if you dont want.

Build Instructions
------------------

### Pinout

The pinout is from the perspective of all components to avoid mistakes and aid in troubleshooting.

#### Reader

*   Wiegand Data 1 - D3 (Arduino)
*   Wiegand Data 0 - D2 (Arduino)
*   +12v - +12v (USB PD Board)
*   Gnd - Gnd (USB PD Board)

#### Arduino

*   VIN - +12v (USB PD Board)
*   GND - Gnd (USB PD Board)
*   D2 - Wiegand Data 0 (Reader)
*   D3 - Wiegand Data 1 (Reader)
*   A4 - SDA (OLED)
*   A5 - SCL (OLED)
*   5v - VCC (OLED)
*   GND - Gnd (OLED)

#### OLED

*   SDA - A4 (Arduino)
*   SCL - A5 (Arduino)
*   VCC - 5v (Arduino)
*   Gnd - GND (Arduino)

### Case

If you have access to a 3D printer, this STL prints quickly and doesnt require any supports. It also has slots for each peice of hardware.
Case secured making use of M3 bolts, which thread into the PLA plastic to avoid the need for brass thread inserts.
Reader fixed to case using M3 bolts as well.

*   [USB C PD Board](https://www.amazon.co.uk/Youmile-charge-trigger-module-voltage/dp/B09WTQC5Q4)
*   [Bolt pack](https://www.amazon.co.uk/TOOINKCV-Metric-Washers-Assortment-Machine/dp/B0CLRRKVV6)

### Optional Wifi addon

Added functionality can be had with an RFID-Tool installed into the same case to add the ability to retrieve the data read via Wi-Fi. This tool connects in-line with the reader, and doesn't interfere with the arduino.

*   [RFID-Tool](https://labs.ksec.co.uk/product/esp-rfid-tool/)

Usage
-----

As simple as it gets: turn it on and scan any card that the connected reader is capable of reading. PACS data and bit length will be displayed on the screen. This data can be written to another card using a Proxmark or similar device, decoded to retrieve the facility code and card number.

This serves as a visual aid for effective card cloning and tech downgrade attacks to confirm that PACS data is transmitted identically.

![HIDRPK40](https://github.com/craigsblackie/desktop-decoder/blob/main/Images/Desktop%20Decoder3.jpg?raw=true)

### Credits
* Craig S. Blackie and Warren Houghton 
