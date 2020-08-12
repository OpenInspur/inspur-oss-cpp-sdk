
#include <inspurcloud/oss/model/ListBucketsResult.h>
#include <tinyxml2/tinyxml2.h>
#include <inspurcloud/oss/model/Bucket.h>
#include <inspurcloud/oss/model/Owner.h>
#include "../utils/Utils.h"
using namespace InspurCloud::OSS;
using namespace tinyxml2;

ListBucketsResult::ListBucketsResult():
    OssResult(),
    prefix_(),
    marker_(),
    nextMarker_(),
    isTruncated_(false),
    maxKeys_()
{
}

ListBucketsResult::ListBucketsResult(const std::string& result):
    ListBucketsResult()
{
    *this = result;
}

ListBucketsResult::ListBucketsResult(const std::shared_ptr<std::iostream>& result):
    ListBucketsResult()
{
    std::istreambuf_iterator<char> isb(*result.get()), end;
    std::string str(isb, end);
    *this = str;
}

ListBucketsResult& ListBucketsResult::operator =(const std::string& result)
{
    XMLDocument doc;
    XMLError xml_err;
    if ((xml_err = doc.Parse(result.c_str(), result.size())) == XML_SUCCESS) {
        XMLElement* root =doc.RootElement();
        if (root && !std::strncmp("ListAllMyBucketsResult", root->Name(), 22)) {
            XMLElement *node;
            node = root->FirstChildElement("Prefix");
            if (node && node->GetText()) prefix_ = node->GetText();

            node = root->FirstChildElement("Marker");
            if (node && node->GetText()) marker_ = node->GetText();

            node = root->FirstChildElement("MaxKeys");
            if (node && node->GetText()) maxKeys_ = atoi(node->GetText());

            node = root->FirstChildElement("IsTruncated");
            if (node && node->GetText()) isTruncated_ = !std::strncmp("true", node->GetText(), 4);

            node = root->FirstChildElement("NextMarker");
            if (node && node->GetText()) nextMarker_ = node->GetText();

            node = root->FirstChildElement("Owner");
            std::string owner_ID, owner_DisplayName;
            if (node) {
                XMLElement *sub_node;
                sub_node = node->FirstChildElement("ID");
                if (sub_node && sub_node->GetText()) owner_ID = sub_node->GetText();

                sub_node = node->FirstChildElement("DisplayName");
                if (sub_node && sub_node->GetText()) owner_DisplayName = sub_node->GetText();
            }

            Owner owner(owner_ID, owner_DisplayName);
            //buckets
            node = root->FirstChildElement("Buckets");
            if (node) {
                XMLElement *bucket_node = node->FirstChildElement("Bucket");
                for (; bucket_node; bucket_node = bucket_node->NextSiblingElement()) {
                    Bucket bucket;
                    XMLElement *node;
                    node = bucket_node->FirstChildElement("CreationDate");
                    if (node && node->GetText()) bucket.creationDate_ = node->GetText();

                    node = bucket_node->FirstChildElement("ExtranetEndpoint");
                    if (node && node->GetText()) bucket.extranetEndpoint_ = node->GetText();

                    node = bucket_node->FirstChildElement("IntranetEndpoint");
                    if (node && node->GetText()) bucket.intranetEndpoint_ = node->GetText();

                    node = bucket_node->FirstChildElement("Location");
                    if (node && node->GetText()) bucket.location_ = node->GetText();

                    node = bucket_node->FirstChildElement("Name");
                    if (node && node->GetText()) bucket.name_ = node->GetText();

                    node = bucket_node->FirstChildElement("StorageClass");
                    if (node && node->GetText()) bucket.storageClass_ = ToStorageClassType(node->GetText());

                    bucket.owner_ = owner;
                    buckets_.push_back(bucket);
                }
            }
        }

        //TODO check the result and the parse flag;
        parseDone_ = true;
    }
    return *this;
}

