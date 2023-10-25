# LCDMEGA
LCD in c for an ATMEGA2560


1. make sure that the AVR toolchain is downloaded avrdude 6.3.2  make sure make is @ GNU Make 4.3 
2. for linux create a plugdev rule for the atmega
3. cd to /etc/udev/rules.d
4. sudo vim 99-usbasp.rules
5. SUBSYSTEM=="usb", ATTR{idVendor}=="0x2341", ATTR{idProduct}=="0x0042", GROUP="dialout", MODE="0666"
6. cd ~/LCDMEGA/
7. $ make
8. $ make install.main
 
