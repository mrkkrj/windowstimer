# windowstimer

Basic simple timer implementation using only native Windows API. Use it on Windows if you don't have/want Qt or Boost in your project.

It can invoke only simple void-void callback functions, thus can be used to e.g. set a global flag and return. It will fire at a given hour and minute or after a given number of seconds. The exact time is given using a string in 24-hour format, e.g. "21:17". 

You can run the timer in a cyclic manner, either to be invoked every N seconds or every day at a given hour.
 
## Implementation
The callback will be run in a separate thread, so take care of synchronization!

Implementation uses C++89 standard for portability. 

There is a Visual Studio 2015 project included providing an usage example which simultaniously serves a test suite.

## Licence
This implementation is released under the MIT licence.

## TODOs
 - Support for general callbacks and lambdas.
 - Add higher resolutions

