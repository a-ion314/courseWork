#!/bin/bash

fusermount -u ~/s3mount

PATH=$PATH:/home/adrian/Desktop/CSC4420Project/s3fs-fuse/src

which s3fs

#examples below

# -o encrypt_passfile= -o encrypt_password=
#s3fs projectdarkmatter /home/adrian/s3mount/ -o passwd_file=/home/adrian/passwd.passwd-s3fs -o umask=0000 -o encrypt_password=Thisisjustatest

#s3fs projectdarkmatter /home/adrian/s3mount/ -o passwd_file=/home/adrian/passwd.passwd-s3fs -o umask=0000 -o encrypt_passfile=/home/adrian/crypto.passwd

