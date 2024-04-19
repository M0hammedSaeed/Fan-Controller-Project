# Fan Controller System 
## Specifications
1. The aim of this project is to design a temperature-controlled fan using ATmega32
   microcontroller, in which the fan is automatically turned ON or OFF according to the
   temperature. Used ATmega32 Microcontroller with frequency 1Mhz.
2. In this project, the LM35 temperature sensor will give continuous analog output
   corresponding to the temperature sensed by it. This analog signal is given to the ADC,
   which converts the analog values to digital values.
3. The digital output of the ADC is equivalent to sensed analog voltage.
4. In order to get the temperature from the sensed analog voltage, we need to perform some
   calculations in the programming for the microcontroller.
5. Once the calculations are done by the microcontroller according to the logic, the
   temperature is displayed on the LCD.
6. The microcontroller will continuously monitor the temperature and based on the
   temperature value, the microcontroller will drive the fan like that:
   * If the temperature is less than 30C turn off the fan.
   * If the temperature is greater than or equal 30C turn on the fan with 25% of its
      maximum speed.
   * If the temperature is greater than or equal 60C turn on the fan with 50% of its
      maximum speed.
   * If the temperature is greater than or equal 90C turn on the fan with 75% of its
      maximum speed.
   * If the temperature is greater than or equal 120C turn on the fan with 100% of its
      maximum speed.
8. The main principle of the circuit is to switch on/off the fan connected to DC motor based
   on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on
   the fan state.
9. Control the DC-Motor speed using PWM signal generated from Timer0.
10. The project should be design and implemented based on the layered architecture

## Project Simulation    
![Project Simulation](https://github.com/M0hammedSaeed/Fan-Controller-Project/assets/114070625/5aca08ad-9ef0-448f-906c-a36a5b5354af)

## Project Design 
![Project Design](https://github.com/M0hammedSaeed/Fan-Controller-Project/assets/114070625/31b2b288-55f6-4b2b-a84f-bf1d1a316707)

