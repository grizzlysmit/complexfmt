/*
 * =====================================================================================
 *
 *       Filename:  complexfmt.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021-03-18 13:17:09
 *       Revision:  3
 *       Compiler:  g++/clang++
 *
 *         Author:  Francis Grizzly Smit (FGJS), grizzly@smit.id.au
 *   Organization:  
 *
 * =====================================================================================
 */
#include <complex>
#include <fmt/format.h>

#ifndef FMTEXTRAS_COMPLEXFMT_H_
#define FMTEXTRAS_COMPLEXFMT_H_

FMT_BEGIN_NAMESPACE

template<typename T, typename Char>
    class formatter<std::complex<T>, Char> : public formatter<T, Char> {
        private:
            enum class style { expr, pair, star, lisp };
            style style_ = style::expr;
            bool bracket = true;
            bool spaced = true;
            using base = formatter<T, Char>;
            using Context_type = basic_format_parse_context<Char>;
        public:
            FMT_CONSTEXPR auto parse(Context_type& ctx) -> decltype(ctx.begin()) {
                auto it = ctx.begin(), end = ctx.end();
                bool done = false;
                if(it != end && *it == ':') ++it;
                for(int cnt = 0;it != end && cnt < 3; it++, cnt++){
                    switch(*it){
                        case '$':
                            style_ = style::expr;
                            break;
                        case ',':
                            style_ = style::pair;
                            break;
                        case '*':
                            style_ = style::star;
                            break;
                        case '|':
                            style_ = style::lisp;
                            break;
                        case '@':
                            bracket = false;
                            break;
                        case '~':
                            bracket = true;
                            break;
                        case ';':
                            spaced  = false;
                            break;
                        case '_':
                            spaced  = true;
                            break;
                        default:
                            done = true;
                    }
                    if(done) break;
                }
                ctx.advance_to(it);
                return base::parse(ctx);
            }
            template<typename FormatContext>
                FMT_CONSTEXPR auto format(const std::complex<T>& c, FormatContext& ctx) -> decltype(ctx.out()) {
                    auto out = ctx.out();
                    if(style_ == style::lisp){
                        out = format_to(out, "#C(");
                        ctx.advance_to(out);
                        bracket = true;
                    }else if(style_ == style::pair){
                        out = format_to(out, "(");
                        ctx.advance_to(out);
                        bracket = true;
                    }else if(bracket){
                        out = format_to(out, "(");
                        ctx.advance_to(out);
                    }
                    out = base::format(c.real(), ctx);
                    T imag = c.imag();
                    char sep[4], *sep_ptr = sep;
                    char tail[3], *tptr = tail;
                    switch(style_){
                        case style::expr:
                            if(imag < 0){
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                                *sep_ptr = '-';
                                sep_ptr++;
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                                imag = -imag;
                            }else{
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                                *sep_ptr = '+';
                                sep_ptr++;
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                            }
                            *tptr = 'i';
                            tptr++;
                            break;
                        case style::star:
                            if(imag < 0){
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                                *sep_ptr = '-';
                                sep_ptr++;
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                                imag = -imag;
                            }else{
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                                *sep_ptr = '+';
                                sep_ptr++;
                                if(spaced){
                                    *sep_ptr = ' ';
                                    sep_ptr++;
                                }
                            }
                            *tptr = '*';
                            tptr++;
                            *tptr = 'i';
                            tptr++;
                            break;
                        case style::pair:
                            *sep_ptr = ',';
                            sep_ptr++;
                            if(spaced){
                                *sep_ptr = ' ';
                                sep_ptr++;
                            }
                            //*tptr = '\0';
                            //tptr++;
                            break;
                        case style::lisp:
                            *sep_ptr = ',';
                            sep_ptr++;
                            if(spaced){
                                *sep_ptr = ' ';
                                sep_ptr++;
                            }
                            //*tptr = '\0';
                            //tptr++;
                            break;
                        default:
                            throw("How did I get here invalid style");
                    }
                    *sep_ptr = '\0';
                    *tptr = '\0';
                    out = format_to(out, sep);
                    ctx.advance_to(out);
                    out = base::format(imag, ctx);
                    out = format_to(out, tail);
                    if(bracket) return format_to(out, ")");
                    return out;
                }
    };

FMT_END_NAMESPACE
#endif // FMTEXTRAS_COMPLEXFMT_H_
 
 

