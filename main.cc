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

	cout<<"\n";
	cout<<"---------------------------------------------------------------------------------\n";
	cout<<"-----------------------------      VECTORS       --------------------------------\n";
	cout<<"---------------------------------------------------------------------------------\n";


	//Create Vectors, vec1 is original, vec2 will be compressed original
	vector <int> vec1 {2,2,5,5,5,5,5,3,3,3,8,8,8,8,8,8,8,8,1,4,4,4,4,6,6,6,6,6,6};
	vector <Compression> vec2;


	//Print original vector
	cout<<"\nVector: \n";
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
				//Set class variables to save
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
	cout<<"\n\n\n";


	cout<<"---------------------------------------------------------------------------------\n";
	cout<<"----------------------------   2D   VECTORS       -------------------------------\n";
	cout<<"---------------------------------------------------------------------------------\n";


	//Create 2D vector and vector to save it in
	vector <vector <int>> Vec  {{2,2,5,5,5,5,5,3,3,3}, 
		{8,8,8,8,8,8,8,8,1},
		{4,4,4,4,6,6,6,6,6,6}};
	vector <vector <Compression>> Vec2 {{}, {}, {}};


	//Print 2D Vector
	cout<<"\n2D Vector: \n";
	for(size_t i = 0; i < Vec.size(); i++){
		for (size_t j = 0; j < Vec.at(i).size(); j++){
			cout<<" "<<Vec.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n";


	//This loop will take the 2D vector and compress and save it to our new vector
	for (size_t i = 0; i < Vec.size(); i++){
		for (size_t j = 0; j < Vec.at(i).size(); j++){
			//First element
			if (j == 0){
				//Set class variables to save
				Compression temp;
				temp.set_data(Vec.at(i).at(j));
				temp.set_duplicate(1);
				temp.set_prev(Vec.at(i).at(j));
				Vec2.at(i).push_back(temp);			//Save class variables into our vector
				continue;
			}
			else {
				//If our last vector is the same, we have a duplicate
				if (Vec2.at(i).back().get_prev() == Vec.at(i).at(j)){
					//get the last duplicate number
					int temp = Vec2.at(i).back().get_duplicate();
					//add one to the duplicate 
					Vec2.at(i).back().set_duplicate(temp+1); 
					continue;
				}
				//If we do not have a duplicate
				else{	
					//Set class variavles to save
					Compression temp;
					temp.set_data(Vec.at(i).at(j));
					temp.set_duplicate(1);
					temp.set_prev(Vec.at(i).at(j));
					Vec2.at(i).push_back(temp);		//Save class variables into our vector
					continue;
				}
			}	
		}
	}


	//Print out new vector (compressed)
	cout<<"Compressed: \n";
	for (size_t i = 0; i < Vec2.size(); i++){
		for (size_t j = 0; j < Vec2.at(i).size(); j++){
			cout<<" "<<Vec2.at(i).at(j).get_data()<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n";


	//Print out new vector (decompressed)
	cout<<"Decompressed: \n";
	for (size_t i = 0; i < Vec2.size(); i++){
		for (size_t j = 0; j < Vec2.at(i).size(); j++){
			for (int k = 0; k < Vec2.at(i).at(j).get_duplicate(); k++){
				cout<<" "<<Vec2.at(i).at(j).get_data()<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"\n\n";



	exit(EXIT_SUCCESS);
}

