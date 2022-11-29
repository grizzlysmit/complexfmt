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

// {fmtextras} stuff //
#include "complexfmt.h"
#include "colourfmt.h"
// {fmt} colour stuff //
#include "fmt/color.h"
// std stuff  //
#include <fmt/core.h>
#include <ios>
#include <vector>
#include <numeric>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "testcmplx.h"
int main(int argc, char *argv[]){
    using std::complex_literals::operator""i;
    using std::complex_literals::operator""if;
    using std::complex_literals::operator""il;
    using std::literals::string_literals::operator""s;
    //*
    if(argc < 2){
        // report version
        std::cout << argv[0] << " Version " << testcmplx_VERSION_MAJOR << "."
                  << testcmplx_VERSION_MINOR << "." << testcmplx_VERSION_PATCH << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }    
    // */
    using namespace fmt::literals;
    std::complex<double> z = 3.1415926536 + 2.71828182845i;
    auto s0 = fmt::format("z == {0:,0.10} == {0:@0.10}\n{1}z {5}=={1} {0:$@;0.10} {3}=={4} {0:,;0.10}{2}\nz == {0:*;0.10} == {0}", z,
            fg(fmt::color::green) | bg(fmt::color::red) | fmt::emphasis::bold, fmtextras::reset_colour(),
            fg(fmt::color::blue) | bg(fmt::color::red) | fmt::emphasis::bold,
            fg(fmt::color::yellow) | bg(fmt::color::red) | fmt::emphasis::bold,
            fg(fmt::color::blue) | bg(fmt::color::red) | fmt::emphasis::bold);
    std::cout << s0 << "\n";
    auto s1 = fmt::format("z == {:@*0^{}.{}f}\n", z, 25, 20);
    std::cout << s1;
    auto s2 = fmt::format("z == {:@ >{}.{}f}\n", z, 25, 20);
    std::cout << s2;
    
    std::complex<double> w = 4.98 - 34.765i;
    //*
    std::cout << fmt::format("w == {:{}.{}}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {:@*0^{}.{}f}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {:@ >{}.{}f}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {0:,0.10} == {0:@0.10}\nw == {0:$@;0.10} == {0:,;0.10}\nw == {0:*;0.10} == {0}", w) << std::endl;
    std::cout << fmt::format("z == {z:,{width}.{precis}}", "z"_a=z, "width"_a=25, "precis"_a=20) << std::endl;
    std::cout << fmt::format(fg(fmt::color::green) | bg(fmt::color::brown) | fmt::emphasis::bold,
            "w == {thecomplex:$_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20, fmtextras::reset_colour()) << std::endl;
    std::cout << fmt::format("w == {thecomplex:,_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    std::cout << fmt::format("w == {thecomplex:|_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    // */
    fmt::print(fg(fmt::color::green) | bg(fmt::color::blue) | fmt::emphasis::bold,
            "z == {thecomplex:|_{width}.{precis}}\n", "thecomplex"_a=z, "width"_a=20, "precis"_a=20);
    /*
    std::cout << "{startcolour}w == {thecomplex:|_{width}.{precis}}{endcolour}"_format("startcolour"_a=fg(fmt::color::green) | bg(fmt::color::brown) | fmt::emphasis::bold,
            "thecomplex"_a=w, "width"_a=20, "precis"_a=20, "endcolour"_a=fmtextras::reset_colour()) << std::endl;
    // */
    auto s11 = fmt::format("{}w == {:|_{}.{}}{}\n", fg(fmt::color::green) | bg(fmt::color::brown) | fmt::emphasis::bold,
            w, 20, 20, fmtextras::reset_colour());
    std::cout << s11;

    return 0;
}

