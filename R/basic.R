# 基础语法
print("Hello, World")
print(123)
print(3e2) # e??
5e-2
cat(1, "加", 1, "等于", 2, "\n")
cat("RUNOOB", file = ".\\r_test.txt")
cat("GOOGLE", file = ".\\r_test.txt", append = TRUE)
sink("r_test.txt", split = TRUE) # 控制台同样输出
for (i in 1:5) {
  print(i)
}
sink() # 取消输出到文件
sink("r_test.txt", append = TRUE) # 控制台不输出，追加写入文件
print("RUNOOB")
readLines(".\\r_test.txt")
print(getwd())
setwd(dir)

# 基础运算
32 %% 2
32 %/% 2
v <- c(2, 4, 6, 9)
t <- c(1, 4, 7, 9)
print(v > t)
print(v >= t)
print(v < t)
print(v <= t)
print(v != t)
print(v == t)
v <- c(3, 1, TRUE, 2 + 3i)
t <- c(0, 1, FALSE, 2 + 3i)
print(v & t)
print(v | t)
print(!v)
print(v && t)
print(v || t)
# 1 到 10 的向量
v <- 1:10
print(v)
# 判断数字是否在向量 v 中
v1 <- 3
v2 <- 15
print(v1 %in% v)
print(v2 %in% v)
# 矩阵与它转置的矩阵相乘
M <- matrix(c(2, 6, 5, 1, 10, 4), nrow = 2, ncol = 3, byrow = TRUE)
t <- M %*% t(M)
print(t)
sqrt(4)
exp(1)
log2(4)
log10(100)
log(exp(1))
# 当取整位是偶数的时候，五也会被舍去，
round(1.55555, 4)
floor(1.5)
ceiling(1.5)
sin(pi / 6) # cos tan asin acos atan
dnorm(0)
pnorm(0)
qnorm(0.95)
rnorm(3, 5, 2)

# 向量
c(1.1, 1.2, 1.3) - 0.5
v <- c(1, 2, 4, 3, 5)
v[c(2, 3, 4)]
v[c(2, 4, 3)]
v[2:4]
v[-2]
v[-2:-4]
v[v < 3]
sort(v)
rev(v)
order(v)
v[order(v)]
sum(v)
mean(v)
var(v)
sd(v)
min(v)
max(v)
range(v)
which(v == 3)
which.max(v)
which.min(v)
seq(1, 9, 2) # seq(from = 1, to = 9, by = 2);
seq(0, 1, length.out = 3)
req(0, 5)
length(c(NA, NA, NULL))
c(NA, NA, NULL, NA)
c(1, 2, 3) > 2
a <- c(1, 2, 3)
b <- a > 2
print(b)
which(b)
vector <- c(10, 40, 78, 64, 53, 62, 69, 70)
print(vector[which(vector >= 60 & vector < 70)])
all(c(TRUE, TRUE, TRUE))
all(c(TRUE, TRUE, FALSE))
any(c(TRUE, FALSE, FALSE))
any(c(FALSE, FALSE, FALSE))
toupper("Runoob")
tolower("Runoob")
nchar("中文", type = "bytes")
nchar("中文", type = "char")
substr("123456789", 1, 5)
substring("1234567890", 5)
as.numeric("12")
as.character(12.34)
strsplit("2022;3;7", ";")
gsub("/", "-", "2022/3/7")

# 矩阵
matrix(c(1:6), 2, 3)
m1 <- matrix(c(1:6), 2, 3, byrow = TRUE)
m1[1, 1]
colnames(m1) <- c("x", "y", "z")
rownames(m1) <- c("a", "b")
m1["a", ]
rownames <- c("row1", "row2", "row3", "row4")
colnames <- c("col1", "col2", "col3")
m1 <- matrix(c(3:14), nrow = 4, byrow = TRUE, dimnames = list(rownames, colnames))
print(m1)
m1 <- matrix(c(7, 9, -1, 4, 2, 3), nrow = 2)
m2 <- matrix(c(6, 1, 0, 9, 3, 2), nrow = 2)
result <- matrix1 * matrix2
cat("相乘结果：", "\n")
print(result)
m1 <- matrix(c(1, 2), 1, 2)
m2 <- matrix(c(3, 4), 2, 1)
m1 %*% m2
a <- matrix(c(1, 3, 2, 4), 2, 2)
solve(a)
t(a)
apply(a, 1, sum)
apply(a, 2, sum)

