#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

void inputPassword(char *password) {
    int i = 0;
    char ch;
    while (1) {
        ch = getch(); //membuat karakter huruf yang ditampilkan menjadi tidak terlihat 
        if(ch == '\n' || ch == '\r') { //jika menekan enter, maka looping akan berhenti
            printf("\n"); //memindahkan kebaris baru jika input sudah selesai
            break;
        } else if(ch == '\b' && i > 0) { //untuk membuat backspace berfungsi
            printf("\b \b"); //menghapus karakter terakhir dari console
            i--;
        } else if (ch != '\b') {
            password[i++] = ch;
            printf("*"); //menampilkan '*' untuk setiap karakter yang diinput
        }     
    }
    password[i] = '\0'; //mengakhiri string dengan null character
}
int main() {
    int harga, noPerjalanan, totalHarga, jumlahTiket, kelasPerjalanan, angka1, angka2, jwb, diskon, subtotal;
    int percobaan = 0;
    bool loginBerhasil = false;
    char namaPelanggan[30], perjalanan[30], username[50], password[50], voucher[30], konfirmasi;
    char usenameBenar[] = "annisarasha24";
    char passwordBenar[] = "1a2b3c4d";
    char kodeVoucher[] = "LiburanHappy";

    srand(time(NULL)); //untuk menginisialisasi random seed

    while (percobaan < 3) {
        printf("Username: ");
        fgets(username, 50, stdin);
        username[strcspn(username, "\n")] = 0; //menghapus new line

        printf("Password: ");
        inputPassword(password);

        if(percobaan < 2) {
            angka1 = rand() % 10;
            angka2 = rand() % 10;
            printf("Jumlah dari %d + %d adalah: ", angka1, angka2);
            scanf("%d", &jwb);
            getchar(); //membersihkan buffer setelah scanf

            if (jwb != angka1 + angka2) {
                printf("Captcha salah, silakan coba lagi\n");
                continue;
            } 
        }

        if(strcmp(username, usenameBenar) == 0 && strcmp(password, passwordBenar) == 0) {
            printf("\tLOGIN BERHASIL\n\n");
            loginBerhasil = true;
            break;
        } else if(strcmp(username, usenameBenar) == 0) {
            printf("Password yang anda masukkan salah, silakan coba lagi.\n");
            percobaan++;
            if (percobaan == 3) {
                printf("Anda telah mencoba 3x. Coba lagi nanti.\n");
            }
        } else if(strcmp(password, passwordBenar) == 0) {
            printf("Username yang anda masukkan salah, silakan coba lagi.\n");
            percobaan++;
            if (percobaan == 3) {
                printf("Anda telah mencoba 3x. Coba lagi nanti.\n");
            }
        } else {
            printf("Username dan Password yang anda masukkan salah, silakan coba lagi.\n");
            percobaan++;
            if (percobaan == 3) {
                printf("Anda telah mencoba 3x. Coba lagi nanti.\n");
            }
        }
    }

    if (!loginBerhasil) {
        return 0;
    }

    printf("PEMESANAN TIKET KERETA API ONLINE\n");

    
    printf("\n    Menu Perjalanan    \n");
    printf("=======================\n");
    printf("1. Bandung - Yogyakarta\n");
    printf("2. Bandung - Malang\n");
    printf("3. Bandung - Jakarta\n");
    printf("4. Bandung - Surabaya\n");
    printf("5. Bandung - Semarang\n");
    printf("6. Bandung - Brebes\n");
    printf("7. Bandung - Tegal\n");
    printf("\nMasukkan kode voucher 'LiburanHappy' untuk mendapatkan potongan harga\n");

    do {
        printf("\nPilih nomor perjalanan : ");
        scanf("%d", &noPerjalanan);

       if(noPerjalanan == 1) {
            strcpy(perjalanan, "Bandung - Yogyakarta");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp220000\n");
            printf("2. Eksekutif        : Rp400000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
            if (kelasPerjalanan == 1) {
                harga = 220000;
            } else if (kelasPerjalanan == 2) {
                harga = 400000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            }      
        } else if (noPerjalanan == 2) {
            strcpy(perjalanan, "Bandung - Malang");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp260000\n");
            printf("2. Eksekutif        : Rp480000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
            if (kelasPerjalanan == 1) {
                harga = 260000;
            } else if (kelasPerjalanan == 2) {
                harga = 480000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            } 
        } else if (noPerjalanan == 3) {
            strcpy(perjalanan, "Bandung - Jakarta");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp120000\n");
            printf("2. Eksekutif        : Rp225000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
            if (kelasPerjalanan == 1) {
                harga = 120000;
            } else if (kelasPerjalanan == 2) {
                harga = 225000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            } 
        } else if (noPerjalanan == 4) {
            strcpy(perjalanan, "Bandung - Surabaya");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp280000\n");
            printf("2. Eksekutif        : Rp520000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
            if (kelasPerjalanan == 1) {
                harga = 280000;
            } else if (kelasPerjalanan == 2) {
                harga = 520000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            } 
        } else if (noPerjalanan == 5) {
            strcpy(perjalanan, "Bandung - Semarang");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp220000\n");
            printf("2. Eksekutif        : Rp450000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
            if (kelasPerjalanan == 1) {
                harga = 220000;
            } else if (kelasPerjalanan == 2) {
                harga = 450000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            } 
        }else if (noPerjalanan == 6) {
            strcpy(perjalanan, "Bandung - Tegal");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp210000\n");
            printf("2. Eksekutif        : Rp430000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
            if (kelasPerjalanan == 1) {
                harga = 210000;
            } else if (kelasPerjalanan == 2) {
                harga = 430000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            } 
        }else if (noPerjalanan == 7) {
            strcpy(perjalanan, "Bandung - Brebes");
            printf("\n       Kelas Perjalanan       \n");
            printf("==============================\n");
            printf("1. Ekonomi Premium  : Rp225000\n");
            printf("2. Eksekutif        : Rp440000\n");
            printf("\nPilih kelas perjalanan (1/2): ");
            scanf("%d", &kelasPerjalanan);
                if (kelasPerjalanan == 1) {
            harga = 225000;
            } else if (kelasPerjalanan == 2) {
                harga = 440000;
            } else {
                printf("Nomor yang anda masukkan tidak valid");
            } 
        } else {
            printf("Nomor yang anda masukkan tidak valid");
        }
        printf("\nNama Pemesan: ");
        scanf("%s", namaPelanggan);
        printf("Jumlah tiket yang dipesan: ");
        scanf("%d", &jumlahTiket);

        getchar();
        printf("Kode Voucher: ");
        fgets(voucher, 30, stdin);
        voucher[strcspn(voucher, "\n")] = 0;

        if(strcmp(voucher, kodeVoucher) == 0) {
            diskon = harga * 0.2 * jumlahTiket;
            totalHarga = harga * 0.8 * jumlahTiket;
        } else {
            diskon = 0;
            totalHarga = harga * jumlahTiket;
        }
        subtotal = harga * jumlahTiket;
 
        printf("\n         Rincian Pemesanan          \n");
        printf("=====================================\n");
        printf("Nama Pelanggan        : %s\n", namaPelanggan);
        printf("Destinasi Perjalanan  : %s\n", perjalanan);
        printf("Jumlah Tiket          : %d\n", jumlahTiket);
        printf("Harga per Tiket       : Rp%d\n", harga);
        printf("Subtotal              : Rp%d\n", subtotal);
        printf("-------------------------------------\n");
        printf("Total Diskon          : Rp%d\n", diskon);
        printf("Total                 : Rp%d\n", totalHarga);
        printf("=====================================\n");

        printf("\nApakah ada tambahan? (Y/N) ");
        scanf(" %c", &konfirmasi);

        while (getchar() != '\n');    
    } while (konfirmasi != 'N' && konfirmasi != 'n');

    return 0;
}