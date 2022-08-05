# 数据库管理系统：

DBMS（DataBase Manager System），这是专门用来管理数据库的系统。所谓的数据库就是指一堆用来存储数据的文件，需要使用DBMS对数据进行增、删、改、查等操作。DBMS是通过执行SQL语句来达到对管理数据的目的，而SQL（结构化查询语言）是一套标准，在所有的DBMS上都是用。常见的DBMS有：MySQL、Oracle、MS SQLsever等等。

## 数据库：

数据库中最基本的元素是表：tale

因为表格的直观性，数据库当中是以表格的形式表示数据的。

任何一张表都有行和列：

- 行（row）：被称为数据/记录

- 列（column）：被称为字段

	每一个字段都有字段名、数据类型、约束等属性

## SQL命令：

mysql -uxxx -pxxx：

以xxx的用户名和xxx的密码登录MySQL数据库管理系统，这是执行SQL命令的前提条件：先进入数据库管理系统

该命令的特点是不见分号不执行（英文分号），它会将分号前的所有内容都当作一条语句。想要结束当前语句的输入而不执行，输入“\c”。

- show databases;

	展示所有的数据库

- select version();

	查看当前MySQL的版本。

- select database();

	查看当前所在的数据库

- use xxx;

	使用xxx名称的数据库为默认数据库

- create database xxx;

	创建名为xxx的数据库

- show tables;

	展示该数据库下的所有表。

- source D:\course\03-MySQL\document\bjpowernode.sql

	导入数据，路径不能有中文

- select * from 表名;

	查看指定表的所有内容

- desc 表名;

	不看表的数据，而是查看表的结构

- select 字段名 from 表名;

	查询一个字段（列）。如果想要查询所有字段，建议采用一个一个字段名列出的方式（用逗号隔开），而不是采用select \* from 表名;因为SQL语句也是采用编译式的，采用\*的方式还会让其转换、读取等占用更多内存，效率低，且可读性差，在开发中不建议采用。

- select 字段名 (as) 别名 from 表名;

	查询一个字段，并且以指定别名的形式显示（不更改表中的原有字段名），as可以省略。如果别名中带有空格或者别名是中文，使用单引号进行包括（可以使用双引号，但是在Oracle中不支持，不是通用的）

- select ename,sal*12 from emp;

	可以在查询的时候对指定字段进行操作（四则运算）并显示操作的结果（不改变表中原有字段的值），通常会与别名搭配（因为输出的是四则运算的表达形式）

#### 条件查询：

##### 格式：

~~~sq
select
	字段名
from
	表名
where
	条件;
~~~

##### 条件：

- =：等于
- <：小于
- \>：大于
- \>=，<=：大于等于，小于等于
- <\>或!=：不等于
- between ...and...：在...和...之间，两边皆闭，等同于<=... and \>=...
- **判断是否为null**：is null / is not null
- and：逻辑符，为“且”
- or：逻辑符，为“或”
- not：逻辑符，为“非”

### SQL的分类：

- DQL：数据查询语言（凡是带有select关键字的都是查询语句）

	select...

- DML：数据操作语言（凡是对表中的数据进行增删改的都是DML）

	insert 增

	delete 删

	update 改

	这个主要是用来操作表中的数据data

- DDL：数据定义语言

	凡是带有create、drop、alter的都是DDL

	DDL主要操作的是表的结构，而非表中的数据

	create：新建，等同于增

	drop：删除

	alter：修改

- TCL：事务控制语言

	TCL经常被用于快速原型开发、脚本编程、GUI和测试等方面，

	简称：TCL，Trasactional Control Languag。代表关键字为事务提交commit、事务回滚rollback。

- DCL：数据控制语言

	数据控制语言DCL用来授予或回收访问数据库的某种特权，并控制数据库操纵事务发生的时间及效果，对数据库实行监视等。简称：DCL，Data Control Language。代表关键字为授权grant、撤销授权revoke。

//024