//
//  main.c
//  PhoneNumberAreaQuery
//
//  Created by HeJeffery on 2017/3/4.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include <stdio.h>

#include "PhoneNumberAreaQuery.h"

int main(int argc, const char * argv[]) {
    
    // 注意：以下三步分开独立运行。除了phone_number_area.txt文件的路径，其它的路径可以自己定义。
    
    
//    // 1.先对phone_number_area.txt进行排序，生成排序后的文件phone_number_area_sorted.txt
//    // 注意文件路径
//    sortPhoneNumberAreaData("/Users/JefferyHe/Documents/Github/PhoneNumberAreaQuery/PhoneNumberAreaQuery/resource/phone_number_area.txt",
//                            "/Users/JefferyHe/Desktop/phone_number_area_sorted.txt");
    
//    // 2.把phone_number_area_sorted.txt中的数据通过二进制的方式写入phone_number_area_binary
//    // 注意文件路径
//    writePhoneNumberAreaDataToBinaryFile("/Users/JefferyHe/Documents/Github/PhoneNumberAreaQuery/PhoneNumberAreaQuery/resource/phone_number_area_sorted.txt",
//                                         "/Users/JefferyHe/Desktop/phone_number_area_binary");
    
//    // 3.搜索
//    // 注意文件路径
//    PhoneArea phoneArea = searchByPhoneNumber("1862333", "/Users/JefferyHe/Desktop/phone_number_area_binary");
//    if (strlen(phoneArea.phoneNumber) != 0) {
//        printf("手机号 = %s, 区域 = %s, 类型 = %s\n", phoneArea.phoneNumber, phoneArea.phoneArea, phoneArea.phoneType);
//
//    } else {
//        printf("没有找到手机号\n");
//    }
    
    return 0;
}
