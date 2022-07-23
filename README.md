# Java操作表：

`arr.length` *arr*为数组名，此操作是为了获取数组的长度
`System.out.print()` 输出内容，但是不换行
`System.out.println()` 输出内容，且换行
*psvm* + *Tab*键：快速生成main方法
*sout* + *Tab*键：快速生成输出函数
*Alt* + *Insert*键：快速生成各种基本方法
*Ctrl* + *B*键：选中方法后，使用此快捷键可以查看该方法的源码

## 对于想要直接结束方法，有两种方式：

1.`System.exit(0)`; 退出JVM(即关机)  
2.`return` `~~~`; 直接退出方法，将控制权交给调用方  
`int[] arr = new int[5];`   
`int`: 表明该数组的元素为int类型  
`[]`: 表明这是一个数组  
`arr`: 表明这是该数组的名称  
`new`: 为该数组分配空间（堆内存）  

## 位运算
| & | &#124; | ~ | ^ | << | >> |
|---|---|---|---|---|---|
| 与 | 或 | 非 | 异或 | 左移 | 右移 |
### 范例：
A：0011 1001
B：0000 1101
| A&B | A&#124;B | ~B | A^B |
|:---:|:---:|:---:|:---:|
|0000 1001|0011 1101|1111 0010|0011 0100|

<<:  
左移符，2<<1即2扩大2的1倍。同理，右移符即缩小
2的N倍。

## 增强for循环：
Java5及以后提供了一种新的书写方式，用以简化
遍历数组元素时的繁琐内容。
```
int[] numbers = new int[]{1,2,3,4,5};
        for (int x:numbers) {
            System.out.println(x);
        }
```

## 标签
尽管goto语句没有在Java中正式得到承认，但是我
们仍然可以在break和continue中找到goto的影子。但是不建议使用。
~~~
Outer:for(int i=101;i<150;i++) {
    for(int j=2;j<i/2;j++) {
        if(i%j==0)
            continue Outer;
    }
    System.out.println(i);
}
~~~

## `System.out.println(arr)`;

实际上输出的是名为arr数组的本地计算机内存地址

## Java中的内存分配分为栈内存和堆内存：

### 栈内存：

定义在Java方法中的空间（用于储存变量名），程序（方法）执行完毕后，立即消失

### 堆内存：

定义在内存的空间，储存各个变量的实际值，在程序执行完毕后，会由垃圾回收器 在空闲时清除。即由`new`创建的空间。

## 数组的动态初始化：

指新建一个数组（已知大小），其组内元素的值由后续操作赋予 其格式为：`数据类型[] 数组名 = new 数据类型[];`

### 静态初始化：

指新建一个已知所有元素值的数组，在新建时便已确定所有元素 其格式为：`数据类型[] 变量名 = new 数据类型[] { , , ,};`

## 数组访问的问题：

-索引越界：要访问的位置超过数组的范围`ArrayIndexOutOfBoundException`
-空指针异常：访问的数组已不再指向堆内存数据（或指向为`null`），造成空指针异常 `NoPointer`
-`null`：指要访问的数据类型默认为`null`

## 稀疏数组：
### 概念：
当一个数组中存有大量重复的元素且含有少数不同元素时，可以使用稀疏数组来对原数组进行压缩，用以
节省部分存储空间。
### 原理：
|行数|原行数|原列数|原不同元素|
|---|---|---|---|
|[0]|11|11|0|
|[1]|1|2|1|
|[2]|2|3|2|

创建一个新的二元数组（固定3列）作为稀疏数组。  
新数组的第0行记录原数组的行、列数以及大量重复的元素  
第1行及其后行则记录对应不同元素所在的行、列数以及元素值

## 方法的定义和调用：

### 定义格式：

定义时须在类中定义
`public static 返回值数据类型 方法名( 数据类型 参数名, ..., ... ) {   [return 值;]   }`
同C语言的函数封装

### 调用：

在`main`方法中调用该函数

### 注意事项：

在方法的定义中不能再嵌套定义另一个新方法
返回值必须与定义相匹配

## 方法的重载：

### 特征：

