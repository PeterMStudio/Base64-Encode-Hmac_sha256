
#pragma once

#include <string>
#include <cmath>
#include <cstdio>

#include "hmac_sha2.h"

class HMac{
public:
    //depend on hmac_sha.h hmac_sha.c sha2.c sha2.h
    static std::string cHMacSha256(const std::string &text, const std::string &key, bool showInfo = false);

    //depend on base64
    static std::string base64Encode(const std::string & src, bool showInfo = false);
};
