
all: force_look
	cd src; $(MAKE)
	cd samples; $(MAKE)

clean: force_look
	cd src; $(MAKE) clean
	cd samples; $(MAKE) clean
	@rm -Rf lib/libsay.so

force_look:
	@true

