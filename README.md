This is my formatter class for the {fmt} library soon to be std::format
=======================================================================

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

style_spec             ::= '$' | ',' | '*'

spacing                ::= '_' | ';'

bracket                ::= '@' | '~'
```

where 

  - `$` means expresion style (i.e. **num** **plus_or_minus** **num**_i_).
  - `,` means pair style      (i.e. (**num**, **num**) ).
  - `*` means star style      (i.e. **num** **plus_or_minus** **num** _*i_ ), some people like this apperently.\
  - `_` space the `,` or `+` or `-`
  - `;` don't space `,` or `+` or `-`
  - `@` don't surround with brackets. 
  - `~` surround with brackets.

and **`format_spec_for_T`** the `format_specifier` for the type **T**.


To compile the the test program **testcmplx** just run 

```
$ g++ -std=c++20 -o testcmplx testcmplx.cpp -lfmt
```
where `$` is your prompt or use some sort of make/build system like cmake or what ever.
