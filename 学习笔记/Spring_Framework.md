# 1、Spring

## 1.1、简介：

- 2002年，首次推出了spring框架的雏形：interface21框架

- spring框架基于interface21，经过重新开发，并不断丰富其内涵，与2004年发布了1.0正式版
- spring framework的创始人Rod Johnson，是悉尼大学的音乐学博士
- spring的理念是：使现有的技术更加容易使用，本身是一个大杂烩，融合了现有的技术框架
- SSH：Struct2 + Spring + Hibernate
- SSM：SpringMvc + Spring + Mybatis

其官网为：https:/lspring.io/projects/spring-framework#overview

下载地址：http://repo.spring.io/release/orglspringframework/spring

GitHub开源地址：https:/lgithub.comlspring-projects/spring-framework

在maven项目中的配置代码：

~~~xml
<dependencies>
        <!-- https://mvnrepository.com/artifact/org.springframework/spring-webmvc -->
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-webmvc</artifactId>
            <version>5.3.22</version>
        </dependency>
    </dependencies>
~~~

上述配置可以一键设置，当然也可以选择jdbc的设置。

~~~xml
<dependencies>
        <!-- https://mvnrepository.com/artifact/org.springframework/spring-webmvc -->
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-jdbc</artifactId>
            <version>5.3.22</version>
        </dependency>
    </dependencies>
~~~

## 1.2、优点：

- Spring是一个开源的免费框架（容器）
- Srping是一个轻量的、非入寝式的框架（不会对别的项目产生影响）
- 控制反转（IOC），面向切面编程（AOP）
- 支持事务的处理，对框架整合的支持

一句话：Spring就是一个轻量的控制反转（IOC）和面向切面编程（AOP）的框架

# 2、IOC理论推导

1. UserDao 接口
2. UserDaoImpl 接口实现类
3. UserService 业务接口
4. UserServiceimpl 业务接口实现类

在之前的开发中，用户的需求可能会影响我们原来的代码，我们需要根据用户的需求去修改源代码。如果程序代码量十分庞大，那么修改一次的成本、代价是十分昂贵的。

然而，当我们转而去使用set接口时，会发现产生了革命性的变化！

~~~java
//利用set方法动态实现值的注入
public void setUserDao(Userdao userdao){
    this.userdao = userdao;
}
~~~

- 之前，程序是主动创建对象，控制权在程序员手上
- 使用了set方法进行注入，程序不再具有主动性，而是变成了被动接收对象

这种思想，从本质上解决了问题，使得我们程序员不用再去管理对象的创建！这也使得系统的耦合度大大降低，可以更加专注在业务的实现上。这就是IOC的原型。

## IOC本质：

控制反转IoC（Inversion of Control），是一种设计思想，DI（依赖注入）是实现IoC的一种方式。在没有IoC的程序中，我们使用面向对象编程，对象的创建与对象间的依赖完全硬解码在程序中，对象的创建由程序自己控制，控制反转后将对象的创建转移给第三方。个人所谓的控制反转就是：获得依赖对象的方式发生了反转。

从用xml的方式配置bean的时候，bean的定义信息是与“实现”相分离的。而采用注解的方式可以把两者结合在一起。bean的定义信息直接以注解的形式定义在实现类中，从而达到了零配置的目的。

**控制反转是一种通过描述（XML或注解）并通过第三方去生产或获取特定对象的方式。在Spring中实现控制反转的是loC容器，其实现方法是依赖注入(Dependency Injection,Dl)。**

# 3、IOC创建对象方式

IOC对象被调用后，会返回一个动态对象（我们所设计的），这个对象就是默认调用了其类中的无参构造方法。

## beans.xml基本格式：

~~~xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">

    <!--使用spring来创建对象，在spring中这些都被称为bean-->
    <bean>
    </bean>

</beans>
~~~

我们只需按要求添加bean即可，模板来自于官网。

## 有参构造：

1. 通过下标赋值：

	~~~xml
	<bean id="exampleBean" class="examples.ExampleBean">
	    <constructor-arg index="0" value="7500"/>
	    <constructor-arg index="1" value="test"/>
	</bean>
	~~~

	

2. 通过类型创建：

	~~~xml
	<bean id="emxapleBean" class="example.ExampleBean">
	    <constructor-arg type="int" value="759"/>
	    <constructor-arg typr="java.lang.String" value="Hello"/>
	</bean>
	~~~

	不推荐这种创建方式，对于有些拥有多个相同类型的形参的构造方法不适用

3. 参数名：

	~~~xml
	<bean id="exampleBean" class="examples.ExampleBean">
	    <constructor-arg name="age" value="22"/>
	</bean>
	~~~

