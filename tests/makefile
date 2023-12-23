################################################################################
# Author: Sebastien CORBEAU (sebastien.corbeau@viveris.fr)                     #
# Date: 20/12/2023                                                             #
################################################################################

################################################################################
# Define project directories
################################################################################
PROJECT_DIR		= $(abspath ../..)
RESOURCE_DIR	= $(PROJECT_DIR)/res
SRC_DIR			= $(abspath .)

################################################################################
# Define target
################################################################################
ifdef TARGET
	-include $(RESOURCE_DIR)/toolchain/config_$(TARGET).mk
endif

CC		= $(CROSS)gcc
CXX		= $(CROSS)g++
STRIP	= $(CROSS)strip
ARCH	= $(shell $(CC) -dumpmachine | cut -d - -f1)

################################################################################
# Define build directories
################################################################################
BUILD_DIR	?= $(PROJECT_DIR)/build/$(MODE)/$(ARCH)
OBJ_DIR		?= $(BUILD_DIR)/obj
LIB_DIR		?= $(BUILD_DIR)/lib
TEST_DIR	?= $(BUILD_DIR)/test
INC_DIR		?= $(BUILD_DIR)/inc

################################################################################
# Compilation flags
################################################################################
CXXFLAGS	+= -funwind-tables -fstack-protector-all -Wall -Werror
INCFLAGS	?= $(PROJECT_DIR)/lib/inc
LIBS		= -L $(LIB_DIR) -lgtest -lgtest_main -l:lib-utils.a

################################################################################
# Obj to compile
################################################################################
TESTS_LIST	= $(patsubst %.cpp, $(TEST_DIR)/%.exe, $(shell find $(SRC_DIR) \
				-name *.cpp | sed -e 's,\$(SRC_DIR)/,,'))

################################################################################
# Main rules
################################################################################
default: all

all: $(TESTS_LIST)

################################################################################
# Build rules
################################################################################
$(TEST_DIR)/%.exe: $(OBJ_DIR)/%.o
	mkdir -p $(@D)
	$(CXX) -o $@ $^ $(LIBS)
ifeq ($(CONF), release)
	$(STRIP) $@
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -fPIC $(INCFLAGS) -o $@ -c $<

################################################################################
# Clean rules
################################################################################
clean:
	rm -rf $(LIB_DIR)/$(LIB_BIN) $

distclean: clean
	rm -Rf $(OBJ_DIR)

.PHONY: default all lib clean distclean doc