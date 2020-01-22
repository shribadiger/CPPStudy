#include<iostream>
#include<iomanip>
using namespace std;

typedef enum PLC_Family_Type {
	type_1500=0x00,
	type_1200=0x01,
} S7Plus_PLC_Type;

typedef enum Common_Key {
	common_public_key = 0x10
}S7Plus_Common_Key;

typedef enum Key_Flags {
	key_flag_1500 = type_1500<<8 | common_public_key,
	key_flag_1200 = type_1200<<8 | common_public_key
}S7Key_Flag;

int main() {
	std::cout<<"\n Getting the Public Key for PLC type\n";
	std::cout<<"\n Key Value for 1500  : "<<std::hex<<setw(4)<<S7Key_Flag::key_flag_1500;
	std::cout<<"\n Key Value for 1200  : "<<std::hex<<setw(4)<<S7Key_Flag::key_flag_1200;
	std::cout<<"\n";
	return 0;
}