在配置文件（.xml）被加载的时候，文件中管理的所有bean都会被初始化（实例化），多个相同类的对象，在内存中只有一个（类似于单例模式）

# 4、Spring配置

## 4.1、别名：

```xml
<!--如果添加了别名，我们也可以通过别名来获取对象-->
<alias name="user" alias="userNew"/>
```

## 4.2、Bean的配置：

~~~xml
<!--id：bean的唯一标识符，也就是我们学的对象名
class：bean所对应的全限定名，即：包名+类名
name：也是别名，可以同时取多个别名（全部包括在双引号中，可以使用逗号、空格、分号等分隔）
-->
<bean id="userT" class="examples.ExampleBean" name="user2 u2,u3;u4">
    <property name="age" value="22"/>
</bean>
~~~

## 4.3、import导入：

如果这个spring项目有多个人在开发，我们会使用不同的beans.xml文件来配置每个人不同的需求，最后完成的时候，我们就会用import把这些文件全部导入到一个总的文件中。这个总的文件我们一般命名为：*applicationContext.xml*

~~~xml
<import resource="beans.xml"/>
<import resource="beans1.xml"/>
~~~

# 5、依赖注入（DI）

## 5.1、构造器注入：

该种方式已经在第三章（IOC的几种创建对象的方式）中详述。

## 5.2、Set方式注入（重要）：

- 依赖注入（Set注入）：
	- 依赖：bean对象的创建依赖于容器
	- 注入：bean对象中的所有属性，由容器来注入

【环境搭建】

1. 复杂类型
2. 真实测试环境

实体类：

~~~java
package com.learn;
/**
 * @author ritia
 * {@code @create} 2022-08-11
 **/

public class Address {
    private String address;

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Address{" +
                "address='" + address + '\'' +
                '}';
    }
}
~~~

~~~java
package com.learn;

import java.util.*;

/**
 * @author ritia
 * &#064;create  2022-08-11
 **/

public class Student {
    private String name;
    private Address address;
    private String[] books;
    private List<String> hobbies;
    private Map<String, String> card;
    private Set<String> games;
    private String wife;
    private Properties info;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public String[] getBooks() {
        return books;
    }

    public void setBooks(String[] books) {
        this.books = books;
    }

    public List<String> getHobbies() {
        return hobbies;
    }

    public void setHobbies(List<String> hobbies) {
        this.hobbies = hobbies;
    }

    public Map<String, String> getCard() {
        return card;
    }

    public void setCard(Map<String, String> card) {
        this.card = card;
    }

    public Set<String> getGames() {
        return games;
    }

    public void setGames(Set<String> games) {
        this.games = games;
    }

    public String getWife() {
        return wife;
    }

    public void setWife(String wife) {
        this.wife = wife;
    }

    public Properties getInfo() {
        return info;
    }

    public void setInfo(Properties info) {
        this.info = info;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", address=" + address +
                ", books=" + Arrays.toString(books) +
                ", hobbies=" + hobbies +
                ", card=" + card +
                ", games=" + games +
                ", wife='" + wife + '\'' +
                ", info=" + info +
                '}';
    }
}
~~~

测试类

~~~java
package com.learn;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @author ritia
 * &#064;create  2022-08-11
 **/

public class MyTest {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");
        Object hello = context.getBean("student");
        System.out.println(hello);
    }
}
~~~

Spring注入（通过XML）

~~~xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">

    <!--使用spring来创建对象，在spring中这些都被称为bean-->
    <bean id="address" class="com.learn.Address">
        <property name="address" value="泉州"/>
    </bean>

    <bean id="student" class="com.learn.Student">
        <!--第一种，普通值注入-->
        <property name="name" value="zh"/>
        <!--第二种，bean注入-->
        <property name="address" ref="address"/>
        <!--第三种，数组注入-->
        <property name="books">
            <array>
                <value>红楼梦</value>
                <value>西游记</value>
                <value>水浒传</value>
                <value>三国演义</value>
            </array>
        </property>
        <!--List注入-->
        <property name="hobbies">
            <list>
                <value>听歌</value>
                <value>敲代码</value>
                <value>看电视</value>
            </list>
        </property>
        <!--Map注入-->
        <property name="card">
            <map>
                <entry key="身份证" value="1234567890"/>
                <entry key="银行卡" value="1234345234"/>
                <entry key="" value=""/>
            </map>
        </property>
        <!--Set注入-->
        <property name="games">
            <set>
                <value>王者</value>
                <value>LoL</value>
                <value>CoC</value>
            </set>
        </property>
        <!--Properties注入-->
        <property name="info">
            <props>
                <prop key="性别">男</prop>
                <prop key="学号">29</prop>
                <prop key="年龄">22</prop>
            </props>
        </property>
        <!--空指针注入-->
        <property name="wife">
            <null/>
        </property>
    </bean>

