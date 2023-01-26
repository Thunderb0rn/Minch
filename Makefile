all : main.cpp
	g++ -Wall -o minch main.cpp

install : main.cpp
	g++ -Wall -o minch main.cpp
	cp -r minch.8.gz /usr/share/man/man8
	cp -r minch /usr/bin
	rm -rf *.o minch

clean :
	rm -rf *.o minch
