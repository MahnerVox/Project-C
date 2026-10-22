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

    void suaHoiVien(HoiVien ds[], int n){
    if (n == 0) {
        printf("\n[Thong bao] Danh sach hoi vien dang rong!\n");
        return;
    }

    char maCapNhat[15];
    printf("\n=== SUA THONG TIN HOI VIEN ===\n");
    printf("Nhap ma hoi vien can sua: ");
    scanf("%s", maCapNhat);
    xoaBoNhoDem();

    int viTri = -1;
    for (int i = 0; i < n; i++) {
        if (soSanhChuoi(ds[i].maHoiVien, maCapNhat) == 1) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        printf("[Loi] Khong tim thay hoi vien co ma: %s\n", maCapNhat);
        return;
    }

    printf("\n--> Da tim thay hoi vien: %s - %s\n", ds[viTri].maHoiVien, ds[viTri].hoTen);
    printf("Nhap ho va ten moi: ");
    scanf(" %[^\n]s", ds[viTri].hoTen);
    xoaBoNhoDem();

    printf("Nhap goi tap moi (Thuong/VIP): ");
    scanf("%s", ds[viTri].goiTap);
    xoaBoNhoDem();

    ds[viTri].soThangDangKy = nhapSoNguyenDuong("Nhap so thang dang ky moi: ");
    ds[viTri].canNang = nhapSoThucDuong("Nhap can nang moi (kg): ");
    ds[viTri].giaTien = nhapSoThucDuong("Nhap gia tien moi (VND): ");

    printf("=> Cap nhat thong tin hoi vien thanh cong!\n");
}
