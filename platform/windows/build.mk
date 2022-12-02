# define source directory
SRC		+= $(PLATFORM_PATH)

# define include directory
INCLUDE	+= $(PLATFORM_PATH)

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS += -lusb

# define lib directory
LIB		+= $(PLATFORM_PATH)/lib
