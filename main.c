#include <stdio.h>

int main() {
    int tuoi;
    int ma_phim;
    int ma_ghe;
    int ma_doi_tuong;
    
    float gia_co_ban = 80000.0;
    float phu_thu_ghe = 0.0;
    float giam_gia = 0.0;
    float gia_sau_giam = 0.0;
    float tong_tien = 0.0;
    
    printf("--- HE THONG BAN VE PHIM CGV ---\n");
    printf("Nhap tuoi khang gia: ");
    if (scanf("%d", &tuoi) != 1) return 0;
    
    printf("Nhap ma loai phim (1-P, 2-T18): ");
    if (scanf("%d", &ma_phim) != 1) return 0;
    
    printf("Nhap ma loai ghe (1-Thuong, 2-VIP, 3-Couple): ");
    if (scanf("%d", &ma_ghe) != 1) return 0;
    
    printf("Nhap ma doi tuong (1-Thuong, 2-HS/SV): ");
    if (scanf("%d", &ma_doi_tuong) != 1) return 0;
    
    // Yeu cau 1: Kiem chuan du lieu dau vao
    if (tuoi <= 0 || (ma_phim != 1 && ma_phim != 2) || (ma_ghe < 1 || ma_ghe > 3) || (ma_doi_tuong != 1 && ma_doi_tuong != 2)) {
        printf("LOI: Du lieu nhap vao khong hop le!\n");
        return 0;
    }
    
    // Yeu cau 2: Kiem tra quy dinh gioi han do tuoi phim T18
    if (ma_phim == 2 && tuoi < 18) {
        printf("TU CHOI BAN VE: Khang gia chua du 18 tuoi de xem phim T18!\n");
        return 0;
    }
    
    // Yeu cau 3: Tinh toan phu thu ghe bang switch-case
    switch (ma_ghe) {
        case 1:
            phu_thu_ghe = 0.0;
            break;
        case 2:
            phu_thu_ghe = 15000.0;
            break;
        case 3:
            phu_thu_ghe = 30000.0;
            break;
        default:
            phu_thu_ghe = 0.0;
            break;
    }
    
    // Tinh toan chiet khau va tong tien
    giam_gia = (ma_doi_tuong == 2) ? (gia_co_ban * 0.20) : 0.0;
    gia_sau_giam = gia_co_ban - giam_gia;
    tong_tien = gia_sau_giam + phu_thu_ghe;
    
    // Yeu cau 4: Hien thi ket qua hoa don chi tiet
    printf("--- HOA DON THANH TOAN ---\n");
    if (ma_doi_tuong == 1) {
        printf("Doi tuong: Khang gia thong thuong\n");
    } else {
        printf("Doi tuong: Hoc sinh / Sinh vien\n");
    }
    
    if (ma_ghe == 1) {
        printf("Loai ghe: Thuong\n");
    } else if (ma_ghe == 2) {
        printf("Loai ghe: VIP\n");
    } else {
        printf("Loai ghe: Couple\n");
    }
    
    printf("Gia ve goc: %.0f VND\n", gia_co_ban);
    printf("Giam gia uu dai: %.0f VND\n", giam_gia);
    printf("Phu thu ghe: %.0f VND\n", phu_thu_ghe);
    printf("Tong tien thanh toan: %.0f VND\n", tong_tien);
    
    return 0;
}