Minitalk
========

Usage
=====

./server
(gives it's PID)

./client PID_from_server and_message

Error tests
===========

1)
./client PID_from_server
(less args)

2)
./client and_message
(less args)

3)
./client wrong_PID and_message
(Invalid PID)

Normal tests
============

1) 10 signs:
0123456789

2) 100 signs:
"0123456789 abcdefghij 01&3456-89 01:?456789 0123456.89 0123456789 #123456789
0,23456789 012=+56789 01234567*9"

3) 1000 signs
https://03www.ru/generator/gen-03.htm

"Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat. Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio dignissim qu"

Bonus tests:
============

4) (Unicode): Emoji
☺
😁
👣
🌈
🐠
🐠🌈👣😁☺

5) (Unicode): Russian
Привет