方法名相同，但是方法的参数类型不同，参数数量不同
在调用的时候，java虚拟机通过参数的差异来区分方法
返回值可以相同，也可以不同。java虚拟机不要求，但若想构成重载，则必须在相同类中，在参数上有差异可区分。

## 参数的传递：

同C语言一样，基本数据类型的实参传递给形参时，方法在栈内存中拥有独立的的空间，形参的改变并不影响实参，但是若是传递数组，则传递的是数组在堆内存中的地址，方法中参数的改变会同时改变数组。

## 对象：

万物皆可为对象（看待事物的一种方式）

### 对象拥有的特性：

属性-值（与Python里字典类型的键值对相似）
行为：对象可执行的操作（是具体能做什么，而非功能）

## 类：

具有共同属性和行为的对象的集合，是Java程序的基本组成单位，也是对象的数据类型
只有先确定了类，才有对象

### 类由属性和行为组成。

#### 属性：

在类中通过成员变量来体现（类中方法外的变量）

#### 行为：

在类中通过成员方法来体现（即普通的方法去掉关键字`static`即可）

### 格式：

`public class 类名{ 数据类型 变量1； 数据类型 变量2； ······ 方法1 方法2 }`

### 实例：

类-手机 对象-小米手机/华为手机 行为：打电话、发短信

## 类的调用：

### 创建：

`类名 对象名 = new 类名();`
新建对象也有堆内存和栈内存，对象新建（即调用类）后，成员变量储存在栈内存，成员变量值储存在堆内存（赋默认值-null/0/···）

### 使用：

成员变量-对象名.变量名
成员方法-对象名.方法名()

## 内存分析：

在类中调用main方法，则JVM在栈内存中开辟一个main方法空间，随后创建新对象——类名 对象名——继续在栈内存中开辟空间 ——new 类名()——则在堆内存中开辟一个新空间（类名），随后将堆内存中该方法的
地址赋给栈内存中的对象名（注意：调用的类下的成员变量继续在堆内存中开辟空间，其值继续储存在堆内存中而非栈内存，但是其成员方法是在栈内存中开辟的，使用后清除）

## 成员变量与局部变量的区别：

### 位置不同：

成员变量在类中并在类中的方法外，局部变量在方法的声明或内部

### 内存位置不同：

成员变量在堆内存中，局部变量在栈内存中

### 生命周期不同：

成员变量跟随对象而存在，局部变量跟随方法而存在

### 4***

## private关键字:

权限修饰符，在成员变量声明时放在声明的最前面，用以表示该成员变量只能在本类 中使用，其他类/类外方法不可以直接访问和修改。故一般会在本类中设置 （set变量名）函数和（get变量名）函数用以设置变量值和获取变量值。setAge()意为
设置变量名为age的值的函数 `alt` + `insert`键可以快速引入 范例：`private int age；`

## this关键字：

修饰符，用于类的定义中。当类中成员方法内的局部变量与成员变量重名时，欲在该成员方法中使用该成员变量而又要避免局部变量覆盖成员变量的问题时，使用该修饰符。this表示当前被调用的对象，被this修饰的变量则为成员变量。
在成员方法中使用。
范例：this.age

### 函数：

用于当前类中的构造方法，应为当前构造方法的第一条语句，this(参数)中意为根据函数内的参数来调用当前类的另一构造方法。无参即本类的无参构造方法。
范例：this(age)

## 封装（Java三大特性之一）：

一般情况下对象的本质与属性都是隐藏在对象内部的，无法直接获取和访问，通过类的创建和使用新对象可达到访问内部的目的。好处就是提高了代码的复用性，同时增加了方法的安全性（`private`的使用）

## 构造方法：

### 格式：

*修饰符 类名() { }*
在类中定义

### 作用：

在声明新对象时，先执行构造函数（实际上就是在调用构造函数，有参数先传入参数，无参数就直接执行函数体
`Student p = new Student();`中的_Student()_就是构造函数

### 注意：

`Student p = new Student();`中*Student()*实际上就是Java在Student类中默认设置了构造方法，即默认在类中插入了一段public Student() { }的代码。但是如果已写了一个
带参的构造方法，就不能再像前面声明新对象，要改成`Student p = new Student(参数);`如果既想要无参声明又要带参声明，则需要在类中手动增加一段`public Student() { };`
以构成方法重载。建议以后都事先写一个无参构造方法。
可以方便的利用形参和多个重载来实现对成员变量的赋值而减省get/set方法

