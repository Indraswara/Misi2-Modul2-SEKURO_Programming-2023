#include<iostream> 
#include<fstream>

using namespace std; 

//fungsi untuk memanggil menu.txt dan ditampilan di dalam terminal 
void menu()
{
    string minuman[10] = {}; 
    char namamenu[50];
    ifstream menu; 
    menu.open("menu.txt");
    while(menu)
    {
        menu.getline(namamenu, sizeof(namamenu)); 
        cout << namamenu << endl; 
    }
    menu.close();
}

//fungsi untuk menulis ke dalam history penjualan.txt
void penjualan(string namaPembeli,int kategori, int menu, int menuQty, int hargaMenu)
{
    ofstream penjualanBarang;
    penjualanBarang.open("penjualan.txt", ios::app);
    penjualanBarang<<"\nNama Pembeli    : " << namaPembeli; 
    if(kategori == 1)
        switch(menu){
            case 1: 
                penjualanBarang<<"\nMenu            : " <<"Gado-gado";
                break;
            case 2:
                penjualanBarang<<"\nMenu            : " <<"Lontong sayur ";
                break;
            case 3:
                penjualanBarang<<"\nMenu            : " <<"Kupat tahu  ";
                break;
            case 4:
                penjualanBarang<<"\nMenu            : " <<"Sate kambing ";
                break;
            case 5:
                penjualanBarang<<"\nMenu            : " <<"Sate ayam";
                break;
            case 6:
                penjualanBarang<<"\nMenu            : " <<"Batagor";
                break;
            case 7:
                penjualanBarang<<"\nMenu            : " <<"Ayam geprek ";
                break;
            case 8:  
                penjualanBarang<<"\nMenu            : " <<"Mie ayam";
                break;
            case 9:
                penjualanBarang<<"\nMenu            : " <<"Bakso urat";
                break;
            case 10:
                penjualanBarang<<"\nMenu            : " <<"Soto ayam";
                break;
    }
    else if(kategori == 2){
        switch(menu)
        {
            case 1: 
                penjualanBarang<<"\nMenu            : " <<"Coca-cola";
                break;
            case 2:
                penjualanBarang<<"\nMenu            : " <<"Soda gembira ";
                break;
            case 3:
                penjualanBarang<<"\nMenu            : " <<"Teh manis ";
                break;
            case 4:
                penjualanBarang<<"\nMenu            : " <<"Milo";
                break;
            case 5:
                penjualanBarang<<"\nMenu            : " <<"Hilo";
                break;
            case 6:
                penjualanBarang<<"\nMenu            : " <<"Jus jeruk";
                break;
            case 7:
                penjualanBarang<<"\nMenu            : " <<"Jus Jambu";
                break;
            case 8:  
                penjualanBarang<<"\nMenu            : " <<"Fanta";
                break;
            case 9:
                penjualanBarang<<"\nMenu            : " <<"Teh tarik";
                break;
            case 10:
                penjualanBarang<<"\nMenu            : " <<"Kopi hitam";
                break;
            }
        }
    penjualanBarang<<"\nJumlah          : " << menuQty; 
    penjualanBarang<<"\nTotal Harga     : " << hargaMenu; 
    penjualanBarang<<"\n"; 
    penjualanBarang.close();

}

void appendMenu()
{
    string filename = "penjualan.txt";
    ofstream file;
    file.open(filename, ios::app);
}
//fungsi delete penjualan
void deletePenjualan()
{
    ofstream file("penjualan.txt");
    file<<"";
}
int main()
{
    //membersihkan penjualan hari sebelumnya
    deletePenjualan();
    char a; 
    bool n = true;
    int totalHarga = 0;
    //while bagian penjual
    while(n)
    {
        cout << "tutup atau buka(t/b)?" << endl; 
        cin >> a; 
        cout << "===============================" << endl; 
        if(a == 'b' || a == 'B')
        {
            bool p = true;
            //bagian pembeli 
            while(p)
            { 
                //nama Pembeli 
                string namaPembeli; 
                //menu console
                int menuMakan, menuMinum, menuMakanQty, menuMinumQty, kategoriMenu, hargaMinum, hargaMakan; 
                char pembeli; 
                cout << "Menu" << endl; 
                cout << "===============================" << endl; 
                int makanan[10] = {14000, 15000, 12000, 13000, 19000, 11000, 15000, 17000, 16000, 15000};
                int minuman[10] = {7000, 5000, 5000, 7000, 6000, 8000, 4000, 5000, 4000, 6000};  
                menu();
                cout << "===============================" << endl; 
                cout << "membeli?(y), keluar(t)?" << endl;
                cin >> pembeli; 
                if(pembeli == 'y'|| pembeli == 'Y')
                {
                    cout << "Masukkan nama: ";
                    cin >> namaPembeli; 
                    cout << "===============================" << endl; ;
                    cout << "Pilih kategori menu: 1. Makanan 2. Minuman"; 
                    cout << endl; 
                    cout << ">";
                    cin >> kategoriMenu; 
                    cout << "===============================" << endl; ;
                    //kategori makanan
                    if(kategoriMenu == 1)
                    {
                        cout << "Pilih menu makanan: "; 
                        cin >> menuMakan; 
                        cout << "Qty: "; 
                        cin >> menuMakanQty;
                        cout << "===============================" << endl; ; 
                        if(menuMakan > 0 && menuMakan <= 10)
                        {
                            totalHarga += makanan[menuMakan-1] * menuMakanQty;
                            hargaMakan = makanan[menuMakan-1] * menuMakanQty;
                        }
                        appendMenu();
                        penjualan(namaPembeli,kategoriMenu, menuMakan, menuMakanQty, hargaMakan);
                    }
                    //kategori mimuman
                    else if(kategoriMenu == 2)
                    {
                        cout << endl; 
                        cout << "Pilih menu minuman: "; 
                        cin >> menuMinum; 
                        cout << "Qty: "; 
                        cin >> menuMinumQty;
                        cout << "===============================" << endl; 
                        if(menuMinum > 0 && menuMinum <=10)
                        {
                            totalHarga += minuman[menuMinum-1] * menuMinumQty;
                            hargaMinum = minuman[menuMinum-1] * menuMinumQty;
                        }
                        appendMenu();
                        penjualan(namaPembeli, kategoriMenu, menuMinum, menuMinumQty, hargaMinum);
                    }
                }
                else if(pembeli =='t' || pembeli == 'T')
                {
                    p = false;
                    if(totalHarga == 0) 
                        cout << "Pembeli gajadi beli" << endl;
                    else
                    {
                        cout << "Total harga yang harus dibayar: " << totalHarga;  
                        cout << endl; 
                        cout << "===============================" << endl; 
                    
                    }  
                }
            }

        }
        else if(a == 't' || a == 'T')
        {
            cout << "History Penjualan" << endl; 
            cout <<"===============================" << endl; 
            n = false; 
            char penjualan[100]; 
            ifstream historyPenjualan; 
            historyPenjualan.open("penjualan.txt");
            if(totalHarga == 0) 
            {
                cout <<"Tidak ada penjualan";
            }
            else{
                
                while(historyPenjualan)
                {
                    historyPenjualan.getline(penjualan, sizeof(penjualan));
                    cout << endl; 
                    cout << penjualan; 
                }
            }
            historyPenjualan.close();
        }
    }
    return 0;
}