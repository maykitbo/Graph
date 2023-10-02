.PHONY: all clean

all:
	cmake -S . -B include
	make -C include
	./include/example

clean:
	rm -rf include
	rm -rf *.png