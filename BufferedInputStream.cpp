/*
 	BufferedStream
 	Philippe Rochat, 2017, Philippe.Rochat'at'gmail.com
*/

#include "BufferedInputStream.h"

BufferedInputStream::BufferedInputStream(uint8_t *buffer, const uint16_t size) {
  this->size = size;
  this->buffer = buffer;
  pos = 0;
  buffer_overflow = (size > 0 ? true: false);
}

int BufferedInputStream::read() {
 	if (pos >= size) {
    	buffer_overflow = true;
    	return -1;
  	}	
	return buffer[pos++];
}

size_t BufferedInputStream::readBytes(char * buf, size_t length) {
	int i;
	
	for(i=0; i<length && pos<size; i++, pos++) {
		buf[i] = buffer[pos];
	}
	if(pos>=size) buffer_overflow = true;

	return i-1;
}

size_t BufferedInputStream::readBytesUntil( char terminator, char *buffer, size_t length) {
	int i;
	
	for(i=0; i<length && pos<size; i++, pos++) {
		buf[i] = buffer[pos];
		if(buf[i] == terminator) {
			i++; pos++;
			break;
		}
	}
	if(pos>=size) buffer_overflow = true;

	return i-1;	
}

String BufferedInputStream::readString() {
	strl = strlen(&buffer[pos]);
	if(pos+strl>size) {
		return (String)"";
	}
	pos+=strlen+1;
	if(pos>=size) buffer_overflow = true;
	return (String)&buffer[pos];
}



