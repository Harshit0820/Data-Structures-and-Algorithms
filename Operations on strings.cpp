// ALL STRING OPERATIONS IN ONE PROJECT FROM VIDEO 132-141
#include<iostream>
using namespace std;

// FOR FINDING LENGTH WE CAN EVEN USE s.length() DIRECT METHOD FOR LENGTH OF STRING
// NOTE: SPACE B/W 2 STRINGS IS ALSO CONSIDER IN THE CALCULATION OF LENGTH OF WHOLE STRING
int LengthOfString(string str)
{
	int i;
	for (i = 0;; i++)
	{
		if (str[i] == '\0')
			break;
	}
	return i;

}

string lower_string(string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
	return str;
}

void noOfvowelsandcons(string str)
{
	int v = 0, c = 0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
		str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
			v++;
		
		else if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
			c++;
	}
	cout<<"\nNo. of vowels in string: "<<v<<" and No. of consonants in string: "<<c;
}

void noOfwords(string str)
{
	int w=1;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == ' ' && str[i-1] != ' ')//if there is NO space prev to a space then increment
			w++;
	}
	cout<<"\nNo. of words in string: "<<w;
}

// NOTE: HERE, SPACE IS CONSIDERED AS VALID PART BETWEEN 2 STRINGS
// (IT DEPENDS ON USER WHETHER TO CONSIDER SPACE AS VALID OR INVALID PART)
// (USUALLY CONSIDER AS INVALID PART, BUT HERE FOR OPERATIONS AND EGS WE HAVE CONSIDER SPACE AS VALID PART)
int validating(string str)
{

	for (int i = 0; str[i] != '\0'; i++)
	{
		// WE ARE CHECKING FOR INVALID CONDITIONS
		if (!(str[i] >= 65 && str[i] <= 90)&&
		!(str[i] >= 97 && str[i] <= 122)&&
		!(str[i]>=48 && str[i]<=57)&& !(str[i]==32))
		{
			return 0;
		}	
	}
	// NOTE: HERE, UPPER CASE, LOWER CASE, NUMBERS AND SPACE IS CONSIDERED AS VALID PART IN A STRING
	return 1;	
}

