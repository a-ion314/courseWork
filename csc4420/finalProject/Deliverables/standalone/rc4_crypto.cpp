#include<string>
#include"md5.h"
#include<iostream>
#include<unistd.h>
#include<fstream>
#include"rc4_skey.c"
#include"rc4_enc.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

int crypto_md5_rc4(int fd, std::string passphrase);

int main(int argc, char* argv[]){
	std::string passphrase = "Thisisjustatest";
	int filedesc = open(argv[1], O_RDWR);
	crypto_md5_rc4(filedesc, passphrase);
	return 0;
}

int crypto_md5_rc4(int fd, std::string passphrase){
	//-----FileInput-----//
	int fileLength = lseek(fd, 0, SEEK_END);
	unsigned char *fileContents;
	fileContents = (unsigned char *) calloc(fileLength, sizeof(char));
	ssize_t outnum;
	outnum = pread(fd, fileContents, fileLength, 0);
	//-----FileInput-----//

	//-----MD5-----//
	unsigned char digest[MD5_DIGEST_LENGTH];//digest contains the hex values outputted by the MD5 hash
	char input[sizeof(passphrase)];//passphrase is given to a char array
	strcpy(input,passphrase.c_str());
	MD5((unsigned char*)&input, strlen(input), (unsigned char*)&digest);//md5 hash function
	//-----MD5-----//
	/*
	openssl uses an input passphrase and hashes it into a 128-bit hash (MD5 by defualt)
	and uses that hash for the key to encrypt files. You can see the true key by adding the
	-p option when using openssl to encrypt or decrypt. MD5 outputs into a digest
	of size 16 bytes. 4 bits for every hex character, 16 bytes total for 32 Hex values.
	The size of the output given by MD5 is FIXED regardless of the size of the passphrase.
	*/


	char mdoutputstring[33];
	for (int i = 0; i < 16; i++){
	sprintf(&mdoutputstring[i*2], "%02X", (unsigned int)digest[i]);
	}
	printf("Key=%s\n", mdoutputstring);	//output string to check the MD5 hash is correct


	//cast fileContents to string for easier handling in function
	std::string fileContentstoFunc(reinterpret_cast<char const*>(fileContents), fileLength);

	RC4_KEY key;
	int length = fileContentstoFunc.length();
	unsigned char *buf = (unsigned char*)malloc(length-1);
	memset(buf, 0, length-1);
	RC4_set_key(&key, sizeof(digest) ,(const unsigned char*)digest);
	RC4(&key, length, (const unsigned char*)fileContentstoFunc.c_str(), buf);
	string result((char*)buf, length);
	free(buf);
	free(fileContents);
	//-----FileOutput-----//
	const char *outputbuf = result.c_str();
	outnum = pwrite(fd, outputbuf, result.length(), 0);
	ftruncate(fd, result.length());
	//-----FileOutput-----//

	return 0;
}

//Note: using the EVP functions is a total pain because they
//are meant to be used with padding enabled so as to not leave out or add
//extra characters in the encrypted text
