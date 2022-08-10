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

~~~sql
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

- between ...and...：在...和...之间，两边皆闭，等同于<=... and \>=...。使用时一定是左边小右边大。

- **判断是否为null**：is null / is not null

- and：逻辑符，为“且”

- or：逻辑符，为“或”

	and和or同时出现，**and优先级较高**。如果想让or先执行，需要加“小括号”。以后在开发中，如果不确定优先级，就加小括号就行了。

- not：逻辑符，为“非”

- in：包含，相当于多个or（not in 则是不包含）

	使用小括号表示多个包含`select empno,ename,job from emp where job in('MANAGER', 'SALESMAN');`意思是查询职位是经理或者是销售员的员工（并非是从经理到销售员）

- like：模糊查询，使用“%”和“\_”进行匹配。

	“%”匹配任意多个字符
	“\_”：任意一个字符。

	找出名字中含有O的：mysql> select ename from emp where ename like '%O%';

	找出名字以T结尾的：select ename from emp where ename like '%T';
	找出名字以K开始的：select ename from emp where ename like 'K%';

	找出第二个字每是A的：select ename from emp where ename like '_A%';

	找出第三个字母是R的：select ename from emp where ename like '__R%';

	若要查询的是特殊符号“%”和“\_”，应该使用转义字符“\\”。

#### 排序：

##### 格式：

~~~sql
select
	字段名
from
	表名
where
	条件
order by
	字段名 ( desc降序或 asc升序);
~~~

各关键字的顺序不能改变，必须要如此。执行的顺序是from --\> where --\> select --\> order by（排序永远在最后，如果没有指明升降序，则默认升序）。

也可以实现多字段查询，只需要在各个字段名间使用“,”逗号分隔，优先使用第一个字段排序，如果第一个字段相同，则使用第二个字段排序，依此类推。

#### 数据处理函数：

数据处理函数又被称为单行处理函数，其处理数据是一行一行地处理。先处理完第一行，然后再处理第二行，以此类推····

- lower：转换小写

- upper：转换大写

- substr(要截取的字符串，起始下标，截取长度)：对字符串进行截取操作。注意，在MySQL中**字符串的起始值默认为1**。

- concat：字符串拼接函数，在MySQL中字符串是无法像Java那样可以直接进行字符串加法运算，需要使用此函数

- length(字符串)：取长度运算

- trim：去除空格

- str_to_date：将字符串转换成日期

- date_format：格式化日期

- format：设置千分位

- case...when...then...end：相当于if,else，但用法有所不同

	~~~sql
	select 
		ename,
		job, 
		sal as oldsal,
		(case job when 'MANAGER' then sal*1.1 when 'SALESMAN' then sal*1.5 else sal end) as newsal 
	from 
		emp;
	~~~

- round(数据，位数)：四舍五入操作，参数可以为负数，如果为-1，意味着四舍五入到十位。

- 如果要查询的字段是字面量（字符串或者数字）那么MySQL默认根据from的表格输出相同行数的表（表中内容全为该字面量）

- rand()：生成0\~1的随机数

- ifnull：可以将null转化成一个具体值。MySQL规定，在所有数据库中，凡是有null参与的数学运算，最终结果都为null

	为了避免这个现象，需要使用ifnull函数。ifnull函数用法：ifnull(数据, 被当做哪个值)。如果“数据”为NULL的时候，把这个数据结构当做哪个值。

#### 分组函数：

分组函数又称为多行处理函数，它的处理对象是多行。

- count：计数
- sum：求和
- avg：平均值
- max：最大值
- min：最小值

分组函数在使用的时候必须先进行分组，然后才能用。如果你没有对数据进行分组，整张表默认为一组。

##### 注意：

- 分组函数自动忽略NULL，你不需要提前对NULL进行处理。
- 分组函数中count(*)和count(具体字段)有区别。一个是统计所有字段的多行，一个是统计中指定字段的多行。只要一行中不是所有的数据均为NULL，那么该行数据就是有效的。
- 分组函数不能够直接使用在where子句中。
- 所有的分组函数可以组合起来一起用。例如：select sum(sal),min(sal),max(sal),avg(sal),count(*) from emp;

#### 分组查询：

##### 格式：

~~~sql
select
	字段名
from
	表名
where
	条件
group by
	字段名
order by
	字段名;
~~~

再次强调，以上关键字的顺序不能颠倒，需要记忆。

执行的顺序：from --\> where --\> group by --\> select --\> order by。前面已经强调分组函数不能在未分组的情况下使用，所以无法在where中使用。这句话的解释是：即使我们没有使用group by，系统也是默认使用，把整张表分为一组，也就等于where是在group by之前，所以不能使用。

重点结论：
			在一条select语句当中，如果有group by语句的话，select后面只能跟：参加分组的字段，以及分组函数，其它的一律不能跟。最好只有一个要分组的字段（MySQL中可以执行，但是Oracle中会报错）。

