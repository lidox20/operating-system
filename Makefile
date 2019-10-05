SRC = ..\BCC\*.cpp 
INCLUDES = ..\BCC\*.h 
LIBS = ..\BCC\*.lib 
INCLUDEPATH = C:\bc31\include;..\BCC;
LIBSPATH = C:\bc31\lib;..\BCC;
TARGET = OS.exe

$(TARGET):	$(SRC) $(INCLUDES)
	C:\bc31\BIN\bcc.exe -mh -v -e$(TARGET) -I$(INCLUDEPATH) -L$(LIBSPATH) $(SRC) $(LIBS)
all:	$(TARGET)
link: $(SRC) 
	C:\bc31\BIN\TLINK.exe $(SRC), $(TARGET),, /L$(LIBSPATH)
clean:
	-del *.obj
	-del $(TARGET)
	-del *.asm
configuration.xmi:	
	configuration.xmi