## 标准类：

-1.用private修饰成员变量
-2.提供一个无参构造方法提供多个带有多个参数的构造方法
-3.提供每个成员变量的get/set函数 提供一个显示对象信息的show()函数
-4.两种赋值方式 函数赋值和构造方法赋值

## API:

应用程序编程接口(Application Programming Interface)
Java API就是指提供各种功能的Java类，这些类将底层封装起来，并提供各种接口，我们只需要了解这些类的使用即可
如果有需要可以查看官方提供的API文档，内有所有官方类的解释，可以查看类的构造方法、成员方法。

## String类：

主要有四种构造方法：无参（后续赋值）、字节数组（转化）、字符数组（转化）和无参直接赋值。
通常在比较两个字符串对象时，直接用“==”来时，比较的是两个对象在堆内存中的地址，要想比较两个对象的内容时，String类提供了一个成员方法`equals()`，例：`s1.equals(s2)`，返回布尔值。
如果要对String类的对象进行多次、大量的增减操作，建议使用StringBuilder类的append
/insert方法。

## StringBuilder类：

与String类的区别是：String类的内容一经赋值就无法更改（所谓的加减操作只是在堆内存中在原内容
的基础上再创建一个新的字符串常量，再将这个新常量的地址赋给栈内存中的String对象），在进行大量更改操作时会占用大量内存而又耗时，故开发了新的类：StringBuilder类。可以将该对象看作一个
容器，装着字符串，该字符串允许自由更改。

### append()方法：

对StringBuilder对象进行增添操作，操作执行完毕后该对象即已被增添，并返回该对象。根据此特性，要执行已知的多个操作时可以进行链式操作，例：`s.append() .append().append`等等。

## String与StringBuilder相互转化：

### String到StringBuilder：

构造方法：`public StringBuilder(String s);`

### StringBuilder到String：

成员方法：`public String toString();`

## 集合：

在编程应用的时候，有时固定大小的数组（静态）不能适应可变的数量（对象数可变、属性数可变...），于是
集合应运而生，其最大的特点就是空间大小可变。

### ArrayList<E>类：

E：指泛型，需要什么类型，E就是那个类型(String、Char、int...)

#### 添加方法：

无参：`public ArrayList()` 创建一个空集合
有参：`public boolean add(E e)` 将指定元素e添加到末尾
`public void add(int index, E element)`
在指定位置插入元素

#### 成员方法：

`public boolean remove(Object o)` 删除指定元素，并判断是否成功
`public E remove(int index)` 删除指定位置的元素，并返回被删除的元素
`public E set(int index, E element)` 修改指定位置的元素，返回被修改的元素
`public E get(int index)` 返回被索引的元素
`public int size()` 返回集合的大小

## 继承：

### 格式：

*public class 子类 extend 父类 { }*

### 意义：

父类也称为基类，是某些类的相同特征的集合
子类也被称为泛类，继承了父类的一切，又能独立设置自己的特有属性，父类的一切，都被
子类包含，都能被子类调用。这种方式提高了代码的复用性，也使得代码的维护更加容易（修改父类即可），提高了编程的效率。

### 使用注意：

存在多重继承的情况下，在子类中要想访问一个变量，首先编译器会在子类中
寻找，其次在父类中寻找，如果未果，编译器则不会继续在父类的父类中寻找，而是报错。

### Super关键字：

如果父类、子类以及子类成员方法中均有声明相同的变量名时，成员方法优先使用该
变量在该方法内存中的值。要想使用子类中方法外的变量，要使用关键字this，同理，要想使用父类中子类外的同名变量，应使用关键字super，用法同this。
super(参数)同this(参数)，应为本构造方法的第一条语句，意为根据参数调用父类中的构造方法。无参即为调用父类中的无参构造方法。若无特别声明，子类中所有构造方法编译器都会默认视第一条语句为super()（为了让子类能够使用和继承父类中的
数据，也应对父类作初始化）。可以认为添加super(参数)来控制。

## `instanceof`：
判断两边是否为继承关系。该关键字的前面为实例对象，后边为类名。  
记住要判断的两个应要具有一定的关系。要么具有继承关系，要么两者拥有共同的父类（父类的父类并不考虑）

