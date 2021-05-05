/*
 * =====================================================================================
 *
 *       Filename:  colourfmt.h
 *
 *    Description: a {fmt} formatter to do expand colour  handling in {fmt}  
 *
 *        Version:  1.0
 *        Created:  2021-05-05 07:30:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francis Grizzly Smit (FGJS), grizzly@smit.id.au
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>

#ifndef FMTEXTRAS_COLOURFMT_H_
#define FMTEXTRAS_COLOURFMT_H_

FMT_BEGIN_NAMESPACE

template<typename Char>
    class formatter<text_style, Char> {
        private:
            using Context_type = basic_format_parse_context<Char>;
        public:
            constexpr auto parse(Context_type& ctx) -> decltype(ctx.begin()) {
                auto it = ctx.begin(), end = ctx.end();
                if(it != end && *it == ':') ++it;
                while(it != end && *it != '}') ++it;
                return it;
            }
            template<typename FormatContext>
                constexpr auto format(const text_style& ts, FormatContext& ctx) -> decltype(ctx.out()) {
                    auto out = ctx.out();
                    basic_memory_buffer<Char> buf;
                    if (ts.has_emphasis()) {
                        auto emphasis = detail::make_emphasis<Char>(ts.get_emphasis());
                        buf.append(emphasis.begin(), emphasis.end());
                    }
                    if (ts.has_foreground()) {
                        auto foreground = detail::make_foreground_color<Char>(ts.get_foreground());
                        buf.append(foreground.begin(), foreground.end());
                    }
                    if (ts.has_background()) {
                        auto background = detail::make_background_color<Char>(ts.get_background());
                        buf.append(background.begin(), background.end());
                    }
                    buf.push_back('\0');
                    out = fmt::format_to(out, buf.data());
                    return out;
                }
    };

FMT_END_NAMESPACE

namespace fmtextras {

struct reset_colour {
    /*
    private:
        bool doit = false;
    public:
        reset_colour() : doit(true) {};
        constexpr operator bool(){
            return doit;
        }
        // */
};

using reset_color = reset_colour;

} // namespace fmtextras //

FMT_BEGIN_NAMESPACE

template<typename Char>
    class formatter<fmtextras::reset_colour, Char> {
        private:
            using Context_type = basic_format_parse_context<Char>;
        public:
            constexpr auto parse(Context_type& ctx) -> decltype(ctx.begin()) {
                auto it = ctx.begin(), end = ctx.end();
                if(it != end && *it == ':') ++it;
                while(it != end && *it != '}') ++it;
                return it;
            }
            template<typename FormatContext>
                constexpr auto format(const fmtextras::reset_colour& rc, FormatContext& ctx) -> decltype(ctx.out()) {
                    auto out = ctx.out();
                    out = format_to(out, "\x1b[0m");
                    return out;
                }
    };

FMT_END_NAMESPACE
#endif // FMTEXTRAS_COLOURFMT_H_
