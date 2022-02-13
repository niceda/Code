##### Look
1. distance();
2. partial_sort();
3. is_permutation
4. unique

##### 技巧
- 字符串转数字
  - string s = "245";
int i = std::stoi(s); 还有stol(long), stof(float), stod(double)等
- 数字转字符串
  - int i = 1; string s = std::to_string(i);
- (s[i] - '0') s保存的整数型的字符串，如“123”。
- vector<int> v[5],创建一个包含5个vector<int>类型的数组。如v[0] 为一个vector<int>
- \<cctype\> 
  ```cpp
    - isalpha() 判断一个字符是否为字母
    - isdigit() 判断一个字符是否为数字
    - isalnum() 判断一个字符是否为数字或字母
    - islower() 判断一个字符是否为小写字母
    - isupper() 判断一个字符是否为大写字母
    - tolower() 把字符串都转化为小写字母
    - toupper() 把字符串都转化为大写字母
  ```
- pirntf("%02d", 4)和printf("%2d", 4)的区别
    - out1 为04， out2 为 4.
- c++中的sort排序函数
  ```cpp
    - std::less<type>() // 从小到大 <
    - std::greater<type>() // >
    - std::less_equal<type>() // <=
    - std::grater_equal<type>() // >=  

  ```
- 所有非零值都转为true,零值转为false。 
- \<cmath\>
  ```cpp
      - pow(r, p)
      - abs()
      - floor()/ceil()
      - sqrt(double x)
      - log()
      - sin(), cos(), tan(); asin()...
      - round()
  ```
- string
    - s.compare();
    - getline(cin, s);
    - printf("%s", s.c_str());
- 'A' = 65; 'a' = 97;  'A' + 32 = 'a';
- \<stdio\>
    - sscanf
    - sprintf 
- vector<vector<int> > v; v.resize(n, vector<int>(m));
- 圆周率
    - double pi = acos(-1.0);
- \<algorithm\>
  - is_heap
  - is_sorted
  - median
  - max_element
  - min_element
  - reverse
  - is_permutation
  - next_permutation
  - prev_permutation
  - merge
  - sort
  - unique
  - fill
  - mismatch

##### 总结
- long long int 长度为64, long int 为32,int 一般为32.
- double精度为16,float精度为7位，int可储存10的9次方大的数据，long和long long可储存10的18次方的大数据 
- 在使用getline读入一整行时，若是前面是使用getchar()、cin这类读入了一个字母，但是不会读入后续换行\n符号或者空格的输入时，再接getline()就容易出现问题。应该使用一个getchar()吃掉回车。
- 用类似scanf("%d-%d %d, &a, &b, &c);读入1-2 3这样的输入数据格式
- printf有时cout更好用，适合用来组合输出
- 一定要注意输出的数字是否要零补充，例如输出结果为42, 题目要求输出的形式可能为0042。
- string tt = s.substr(j, i - j); temp = std::stoi(tt);
- 运行超时的话，可以将unorder_map 换成 map，unorder_map的插入、删除等为常数时间，而map的为 对数时间。
- 排序建议用引用传参，这样更快，虽然有时候不用引用传参也能通过，但还是尽量用，养成好习惯
- 判断素数时，有时需要把0和1也要考虑进去。
- node *root = NULL;在main里记得要加等于NULL;
- insert(node *&root); 记得传引用;

##### problem

```cpp
#include <iostream>
using namespace std;

int main() {
    double d1 = 1.555;
    double d2 = 1.5555;
    printf("%.2f\n", d1);
    printf("%.3f\n", d2);
  }
```
d1不进位，d2进位  
甲级1104, 把long double 改为double, 有个测试点就通不过，应该就是这个原因。
