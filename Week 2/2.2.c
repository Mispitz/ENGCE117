#include <stdio.h>
#include <string.h>

// โปรโตไทป์ตามโจทย์
char* reverse(char str1[]);

int main() {
    char text[50] = "I Love You";
    char *out;
    
    // เรียกใช้ฟังก์ชัน
    out = reverse(text);
    
    // แสดงผลลัพธ์
    printf("Original: %s\n", text);
    printf("Reversed: %s\n", out);
    
    return 0;
}

char* reverse(char str1[]) {
    // ต้องประกาศเป็น static เพื่อให้ค่าไม่หายไปเมื่อจบฟังก์ชัน
    static char str2[50]; 
    
    int len = strlen(str1);
    int j = 0;

    // วนลูปจากตัวท้ายสุดมาหน้าสุด
    for (int i = len - 1; i >= 0; i--) {
        str2[j] = str1[i];
        j++;
    }
    
    str2[j] = '\0'; // อย่าลืมปิดท้ายสตริง
    
    return str2; // ส่ง address ของ str2 กลับไป
}