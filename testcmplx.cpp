/*
 * =====================================================================================
 *
 *       Filename:  testcmplx.cpp
 *
 *    Description: test fmt on complex numbers 
 *
 *        Version:  1.0
 *        Created:  2021-04-29 11:01:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francis Grizzly Smit (FGJS), grizzly@smit.id.au
 *   Organization:  
 *
 * =====================================================================================
 */

#include "complexfmt.h"
#include "colourfmt.h"
#include "fmt/color.h"
#include <ios>
#include <vector>
#include <numeric>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
int main(int argc, char *argv[]){
    using std::complex_literals::operator""i;
    using std::complex_literals::operator""if;
    using std::complex_literals::operator""il;
    using std::literals::string_literals::operator""s;
    using namespace fmt::literals;
    std::complex<double> z = 3.1415926536 + 2.71828182845i;
    std::cout << fmt::format("z == {0:,0.10} == {0:@0.10}\n{1}z == {0:$@;0.10}{2} == {0:,;0.10}\nz == {0:*;0.10} == {0}"s, z,
            fg(fmt::color::green) | bg(fmt::color::blue) | fmt::emphasis::bold, fmt::reset_colour()) << std::endl;
    std::cout << fmt::format("z == {:@*0^{}.{}f}", z, 25, 20) << std::endl;
    std::cout << fmt::format("z == {:@ >{}.{}f}", z, 25, 20) << std::endl;
    
    std::complex<double> w = 4.98 - 34.765i;
    std::cout << fmt::format("w == {:{}.{}}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {:@*0^{}.{}f}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {:@ >{}.{}f}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {0:,0.10} == {0:@0.10}\nw == {0:$@;0.10} == {0:,;0.10}\nw == {0:*;0.10} == {0}"s, w) << std::endl;
    std::cout << fmt::format("z == {z:,{width}.{precis}}", "z"_a=z, "width"_a=25, "precis"_a=20) << std::endl;
    std::cout << fmt::format(fg(fmt::color::green) | bg(fmt::color::brown) | fmt::emphasis::bold,
            "w == {thecomplex:$_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20, fmt::reset_colour()) << std::endl;
    std::cout << fmt::format("w == {thecomplex:,_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    std::cout << fmt::format("w == {thecomplex:|_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    fmt::print(fg(fmt::color::green) | bg(fmt::color::blue) | fmt::emphasis::bold,
            "z == {thecomplex:|_{width}.{precis}}\n", "thecomplex"_a=z, "width"_a=20, "precis"_a=20);
    std::cout << "{}w == {:|_{}.{}}{}"_format(fg(fmt::color::green) | bg(fmt::color::brown) | fmt::emphasis::bold, w, 20, 20, fmt::reset_colour()) << std::endl;

    return 0;
}