</beans>
~~~

## 5.3、扩展方式注入：

### 5.3.1 通过P命名空间方式注入：

所谓的P命名空间的方式注入也即代替了properties的复杂形式。

范例：

~~~xml
//需要在开头导入此依赖
xmlns:p="http://www.springframework.org/schema/p"

<bean name="john-classic" class="com.example.Person">
    <property name="name" value="John Doe"/>
    <property name="spouse" ref="jane"/>
</bean>

<bean name="john-modern"
      class="com.example.Person"
      p:name="John Doe"
      p:spouse-ref="jane"/>

<bean name="jane" class="com.example.Person">
    <property name="name" value="Jane Doe"/>
</bean>
~~~

### 5.3.2 通过C命名空间方式注入：

所谓的C命名空间方式也就是调用构造器，主要是调用有参构造器，当然前提也就是在所使用的对象的类中要有对应的构造器。

范例：

~~~xml
<!--开头需要导入此依赖-->
xmlns:c="http://www.springframework.org/schema/c"

<bean id="beanTwo" class="x.y.ThingTwo"/>
<bean id="beanThree" class="x.y.ThingThree"/>

<!-- traditional declaration with optional argument names -->
<bean id="beanOne" class="x.y.ThingOne">
    <constructor-arg name="thingTwo" ref="beanTwo"/>
    <constructor-arg name="thingThree" ref="beanThree"/>
    <constructor-arg name="email" value="something@somewhere.com"/>
</bean>

<!-- c-namespace declaration with argument names -->
<bean id="beanOne" class="x.y.ThingOne" c:thingTwo-ref="beanTwo"
      c:thingThree-ref="beanThree" c:email="something@somewhere.com"/>

<!--也可以采用索引的方式-->
<bean id="beanOne" class="x.y.ThingOne" c:_0-ref="beanTwo" c:_1-ref="beanThree"
    c:_2="something@somewhere.com"/>
~~~

## 5.4、Bean的作用域：

![image-20220811172800512](Pictures/Bean的作用域.png "Bean的作用域")

### 5.4.1 单例模式（Spring默认机制）：

~~~xml
1 <bean id="user2" class="com.nty.pojo.user" c:age="18" c:name="狂神" scope="sing1eton" />
~~~

只有一个单例 bean 的共享实例被管理，并且所有对具有一个或多个与该 bean 定义匹配的 ID 的 bean 的请求都会导致 Spring 容器返回一个特定的 bean 实例（多个对象共享内存中的同一个实例）

### 5.4.2 原型模式：

每次从容器中get的时候，都会产生一个新对象!

~~~xml
1<bean id="accountservice" class="com.something.Defau1tAccountservice" scope="prototype" />
~~~

### 5.4.3 其余的模式：

其余的request、session、 application、这些个只能在web开发中使用到!

# 6、Bean的自动装配

- 自动装配是Spring满足Bean依赖的一种方式
- Spring会自动在上下文中寻找，并自动给Bean装配属性

在Spring中有三种装配方式：

1. 在xml中显示的配置
2. 在Java中显示配置
3. 隐式的自动装配bean【重要！】

## 6.1 原始代码实现：

一个人有两只宠物，一只猫，一只狗，两只宠物都会叫。

## 6.2 byName自动装配：

~~~xml
<bean id="cat" class="com.learn.Cat"/>
<bean id="dog" class="com.learn.Dog"/>

<bean id="person" class="com.learn.People" autowire="byName"
      p:name="ZH"/>
~~~

## 6.3 byType自动装配：

~~~xml
<bean id="cat" class="com.learn.Cat"/>
<bean id="dog" class="com.learn.Dog"/>

<bean id="person" class="com.learn.People" autowire="byType"
      p:name="ZH"/>
~~~

### 两种装配方式的比较：

- 使用byName自动装配，Spring会获取set方法中的变量名，然后在xml配置的上下文中寻找是否有与变量匹配的beanID，Spring能够自动识别大小写，但不支持有前后缀及其他的更改

- 使用byType自动装配，Spring会在xml中寻找与自动注入的属性相匹配的bean的类型。

	但是也要注意一个类型只能对应一个bean，要保证需要获取的类型唯一。好处是此时可以不写需要获取的bean的ID

## 6.4 使用注解自动装配：

