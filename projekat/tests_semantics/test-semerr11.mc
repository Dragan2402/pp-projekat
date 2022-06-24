//OPIS: Deklarisanje nepostojece klase
class Dragan {  
    int p;
    int y;
    Dragan(int parametar,int parametar2){
        p = parametar;  
        y=parametar2;      
    }
}

int main() {
    int randomVariable;
    unsigned randomVariable2;
    class Dragan draganInstance = new Dragan(randomVariable,randomVariable2);
}