JAVA_HOME=~/hadoop-client_withouinfso/java6/
JAVA_INCLUDE_NORMAL=$(JAVA_HOME)/include/
JAVA_INCLUDE_PLATFORM=$(JAVA_HOME)/include/linux

C_FLAGS="--shared -fPIC -g "
C_FLAGS+=" -I$(JAVA_INCLUDE_NORMAL) "
C_FLAGS+=" -I$(JAVA_INCLUDE_PLATFORM) "

libSample1.so : Sample1.c
	gcc Sample1.c -o libSample1.so