# 控制语句
x <- switch(3,
  "google",
  "runoob",
  "taobao",
  "weibo"
)
print(x)
youlike <- "runoob"
switch(youlike,
  google = "www.google.com",
  runoob = "www.runoob.com",
  taobao = "www.taobao.com"
)
x <- switch(4,
  "google",
  "runoob",
  "taobao"
)
cnt <- 2
repeat {
  print("Hello, World")
  cnt <- cnt + 1
  if (cnt > 5) {
    break
  }
}
cnt <- 2
while (cnt < 7) {
  print("Hello, World")
  cnt <- cnt + 1
}
v <- LETTERS[1:4]
for (val in v) {
  print(val)
}
v <- LETTERS[1:6]
for (i in v) {
  if (i == "D") {
    next
  }
  print(i)
}

# 函数
myfunction <- function(x) {
  (1 + x)
}
myfunction1(5)
myfuction2 <- function(a = 3, b = 6) {
  result <- a + b
  print(result)
}
myfunction2()
myfunction2(2, 6)
myfunction3 <- function(a, b) {
  print(a^2)
  print(a)
  if (a < 1) {
    print(b)
  } # 未使用到 b，所以不会报错
}
# 传入一个参数
myfunction3(6)

# 字符串
a <- "Google"
b <- "Runoob"
c <- "Taobao"
paste(a, b, c)
paste(a, b, c, sep = "-")
paste(letters[1:6], 1:6, sep = "", collapse = "=")
# 显示 9 位，最后一位四舍五入
result <- format(23.123456789, digits = 9)
print(result)
# 使用科学计数法显示
result <- format(c(6, 13.14521), scientific = TRUE)
print(result)
# 小数点右边最小显示 5 位，没有的以 0 补充
result <- format(23.47, nsmall = 5)
print(result)
# 将数字转为字符串
result <- format(6)
print(result)
# 宽度为 6 位，不够的在开头添加空格
result <- format(13.7, width = 6)
print(result)
# 左对齐字符串
result <- format("Runoob", width = 9, justify = "l")
print(result)
# 居中显示
result <- format("Runoob", width = 10, justify = "c")
print(result)

# list
list_data <- list("runoob", "google", c(11, 22, 33), 123, 51.23, 119.1)
print(list_data)
list_data <- list(c("Google", "Runoob", "TaoBao"), matrix(c(1, 2, 3, 4, 5, 6), nrow = 2), list("runoob", 12.3))
names(list_data) <- c("sites", "Numbers", "Lists")
print(list_data)
print(list_data[1])
print(list_data$Numbers)
list_data[4] <- "new elements"
print(list_data[4])
list_data[4] <- NULL
print(list_data[4])
list_data[3] <- "我来替换第三个元素"
print(list_data[3])
list1 <- list(1, 2, 3)
list2 <- list("Google", "Runoob", "Taobao")
list <- c(list1, list2)
print(list)
list1 <- list(c(1:5))
list2 <- list(c(10:14))
v1 <- unlist(list1)
v2 <- unlist(list2)
result <- v1 + v2
print(result)

# array
vector1 <- c(5, 9, 3)
vector2 <- c(10, 11, 12, 13, 14, 15)
result <- array(c(vector1, vector2), dim = c(3, 3, 3))
dim(result)
dim(result)[1]
dim(result)[2]
names(result)
print(result)
column.names <- c("COL1", "COL2", "COL3")
row.names <- c("ROW1", "ROW2", "ROW3")
matrix.names <- c("Matrix1", "Matrix2")
result <- array(c(vector1, vector2), dim = c(3, 3, 2), dimnames = list(row.names, column.names, matrix.names))
print(result)
names(result)
print(result[3, , 2])
print(result[1, 3, 2])
print(result[, , 2])
print(apply(result, c(1), sum))

