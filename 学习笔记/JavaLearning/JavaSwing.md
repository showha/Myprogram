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

注意：awt是拥有单独的线程，主线程的状态几乎不会影响到窗体。

## 2、JFrame窗体

javax.swing中的JFrame类是java.awt中Frame类的子类。Frame类的对象是窗体，为重容器（重组件），所以JFrame创建的也是窗体，JFrame也是重容器。可以使用JFrame及其子类创建一个窗口。因为窗口默认被系统添加到显示器屏幕上，因此***不允许***将一个窗口添加到另一个容器中。

JFrame窗体默认布局是*BorderLayout布局*，基本结构为：窗体上面是菜单条区域，是一个很窄的矩形区域，用来放置菜单条。菜单条区域下面用来放置组件。如果窗体并没有添加菜单条，那么菜单条区域将被其他组件占用。

JFrame类的常用方法如下：

- public JFrame() throws HeadlessException

	Constructs a new frame that is initially invisible. This constructor sets the component's locale property to the value returned by `JComponent.getDefaultLocale`.

	创建一个初始不可见的新窗口。这个构造器会使用**JComponent.getDefaultLocale**的返回值作为组件的本地属性。
	
- public JFrame(String title) throws HeadlessException

  Creates a new, initially invisible Frame with the specified title. This constructor sets the component's locale property to the value returned by `JComponent.getDefaultLocale`.

  创建一个使用指定标题的、初始不可见的新窗口。这个构造器会使用**JComponent.getDefaultLocale**的返回值作为组件的本地属性。

- public void setBounds(int x, int y, int width, int height)

  Moves and resizes this component. The new location of the top-left corner is specified by `x` and `y`, and the new size is specified by `width` and `height`. This method changes layout-related information, and therefore, invalidates the component hierarchy. The `width` or `height` values are automatically enlarged if either is less than the minimum size as specified by previous call to `setMinimumSize`. The method changes the geometry-related data. Therefore, the native windowing system may ignore such requests, or it may modify the requested data, so that the `Window` object is placed and sized in a way that corresponds closely to the desktop settings.

  此方法不在JFrame中，而是继承自java.awt.Window类（此类是java.awt.Frame的父类），即JFrame的父类的父类。

  此方法能移动和缩放组件。左上角的新位置由**x**和**y**指定，窗体的新大小由**width**和**height**指定。此方法会更改布局的相关信息，因此，会造成组件的层次结构无效。如果**width**或**height**的值小于先前调用的setMinimumSize方法所指定的最小值，那么**width**或**height**的值会自动扩增。此方法会更改与几何图元相关的数据，因此，本地窗口系统可能会忽略这些请求或者可能会修改所请求的数据，从而以与桌面设置紧密对应的方式来放置窗体对象和设置其大小。

- public void setSize(int width, int height)

  Resizes this component so that it has width `width` and height `height`. This method changes layout-related information, and therefore, invalidates the component hierarchy. The `width` and `height` values are automatically enlarged if either is less than the minimum size as specified by previous call to `setMinimumSize`. The method changes the geometry-related data.   Therefore, the native windowing system may ignore such requests, or it may modify the requested data, so that the `Window` object is placed and sized in a way that corresponds closely to the desktop settings.

  此方法不在JFrame中，而是继承自java.awt.Window类（此类是java.awt.Frame的父类），即JFrame的父类的父类。

  重新设定组件的长和宽。此方法会更改布局的相关信息，因此，会造成组件的层次结构无效。如果**width**或**height**的值小于先前调用的setMinimumSize方法所指定的最小值，那么**width**或**height**的值会自动扩增。此方法会更改与几何图元相关的数据，因此，本地窗口系统可能会忽略这些请求或者可能会修改所请求的数据，从而以与桌面设置紧密对应的方式来放置窗体对象和设置其大小。

