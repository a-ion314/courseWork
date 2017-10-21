#!/bin/bash

fusermount -u ~/s3mount

PATH=$PATH:/home/adrian/Desktop/CSC4420Project/s3fs-fuse/src

which s3fs

#new commands below
# -o encrypt_passfile= -o encrypt_password=

#example
#s3fs projectdarkmatter /home/adrian/s3mount/ -o passwd_file=/home/adrian/passwd.passwd-s3fs -o umask=0000