## 方法重写：

### 概述：

子类中出现了和父类中一模一样的方法声明。

### 应用：

当子类需要父类的功能，而功能主体子类有自己特有的内容时，可以重写父类中的方法，这样，既沿袭了父类的功能，又定义了子类的特有功能。

### 使用：

一般是在父类成员方法的基础上增添新的功能，可以考虑在声明子类的成员方法时，使用 super关键字对父类的同名方法直接调用。（也可以理解为子类的新方法覆盖了继承的父类方
法），但必须要注意是同名（使用@*Override*）对重写方法进行注释，让编译器识别。

### 注意：

`private`修饰的方法不能重写（父类私有成员能被子类继承，但不属于子类，子类
不能直接访问和调用，除非父类中有公开的、能调用其私有成员的方法，子类可以通过继承 该方法间接访问父类的私有成员）。子类的访问权限（开放权限）必须大于父类（public> 默认 > 私有）。
Java中的继承是单继承（不能同时继承多个类），同时可以通过（套娃）的方式实现多层继承（即父类的父类也能被子类继承）。

## 带包的Java类编译和执行：

### 包的格式：

*package 一级包名.二级包名.三级包名...;*

### 方法：

1、手动建包：根据包名建立一级、二级、三级...文件夹，并将Java类文件放置于最深层 再用javac命令编译java类，最后在原始路径下用java命令带包执行:*java com.itheima.HelloWorld*
2、自动建包：在原始路径下，执行如下命令：*javac -d . HelloWorld.java*，最后执行：*java com.itheima.HelloWorld*。

## 导包：

当要使用的类与当前类不在同一包下，如果不怕麻烦的话，可以直接使用完整包名来新建对象和调用方法，例如：`java.util.Scanner`。当然，更简洁的是，
Java提供了导包功能，即在声明包名后，输入（例）：`import java.util.Scanner;`以import包名的方式来导入不同包下的类。

## 权限修饰符：


| 修饰符                                                                                                                        | 同类 | 同包子类无关类 | 不同包子类 | 不同包无关类 |
| :------------------------------------------------------------------------------------------------------------------------------ | :----- | :--------------- | :----------- | :------------- |
| private                                                                                                                       | Yes  | No             | No         | No           |
| default                                                                                                                       | Yes  | Yes            | No         | No           |
| protected                                                                                                                     | Yes  | Yes            | Yes        | No           |
| public                                                                                                                        | Yes  | Yes            | Yes        | Yes          |

 总结起来就是：`private`仅限于本类访问和调用，`default`适用于同包类，而`protected`适用于能跟它产生关系的所有类（同包和其子类）
`public`则是完全开放，任何类都能够调用和访问。

## 状态修饰符：

主要有：`final`和`static`

### final：

最终态，被`final`修饰的方法一旦封装完毕，在子类中就不可以被重写。被`final`修饰的变量
一旦初始化完毕，就不可被修改（相当于C语言中的`const`）。被`final`修饰的参数，一经传入，则不能被修改。被`final`修饰的类，该类则不能被继承。`final`其实是规定了被修饰的对象，其值无法被
修改。*int*型等基本型其值无法被修改，方法、类的对象其值是堆内存里的地址。而地址所指向的内容可以被修改。

### static：

静态。被`static`修饰的变量为所有该类对象共享，例：两个*student*类的对象s1、s2，拥有
被`static`修饰的成员变量*university*。则两个对象s1、s2共享*university*。只要其中一个对象将*university*的值更改，另一个对象所访问到的该变量值也会随之更改。一般来说，对于这类变量
的访问都是通过类名来访问的（*student.university*）。

### 非静态的成员方法可以调用和访问：

非静态的成员变量
非静态的成员方法
静态的成员变量
静态的成员方法

### 静态的成员方法可以调用和访问：

静态的成员方法
静态的成员变量
**总之，静态方法只能访问静态成员**
造成两者之间差异的原因：
静态方法在类创建时就会跟随类而被创建，静态的成员变量也是如此，
而非静态的成员方法和变量只有在实例创建时才会随之被创建，在此之前并不存在，无法被静态方法
方法和调用。所以和main方法在同一类下的其他方法要想能被main方法调用，就只能是静态方法。
内存上的本质就在于系统会为静态方法分配一个固定的内存空间。而普通方法，会随着对象的调用而加载，当使用完毕，会自动释放掉空间。

