#include <iostream>
#include <vector>
using namespace std;


//Class
class Compression {
	private:
		int data = 0;					//Data value
		int duplicate = 1;				//How many duplicates (multiplier)
		int prev = 0;					//Previous number

	public:

		//Constructors
		Compression(){}		//Default Constructor
		Compression(int new_data, int new_duplicate, int new_prev){
			this->data = new_data;
			this->duplicate = new_duplicate;
			this->prev = new_prev;
		}

		//Get & Set Methods
		int get_data(){return this->data;}
		int get_duplicate(){return this->duplicate;}
		int get_prev(){return this->prev;}
		void set_data(int new_data){this->data = new_data;}
		void set_duplicate(int new_duplicate){this->duplicate = new_duplicate;}
		void set_prev(int new_prev){this->prev = new_prev;}
		
		//Print Function (Compressed)
		void Print_compressed(){
			cout<<" "<<get_data()<<" ";
		}

		//Print Function (Decompressed)
		void Print_decompressed(){
			//Print data once for every duplication
			for (int i = 0; i < get_duplicate(); i++){
				cout<<" "<<get_data()<<" ";
			}
		}
};


int main(){

	//Create Vectors, vec1 is original, vec2 will be compressed original
	vector <int> vec1 {2,2,5,5,5,5,5,3,3,3,8,8,8,8,8,8,8,8,1,4,4,4,4,6,6,6,6,6,6};
	vector <Compression> vec2;


	//Print original vector
	cout<<"\nOriginal: \n";
	for(int a : vec1){
		cout<<" "<<a<<" ";
	}
	cout<<"\n\n";


	//This loop will take the original vector and compress and save it to our new vector
	for (size_t i = 0; i < vec1.size(); i++){
		//First element
		if (i == 0){
			//Set class variables to save
			Compression temp;
			temp.set_data(vec1.at(i));
			temp.set_duplicate(1);
			temp.set_prev(vec1.at(i));
			vec2.push_back(temp);			//Save class variables into our vector
			continue;
		}
		else {	//if (i > 0)
			//If our last vector is the same, we have a duplicate
			if (vec2.back().get_prev() == vec1.at(i)){
				int temp = vec2.back().get_duplicate();		//get the last duplicate number
				vec2.back().set_duplicate(temp+1);			//add one to the duplicate 
				continue;
			}
			//If we do not have a duplicate
			else{	
				//Set class variavles to save
				Compression temp;
				temp.set_data(vec1.at(i));
				temp.set_duplicate(1);
				temp.set_prev(vec1.at(i));
				vec2.push_back(temp);		//Save class variables into our vector
				continue;
			}
		}
		
	}


	//Print out new vector (compressed)
	cout<<"Compressed: \n";
	vector <Compression>::iterator it;
	for(it = vec2.begin(); it != vec2.end(); ++it){
		it->Print_compressed();								
	}
	cout<<"\n\n";

	//Print out new vector (decompressed)
	cout<<"Decompressed: \n";
	vector <Compression>::iterator it2;
	for(it2 = vec2.begin(); it2 != vec2.end(); ++it2){
		it2->Print_decompressed();		//Print class
	}
	cout<<"\n\n";


	exit(EXIT_SUCCESS);
}

