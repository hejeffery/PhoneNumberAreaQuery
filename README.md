# PhoneNumberAreaQuery
![Build Status](https://img.shields.io/badge/PhoneNumberAreaQuery-1.0.0-green.svg)
![Travis](https://img.shields.io/travis/rust-lang/rust.svg)
![npm](https://img.shields.io/npm/l/express.svg)

## 手机号码归属地查询
用c写的手机号码归属地查询。归属地的数据来源于百度。数据最新的更新日期：2017年03月04日。总共有324110条数据。

##编译要求
Xcode4+,
OS X 10.7+

##项目结构
###source
* PhoneNumberAreaQuery.c。包含处理原数据，和查询的方法

###resource
* phone_number_area.txt 手机号码归属地原数据
* phone_number_area_sorted.txt 排序后的手机号码归属地原数据
* phone_number_area_binary 手机号码归属地的二进制文件，用来真正查找的数据文件

##整体思路
* 用二分查找法在排序后的二进制归属地文件中查找。
* 1.对phone_number_area.txt文件中的数据进行排序，并输入到phone_number_area_sorted.txt中
* 2.创建一个结构体，封装数据
* 3.创建一个结构体数组，从phone_number_area_sorted.txt中加载数据，初始化结构体数组中的每一个数据，并把结构体数组写入phone_number_area_binary中
* 4.通过fseek和fread两个函数进行二分查找

##注意
* 注意项目运行中一定要修改相应的文件路径。