- public void setVisible(boolean b)

  Shows or hides this `Window` depending on the value of parameter `b`.

  If the method shows the window then the window is also made focused under the following conditions:

  - The `Window` meets the requirements outlined in the [`isFocusableWindow()`](#isFocusableWindow()) method.
  - The `Window`'s `autoRequestFocus` property is of the `true` value.
  - Native windowing system allows the `Window` to get focused.

  There is an exception for the second condition (the value of the `autoRequestFocus` property). The property is not taken into account if the window is a modal dialog, which blocks the currently focused window.

  Developers must never assume that the window is the focused or active window until it receives a WINDOW_GAINED_FOCUS or WINDOW_ACTIVATED event.

  此方法不在JFrame中，而是继承自java.awt.Window类（此类是java.awt.Frame的父类），即JFrame的父类的父类。

  窗体的显示或者隐藏取决于参数**b**的值。默认为隐藏不可见。

~~~java
public static void main(String[] args) {
    JFrame frame = new JFrame();
    frame.setSize(500, 300);
    frame.setTitle("你好！");
    frame.setBackground(Color.cyan); // 设置窗体的背景颜色
    frame.getContentPane().setVisible(false);
    /*
    ** 在你直接调用setBackground(Color.red)这个方法后，你的确设置了JFrame的背景颜色，而你看到的却不是直接的JFrame，	   ** 而是JFrame.getContentPane()。而JFrame上的contentPane默认是Color.WHITE的，所以，无论你对JFrame怎么设置背景     ** 颜色，你看到的都只是contentPane.
    ** http://t.zoukankan.com/gojava-p-3709736.html
    */

    // 设置窗体的初始位置为屏幕中央
    Dimension di = Toolkit.getDefaultToolkit().getScreenSize(); // 获取屏幕大小
    int x = (int) ((di.getWidth() - frame.getWidth()) / 2);
    int y = (int) ((di.getHeight() - frame.getHeight()) / 2);
    frame.setLocation(x, y);

    frame.setCursor(new Cursor(Cursor.CROSSHAIR_CURSOR)); // 设置窗体中鼠标的样式
    frame.setAlwaysOnTop(true); // 是否始终置于最上层
    frame.setResizable(false); // 是否可以调整大小
    frame.setVisible(true); // 是否可见
}
~~~

## 3、监听器

顾名思义，Java监听器就是用来监听各个事件的发生。

### WindowListener（窗口监听器）：

~~~Java
public interface WindowListener extends EventListener {
    /**
     * 当窗体被打开，触发该方法
     * 具体实现需要重写该方法
    */
    public void windowOpened(WindowEvent e);

    /**
     * 当窗体正在关闭时，触发该方法
     * 具体实现需要重写该方法
     */
    public void windowClosing(WindowEvent e);

    /**
     * 当窗体关闭后，触发该方法
     * 具体实现需要重写该方法
     */
    public void windowClosed(WindowEvent e);

    /**
     * 当窗体被最小化为图标时，触发该方法
     * 具体实现需要重写该方法
     */
    public void windowIconified(WindowEvent e);

    /**
     * 当窗体从最小化图标变回普通状态时，触发该方法
     * 具体实现需要重写该方法
     */
    public void windowDeiconified(WindowEvent e);

    /**
     * 当窗体变为活跃状态时，触发该方法
     * 具体实现需要重写该方法
     */
    public void windowActivated(WindowEvent e);

    /**
     * 当窗体变为不活跃状态时，触发该方法
     * 具体实现需要重写该方法
     */
    public void windowDeactivated(WindowEvent e);
}
~~~

往窗口上添加窗口监听器：

~~~java
frame.addWindowListener(new WindowAdapter() {
    @Override
    public void windowClosing(WindowEvent e) {
        frame.dispose();
    }
});
~~~

此方法原本是需要的参数是WindowListener接口，但是如果添加WindowListener接口则需重写所有方法，而抽象类WindowAdapter可以选择性重写任意一个方法，没有限制。

### KeyListener（键盘监听器）：

~~~java
public interface KeyListener extends EventListener {

    /**
     * 当有按键被触动时，触发该方法
     * 具体实现需要重写该方法
     */
    public void keyTyped(KeyEvent e);

    /**
     * 当有按键被按下时，触发该方法
     * 具体实现需要重写该方法
     */
    public void keyPressed(KeyEvent e);

    /**
     * 当有按键被释放时，触发该方法
     * 具体实现需要重写该方法
     */
    public void keyReleased(KeyEvent e);
}
~~~

往窗体中添加键盘监听器：

~~~java
frame.addKeyListener(new KeyAdapter() {
    @Override
    public void keyPressed(KeyEvent e) {
        System.out.println(e.getKeyChar());
    }
});
~~~

同窗口监听器，我们使用adapter来实现。KeyEvent中的方法参见Java帮助文档

### MouseListener（鼠标监听器）：

~~~java
public interface MouseListener extends EventListener {

    /**
     * 当鼠标点击时，触发该方法
     * 具体实现需要重写该方法
     */
    public void mouseClicked(MouseEvent e);

    /**
     * 当鼠标按下时，触发该方法
     * 具体实现需要重写该方法
     */
    public void mousePressed(MouseEvent e);

    /**
     * 当鼠标释放时，触发该方法
     * 具体实现需要重写该方法
     */
    public void mouseReleased(MouseEvent e);

    /**
     * 当鼠标进入窗体时，触发该方法
     * 具体实现需要重写该方法
     */
    public void mouseEntered(MouseEvent e);

    /**
     * 当鼠标退出窗体时，触发该方法
     * 具体实现需要重写该方法
     */
    public void mouseExited(MouseEvent e);
}
~~~

在MouseAdapter中多实现了两个方法：

~~~java
/**
 * 当鼠标滚轮滚动时，触发该方法
 * 具体实现需要重写该方法
 * @since 1.6
 */
public void mouseWheelMoved(MouseWheelEvent e){}

/**
 * 当鼠标拖动时，触发该方法
 * 具体实现需要重写该方法
 * @since 1.6
 */
public void mouseDragged(MouseEvent e){}

/**
 * 当鼠标移动时，触发该方法
 * 具体实现需要重写该方法
 * @since 1.6
 */
public void mouseMoved(MouseEvent e){}
~~~

在窗体中添加鼠标监听器：

~~~java
frame.addMouseListener(new MouseAdapter() {
    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println(e.getX() + ", " + e.getY());
    }
    // 小提示：
    // MouseEvent中有getButton()方法，该方法会返回一个整数
    // 这个整数用来表示当前点击的是左键、右键还是滚轮中键
});
~~~

