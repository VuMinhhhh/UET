#include <iostream>

using namespace std;

struct date {
    string ngaysinh;
};

struct SinhVien {
    int diem[3];
    date ngaysinh;
    friend istream &operator>> (istream &in, SinhVien &a) {
        in >> a.diem[0] >> a.diem[1] >> a.diem[2] >> a.ngaysinh.ngaysinh;
        return in;
    }
    friend ostream &operator<<(ostream &out, SinhVien a) {
        out << a.diem[0] << " " << a.diem[1] << " " << a.diem[2] << endl;
        out << a.ngaysinh.ngaysinh;
        return out;
    }
};

int main() {
    SinhVien a;
    cin >> a;
    SinhVien b = a;
    cout << a << endl;
    cout << endl;
    cout << b << endl;
    a.diem[0] += 1;
    a.diem[1] += 2;
    a.diem[2] += 3;
    a.ngaysinh.ngaysinh += "s";
    cout << a << endl << b;


}
