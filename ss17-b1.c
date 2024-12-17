#include <stdio.h>
#include <math.h>
int displayMenu(){
	int choice;
	printf("\n MENU \n");
        printf("1.Nhap vao so phan tu va tung phan tu\n");
	printf("2.Hien thi cac phan tu trong mang\n");
	printf("3.Tinh do dai mang\n");
	printf("4.Tinh tong cac phan tu trong mang\n");
	printf("5.Hien thi phan tu lon nhat\n");
	printf("6.Thoat\n");
	printf("Lua chon cua ban:");
	scanf("%d", &choice);
	return choice;
}
void nhapMang(int *arr, int *size) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", size);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void hienThiMang(int *arr, int size) {
	printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int tinhDoDaiMang(int size) {
    return size;
}
int tinhTongMang(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
int timMax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int choice;
    int size = 0;
	int arr[100];
    do {
    	choice = displayMenu();
        switch (choice) {
			case 1:
				if(size < 0 || size > 100){
                	printf("So phan tu mang khong hop le");
                break;
            	} else {
            		nhapMang(arr, &size);
				}
				break;
            case 2:
            	if(size < 0 || size > 100){
                	printf("Moi nhap mang");
                break;
            	} else {
	            	hienThiMang(arr, size);
                }
                break;
            case 3:
            	if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                	break;
            	} else {
					printf("Do dai mang la: %d\n", tinhDoDaiMang(size));
				}
				break;
			case 4:
				if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                	break;
            	} else {
            		printf("Tong cac phan tu trong mang: %d\n", tinhTongMang(arr, size));
            	}
            	break;
			case 5:
				if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                	break;
            	} else {
            	printf("Phan tu lon nhat trong mang: %d\n", timMax(arr, size));
				}
				break;
			case 6:
                printf("Ket thuc chuong trinh.\n");
                break;
            default: {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } while (choice != 6);
    return 0;
}
