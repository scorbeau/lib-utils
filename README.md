# Lib Utils

## Table of Contents

1. [Description](#description)
2. [Dependencies](#dependencies)
3. [Init repository](#init-repository)
4. [How to build](#how-to-build)
    1. [Compile library](#compile-library)
    2. [Compile test application](#compile-test-application)
    3. [Compile unit test](#compile-unit-test)
5. [Known issues](#known-issues)

## Description <a name="description"></a>

This project is a set of utils tools :
 * String management (copy, concat),
 * Number parser.
 * Assert.
 * Tables.

The project is hosted on Github.

## Dependencies <a name="dependencies"></a>

This project depends on *git-version-tools* tools installed as submodule of this
project:
 * [git-version-tools](https://github.com/scorbeau/git-version-tools)

This project is compiled with [msys2](https://www.msys2.org/) and mingw64 and 
based on makefile system.

Install packages below:
 * mingw-w64-x86_64-gcc
 * mingw-w64-x86_64-gtest

## Init repository <a name=init-repository></a>

Clone repository and init submodule with commands below:

```(bash)
git clone git@github.com:scorbeau/lib-utils.git
cd lib-utils
git submodule update --init --recursive
```

## How to build <a name="how-to-build"></a>

### Compile library <a name="compile-library"></a>
To compile project use command below:

```(bash)
make lib
```

Outputs are located to *build/<compilation_mode>/\<arch>/lib/*.

### Compile test application <a name="compile-test-application"></a>
To compile project use command below:

```(bash)
make appl
```

Outputs are located to *build/<compilation_mode>/\<arch>/bin/*.

### Compile unit test <a name="compile-unit-test"></a>

To compile unit test use command below:

```(bash)
make
```

Outputs are located to *build/<compilation_mode>/\<arch>/lib*.

### Compile for specific target <a name="specific-target-complation"></a>

To compile for specific target, define variable **TARGET** when invoke *make*:

```(bash)
make TARGET=mingw64
```

By default target is build for gcc host machine.

If you want to add board support add config_\<TARGET>.mk in *res/toolchain* 
directory.

## Known issues <a name="known-issues"></a>

Nothing to mention.
