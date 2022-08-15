# 1、简介

## 1.1 何为Mybatis

- MyBatis 是一款优秀的**持久层框架**
- 它支持自定义 SQL、存储过程以及高级映射
- MyBatis 免除了几乎所有的 JDBC 代码以及设置参数和获取结果集的工作
- MyBatis 可以通过简单的 XML 或注解来配置和映射原始类型、接口和 Java POJO（Plain Old Java Objects，普通老式 Java 对象）为数据库中的记录
- MyBatis 本是apache的一个[开源项目](https://baike.baidu.com/item/开源项目/3406069)iBatis, 2010年这个[项目](https://baike.baidu.com/item/项目/477803)由apache software foundation 迁移到了[google code](https://baike.baidu.com/item/google code/2346604)，并且改名为MyBatis 。
- 2013年11月迁移到[Github](https://baike.baidu.com/item/Github/10145341)。

## 1.2 获取Mybatis

- maven仓库

	~~~xml
	<dependency>
	    <groupId>org.junit.jupiter</groupId>
	    <artifactId>junit-jupiter</artifactId>
	    <version>5.9.0</version>
	    <scope>test</scope>
	</dependency>
	~~~

- Github：https://github.com/mybatis/mybatis-3

- 中文文档：https://mybatis.org/mybatis-3/zh/index.html

## 1.3 持久化

数据持久化

- 持久化就是将程序的数据在持久状态和瞬时状态转化的过程
- 内存：**断电即失**
- 数据库(Jdbc)，io文件持久化。
- 生活：冷藏.罐头。

**为什么需要持久化？**

- 有一些对象，不能让它丢掉
- 内存太贵了

## 1.4 持久层

Dao层、Service层、Controller层······

- 完成持久化工作的代码块
- 层界限十分明显

## 1.5 Mybatis的作用

帮助程序员将数据存入到数据库中

- 方便
- 传统的JDBC代码太复杂了。简化。框架。自动化
- 不用Mybatis也可以。更容易上手
- 优点：
	- 简单易学
	- 灵活
	- sql和代码的分离，提高了可维护性
	- 提供映射标签，支持对象与数据库的orm字段关系映射
	- 提供对象关系映射标签，支持对象关系组建维护
	- 提供xml标签，支持编写动态sql

# 2、搭建第一个Mybatis程序

步骤：配置环境 --\> 导入Mybatis --\> 编写代码 --\> 测试

## 2.1 配置环境

### 2.1.1 搭建数据库

~~~sql
CREATE DATABASE `newDatabase`;

USE `newDatabase`;

CREATE TABLE user (
	id	INT(20) NOT NULL PRIMARY KEY,
    name	VARCHAR(30) DEFAULT NULL,
    pwd	VARCHAR(30) DEFAULT NULL
)ENGINE=INNODB DEFAULT CHARSET=utf8;

INSERT INTO `user` VALUES
    (1,'张三','123')，
    (2,'李四','123456')，
    (3,'王五','123456789')；
~~~

### 2.1.2 导入Maven依赖

~~~xml
<dependencies>
    <!--该依赖是为了解决出现slf4j报错而导入的-->
    <dependency>
        <groupId>org.slf4j</groupId>
        <artifactId>slf4j-simple</artifactId>
        <version>1.7.25</version>
        <scope>compile</scope>
    </dependency>
    <!--导入junit单元测试-->
    <dependency>
        <groupId>org.junit.jupiter</groupId>
        <artifactId>junit-jupiter</artifactId>
        <version>5.9.0</version>
        <scope>test</scope>
    </dependency>
    <!--导入mysql驱动依赖-->
    <!-- https://mvnrepository.com/artifact/mysql/mysql-connector-java -->
    <dependency>
        <groupId>mysql</groupId>
        <artifactId>mysql-connector-java</artifactId>
        <version>8.0.29</version>
    </dependency>
    <!--导入mybatis依赖-->
    <!-- https://mvnrepository.com/artifact/org.mybatis/mybatis -->
    <dependency>
        <groupId>org.mybatis</groupId>
        <artifactId>mybatis</artifactId>
        <version>3.5.6</version>
    </dependency>
</dependencies>
~~~

## 2.2 编写模块

### 2.2.1 编写Mybatis的核心配置文件

在resource包下编写此mybatis-config.xml：

~~~xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <environments default="development">
        <environment id="development">
            <transactionManager type="JDBC"/>
            <dataSource type="POOLED">
                <property name="driver" value="com.mysql.cj.jdbc.Driver"/>
                <!--这里的文字编码一定要设置，否则中文一定会乱码-->
                <property name="url"
                          value="jdbc:mysql://localhost:3306/mysql?useSSL=false&amp;useUnicode=true&amp;characterEncoding=UTF-8"/>
                <property name="username" value="root"/>
                <property name="password" value="password"/>
            </dataSource>
        </environment>
    </environments>
    <!--注册对应的UserMapper，此步必不可少-->
    <mappers>
        <mapper resource="com/kuang/dao/UserMapper.xml"/>
    </mappers>
</configuration>
~~~

编写Mybatis工具类（MybatisUtils.java）：

~~~java
//sqlSessionFactory --> sqlSession
public class MybatisUtils {
    private static SqlSessionFactory sqlSessionFactory;
    static{
        try {
            //使用Mybatis第一步：获取sqlSessionFactory对象
            String resource = "mybatis-config.xml";
            InputStream inputStream = Resources.getResourceAsStream(resource);
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    //既然有了 SqlSessionFactory，顾名思义，我们就可以从中获得 SqlSession 的实例了。
    // SqlSession 完全包含了面向数据库执行 SQL 命令所需的所有方法。
    public static SqlSession getSqlSession(){
        return sqlSessionFactory.openSession();
    }
}
~~~

## 2.3 编写代码

### 2.3.1 实体类

~~~java
public class User {
    //成员变量的名字要与mysql查询表中的字段名一致
    private String name;
    private String pwd;
    private int id;

    public User(String name, String pwd, int id) {
        this.name = name;
        this.pwd = pwd;
        this.id = id;
    }
    //getter 和 setter
    //toSring方法
}
~~~

### 2.3.2 Dao接口

~~~java
public interface UserMapper {
    List<User> getUserList();
}
~~~

### 2.3.3 接口实现类

由原来的UserDaoImpl，使用myatis后则转变为一个Mapper配置文件

~~~xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">

<!--namespace绑定一个对应的Dao/Mapper接口-->
<mapper namespace="zh.learn.pojo.UserMapper">
    <!--select查询语句，这里的id要与接口中的方法对应，resultType是返回值类型，parameterType是参数类型-->
    <select id="getUserList" resultType="zh.learn.pojo.User">
        select id, name, pwd from newDatabase.user;
    </select>
</mapper>
~~~

## 2.4 测试

### 2.4.1 测试类

```java
public class UserMapperTest {
    @Test
    public void test1() {
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        //获取接口的class类，将接口与sql查询结合在一起
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        List<User> user_list = mapper.getUserList();
        for (User user : user_list) {
            System.out.println(user);
        }
        //要关闭资源，否则有可能会出现某种错误
        sqlSession.close();
    }
}
```

注意点：

org.apache.ibatis.binding.BindingException: Type interface com.dz.dao.UserDao is not known to the MapperRegistry.

**MapperRegistry**是什么？

核心配置文件中注册 mappers（见上文mybatis-config.xml的配置）

在maven（prom.xml）中应尽量添加如下build，以避免文件目录识别错误

~~~xml
<build>
    <resources>
        <resource>
            <directory>src/main/resources</directory>
            <includes>
                <include>**/*.properties</include>
                <include>**/*.xml</include>
            </includes>
            <filtering>true</filtering>
        </resource>
        <resource>
            <directory>src/main/java</directory>
            <includes>
                <include>**/*.properties</include>
                <include>**/*.xml</include>
            </includes>
            <filtering>true</filtering>
        </resource>
    </resources>
</build>
~~~

可能遇到的问题：

1. 配置文件没有注册
2. 绑定接口错误
3. 方法名不对
4. 返回类型不对
5. Maven导出资源问题

# 3、CRUD

## 3.1 namespqce

namespqce的值要与dao或mapper中接口的包名一致

## 3.2 select

查询语句

~~~xml
<select id="getUserList" resultType="zh.learn.pojo.User">
    select id, name, pwd from newDatabase.user;
</select>
~~~

该条位于mapper中，其中的：

- id：即namespace对应接口下对应的方法名
- resultType：sql执行语句的返回值，也是id对应方法的返回值
- parameterType：id对应方法的参数

<img src="Pictures/返回值的别名.png" title="返回值的别名" style="zoom:150%;" />

## 3.3 add、delete、update

增删改同前面的查询，只是要记得提交事务，不然更改无法生效！

~~~java
//如果使用此方法则无需提交
public static SqlSession getSqlSession(){
        return sqlSessionFactory.openSession(true);// 自动提交
    }
// 自动提交，不需要显示写SqlSession.commit();
~~~

UserMapper.xml

~~~xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">

<mapper namespace="zh.learn.pojo.UserMapper">
    <select id="getUserList" resultType="zh.learn.pojo.User">
        select id, name, pwd from newDatabase.user;
    </select>

    <select id="getUserByID" resultType="zh.learn.pojo.User" parameterType="_int">
        select id, name, pwd from newDatabase.user where id = #{id};
    </select>

    <insert id="insertUser" parameterType="zh.learn.pojo.User">
        insert into newDatabase.user(id, name, pwd) VALUES (#{id},#{name},#{pwd});
    </insert>

    <delete id="deleteByID" parameterType="_int">
        delete from newDatabase.user where id = #{id};
    </delete>

    <update id="updateUser" parameterType="zh.learn.pojo.User">
        update newDatabase.user set name = #{name}, pwd = #{pwd} where id = #{id};
    </update>
</mapper>
~~~

UserMapper.java

~~~java
public interface UserMapper {
    List<User> getUserList();

    User getUserByID(int id);

    void insertUser(User user);

    void deleteByID(int id);

    void updateUser(User user);
}
~~~

UserMapperTest.java

~~~java
public class UserMapperTest {
    @Test
    public void test1() {
        SqlSession sqlSession = MybatisUtils.getSqlSession();

        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        List<User> user_list = mapper.getUserList();

        for (User user : user_list) {
            System.out.println(user);
        }

        sqlSession.close();
    }

    @Test
    public void selectTest2() {
        SqlSession sqlSession = null;
        try {
            sqlSession = MybatisUtils.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            User user = mapper.getUserByID(1);
            System.out.println(user);
        } finally {
            if (sqlSession != null)
                sqlSession.close();
        }
    }

    @Test
    public void insertTest() {
        SqlSession sqlSession = null;
        try {
            sqlSession = MybatisUtils.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            mapper.insertUser(new User("王晓娟","86643215", 4));
            System.out.println("增添成功！");
            sqlSession.commit();
        } finally {
            if (sqlSession != null)
                sqlSession.close();
        }
    }

    @Test
    public void DeleteTest() {
        SqlSession sqlSession = null;
        try {
            sqlSession = MybatisUtils.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            mapper.deleteByID(4);
            sqlSession.commit();
        } finally {
            if (sqlSession != null)
                sqlSession.close();
        }
    }

    @Test
    public void updateUserTest() {
        SqlSession sqlSession = null;
        try {
            sqlSession = MybatisUtils.getSqlSession();
            UserMapper mapper = sqlSession.getMapper(UserMapper.class);
            mapper.updateUser(new User("韩美美","772310576",4));
            System.out.println("更新成功！");
            sqlSession.commit();
        } finally {
            if (sqlSession != null)
                sqlSession.close();
        }
    }
}
~~~

## 3.4 万能Map

> 假设，我们的实体类，或者数据库中的表，字段或者参数过多，我们应该考虑使用Map。
>
> 不然需要new 对象，对面的属性就是很多，会比较麻烦。

UserMapper接口

```
public void addUser2(Map<String,Object> map);
```

UserMapper.xml

```xml
<!-- 传递map的key-->
<insert id="addUser2" parameterType="map">
    insert into user (id,name,password) values (#{userid},#{username},#{userpassword})
</insert>
 @Test
    public void test3(){
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
        HashMap<String, Object> map = new HashMap<String, Object>();
        map.put("userid",4);
        map.put("username","王虎");
        map.put("userpassword",789);
        
        mapper.addUser2(map);
        sqlSession.commit();//提交事务
        sqlSession.close();
    }
```

>Map传递参数：在sql中取出key即可！ eg：【parameter=“map”】
>
>对象传递参数：在sql中取出对象的属性即可！ 【parameter=“pojo.User”】
>
>只有一个基本类型参数的情况下：直接在sql中取到
>
>多个参数用Map , **或者注解！**

## 3.5 模糊查询

原来的sql：

```xml
SELECT * from `user` where name like '22%'
  <update id="update" parameterType="pojo.User" flushCache="false">
        update user set name = #{name} where id = #{id}
    </update>
//通配符% %（表示任意）
    List<User> queryLike(@Param("name") String name);
```

通配符可以直接输入到测试类中，转化的通配符会被自动识别。在UserMapper.xml中就应该把传入参数的类型写死，这是为了以防用户输入不合规矩的字符串。

# 4、配置解析

## 4.1 mybatis-config.xml

MyBatis 的配置文件包含了会深深影响 MyBatis 行为的设置和属性信息。 配置文档的顶层结构如下：

- configuration（配置）
	- [properties（属性）](https://mybatis.org/mybatis-3/zh/configuration.html#properties)
	- [settings（设置）](https://mybatis.org/mybatis-3/zh/configuration.html#settings)
	- [typeAliases（类型别名）](https://mybatis.org/mybatis-3/zh/configuration.html#typeAliases)
	- [typeHandlers（类型处理器）](https://mybatis.org/mybatis-3/zh/configuration.html#typeHandlers)
	- [objectFactory（对象工厂）](https://mybatis.org/mybatis-3/zh/configuration.html#objectFactory)
	- [plugins（插件）](https://mybatis.org/mybatis-3/zh/configuration.html#plugins)
	- environments（环境配置）
		- environment（环境变量）
			- transactionManager（事务管理器）
			- dataSource（数据源）
	- [databaseIdProvider（数据库厂商标识）](https://mybatis.org/mybatis-3/zh/configuration.html#databaseIdProvider)
	- mappers（映射器）

## 4.2 environmets（环境配置）

在标签environments中可以配置多个environment，通过设置environments中default参数值（其值为environment的ID）来指定所要选择的环境。所以mybatis可以配置多种环境

**不过要记住：尽管可以配置多个环境，但每个SqlSessionFactory实例只能选择一种环境**

Mybatis默认的事务管理器就是JDBC，使用连接池：POOLED

### sqlSession

在java测试类中，我们使用sqlSessionFactoryBuilder这个类来生成sqlSessionFactory类，一旦sqlSessionFactory生成完毕，sqlSessionFactoryBuilder这个实例就失去了作用，可以被抛弃。

相反，sqlSessionFactory可以一直存在，**没有任何理由丢弃它或重新创建另一个实例**。其可以被想象成数据库连接池，因此SqlSessionFactory 的最佳作用域是应用作用域，也正是因为如此，在程序中反复、多次创建工厂类实例是一种不好的行为。它用来提供sqlSession实例，其可以创建多个SqlSession实例。最简单的就是使用单例模式或是静态单例模式

**SqlSession**是连接到数据库连接池的一个请求，但是它不是线程安全的，不能被共享，所以它的最佳的作用域是请求或方法作用域。一个SqlSession可以创建多个Mapper实例，一个Mapper就代表一个业务，一个SqlSession可以当作一台机器，该机器使用完后就应该被关闭，送回工厂进行回收。

## 4.3 properties（属性）

这些属性可以在外部进行配置，并可以进行动态替换。你既可以在典型的 Java 属性文件中配置这些属性，也可以在 properties 元素的子元素中设置。

设置好的属性可以在整个配置文件中用来替换需要动态配置的属性值。

db.properties：

~~~properties
driver=com.mysql.cj.jdbc.Driver
url=jdbc:mysql://localhost:3306/mysql?useSSL=false&amp;useUnicode=true&amp;characterEncoding=UTF-8
username=root
password=root
~~~

mybatis-config.xml的配置：

![](Pictures/mybatis-config配置的顺序.png "mybatis-config配置的顺序")

上图为在配置中个属性的顺序（必须按照这个顺序来！）

~~~xml
<!--引入外部配置文件-->
<properties resource="db.properties"/>
~~~

- 可以直接引入外部文件
- 可以在其中增加一些属性配置
- 如果两个文件有同一个字段，首先读取在properties元素体内指定的属性，然后根据 properties 元素中的 resource 属性读取类路径下属性文件，或根据 url 属性指定的路径读取属性文件，并覆盖之前读取过的同名属性，最后读取作为方法参数传递的属性，并覆盖之前读取过的同名属性（优先使用外部配置文件的）

## 4.4 typeAliases（类型别名）

- 类型别名是为Java类型设置一个短的名字
- 存在的意义仅在于用来减少类完全限定名的冗余

~~~xml
<!--可以给实体类起别名-->
<typeAliases>
    <typeAlias type="com.dz.pojo.User" alias="User"></typeAlias>
</typeAliases>
~~~

也可以指定一个包名，MyBatis 会在包名下面搜索需要的 Java Bean，比如：

扫描实体类的包，它默认别名就为这个类的类名（首字母小写）

```xml
<!--可以给实体类起别名-->
<typeAliases>
    <package name="com.dz.pojo"/>
</typeAliases>
```

在实体类比较少的时候，使用第一种方式

如果实体类较多，使用第二种方式

第一种可以自定义别名，第二种不行，如果非要改，需要在实体类上增加注解

```java
@Alias("user")
public class User {}
```

**这里不推荐起别名的方式，原因是当你程序报错时，你要去寻找具体报错的包/类时，会相当麻烦**

## 4.5 setting（设置）

这是 MyBatis 中极为重要的调整设置，它们会改变 MyBatis 的运行时行为

![](Pictures/setting设置.png "setting设置")

## 4.6、其他设置

- [typeHandlers（类型处理器）](https://mybatis.org/mybatis-3/zh/configuration.html#typeHandlers)
- [objectFactory（对象工厂）](https://mybatis.org/mybatis-3/zh/configuration.html#objectFactory)
- plugins插件
	- mybatis-generator-core
	- mybatis-plus
	- 通用mapper

## 4.7、映射器（mappers）

这个映射器就是为了解决我们实体类中属性名与Mysql中字段名不匹配的问题

MapperRegistry：注册绑定我们的Mapper文件

方式一：【推荐使用】

```xml
<mappers>
	<mapper resource="com/dz/dao/UserMapper.xml"></mapper>
</mappers>
```

方式二：使用class文件绑定注册

```xml
<mappers>
	<mapper class="com.dz.dao.UserMapper"></mapper>
</mappers>
```

方式二注意点：

- 接口和他的Mapper配置文件必须同名
- 接口和他的Mapper配置文件必须在同一包下

方式三：使用扫描包进行注入绑定

```xml
<mappers>
	<package name="com.dz.dao"></package>
</mappers>
```

方式三注意点：

- 接口和他的Mapper配置文件必须同名
- 接口和他的Mapper配置文件必须在同一包下
