#!/bin/bash

################################################################################
# Author: Sebastien CORBEAU <corbeau.sebastien@yahoo.fr>
# Date: 2023-12-20
# Brief: This script generate C header file contains the tag and SHA1 commit of
#        GIT repository.
################################################################################

if [ $# -lt 1 ]; then
    echo "Generate C header contains GIT tag version and SHA1 commit " \
         "in <output>"
    echo "Optionnaly user could force TAG and SHA1 version."
    echo "Usage $0 <output> [TAG] [SHA1]"
    exit 1
fi

rm -rf $1

if [ $# -eq 2 ]; then
    if [ "$2" != "" ]; then
        TAG=$2
    else
        TAG="INVALID_TAG"
    fi
    SHA1="SHA1_NOT_FORCE"
elif [ $# -ge 3 ]; then
    if [ "$2" !=  "" ]; then
        TAG=$2
    else
        TAG="INVALID_TAG"
    fi

    if [ "$3" !=  "" ]; then
        GIT_SHA1=$3
    else
        GIT_SHA1="INVALID_SHA1"
    fi
else
    TAG=`git describe --tag --dirty=-DIRTY`
    if [ $? -ne 0 ]; then
        TAG="NO_TAG"
    fi

    SHA1=`git rev-parse HEAD`
    if [ $? -ne 0 ]; then
        SHA1="NO_SHA1"
    fi
fi

LIB_NAME=$(basename $(git rev-parse --show-toplevel))
if [ $? -ne 0 ]; then
    LIB_NAME="NO_LIBRARY_NAME"
fi

echo "/*!" > $1
echo " * @file: $(basename $1)" >> $1
echo " * @date: $(date '+%Y-%m-%d')" >> $1
echo " * @author: This file is auto generated by $(basename $0) written by "\
    "Sebastien CORBEAU (corbeau.sebastien@yahoo.fr)" >> $1
echo " * @brief: Declaration of library revision get from GIT repo." >> $1
echo " */" >> $1
echo "#ifndef GIT_REVISION_H__" >> $1
echo "#define GIT_REVISION_H__" >> $1
echo "" >> $1
echo "#define GIT_TAG   \"$TAG\"" >> $1
echo "#define GIT_SHA1  \"$SHA1\"" >> $1
echo "#define LIB_NAME  \"$LIB_NAME\"" >> $1
echo "" >> $1
echo "#endif /* GIT_REVISION_H__ */" >> $1