export JAVA_HOME=/home/wenchunyang/hadoop-client_withouinfso/java6/
export PATH=$JAVA_HOME/bin:$PATH:
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:".":

#for jvm
JVM_PATH="$JAVA_HOME/jre/lib/amd64:$JAVA_HOME/jre/lib/amd64/server/"
export LD_LIBRARY_PATH=$JVM_PATH:$LD_LIBRARY_PATH:

java -version
javac Sample2.java

make

# run Sample2
#ldd app
./app
