/*
 	BufferedStream
 	Philippe Rochat, 2017, Philippe.Rochat'at'gmail.com
*/

#ifndef BufferedOutputStream_h
#define BufferedOutputStream_h

#include <inttypes.h>
#include <Stream.h>

class BufferedOutputStream : public Stream
{
private:
	uint8_t *buffer;      // Data buffer
  uint16_t size;        // Sizeof Data Buffer
  uint16_t pos;         // Position where to write next data
  bool buffer_overflow; 
	bool _self_alloc;

public:
  // public methods
  /// Instanciate a BufferedOutputStream with an already existing buffer (allocated)
  BufferedOutputStream(uint8_t *buffer, const uint16_t size);
  BufferedOutputStream(const uint16_t size); // With self allocation
  virtual ~BufferedOutputStream();

  operator const uint8_t *() const { return buffer; }
  operator const char *() const { return (const char*)buffer; }

  const uint16_t current_length() const { return pos; }

  // FAKE: all input functions are faked
  void begin(long speed) {}
  bool listen() { return true; }
  void end() {}
  bool isListening() { return true; }
  int peek() { return -1; }
  virtual int read() { return -1; }
  virtual int available() { return -1; }
  // FAKE
  
  bool overflow() { bool ret = buffer_overflow; buffer_overflow = false; return ret; } 
  virtual size_t write(uint8_t byte);
  virtual void flush(); // Clear buffer (reset to 0)
  
  using Print::write;
};

#endif
