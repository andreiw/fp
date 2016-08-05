all: fp sfp

sfp: fp
	ln -s fp sfp

fp: fp.c

clean:
	rm -f *~ sfp fp
