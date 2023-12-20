################################################################################
# Author: Sebastien CORBEAU (sebastien.corbeau@viveris.fr)                     #
# Date: 19/12/2023                                                             #
################################################################################

################################################################################
# Define project directories
################################################################################
PROJECT_DIR		= $(abspath .)
RESOURCE_DIR	= $(PROJECT_DIR)/res

################################################################################
# Define target
################################################################################
ifdef TARGET
	-include $(RESOURCE_DIR)/toolchain/config_$(TARGET).mk
endif

CC		?= $(CROSS)gcc
ARCH	?= $(shell $(CC) -dumpmachine | cut -d - -f1)

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
	CXXFLAGS	+= -g$(DEBUG_LEVEL) -DCONF=debug -DDEBUG_ENABLE=1
	CONF=debug
else
	CONF=release
endif

################################################################################
# Define build directories
################################################################################
BUILD_DIR	?= $(PROJECT_DIR)/build/$(CONF)/$(ARCH)
OBJ_DIR		?= $(BUILD_DIR)/obj
LIB_DIR		?= $(BUILD_DIR)/lib
BIN_DIR		?= $(BUILD_DIR)/bin
TEST_DIR	?= $(BUILD_DIR)/test
DOC_DIR		?= $(PROJECT_DIR)/build/doc
INC_DIR		?= $(BUILD_DIR)/inc

################################################################################
# Compilation flags
################################################################################
CFLAGS		+= -rdynamic -funwind-tables -fstack-protector-all -Wall -Werror
CXXFLAGS	+= -rdynamic -funwind-tables -fstack-protector-all -Wall -Werror

################################################################################
# Version header file
################################################################################
GIT_VERSION_FILE=$(INC_DIR)/git-informations.h

################################################################################
# Project name
################################################################################
PROJECT_NAME	= $(notdir $(shell git rev-parse --show-toplevel))

################################################################################
# Main rules
################################################################################
default: all

all: libs 

################################################################################
# Build rules
################################################################################
libs: $(GIT_VERSION_FILE)
	make -C lib LIB_NAME="$(PROJECT_NAME)" CROSS="$(CROSS)" CFLAGS="$(CFLAGS)" \
		BUILD_DIR="$(BUILD_DIR)" LIB_DIR="$(LIB_DIR)" OBJ_DIR="$(OBJ_DIR)/lib" \
		DOC_DIR="$(DOC_DIR)" INC_DIR="$(INC_DIR)" CONF="$(CONF)"

$(GIT_VERSION_FILE):
	@mkdir -p $(@D)
	@rm -Rf $@
	$(RESOURCE_DIR)/tools/git/version_header_generator.sh $@

################################################################################
# Clean rules
################################################################################
clean:
	rm -Rf $(LIB_DIR) $(BIN_DIR) $(INC_DIR) $(DOC_DIR)

distclean:
	rm -rf build

.PHONY: default all libs clean