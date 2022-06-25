//OPIS: Test klasa bez parametara 
//RETURN: 5
class Test{
	Test(){}
	int getFive(){
		return 5;
	}
}


int main() {
	class Test testInstance = new Test();
	return testInstance.getFive();
}