# factor
x <- c("nan", "nv", "nan", "nv")
sex <- factor(x)
print(sex)
print(is.factor(sex))
x <- c("男", "女", "男", "男", "女", levels = c("男", "女"))
sex <- factor(x)
print(sex)
sex <- factor(c("f", "m", "f", "f", "m"), levels = c("f", "m"), labels = c("female", "male"), ordered = TRUE)
print(sex)
v <- gl(3, 4, labels = c("Google", "Runoob", "Taobao"))
print(v)

# Data frame
table <- data.frame(
  姓名 = c("张三", "李四"),
  工号 = c("001", "002"),
  月薪 = c(1000, 2000)
)
print(table)
str(table)
print(summary(table))
result <- data.frame(table$姓名, table$工号)
print(result)
table[1:2]
table[1:2, ]
table[c(1, 2), c(1, 2)]

# R数据重塑
# data frame 1
df1 <- data.frame(SiteId = c(1:6), Site = c("Google", "Runoob", "Taobao", "Facebook", "Zhihu", "Weibo"))
# data frame 2
df2 <- data.frame(SiteId = c(2, 4, 6, 7, 8), Country = c("CN", "USA", "CN", "USA", "IN"))
df1 <- merge(x = df1, y = df2, by = "SiteId")
print("----- INNER JOIN -----")
print(df1)
# FULL JOIN
df2 <- merge(x = df1, y = df2, by = "SiteId", all = TRUE)
print("----- FULL JOIN -----")
print(df2)
# LEFT JOIN
df3 <- merge(x = df1, y = df2, by = "SiteId", all.x = TRUE)
print("----- LEFT JOIN -----")
print(df3)
# RIGHT JOIN
df4 <- merge(x = df1, y = df2, by = "SiteId", all.y = TRUE)
print("----- RIGHT JOIN -----")
print(df4)
install.packages("MASS", repos = "https://mirrors.ustc.edu.cn/CRAN/")
install.packages("reshape2", repos = "https://mirrors.ustc.edu.cn/CRAN/")
install.packages("reshape", repos = "https://mirrors.ustc.edu.cn/CRAN/")
# 载入库
library(MASS)
library(reshape2)
library(reshape)
# 创建数据框
id <- c(1, 1, 2, 2)
time <- c(1, 2, 1, 2)
x1 <- c(5, 3, 6, 2)
x2 <- c(6, 5, 1, 4)
mydata <- data.frame(id, time, x1, x2)
# 整合
md <- melt(mydata, id = c("id", "time"))
md
# Print recasted dataset using cast() function
cast.data <- cast(md, id ~ variable, mean)
cast.data <- cast(md, id ~ variable, mean)
print(cast.data)
cat("\n")
time.cast <- cast(md, time ~ variable, mean)
print(time.cast)
cat("\n")
id.time <- cast(md, id ~ time, mean)
print(id.time)
cat("\n")
id.time.cast <- cast(md, id + time ~ variable)
print(id.time.cast)
cat("\n")
id.variable.time <- cast(md, id + variable ~ time)
print(id.variable.time)
cat("\n")
id.variable.time2 <- cast(md, id ~ variable + time)
print(id.variable.time2)

# packages
.libPaths()
library()
install.packages("XML", repos = "https://mirrors.ustc.edu.cn/CRAN/")
search()

# CSV file
data <- read.csv("sites.csv", encoding = "UTF-8")
print(data)
print(is.data.frame(data))
print(ncol(data))
print(nrow(data))
print(subset(data, likes == 222))
print(subset(data, likes > 1 & name == "Runoob"))
retval <- subset(data, likes == 222)
write.csv(retval, "runoob.csv")
write.csv(retval, "runoob.csv", row.names = FALSE)

# Excel file
install.packages("xlsx", repos = "https://mirrors.ustc.edu.cn/CRAN/")
# any(grep1("xlsx",installed.packages()))
library("xlsx")
# print(read.xlsx("sites.xlsx", sheetIndex = 1))
data <- read.xlsx("C:\\Users\\Fida\\Desktop\\Code\\R\\sites.xlsx", sheetIndex = 1)
print(data)
names(data)
# XML file

