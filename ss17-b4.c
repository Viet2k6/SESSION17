#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void nhapMang(int **arr, int *n);
void inMang(int *arr, int n);
void inSoChan(int *arr, int n);
bool laSoNguyenTo(int num);
void inSoNguyenTo(int *arr, int n);
void daoNguocMang(int *arr, int n);
void sapXepMang(int *arr, int n, int tangDan);
int timKiemPhanTu(int *arr, int n, int key);
void hienThiMenuSapXep();

int main() {
    int *arr = NULL;
    int n = 0;
    int choice, key, foundIndex;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra mang\n");
        printf("3. In ra cac phan tu la so chan\n");
        printf("4. In ra cac phan tu la so nguyen to\n");
        printf("5. Dao nguoc mang\n");
        printf("6. Sap xep mang\n");
        printf("7. Tim kiem phan tu trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(&arr, &n);
                break;
            case 2:
                if (n > 0) {
                    inMang(arr, n);
                } else {
                    printf("Mang rong. Vui long nhap mang truoc!\n");
                }
                break;
            case 3:
                if (n > 0) {
                    inSoChan(arr, n);
                } else {
                    printf("Mang rong. Vui long nhap mang truoc!\n");
                }
                break;
            case 4:
                if (n > 0) {
                    inSoNguyenTo(arr, n);
                } else {
                    printf("Mang rong. Vui long nhap mang truoc!\n");
                }
                break;
            case 5:
                if (n > 0) {
                    daoNguocMang(arr, n);
                    printf("Mang sau khi dao nguoc: ");
                    inMang(arr, n);
                } else {
                    printf("Mang rong. Vui long nhap mang truoc!\n");
                }
                break;
            case 6:
                if (n > 0) {
                    int subChoice;
                    hienThiMenuSapXep();
                    scanf("%d", &subChoice);
                    if (subChoice == 1 || subChoice == 2) {
                        sapXepMang(arr, n, subChoice == 1);
                        printf("Mang sau khi sap xep: ");
                        inMang(arr, n);
                    } else {
                        printf("Lua chon khong hop le!\n");
                    }
                } else {
                    printf("Mang rong. Vui long nhap mang truoc!\n");
                }
                break;
            case 7:
                if (n > 0) {
                    printf("Nhap phan tu can tim: ");
                    scanf("%d", &key);
                    foundIndex = timKiemPhanTu(arr, n, key);
                    if (foundIndex != -1) {
                        printf("Phan tu %d tim thay tai vi tri: %d\n", key, foundIndex);
                    } else {
                        printf("Khong tim thay phan tu %d trong mang.\n", key);
                    }
                } else {
                    printf("Mang rong. Vui long nhap mang truoc!\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
        }
    } while (choice != 8);

    free(arr);
    return 0;
}

void nhapMang(int **arr, int *n) {
    do {
        printf("Nhap so phan tu cua mang (n > 0): ");
        scanf("%d", n);
        if (*n <= 0) {
            printf("So phan tu phai lon hon 0. Vui long nhap lai!\n");
        }
    } while (*n <= 0);

    *arr = (int *)malloc(*n * sizeof(int));
    if (*arr == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }

    printf("Nhap tung phan tu:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &(*arr)[i]);
    }
}

void inMang(int *arr, int n) {
    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void daoNguocMang(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void hienThiMenuSapXep() {
    printf("\nSAP XEP MANG\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Lua chon cua ban: ");
}

void sapXepMang(int *arr, int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int timKiemPhanTu(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