### MouseWheelListener（鼠标滚轮监听器）：

~~~java
public interface MouseWheelListener extends EventListener {

    /**
     * Invoked when the mouse wheel is rotated.
     * @param e the event to be processed
     * @see MouseWheelEvent
     */
    public void mouseWheelMoved(MouseWheelEvent e);
}
~~~

这个不再需要适配器（因为接口中只有一个方法）

## 常用组件

在开始前，暂时先将布局设置为空（frame.setLayout(null)），后续学到了Layout再进行讨论。

所有的组件都继承自Component类。

- Label类（标签类）

	该类为一个标签（相当于PPT里的文本框），带有文字。

	~~~java
	Label label = new Label("你好！"); // 新增一个标题为“你好！”的标签
	label.setBounds(30, 50, 100, 40); // 设置初始位置（相对于窗体的）为30, 50
	// 设置标签的大小宽100，高40（大小要能够覆盖字体本身）
	label.setFont(new Font("JetBrainsMono NF", Font.BOLD, 20)); // 设置字体为JetBrainsMono NF，加粗（bold）
	// 大小20
	label.setForeground(Color.pink); // 设置标签字体颜色为pink
	// 设置字体类型的方法在Frame类也有，如果使用的是Frame类中的方法，那么作用于窗体中的所有文本字体
	label.setBackground(Color.darkGray); // 设置标签背景色为暗灰色
	frame.add(label); // 将标签添加到窗体中
	~~~

	可以使用如下代码获取电脑中的字体：

	~~~java
	for (Font font : GraphicsEnvironment.getLocalGraphicsEnvironment().getAllFonts()) {
	    System.out.println(font);
	}
	~~~

- Button类（按钮类）

	该类创建一个按钮。

	~~~java
	/**
	 * 添加一个Button（按钮）
	 */
	Button button = new Button("我是按钮");
	button.setBounds(20, 50, 100, 40);
	button.setFont(new Font("JetBrainsMono NF", Font.ROMAN_BASELINE, 20));
	frame.add(button);
	
	/**
	 * 添加一个TextField，即一个输入框
	 * 可以用来输入信息
	 */
	// TextField textField = new TextField();
	// textField.setBounds(20, 100, 200, 30);
	// textField.setEchoChar('*'); // 设置输入框显示的字符为'*'
	// textField.setFont(new Font("JetBrainsMono NF", Font.ROMAN_BASELINE, 25));
	// frame.add(textField);
	
	/**
	 * 添加一个TextArea，即一个输入区域
	 * 弥补了TextField无法输入多行信息的缺点
	 * 但是也无法把显示字符改成'*'号
	 */
	TextArea text = new TextArea();
	text.setBounds(20, 220, 200, 100);
	text.setFont(new Font("JetBrainsMono NF", Font.ROMAN_BASELINE, 15));
	// text.setEnchoChar('*'); 没有此方法
	frame.add(text);
	
	/**
	 * 添加一个单选框（Checkbox）
	 */
	// Checkbox checkBox = new Checkbox("记住密码");
	// checkBox.setBounds(20, 150, 100, 30);
	// frame.add(checkBox);
	
	/**
	 * 添加一个多选框（Checkbox）
	 * 此多选框需要new多个单选框
	 */
	CheckboxGroup group = new CheckboxGroup();
	Checkbox checkBox1 = new Checkbox("选我");
	checkBox1.setBounds(20, 150, 100, 30);
	frame.add(checkBox1);
	
	Checkbox checkBox2 = new Checkbox("你干嘛");
	checkBox2.setBounds(20, 180, 100, 30);
	frame.add(checkBox2);
	// 使用下列方法，显示的结果是：在选择时，只能二选一
	checkBox1.setCheckboxGroup(group); // 与多选框相关联
	checkBox2.setCheckboxGroup(group); // 与多选框相关联
	
	// 当按钮被点击时，触发该方法
	button.addActionListener(e -> {
	    System.out.println("按钮被点击");
	    String str = text.getText();
	    System.out.println("输入的文本是 " + str);
	    // System.out.println("是否记住密码 " + checkBox.getState()); // 输出单选框的状态
	    // 未选中时为false，选中时为true
	    System.out.println("你的选择是 " + group.getSelectedCheckbox().getLabel()); // 输出
	    // 多选框中选中的标签名
	});
	~~~

	

