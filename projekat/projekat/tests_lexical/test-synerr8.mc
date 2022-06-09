//OPIS: Nepravilno pozivanje metode
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
    class Dragan dragan =   new Dragan(5);
    randomVariable = funkcija1Test.();
}