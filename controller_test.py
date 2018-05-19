#!/usr/bin/env python2
import serial,curses

ser = serial.Serial('/dev/ttyACM6',115200,timeout=1)

def main(stdscr):
    while True:
        c = stdscr.getkey()
        print(c)
        ser.write(c)

curses.wrapper(main)

