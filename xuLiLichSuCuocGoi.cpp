#include <iostream>
#include <string>
using namespace std;
struct LienHe {
    string ten;
    string sdt;
};
struct Node {
    LienHe duLieu;
    Node* prev;
    Node* next;
};
struct DanhBa {
    Node* head;
    Node* tail;
};
struct NodeLichSu {
    string sdt;
    NodeLichSu* next;
};
struct LichSuCuocGoi {
    NodeLichSu* head;
};
void KhoiTaoLichSu(LichSuCuocGoi &ls) {
    ls.head = NULL;
}
void GhiNhanCuocGoi(LichSuCuocGoi &ls, string sdt) {
    NodeLichSu* nodeMoi = new NodeLichSu;
    nodeMoi->sdt = sdt;
    nodeMoi->next = ls.head;
    ls.head = nodeMoi;
    
    cout << "Dang goi toi so: " << sdt << "...\n";
    cout << "[Lich su] Da ghi nhan cuoc goi thanh cong!\n";
}
void HienThiLichSu(LichSuCuocGoi ls) {
    if (ls.head == NULL) {
        cout << "[Lich su] Chua co cuoc goi nao duoc ghi nhan!\n";
        return;
    }
    cout << "\n--- LICH SU CUOC GOI GAN DEY (MOI NHAT O DAU) ---\n";
    NodeLichSu* p = ls.head;
    int stt = 1;
    while (p != NULL) {
        cout << stt++ << ". So dien thoai: " << p->sdt << "\n";
        p = p->next;
    }
}
void GiaiPhongLichSu(LichSuCuocGoi &ls) {
    NodeLichSu* p = ls.head;
    while (p != NULL) {
        NodeLichSu* temp = p;
        p = p->next;
        delete temp;
    }
    ls.head = NULL;
}
int main() {
    LichSuCuocGoi lichSu;
    KhoiTaoLichSu(lichSu);
    int luaChon;
    do {
        cout << "\n================ MENU CHUONG TRINH ================\n";
        cout << "1. Them lien he moi\n";
        cout << "2. Xoa lien he theo SDT\n";
        cout << "3. Hien thi danh ba (A-Z)\n";
        cout << "4. Hien thi danh ba (Z-A)\n";
        cout << "5. Sap xep danh ba theo ten\n";
        cout << "6. Tim kiem theo tien to ten\n";
        cout << "7. Thuc hien cuoc goi (Luu lich su)\n";
        cout << "8. Xem lich su cuoc goi gan day\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "=============================================================\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
        switch (luaChon) {
            case 1:
                cout << "-> Chuc nang ThemLienHe() \n";
                break;
            case 2:
                cout << "-> Chuc nang XoaLienHe() \n";
                break;
            case 3:
                cout << "-> Chuc nang HienThiXuoi() \n";
                break;
            case 4:
                cout << "-> Chuc nang HienThiNguoc() \n";
                break;
            case 5:
                cout << "-> Chuc nang SapXepDanhBa() \n";
                break;
            case 6:
                cout << "-> Chuc nang TimKiemTheoTen() \n";
                break;
            case 7: {
                string sdt;
                cout << "Nhap so dien thoai muon goi: ";
                getline(cin, sdt);
                GhiNhanCuocGoi(lichSu, sdt);
                break;
            }
            case 8:
                HienThiLichSu(lichSu);
                break;
            case 0:
                GiaiPhongLichSu(lichSu);
                cout << "Da thoat va giai phong bo nho lich su!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);
    return 0;
}