#include <iostream>
#include <iomanip>
#include <chrono>
#include "kontenlms.h"

using namespace std;
using namespace std::chrono;

// Fungsi untuk menampilkan header tabel (hanya NO dan KONTEN)
void displayHeader() {
    cout << "\n" << string(65, '=') << endl;
    cout << left << setw(5) << "NO" 
         << setw(60) << "KONTEN" << endl;
    cout << string(65, '=') << endl;
}

// Fungsi untuk menampilkan satu baris konten (hanya NO dan KONTEN)
void displayKonten(int no, const KontenLMS& konten) {
    cout << left << setw(5) << no 
         << setw(60) << konten.judulKonten << endl;
}

// Fungsi untuk menampilkan semua konten
void displayAllKonten(const vector<KontenLMS>& data) {
    displayHeader();
    for (size_t i = 0; i < data.size(); i++) {
        displayKonten(i + 1, data[i]);
    }
    cout << string(65, '=') << endl;
}

int main() {
    // Inisialisasi data konten LMS
    vector<KontenLMS> dataKonten = {
        {"MW01", "Materi Week 1 \"Storage Management\"", "Materi", 12},
        {"QW01", "Quiz 1 \"Storage Management\"", "Quiz", 4},
        {"TW01", "Tugas 1 \"Storage Management\"", "Tugas", 18},
        {"PW01", "PR 1 \"Storage Management\"", "PR", 15},
        {"VW01", "Video Pembelajaran \"Storage Management\"", "Video", 420},
        {"RW01", "Referensi Materi \"Storage Management\"", "Referensi", 55},
        {"KW01", "Tugas Kelompok Week 1", "Tugas", 90},
        
        {"MW02", "Materi Week 2 \"Indexing\"", "Materi", 14},
        {"QW02", "Quiz 2 \"Indexing\"", "Quiz", 5},
        {"TW02", "Tugas 2 \"Indexing\"", "Tugas", 22},
        {"PW02", "PR 2 \"Indexing\"", "PR", 17},
        {"VW02", "Video Pembelajaran \"Indexing\"", "Video", 510},
        {"RW02", "Referensi Materi \"Indexing\"", "Referensi", 63},
        
        {"MW03", "Materi Week 3 \"Query Processing\"", "Materi", 16},
        {"QW03", "Quiz 3 \"Query Processing\"", "Quiz", 6},
        {"TW03", "Tugas 3 \"Query Processing\"", "Tugas", 25},
        {"PW03", "PR 3 \"Query Processing\"", "PR", 19},
        {"VW03", "Video Pembelajaran \"Query Processing\"", "Video", 680},
        {"RW03", "Referensi Materi \"Query Processing\"", "Referensi", 72},
        {"KW03", "Tugas Kelompok Week 3", "Tugas", 110},
        
        {"MW04", "Materi Week 4 \"Concurrency Control\"", "Materi", 15},
        {"QW04", "Quiz 4 \"Concurrency Control\"", "Quiz", 6},
        {"TW04", "Tugas 4 \"Concurrency Control\"", "Tugas", 28},
        {"PW04", "PR 4 \"Concurrency Control\"", "PR", 21},
        {"VW04", "Video Pembelajaran \"Concurrency Control\"", "Video", 750},
        {"RW04", "Referensi Materi \"Concurrency Control\"", "Referensi", 80},
        
        {"MW05", "Materi Week 5 \"Backup and Recovery\"", "Materi", 18},
        {"QW05", "Quiz 5 \"Backup and Recovery\"", "Quiz", 7},
        {"TW05", "Tugas 5 \"Backup and Recovery\"", "Tugas", 30},
        {"PW05", "PR 5 \"Backup and Recovery\"", "PR", 23},
        {"VW05", "Video Pembelajaran \"Backup and Recovery\"", "Video", 920},
        {"RW05", "Referensi Materi \"Backup and Recovery\"", "Referensi", 95},
        {"KW05", "Tugas Kelompok Week 5", "Tugas", 135}
    };
    
    int pilihan;
    string keyword;
    
    do {
        cout << "\n========== SISTEM KONTEN LMS ==========\n";
        cout << "1. Tampilkan Semua Konten Pembelajaran\n";
        cout << "2. Cari Konten Pembelajaran (dengan Running Time)\n";
        cout << "0. Keluar\n";
        cout << "=======================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                displayAllKonten(dataKonten);
                break;
                
            case 2:
                cout << "Masukkan kata kunci pencarian: ";
                getline(cin, keyword);
                {
                    // ========== ITERATIVE SEARCH ==========
                    auto startIterative = high_resolution_clock::now();
                    int resultIterative = searchJudulIterative(dataKonten, keyword);
                    auto stopIterative = high_resolution_clock::now();
                    auto durationIterative = duration_cast<nanoseconds>(stopIterative - startIterative);
                    
                    // ========== RECURSIVE SEARCH ==========
                    auto startRecursive = high_resolution_clock::now();
                    int resultRecursive = searchJudulRecursive(dataKonten, keyword, 0);
                    auto stopRecursive = high_resolution_clock::now();
                    auto durationRecursive = duration_cast<nanoseconds>(stopRecursive - startRecursive);
                    
                    // ========== TAMPILKAN HASIL ==========
                    if (resultIterative != -1) {
                        cout << "\n Konten ditemukan!\n";
                        displayHeader();
                        displayKonten(resultIterative + 1, dataKonten[resultIterative]);
                        cout << string(65, '=') << endl;
                    } else {
                        cout << "\n Konten tidak ditemukan!\n";
                    }
                    
                    // ========== RUNNING TIME COMPARISON ==========
                    cout << "\n========== PERBANDINGAN RUNNING TIME ==========\n";
                    cout << "Metode Iteratif  : " << durationIterative.count() << " nanoseconds\n";
                    cout << "Metode Rekursif  : " << durationRecursive.count() << " nanoseconds\n";
                    cout << "===============================================\n";
                    
                    // Menentukan yang lebih cepat
                    if (durationIterative.count() < durationRecursive.count()) {
                        cout << " Metode Iteratif lebih cepat!\n";
                    } else if (durationRecursive.count() < durationIterative.count()) {
                        cout << " Metode Rekursif lebih cepat!\n";
                    } else {
                        cout << " Kedua metode memiliki waktu yang sama!\n";
                    }
                }
                break;
                
            case 0:
                cout << "\nTerima kasih telah menggunakan sistem!\n";
                break;
                
            default:
                cout << "\n Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 0);
    
    return 0;
}