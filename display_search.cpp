#include "gym.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

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

void timKiemHoiVien(HoiVien ds[], int n, const char tuKhoa[])
{
    int timThay = 0;
    printf("\n--> Ket qua tim kiem voi tu khoa \"%s\":\n", tuKhoa);

    HoiVien kq[100];
    int dem = 0;
    for (int i = 0; i < n; ++i)
    {
        // Kiem tra tu khoa co trong maHoiVien or hoTen
        if (strstr(ds[i].maHoiVien, tuKhoa) != NULL || strstr(ds[i].hoTen, tuKhoa) != NULL)
        {
            kq[dem] = ds[i];
            dem++;
        }
    }
    if (dem > 0)
    {
        hienThiDanhSach(kq, dem);
    } else
    {
        printf("[Thong bao] Khong tim thay hoi vien nao phu hop!\n");
    }
}

void hieuUngChuyenCanh()
{
    // Chuyen canh va cho doi
    for (int i = 0; i < 30; ++i)
    {
        printf("\n");
        Sleep(30);
    }

    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n");
    const char* loadingText = "           L O A D I N G . . .";
    for (int i = 0; loadingText[i] != '\0'; ++i)
    {
        printf("%c", loadingText[i]);
        Sleep(50);
    }

    Sleep(1000);

    system("cls");
}

int main()
{
    hienThiDanhSach();
    return 0;
}

