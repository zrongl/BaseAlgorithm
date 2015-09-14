//
//  log.c
//  Algorithm
//
//  Created by ronglei on 14-7-14.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "advance.h"

/*
 __DATE__               进行预处理的日期("mm dd yy"形式的字符串文字)
 __FIFE__               代表当前源代码文件的字符串文字
 __LINE__               代表当前源代码文件中行号的整数常量
 __STDC__               设置为1时，表示该实现遵循C标准
 __STDC_HOSTED__        为本机环境设置为1，否则设为0
 __STDC_VERSION__       为C99时设置为199901L
 __TIME__               源文件编译时间，格式为:"hh: mm: ss"
 __VA_ARGS__            是一个可变参数的宏，很少人知道这个宏，这个可变参数的宏是新的C99规范中新增的，目前似乎只有gcc支持
 (VC6.0的编译器不支持)。宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余
 的","去掉的作用,否则会编译出错, 你可以试试。
 C99标准提供一个名为__func__的预定义标识符。__func__展开为一个代表函数名(该函数包含该标识符)的字符串。该标识符具有函数作用域，而宏本质上具有文件作用域。因而__func__是C语言的预定义标识符，而非预定义宏。
 */

//Another wrong version of RLLog
#define RLLog(format, ...) do {\
fprintf((stderr, "<%s : %d> %s\n",\
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __func__);\
(RLLog)((format), ##__VA_ARGS__);\
fprintf(stderr, "-------\n");\
} while (0);

