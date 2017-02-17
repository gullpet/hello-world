#include <stdbool.h>
#include <stdlib.h>

//Codice ascii, Codifica in decimale
const short int codice39[44][2] = {
{49, 289},
{50, 97},
{51, 352},
{52, 49},
{53, 304},
{54, 112},
{55, 37},
{56, 292},
{57, 100},
{48, 52},
{65, 265},
{66, 73},
{67, 328},
{68, 25},
{69, 280},
{70, 88},
{71, 13},
{72, 268},
{73, 76},
{74, 28},
{75, 259},
{76, 67},
{77, 322},
{78, 19},
{79, 274},
{80, 82},
{81, 7},
{82, 262},
{83, 70},
{84, 22},
{85, 385},
{86, 193},
{87, 448},
{88, 145},
{89, 400},
{90, 208},
{45, 133},
{46, 388},
{32, 196},
{42, 148},
{36, 168},
{47, 162},
{43, 138},
{37, 42},
};

// {A, B, C, Codifica}
const int codice128[107][4] = {
{32,32,0,212222},
{33,33,1,222122},
{34,34,2,222221},
{35,35,3,121223},
{36,36,4,121322},
{37,37,5,131222},
{38,38,6,122213},
{39,39,7,122312},
{40,40,8,132212},
{41,41,9,221213},
{42,42,10,221312},
{43,43,11,231212},
{44,44,12,112232},
{45,45,13,122132},
{46,46,14,122231},
{47,47,15,113222},
{48,48,16,123122},
{49,49,17,123221},
{50,50,18,223211},
{51,51,19,221132},
{52,52,20,221231},
{53,53,21,213212},
{54,54,22,223112},
{55,55,23,312131},
{56,56,24,311222},
{57,57,25,321122},
{58,58,26,321221},
{59,59,27,312212},
{60,60,28,322112},
{61,61,29,322211},
{62,62,30,212123},
{63,63,31,212321},
{64,64,32,232121},
{65,65,33,111323},
{66,66,34,131123},
{67,67,35,131321},
{68,68,36,112313},
{69,69,37,132113},
{70,70,38,132311},
{71,71,39,211313},
{72,72,40,231113},
{73,73,41,231311},
{74,74,42,112133},
{75,75,43,112331},
{76,76,44,132131},
{77,77,45,113123},
{78,78,46,113321},
{79,79,47,133121},
{80,80,48,313121},
{81,81,49,211331},
{82,82,50,231131},
{83,83,51,213113},
{84,84,52,213311},
{85,85,53,213131},
{86,86,54,311123},
{87,87,55,311321},
{88,88,56,331121},
{89,89,57,312113},
{90,90,58,312311},
{91,91,59,332111},
{92,92,60,314111},
{93,93,61,221411},
{94,94,62,431111},
{95,95,63,111224},
{0,96,64,111422},
{1,97,65,121124},
{2,98,66,121421},
{3,99,67,141122},
{4,100,68,141221},
{5,101,69,112214},
{6,102,70,112412},
{7,103,71,122114},
{8,104,72,122411},
{9,105,73,142112},
{10,106,74,142211},
{11,107,75,241211},
{12,108,76,221114},
{13,109,77,413111},
{14,110,78,241112},
{15,111,79,134111},
{16,112,80,111242},
{17,113,81,121142},
{18,114,82,121241},
{19,115,83,114212},
{20,116,84,124112},
{21,117,85,124211},
{22,118,86,411212},
{23,119,87,421112},
{24,120,88,421211},
{25,121,89,212141},
{26,122,90,214121},
{27,123,91,412121},
{28,124,92,111143},
{29,125,93,111341},
{30,126,94,131141},
{31,127,95,114113},
{-3,-3,96,114311},
{-2,-2,97,411113},
{-12,-11,98,411311},	//Shift
{-13,-13,99,113141},	//Code C
{-12,-4,-12,114131},	//Code B
{-4,-11,-11,311141},	//Code A
{-1,-1,-1,411131},
{-21,-21,-21,211412},	//Start A
{-22,-22,-22,211214},	//Start B
{-23,-23,-23,211232},	//Start C
{-20,-20,-20,2331112}	//Stop
};

/*
 A,       B,       C
*/
const int codiceEAN13[10][3] = {
{1112212, 1211222, 2221121},
{1122112, 1221122, 2211221},
{1121122, 1122122, 2212211},
{1222212, 1211112, 2111121},
{1211122, 1122212, 2122211},
{1221112, 1222112, 2112221},
{1212222, 1111212, 2121111},
{1222122, 1121112, 2111211},
{1221222, 1112112, 2112111},
{1112122, 1121222, 2221211},
};

const char* getValEAN(int codice){
	char* ans = (char*) malloc(sizeof(char) * 2);
	if(codice == 212){
		*ans = -5;
		ans[1] = -5;
		return ans;
	}
	if(codice == 12121){
		*ans = -6;
		ans[1] = -6;
		return ans;
	}
	for(int i=0;i<10;i++){
		if(codiceEAN13[i][0] == codice){
			*ans = i;
			*(ans+1) = 'A';
			return ans;
		}
		if(codiceEAN13[i][1] == codice){
			*ans = i;
			*(ans+1) = 'B';
			return ans;
		}
		if(codiceEAN13[i][2] == codice){
			*ans = i;
			*(ans+1) = 'C';
			return ans;
		}
	}
	*ans = -1;
	ans[1] = -1;
	return ans;
}

const int* getVal128(short int larghezze[], int i, int j, char mode){
	int codice = 0;
	int p=1;
	for(; j>=i; j--, p*=10)
		codice += larghezze[j] * p;
	int c;
	int* result = (int*) malloc(sizeof(int)*2);
	for(c=0;c<107;c++){
		if(codice128[c][3] == codice){
			*result = codice128[c][mode-65];
			*(result+1) = c;
			return result;
		}
	}
	*result = -99;
	result[1] = -99;
	return result;
}

int getVal39(bool bits[], int i, int j){
	short int p = 1;
	int ans = 0;
	for(;j>=i;j--, p*=2)
		ans += bits[j] * p;
	
	for(int i=0;i<44;i++){
		if(codice39[i][1] == ans)
			return codice39[i][0];
	}
	return -1;
}