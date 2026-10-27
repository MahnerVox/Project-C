#ifndef STATS_VALID_H
#ifndef STATS_VALID_H

#include "gym.h"

void xoaBoNhoDem();
int soSanhChuoi(char s1[], char s2[]);
int kiemTraMaTrung(HoiVien ds[], int n, char ma[]);
int nhapSoNguyenDuong(char thongBao[]);
float nhapSoThucDuong(char thongBao[]);

float tinhBMI(HoiVien hv);
void inPhanLoaiBMI(float bmi);

float tinhTongDoanhThu(HoiVien ds[], int n);
float tinhCanNangTrungBinh(HoiVien ds[], int n);
int demGoiVip(HoiVien ds[], int n);
void inThongKe(HoiVien ds[], int n);

#endif