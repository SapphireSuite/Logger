# Logger

[![Unix](https://github.com/SapphireSuite/Logger/actions/workflows/test_unix.yml/badge.svg)](https://github.com/SapphireSuite/Logger/actions/workflows/test_unix.yml)
[![Windows](https://github.com/SapphireSuite/Logger/actions/workflows/test_windows.yml/badge.svg)](https://github.com/SapphireSuite/Logger/actions/workflows/test_windows.yml)
[![MacOS](https://github.com/SapphireSuite/Logger/actions/workflows/test_macos.yml/badge.svg)](https://github.com/SapphireSuite/Logger/actions/workflows/test_macos.yml)

Sapphire Suite's C++ Logger.\
Links to the **official** [documentation](https://SapphireSuite.github.io/Logger/) and [wiki](https://github.com/SapphireSuite/Logger/wiki) for advanced details.



# Quick Use

### Collection Header
```cpp
#include <SA/Collections/Debug>
```


## CMake
Add the subdirectory to the build tree and link the library to your taget:
```cmake
add_subdirectory(Logger)
target_link_libraries(<target> <link> SA_Logger)
```


## Quick Init
Create the Logger variable and register it to the static instance:
```cpp
Logger myLogger;

// Register logger to static instance.
Sa::Debug::logger = &myLogger;
```
Add _LogStream_ output to the logger:
```cpp
// Output to console.
ConsoleLogStream cslStream;
logger.Register(cslStream);

// Output to file (default Log/Log.txt).
FileLogStream fileStream;
logger.Register(fileStream);
```
Now the log macros can be used anywhere in the code.


## SA_LOG
The *SA_LOG* macro is used to log a string with an optionnal level, channel and details:
```cpp
SA_LOG(_str, _lvl = Normal, _channel = Default, _details = "");
```
Examples:
```cpp
SA_LOG("Hello");									// Log with 'Normal' level in 'Default' channel.
SA_LOG("Hello", Infos);								// Log with 'Infos' level in 'Default' channel.
SA_LOG("Hello", Infos, MyChannel);					// Log with 'Infos' level in 'MyChannel' channel.
SA_LOG("Hello", Infos, MyChannel, "My details");	// Log with 'Infos' level in 'MyChannel' channel with details "My details".
```


## SA_WARN
The *SA_WARN* macro is used to conditionnally (on false predicate) log a **warning** in an optionnal channel with details.
The predicate as a string is automatically logged:
```cpp
SA_WARN(_predicate, _channel = Default, _details = "");
```
Examples:
```cpp
SA_WARN(myValue == 1)							// Log "myValue == 1" if myValue != 1 in 'Default' channel.
SA_WARN(myValue == 1, MyChannel)				// Log "myValue == 1" if myValue != 1 in 'MyChannel' channel.
SA_WARN(myValue == 1, MyChannel, "My details")	// Log "myValue == 1" if myValue != 1 in 'MyChannel' channel with details "My details".
```


## SA_ERROR
The *SA_ERROR* macro is used to conditionnally (on false predicate) log an **error** in an optionnal channel with details.
The predicate as a string is automatically logged:
```cpp
SA_ERROR(_predicate, _channel = Default, _details = "");
```
Examples:
```cpp
SA_ERROR(myValue == 1)							// Log "myValue == 1" if myValue != 1 in 'Default' channel.
SA_ERROR(myValue == 1, MyChannel)				// Log "myValue == 1" if myValue != 1 in 'MyChannel' channel.
SA_ERROR(myValue == 1, MyChannel, "My details")	// Log "myValue == 1" if myValue != 1 in 'MyChannel' channel with details "My details".
```


## SA_ASSERT
the *SA_ASSERT* macro is used to conditionnally (on false exception predicate) throw an **execption** in a channel.
Arguments to build the exception must be provided:
```cpp
SA_ASSERT(_exceptionType, _channel = Default, _exceptionArgs...);
```
Examples:
```cpp
SA_ASSERT(OutOfBound, Default, 2, 0, 10)	// Doesn't throw Exception_OutOfBound because 2 is in range [0, 10].
SA_ASSERT(OutOfBound, Default, 2, 5, 10)	// Throw Exception_OutOfBound because 2 is not in range [5, 10].
```



# Authors

**Maxime "mrouffet" ROUFFET** - main developer (maximerouffet@gmail.com)
