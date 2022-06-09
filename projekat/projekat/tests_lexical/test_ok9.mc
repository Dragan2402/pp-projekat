//OPIS: Deklarisanje klase i kreiranje instance klase
class Dragan {  
    int p;
    Dragan(int parametar){
        p = parametar;        
    }
    int funkcija1Test(){
        return p;
    }
}

int main() {
    int randomVariable;
    randomVariable = 5;
    class Dragan draganInstance = new Dragan(randomVariable);
}