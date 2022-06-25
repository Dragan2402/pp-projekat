//OPIS: Instanciranje klase i poziv funkcije klase
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
    int result;
    randomVariable = 5;
    class Dragan draganInstance = new Dragan(randomVariable);
    result = draganInstance.funkcija1Test();
    return draganInstance.funkcija1Test();
}


