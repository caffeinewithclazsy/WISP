# WISP

Wireless Intelligence & Signal Probe

Project Overview

WISP is a portable WiFi scanning and monitoring device built using an ESP32, rechargeable battery setup, and physical power switch.

The project transforms the ESP32 into a standalone wireless scanning system that hosts a live cyber-style web dashboard for monitoring nearby WiFi networks in real time.

The device scans surrounding networks and displays:

* WiFi names (SSID)
* Signal strength (RSSI)
* Channel information
* Open/Secured status
* Channel traffic analysis
* ESP32 system information

The system is fully portable and operates wirelessly using battery power, making it a compact handheld network analysis tool.

⸻

Project Objective

The main goal of WISP was to create a lightweight and portable WiFi analyzer capable of:

* Scanning nearby wireless networks
* Visualizing network strength
* Monitoring WiFi channels
* Hosting a responsive dashboard directly from the ESP32
* Operating independently using portable battery power

⸻

Features

* Portable battery-powered design
* Dedicated ON/OFF switch
* ESP32 Access Point mode
* Real-time WiFi scanning
* Live web dashboard
* Signal strength indicator bars
* Open/Secured network detection
* Channel analyzer
* Cyberpunk-inspired UI
* Auto-refreshing webpage
* Lightweight embedded web server

⸻

Hardware Components

* ESP32 Development Board
* Rechargeable Battery Module
* Power Switch
* USB Cable
* Jumper Wires

⸻

Software & Technologies Used

* Arduino IDE
* Embedded C++
* HTML/CSS
* ESP32 WiFi Library
* WebServer Library

⸻

Working Principle

1. The ESP32 starts in WiFi Access Point mode.
2. A local web server is initialized.
3. The ESP32 scans nearby WiFi networks using WiFi.scanNetworks().
4. Network information is stored dynamically.
5. A live dashboard webpage is generated and hosted by the ESP32.
6. Users connect to the WISP hotspot and access the dashboard through a browser.
7. The webpage refreshes automatically to provide updated network information.

⸻

Dashboard Information

The WISP dashboard displays:

* Device IP Address
* System Uptime
* Free RAM
* Number of detected networks
* Signal quality visualization
* Channel distribution analysis
* Security status of nearby networks

⸻

UI Design

The dashboard uses a cyber-inspired interface with:

* Neon green styling
* Animated radar effect
* Responsive mobile-friendly layout
* Live signal bars
* Dark-themed futuristic design

⸻

Portable Design

WISP was designed as a portable standalone device using:

* Rechargeable battery power
* Dedicated hardware switch for power control
* Wireless dashboard access
* Compact ESP32-based architecture

This allows the system to operate without requiring a continuous USB connection.

⸻

Learning Outcomes

Through this project, I explored:

* ESP32 networking
* Embedded web servers
* WiFi scanning techniques
* Real-time data visualization
* HTML generation using microcontrollers
* Portable embedded system design
* IoT dashboard development

⸻

Future Improvements

Planned upgrades for WISP include:

* OLED display integration
* GPS-based network mapping
* SD card data logging
* Advanced signal graphs
* Packet monitoring
* Mobile application support
* Historical network storage

⸻

Conclusion

WISP demonstrates how an ESP32 can be transformed into a portable wireless monitoring tool with real-time network analysis and an interactive web interface.

The project combines embedded systems, networking, IoT, and frontend dashboard design into a compact portable cybersecurity-style device.
