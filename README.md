# BufferedStream
A buffered stream for Arduino. Provide a way to use a buffer to mimic a Serial.
I made those to two classes to use msgpack, and to store packed messages into a Buffer (that could next send over radio for example)

BufferedOutputStream
====================

Provides an encapsulation for a buffer you can then stream into. This can be used as a Serial to print to, and result goes into a buffer.

BufferedInputStream
===================

Provides an encapsulation for a buffer you can then stream from. This can be used as a Serial to read from a buffer.
