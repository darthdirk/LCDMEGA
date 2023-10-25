# LCDMEGA
LCD in c for an ATMEGA2560


1. make sure that the AVR toolchain is downloaded avrdude 6.3.2  make sure make is @ GNU Make 4.3 
2. for linux create a plugdev rule for the atmega
2.1. cd to /etc/udev/rules.d
2.2. sudo vim 99-usbasp.rules
2.3. SUBSYSTEM=="usb", ATTR{idVendor}=="0x2341", ATTR{idProduct}=="0x0042", GROUP="dialout", MODE="0666"
2.4. cd ~/LCDMEGA/
2.5. $ make
2.6. $ make install.main
 
