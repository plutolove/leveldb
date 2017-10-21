//
// Created by plutolove on 9/2/16.
//

#include <iostream>
#include <cassert>
#include "leveldb/db.h"
typedef long long LL;
using namespace std;
int main() {
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/home/meng/CLionProjects/db/", &db);
  assert(status.ok());
  string key = "name";
  string value = "mengshangqi";
  status = db->Put(leveldb::WriteOptions(), key, value);
  assert(status.ok());

  // read
  status = db->Get(leveldb::ReadOptions(), key, &value);
  assert(status.ok());
  cout << value << endl;
  for(int i=0; i<50000; i++) {
    status = db->Put(leveldb::WriteOptions(), to_string(i)+"dfgdf", to_string(i)+"fdhfghjdfg");
    assert(status.ok());
  }
  return 0;
}
