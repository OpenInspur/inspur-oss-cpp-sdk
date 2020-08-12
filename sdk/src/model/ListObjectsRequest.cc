
#include <inspurcloud/oss/model/ListObjectsRequest.h>
#include "../utils/Utils.h"

using namespace InspurCloud::OSS;

ParameterCollection ListObjectsRequest::specialParameters() const
{
    ParameterCollection params;
    if (delimiterIsSet_) params["delimiter"] = delimiter_;
    if (markerIsSet_) params["marker"] = marker_;
    if (maxKeysIsSet_) params["max-keys"] = std::to_string(maxKeys_);
    if (prefixIsSet_) params["prefix"] = prefix_;
    if (encodingTypeIsSet_) params["encoding-type"] = encodingType_;
    return params;
}

HeaderCollection ListObjectsRequest::specialHeaders() const
{
    HeaderCollection headers;
    if (requestPayer_ == RequestPayer::Requester) {
        headers["x-oss-request-payer"] = ToLower(ToRequestPayerName(RequestPayer::Requester));
    }
    return headers;
}
