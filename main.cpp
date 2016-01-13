#include <iostream>
#include <list>
#include <vector>

#include <gwachs/variadic_print.hpp>

using namespace std;
using namespace gwl::iostream;

struct Test{
    int a;
    int b;
};

std::ostream & operator<<(std::ostream &out, const Test& t){
    out << "{A=" << t.a << "  B=" << t.b << "}";
    return out;
}

int main() {

    print("Simple print\n");

    print("Testing different primitive types: ", 2,5.,6.,'z','\n'); //Uses default ostream's operator <<

    print("Testing custom printing ", Test{7,9},"\n"); //Uses overload ostream's operator <<


    //Using custom arithmetic separators
    printl<'-'>(1,5,7,9);
    printl<','>(1,5,7,9);
    printl<'\0'>(1,5,7,9);



    //printing containers
    std::list<int> l{1,2,3,4,5,6};
    printl(l,"\n");

    std::vector<int> v{10,9,8,7,6,5};
    printl(v,"\n");

    return 0;
}