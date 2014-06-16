#include<cmath>
#include<iostream>

// Returns the minimal 2^m (m natural number) that is greater than n.
constexpr int ceiling_prod2(int n) { 
    return (1 << static_cast<int>(ceil( log(n)/log(2)))); 
}

// template version
template<int N> constexpr int ceiling_prod2(void) { 
    return (1 << static_cast<int>(ceil( log(N)/log(2)))); 
}

int main(int argc, char **argv){
    for(int i = 10; i < 1000000; i *= 1.1){
        const int fftsize = ceiling_prod2( i );
        std::cerr << i << " " << fftsize << std::endl;
    }

    std::cerr << 3 << " " << ceiling_prod2< 3 >() << std::endl;
    std::cerr << 15 << " " << ceiling_prod2< 15 >() << std::endl;
    std::cerr << 431 << " " << ceiling_prod2< 431 >() << std::endl;
    std::cerr << 2351 << " " << ceiling_prod2< 2351 >() << std::endl;
    std::cerr << 612331 << " " << ceiling_prod2< 612331 >() << std::endl;
    std::cerr << 218953187 << " " << ceiling_prod2< 218953187 >() << std::endl;
}

// compile: g++ radix2.cpp -std=c++0x
