# 24130 - 7 SEGMENT EL WIRE DISPLAY WITH ARDUINO NANO
---
## Description
This project is designed to help you build your own completely customized 7-segment display using EL Wires! The great thing about this project is it is completely tried and tested, and comes with a well-commented code to support you.

Following video shows the completed project in action!

![1][]

You can create 7-segment displays of any size you like without breaking the bank. Furthermore, you can create novel segment shapes and do not have to stick to the monochrome 7-segment displays that are available. Sky is the limit when it comes to personalizing your 7-segment displays by following the techniques described in this project! This project is fun!

## Operation
This application simply counts up from 0 to 9 periodically and runs in an infinite loop. This code has been tested on Arduino Nano and works as expected. Of course, you can use my code as your base to build on to create more interesting applications. What I provide is only a starting point of inspiration to help you get up to speed fast to express your creativity!

If the 7 segment display you are driving is common anode, you can use this code without any change. If you are using a common cathode 7-segment display, simply comment out the following definition:

`#define COMMON_ANODE_DISPLAY`

Be sure to connect your Arduino Nano to the respective digital pins as per definitions provided. You can change the recommended pins as you wish, of course.

## EL Wire 7-Segment Circuit Diagram

The first thing to note before diving into the circuit diagram is we will need to create a simple optocoupler using a light dependent resistor (LDR) and an ordinary LED (preferably one with white light) Following is a schematic diagram of this optocoupler.

![2][]

While building the optocoupler, be sure to keep the LDR and the LED face to face and cover them both to isolate from ambient light. I used shrink fit tubes to place them face to face, which achieved this objective. You can also paint the shrink fit black to improve the ambient light immunity of the optocoupler, which will help improve the performance of your circuit.

You will need one optocoupler for each segment of the 7-segment display. Each optocoupler will drive one EL Wire segment, which is about 10 cm in length as in our demo video above. Of course, you may choose to use longer or shorter EL Wires for each segment as you wish. Following circuit shows how the demo in the above video was wired. The 7-segment display reference used has also been included to help you make better sense of the circuit diagram.

![3][]

In the circuit above OC x shows the home made optocoupler and as you can see we are using 7 of them in this project. If you would like to implement more than one 7-segment EL Wire display, you will need to build more than 7 optocouplers.

The reason why using LDRs in series with each EL wire works is, when LDR is exposed to intense light it has a low resistance of about 70 Ohms, which is enough to supply the required current for the EL wire to glow. When there is no light, the LDR resistance exceeds 2 megaOhms. The EL wire controller also outputs low current (though it delivers AC voltage of around 200 Volts!) Because it delivers low current, it is safe to work with (though you may feel a gentle shock if you touch the output of the controller directly) The low current output of the EL wire controller also means the LDRs will not overheat after long periods of operation. 

The EL Wire controller indicated in the circuit diagram is an off-the-shelf component that comes with any EL wire controller you will purchase. An EL Wire controller looks as shown below. It operates with 2xAA batteries and has a two terminal output which needs to be connected to an EL wire. There is also a mode button which is used to toggle between the following 4 modes:
1. Turn controller off
2. Turn controller on in constant current mode
3. Blink EL wire fast
4. Blink EL wire faster

![4][]

In our project, we operate the EL Wire controller in the second mode all the time, and control the EL Wire on/off states using the Arduino Nano.

## Useful tips
1. Be sure to connect a 1K resistor externally to each digit pin of your 7-segment display to maintain a fixed light intensity.
2. This driver software will also work with optocouplers (assuming the resistors mentioned above are connected to each optocoupler!)
3. You can also experiment with different values for the `#define DIGIT_LATENCY_MS` and `#define OFF_DELAY_MS` values to change the speed of counting.

I hope you will find this project compelling and engaging. Enjoy!

*GOOD LUCK & ENJOY EXPERIMENTING WITH THIS CUSTOM EL WIRE 7-SEGMENT DISPLAY !*

---
*Follow my channel on **[YouTube][5]**, **[TikTok][6]** and **[Instagram][7]** for hundreds of engaging build video tutorials:*

---

***circuitapps* - October 2024**

[1]: ./24130_EL_Wire_7-segment_Display_ANIMATED_GIF_PROJECT_29102024.gif
[2]: ./homemade_optocoupler.png
[3]: ./Seven_segment_EL_Wire_circuit.png
[4]: ./EL_wire_controller.png
[5]: https://www.youtube.com/@circuitapps
[6]: https://www.tiktok.com/@circuitappschannel
[7]: https://www.instagram.com/youtubecircuitapps


