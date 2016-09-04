//
// Created by plutolove on 9/2/16.
//

#include <iostream>
#include "leveldb/db.h"

int main() {
    std::cout << "Hello, hac" << std::endl;
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    std::string dbpath = "testdb";
    leveldb::Status status = leveldb::DB::Open(options, dbpath, &db);
    assert(status.ok());
    std::string key = "sdfg";
    //std::string val = "test_value";
    //status = db->Put(leveldb::WriteOptions(), key, val);
    std::string outval;
    status = db->Get(leveldb::ReadOptions(), key, &outval);
    std::cout << key << " : " << outval << std::endl;
}
