These are the steps to ensure you can get s3fs up and running properly

1. please ensure that you have an AWS account set up as well as a bucket so that you can user s3fs.

2. ensure you have the required dependencies by running the command below

sudo apt-get install automake autotools-dev g++ git libcurl4-gnutls-dev libfuse-dev libssl-dev lib-xml2-dev make pkg-config

3. go to your home directory and create a new folder where you will be mounting s3fs

4. within your home directory set up 2 password files, one for your bucket and one for your encryption password. the format for your bucket credentials should be ID:CREDENTIAL within the first line of the file, and the encryptionn password should too be within the first line of the file of its appropriate location.
You should now have 2 passwords files, one with your amazon credentials and the other with your encryption password.

Ensure you have the proper permissions set by using chmod 600 on both of those password files.

5. go within the s3fs-fuse directory and type in the following commands, note that you might have to wait some time in between typing these commands.

./autogen.sh
./configure
make

6. Once you have done edit either s3script.sh or s3securescript.sh to see examples of how s3fs should be called

you can set up your own script with the following lines:
fusermount -u ~/yourmountpath
PATH=$PATH:/locationofs3fs/s3fs-fuse/src
which s3fs

now from here you can determine if you want this specific script to either encfrypt or not. If you want it to NOT encrypt then type the folliwng:
s3fs yourbucket /fullpathtomount/ -o passwd_file=/fullPathToAWSpasswordFile/ -o umask=0000 -o encrypt_passfile=/fullPathToEncryptionPasswordFile/

if you do not want to use the encryption password file then replace the encrypt_passfile= argument with -o encrypt_password= below is an example of its use:
-o encrypt_password=ThisIsMyPassword

If you DONT want to encrypt then do not include -o encrypt_password= OR -o encrypt_passfile=

7. You should now have successfully downloaded and set up s3fs-fuse with encryption!

The TESTING folder is a folder of pictures to test with and some compiled standalone code. The standalone folder has my standalone with it.
