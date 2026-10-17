#include "gym.h"
void themHoiVien(HoiVien ds[], int *n) {
    if (*n >= 100) {
        printf("\n[Loi] Danh sach da day (toi da 100 hoi vien)!\n");
        return;
    }

    HoiVien hv;
    printf("\n=== THEM HOI VIEN MOI ===\n");

    do {
        printf("Nhap ma hoi vien (khong dau cach): ");
        scanf("%s", hv.maHoiVien);
        xoaBoNhoDem();

        if (kiemTraMaTrung(ds, *n, hv.maHoiVien)) {
            printf("[Loi] Ma hoi vien da ton tai! Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);
    printf("Nhap ho va ten: ");
    scanf(" %[^\n]s", hv.hoTen);
    xoaBoNhoDem();

    printf("Nhap goi tap (Thuong/VIP): ");
    scanf("%s", hv.goiTap);
    xoaBoNhoDem();

    hv.soThangDangKy = nhapSoNguyenDuong("Nhap so thang dang ky: ");
    hv.canNang = nhapSoThucDuong("Nhap can nang (kg): ");
    hv.giaTien = nhapSoThucDuong("Nhap gia tien (VND): ");
    ds[*n] = hv;
    (*n)++;

    printf("=> Them hoi vien thanh cong!\n");
}