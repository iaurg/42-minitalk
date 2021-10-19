# 42-minitalk

TODO
- [] The executable files must be named client and server.
- [] You have to handle errors sensitively. In no way can your program quit unexpectedly
(Segmentation fault, bus error, double free, etc).
- [] Your program cannot have memory leaks.
- [] You can use one global variable but it must be justified
- [] Communication between your programs should ONLY be done using UNIX signals.
- [] You can only use the two signals SIGUSR1 and SIGUSR2
- [] Remove printf
- [] Make code run faster


On the mandatory part you are allowed to use the following functions:
◦ write
◦ ft_printf and any equivalent YOU coded
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill
◦ getpid
◦ malloc
◦ free
◦ pause
◦ sleep
◦ usleep
◦ exit

### Material:

https://www.youtube.com/watch?v=83M5-NPDeWs

https://www.youtube.com/watch?v=5We_HtLlAbs

Signals communicate between proccesses

usleep stops for some time the execution

getpid() - Gets process ID

Signals work as something that send notifications to processes

Process decides what to do when the signal arrives, using a handler

SIGUSR1 = 10 SIGUSR2 = 12

signals can be sent three ways: -9, -SIGUSR1, USR1

kill()--Send Signal to Process or Group of Processes

https://www.ibm.com/docs/en/i/7.2?topic=ssw_ibm_i_72/apis/sigkill.htm

https://stackoverflow.com/questions/67985972/how-can-you-send-a-string-given-has-argument-to-a-program-to-another-program-usi

Avoid using signal from manual:

The behavior  of signal() varies across UNIX versions, and has also varied historically across different versions of Linux.  Avoid its use: use sigaction(2) instead.  See Portability below.

sigaction manual: https://man7.org/linux/man-pages/man2/sigaction.2.html

Mastering signals: https://www.youtube.com/watch?v=L3XuR-iRysU&list=PLysdvSvCcUhbrU3HhGhfQVbhjnN9GXCq4&index=42

Binary converter: https://c-for-dummies.com/blog/?p=3032

Bitwise converter: https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm

Generate characters: http://www.unit-conversion.info/texttools/random-string-generator/

a = 110000 = 48
holder += 1 << 6;
holder += 0 << 5;
holder += 0 << 4;
holder += 0 << 3;
holder += 0 << 2;
holder += 0 << 1;
holder += 1 << 0;

### Interesting:

https://www.youtube.com/watch?v=X8jsijhllIA

### Examples:

https://github.com/yhcho0405/MiniTalk

https://github.com/mlanca-c/Minitalk

https://github.com/natflausino/Minitalk

https://github.com/rkrocha/minitalk
