#include <iostream>
#include <ctime>

bool maggiori_ele(int v[], int n, int ele);

int main(){

    int lung_vett = 20;
    int vett[lung_vett];
    int elemento = 2;
    int val_min = 1;
    int val_max = 20;

    srand(time(NULL));

    std::cout << std::endl;
    std::cout << "\tVettore: ";

    for(int i = 0; i < lung_vett; i++){
        vett[i] = val_min + (rand() % (val_max - val_min + 1));
        if(i < lung_vett-1)
            std::cout << vett[i] << ", ";
        else
            std::cout << vett[i];
    }

    std::cout << std::endl;
    std::cout << "\tValore: " << elemento << std::endl;
    std::cout << std::endl;

    if(maggiori_ele(vett, lung_vett, elemento) == true){
        std::cout << "\tTutti gli elementi del vettore sono minori di: " << elemento;
        std::cout << std::endl;
    }else{
        std::cout << "\tCi sono elementi maggiori di: " << elemento;
        std::cout << std::endl;
    }

    return 0;
}

bool maggiori_ele(int v[], int n, int ele){
    if(n <= 0)                              // condizione di terminazione della ricorsione
        return true;

    if(maggiori_ele(v, n-1, ele) == false)  // chiamata ricorsiva + passo di avvicinamento
        return false;

    if(v[n-1] > ele)                        // risultato costruito a ritroso
        return false;

    return true;
}
