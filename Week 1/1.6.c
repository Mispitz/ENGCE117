#include <stdio.h>
#include <stdlib.h> 

// ฟังก์ชันถูกเปลี่ยนให้ส่งคืนตัวชี้ไปยังเมทริกซ์ (int*)
int *getmatrix( int *row, int *col);

int main(){
    // 'data' จะเก็บที่อยู่ของเมทริกซ์ทั้งหมดที่จัดสรรโดย malloc()
    int *data = NULL; 
    int m, n; // m=row, n=col
    
    // เรียกฟังก์ชัน: รับที่อยู่ของเมทริกซ์ที่จัดสรรมาเก็บใน 'data'
    // และส่งที่อยู่ของ m, n เพื่อให้ฟังก์ชันแก้ไขขนาด
    data = getmatrix( &m, &n); 

    // ตรวจสอบว่าจัดสรรหน่วยความจำสำเร็จหรือไม่
    if (data != NULL && m > 0 && n > 0)
    {
        printf("\n--- เมทริกซ์ที่เข้าถึงได้ใน main() ---\n");
        
        // แสดงผลเมทริกซ์ที่เก็บในรูปแบบ 1D ด้วยสูตรการคำนวณ 2D
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // สูตรการเข้าถึง: data[i * n + j]
                printf("%d ", data[i * n + j]); 
            }
            printf("\n");
        }
        
        // **สำคัญมาก:** ต้องคืนหน่วยความจำที่จัดสรรโดย malloc()
        free(data);
        data = NULL;
    } 
    else 
    {
        printf("\nไม่สามารถสร้างเมทริกซ์ได้.\n");
    }

    return 0;
}

// ฟังก์ชันนี้จะจัดการการจัดสรรหน่วยความจำและส่งคืนตัวชี้
int *getmatrix( int *row, int *col){
    
    printf("Enter number of rows: ");
    if (scanf("%d", row) != 1 || *row <= 0) return NULL;
    
    printf("Enter number of columns: ");
    if (scanf("%d", col) != 1 || *col <= 0) return NULL;
    
    int total_size = (*row) * (*col);
    
    // **ส่วนที่แก้ไข:** จัดสรรหน่วยความจำบน HEAP ด้วย malloc()
    // หน่วยความจำนี้จะคงอยู่แม้ฟังก์ชัน getmatrix จะจบลงแล้ว
    int *matrix_ptr = (int *)malloc(sizeof(int) * total_size);

    if (matrix_ptr == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; // คืน NULL เมื่อจัดสรรไม่สำเร็จ
    }
    
    printf("\n--- ป้อนข้อมูลสำหรับเมทริกซ์ %d แถว x %d คอลัมน์ ---\n", *row, *col);

    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf("Enter num [%d][%d]: ", i + 1, j + 1);
            
            // อ่านค่าเข้าสู่หน่วยความจำที่ถูกชี้โดย matrix_ptr ด้วยสูตร 1D
            scanf("%d", &matrix_ptr[i * (*col) + j]);
        }
    }

    printf("\n--- ข้อมูลที่คุณป้อน (ใน getmatrix) ---\n");
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf("%d ", matrix_ptr[i * (*col) + j]);
        }
        printf("\n");
    }

    // คืนตัวชี้ไปยังตำแหน่งเริ่มต้นของเมทริกซ์ที่จัดสรรบน Heap
    return matrix_ptr;
}