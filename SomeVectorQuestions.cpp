#include<iostream>
#include<vector>
#include<assert.h>
#include<iterator>
using namespace std;

/* 
 * Copy function customization with template class support
 */
template<typename Container, typename OutputItr>
OutputItr copy(const Container& c, OutputItr result) {
	return std::copy(c.begin(), c.end(), result);
}

int main() {
	std::vector<int> vtr;
	try {
	//std::cout<<"\nvtr[0]:"<<vtr[0]; // this will give the segmentation fault
	std::cout<<"\nvtr.at(0):"<<vtr.at(0); // this will throw the out of range execption
        }
	catch(std::exception e) {
		std::cout<<"\n Exception in the vector access\n";
		std::cout<<"\n E: "<<e.what();
	}

	vtr.reserve(5);
	std::cout<<"\nvtr[5]:"<<vtr[11]; // this will give the segmentation fault
        assert(vtr.capacity() >= 2);

	std::cout<<"\n Before Capacity: "<<vtr.capacity();
	vtr.reserve(4); /// reserve function never shrik the data from the vector
	std::cout<<"\n After Capacity: "<<vtr.capacity();
	std::cout<<"\n After size: "<<vtr.size();

	vtr.resize(10); // resize function only increase the size but not shrik the size resize(1)
	std::cout<<"\n After resize - Capacity: "<<vtr.capacity();

	// trying to add teh value at perticular index of the vector
	vtr.reserve(10); //after reserver abserved that all values are get assigned to Zero
	vtr[9]=100;
	std::cout<<"\n Trying to access index 99 :"<<vtr[99];
	std::cout<<"\n After size: "<<vtr.size();

	for(std::vector<int>::iterator itr=vtr.begin(); itr != vtr.end(); itr++) {
		//try to use the itearator to change the value in vector
		*itr=100;
	}
	//checking the iterator will change the value inside the array;
	//if we use the comparision itr < vtr.end()  might give un predictive output.
	for(std::vector<int>::iterator itr=vtr.begin(); itr != vtr.end(); itr++) {
		//try to use the itearator to change the value in vector
		std::cout<<"\n value : "<<*itr;
	}

        copy(vtr.begin(),vtr.end(), ostream_iterator<int>(std::cout, "\n"));
	//Now create a template class to handle the copy operation easy way
	//customize the operation
        copy(vtr, ostream_iterator<int>(std::cout, "\n"));

	return 0;
}
