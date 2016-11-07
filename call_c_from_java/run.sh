export JAVA_HOME=~/hadoop-client_withouinfso/java6/
export PATH=$PATH:$JAVA_HOME/bin:
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:".":

javac Sample1.java

# Generate Header @Sample1.h
# javah Sample1
# Then program it, see @Sample1.c

# build libSample.so
make

# run Sample1
# We should put libSample1.so to a folder where ld can find
java Sample1

