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
    
    writePhoneNumberAreaDataToBinaryFile("/Users/JefferyHe/Desktop/PhoneNumberAreaQuery/resource/phone_number_area.txt",
                                         "/Users/JefferyHe/Desktop/phone_number_area");
    
    return 0;
}
