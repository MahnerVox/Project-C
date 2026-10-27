#include <stdio.h>
#include "gym.h"
#include "stats_valid.h"

void xoaBoNhoDem()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
int soSanhChuoi(const char s1[], const char s2[])
{
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] - s2[i];
}
int kiemTraMaTrung(HoiVien ds[], int n, const char ma[])
{
    int i;
    for (i = 0; i < n; i++) {
        if (soSanhChuoi(ds[i].maHoiVien, ma) == 0) {
            return 1;
        }
    }
    return 0;
}
int nhapSoNguyenDuong(const char thongBao[])
{
    int so, c;
    while (1) {
        printf("%s", thongBao);
        if (scanf("%d", &so) == 1) {
            c = getchar();
            if (c == '\n' && so > 0) {
                return so;
            }
            if (c != '\n') {
                xoaBoNhoDem();
            }
        } else {
            xoaBoNhoDem();
        }
        printf("Gia tri khong hop le! Vui long nhap so nguyen duong.\n");
    }
}
float nhapSoThucDuong(const char thongBao[])
{
    float so;
    int c;
    while (1) {
        printf("%s", thongBao);
        if (scanf("%f", &so) == 1) {
            c = getchar();
            if (c == '\n' && so > 0) {
                return so;
            }
            if (c != '\n') {
                xoaBoNhoDem();
            }
        } else {
            xoaBoNhoDem();
        }
        printf("Gia tri khong hop le! Vui long nhap so thuc duong.\n");
    }
}
float tinhBMI(HoiVien hv)
{
    float chieuCaoM = hv.chieuCao / 100;
    if (chieuCaoM <= 0) {
        return 0;
    }
    return hv.canNang / (chieuCaoM * chieuCaoM);
}
void inPhanLoaiBMI(float bmi)
{
    if (bmi < 18.5) {
        printf("Gay");
    } else if (bmi < 25) {
        printf("Binh thuong");
    } else if (bmi < 30) {
        printf("Thua can");
    } else {
        printf("Beo phi");
    }
}
float tinhTongDoanhThu(HoiVien ds[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].giaTien; 
    } 
    return tong;
}
float tinhCanNangTrungBinh(HoiVien ds[], int n) {
    float tong = 0;
    if (n <= 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        tong += ds[i].canNang;
    }
    return tong / n;
}
int demGoiVip(HoiVien ds[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (soSanhChuoi(ds[i].goiTap, "VIP") == 0) {
            dem++;
        }
    }
    return dem;
}
void inThongKe(HoiVien ds[], int n) {
    if (n <= 0) {
        printf("Danh sach rong, chua co du lieu de thong ke!\n");
        return;
    }
    printf("========== THONG KE ==========\n");
    printf("Tong so hoi vien      : %d\n", n);
    printf("Tong doanh thu        : %.0f VND\n", tinhTongDoanhThu(ds, n));
    printf("Can nang trung binh   : %.1f kg\n", tinhCanNangTrungBinh(ds, n));
    printf("So hoi vien goi VIP   : %d\n", demGoiVip(ds, n));
    printf("==============================\n");
}
