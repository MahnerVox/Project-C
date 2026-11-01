#include "gym.h"
#include "stats_valid.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#ifdef _WIN32
#define LENH_XOA_MAN_HINH "cls"
static void nghi(int ms)
{
    Sleep(ms);
}

#else
#include <unistd.h>
#define LENH_XOA_MAN_HINH "clear"
static void nghi(int ms)
{
    usleep((useconds_t)ms * 1000);
}

#endif
#define DO_RONG_BANG 108
static void inDuongKe(char c)
{
    for (int i = 0; i < DO_RONG_BANG; i++) {
        putchar(c);
    }
    putchar('\n');
}

static int chuaChuoiKhongPhanBietHoa(const char s[], const char tuKhoa[])
{
    for (int i = 0; s[i] != '\0'; i++) {
        int j = 0;
        while (tuKhoa[j] != '\0' && s[i + j] != '\0' &&
               tolower((unsigned char)s[i + j]) == tolower((unsigned char)tuKhoa[j])) {
            j++;
        }
        if (tuKhoa[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

void hienThiDanhSach(HoiVien ds[], int n)
{
    if (n == 0) {
        printf("\n[Thong bao] Danh sach hoi vien hien dang rong!\n");
        return;
    }

    printf("\n");
    inDuongKe('=');
    printf("%*s\n", (DO_RONG_BANG + 18) / 2, "DANH SACH HOI VIEN");
    inDuongKe('=');
    printf("| %-4s | %-10s | %-20s | %-10s | %-10s | %-8s | %-9s | %-12s |\n",
           "STT", "Ma HV", "Ho va Ten", "Goi Tap", "So Thang", "Can Nang", "Chieu Cao", "Gia Tien");
    inDuongKe('-');

    for (int i = 0; i < n; i++) {
        printf("| %-4d | %-10s | %-20s | %-10s | %-10d | %-8.1f | %-9.2f | %-12.0f |\n",
               i + 1,
               ds[i].maHoiVien,
               ds[i].hoTen,
               ds[i].goiTap,
               ds[i].soThangDangKy,
               ds[i].canNang,
               ds[i].chieuCao,
               ds[i].giaTien);
    }
    inDuongKe('=');
}

void timKiemHoiVien(HoiVien ds[], int n, const char tuKhoa[])
{
    printf("\n--> Ket qua tim kiem voi tu khoa \"%s\":\n", tuKhoa);

    HoiVien kq[MAX_HOI_VIEN];
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        if (chuaChuoiKhongPhanBietHoa(ds[i].maHoiVien, tuKhoa) ||
            chuaChuoiKhongPhanBietHoa(ds[i].hoTen, tuKhoa)) {
            kq[dem] = ds[i];
            dem++;
        }
    }
    if (dem > 0) {
        hienThiDanhSach(kq, dem);
    } else {
        printf("[Thong bao] Khong tim thay hoi vien nao phu hop!\n");
    }
}

void hieuUngChuyenCanh()
{
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
        nghi(10);
    }

    nghi(300);

    system("cls");
}

void sapXepTheoGiaTien(HoiVien ds[], int n, int tangDan)
{
    if (n <= 0) {
        printf("\n[Thong bao] Danh sach hoi vien hien dang rong!\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dieuKien = tangDan ? (ds[i].giaTien > ds[j].giaTien) : (ds[i].giaTien < ds[j].giaTien);
            if (dieuKien) {
                HoiVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("\n[Thong bao] Da sap xep danh sach theo gia tien (%s)!\n", tangDan ? "Tang dan" : "Giam dan");
}
