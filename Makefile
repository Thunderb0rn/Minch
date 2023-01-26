all : main.cpp
	g++ -Wall -o minch main.cpp

install : main.cpp
	g++ -Wall -o minch main.cpp
	cp -r minch.8.gz /usr/share/man/man8
	chown root:root /usr/share/man/man8/minch.8.gz
	cp -r minch /usr/bin
	chown root:root /usr/bin/minch
	rm -rf *.o minch

uninstall:
	rm -rf /usr/bin/minch /usr/share/man/man8/minch.8.gz

clean :
	rm -rf *.o minch
