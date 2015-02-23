#!/bin/bash
qemu-system-i386 -m 1024 -s -hda test.img  -curses -serial /dev/tty  -redir tcp:2323::23
