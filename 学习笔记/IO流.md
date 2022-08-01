# File类：

- File类的一个对象，代表一个文件或者一个文件目录

- File类的声明在java.io包下
- File类中涉及到了文件的创建、删除、重命名、修改时间、文件大小等方法，并未涉及到写入或读取文件内容的操作。如需要读取或写入文件内容，必须使用IO流来完成
- 后续File类对象常会作为参数传递到流的构造器中，指明读取或写入的“终点”

## File类的实例化：

### 构造器：

- public File(String pathname)

	以pathname 为路径创建 File 对象，可以是 绝对路径 或者 相对路径 ，如果 pathname 是相对路径，则默认的当前路径在系统属性 user.dir 中存储。

- public File(String parent,String child)

	以 parent 为父路径， child 为子路径创建 File 对象 。

- public File(File parent,String child)

	根据一个父 File 对象和子文件路径创建 File 对象

### 路径：

路径的分类有两种：一种是相对路径（相对于当前路径），一种是绝对路径（从盘符开始一直到文件名）

在IDEA中，如果使用JUnit中的单元测试方法测试，相对路径即为当前Module下

如果使用main方法进行测试，相对路径即为当前Project下

在Eclipse中，使用的无论是单元测试方法还是mail()方法，相对路径都是当前的project下

#### 路径分隔符：

- windows 和 DOS 系统默认使用“\\”来表示
- UNIX 和 URL 使用“/”来表示

由于Java是跨平台语言，分隔符最好还是要慎用。为了解决这个隐患， File 类提供了一个常量：public static final String separator。根据操作系统，动态的提供分隔符。File file2 = new File("d:"+ separator + " atguigu"+ separator + "info.txt");

### 常用方法：

![](File类常用方法1.png "File类常用方法1")

![](File类常用方法2.png "File类常用方法2")

![](File类常用方法3.png "File类常用方法3")

# IO流：

所谓的I/O流指的是Input和Output。数据进行传输而形成数据流（Stream）。

## 数据流的分类：

- 按操作数据单位不同分为：字节流（8 bit）和字符流（16 bit）。

	字节流传输的是字节（0100100类型的）二进制数据，用于视频、音频、照片等的传输

	字符流传输的是字符，适用于文件的内容、文字等

- 按数据流的流向不同分为：输入流和输出流

- 按流的角色的不同分为：节点流和处理流。

	节点流是指由文件的节点直接向内存（程序）传输的数据流

	处理流是指在节点流之外对节点流做进一步的包装，作用是加快节点流的传输

## 流的抽象类：

| （抽象基类） | 字节流       | 字符流 |
| ------------ | :----------- | ------ |
| 输入流       | InputStream  | Reader |
| 输出流       | OutputStream | Writer |

所有的IO流体系都是基于上述四个抽象类延伸的（一般在相关类上会带有相关上述抽象类的名字）

![](IO流体系结构.png "IO流体系结构")

表中加深蓝色的类需要重点关注

| 抽象基类     | 节点流（或文件流） | 缓冲流（处理流的一种） |
| ------------ | ------------------ | ---------------------- |
| InputStream  | FileInputStream    | BufferedInputStream    |
| OutputStream | FileOutputStream   | BufferedOutputStream   |
| Reader       | FileReader         | BufferedReader         |
| Writer       | FileWriter         | BufferedWriter         |

### 节点流：

一般地，使用数据流读取文件处理分为四步：

1. 创建File对象，指向我们要处理的文件
2. 创建数据流对象，建立数据存放文件
3. 创建一个临时存放数据的数组
4. 调用流对象的读取方法将流中的数据读入到数组中
5. 关闭资源

~~~java
FileReader fr = null;
//使用try-finally是为了确保能够执行fr.close()
try {
    File fi = new File("C:\\Users\\Program\\Java\\Learning\\EclipseKeys.java");
    fr = new FileReader(fi);
    char[] cube = new char[5];
    int len;
    //使用数组分批次读取，要比一个一个读取效率高
    while ((len = fr.read(cube)) != -1) {
        //len不能使用cube.length()替代
        for (int i = 0; i < len; i++) {
            System.out.print(cube[i]);
        }
    }
    //也可以使用下面的写法，缺点是耗内存,浪费大
    // while ((len = fr.read(cube,0,len))!= -1) {
    // String str = new String(cube);
    // System.out.print(str);
    // }
} catch (IOException e) {
    e.printStackTrace();
} finally {
    try {
        //判断是否读取成功，不然不成功的话还会报错
        if (fr != null)
            fr.close();
    } catch (IOException e) {
        e.printStackTrace();
    }
}
~~~

