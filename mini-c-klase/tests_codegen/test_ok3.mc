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

int pet(int test){
    int y;
    y= test;
    return y;
}

int main() {
    int randomVariable;
    int test;
    randomVariable = 5;
    class Dragan draganInstance = new Dragan(randomVariable);
    test = draganInstance.funkcija1Test();
    return pet(randomVariable);
}

