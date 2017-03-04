//
//  PhoneNumberAreaQuery.c
//  PhoneNumberAreaQuery
//
//  Created by HeJeffery on 2017/3/4.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "PhoneNumberAreaQuery.h"

#define NUMBER 324144

// 删掉'\0'
void delWrapChar(char *str) {
    
    while (*str != '\0') {
        
        if (*str == '\n') {
            *str = '\0';
        }
        str++;
    }
}

void writePhoneNumberAreaDataToBinaryFile(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL) {
        return;
    }
    
    FILE *rfile = fopen(sourcePath, "rb");
    if (rfile == NULL) {
        return;
    }
    
    PhoneArea *phoneAreas = (PhoneArea *)malloc(sizeof(PhoneArea) * NUMBER);
    
    int i = 0;
    while (!feof(rfile)) {
        char phoneAreaString[256] = {0};
        fgets(phoneAreaString, 256, rfile);
        
        struct PhoneArea phoneArea = {0};
        // 删除换行
        delWrapChar(phoneAreaString);
        sscanf(phoneAreaString, "%[^,],%[^,],%[^,]", phoneArea.phoneNumber, phoneArea.phoneArea, phoneArea.phoneType);
        
        phoneAreas[i] = phoneArea;
        i++;
    }
    
    fclose(rfile);
    
    FILE *wfile = fopen(targetPath, "wb");
    if (wfile == NULL) {
        free(phoneAreas);
        return;
    }
    
    fwrite(phoneAreas, sizeof(PhoneArea), NUMBER, wfile);
    
    fclose(wfile);
    
    free(phoneAreas);
}
