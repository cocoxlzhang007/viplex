@echo off
echo 请把文件“demo\java\src\test.java”中的g_sn设置成实际设备的sn号（sn号可以在设备外观上看到）
pause
echo 中文测试
javac  -cp "./lib/jna-5.6.0.jar;./lib/jna-platform-5.6.0.jar;./../../bin/;./" -encoding utf-8 -d . ./src/ViplexCore.java ./src/Test.java
echo '生成class文件，按任意键开始运行demo'
java -cp "./lib/jna-5.6.0.jar;./lib/jna-platform-5.6.0.jar;./../../bin/;./" Test
pause