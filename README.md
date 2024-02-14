# WIP

**This library is a work in progress and might not (probably won't) work until the first release!**

# FocalTech Touch IC library
![Compile](https://github.com/DustinWatts/FocalTech_Touch/actions/workflows/compile.yml/badge.svg)
![Compile](https://github.com/DustinWatts/FocalTech_Touch/actions/workflows/compile-arduino.yml/badge.svg)
![Latest commit](https://img.shields.io/github/last-commit/DustinWatts/FocalTech_Touch)
[![](https://badgen.net/github/release/DustinWatts/FocalTech_Touch)](https://github.com/DustinWatts/FocalTech_Touch/releases)

Library for the FocalTech touch controllers. At the moment the following IC's are supported:

- FT6236 (ChipID 0x36)
- FT6206 (ChipID 0x06)
- FT6236U (ChipID 0x64)
- FT5436 (ChipID 0x54)
- FT6234 (ChipID 0x54)

And there are more to come!

_Although this library supports the Arduino boards, the maximum VCC voltage and on the data pins is 3.3V. So if you plan to use this with an Arduino, be sure to not exceed 3.3V! (use an Arduino board that runs on 3.3V or levelshifters and a voltage regulator)_

# Usage

First, include the library in your sketch:

`#include <FocalTech.h>`

Next, create the object to be used (I use "ts" here, but you can use whatever you like):

`FocalTech ts = FocalTech();`

Next, in the setup() use begin to start the touch controller:

`ts.begin(40)`

_40 sets the threshold for touch detection, aka how sensitive the touchscreen is. 40 seems to be a good number. This can be an integer from 0 to 255._

If your I2C pins are not the board's default pins or you are using custom pins for I2C you can also specify the I2C pins to be used. You start by supplying the threshold and then the I2C data pin followd by the I2C clock pin:

`ts.begin(40, SDA_pin, SCL_pin)`

Lastly, in the loop you can check for touches. If there is a touch detected, `touched()` will return _true_ and you can go and get the X and Y coordinates using `getPoint()`. In the loop it will look something like this:

```
void loop(void)
{

    if (ts.touched())
    {
        // Retrieve a point
        TS_Point p = ts.getPoint();

        // Print coordinates to the serial output
        Serial.print("X Coordinate: ");
        Serial.println(p.x);
        Serial.print("Y Coordinate: ");
        Serial.println(p.y);
    }

    //Debouncing. To avoid returning the same touch multiple times you can play with this delay.
    delay(50);
}
```

At the and of a short loop a delay is needed to give the controller some time to clear it's registers and be ready for a next touch. If you have a short loop and don't add this delay, you run the risk of a touch being picked up multiple times where it was meant to be just a single touch.

# Datasheet
Datasheets for the supported IC's can be found here:

FT62x6: http://dustinwatts.nl/docs/FT6236-FocalTechSystems.pdf
FT5436: https://focuslcds.com/wp-content/uploads/Drivers/FT5436.pdf

## Support Me

If you like what I am doing, there are a number of ways you can support me. 

| Platform | Link|
|:-----:|:-----|
| [<img src="https://github.com/DustinWatts/small_logos/blob/main/twitter_logo.png" alt="Twtter" width="24"/>](https://twitter.com/dustinwattsnl "Follow me on Twitter") | You can follow me on Twitter: [@dustinwattsnl](https://twitter.com/dustinwattsnl "Follow me on Twitter")|
| [<img src="https://github.com/DustinWatts/small_logos/blob/main/youtube_logo.png" alt="YouTube" width="32"/>](https://www.youtube.com/dustinwatts "Subscrive to my YouTube channel") | You can subscribe to my channel on Youtube: [/dustinWatts](https://www.youtube.com/dustinwatts "Subscribe to my YouTube channel") |
| [<img src="https://github.com/DustinWatts/small_logos/blob/main/patreon_logo.png" alt="Patreon" width="32"/>](https://www.patreon.com/dustinwatts) | You can support me by becoming a patron on Patreon: https://www.patreon.com/dustinwatts |
| [<img src="https://github.com/DustinWatts/small_logos/blob/main/paypalme_logo.png" alt="PayPal.me" width="32"/>](https://www.paypal.me/dustinwattsnl) | You can make a one time donation using PayPal.me: https://www.paypal.me/dustinwattsnl |

## Get help

For quick access to help you can join my Discord server where I have a dedicated #freetouchdeck channel. https://discord.gg/RE3XevS
