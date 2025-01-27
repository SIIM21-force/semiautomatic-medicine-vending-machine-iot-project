**********Self-Assistive Semi-Automatic Medcine Vending Machine using IoT**********
BY MY TEAM MEMBERS:
	JINITH M
	MAHESH P
	SAMARTH M KATAGERI
	DASHRATH RAO

This project proposes a Semi-Automated Medicine Vending Machine (SMVM) to address the critical issue of 24/7 medicine accessibility,
particularly in remote and underserved areas. Inspired by the convenience of ATMs, the SMVM utilizes fingerprint scanner technology
for secure and personalized access to essential medications.

This innovative solution aims to reduce healthcare disparities, improve patient outcomes, and enhance overall healthcare accessibility.

**********PROBLEM STATEMENT**********

1. Limited Access to Medications: Many individuals, especially in remote areas, face challenges in accessing essential medications,
   particularly during emergencies or late-night hours.
2. Inefficient Pharmacy Operations: Traditional pharmacies often experience long queues, stockouts, and inefficient management,
   leading to delays in dispensing medications.
3. Need for 24/7 Healthcare Solutions: A reliable and accessible system is required to provide round-the-clock access to medications,
   reducing the burden on healthcare providers and improving patient care.

**********HOW TO MAKE THIS PROJECT**********

A. HARDWARE REQUIREMENTS:

1.  Any Arduino that meets your needs, for example Arduino UNO (my team used Arduino MEGA for just some praise).
2.  2 voltage regulators (one with 5V and another with 12V) with adaptors.
3.  Vending Machine Assembly, includes servomotors.
4.  Multi-channel Relay (depending on how much servomotors you need in Vending Machine Assembly).
5.  NodeMCU ESP8266 WiFi module.
6.  aPR33A3 V2 audio assistant module with Mono Speaker.
7.  Single channel relay with coolant for Vending Machine Assembly (in case in the source code, Fan).
8.  Adafruit Optical Fingerprint Sensor.
9.  Any temperature sensor (in case in the source code, Dallas Temperature sensor: DS18B20).
10. FSR sensor.

For additional details about all these parts, see report (either in .docx or in .pdf file).

B. SOFTWARE REQUIREMENTS:

1. Arduino IDE for dumping code in any Arduino board, as well as fingerprint register serial monitoring.
2. Adafruit IO platform for constant monitoring of Vending Machine assembly activity and user activity.

(EXCUSE MY TEAM FOR POOR EXPLANATION OF THE PROJECT)
(YOU HAVE BEEN WARNED: NO CONNECTION DIAGRAM HAS BEEN ADDED IN THIS PROJECT IN ALL OF THE DOCUMENTS WE UPLOADED)

ARDUINO IDE IS A MUST FOR THESE SOURCE CODE TO COMPILE, UPLOAD INTO BOARD AND RUN AS IT IS.

SET A USERNAME AND PASSWORD FOR NODEMCU AND USE ANY PHONE AS HOTSPOT FOR SEAMLESS CONNECTION WHILE USING THE ASSEMBLY, IN A SOURCE CODE WE ADD.

1. Download the source code and open using Arduino IDE.
2. For fingerprint registration: upload Enroll_finger.ino into board and follow the procedure in .pptx file.
3. For use of Vending Machine: upload finalfpservo.ino into board and do the same as in step 2.
4. For NodeMCU configuration: upload nodemcu_security.ino into ESP8266 board and configure it.

**********THANK YOU FOR THE SUPPORT BY USING THIS PROJECT**********
**********MAKE ANY CHANGES AS YOU WISH, THE SOURCE CODE IS ALL YOURS**********