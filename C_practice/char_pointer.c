#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  //由于[ ] 的优先级高于* 所以a先和 [ ]结合，
  //他还是一个数组，数组中的元素才是char * ，
  //char * 是一个变量，保存的地址。。
  char *name[5] = {"golang", "java", "c", "dart", "erlang"};
  char *n2[2] = {"xue", "lai"};
  
  int k;
  char *tmp;
  //二级指针
  char** tmp2;
  tmp=name[0];
  tmp2=&tmp;
  //printf("%p\n", &name2[0]);
  //printf("%s\n", *(*tmp));
  printf("%c\n", *tmp);
  printf("%p\n", tmp2);
  
  printf("%c\n", **tmp2);


  //C语言中没有字符串类型的变量
  char* s;
  s="china";
  //C语言中编译器会给字符串常量分配地址，如果 "China",
  // 存储在内存中的 0x3000 0x3001 0x3002 0x3003 0x3004 0x3005 .
  printf("%s\n", s);

  printf("%p\n", tmp);
  printf("%p\n", *tmp2);

  //其实真正的意义是 s ="China" = 0x3000;
  //你把China 看作是字符串，但是编译器把它看作是地址 
  //0x3000，即字符串常量的本质表现是代表它的第一个字符的地址。
  
 //定义 char a[10 ]  时，编译器会给数组分配十个单元，每个单元的数据类型为字符。。
 //而定义 char *s 时，  这是个指针变量，只占四个字节，32位，用来保存一个地址

//https://blog.csdn.net/daiyutage/article/details/8604720

//   for (int i = 0;i < (sizeof(name)/sizeof(*name))-1;i++) {
//     k = i;
//     for (int j = i+1;j < (sizeof(name)/sizeof(*name));j++) {
//       if (strcmp(name[k], name[j]) > 0) {
//         k = j;
//       }
//     }
//     if (k != i) {
//       tmp = name[i];
//       name[i] = name[k];
//       name[k] = tmp;
//     }
//   }

//   for (int i = 0;i < (sizeof(name)/sizeof(*name));i++) {
//     printf("%s\n", *(name+i));
//   }
}
