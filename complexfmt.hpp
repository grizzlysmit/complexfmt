/*
 * =====================================================================================
 *
 *       Filename:  complexfmt.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2021-03-18 13:17:09
 *       Revision:  2
 *       Compiler:  g++/clang++
 *
 *         Author:  Francis Grizzly Smit (FGJS), grizzly@smit.id.au
 *   Organization:  
 *
 * =====================================================================================
 */
#include <complex>
#include <fmt/format.h>

#ifndef COMPLEXFMT
#define COMPLEXFMT



template<typename T, typename Char>
    class fmt::formatter<std::complex<T>, Char> : public fmt::formatter<T, Char> {
        private:
            enum class style { expr, pair, star };
            style style_ = style::expr;
            bool bracket = true;
            bool spaced = true;
            using base = fmt::formatter<T, Char>;
            using Context_type = basic_format_parse_context<Char>;
        public:
            constexpr auto parse(Context_type& ctx) -> decltype(ctx.begin()) {
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
                auto format(const std::complex<T>& c, FormatContext& ctx){
                    auto out = ctx.out();
                    if(bracket){
                        out = format_to(out, "(");
                        ctx.advance_to(out);
                    }
                    out = base::format(c.real(), ctx);
                    T imag = c.imag();
                    char sep = '+';
                    char trail[3];
                    switch(style_){
                        case style::expr:
                            if(imag < 0){
                                sep = '-';
                                imag = -imag;
                            }
                            *trail = 'i';
                            *(trail + 1) = '\0';
                            break;
                        case style::star:
                            if(imag < 0){
                                sep = '-';
                                imag = -imag;
                            }
                            *trail = '*';
                            *(trail + 1) = 'i';
                            break;
                        case style::pair:
                            sep = ',';
                            *trail = '\0';
                            break;
                        default:
                            throw("How did I get here invalid style");
                    }
                    *(trail + 2) = '\0';
                    if(spaced){
                        if(style_ == style::pair){
                            out = format_to(out, "{} ", sep);
                        }else{
                            out = format_to(out, " {} ", sep);
                        }
                    }else{
                        out = format_to(out, "{}", sep);
                    }
                    ctx.advance_to(out);
                    out = base::format(imag, ctx);
                    out = format_to(out, trail);
                    if(bracket) return format_to(out, ")");
                    return format_to(out, "");
                }
    };
#endif // COMPLEXFMT
 
 

