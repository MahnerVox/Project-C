#ifndef GYM_H
#define GYM_H

#include <stdio.h>

typedef struct {
    char maHoiVien[15];  
    char hoTen[50];      
    char goiTap[20];    
    int soThangDangKy;    
    float canNang;      
    float giaTien;      
} HoiVien;

void xoaBoNhoDem();
int soSanhChuoi(char s1[], char s2[]);
int kiemTraMaTrung(HoiVien ds[], int n, char ma[]);
int nhapSoNguyenDuong(char thongBao[]);
float nhapSoThucDuong(char thongBao[]);

void themHoiVien(HoiVien ds[], int *n);
void hienThiDanhSach(HoiVien ds[], int n);

#endif