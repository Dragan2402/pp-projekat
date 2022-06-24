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
    int test;
    randomVariable = 5;
    class Dragan draganInstance = new Dragan(randomVariable);
    test = draganInstance.funkcija1Test();
    return test;
}