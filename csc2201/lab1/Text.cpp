
#include "Text.h"

Text::Text ( const char *charSeq )
{
	bufferSize = strlen(charSeq);
	buffer = (char*)malloc(bufferSize + 1);
	strcpy(buffer, charSeq);
}

Text::Text ( const Text &other )
{
}

void Text::operator = ( const Text &other )
{
	if (this != &other){
		this->buffer = other.buffer;
		this->bufferSize = other.bufferSize;
	}
}

Text::~Text ()
{
}

int Text::getLength () const
{
	return bufferSize;
}

char Text::operator [] ( int n ) const
{
	return 0;
}

void Text::clear ()
{
}

void Text::showStructure () const
{
	cout << "buffer: " << buffer << endl;
	cout << endl;
}

Text Text::toUpper( ) const
{
	Text temp;
	return temp;
}

Text Text::toLower( ) const
{
	Text temp;
	return temp;
}

bool Text::operator == ( const Text& other ) const
{
	return false;
}

bool Text::operator <  ( const Text& other ) const
{
	return false;
}

bool Text::operator >  ( const Text& other ) const
{
	return false;
}
