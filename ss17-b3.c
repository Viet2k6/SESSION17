#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void arr(char *a) {
    printf("Nhap vao chuoi: ");
    fgets(a, 100, stdin);
    a[strcspn(a, "\n")] = '\0'; 
}

void print(const char *a) {
    int len = strlen(a);
    char temp[100];
    strcpy(temp, a);
    for (int i = 0; i < len / 2; i++) {
        char tmp = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = tmp;
    }
    printf("Chuoi dao nguoc: %s\n", temp);
}

void length(const char *a) {
    int count = 0;
    int inWord = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (isspace(a[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    printf("So luong tu trong chuoi la: %d\n", count);
}

void sum(const char *a, char *b) {
    printf("Nhap vao chuoi khac: ");
    fgets(b, 100, stdin);
    b[strcspn(b, "\n")] = '\0';

    if (strlen(a) > strlen(b)) {
        printf("Chuoi ban dau dai hon chuoi moi.\n");
    } else if (strlen(a) < strlen(b)) {
        printf("Chuoi ban dau ngan hon chuoi moi.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}

void max(char *a) {
    char temp[100];
    strcpy(temp, a);
    for (int i = 0; temp[i] != '\0'; i++) {
        temp[i] = toupper(temp[i]);
    }
    printf("Chuoi in hoa: %s\n", temp);
}

void newstring(const char *a, char *b) {
    printf("Nhap vao chuoi khac: ");
    fgets(b, 100, stdin);
    b[strcspn(b, "\n")] = '\0';

    char *result = malloc(strlen(a) + strlen(b) + 1);
    if (result == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    strcpy(result, a);
    strcat(result, b);
    printf("Chuoi sau khi noi: %s\n", result);
    free(result);
}

int main() {
    int choice;
    char a[100] = {0}; 
    char b[100] = {0}; 

    do {
        printf("\n\n1: Nhap vao chuoi");
        printf("\n2: In ra chuoi dao nguoc");
        printf("\n3: Dem so luong tu trong chuoi");
        printf("\n4: Tao chuoi moi so sanh voi chuoi ban dau");
        printf("\n5: In hoa cac chu cai trong chuoi");
        printf("\n6: Nhap vao chuoi khac noi voi chuoi ban dau");
        printf("\n7: Thoat");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1:
            arr(a);
            break;
        case 2:
            if (strlen(a) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                print(a);
            }
            break;
        case 3:
            if (strlen(a) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                length(a);
            }
            break;
        case 4:
            if (strlen(a) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                sum(a, b);
            }
            break;
        case 5:
            if (strlen(a) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                max(a);
            }
            break;
        case 6:
            if (strlen(a) == 0) {
                printf("Chuoi chua duoc nhap.\n");
            } else {
                newstring(a, b);
            }
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}
