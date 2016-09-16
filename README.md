###LevelDB源码分析
* include/leveldb

>* c.h 声明leveldb的c语言接口
  
>* cache.h 声明一个纯虚类Cache
  
>>* extern Cache *NewLRUCache(size_t capacity) 
声明一个全局函数，返回一个固定大小的LRUCache  

>>* struct Handle {}  
定义一个空Handle，在实际应用中，用户可以根据自己的需求定义新的Handle结构体  

>>* Cache(const Cache &) 和 void operator=(const Cache &)  
定义为private禁止复制

>>* Insert 插入kv返回Handle  

>>* Lookup 查询k返回Handle  

>>* Value 传入handle得到对应的value   

>>* Erase 删除kv  

>>* NewId 产生一个新id  