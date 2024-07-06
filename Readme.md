# Greenhouse Control System for Indoor Farming

## Authors
Muhammad Huzaifa  
School of Electrical Engineering and Computer Sciences, SEECS  
National University of Sciences and Technology, NUST  
Islamabad, Pakistan  
Email: mhuzaifa.bee21seecs@seecs.edu.pk

Wajiha Ali  
School of Electrical Engineering and Computer Sciences, SEECS  
National University of Sciences and Technology, NUST  
Islamabad, Pakistan  
Email: wali.bee21seecs@seecs.edu.pk


## Introduction
Traditional greenhouse systems often rely on manual adjustments or rudimentary automated controls that may not respond adequately to dynamic environmental changes. Advanced greenhouse control systems, integrating sophisticated sensing and control algorithms, present a promising solution to enhance the precision and responsiveness of environmental management within greenhouses.

## Literature Review
Recent advancements in greenhouse control systems have emphasized the integration of sensor technologies with automated control algorithms to achieve precise environmental management. Temperature sensors such as the DHT11 interface seamlessly with microcontroller platforms like Arduino, allowing for real-time monitoring of temperature and humidity levels within the greenhouse environment. Arduino-based control systems offer flexibility and scalability, making them ideal platforms for implementing advanced control algorithms such as the PID controller.

## Methodology
### Hardware and Sensor Setup
The greenhouse control system hardware comprises an Arduino microcontroller, a DHT11 sensor for temperature and humidity sensing, and a motor driver for fan speed control. The DHT11 sensor is connected to pin 2 of the Arduino board for data acquisition. It provides real-time temperature and humidity readings crucial for regulating the greenhouse environment. The motor driver interfaces with the Arduino to adjust fan speed based on temperature variations.

### Software Development
The software development process involves coding the Arduino to implement the control logic for the greenhouse system. The code structure encompasses initialization, sensor data acquisition, PID control algorithm implementation, and fan speed control logic. Sensor data acquisition involves continuously reading temperature and humidity values from the DHT11 sensor. These readings serve as inputs to the PID control algorithm, which calculates the necessary adjustments to maintain the desired temperature setpoint. Fan speed control logic determines the appropriate fan speed based on temperature error.

### Experimental Setup and Validation
The Arduino code is integrated into the experimental setup to validate the greenhouse control system's performance under various environmental conditions. Validation experiments involve simulating temperature fluctuations and observing the system's response in maintaining the desired temperature setpoint. Key performance metrics such as temperature stability, response time, and energy efficiency are evaluated to determine the effectiveness of the control system.

## PID Controller Design
The PID controller operates based on proportional, integral, and derivative terms, each contributing to the controller's output signal. In the greenhouse control system, the PID controller is implemented using an Arduino microcontroller, which continuously monitors temperature readings from the DHT11 sensor. The PID algorithm computes proportional, integral, and derivative terms based on the error signal and predefined controller gains (Kp, Ki, Kd). These terms are then combined to generate the control output, which determines the fan speed necessary to regulate the greenhouse temperature effectively. Tuning the PID controller is crucial to ensuring optimal performance and stability, achieved through iterative adjustment of controller gains and empirical testing.

## Results and Discussions
### Temperature Regulation
The greenhouse control system demonstrated commendable efficacy in maintaining the desired temperature setpoint, with minimal deviations observed. Rapid response to temperature fluctuations and minimal steady-state error highlight the PID controller's ability to achieve and maintain stable greenhouse conditions.

### System Performance Evaluation
Evaluation of the greenhouse control system's performance under various environmental conditions revealed robustness, reliability, and adaptability to dynamic changes. The system effectively adjusted fan speed to ensure optimal temperature levels, contributing to energy efficiency and operational cost savings.

### Energy Efficiency Assessment
Energy efficiency analysis indicated optimized fan speed control and reduced overall energy consumption, enhancing sustainability and economic viability for indoor farming operations.

### Plant Growth Parameters
Observations regarding plant growth parameters underscored the system's positive impact on vegetation, including enhanced growth characteristics and optimized crop yields.

## Conclusion
The implementation of the greenhouse control system represents a significant advancement in agricultural technology, offering precise temperature regulation and resource-efficient management practices. The system's effectiveness in maintaining optimal growing conditions demonstrates its potential for enhancing crop productivity and promoting sustainable agricultural practices.


