#include <stdio.h>
#include <string.h>

// Function Prototype
void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    // เตรียมตัวแปรตามโจทย์
    char out[20][10]; // เก็บได้สูงสุด 20 คำ คำละไม่เกิน 10 ตัวอักษร
    int num;

    // เรียกใช้ฟังก์ชัน (สังเกตการส่ง &num เพื่อรับค่าจำนวนคำกลับมา)
    explode("I/Love/You", '/', out, &num);

    // แสดงผลลัพธ์
    printf("Count = %d\n", num);
    for(int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }

    return 0;
}

// Function Definition
void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0; // ตำแหน่งตัวอักษรของข้อความต้นฉบับ
    int r = 0; // แถว (คำที่เท่าไหร่)
    int c = 0; // คอลัมน์ (ตัวอักษรตัวที่เท่าไหร่ในคำนั้น)

    *count = 0; // รีเซ็ตค่าเริ่มต้น

    while (str1[i] != '\0') {
        if (str1[i] == splitter) {
            // เมื่อเจอตัวคั่น (/) ให้ปิดท้ายคำเดิม
            str2[r][c] = '\0';
            r++;    // ขึ้นคำใหม่ (แถวใหม่)
            c = 0;  // เริ่มตัวอักษรแรกใหม่
        } else {
            // ถ้าไม่ใช่ตัวคั่น ให้เก็บตัวอักษรลงไป
            str2[r][c] = str1[i];
            c++;
        }
        i++;
    }
    
    // จัดการคำสุดท้าย (เพราะ loop จบก่อนที่จะได้ปิดคำสุดท้าย)
    str2[r][c] = '\0';
    
    // นับจำนวนคำทั้งหมด (index เริ่มที่ 0 ดังนั้นจำนวนคือ r + 1)
    *count = r + 1;
}