# Java Swing(GUI设计)

## 1、概述

在Java的早期编程中，使用的是**java.awt**包提供的类，包含Button(按钮)、TextField(文本框)、List(列表)等组件。然而在Java 2(JDK 1.2)中新增了Javax.swing包，提供了更强大的GUI设计工具。

Java早期的java.awt包中的类所创建的组件习惯上被称为重组件，即每一个组件都有一个对应的本地组件在为它工作（也被称为同位体），也带来了不同平台外观不一致、功能单一、无法被扩展等缺点。

在java.swing包中，提供了更丰富、功能更强大的组件——SWING组件，大部分为轻组件，没有同位体。轻组件把与显示组件有关的许多工作和处理组件事件的工作交给相应的UI代表来完成（这些UI代表由Java编写，被添加到Java运行环境中，不依赖平台），使得在不同的平台能够达到外观一致、性能更高的效果。

- Component
	- Container
		- JComponent
			- JButton
			- JTextField
			- JTeatArea
			- JTree
			- JTable
			- JPanel
		- Window
			- Frame
				- JFrame
			- Dialog
				- JDialog

*JComponent类的部分子类以及JFrame类的JDialog类*

***重要***：需要牢记两个概念——容器类和组件类

Java把由组件类或间接子类创建的对象称为一个组件（Component），把由容器类或间接子类创建的对象称为一个容器（Container）。

容器中可以添加组件，Container类提供了公开的方法add()将组件添加到该容器中，使用removeAll()移除容器中所有的组件，remove(Component c)去掉指定的组件。每当容器中的组件发生增删时，应调用validate()方法，保证容器中的组件正常显示。

***特别的***：容器本身也可以被视为一个组件，因此可以把一个容器添加到另一个容器中实现容器的嵌套。

java.swing包中**最重要的四个类**：*JApplet*、*JFrame*、*JDialog*和*JComponent*。

*JComponent*类的所有子类都是轻组件，同时JComponent又是java.awt中Container类的子类，所以所有的轻组件都是容器。

*JFrame*, *JApplet*, *JDialog*都是重组件，即有同位体的组件，这样窗口、对话框和小应用程序可以与操作系统进行信息的交互，轻组件必须在容器中绘制自己。

习惯上称这些容器为SWING底层容器。

## 2、JFrame窗体

javax.swing中的JFrame类是java.awt中Frame类的子类。Frame类的对象是窗体，为重容器（重组件），所以JFrame创建的也是窗体，JFrame也是重容器。可以使用JFrame及其子类创建一个窗口。因为窗口默认被系统添加到显示器屏幕上，因此***不允许***将一个窗口添加到另一个容器中。

JFrame窗体默认布局是*BorderLayout布局*，基本结构为：窗体上面是菜单条区域，是一个很窄的矩形区域，用来放置菜单条。菜单条区域下面用来放置组件。如果窗体并没有添加菜单条，那么菜单条区域将被其他组件占用。

JFrame类的常用方法如下：

- public JFrame() throws HeadlessException

	Constructs a new frame that is initially invisible. This constructor sets the component's locale property to the value returned by `JComponent.getDefaultLocale`.

	创建一个初始不可见的新窗口