#!/bin/bash
nome="hd.sh"
dir="/home/jimmy"

rm $nome        
dd if=/dev/zero of=$nome bs=512 count=4000

fdisk $nome  << EOF
x
c
4
h
16
s
63
r
n
p
1
1
3999
a
1
w
EOF

losetup /dev/loop1 $nome
losetup -o 512 /dev/loop2 /dev/loop1

mke2fs /dev/loop2
mount  /dev/loop2 /mnt/
cp -R bootdisk/* /mnt/
umount /mnt/

grub --device-map=/dev/null << EOF
device (hd0) ./c.img
geometry (hd0) 4 16 63
root (hd0,0)
setup (hd0)
quit
EOF

losetup -d /dev/loop2
losetup -d /dev/loop1