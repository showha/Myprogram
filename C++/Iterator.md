### 关于C++各种迭代器的特性：

|                  种类                  |  满足的条件   |           特性           |
| :------------------------------------: | :-----------: | :----------------------: |
|       Input iterator(输入迭代器)       | 可读,但不可写 |      只支持自增运算      |
|      Output iterator(输出迭代器)       | 可写,但不可读 |      只支持自增运算      |
|      Forward iterator(前向迭代器)      |  可读和可写   |      只支持自增运算      |
|   Bidirectional iterator(双向迭代器)   |  可读和可写   |    支持自增和自减运算    |
| Random access iterator(随机访问迭代器) |  可读和可写   | 支持完整的迭代器算术运算 |

### 关于C++各种容器的特性、用途：

| 容器类型 |                             特点                             | 迭代器类型 |
| :------: | :----------------------------------------------------------: | :--------: |
|  string  | 替换C语言中用数组存储字符串，该容器可直接存字符串，因此叫字符串类型 |  随机访问  |
|  vector  |  动态数组，在运行阶段动态增长数组长度，解决了数组越界问题。  |            |
|   set    |    主要特性是自动排序、去重，插入新元素也是自动排序、去重    |            |
|   list   | 双向链表，优点是插入和删除元素都比较快捷，缺点是不能随机访问元素 。不能使用sort()函数，有自己的排序函数。 |            |
|   map    | 类似字典类型，采用key-value的思想。初始化是map<string, int> m; |            |