# JSON file

# MySQL连接

# 绘图
info <- c(1, 2, 4, 8)
names <- c("Google", "Runoob", "Taobao", "Weibo")
cols <- c("#ED1C24", "#22B14C", "#FFC90E", "#3f48CC")
pie(info, labels = names)
pie(info, labels = names, col = cols)
png(file = "runoob-pie.png", height = 300, width = 300)
pie(info, labels = names, col = cols)
install.packages("showtext", repos = "https://mirrors.ustc.edu.cn/CRAN/")
library(showtext)
font_add("SyHei", "SourceHanSansSC-Bold.otf")
font_files()
# 计算百分比
piepercent <- paste(round(100 * info / sum(info)), "%")
# 绘图
showtext.begin()
pie(info, labels = piepercent, main = "网站分析", col = cols, family = "SyHei")
showtext.end()
# 添加颜色样本标注
legend("topright", names, cex = 0.8, fill = cols)
cvd19 <- c(83534, 2640626, 585493)
barplot(cvd19)
showtext.begin()
barplot(cvd19,
  main = "新冠疫情条形图",
  col = c("#ED1C24", "#22B14C", "#FFC90E"),
  names.arg = c("中国", "美国", "印度"),
  family = "SyHei"
)
showtext.end()
curve(sin(x), -2 * pi, 2 * pi)
# 定义函数 f
f <- function(x) {
  if (x >= 0) {
    x
  } else {
    x^2
  }
}
# 生成自变量序列
x <- seq(-2, 2, length = 100)
# 生成因变量序列
y <- rep(0, length(x))
j <- 1
for (i in x) {
  y[j] <- f(i)
  j <- j + 1
}
# 绘制图像
plot(x, y, type = "l")
v <- c(7, 12, 28, 3, 41)
plot(v,
  type = "o", col = "red", xlab = "Month", ylab = "Rain fall",
  main = "Rain fall chart"
)
x <- c(10, 40)
y <- c(20, 60)
plot(x, y, "l")
plot(x, y, "o")
input <- mtcars[, c("wt", "mpg")]
plot(
  x = input$wt, y = input$mpg,
  xlab = "Weight",
  ylab = "Milage",
  xlim = c(2.5, 5),
  ylim = c(15, 30),
  main = "Weight vs Milage"
)
pairs(~ wt + mpg + disp + cyl, data = mtcars, main = "Scatterplot Matrix")

# R实例
## mean
x <- c(12, 27, 3, 4.2, 2, 2, 54, -21, 4, -2)
print(mean(x))
x <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20)
result.mean <- mean(x, trim = 0.3)
result.mean2 <- mean(c(4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17))
print(result.mean)
print(result.mean2)
x <- c(1, 2, 3, 4.5, 6, NA)
result.mean <- mean(x)
print(result.mean)
result.mean <- mean(x, na.rm = TRUE)
print(result.mean)
## median()
x <- c(1, 2, 3, 4, 5, 6, 7)
print(median(x))
x <- c(1, 2, 3, 4.5, 6, NA)
print(median(x))
print(median(x, na.rm = TRUE))
## 计算向量中出现最多的元素
getmode <- function(v) {
  uniqv <- unique(v)
  uniqv[which.max(tabulate(match(v, uniqv)))]
}
v <- c(2, 1, 2, 3, 1, 2, 3, 4, 1, 5, 5, 3, 2, 3)
print(getmode(v))
charv <- c("google", "runoob", "taobao", "runoob", "runoob")
print(getmode(charv))
## 线性回归
x <- c(151, 174, 138, 186, 128, 136, 179, 163, 152, 131)
y <- c(63, 81, 56, 91, 47, 57, 76, 72, 62, 48)
relation <- lm(y ~ x)
print(relation)
print(summary(relation))
a <- data.frame(x = 170)
print(predict(relation, a))
plot(y, x,
  col = "blue", main = "Height & Weight Regression",
  abline(lm(x ~ y)), cex = 1.3, pch = 16, xlab = "Weight in Kg", ylab = "Height in cm"
)