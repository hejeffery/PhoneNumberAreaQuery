//
//  PhoneNumberAreaQuery.c
//  PhoneNumberAreaQuery
//
//  Created by HeJeffery on 2017/3/4.
//  Copyright © 2017年 HeJeffery. All rights reserved.
//

#include "PhoneNumberAreaQuery.h"

#define NUMBER 324110
#define PHONE_BASE_LENGTH 7

// 删掉'\0'
void delWrapChar(char *str) {
    while (*str != '\0') {
        
        if (*str == '\n') {
            *str = '\0';
        }
        str++;
    }
}

int comparePhoneArea(const void *phoneArea1, const void *phoneArea2) {
    return strcmp((*(PhoneArea *)phoneArea1).phoneNumber, (*(PhoneArea *)phoneArea2).phoneNumber);
}

void sortPhoneNumberAreaData(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL || targetPath == NULL) {
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
        // 删除换行
        delWrapChar(phoneAreaString);
        PhoneArea phoneArea = {0};
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
    
    // 先排序
    qsort(phoneAreas, NUMBER, sizeof(PhoneArea), comparePhoneArea);
    
    for (int i = 0; i < NUMBER; i++) {
        char str[256] = {0};
        sprintf(str, "%s,%s,%s\n", phoneAreas[i].phoneNumber, phoneAreas[i].phoneArea, phoneAreas[i].phoneType);
        fputs(str, wfile);
    }
    
    fclose(wfile);
    
    free(phoneAreas);
}

void writePhoneNumberAreaDataToBinaryFile(const char *sourcePath, const char *targetPath) {
    
    if (sourcePath == NULL || targetPath == NULL) {
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
        
        PhoneArea phoneArea = {0};
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

PhoneArea searchByPhoneNumber(const char *searchNumber, const char *binaryFilePath) {
    
    PhoneArea phoneArea = {0};
    if (searchNumber == NULL || binaryFilePath == NULL) {
        return phoneArea;
    }
    
    char number[12] = {0};
    strcpy(number, searchNumber);
    
    long searchNumberLength = strlen(number);
    
    
    if (searchNumberLength < PHONE_BASE_LENGTH) {
        return phoneArea;
    }
    
    if (searchNumberLength > PHONE_BASE_LENGTH) {
        number[PHONE_BASE_LENGTH] = '\0';
    }
    
    FILE *rfile = fopen(binaryFilePath, "rb");
    
    int head = 0;
    int tail = NUMBER;
    while (head <= tail) {

        int middle = (head + tail) * 0.5;
        fseek(rfile, sizeof(PhoneArea) * middle, SEEK_SET);
        fread(&phoneArea, sizeof(PhoneArea), 1, rfile);
        
        if (strcmp(number, phoneArea.phoneNumber) == 0) {
            return phoneArea;
            
        } else if (strcmp(number, phoneArea.phoneNumber) > 0) {
            head = middle + 1;

        } else {
            tail = middle - 1;
        }
    }

    fclose(rfile);
    
    return phoneArea;
}