## 多态（Java三大特性之一）：

同一个对象在不同时刻表现出来的多种形态。

### 条件：

1、有继承/实现关系
2、有方法重写
3、有父类引用指向子类对象（ *父类 fu = new 子类();*）

### 运行特点：

以*Animal a = new Cat();*为例。形象化地讲，这句话地意思是将“猫”看成是“动物”，则我们
观察到的特征则是“动物”的特征（披着“动物”的皮），所以我们能够调用的行为（方法）和访问的特征（成员变量）都是“动物”所拥有的
（而非“猫”所拥有的）。但是调用的行为其执行的主体却为“猫”，
所以其表现出来的动作是“猫”的动作（而非“动物”的行为），不过其年龄、属性无论“猫”为多少，显示的 都是“动物”的年龄、属性等~~~

### 原理解释：

以 *Animal a = new Cat();* 为例，该语句在栈内存中创建了一个*Animal*类的实例，在堆内存中创建了一个*Cat*主体，并将其地址
传递给栈内存中的实例。我们能够调用和访问堆内存中的方法和变量都是先通过接触栈内存中方法的属性，再通过属性中存储的地址而访问
堆内存中对应的值。这也就意味着栈内存里实例方法中有多少属性，我们就能访问堆内存中对应的多少属性。（*Animal*限制了*Cat*）
同时行为之所以体现的是*Cat*的行为，是因为该行为在*Cat*类中被重写了，而*Cat*类新声明的方法和 变量在*Animal*中没有对应，无法被使用。
至于*Animal*父类中的变量，因为无法被重写，故获取的值仍然是*Animal*类中的值（在*Animal*栈内存中直接获取该变量的地址，得到的
自然而然就是*Animal*类的值，而非*Cat*类中的值）。

## 多态转型：

### 向上转型：

由父类指向子类 *Fu f = new Zi();*

### 向下转型：

由子类转向父类（强制类型转化）*Zi z = (Zi) f;*
这样做的好处就是要想使用子类中的独有方法和变量，不用再新建一个子类实例而浪费一个内存空间，实质上只是将多态的父类实例转化为子类，
内存地址不变。（前后堆内存中的实例都是子类实例）

### 请注意：

强制转换必须要求堆内存中的类型必须与要转化的类型相匹配，否则编译报错`ClassCastException`类型转化异常

## 抽象类（abstract）：

### 抽象方法：

以猫、狗、动物为例。我们知道某只动物是“动物类”，却不知道这只动物具体属于“猫类” 还是“狗类”。我们知道“动物类”都有某种行为（方法），但因为不知道具体属于何种动物，我
们无法对这种行为进行具体描述（“猫类”与“狗类”的行为可能不同），故我们不想对这种方法 进行具体定义（只声明，没有方法体）。这种方法就称为抽象方法，而抽象方法只能被包含在抽象类中。
抽象类中可以既有抽象方法也可以有实体方法，并且抽象方法可有可无（如果没有，这个类也是 多此一举）
抽象类无法直接创建实例（它是抽象的，“不存在”的），一般都是通过子类继承并多态来实现。注意，再创建子类时，必须要对父类中的抽象方法进行重写（可以理解为父类抽象类只规定了子类要
完成的任务并不要求子类以何种方式去完成，但是子类必须完成这个任务）如果子类不对抽象方法进行重写则自身也必须是抽象类（因为该子类继承了抽象方法，但抽象方法只能存在于抽象类中）
抽象类也要有构造方法（其不是不能实例化，而是无法直接创建实例，必须通过子类多态而达到间接实例化，在子类实例化时其构造方法要访问父类的构造方法来对父类进行初始化，即默认语句
`super()`）用于子类访问父类数据的初始化。

## 接口（`Interface`）：

接口就是一个规范，接口就是某个事物对外提供的一些功能的说明。我们还可以利用接口实现多态功
能，同时接口也弥补了Java单一继承的弱点，也就是类可以实现多个接口。一般使用接口声明方法
或常量，接口中的方法只能是声明，不能是具体的实现，这一点和抽象类是不一样的。接口是更高级
别的抽象。

