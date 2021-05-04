This is my formatter class for the {fmt} library soon to be std::format
=======================================================================

- [Table of contents](#readme)
  * [Licence](#licence)
  * [Spec-Usage](#spec-usage)
  * [Example code](#example-code)



## Licence

I'm releasing this under the LGPL version 3 see the [LICENCE.md](LICENCE.md)  file, or [COPYING](COPYING) for plain text

## Spec-Usage 

For std::complex<T> then the format spec is as follows: 
```
replacement_field ::=  "{" [arg_id] [":" cmplx_format_spec] "}"
arg_id            ::=  integer | identifier
integer           ::=  digit+
digit             ::=  "0"..."9"
identifier        ::=  id_start id_continue*
id_start          ::=  "a"..."z" | "A"..."Z" | "_"
id_continue       ::=  id_start | digit
```

all standard except for `cmplx_format_spec` which is as follows

```
cmplx_format_spec     ::= cmplx_form [ format_spec_for_T ]

cmplx_form            ::= [ three_char_cmplx_spec ]

three_char_cmplx_spec ::= [ style_spec ] three_char_cmplx_spec
                          | [ spacing ]  three_char_cmplx_spec
                          | [ bracket ]  three_char_cmplx_spec

style_spec             ::= '$' | ',' | '*' | '|'

spacing                ::= '_' | ';'

bracket                ::= '@' | '~'
```

where 

  - `$` means expresion style (i.e. **num** **plus_or_minus** **num**_i_ ).
  - `,` means pair style      (i.e. (**num**, **num**) ).
      * **NB: this style overrides brackets i.e. `@` as no brackets makes no sense for this style**
  - `*` means star style      (i.e. **num** **plus_or_minus** **num** _*i_ ), some people like this apperently.
  - `|` means lisp style      (i.e. #C(**num**, **num**) ), this syle is used in common lisp.
      * **NB: this style overrides brackets i.e. `@` as no brackets makes no sense for this style**
  - `_` space the `,` or `+` or `-`
  - `;` don't space `,` or `+` or `-`
  - `@` don't surround with brackets. 
  - `~` surround with brackets.

and **`format_spec_for_T`** is the `format_specifier` for the type **T**.

**NB: I only accept 3 chars in the** _**three_char_cmplx_spec**_.

To compile the the test program **testcmplx** just run 

```
$ g++ -std=c++20 -o testcmplx testcmplx.cpp -lfmt
```

or
```
$ clang++ -std=c++20 -o testcmplx testcmplx.cpp -lfmt
```
where `$` is your prompt or use some sort of make/build system like cmake or what ever.

[Top](#readme)

## Example code

```
#include "complexfmt.h"
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
    std::cout << fmt::format("z == {0:,0.10} == {0:@0.10}\nz == {0:$@;0.10} == {0:,;0.10}\nz == {0:*;0.10} == {0}"s, z) << std::endl;
    std::cout << fmt::format("z == {:@*0^{}.{}f}", z, 25, 20) << std::endl;
    std::cout << fmt::format("z == {:@ >{}.{}f}", z, 25, 20) << std::endl;
    
    std::complex<double> w = 4.98 - 34.765i;
    std::cout << fmt::format("w == {:{}.{}}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {:@*0^{}.{}f}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {:@ >{}.{}f}", w, 25, 20) << std::endl;
    std::cout << fmt::format("w == {0:,0.10} == {0:@0.10}\nw == {0:$@;0.10} == {0:,;0.10}\nw == {0:*;0.10} == {0}"s, w) << std::endl;
    std::cout << fmt::format("z == {z:,{width}.{precis}}", "z"_a=z, "width"_a=25, "precis"_a=20) << std::endl;
    std::cout << fmt::format(fg(fmt::color::green) | bg(fmt::color::brown) | fmt::emphasis::bold,
            "w == {thecomplex:$_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    std::cout << fmt::format("w == {thecomplex:,_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    std::cout << fmt::format("w == {thecomplex:|_{width}.{precis}}", "thecomplex"_a=w, "width"_a=20, "precis"_a=20) << std::endl;
    fmt::print(fg(fmt::color::green) | bg(fmt::color::blue) | fmt::emphasis::bold,
            "z == {thecomplex:|_{width}.{precis}}\n", "thecomplex"_a=z, "width"_a=20, "precis"_a=20);
    std::cout << "w == {:|_{}.{}}"_format(w, 20, 20) << std::endl;

    return 0;
}
```

[Top](#readme)
