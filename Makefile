SRC = md-test.c
INCLUDE = ./include
LIBS = ./libs/iTunesMobileDevice.lib ./libs/CoreFoundation.lib

windows:
		gcc $(SRC) -o md-test.exe -I $(INCLUDE) $(LIBS)