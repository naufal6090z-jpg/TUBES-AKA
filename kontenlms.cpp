#include "kontenlms.h"
#include <algorithm>
#include <cctype>

// Fungsi helper untuk mengubah string menjadi lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Fungsi untuk mencari konten berdasarkan judul secara iterative
int searchJudulIterative(const vector<KontenLMS>& data, const string& targetJudul) {
    string target = toLower(targetJudul);
    
    for (size_t i = 0; i < data.size(); i++) {
        string judul = toLower(data[i].judulKonten);
        if (judul.find(target) != string::npos) {
            return i; // Return index jika ditemukan
        }
    }
    return -1; // Return -1 jika tidak ditemukan
}

// Fungsi untuk mencari konten berdasarkan judul secara recursive
int searchJudulRecursive(const vector<KontenLMS>& data, const string& targetJudul, int index) {
    // Base case: jika sudah mencapai akhir array
    if (index >= (int)data.size()) {
        return -1;
    }
    
    string target = toLower(targetJudul);
    string judul = toLower(data[index].judulKonten);
    
    // Jika ditemukan, return index
    if (judul.find(target) != string::npos) {
        return index;
    }
    
    // Recursive case: lanjut ke index berikutnya
    return searchJudulRecursive(data, targetJudul, index + 1);
}