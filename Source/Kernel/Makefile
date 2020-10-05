# defines the compiler and linker paths and arguments
include ../../Makefile.variables

# object file generation path
BUILDDIR	:= Build
# modules path
SOURCEDIR	:= Source
# output binary path
KERNEL		:= $(BUILDDIR)/bootx64.efi

# Based off: https://stackoverflow.com/a/48267562, and help from https://stackoverflow.com/a/40621556
# This file blantly compiles all source files rather than relevant ones inferred from headers
# TODO: fix that ^. May rewrite this makefile so that it compiles files from a list rather than discovering them all automatically.


# Names of modules and files to be compiled
# just get all files
OBJECTS		+= $(patsubst $(SOURCEDIR)/%.c,%.o,$(shell find $(SOURCEDIR) -iname "*.c"))

# prepend BUILDDIR
OBJECTS		:= $(addprefix $(BUILDDIR)/, $(OBJECTS))

# there should be a dep file for every object file
DEPENDENCIES:= $(patsubst %.o,%.d,$(OBJECTS))


# link the object files into the EFI file under Build/Binary/bootx64.efi, if objects are newer than the EFI file
$(KERNEL): $(OBJECTS) 
# using $(OBJECTS) to link all objects instead of $<, which only does first object file
	$(LD) $(LDFLAGS) -entry:efi_main $(OBJECTS) -out:$@

# rules for module files
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# include the dependencies if they exist    
-include $(DEPENDENCIES)

clean:
	rm -rf $(BUILDDIR)
