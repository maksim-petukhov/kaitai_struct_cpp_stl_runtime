#ifdef GTEST_NANO
#include "tests/gtest-nano.h"
#else
#include <gtest/gtest.h>
#endif

#include "kaitai/kaitaistream.h"

TEST(KaitaiStreamTest, to_string)
{
    EXPECT_EQ(kaitai::kstream::to_string(123), "123");
    EXPECT_EQ(kaitai::kstream::to_string(-123), "-123");
}

TEST(KaitaiStreamTest, to_string_uint8)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint8_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint8_t>::max()), "255");
}

TEST(KaitaiStreamTest, to_string_int8)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int8_t>::min()), "-128");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int8_t>::max()), "127");
}

TEST(KaitaiStreamTest, to_string_uint16)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint16_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint16_t>::max()), "65535");
}

TEST(KaitaiStreamTest, to_string_int16)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int16_t>::min()), "-32768");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int16_t>::max()), "32767");
}

TEST(KaitaiStreamTest, to_string_uint32)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint32_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint32_t>::max()), "4294967295");
}

TEST(KaitaiStreamTest, to_string_int32)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int32_t>::min()), "-2147483648");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int32_t>::max()), "2147483647");
}

TEST(KaitaiStreamTest, to_string_uint64)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint64_t>::min()), "0");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<uint64_t>::max()), "18446744073709551615");
}

TEST(KaitaiStreamTest, to_string_int64)
{
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int64_t>::min()), "-9223372036854775808");
    EXPECT_EQ(kaitai::kstream::to_string(std::numeric_limits<int64_t>::max()), "9223372036854775807");
}

TEST(KaitaiStreamTest, string_to_int)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("123"), 123);
    EXPECT_EQ(kaitai::kstream::string_to_int("-123"), -123);
}

TEST(KaitaiStreamTest, string_to_int_uint8)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("0"), std::numeric_limits<uint8_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("255"), std::numeric_limits<uint8_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_int8)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("-128"), std::numeric_limits<int8_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("127"), std::numeric_limits<int8_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_uint16)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("0"), std::numeric_limits<uint16_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("65535"), std::numeric_limits<uint16_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_int16)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("-32768"), std::numeric_limits<int16_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("32767"), std::numeric_limits<int16_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_uint32)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("0"), std::numeric_limits<uint32_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("4294967295"), std::numeric_limits<uint32_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_int32)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("-2147483648"), std::numeric_limits<int32_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("2147483647"), std::numeric_limits<int32_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_int64)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("-9223372036854775808"), std::numeric_limits<int64_t>::min());
    EXPECT_EQ(kaitai::kstream::string_to_int("9223372036854775807"), std::numeric_limits<int64_t>::max());
}

TEST(KaitaiStreamTest, string_to_int_base13)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("0", 13), 0);
    EXPECT_EQ(kaitai::kstream::string_to_int("123", 13), 198);
    EXPECT_EQ(kaitai::kstream::string_to_int("-123", 13), -198);
    EXPECT_EQ(kaitai::kstream::string_to_int("4a7b9c", 13), 1788149);
}

TEST(KaitaiStreamTest, string_to_int_base8)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("0", 8), 0);
    EXPECT_EQ(kaitai::kstream::string_to_int("123", 8), 83);
    EXPECT_EQ(kaitai::kstream::string_to_int("-123", 8), -83);
    EXPECT_EQ(kaitai::kstream::string_to_int("777", 8), 511);
}

TEST(KaitaiStreamTest, string_to_int_base16)
{
    EXPECT_EQ(kaitai::kstream::string_to_int("0", 16), 0);
    EXPECT_EQ(kaitai::kstream::string_to_int("123", 16), 291);
    EXPECT_EQ(kaitai::kstream::string_to_int("-123", 16), -291);
    EXPECT_EQ(kaitai::kstream::string_to_int("4a7b9f", 16), 4881311);
}

TEST(KaitaiStreamTest, string_to_int_out_of_range)
{
    // 99999999999999999999999 = 0x152d_02c7_e14a_f67f_ffff =>
    // will need at least 77 bits to store, so should fail on 64-bit int
    try {
        kaitai::kstream::string_to_int("99999999999999999999999");
        FAIL() << "Expected out_of_range exception";
    } catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(), std::string("string_to_int"));
    }
}

TEST(KaitaiStreamTest, string_to_int_garbage)
{
    try {
        kaitai::kstream::string_to_int("123.^&@#!@");
        FAIL() << "Expected invalid_argument exception";
    } catch (std::invalid_argument& e) {
        EXPECT_EQ(e.what(), std::string("string_to_int"));
    }
}

