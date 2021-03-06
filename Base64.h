#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

namespace Base64
{
    std::string base64_encode(const std::string &);

    const std::string &SALT1 = "Pjpr<)h}exU>zQv cr}Fy72IujNiTXF1";
    const std::string &SALT2 = "vJWg(241K<'@F5<Q|#*#PS;a\:vzT<2z";
    const std::string &SALT3 = "ilgJx!4EAs}US}e(7t$>d@0M2R#b$WJi";

    std::string EncryptB64(std::string s)
    {
        s = SALT1 + s + SALT2 + SALT3;
        s = base64_encode(s);
        s.insert(7, SALT3);
        s += SALT1;
        s = base64_encode(s);
        s += SALT2 + SALT3 + SALT1;
        s = base64_encode(s);
        s.insert(1, "L");
        s.insert(7, "M");
        return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_encode(const std::string &s)
    {
        std::string ret;
        int val = 0;
        int bits = -6;
        const unsigned int b63 = 0x3F;

        // encode string
        for(const auto &c : s)
        {
            val = (val << 8) + c; // same as val = (val * 2^8) + c
            bits += 8;
            while(bits >= 0)
            {
                // & -> 101 & 011 = 001
                ret.push_back(BASE64_CODES[(val >> bits) & b63]);
                bits -= 6; // base64 groups by 6 bits
            }
        }

        // add padding (=)
        if (bits > -6)
            ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);
        while(ret.size()%4)
            ret.push_back('=');

        return ret;
    }
}

#endif // BASE_64