一般的，使用数据流写入文件需要四步：

1. 提供File类对象，指明写出到的文件
2. 提供FileWriter对象，用于数据的写出
3. 写出的操作
4. 流资源的关闭

这种操作写入到文件中，不是删除原有的文件再用新文件去替换，而是替换了原有的文件的内容，并非删除。

如果使用构造器 FileOutputStream(file,true)，则目录下的同名文件不会被覆盖在文件内容末尾追加内容。

~~~java
FileReader fr = null;
FileWriter fw = null;
try {
    File f1 = new File("C:\\Users\\Program\\Java\\Learning\\EclipseKeys.java");
    File f2 = new File("HelloJava.java");

    fr = new FileReader(f1);
    fw = new FileWriter(f2);

    char[] ch = new char[5];
    int len;

    while ((len = fr.read(ch)) != -1) {
        //写入指定长度的字符
        fw.write(ch,0,len);
    }
} catch (IOException e) {
    e.printStackTrace();
} finally {
    try {
        //判断不为空，才能执行关闭操作
        if (fr != null)
            fr.close();
    } catch (IOException e) {
        e.printStackTrace();
    }
    //上一个try-catch间断不会影响下一个运行
    try {
        if (fw != null)
            fw.close();
    } catch (IOException e) {
        e.printStackTrace();
    }
}
~~~

在对字节流进行读取的时候，其实也是可以读取字符的，但只能正确处理英文和数字。因为英文和数字按照ASCII码来存储时，只占用一个字节，正好和字节对上。而中文的存储是双字节的，在读取和处理的时候会因此乱码。既然Java已经提供了专门的字节和字符处理类，我们也应遵照这种方式分别处理。

如果字节流过大、过长时，接受的临时数组容量可以设置得大一点（通常是1024，在实际开发时，会有专门的方法提供）

### 缓冲流：

一般的，使用缓冲流读取、处理文件需要五步：

1. 提供File类对象，指明要处理的文件
2. 提供字节流的、输入或输出流的对象，用于数据的读取和写入
3. 构造对应的缓冲流，并将相应的字节流作为参数传入
4. 创建临时数组，用于存储读取的数据
5. 读取、写入的操作
6. 资源的关闭。（实际上只要关闭缓冲流即可，缓冲流在节点流的外层，在调用缓冲流的关闭方法时会自动调用节点流的关闭方法）

~~~java
BufferedInputStream fr = null;
BufferedOutputStream fw = null;
try {
    File f1 = new File("C:\\Users\\Program\\Java\\Learning\\EclipseKeys.java");
    File f2 = new File("HelloJava.java");

    FileInputStream p1 = new FileInputStream(f1);
    FileOutputStream p2 = new FileOutputStream(f2);

    fr = new BufferedInputStream(p1);
    fw = new BufferedOutputStream(p2);

    byte[] cube = new byte[5];
    int len;

    while ((len = fr.read(cube)) != -1) {
        fw.write(cube,0,len);
        //fw.flush();
        //显示地刷新缓存区。缓冲流默认提供8k的缓冲区，当缓冲区满了的时候
        //会自动刷新缓冲区，将数据转化成输出流进入下一个流程。
    }
} catch (IOException e) {
    e.printStackTrace();
} finally {
    if (fr != null) {
        try {
            fr.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    if (fw != null) {
        try {
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
~~~

对于读取字符流而言，除了使用char数组接收外，还可以使用String字符串来接收（使用fr.readLine()方法读取）。不过不同的是，该方法不会读取换行符，这就意味着需要在String字符串后加上"\n"或者在write()方法后加上newLine()方法。

**加密算法**中可能需要对临时数组中的元素进行一一更改，此时切忌使用for-each循环，要赋值的只是循环体内临时创建的变量（每次循环前被临时数组赋值），而不是对临时数组进行更改，这种做法是无用的。正确的做法是使用for-i循环，通过下标索引更改。

//597