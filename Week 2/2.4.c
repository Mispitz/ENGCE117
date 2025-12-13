#include <stdio.h>
#include <string.h>

// กำหนดขนาดของ Array ไว้ล่วงหน้า (สามารถปรับเปลี่ยนได้)
#define MAX_WORDS 20
#define MAX_LEN 20

// Function Prototype
void explode(char str1[], char splitter, char str2[MAX_WORDS][MAX_LEN], int *count);

int main() {
    // ข้อมูลนำเข้าตามโจทย์
    char str1[] = "I/Love/You";
    char splitter = '/';
    
    // ตัวแปรสำหรับเก็บผลลัพธ์
    char str2[MAX_WORDS][MAX_LEN];
    int count = 0;

    // เรียกใช้ฟังก์ชัน
    explode(str1, splitter, str2, &count);

    // แสดงผลลัพธ์เพื่อตรวจสอบความถูกต้อง
    printf("Output:\n");
    for (int i = 0; i < count; i++) {
        printf("str2[%d] = \"%s\"\n", i, str2[i]);
    }
    printf("count = %d\n", count);

    return 0;
}

// Function Definition
void explode(char str1[], char splitter, char str2[MAX_WORDS][MAX_LEN], int *count) {
    int i = 0; // ตัวนับตำแหน่งของ str1 (ต้นฉบับ)
    int r = 0; // ตัวนับแถวของ str2 (คำที่เท่าไหร่)
    int c = 0; // ตัวนับคอลัมน์ของ str2 (ตัวอักษรที่เท่าไหร่ในคำนั้น)

    // วนลูปจนกว่าจะเจอจุดสิ้นสุดของ string ต้นฉบับ
    while (str1[i] != '\0') {
        if (str1[i] == splitter) {
            // กรณีเจอตัวคั่น (/)
            str2[r][c] = '\0'; // ปิดท้ายคำเก่าด้วย NULL Character
            r++;               // ขยับไปเก็บคำถัดไป (แถวใหม่)
            c = 0;             // รีเซ็ตตัวนับตัวอักษรเป็น 0
        } else {
            // กรณีเป็นตัวอักษรปกติ
            str2[r][c] = str1[i]; // ก๊อปปี้ตัวอักษรลงไป
            c++;                  // ขยับไปช่องถัดไป
        }
        i++; // ขยับไปตัวถัดไปของ str1
    }

    // *** สำคัญมาก *** // เมื่อจบลูป คำสุดท้ายจะยังไม่ได้ปิดท้ายด้วย \0 และยังไม่ถูกนับ
    str2[r][c] = '\0'; 
    
    // อัปเดตค่า count ผ่าน pointer (จำนวนคำ = index แถวสุดท้าย + 1)
    *count = r + 1;
}