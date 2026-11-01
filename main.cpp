#include "gym.h"
#include "stats_valid.h"

int main()
{
    HoiVien danhSach[MAX_HOI_VIEN];
    int n = 0;
    int luaChon;
    char tuKhoa[50];

    hieuUngChuyenCanh();

    do {
        printf("\n================ QUAN LY PHONG GYM ================\n");
        printf("1. Them hoi vien moi\n");
        printf("2. Hien thi danh sach hoi vien\n");
        printf("3. Sua thong tin hoi vien theo ma\n");
        printf("4. Xoa hoi vien theo ma\n");
        printf("5. Tim kiem hoi vien\n");
        printf("6. Sap xep theo gia tien (tang dan)\n");
        printf("7. Sap xep theo gia tien (giam dan)\n");
        printf("8. Thong ke\n");
        printf("9. Tinh BMI hoi vien\n");
        printf("0. Thoat\n");
        printf("===================================================\n");

        luaChon = nhapSoNguyenKhongAm("Chon chuc nang (0-9): ");

        switch (luaChon) {
            case 1:
                themHoiVien(danhSach, &n);
                break;
            case 2:
                hienThiDanhSach(danhSach, n);
                break;
            case 3:
                suaHoiVien(danhSach, n);
                break;
            case 4:
                xoaHoiVien(danhSach, &n);
                break;
            case 5:
                if (n == 0) {
                    printf("\n[Thong bao] Danh sach hoi vien dang rong!\n");
                } else {
                    docChuoi("Nhap tu khoa tim kiem (ma hoac ten): ", tuKhoa, sizeof(tuKhoa));
                    timKiemHoiVien(danhSach, n, tuKhoa);
                }
                break;
            case 6:
                sapXepTheoGiaTien(danhSach, n, 1);
                break;
            case 7:
                sapXepTheoGiaTien(danhSach, n, 0);
                break;
            case 8:
                inThongKe(danhSach, n);
                break;
            case 9:
                inBMIHoiVien(danhSach, n);
                break;
            case 0:
                printf("\nDa thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\n[Loi] Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}