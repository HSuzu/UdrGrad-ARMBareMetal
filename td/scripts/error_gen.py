#!/usr/bin/env python3

import sys, os
import serial
import numpy as np
import argparse
import time

description = """
Generate a frame error periodically. If the yellow led blink, the error occur.
"""

def main():
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument("-f", "--file",
                        help="Set the file to be send.",
                        type=str)
    parser.add_argument("-p", "--port",
                        help="Set the USB port to use for serial communication. Default to /dev/ttyACM0.",
                        type=str,
                        default="/dev/ttyACM0")
    parser.add_argument("-s", "--speed",
                        help="Set serial port speed. Defaults to 38400.",
                        type=int,
                        default=38400)
    args = parser.parse_args()

    f = open(args.file,"rb")

    # Open serial port
    try:
        ser = serial.Serial(args.port, args.speed, writeTimeout = 0	)
    except serial.SerialException as err:
        print(err)
        sys.exit(-1)

    n = 0;

    try:
        c = f.read(100);
        # Send bytes
        while True:
            ser.write(c)

            n = n+1;
            if n >= 100:
				# change port information to force the error
                ser.close();
                ser.parity = serial.PARITY_EVEN;
                ser.bytesize = serial.FIVEBITS;
                ser.baudrate = args.speed*2;
                ser.open();

                # Send bytes 2 bytes in the wrong configuration
                for i in range(2):
                    ser.write(np.random.randint(0, 256, 1))

				# Fix the port configuration
                ser.close();
                ser.parity = serial.PARITY_NONE;
                ser.bytesize = serial.EIGHTBITS;
                ser.baudrate = args.speed;
                ser.open();

                print("Possible framming Error..")
                n = 0;

            c = f.read(100);
    except EOFError:
        pass
    # Close serial port
    ser.close()

if __name__== "__main__":
    main()
