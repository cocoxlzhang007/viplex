#!/bin/bash
mv ./src/viplexcore.java ./src/ViplexCore.java
mv ./src/test.java ./src/Test.java
javac -cp "./lib/jna-5.6.0.jar:./lib/jna-platform-5.6.0.jar:./:../../bin/" -encoding utf-8 -d . ./src/ViplexCore.java ./src/Test.java
java -cp "./lib/jna-5.6.0.jar:./lib/jna-platform-5.6.0.jar:./:../../bin/" Test