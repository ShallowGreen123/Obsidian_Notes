1. GNU gcc 编译器特性扩展 
~~~C

#define DATA_TYPE_CMP(x, type) \
    __builtin_types_compatible_p(typeof(x), type)

#define __containerof(ptr, type, member) ({         \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})

typeof()

offsetof()
~~~

~~~c
#include <stdio.h>
#include <string.h>
//Linux函数
int main()
{
	printf("%d\n",ffs(8)); // 查找第一个位的值为1的位置 
	printf("%d\n",ffs(9));
	printf("%d\n",ffs(16));
	return 0;
}
~~~

c语言特性
~~~c 
void test_fun(void *data, int len)
{
    for(int i =0; i<len; i++){
        printf("%d ", *((int *)data + i));
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3};
    test_fun(arr, 3);
    test_fun((int []){4,5,6,7}, 4);
    return 0;
}

//result
$ a.exe
1 2 3
4 5 6 7
~~~~


天选B760M 主板 : 1297
i7-13700K CPU : 3196
Kingston 32G D4 内存 : 558
Kingston 2T 固态 : 658
西部数据 机械硬盘 2T : 389
VALKYRIE 水冷散热 : 558
长城650W 电源 : 473 
爱国者A15 机箱 : 120
24寸2K165Hz 显示器 : 1291
音响 : 54

合计 : 8594


