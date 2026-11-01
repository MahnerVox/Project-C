#ifndef GYM_H
#define GYM_H

#include <stdio.h>

#define MAX_HOI_VIEN 100

typedef struct {
    char maHoiVien[15];
    char hoTen[50];
    char goiTap[20];
    int soThangDangKy;
    float canNang;
    float chieuCao;
    float giaTien;
} HoiVien;

void themHoiVien(HoiVien ds[], int *n);
void suaHoiVien(HoiVien ds[], int n);
void xoaHoiVien(HoiVien ds[], int *n);

void hienThiDanhSach(HoiVien ds[], int n);
void timKiemHoiVien(HoiVien ds[], int n, const char tuKhoa[]);
void sapXepTheoGiaTien(HoiVien ds[], int n, int tangDan);
void hieuUngChuyenCanh(void);

#endif