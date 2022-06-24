//OPIS: Instanciranje klase i poziv funkcije klase razliciti tipovi
class Dragan {  
    int p;
    Dragan(int parametar){
        p = parametar;        
    }
    unsigned funkcija1Test(){
        return p;
    }
}

class Pero {  
    int p;
    Pero(int parametar){
        p = parametar;        
    }
    unsigned funkcija1Test(){
        return p;
    }
}

int main() {
    int randomVariable;
    int result;
    randomVariable = 5;
    result= 6;
    class Dragan draganInstance = new Dragan(randomVariable);
    class Pero perence = new Pero(randomVariable);
    result = draganInstance.funkcija1Test();
    return perence.funkcija1Test();
}