void reverse(string str)
{
	int i, j, temp;
	j = LengthOfString(str) - 1;
	for (i = 0; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	cout << "\nReverse string is: " << str;
}

// NOTE: SOMETIMES THE SAME ALPHABETS CAN OF UPPER CASE AND LOWER CASE IN 2 STRINGS
// SO TO GET CORRECT O/P CONVERT BOTH STRINGS TO FULLY SINGLE CASE (EITHER UPPER OR LOWER)
// AS CODE WILL CONSIDER SAME ALPHABET'S UPPER AND LOWER CASE AS DIFFERENT THING DUE TO DIFFERENT ASCII CODE
void stringCompare(string A, string B){
	int i,j;
	for(i=0,j=0; A[i]!='\0' || B[j]!='\0'; i++,j++){
		if(A[i]!=B[j]){ // checking not equal strings condition
			break;
		}
	}
	// After breaking from for loop below if and else conditions will be checked
	if(A[i]==B[j]){
		cout<<"\nBoth strings are equal";
	}
	else if(A[i]<B[j]){
		cout<<"\nFirst string is smaller and Second string is greater";
	}
	else{
		cout<<"\nFirst string is greater and Second string is smaller";
	}
}

// NOTE: PALINDROME IS UPPER AND LOWER CASE SENSITIVE
void isPalindrome(string S)
{
	S=lower_string(S); // making lower case string to get correct o/p
	int l = 0;
	int h = LengthOfString(S) - 1;

	while (h > l){
		if (S[l++] != S[h--]) // Checking NOT palindrome or NOT equal alphabets condition
		{
			cout << "\nString is Not Palindrome"<<endl;
			return;
		}
	}
	cout << "\nString is Palindrome"<<endl;
}

// NOTE: SPACE B/W STRING IS ALSO CONSIDERED AS CHARACTER SO DUPLICATION OF SPACE WILL ALSO BE PRINTED
// INCLUDING SPECIAL CHARACTERS, NUMBERS, ALPHABETS ETC. 
// (teacher code in notes kind of same code using hashtable, but this code is better)
void PrintDuplicate_Hashtable(string str)
{
	cout<<"Duplicates (using hashtable method) are: ";
	int H[128] = {0}; // big size of hashtable for checking duplication of more chars including alphabets
	str = lower_string(str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		H[str[i] - 'a']++;
		if (H[str[i] - 'a'] == 2) // checking for 1 repitition only
		{
			cout << str[i];
		}
	}
}

// [FOR BETTER EXPLANATION OF THIS TOPIC AND OPERATION SEE VIDEO-139 OF SECTION-8 OF COURSE]
// NOTE: ALL THE EXPLANATION OF CONCEPTS AND CODE USED IN THIS OPERATION IS IN EITHER NOTES OR IN VIDEO-139
void PrintDuplicate_Bitwise(string W)
{
	int H = 0, x = 0;
	W = lower_string(W);
	for (int i = 0; W[i] != '\0'; i++){
		x = 1; // setting LSB as 1 (as required)
		x = x<<(W[i]-97); // MASKING PROCESS
		if((x & H) > 0){
			cout<<endl<<W[i]<<" is duplicate in the string";
		}
		else{
			H = x | H; // MERGING PROCESS
		}
	}
}

// NOTE: FOR DUPLIACTES TO BE IN STRINGS IN ANAGRAM OPERATION, 
// TO BE ANAGRAM THERE MUST BE SAME NO. OF SAME ALPHABET'S DUPLICATES IN EACH STRING
// (i.e. if C has 5 a's, so to be anagram with D, D must also have 5 a's, independent of index position)
void isAnagram(string C, string D)
{
	// making lower case string to get correct o/p
	C = lower_string(C);
	D = lower_string(D);
	
	int H[26] = {0}; // size of hashtable for checking only lower case alphabets
	// for checking of all chars space,no.,special chars,upper case,etc. take big size i.e. 128 (all chars)
	int i;
	for(i=0; C[i]!='\0'; i++){
		H[C[i]-97] += 1;
	}
	for(i=0; D[i]!='\0'; i++){
		H[D[i]-97] -= 1;
		if(H[D[i]-97] < 0){ // jusy one -1 then break no need further
			cout<<"\nStrings are not anagram";
			break;
		}
	}
	if(D[i] == '\0'){ // checking we reached D's last element i.e. if D is got finished
		cout<<"\nStrings are anagram";
	}
	
}

// [FOR BETTER EXPLANATION OF THIS TOPIC AND OPERATION SEE VIDEO-141 OF SECTION-8 OF COURSE]
// NOTE: WE HAVE USED 1ST METHOD CODE HERE, 2ND METHOD CODE IN NOTES 
// (BUT 1ST METHOD IS BETTER AS IT DOES NOT CHANGES THE ORIGINAL STRING, RATHER USES OTHER STRING FOR RESULT)
void Permutation(string N, int k){ // k is call no. for result increamenting and calling operation
	static int A[10]={0};
	static char Res[10];
	int i;
	if(N[k]=='\0'){
		Res[k]='\0';
		cout<<Res<<endl;
	}
	else{
		for(i=0;N[i]!='\0';i++){
			if(A[i]==0){
				Res[k]=N[i];
				A[i]=1;
				Permutation(N,k+1);
				A[i]=0; // Done Backtracing time
			}
		}
	}
}

int main(){
	string str = "HELLO   WORLDDD 1233"; // HERE, 3 SPACES OR WHITE SPACE B/W 'HELLO' AND 'WORLD'
	
	// Here we are giving strings A and B eg as NOT equal string
	string A = "Painter";
	string B = "Painting";
	// Here we are giving strings A1 and B1 eg as equal string
	string A1 = "Python";
	string B1 = "Python";
	
	string S = "Madam";
	
	string W = "Finding";
	
	// Here we are giving strings C1 and D1 eg as NOT anagram string
	string C = "Daredevil";
	string D = "Medieval";
	// Here we are giving strings C and D eg as anagram string
	string C1 = "Decimal";
	string D1 = "Medical";
	
	string N = "ABC";

	cout << "Length of string is: "<<LengthOfString(str);
	
	cout << "\nThe string in lower case: " << lower_string(str);
	
	noOfvowelsandcons(str);
	
	noOfwords(str);
	
	if(validating(str)==1){
		cout<<"\nA valid string";
	}
	else if(validating(str)==0){
		cout<<"\nNot a valid string";
	}
	
	reverse(str);
	
	// Strings A, B, A1, B1 are used in compare operation
	stringCompare(A,B);
	stringCompare(A1,B1);
	
	// String S is used in palindrome operation
	isPalindrome(S);

	PrintDuplicate_Hashtable(str);
	
	// String W is used in finding duplicates using bitwise operation
	PrintDuplicate_Bitwise(W);
	
	// Strings C, D, C1, D1 are used in anagram operation
	isAnagram(C,D);
	isAnagram(C1,D1);
	
	// String N is used in permutation operation
	cout<<"\nPermutations of string are: "<<endl;
	Permutation(N,0); // k=0 initially

}
// NOTE: \0 IS CONSIDERED AS TAKING MEMORY IN STRING IN PC 
// BUT IT DOES NOT CONSIDER WHILE CALCULATION OF LENGTH OF STRING
