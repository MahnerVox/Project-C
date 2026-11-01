#include "gym.h"
#include "stats_valid.h"

void themHoiVien(HoiVien ds[], int *n)
{
    if (*n >= MAX_HOI_VIEN) {
        printf("\n[Loi] Danh sach da day (toi da %d hoi vien)!\n", MAX_HOI_VIEN);
        return;
    }

    HoiVien hv;
    printf("\n=== THEM HOI VIEN MOI ===\n");

    while (1) {
        nhapMaHoiVien("Nhap ma hoi vien (khong dau cach): ", hv.maHoiVien);
        if (kiemTraMaTrung(ds, *n, hv.maHoiVien)) {
            printf("[Loi] Ma hoi vien da ton tai! Vui long nhap lai.\n");
        } else {
            break;
        }
    }

    docChuoi("Nhap ho va ten: ", hv.hoTen, sizeof(hv.hoTen));
    nhapGoiTap("Nhap goi tap (Thuong / VIP): ", hv.goiTap);
    hv.soThangDangKy = nhapSoThang("Nhap so thang dang ky (1-12): ");
    hv.canNang = nhapSoThucDuong("Nhap can nang (kg): ");
    hv.chieuCao = nhapChieuCao("Nhap chieu cao (m): ");
    hv.giaTien = nhapSoThucDuong("Nhap gia tien (VND): ");

    ds[*n] = hv;
    (*n)++;

    printf("=> Them hoi vien thanh cong!\n");
}

void suaHoiVien(HoiVien ds[], int n)
{
    if (n == 0) {
        printf("\n[Thong bao] Danh sach hoi vien dang rong!\n");
        return;
    }

    char maCapNhat[15];
    printf("\n=== SUA THONG TIN HOI VIEN ===\n");
    nhapMaHoiVien("Nhap ma hoi vien can sua: ", maCapNhat);

    int viTri = timViTriTheoMa(ds, n, maCapNhat);
    if (viTri == -1) {
        printf("[Loi] Khong tim thay hoi vien co ma: %s\n", maCapNhat);
        return;
    }

    printf("\n--> Da tim thay hoi vien: %s - %s\n", ds[viTri].maHoiVien, ds[viTri].hoTen);
    docChuoi("Nhap ho va ten moi: ", ds[viTri].hoTen, sizeof(ds[viTri].hoTen));
    nhapGoiTap("Nhap goi tap moi (Thuong / VIP): ", ds[viTri].goiTap);
    ds[viTri].soThangDangKy = nhapSoThang("Nhap so thang dang ky moi (1-12): ");
    ds[viTri].canNang = nhapSoThucDuong("Nhap can nang moi (kg): ");
    ds[viTri].chieuCao = nhapChieuCao("Nhap chieu cao moi (m): ");
    ds[viTri].giaTien = nhapSoThucDuong("Nhap gia tien moi (VND): ");

    printf("=> Cap nhat thong tin hoi vien thanh cong!\n");
}

void xoaHoiVien(HoiVien ds[], int *n)
{
    if (*n == 0) {
        printf("\n[Thong bao] Danh sach hoi vien dang rong!\n");
        return;
    }

    char maXoa[15];
    printf("\n=== XOA HOI VIEN ===\n");
    nhapMaHoiVien("Nhap ma hoi vien can xoa: ", maXoa);

    int viTri = timViTriTheoMa(ds, *n, maXoa);
    if (viTri == -1) {
        printf("[Loi] Khong tim thay hoi vien co ma: %s\n", maXoa);
        return;
    }

    for (int i = viTri; i < *n - 1; i++) {
        ds[i] = ds[i + 1];
    }
    (*n)--;

    printf("=> Da xoa thanh cong hoi vien co ma: %s\n", maXoa);
}