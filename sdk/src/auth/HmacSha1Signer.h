#pragma once

#include "Signer.h"


namespace InspurCloud
{
namespace OSS
{

    class  HmacSha1Signer : public Signer
    {
    public:
        HmacSha1Signer();
        ~HmacSha1Signer();
        
        virtual std::string generate(const std::string &src, const std::string &secret)const override;
    };
}
}
