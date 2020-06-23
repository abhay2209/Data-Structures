#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Note: the names in this code use a number of standard prefixes, which you should know.  I've thrown
// in a few others in this list. They can be used with CamelCase or underscore_separated naming conventions.
//
//		min		minimum
//		max		maximum
//		avg		average
//		std		standard
//		temp	temporary (try not to use "temp" by itself as a variable name.  Say what the temporary holds.)
//		num		number of (when used as a prefix only.  Used as a suffix, it indicates an index or ID number.
//					       for example, numFiles is the number of files you have.  fileNum is the ID number
//						   of one particular file.)
//
//	Some people, notably people who learned to use C-style in C++, also use "in" as a prefix for "input", 
//  and "out" as a prefix for "output".  My preference is to not use these prefixes.
//
//  In general, except in the case of the standard prefixes, I advocate writing words out fully.  Don't use
//  "rng" for "range", for instance.  As another example, it would be disastrous to abbreviate "comparisons"
//  in the following main() function as "comp".  When the brain sees "comp" it has to sort out what that
//  means--it could be "computer" or "comprehensive" or "complete" or "computation", etc.--so writing it
//  out is essential.  Most of the comments in the code are meant to help out students and could be eliminated
//  in professional code.
//
//  Note that the correct specification of what a function may throw requires parentheses around the type, as
//  with writeArray() below.

class FileOpeningException {
private:
	string errorMessage;
public:
	FileOpeningException(string message) {
		errorMessage = message;
	}
	string getMessage() {
		return errorMessage;
	}
};

string* readWords(string filename, int & arraySize);
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException);
int numLinesInFile(string filename);
int isInAlphabeticalOrder(string s);
float avg_num_comparisons(string *arr, int numOfWords);
float* avg_comparisons_for_length(string *s,int numOfWords,int maxLength);




int main (void) {
	int numWords;
	string wordListFilename = "./wordlist";
	string outputFilename = "average_comps.txt";

	// This reads the words from wordListFilename.
	// numWords will be the number of words in the array words
	// words[i] will be the ith word
	string *words = readWords(wordListFilename, numWords);


	// TO DO:: You can remove/comment out this.
	// Print out the list.
	//for (int i=0; i<numWords; i++) {
	//	cout << words[i] << endl;
	//}


	// TO DO:: You should compute these values.
	float avgWordLength=0;
	float avgNumComparisons=0;
	int maxWordLength=0;  
	float *avgComparisonsForLength;  // avgComparisonsForLength[i] is the average number of comparisons for a word of length i.


   // TO DO:: Insert your code here.
	int num_of_words = numLinesInFile(wordListFilename); 
	float total_word_length = 0;
	
    // The purpose of this loop is to find the total length of words from which i can calculate the average
    // At the same time i am using this to find the length of the longest word
	for(int i=0;i<num_of_words;i++){
		float single_word_length = words[i].length();
		if(single_word_length > maxWordLength){
			maxWordLength=single_word_length;
		}
		total_word_length += single_word_length;
    }
    avgWordLength = (total_word_length*1.0)/num_of_words; // this completes part 1 of question 1)
    cout<<avgWordLength<<endl; // I am also prinitng my answers in case you run my words.cpp 
    avgNumComparisons = avg_num_comparisons(words,num_of_words);// I passed the values in a function that does all the work
    cout<<avgNumComparisons<<endl;

    avgComparisonsForLength = avg_comparisons_for_length(words,num_of_words,maxWordLength);
    

   // Print average number of comparisons for each length to a file for plotting.
	writeArray(outputFilename, avgComparisonsForLength, maxWordLength+1);

	// Clean up memory and return.
	delete[] words;
	delete[] avgComparisonsForLength; // as this points to a heap memory which has to be deleted
	return 0;
}
// At first i created global variables for computing comparisons, but this function is used a lot so changing its return type saves a lot of lines
int isInAlphabeticalOrder(string s) {  // 	The return type is changed to int so i can return the amout of comparisons I am doing
	int length = s.size();
	float comparison_count = 0;  // initialised it over here
    for (int i = 0; i < length - 1; ++i) {
    	comparison_count++; // Its calculated over here
		if (s[i] > s[i+1]) {
			return comparison_count; 
		}
	}
	return comparison_count;
}

float avg_num_comparisons(string *arr, int numOfWords){ //This is the second part of the assignment
float total_comparisons = 0;
for(int i=0;i<numOfWords;i++){
	total_comparisons+=isInAlphabeticalOrder(arr[i]); // or else i would have used the global variable for addition if the return type was bool for isInAlphabeticalOrder
}
return total_comparisons/(1.0*numOfWords); // returns the average
}
float* avg_comparisons_for_length(string *s,int numOfWords,int maxLength){
//i will create two arrays, one of them will add the number of comparisons for particular length and the other one will add the number of words
//in the end i will divide the two and return the one which saves averages
float *wordCount =  new float[maxLength+1];// This saves number of words for each length
float *totalLength = new float[maxLength+1];// this adds length for each length of words in different index
 
for(int i=0;i<maxLength+1;i++){ //initialization of both the arrays

	wordCount[i]=0;
	totalLength[i]=0;      
}
for(int i =0;i<numOfWords;i++){//Calculating the amount of words for a particular length and adding the comparisons for each
	wordCount[s[i].size()]++;
	totalLength[s[i].size()]+=isInAlphabeticalOrder(s[i]);
}
for(int i=1;i<maxLength+1;i++){ // start from 1 as it doesnt make sense for length 0

	totalLength[i]=totalLength[i]/wordCount[i]; // save the average in the total length array
}
delete[] wordCount; // deleting as we don't need this
return totalLength; // returning the array pointing to the heap
}


// Writes the array arr in text format to a file named filename.
// each element of the array has its own line in the file, 
// which contains the element's index and value, separated by a space.
void writeArray(string filename, float *arr, int arraySize) throw (FileOpeningException){
	ofstream outputStream(filename.c_str());

	if (outputStream.fail()) {
		throw new FileOpeningException("Error opening " + filename);
	}

	for (int i = 0; i<arraySize; i++) {
		outputStream << i << " " << arr[i] << endl;
	}
	outputStream.close();
}

int numLinesInStream(ifstream& stream) {
	int numLines = 0;
	string tempLine;

	// getline returns 0 at end of file.
	while (getline(stream, tempLine)) {
		numLines++;
	}
	return numLines;
}

// note how the following function is all about one thing:
// the handling of the ifstream called inputStream().
// the exact computation done using inputStream() is abstracted
// to a single call (to numLinesInStream).
// Here, I don't declare the thrown object with a "throw ()" on the
// first line.  It's optional, so I'm leaving it off this time.
int numLinesInFile(string filename) {
	ifstream inputStream(filename.c_str());

	if (inputStream.fail()) {
		throw new FileOpeningException(filename + "... file not found ...");
	}

	int numLines = numLinesInStream(inputStream);

	inputStream.close();
	return numLines;
}

// Reads lines from a file named filename.
// Returns an array of strings, one per line of the file filename, 
// and places the size of the array in the reference parameter (output parameter) arraySize
string* readWords(string filename, int & arraySize) {
	string* result = NULL;
	arraySize = numLinesInFile(filename);
	ifstream inputStream(filename.c_str());

	// Read file contents into result, now that size is known
	result = new string[arraySize];			//create results array
	for (int i=0; i < arraySize; i++){
		getline(inputStream, result[i]);
	}
	inputStream.close(); //don't forget to close file

    return result;
}