### 格式：

*public interface 接口名{ }*
接口没有构造方法，其是对行为的抽象，没有具体存在。

## 注意：

`Object`是所有类的超类。如果一个类没有父类，那么`Object`就是它的父类。接口的子类有构造方法
（默认包含`super()`），实际上`super()`指的就是`Object`类中构造方法。

## 实现（`implements`）：

### 格式：

*public class 类名 implements 接口名 { }*
其用法同抽象类，无法直接实例化，必须通过子类来完成，一个子类可以同时继承多个接口。
接口中可以定义成员变量，但是接口中的成员变量都会被视为有`public static final`修饰，
不可更改，也就意味着可以直接通过类名来调用访问。成员方法默认有`public abstract`修饰
只能是抽象方法。

## 接口、抽象类的区别：

### 成员区别：

抽象类中有常量和变量，有构造方法，有抽象方法和非抽象方法
接口中只有常量和抽象方法

### 关系区别：

类与类：继承，单继承
类与接口：实现，可以是单实现，也可以是多实现
接口与接口：继承，单继承与多继承

### 设计理念区别：

抽象类主要是对类抽象，包括属性和行为
接口主要是对行为抽象

### Tips：

在解决具体实际问题时，先从最具体的分析，然后再从中剥离共同
特征，以此作为父 类、接口、抽象类（最具体的一般视为具体类）

## 作为形参和返回值：
### 类名：
形参为类名，实质上需要传入的是该类对象；同理，返回值为类名，
需要返回的也是该类的对象。
### 抽象类：
形参为抽象类，实质上是要通过通过多态的方式创建子类实例并传入
作为形参；作为返回值，其实质上要返回的也是子类实例（多态）。
### 接口：
其运用同抽象类，要通过其他类的实现才能作为参数和返回值

## 内部类：
指的是被包含在一个类中的类（即外部类包含着内部类），内部类
可以直接访问外部类的成员，而 外部类无法直接访问内部类的成员
（必须先创建一个内部类的实例），内部类可以直接访问外部类中
`private`成员。（内部类如果被实例化那么外部类也肯定会先被
实例化，外部类实例化不代表着 内部类被实例化）  
### 同包下的不同类调用内部类（成员内部类）：
*外部类.内部类 实例名 = 外部类.new 内部类();*  
但是我们使用成员内部类的原因很大一部分就是想要用成员内部类隐藏
一部分代码，不对外开放 一般也会使用`private`来修饰。基于此种
情况下，我们会在外部类中创建一个新的方法，用于访问内部类，也就是
说我们会直接创建外部类实例，调用外部类中的该方法来达到目的。
### 同包下不同类调用内部类（局部内部类）：
该内部类被定义在外部类的成员方法中，如果要想在其他类中使用外部
类的成员方法中的局部内部类先要在成员方法中创建内部类实例，通过
成员方法里对该实例的操作（调用和访问）来实现。最后只需使用外部类
的成员方法便可达到创建和访问内部类的目的。（方法调用完会被JVM清除）

## 匿名内部类：
### 前提：
存在一个类或者是一个接口
### 格式：
*new 类名或接口名() { 重写方法; };*  <<-- <<-- <<-- <<--
### 本质：
是一个继承了该类或实现了该类接口的子类匿名对象。`new`是在堆内存中
创建了一个子类对象，只不过这种创建对象并没有栈内存中的对象名来
接受来自堆内存中的地址。但是也可以用多态的方式来接受堆内存中的
地址，并在成员方法中多次调用。这样的好处是：抽象类、接口可以不通过
子类继承和实现并且再进一步创建子类实例，而是直接继承和实现（在
语句体内重写方法）
### 意义：
匿名内部类的返回值可以看作是类/接口的实例对象，可以直接作为对象
传入需要同类对象的方法 （即可以直接定义，作为实参传入）

## Math类（`java.lang.math`）:
该类中没有构造方法，只有成员变量和成员方法。且所有的成员方法和
成员变量都被`static`所修饰， 意味着所有成员均为静态，可以直接通过
类名（`math.`）来调用访问

