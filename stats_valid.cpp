#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "gym.h"
#include "stats_valid.h"

void xoaBoNhoDem(void)
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
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int timViTriTheoMa(HoiVien ds[], int n, const char ma[])
{
    for (int i = 0; i < n; i++) {
        if (soSanhChuoi(ds[i].maHoiVien, ma) == 0) {
            return i;
        }
    }
    return -1;
}

int kiemTraMaTrung(HoiVien ds[], int n, const char ma[])
{
    return timViTriTheoMa(ds, n, ma) != -1;
}

static void docDong(char buf[], int size)
{
    if (fgets(buf, size, stdin) == NULL) {
        exit(0);
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {
        xoaBoNhoDem();
    }
}

void docChuoi(const char thongBao[], char out[], int size)
{
    char buf[256];
    while (1) {
        printf("%s", thongBao);
        docDong(buf, sizeof(buf));
        size_t len = strlen(buf);
        if (len == 0) {
            printf("[Loi] Khong duoc de trong! Vui long nhap lai.\n");
            continue;
        }
        if (len >= (size_t)size) {
            printf("[Loi] Toi da %d ky tu! Vui long nhap lai.\n", size - 1);
            continue;
        }
        strcpy(out, buf);
        return;
    }
}

void nhapMaHoiVien(const char thongBao[], char out[15])
{
    while (1) {
        docChuoi(thongBao, out, 15);
        if (strchr(out, ' ') != NULL) {
            printf("[Loi] Ma hoi vien khong duoc chua dau cach! Vui long nhap lai.\n");
            continue;
        }
        return;
    }
}

void nhapGoiTap(const char thongBao[], char out[20])
{
    while (1) {
        docChuoi(thongBao, out, 20);
        if (soSanhChuoi(out, "Thuong") == 0 || soSanhChuoi(out, "VIP") == 0) {
            return;
        }
        printf("[Loi] Goi tap chi chap nhan 'Thuong' hoac 'VIP'! Vui long nhap lai.\n");
    }
}

static int docSoNguyen(const char thongBao[], int giaTriNhoNhat)
{
    char buf[64];
    while (1) {
        printf("%s", thongBao);
        docDong(buf, sizeof(buf));
        char *end;
        long v = strtol(buf, &end, 10);
        if (end != buf) {
            while (isspace((unsigned char)*end)) {
                end++;
            }
            if (*end == '\0' && v >= giaTriNhoNhat && v <= 1000000000L) {
                return (int)v;
            }
        }
        printf("Gia tri khong hop le! Vui long nhap lai.\n");
    }
}

int nhapSoNguyenDuong(const char thongBao[])
{
    return docSoNguyen(thongBao, 1);
}

int nhapSoNguyenKhongAm(const char thongBao[])
{
    return docSoNguyen(thongBao, 0);
}

int nhapSoThang(const char thongBao[])
{
    while (1) {
        int v = nhapSoNguyenDuong(thongBao);
        if (v >= 1 && v <= 12) {
            return v;
        }
        printf("[Loi] So thang dang ky phai tu 1 den 12!\n");
    }
}

float nhapSoThucDuong(const char thongBao[])
{
    char buf[64];
    while (1) {
        printf("%s", thongBao);
        docDong(buf, sizeof(buf));
        char *end;
        double v = strtod(buf, &end);
        if (end != buf) {
            while (isspace((unsigned char)*end)) {
                end++;
            }
            if (*end == '\0' && v > 0 && v <= 1e12) {
                return (float)v;
            }
        }
        printf("Gia tri khong hop le! Vui long nhap so thuc duong.\n");
    }
}

float nhapChieuCao(const char thongBao[])
{
    while (1) {
        float v = nhapSoThucDuong(thongBao);
        if (v >= 0.5f && v <= 2.5f) {
            return v;
        }
        printf("[Loi] Chieu cao phai nam trong khoang 0.5 den 2.5 met!\n");
    }
}

float tinhBMI(HoiVien hv)
{
    if (hv.chieuCao <= 0 || hv.canNang <= 0) {
        return 0;
    }
    return hv.canNang / (hv.chieuCao * hv.chieuCao);
}

void inPhanLoaiBMI(float bmi)
{
    if (bmi < 18.5f) {
        printf("Gay");
    } else if (bmi < 25) {
        printf("Binh thuong");
    } else if (bmi < 30) {
        printf("Thua can");
    } else {
        printf("Beo phi");
    }
}

void inBMIHoiVien(HoiVien ds[], int n)
{
    if (n <= 0) {
        printf("\n[Thong bao] Danh sach hoi vien dang rong!\n");
        return;
    }
    char ma[15];
    printf("\n=== TINH BMI HOI VIEN ===\n");
    nhapMaHoiVien("Nhap ma hoi vien: ", ma);
    int viTri = timViTriTheoMa(ds, n, ma);
    if (viTri == -1) {
        printf("[Loi] Khong tim thay hoi vien co ma: %s\n", ma);
        return;
    }
    float bmi = tinhBMI(ds[viTri]);
    printf("Hoi vien: %s - %s\n", ds[viTri].maHoiVien, ds[viTri].hoTen);
    printf("BMI: %.1f - Phan loai: ", bmi);
    inPhanLoaiBMI(bmi);
    printf("\n");
}

float tinhTongDoanhThu(HoiVien ds[], int n)
{
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].giaTien;
    }
    return tong;
}

float tinhCanNangTrungBinh(HoiVien ds[], int n)
{
    float tong = 0;
    if (n <= 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        tong += ds[i].canNang;
    }
    return tong / n;
}

int demGoiVip(HoiVien ds[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (soSanhChuoi(ds[i].goiTap, "VIP") == 0) {
            dem++;
        }
    }
    return dem;
}

void inThongKe(HoiVien ds[], int n)
{
    if (n <= 0) {
        printf("\nDanh sach rong, chua co du lieu de thong ke!\n");
        return;
    }
    printf("\n========== THONG KE ==========\n");
    printf("Tong so hoi vien      : %d\n", n);
    printf("Tong doanh thu        : %.0f VND\n", tinhTongDoanhThu(ds, n));
    printf("Can nang trung binh   : %.1f kg\n", tinhCanNangTrungBinh(ds, n));
    printf("So hoi vien goi VIP   : %d\n", demGoiVip(ds, n));
    printf("==============================\n");
}