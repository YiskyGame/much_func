# much_func
much_func，最初的名字叫作much function，意为更多函数。

它完全因为编程中麻烦的内容太多，而C++可以函数式编程，所以诞生了它，而且语言是C++。

它分为四(v4.0-Pre后会改为五)部分：

+ much_func.h：此头文件主要存放各种函数(v4.0-Pre之前包含a_to_b变种)，以及导入iofunc.h、bignum.h与v4.0-Pre版本后的func_atob.h。
+ iofunc.h：此头文件为存放各种输入输出函数，使用C++流来编写。
+ bignum.h：此头文件为存放bignum高精度类以及重载运算符(除了除号/外)。
+ vector_func.h：此头文件为存放各种关于vector的函数与重载的运算符。
+ _(特殊-因v4.0-Pre还未发布)_ func_atob.h：4.0-Pre及之后用于存放函数a_to_b变种。

截止目前，头文件中的函数有几十个，这里就不再描述了。可以自己去查看。
