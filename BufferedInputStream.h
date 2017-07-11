/*
 	BufferedStream
 	Philippe Rochat, 2017, Philippe.Rochat'at'gmail.com
*/

#ifndef BufferedInputStream_h
#define BufferedInputStream_h

#include <inttypes.h>
#include <Stream.h>

class BufferedInputStream : public Stream
{
private:
  uint8_t *buffer;      // Data buffer
  uint16_t size;        // Sizeof Data Buffer
  uint16_t pos;         // Position where to read next data
  bool buffer_overflow; 

public:
  // public methods
  /// Instanciate a BufferedOutputStream with an already existing buffer (allocated)
  BufferedInputStream(uint8_t *buffer, const uint16_t size);
  virtual ~BufferedInputStream() {};

  operator const uint8_t *() const { return buffer; }
  operator const char *() const { return (const char*)buffer; }

  const uint16_t current_length() const { return pos; }

  // FAKE - Stream is in memory
  void begin(long speed) {}
  bool listen() { return true; }
  void end() { buffer = NULL; size=0; pos=0;}
  bool isListening() { return true; }
  virtual size_t write(uint8_t byte) { return -1; }
  virtual void flush() {pos=0;}; // Clear buffer (reset to 0)
  // FAKE

  virtual int available() { return size-pos; }
  bool overflow() { bool ret = buffer_overflow; buffer_overflow = false; return ret; }  int peek() { return buffer[pos]; }
  virtual int read();
  virtual size_t readBytes(char * buf, size_t length);
  virtual size_t readBytes( uint8_t *buffer, size_t length) { return readBytes((char *)buffer, length); }
  size_t readBytesUntil( char terminator, char *buffer, size_t length); // as readBytes with terminator character
  size_t readBytesUntil( char terminator, uint8_t *buffer, size_t length) { return readBytesUntil(terminator, (char *)buffer, length); }
  String readString();
  // NOT IMPLEMENTED String readStringUntil(char terminator);
  // NOT IMPLEMENTED long parseInt(LookaheadMode lookahead = SKIP_ALL, char ignore = NO_IGNORE_CHAR);
  // NOT IMPLEMENTED float parseFloat(LookaheadMode lookahead = SKIP_ALL, char ignore = NO_IGNORE_CHAR);
  // The 2 above would need a redefinition of timedPeek and timedRead ... 
  using Print::write;
};

#endif