## System类（`java.lang.system`）：
该类无法被实例化，成员方法均为静态，可以通过类名来调用。
### 方法：
`public static void exit(int status)` 终止当前运行
的Java虚拟机。其中非零值表示异常终止，0则要求其正常退出  
`public static long currentTimeMillis()` 以毫秒为单位返回
当前时间与UTC时间 1970年1月1日午夜之间的差异，以毫秒为单位。  
`public static long nanoTime()`以纳秒为单位返回JVM中当前
测量时间，不以挂钟、其他时间为参考，仅用于差值比较得出在JVM中
时间间隔（精确计算时间经过）

## Object类（`java.lang.Object`）：
类`Object`是类层次结构的根。 每个类都有Object作为超类（继承自
`Object`）
`toString`方法：
如果想要`println`输出类的信息，得到的结果并不令人满意。若去查看
`println`方法的源码，就会发现和`valueOf()`有关，而`valueOf()`中又
调用了`toString()`方法，`Object`中的`toString`方法是输出：包名+
类名+地址。这使得简单查看类的信息变得复杂，因此建议在子类中重写此
方法。（可以使用IDEA快速重写）
### `public boolean equals(Object o)`：
想要比较两个对象是否相同，`Object`中的`equals`方法是直接比较两个对
象的地址，一般建议 在子类中重写。重写方法中很可能会用到`getClass()`
方法。该方法获取字节码文件（即比较的时候是比较两个对象是否是同一个类）。

## Arrays类（`java.util.Arrays`）：
`Array`类中有一个无参构造方法（被`private`修饰，无法被访问），其是
一个包含了许多操作数组的方法的集合（均为静态）
### toString()方法：
显示数组的信息（展示数组中的全部元素）
### sort()方法：<<-- <<-- <<-- <<--
按照数字排列顺序排列指定数组

## 基本类型包装类：
将基本数据类型封装成对象的好处在于可以在对象中定义更多的功能方法
操作该数据，常用的操作之一就是用于基本数据类型与字符串之间的转换  
byte--Byte short--Short int--Integer  
long--Long float--Float double--double  
char--Character boolean--Boolean  
这些类都是最终类（无法被继承），都有一个父类（`Number`），有构造
方法，但是很少使用，成员方法中不全是静态（也就意味着要创建对象，
进行调用），通常，使用`valueOf()`来创建是一个更好的选择。

## int与String类型相互转换：
### int --> String：
String s = '' + 100; String s = String.valueOf(100);
### String --> int：
Integer i =Integer.valueOf(String s); int i1 = i.intValue();
或者 int i2 = Integer.parseInt(String s);

## 自动拆箱和装箱：
### 装箱：
将基本数据类型转换为包装类，一般用`valueOf()`方法，
integer i = 100;实际上隐含了`valueOf`方法，实现了自动转换。
### 拆箱：
将包装类自动转换为基本数据类型，一般用`parseInt()`等方法，
Integer ii = 10; ii += 10; 就隐含了`parseInt`方法，实现了
自动拆包

## Date类（`java.util.Date`）：
`Date`类表示特定的时刻，精度为毫秒。
### 构造方法：
*public Date()*  
分配一个Date对象并对其进行初始化，使其表示分配的时间，测量Date到毫秒。  
*public Date(long date)*  
分配Date对象并将其初始化以表示自标准基准时间（称为“纪元”）以来的
指定毫秒数，即 1970年1月1日00:00:00 GMT。
### 成员方法：
*public long getTime()*  
返回自此Date对象表示的1970年1月1日00:00:00 GMT以来的毫秒数。  
*public void setTime(long time)*  
将此Date对象设置为表示格林威治标准时间1970年1月1日00:00:00之后的time毫秒的时间点。

## SimpleDateFormat类（`java.text.SimpleDateFormat`）：
格式化输出日期和时间（简易上手，在创建该类对象后，调用`format`方法即可）
构造方法：
无参构造：*public SimpleDateFormat()*  
构造一个`SimpleDateFormat`使用默认模式和日期格式符号默认FORMAT区域设置
带参构造：*public SimpleDateFormat(String pattern)*  
构造一个`SimpleDateFormat`使用给定的模式和默认的默认日期格式符号FORMAT区域设置

