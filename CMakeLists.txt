cmake_minimum_required(VERSION 3.13)
project(libfts)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/libft)

add_executable(libfts
        include/libft/io.h
        include/libft/mem.h
        include/libft/str.h
        include/dependencies.h
        include/libft.h
        io/ft_puts.asm
        io/ft_puts.o
        mem/ft_bzero.asm
        mem/ft_bzero.o
        str/ft_strlen.asm
        str/ft_strlen.o
        README.md
        test.c)
