cmake_minimum_required(VERSION 3.5)
project(leveldb)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")# -Wall -pthread")

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include)

set(SOURCE_FILES
        db/builder.cc
        db/builder.h
        db/c.cc
        db/db_impl.cc
        db/db_impl.h
        db/db_iter.cc
        db/db_iter.h
        db/dbformat.cc
        db/dbformat.h
        db/dumpfile.cc
        db/filename.cc
        db/filename.h
        db/leveldbutil.cc
        db/log_format.h
        db/log_reader.cc
        db/log_reader.h
        db/log_writer.cc
        db/log_writer.h
        db/memtable.cc
        db/memtable.h
        db/repair.cc
        db/skiplist.h
        db/snapshot.h
        db/table_cache.cc
        db/table_cache.h
        db/version_edit.cc
        db/version_edit.h
        db/version_set.cc
        db/version_set.h
        db/write_batch.cc
        db/write_batch_internal.h
        helpers/memenv/memenv.cc
        helpers/memenv/memenv.h
        include/leveldb/c.h
        include/leveldb/cache.h
        include/leveldb/comparator.h
        include/leveldb/db.h
        include/leveldb/dumpfile.h
        include/leveldb/env.h
        include/leveldb/filter_policy.h
        include/leveldb/iterator.h
        include/leveldb/options.h
        include/leveldb/slice.h
        include/leveldb/status.h
        include/leveldb/table.h
        include/leveldb/table_builder.h
        include/leveldb/write_batch.h
        port/atomic_pointer.h
        port/port.h
        port/port_example.h
        port/port_posix.cc
        port/port_posix.h
        port/thread_annotations.h
        table/block.cc
        table/block.h
        table/block_builder.cc
        table/block_builder.h
        table/filter_block.cc
        table/filter_block.h
        table/format.cc
        table/format.h
        table/iterator.cc
        table/iterator_wrapper.h
        table/merger.cc
        table/merger.h
        table/table.cc
        table/table_builder.cc
        table/two_level_iterator.cc
        table/two_level_iterator.h
        util/arena.cc
        util/arena.h
        util/bloom.cc
        util/cache.cc
        util/coding.cc
        util/coding.h
        util/comparator.cc
        util/crc32c.cc
        util/crc32c.h
        util/env.cc
        util/env_posix.cc
        util/filter_policy.cc
        util/hash.cc
        util/hash.h
        util/histogram.cc
        util/histogram.h
        util/logging.cc
        util/logging.h
        util/mutexlock.h
        util/options.cc
        util/posix_logger.h
        util/random.h
        util/status.cc main.cpp
        TEST/testharness.cc
        TEST/testharness.h
        )

add_library(leveldb ${SOURCE_FILES})
find_package (Threads REQUIRED)
target_link_libraries(leveldb Threads::Threads )

add_executable(arena_test TEST/arena_test.cc)
target_link_libraries(arena_test leveldb)

add_executable(coding_test TEST/coding_test.cc)
target_link_libraries(coding_test leveldb)