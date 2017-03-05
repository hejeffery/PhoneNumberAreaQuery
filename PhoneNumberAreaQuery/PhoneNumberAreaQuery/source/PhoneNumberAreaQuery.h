//
//  PhoneNumberAreaQuery.h
//  PhoneNumberAreaQuery
//
//  Created by HeJeffery on 2017/3/4.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#ifndef PhoneNumberAreaQuery_h
#define PhoneNumberAreaQuery_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct PhoneArea PhoneArea;

struct PhoneArea {
    
    char phoneNumber[8];
    char phoneArea[36];
    char phoneType[28];
};

/**
 *  把phone_number_area.txt中的数据按电话号码的升序排序
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void sortPhoneNumberAreaData(const char *sourcePath, const char *targetPath);

/**
 *  把phone_number_area.txt的数据转换为二进制文件
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void writePhoneNumberAreaDataToBinaryFile(const char *sourcePath, const char *targetPath);

/**
 *  搜索号码
 *
 *  @param searchNumber 需要搜索的号码
 *  @param binaryFilePath 二进制文件
 */
PhoneArea searchByPhoneNumber(const char *searchNumber, const char *binaryFilePath);

#endif /* PhoneNumberAreaQuery_h */
