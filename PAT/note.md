#### algorithm 
* distance()
```cpp
  vector<int> v{3, 1, 4};
  cout << "distance(first, last) = " << distance(v.begin(), v.end()) << '\n'
       << "distance(last, first) = " << distance(v.end(), v.begin()) << '\n';
  //result:
  distance(first, last) = 3
  distance(last, first) = -3

```
* partial_sort()
```cpp
  vector<int> v = {23, 43, 4245, 3452345, 23, 2345, 23, 4};
  partial_sort(v.begin(), v.begin() + 3, v.end());
  for (auto val : v) {
    cout << val << " " ;
  }
  //result:
  4 23 23 3452345 4245 2345 43 23
```
* is_permutation()
若范围 [first1, last1) 是 [first2, last2) 的排列则为 true 。
```cpp
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {2, 1, 3, 5, 4};
  cout << "v2 is a permutation of v1:" << boolalpha << is_permutation(v1.begin(), v1.end(), v2.begin());
  //result:
  v2 is a permutation of v1:true
```
* next_permutation/prev_permutation
```cpp
   // next_permutation
   std::string s = "aba";
    std::sort(s.begin(), s.end());
    do {
        std::cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
    //result:
    aab
    aba
    baa

    //prev_permutation
    std::string s="abc";
    std::sort(s.begin(), s.end(), std::greater<char>());
    do {
        std::cout << s << ' ';
    } while(std::prev_permutation(s.begin(), s.end()));
    std::cout << '\n';
    //result:
    cba cab bca bac acb abc
```
* unique()  
从来自范围 [first, last) 的相继等价元素组消除首元素外的元素，并返回范围的新逻辑结尾的尾后迭代器。  
通过用覆写要被擦除的元素的方式迁移范围中的元素进行移除。
```cpp
    // 含有数个重复元素的 vector
    std::vector<int> v{1,2,1,1,3,3,3,4,5,4};
 
    // 移除相继（毗邻）的重复元素
    auto last = std::unique(v.begin(), v.end());
    // v 现在保有 {1 2 1 3 4 5 4 x x x} ，其中 x 不确定
    v.erase(last, v.end());
    for (int i : v)
      std::cout << i << " ";
    std::cout << "\n";
 
    // sort 后 unique 以移除所有重复
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    last = std::unique(v.begin(), v.end());
    // v 现在保有 {1 2 3 4 5 x x} ，其中 'x' 不确定
    v.erase(last, v.end()); 
    for (int i : v)
      std::cout << i << " ";
    std::cout << "\n";
    //result:
    1 2 1 3 4 5 4
    1 2 3 4 5
```
* is_heap  
检查范围 [first, last) 中的元素是否为最大堆。 最小堆：is_heap(v.begin(), v.end(), greater<int>());
```cpp
   std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    if (!std::is_heap(v.begin(), v.end())) {
        std::cout << "making heap...\n";
        std::make_heap(v.begin(), v.end());
    }
 
    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    //result:
    initially, v: 3 1 4 1 5 9 
    making heap...
    after make_heap, v: 9 5 4 1 1 3   std::cout << '\n';
```
* make_heap/pop_heap  
在范围 [first, last) 中构造最大堆。函数第一版本用 operator< 比较元素，第二版本用给定的比较函数 comp 。
```cpp
    std::cout << "Max heap:\n";
 
    std::vector<int> v { 3, 2, 4, 1, 5, 9 };
 
    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::pop_heap(v.begin(), v.end());
 
    std::cout << "after pop_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    auto top = v.back();
    v.pop_back();
    std::cout << "former top element: " << top << '\n';
 
    std::cout << "after removing the former top element, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n' << '\n';
 
    std::cout << "Min heap:\n";
 
    std::vector<int> v1 { 3, 2, 4, 1, 5, 9 };
 
    std::cout << "initially, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';
 
    std::make_heap(v1.begin(), v1.end(), std::greater<int>{});
 
    std::cout << "after make_heap, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';
 
    std::pop_heap(v1.begin(), v1.end(), std::greater<int>{});
 
    std::cout << "after pop_heap, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';
 
    auto top1 = v1.back();
    v1.pop_back();
    std::cout << "former top element: " << top1 << '\n';
 
    std::cout << "after removing the former top element, v1: ";
    for (auto i : v1) std::cout << i << ' ';
    std::cout << '\n';
    //result:
    Max heap:
    initially, v: 3 2 4 1 5 9 
    after make_heap, v: 9 5 4 1 2 3 
    after pop_heap, v: 5 3 4 1 2 9 
    former top element: 9
    after removing the former top element, v: 5 3 4 1 2 
     
    Min heap:
    initially, v1: 3 2 4 1 5 9 
    after make_heap, v1: 1 2 4 3 5 9 
    after pop_heap, v1: 2 3 4 9 5 1 
    former top element: 1
    after removing the former top element, v1: 2 3 4 9 5
```
* push_heap()
```cpp
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    v.push_back(6);
 
    std::cout << "before push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::push_heap(v.begin(), v.end());
 
    std::cout << "after push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    //result:
    v: 9 5 4 1 1 3 
    before push_heap: 9 5 4 1 1 3 6 
    after push_heap:  9 5 6 1 1 3 4
```
* sort_heap()  
转换最大堆 [first, last) 为以升序排序的范围。产生的范围不再拥有堆属性。  
函数的第一版本用 operator< 比较元素，第二版本用给定的比较函数 comp 比较。
```cpp
    std::vector<int> v = {3, 1, 4, 1, 5, 9}; 
 
    std::make_heap(v.begin(), v.end());
 
    std::cout << "heap:\t";
    for (const auto &i : v) {
        std::cout << i << ' ';
    }   
 
    std::sort_heap(v.begin(), v.end());
 
    std::cout << "\nsorted:\t";
    for (const auto &i : v) {                                                   
        std::cout << i << ' ';
    }   
    std::cout << '\n';
    //result:
    heap:   9 4 5 1 1 3 
    sorted: 1 1 3 4 5 9
```
* is_sorted()
```cpp
    int digits[] = {3, 1, 4, 1, 5};
 
    for (auto i : digits) std::cout << i << ' ';
    std::cout << ": is_sorted: " << std::boolalpha
              << std::is_sorted(std::begin(digits), std::end(digits)) << '\n';
 
    std::sort(std::begin(digits), std::end(digits));
 
    for (auto i : digits) std::cout << i << ' ';
    std::cout << ": is_sorted: "
              << std::is_sorted(std::begin(digits), std::end(digits)) << '\n';
    //result:
    3 1 4 1 5 : is_sorted: false
    1 1 3 4 5 : is_sorted: true
```
* nth_element()  
nth_element 是部分排序算法，它重排 [first, last) 中元素，使得：
- nth 所指向的元素被更改为假如 [first, last) 已排序则该位置会出现的元素。
- 这个新的 nth 元素前的所有元素小于或等于新的 nth 元素后的所有元素。
```cpp
  std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

  std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
  std::cout << "The median is " << v[v.size() / 2] << '\n';

  std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
  std::cout << "The second largest element is " << v[1] << '\n';
  //result:
  The median is 5
  The second largest element is 7
```
* max_element()/min_element()  
注意返回的是迭代器
```cpp
  //max_element
  static bool abs_compare(int a, int b)
  {
      return (std::abs(a) < std::abs(b));
  }
   
  int main()
  {
      std::vector<int> v{ 3, 1, -14, 1, 5, 9 }; 
      std::vector<int>::iterator result;
   
      result = std::max_element(v.begin(), v.end());
      std::cout << "max element at: " << std::distance(v.begin(), result) << '\n';
   
      result = std::max_element(v.begin(), v.end(), abs_compare);
      std::cout << "max element (absolute) at: " << std::distance(v.begin(), result) << '\n';
  }
  //result:
  max element at: 5
  max element (absolute) at: 2

  //min_element
  std::vector<int> v{3, 1, 4, 1, 5, 9};
   
  std::vector<int>::iterator result = std::min_element(std::begin(v), std::end(v));
  std::cout << "min element at: " << std::distance(std::begin(v), result);
  //result:
  min element at: 1
```
* merge()  
归并二个已排序范围 [first1, last1) 和 [first2, last2) 到始于 d_first 的一个已排序范围中。  
注意 v3.size() 要大于或等于 v1.size() + v2.size();
```cpp
  vector<int> v1 = {1, 2, 3, 4, 7, 9, 100};
  vector<int> v2 = {1, 2, 5, 6, 8, 10, 99};
  vector<int> v3(14);
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
  for (auto val : v3) {
    cout << val << " ";
  }
```
* mismatch()  
返回值 : 拥有指向首二个不相等元素的迭代器的 std::pair 。  
若比较抵达 last1 或 last2 中首先发生者时未找到不匹配，则 pair 保有尾迭代器和来自另一范围的对应迭代器。
```cpp
  string s1 = "abc", s2 = "abd";
  cout << *mismatch(s1.begin(), s1.end(), s2.begin()).first << " "
       << *mismatch(s1.begin(), s1.end(), s2.begin()).second;
  //result:
  c d
```
* other: sort()/fill()/reverse()
#### other function
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
- \<cmath\>
  ```cpp
      - pow(r, p)
      - abs()
      - floor()/ceil()
      cout << floor(1.2) << " " << floor(-1.2) << "\n";
      cout << ceil(1.2) << " " << ceil(-1.2);
      //result:
      1 -2
      2 -1
      - sqrt(double x)
      - log()
      - sin(), cos(), tan(), asin()...
      - round()
      cout << round(1.2) << " " << round(1.5) << " " << round(1.6) << "\n";
      cout << round(-1.2) << " " << round(-1.5) << " " << round(-1.6) << "\n";
      //result:
      1 2 2
      -1 -2 -2
  ```
