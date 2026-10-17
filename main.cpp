#include "gym.h"

int main() {
    HoiVien danhSach[100]; 
    int n = 0;          
    int luaChon;

    do {
        printf("\n================ QUAN LY PHONG GYM ================\n");
        printf("1. Them hoi vien moi\n");
        printf("2. Hien thi danh sach hoi vien\n");
        printf("0. Thoat\n");
        printf("===================================================\n");

        luaChon = nhapSoNguyenDuong("Chon chuc nang (0-2): ");

        switch (luaChon) {
            case 1:
                themHoiVien(danhSach, &n);
                break;
            case 2:
                hienThiDanhSach(danhSach, n);
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