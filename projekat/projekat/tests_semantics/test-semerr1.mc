//OPIS Deklarisanje dvije klase sa istim nazivom
class Dragan {  
    int p;
    int y;
    Dragan(int parametar, int x){
        p = parametar;
        y = x;        
    }
    int funkcija1Test(){
        return p;
    }
}

class Dragan {  
    int age;
    int anotherNumber;
    User(int parametar, int y){
        age = parametar;    
        anotherNumber = y;    
    }
    int getAge(){
        return age;
    }
}

int main() {
    int randomVariable;
    int randomVariable2;
    randomVariable2 = 6;
    randomVariable = 5;
    class Dragan draganInstance = new Dragan(randomVariable,randomVariable2);
    class User userTest = new User(randomVariable,randomVariable2);
}