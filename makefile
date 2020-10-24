CFLAGS = -std=c++17 -O2
imageCode:main.cpp
	g++ $(CFLAGS) -o rawimage main.cpp
clean:
	rm -f rawimage 