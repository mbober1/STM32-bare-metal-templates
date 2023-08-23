set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TARGET_TRIPLET "arm-none-eabi")

set(OBJCOPY ${TARGET_TRIPLET}-objcopy CACHE INTERNAL "objcopy tool")
set(OBJDUMP ${TARGET_TRIPLET}-objdump CACHE INTERNAL "objdump tool")
set(OBJSIZE ${TARGET_TRIPLET}-size CACHE INTERNAL "objsize tool")
set(CMAKE_C_COMPILER ${TARGET_TRIPLET}-gcc  CACHE INTERNAL "c compiler")
set(CMAKE_CXX_COMPILER ${TARGET_TRIPLET}-g++ CACHE INTERNAL "cpp compiler")
set(DEBUGGER ${TARGET_TRIPLET}-gdb CACHE INTERNAL "debugger")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_FLAGS   "${MCPU_FLAGS} ${VFP_FLAGS} -fdata-sections \
                    -ffunction-sections -fno-common -fno-builtin"
                         CACHE INTERNAL "c compiler flags")
set(CMAKE_CXX_FLAGS "${MCPU_FLAGS} ${VFP_FLAGS} -fdata-sections \
                    -ffunction-sections -fno-common -fno-builtin \
                    -fno-rtti -fno-exceptions"
                         CACHE INTERNAL "cxx compiler flags")
set(CMAKE_ASM_FLAGS "${MCPU_FLAGS} -x assembler-with-cpp"
                         CACHE INTERNAL "asm compiler flags")
set(CMAKE_EXE_LINKER_FLAGS "${MCPU_FLAGS} ${LD_FLAGS} -Wl,--gc-sections \
                            --specs=nosys.specs"
                         CACHE INTERNAL "exe link flags")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -ggdb3 -DDEBUG"
                         CACHE INTERNAL "c debug compiler flags")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb3 -DDEBUG"
                         CACHE INTERNAL "cxx debug compiler flags")
set(CMAKE_ASM_FLAGS_DEBUG "-g -ggdb3 -DDEBUG -D__STARTUP_CLEAR_BSS"
                         CACHE INTERNAL "asm debug compiler flags")

set(CMAKE_C_FLAGS_RELEASE "-O3"
                         CACHE INTERNAL "c release compiler flags")
set(CMAKE_CXX_FLAGS_RELEASE "-O3"
                         CACHE INTERNAL "cxx release compiler flags")
set(CMAKE_ASM_FLAGS_RELEASE ""
                         CACHE INTERNAL "asm release compiler flags")
