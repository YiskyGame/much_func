# much_func
much_func，最初的名字叫作much function，意为更多函数。

这是一个头文件，完全使用C++编写。

它完全因为编程中麻烦的内容太多，而C++可以函数式编程，所以诞生了它，而且语言是C++。

它分为三部分：

+ much_func.h：此头文件主要存放各种函数(v4.0-pre1之前包含a_to_b变种)，以及导入iofunc.h、bignum.h与v4.0-pre1版本后的func_atob.h。
+ iofunc.h：此头文件为存放各种输入输出函数，使用C++流来编写。
+ bignum.h：此头文件为存放bignum高精度类以及重载运算符(除了除号/外)。
+ _(特殊-因v4.0-pre1还未发布)_ func_atob.h：4.0-pre1及之后用于存放函数a_to_b变种。

截止目前，头文件中的函数有几十个，这里就不再描述了。可以自己去查看。
