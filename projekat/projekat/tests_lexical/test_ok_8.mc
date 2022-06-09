//OPIS: Deklarisanje klase sa vise funkcija i medjupozivom
class Dragan {  
    int p;
    Dragan(int parametar){
        p = parametar;        
    }
    int funkcija1Test(int abc){
        return p+abc;
    }
    int funkcija2Test(int def){
        int m;
        m = funkcija1Test(6);
        return m + def;
    }
}

int main() {
    int randomVariable;
}