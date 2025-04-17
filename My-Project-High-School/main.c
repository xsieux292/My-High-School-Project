//
//  main.c
//  My-Project-High-School
//
//  Created by Aphichit's Macbook on 17/4/2568 BE.
//

//โปรแกรมนับหาจำนวนการถูกใจของคอมเมนต์ที่มากที่สุด

#include <stdio.h>
#include <string.h>
int main(){
    int n,count=0,max=0,cn=1;
    
    printf("\tโปรแกรมหาคอมเมนต์ที่มีการกดไลค์มากที่สุด\n");
    printf("--------------------------------------\n");
    printf("ป้อนค่าของจำนวนการกดไลค์ทั้งหมด : ");
    scanf("%d",&n);
    printf("--------------------------------------\n");
    printf("ป้อนค่าของรายชื่อการกดไลค์คอมเมนต์ : \n");
    
    //ความยาวของชื่อคนที่คอมเมนต์ต้องไม่เกิน1000และไม่เว้นวรรค
    char comment[n][1000],set_com[n][1000];
    for (int i = 0; i < n; i++) {
        printf("%d) ",i+1);
        scanf("%s", comment[i]);
        
        //ตรวจสอบว่าความคิดเห็นนี้มีอยู่ใน set_com หรือไม่
        //ถ้ามี is_duplicate==1 ถ้าไม่มี is_duplicate==0
        int is_duplicate = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(set_com[j], comment[i]) == 0) {
                //ใช้strcmp()เปรียบเทียบค่า
                is_duplicate = 1;
                break;
            }
        }

        //ถ้าไม่ซ้ำ ให้เพิ่มลงใน set_com
        if (!is_duplicate) {
        strcpy(set_com[count], comment[i]);
        count++;
        }
    }
    int countlike[count];
    
    //i=index ของตัวข้อมูลที่เราจะตรวจสอบ
    //j=index ของข้อมูลในset เพื่อที่ขะหาว่ามีตัวซ้ำกันไหม
    for (int i = 0; i < count; i++) {
        int curcount=0;
        for (int j=0; j<n; j++) {
            
            //check ว่า ค่า set_com[i] ซ้ำกับข้อมูลใน comment ไหม ถ้าซ้ำให้เพิ่มค่า curcount
            if (strcmp(set_com[i], comment[j]) == 0) {
                curcount++;
            }
        }
        
        //หลังจาก check ทุกตัวใน comment เสร็จ ให้เพิ่มค่าการจำนวนการกดไลค์ลงใน countlike ที่ index เดียวกันกับ set_com ตัวที่เช็ค
        countlike[i]=curcount;
    }
    
    //หาค่าการกดlikeที่มากที่สุด
    for (int i=0; i<count; i++) {
        if (countlike[i]>max) {
            max=countlike[i];
        }
    }
    
    printf("--------------------------------------\n");
    
    //แสดงผลค่าที่มีไลค์มากสุดออกมา
    
    printf("คอมเมนต์ที่มีการกดไลค์มากที่สุด มีจำนวนการกดไลค์ %d ไลค์ และมีรายการดังนี้ : \n",max);
    
    for (int i=0; i<count; i++) {
        if (countlike[i]==max) {
            printf("%d) ",cn);
            printf("%s\n",set_com[i]);
            cn++;
        }
    }
    
    printf("รายการของจำนวนการโดนกดไลค์ของแต่ละคอมเมนต์ : \n");
    
    cn=1;
    for (int i=0; i<count; i++) {
        printf("%d) ",cn);
        
        printf("%s โดนกดไลค์จำนวน %d\n",set_com[i],countlike[i]);
        
        cn++;
    }
    
    printf("-----------------END------------------\n");
    
    return 0;
}
