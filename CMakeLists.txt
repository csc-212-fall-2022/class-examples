cmake_minimum_required(VERSION 3.14)
project("class examples")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3 -Og")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Doctest REQUIRED)

set(CMAKE_MEMORYCHECK_COMMAND valgrind)

include(CTest)

find_program(CLANG_TIDY_EXE NAMED clang-tidy)
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}" "-checks=-*,modernize-*, bugprone-*")

include(cmake/ClangFormat.cmake)

add_library(Queue chapter10/Queue.cpp chapter10/Queue.hpp)

add_executable(QueueTest chapter10/Queue.test.cpp)
target_link_libraries(QueueTest Queue Doctest)

add_test(NAME QueueTest COMMAND QueueTest)

#add_executable(DedupLinkedList chapter10/DedupeLinkedList.cpp)

add_executable(LinkedList chapter10/LinkedList.cpp)

add_library(ChainedHashTable chapter11/ChainedHashTable.hpp chapter11/HashTableNode.hpp)
set_target_properties(ChainedHashTable PROPERTIES LINKER_LANGUAGE CXX)

add_executable(ChainedHashTableTest chapter11/ChainedHashTable.test.cpp)
target_link_libraries(ChainedHashTableTest Doctest ChainedHashTable)

add_test(NAME ChainedHashTableTest COMMAND ChainedHashTableTest)

add_library(HashTables chapter11/ChainedHashTable.hpp chapter11/HashTableNode.hpp)
set_target_properties(HashTables PROPERTIES LINKER_LANGUAGE CXX)

add_library(BloomFilter bloomfilter/BloomFilter.hpp bloomfilter/BloomFilter.cpp)
add_executable(BloomFilterTest bloomfilter/BloomFilter.test.cpp)
target_link_libraries(BloomFilterTest BloomFilter Doctest)

add_executable(class_examples main.cpp)
