JAVA_HOME=/home/wenchunyang/hadoop-client_withouinfso/java6/
JAVA_INCLUDE_NORMAL=$(JAVA_HOME)/include/
JAVA_INCLUDE_PLATFORM=$(JAVA_HOME)/include/linux

#C_FLAGS="--shared -fPIC -g "
C_FLAGS=
C_FLAGS+=-I$(JAVA_INCLUDE_NORMAL)
C_FLAGS+= -I$(JAVA_INCLUDE_PLATFORM)
C_FLAGS+= -L$(JAVA_HOME)/jre/lib/amd64/
C_FLAGS+= -L$(JAVA_HOME)/jre/lib/amd64/server/

#C_LIBRARY+= -ljava
# This should be at the end.
C_LIBRARY+= -ljvm

app : Sample2.c
	gcc $(C_FLAGS) Sample2.c -o app $(C_LIBRARY)


