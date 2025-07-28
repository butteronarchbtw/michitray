# the @: suppresses "nothing can be done..." because it runs something,
# which is a no-op but at indeed something
all: output
	@:

.PHONY: all	clean

output: Doxyfile
	@- rm -rf $@
	@ doxygen Doxyfile

clean:
	@- rm -rf output
