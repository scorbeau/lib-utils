################################################################################
# Author: Sebastien CORBEAU (sebastien.corbeau@viveris.fr)                     #
# Date: 23/12/2023                                                             #
################################################################################

################################################################################
# Define project directories
################################################################################
PROJECT_DIR		= $(abspath ../..)
RESOURCE_DIR	= $(PROJECT_DIR)/res
SRC_DIR			= $(abspath ./src)

################################################################################
# Define target
################################################################################
ifdef TARGET
	-include $(RESOURCE_DIR)/toolchain/config_$(TARGET).mk
endif

CC		= $(CROSS)gcc
LD		= $(CROSS)ld
AR		= $(CROSS)ar
STRIP	= $(CROSS)strip
ARCH	= $(shell $(CC) -dumpmachine | cut -d - -f1)

################################################################################
# Select compilation configuration
################################################################################
# if DEBUG_LEVEL is passed in make command force enabling
ifneq ($(DEBUG_LEVEL),)
	DEBUG_ENABLE=y
endif

DEBUG_LEVEL	?= 3

ifeq ($(DEBUG_ENABLE),y)
	CFLAGS		+= -g$(DEBUG_LEVEL) -DCONF=debug -DDEBUG_ENABLE=1
	CONF=debug
else
	CONF=release
endif

################################################################################
# Define build directories
################################################################################
BUILD_DIR	?= $(PROJECT_DIR)/build/$(MODE)/$(ARCH)
OBJ_DIR		?= $(BUILD_DIR)/obj
LIB_DIR		?= $(BUILD_DIR)/lib
BIN_DIR		?= $(BUILD_DIR)/bin
TEST_DIR	?= $(BUILD_DIR)/test
DOC_DIR		?= $(PROJ_DIR)/build/doc

################################################################################
# Compilation flags
################################################################################
CFLAGS		?= -funwind-tables -fstack-protector-all -Wall -Werror
override INCFLAGS	+= -iquote $(abspath ./inc)
LIBS		= -L $(LIB_DIR) -l:lib-utils.a

################################################################################
# Obj to compile
################################################################################
OBJS_LIST	= $(patsubst %.c, $(OBJ_DIR)/%.o, $(shell find $(SRC_DIR) -name \
				*.c | sed -e 's,\$(SRC_DIR)/,,'))

################################################################################
# Application name
################################################################################
APPL_NAME	?= $(notdir $(shell git rev-parse --show-toplevel))
APPL_BIN	= $(APPL_NAME).exe

################################################################################
# Main rules
################################################################################
default: all

all: appl

################################################################################
# Build rules
################################################################################
appl: $(APPL_BIN)
$(APPL_BIN): $(BIN_DIR)/$(APPL_BIN)
$(BIN_DIR)/%.exe: $(OBJS_LIST)
	mkdir -p $(@D)
	$(CC) -o $@ $^ $(LIBS)
ifeq ($(CONF), release)
	$(STRIP) $@
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p  $(shell dirname $@)
	$(CC) $(CFLAGS) -fPIC $(INCFLAGS) -DAPPL_NAME="$(APPL_NAME)" -o $@ -c $<

################################################################################
# Clean rules
################################################################################
clean:
	rm -rf $(BIN_DIR)/$(APPL_BIN) $

distclean: clean
	rm -Rf $(OBJ_DIR)

.PHONY: default all appl clean distclean doc