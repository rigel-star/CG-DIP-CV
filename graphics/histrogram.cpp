#include <iostream>

using namespace std;


int *histo(int gram[]){
	
	static int newHisto[256];
	
	for(int i=0; i<sizeof(gram); i++){
		int p = gram[i];
		int r = (p >> 16) & 256;
		newHisto[r]++;
	}
	
	return newHisto;
	
}


int main(void){
	
	
	int gram[40] = {123, 45, 67, 21, 34, 98, 198, 213, 255, 21, 22, 24, 43, 54, 46, 90, 231, 78, 62, 156,
					123, 45, 67, 21, 34, 98, 198, 213, 255, 21, 22, 24, 43, 54, 46, 90, 231, 78, 62, 156};
	
	int *gramming = histo(gram);
	
	for(int i=0; i<sizeof(gramming); i++){
		cout << *gramming << endl;
	}
	
	
	return 0;
}