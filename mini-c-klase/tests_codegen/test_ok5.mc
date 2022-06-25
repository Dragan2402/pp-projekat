//OPIS: Deklarisanje dvije klase
//RETURN: 10
class Rectangle{  
    int a;
    int b;
    Rectangle(int parA,int parB){
        a = parA;
        b = parB;        
    }
    int getA(int par1){
        return a+par1;
    }
    int getB(){
    	return b;
    }
}

class Circle{  
    int r;
    Circle(int parR){
        r = parR;        
    }
    int getR(){
        return r;
    }
    int getRFull(){
    	return r+r;
    }
}


int main() {
    int aX;
    int bX;	
    int test1;
    int test2;
    int test3;
    aX = 5;
    bX = 6;
    test3 = 5;
    
    class Rectangle rectangleInstance = new Rectangle(aX,bX);
    test1 = rectangleInstance.getA(test3);
    test2 = rectangleInstance.getB();
    class Circle circleInstance = new Circle(aX);
    return circleInstance.getRFull();
}