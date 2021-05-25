
#include "hmac.h"


#include "hmac_sha2.h"
#include "base64.h"

#include <array>



std::string HMac::cHMacSha256(const std::string &text, const std::string &key, bool showInfo) {
    char buf[2];
    unsigned char mac[SHA256_DIGEST_SIZE];
    hmac_sha256((const unsigned char *)key.c_str(), key.length(), (const unsigned char *)text.c_str(),
                text.length(), mac, SHA256_DIGEST_SIZE);
    std::string val =  std::string{reinterpret_cast<char const*>(mac), 32};

    if(showInfo){
        printf("\n-----------------------Hash256-----------------------");
        printf("\n       Secret: %s",key.c_str());
        printf("\n      Message: %s",text.c_str());
        printf("\n  Result(Hex):");
        for(int i = 0; i < SHA256_DIGEST_SIZE; i++)
        {
            printf(" %.2x ", mac[i]);
        }
        printf("\nResult(String): %s",val.c_str());
        printf("\n***********************Hash256***********************\n");
    }

    return val;
}

std::string HMac::base64Encode(const std::string &src, bool showInfo ) {

    std::string ret = base64_encode(reinterpret_cast<const unsigned char*>(src.c_str()),src.length());
    if(showInfo){
        printf("\n-----------------------Base64-----------------------");
        printf("\nSrc: %s",src.c_str());
        printf("\nRet: %s",ret.c_str());
        printf("\n***********************Base64***********************\n");
    }

    return ret;
}
