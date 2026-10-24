#include "gym.h"
#include <stdio.h>

void hienThiDanhSach(HoiVien ds[], int n)
{
    if (n == 0) {
        printf("\n[Thong bao] Danh sach hoi vien hien dang rong!\n");
        return;
    }

    printf("\n================================ DANH SACH HOI VIEN ================================\n");
    printf("| %-4s | %-10s | %-20s | %-10s | %-10s | %-8s | %-12s |\n",
           "STT", "Ma HV", "Ho va Ten", "Goi Tap", "So Thang", "Can Nang", "Gia Tien");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %-4d | %-10s | %-20s | %-10s | %-10d | %-8.1f | %-12.0f |\n",
               i + 1,
               ds[i].maHoiVien,
               ds[i].hoTen,
               ds[i].goiTap,
               ds[i].soThangDangKy,
               ds[i].canNang,
               ds[i].giaTien);
    }
    printf("===================================================================================\n");
}
<<<<<<< HEAD
void timKiemHoiVien(HoiVien ds[], int n, const char tuKhoa[])
{
    
}

int main()
{
    hienThiDanhSach();
    return 0;
}
=======
>>>>>>> 9ae31ee84a6ae1b02df9920b64be4eb9f62fcc2e
