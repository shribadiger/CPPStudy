#include<iostream>
#include<vector>
using namespace std;

std::vector<int> FibSeries;

void genFibSeries(int num){
    int fib1=0;
    int fib2=1;
    FibSeries.reserve(num);
    FibSeries[0]=fib1;
    FibSeries[1]=fib2;
    for(int i=2;i<num;i++) {
        FibSeries[i]=FibSeries[i-2]+FibSeries[i-1];
    }
    for(int i=0;i<num;i++) {
	    std::cout<<"\t"<<FibSeries[i];
    }
    std::cout<<"\n";
}

int getFinalNumber(int num) {
    int result=0;
    int repeater=1;
    for(int i=0;i<num;i++){
        FibSeries[i]=FibSeries[i]%10;
    }
    for(int i=0;i<num;i++) {
	    std::cout<<"\t"<<FibSeries[i];
    }
    std::cout<<"\n";
    int i=0;
    while(num != 1) {
	for(i=0;i<num/2;i++) {
	std::cout<<"\n --------------------------\n";
        FibSeries[i]=FibSeries[repeater];
	std::cout<<"\t"<<FibSeries[i];
        repeater=repeater+2;
	}
	std::cout<<"\n";
        num=num/2;
	std::cout<<"\n\n NUM : "<<num<<"\n\n";
    }
    return(FibSeries[num]);
    
}

int main() {
    int test;
    cin>>test;
    for(int i=0;i<test;i++) {
        int num;
        cin>>num;
        genFibSeries(num);
        int result = getFinalNumber(num);
        std::cout <<result << std::endl;
    }
}
