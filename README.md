# RGB_LED_Control_with_Display

I have created a program that first counts from 0 to 9 on a 7-segment display that uses a shift register and then the active buzzer makes a sound signalling the user to enter values for an RGB LED via the serial monitor using USART. The user will be prompted to enter valid values for R, G, and B color by typing them in the console and separating them with a space. The program will show the numeric values on an LCD using two lines of display. The first line will display "Current Values:" and the second line will display "Rx Gx Bx" where x refers to the values between 0 to 255 for R, G, and B. To generate PWM, the program uses Timer0 channel A&B and Timer2 Channel B.
The program then prompts the user to enter change values for R, G, and B color using the same method as before. The program parses the received string input and generates numeric values for the change in red, green, and blue. If the user pushes the button, the RGB values are updated, and the new values are used to generate PWM and generate the colors on the RGB LED. In addition, the message on the LCD should reflect the updated values for RGB. I added error checking to detect if the user enters a wrong amount of RGB values.

<img width="807" alt="Screenshot 2024-05-06 at 11 15 51 PM" src="https://github.com/Oreoluwa-hbo/RGB_LED_Control_with_Display/assets/97203137/8211c84a-cde6-419a-9132-bd1847db61e7">
