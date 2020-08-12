#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/Types.h>
namespace InspurCloud
{
namespace OSS
{
    class INSPURCLOUD_OSS_EXPORT Tag
    {
    public:
        Tag() {};
        Tag(const std::string& key, const std::string& value) :
            key_(key), value_(value) 
        {}
        void setKey(const std::string& key) { key_ = key; }
        void setValue(const std::string& value) { value_ = value; }
        const std::string& Key() const { return key_; }
        const std::string& Value() const { return value_; }
    private:
        std::string key_;
        std::string value_;
    };

    using TagSet = std::vector<Tag>;

    class INSPURCLOUD_OSS_EXPORT Tagging
    {
    public:
        Tagging() {};
        Tagging(const TagSet& tags) { tagSet_ = tags;}

        const TagSet& Tags() const { return tagSet_; }
        void setTags(const TagSet& tags) { tagSet_ = tags; }
        void setTags(TagSet&& tags) { tagSet_ = std::move(tags); }
        void addTag(const Tag& tag)  { tagSet_.push_back(tag) ; }
        void addTag(Tag&& tag) { tagSet_.push_back(std::move(tag)); }
        void clear() { tagSet_.clear();}
        std::string toQueryParameters();
    private:
        TagSet tagSet_;
    };
}
}
