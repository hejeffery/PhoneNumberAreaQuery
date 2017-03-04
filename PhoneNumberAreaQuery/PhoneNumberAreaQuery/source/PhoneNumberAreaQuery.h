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
 *  把phone_number_area.txt的数据转换为二进制文件
 *
 *  @param sourcePath 源文件的路径
 *  @param targetPath 目标文件的路径
 */
void writePhoneNumberAreaDataToBinaryFile(const char *sourcePath, const char *targetPath);

#endif /* PhoneNumberAreaQuery_h */
