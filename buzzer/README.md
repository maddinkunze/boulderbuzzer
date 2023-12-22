## Build Instructions

### Bill of Materials

| Amount | Part Name | DIY | Buy | Image | Additional Notes |
|---|---|---|---|---|---|
| $1 \times$ | Buzzer | ❌ | https://www.amazon.com/dp/B0CPHT5N3X <br> https://www.ebay.com/itm/395040810324 <br> https://www.amazon.com/dp/B0CGHFH3M1 <br> https://www.amazon.com/dp/B0CQSXBK7R <br> https://www.sparkfun.com/products/9181 <br> https://grobotronics.com/big-dome-push-button-red-100mm.html?sl=en <br> https://www.sparkfun.com/products/retired/11964 | | Preferrably with a transparent dome
| $1 \times$ | Buzzer Case | Click here | ❌ | | May not be neccessary, you can repurpose the outer shell of the buzzer
| $1 \times$ | 3D-Printed Bolt Holder | Click here | Can be ordered online using the design files | | Can be omitted in certain cases, should match the type of hollow M10 Bolt you are using
| $1 \times$ | M10 $\times$ 30mm Bolt (Hollow) | Click here | https://www.amazon.de/dp/B0BRNBQY3Y <br> https://www.ebay.com/itm/143405833724 | |
| $2 \times$ | M3 $\times$ 10mm Bolt (countersunk) |
| $2 \times$ | M3 $\times$ 12mm Bolt (countersunk) |
| $2 \times$ | M3 Nut |
| $2 \times$ | M3 Washer |
| $2 \times$ | M3 Rivet Nut | Click here | https://www.amazon.com/dp/B0962QQGFZ <br> https://www.ebay.com/itm/151788854026 | | Should have a height of at least [TODO]mm (so that the spring has enough room for actually compressing so the buzzer can be pressed)
| $1 \times$ | Custom PCB | Click here | The custom PCB can be ordered online (non-exhaustive list) from: <br> https://pcbway.com/ <br> https://jlcpcb.com/
| $2 \times$ | ESP-01S Module | ❌ | https://www.amazon.com/dp/B09J2KPHTN <br> https://www.ebay.com/itm/334980650665 | | An ESP-01S is preferred over an ESP-01, but both can be used
| $1 \times$ | AMS1117-3.3V Voltage Regulator (SMD) | ❌ | https://www.amazon.com/dp/B07X75XXYL <br> https://www.ebay.com/itm/392097419034
| $2 \times$ | RGB LED (5050 SMD) | ❌ | https://www.amazon.com/dp/B01CUGABPU <br> https://www.ebay.com/itm/191674244800 | | The RGB LEDs should not have a common cathode, having individual anodes for each internal LED is preferred but not neccessary; WS2812B and other addressable LEDs are **NOT** supported by my PCB design
| $2 \times$ | 100 - 200 $\Omega$ Resistor (THT)
| $1 \times$ | 120 - 220 $\Omega$ Resistor (THT)
| $1 \times$ | 3.3 - 10 $k\Omega$ Resistor (THT)
| $1 \times$ | 2 Pin, 3.5mm Pitch Screw Terminal (THT) | ❌ | https://www.amazon.com/dp/B07B791NMQ <br> https://www.ebay.com/itm/195773785709 <br> https://www.ebay.com/itm/314913808536 | | This can be omitted when soldering the power cable directly to the PCB; a larger or smaller pitch terminal can be used by changing the pcb design files
| $2 \times$ | 4 Pin, 2.54mm Pitch Round Female Pin Header/Socket (THT) | ❌ | https://www.amazon.com/dp/B0778TFL39 <br> https://www.ebay.com/itm/285532509511 <br> https://www.ebay.com/itm/196038438582 | | This can be omitted or replaced with other types of headers; in _both_ cases the pcb design should be changed
| $1 \times$ | $5.5mm \times 2.1mm$ DC Power Plug | ❌ | https://www.amazon.com/dp/B07Y8M8TWM <br> https://www.ebay.com/itm/114822858070 | | You can chose any plug you want, bear in mind that the plug has to fit through the same $\varnothing 10mm$ hole as the bolt
| $20cm$ | Flexible Power Cable
| $3cm$ | $\varnothing 9-14mm$ Heatshrink | | | | The heatshrink is only needed when removing the cover of your DC plug
| $5ml$ | White (Acrylic) Paint

### Required Tools
 - Screwdriver
   - Bit for your M3 Bolts
   - Bit for your screw terminal (optional)
 - Power Drill
   - 3mm Drill Bit
   - 10mm Drill Bit
 - Paint Brush
 - Soldering Iron + Solder
 - Pair of Pliers (probably)