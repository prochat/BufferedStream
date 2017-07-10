/*
 	BufferedStream
 	Philippe Rochat, 2017, Philippe.Rochat'at'gmail.com
*/

#include "BufferedOutputStream.h"

BufferedOutputStream::BufferedOutputStream(uint8_t *buffer, const uint16_t size) {
  this->size = size;
	this->buffer = buffer;
  memset(this->buffer, 0, this->size);
	pos = 0;
	buffer_overflow = (size > 0 ? true: false);
	_self_alloc = false;
}

BufferedOutputStream::BufferedOutputStream(const uint16_t size) {
	if(size > 0) {
    this->size=size;
		this->buffer = (uint8_t*) calloc(this->size, sizeof(uint8_t));
		pos = 0;
		buffer_overflow = false;
    _self_alloc = true;
	} else {
		this->buffer = NULL;
		this->size = 0;
		pos = 0;
		buffer_overflow = true;
	}
}

BufferedOutputStream::~BufferedOutputStream() {
  if(_self_alloc) free(buffer);
}

size_t BufferedOutputStream::write(uint8_t d) {
  	if (pos >= size) {
    	buffer_overflow = true;
    	return 0;
  	}
  	buffer[pos] = d;
  	++pos;
  	return 1;
}

void BufferedOutputStream::flush() {
  	memset(buffer, 0, size);
  	pos = 0;
}