​			select job, sum(sal) from emp group by job;的意思是，从表格emp中对job进行分组，然后查询分完组的job（相同的合并），并将相同job的所有sal相加起来，最后显示输出。

当然，也可以使用联合分组。例如SELECT DEPTNO, JOB, MAX(SAL) MAX FROM EMP GROUP BY DEPTNO, JOB;就是将deptno和job组合起来一起分组。与此同时，select中的字段也就只能选择被分组的字段。

##### having语句：

having语句在group by后面使用，意思是在分完组后，再按照having给的条件进一步过滤。不过，因为分组已经消耗了大量操作，与进一步过滤的操作重复，这样的效率低，通常都是使用where先筛选再分组。之所以使用having是有时会碰到where不能使用的情况（例如不能在where中使用分组函数）。

例子：select deptno,avg(sal)  from emp group by deptno having avg(sal) > 2500;

### 连接查询：

#### 笛卡尔积现象：

当两张表进行连接查询，没有任何条件限制的时候，最终查询结果条数，是两张表条数的乘积，这种现象被称为：笛卡尔积现象。避免笛卡尔积现象的办法是给表格起别名。（这只能避免输出结果不满足笛卡尔积现象，真正查询的次数仍然是笛卡尔积数）

#### 内连接：

##### 等值链接：

查询的时候查询的是多张表格，而非一张。等值连接也就是查询的判断条件为：是否相等。

我们现在采用的是SQL99的语法（使用join...on...的方式），相比于SQL92的语法（采用from...where...的方式），优点是分离了连接查询的条件与条件查询的条件（避免了两者的混淆）。下图中的inner可以省略，但是如果不省略更容易看出来是内连接。

~~~sql
select 
	e.ename,d.dname
from
	emp e
inner join
	dept d
on
	e.deptno = d.deptno;
~~~

##### 非等值连接：

连接查询的条件不是用是否相等来判断的，而是使用不等号（<\>、\>、between...and...等）

##### 自连接：

需要连接查询的两张表格均为同一张表格，方法是导入两张相同的表格，起不同的别名。

~~~sql
select y.ename, l.ename
from EMP y
inner join 
EMP l
on
y.mgr = l.empno;
~~~

#### 外连接：

与内连接相对，内连接中A和B连接，AB两张表没有主次关系，平等的。其特点是：将完全能够匹配上这个条件的数据查询出来。

外连接中表有主次之分，即其按照条件把主表中所有信息在次表中的对应信息寻找出来，哪怕次表中没有与主表对应的信息（此时自动输出NULL）

##### 左外连接（左连接）：

~~~sql
select 
	e.ename,d.dname
from
	dept d 
left outer join 
	emp e
on
	e.deptno = d.deptno;
~~~

在join左边的表即表示主表，outer可以省略（下同）

##### 右外连接（右连接）：

~~~sql
select 
	e.ename,d.dname
from
	dept d 
right outer join 
	emp e
on
	e.deptno = d.deptno;
~~~

在join右边的表示主表

##### 多表连接：

~~~sql
select 
	e.ename,e.sal,d.dname,s.grade,l.ename
from
	emp e
join
	dept d
on 
	e.deptno = d.deptno
join
	salgrade s
on
	e.sal between s.losal and s.hisal
left join
	emp l
on
	e.mgr = l.empno;
~~~

### 子查询：

select语句中嵌套select语句，被嵌套的select语句称为子查询。

#### 格式：

~~~sql
select
	..(select).
from
	..(select).
where
	..(select).
~~~

#### where中的子查询：

`select ename,sal from emp where sal > (select min(sal) from emp);`通过嵌套子查询来解决where中不能使用分组函数的问题

#### from中的子查询：

from后面的子查询，可以将子查询的查询结果当做一张临时表。

~~~sql
select 
	t.*, s.grade
from
	(select job,avg(sal) as avgsal from emp group by job) t
join
	salgrade s
on
	t.avgsal between s.losal and s.hisal;
~~~

#### select中的子查询：

~~~sql
select 
	e.ename,e.deptno,(select d.dname from dept d where e.deptno = d.deptno) as dname 
from 
	emp e;
~~~

对于select后面的子查询来说，这个子查询只能一次返回1条结果，多于1条，就报错了。这与select的运行机制有关：select是一行一行处理的，在处理开始时有一个指针p指向虚表1（即该select对应的from所加载的表格）第一个元素，此时再有嵌套select时，就先加载虚表2，指针q指向虚表2的第一个元素。如果该嵌套子查询的判断条件中有虚表1的元素，因为指针p在q处理完之前不发生移动，所以该元素在此次子查询中恒定不变。等到指针q遍历完需报表2中的所有元素，则将结果返回。p指针处理完一行，接收子查询的**唯一的一行**，将其作为查询结果与该行的查询结果拼接在一起并返回，接着指针p向下一个元素移动，继续发生上述过程。如果子查询中没有虚表1中的元素，则虚表2直接遍历完所有然后返回结果。即主查询的一行最多只能接收子查询的单行结果（子查询只能返回单行结果）

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