TEST(KaitaiStreamTest, bytes_to_str_ascii)
{
    std::string res = kaitai::kstream::bytes_to_str("Hello, world!", "ASCII");
    EXPECT_EQ(res, "Hello, world!");
}

#ifndef KS_STR_ENCODING_NONE
TEST(KaitaiStreamTest, bytes_to_str_iso_8859_1)
{
    std::string res = kaitai::kstream::bytes_to_str("\xC4\xD6\xDC\xE4\xF6\xFC\xDF\xA6", "ISO-8859-1");
    EXPECT_EQ(res,
        "\xC3\x84"  // U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS
        "\xC3\x96"  // U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS
        "\xC3\x9C"  // U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS
        "\xC3\xA4"  // U+00E4 LATIN SMALL LETTER A WITH DIAERESIS
        "\xC3\xB6"  // U+00F6 LATIN SMALL LETTER O WITH DIAERESIS
        "\xC3\xBC"  // U+00FC LATIN SMALL LETTER U WITH DIAERESIS
        "\xC3\x9F"  // U+00DF LATIN SMALL LETTER SHARP S
        "\xC2\xA6"  // U+00A6 BROKEN BAR
    );
}

TEST(KaitaiStreamTest, bytes_to_str_iso_8859_15)
{
    std::string res = kaitai::kstream::bytes_to_str("\xC4\xD6\xDC\xE4\xF6\xFC\xDF\xA6", "ISO-8859-15");
    EXPECT_EQ(res,
        "\xC3\x84"  // U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS
        "\xC3\x96"  // U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS
        "\xC3\x9C"  // U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS
        "\xC3\xA4"  // U+00E4 LATIN SMALL LETTER A WITH DIAERESIS
        "\xC3\xB6"  // U+00F6 LATIN SMALL LETTER O WITH DIAERESIS
        "\xC3\xBC"  // U+00FC LATIN SMALL LETTER U WITH DIAERESIS
        "\xC3\x9F"  // U+00DF LATIN SMALL LETTER SHARP S
        "\xC5\xA0"  // U+0160 LATIN CAPITAL LETTER S WITH CARON
    );
}

TEST(KaitaiStreamTest, bytes_to_str_gb2312)
{
    std::string res = kaitai::kstream::bytes_to_str("\xC4\xE3\xBA\xC3\xCA\xC0\xBD\xE7", "GB2312");
    EXPECT_EQ(res,
        "\xE4\xBD\xA0"  // U+4F60 CJK UNIFIED IDEOGRAPH-4F60
        "\xE5\xA5\xBD"  // U+597D CJK UNIFIED IDEOGRAPH-597D
        "\xE4\xB8\x96"  // U+4E16 CJK UNIFIED IDEOGRAPH-4E16
        "\xE7\x95\x8C"  // U+754C CJK UNIFIED IDEOGRAPH-754C
    );
}

TEST(KaitaiStreamTest, bytes_to_str_ibm437)
{
    std::string res = kaitai::kstream::bytes_to_str("\xCC\xB2\x40", "IBM437");
    EXPECT_EQ(res,
        "\xE2\x95\xA0"  // U+2560 BOX DRAWINGS DOUBLE VERTICAL AND RIGHT
        "\xE2\x96\x93"  // U+2593 DARK SHADE
        "\x40"          // U+0040 COMMERCIAL AT
    );
}

TEST(KaitaiStreamTest, bytes_to_str_utf16le)
{
    // NB: UTF16 bytes representation will have binary zeroes in the middle, so we need to convert it to std::string with explicit length
    std::string res = kaitai::kstream::bytes_to_str(std::string("\x41\x00\x42\x00\x91\x25\x70\x24", 8), "UTF-16LE");
    EXPECT_EQ(res,
        "AB"
        "\xE2\x96\x91"  // U+2591 LIGHT SHADE
        "\xE2\x91\xB0"  // U+2470 CIRCLED NUMBER SEVENTEEN
    );
}

TEST(KaitaiStreamTest, bytes_to_str_utf16be)
{
    // NB: UTF16 bytes representation will have binary zeroes in the middle, so we need to convert it to std::string with explicit length
    std::string res = kaitai::kstream::bytes_to_str(std::string("\x00\x41\x00\x42\x25\x91\x24\x70", 8), "UTF-16BE");
    EXPECT_EQ(res,
        "AB"
        "\xE2\x96\x91"  // U+2591 LIGHT SHADE
        "\xE2\x91\xB0"  // U+2470 CIRCLED NUMBER SEVENTEEN
    );
}
#endif

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
