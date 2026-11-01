#ifndef STATS_VALID_H
#define STATS_VALID_H

#include "gym.h"

void xoaBoNhoDem(void);
int soSanhChuoi(const char s1[], const char s2[]);
int kiemTraMaTrung(HoiVien ds[], int n, const char ma[]);
int timViTriTheoMa(HoiVien ds[], int n, const char ma[]);

void docChuoi(const char thongBao[], char out[], int size);
void nhapMaHoiVien(const char thongBao[], char out[15]);
void nhapGoiTap(const char thongBao[], char out[20]);
int nhapSoThang(const char thongBao[]);
int nhapSoNguyenDuong(const char thongBao[]);
int nhapSoNguyenKhongAm(const char thongBao[]);
float nhapSoThucDuong(const char thongBao[]);
float nhapChieuCao(const char thongBao[]);

float tinhBMI(HoiVien hv);
void inPhanLoaiBMI(float bmi);
void inBMIHoiVien(HoiVien ds[], int n);

float tinhTongDoanhThu(HoiVien ds[], int n);
float tinhCanNangTrungBinh(HoiVien ds[], int n);
int demGoiVip(HoiVien ds[], int n);
void inThongKe(HoiVien ds[], int n);

#endif