- \<functional>\
  ```cpp
      - std::less<type>() // 从小到大 <
      - std::greater<type>() // >
      - std::less_equal<type>() // <=
      - std::grater_equal<type>() // >=  
  ```
- \<stdio\>
```cpp
    - sscanf
    - sprintf 
    char a[50] = "1.234", b[50];
    double f;
    sscanf(a, "%lf", &f);
    cout << f << endl;
    sprintf(b, "%.1f", f);
    cout << b;
    //result:
    1.234
    1.2
```
- other
```cpp
  - stoi()/stol()/stof()/stod()等
```

#### 总结/注意事项
- 所有非零值都转为true,零值转为false。 
- 圆周率: double pi = acos(-1.0);
- vector<vector<int> > v; v.resize(n, vector<int>(m));
- printf("%s", s.c_str());
- 'A' = 65; 'a' = 97;  'A' + 32 = 'a';
- pirntf("%02d", 4)和printf("%2d", 4)的区别; out1 为 04， out2 为 4.
- long long int 长度为64, long int 为32,int 一般为32.
- double精度为16位,float精度为7位，int可储存10的9次方大的数据，long和long long可储存10的18次方的大数据 
- 在使用getline读入一整行时，若是前面是使用getchar()、cin这类读入了一个字母，但是不会读入后续换行\n符号或者空格的输入时，再接getline()就容易出现问题。应该使用一个getchar()吃掉回车。
- 运行超时的话，可以将unorder_map 换成 map，unorder_map的插入、删除等为常数时间，而map的为对数时间。
- 排序建议用引用传参，特别是排vector<int> a这种，这样更快，虽然有时候不用引用传参也能通过，但还是尽量用，养成好习惯
- 判断素数时，有时需要把0和1也要考虑进去。
- node *root = NULL;在main里记得要加等于NULL;
- insert(node *&root); 记得传引用;
- 如果有表达错误，看需不需要最后加一行！！！1119测试点最后要加一行！！！注意点
- for (int i = 0; i < (int)v.size() - 1; i++); 记得v.size()前面加int, 不然会断错误!!!

#### problem
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
