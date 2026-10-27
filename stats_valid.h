#ifndef STATS_VALID_H
#define STATS_VALID_H

#include "gym.h"

void xoaBoNhoDem();
int soSanhChuoi(const char s1[], const char s2[]);
int kiemTraMaTrung(HoiVien ds[], int n, const char ma[]);
int nhapSoNguyenDuong(const char thongBao[]);
float nhapSoThucDuong(const char thongBao[]);

float tinhBMI(HoiVien hv);
void inPhanLoaiBMI(float bmi);

float tinhTongDoanhThu(HoiVien ds[], int n);
float tinhCanNangTrungBinh(HoiVien ds[], int n);
int demGoiVip(HoiVien ds[], int n);
void inThongKe(HoiVien ds[], int n);

#endif
