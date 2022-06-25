//OPIS: Deklarisanje klase i pozivi funkcija klase
//RETURN: 333


class Person{  
    int age;
    int height;
    int weight;
    int shoeSize;
    Person(int parAge,int parHeight,int parWeight,int parShoe){
        age=parAge;
        height=parHeight;
        weight = parWeight;
        shoeSize = parShoe;        
    }
    int getAge(){
        return age;
    }
    int getHeight(){
    	return height;
    }
    int getWeight(){
    	return weight;
    }
    int getShoe(){
    	return shoeSize;
    }
    
    int getSumPlusFive(int addPar){
    	return getAge() + getHeight()+getWeight()+getShoe()+addPar;    	
    }
    
}

int main() {
	int a;
	int h;
	int w;
	int s;
	int add;
	a = 25;
	h = 180;
	w = 80;
	s = 43;
	add = 5;
	
	class Person personInstance = new Person(a,h,w,s);
	return personInstance.getSumPlusFive(add);
}