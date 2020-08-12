
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
	enum CompressionType
	{
		NONE = 0,
		GZIP
	};

    enum CSVHeader
    {
        None = 0, // there is no csv header
        Ignore,   // we should ignore csv header and should not use csv header in select sql
        Use       // we can use csv header in select sql
    };

    enum JsonType
    {
        DOCUMENT = 0,
        LINES
    };

    class SelectObjectRequest;
    class CreateSelectObjectMetaRequest;

	class INSPURCLOUD_OSS_EXPORT InputFormat
	{
	public:
        void setCompressionType(CompressionType compressionType);

        void setLineRange(int64_t start, int64_t end);
        void setSplitRange(int64_t start, int64_t end);

		const std::string CompressionTypeInfo() const;

        

    protected:
        InputFormat();
        friend SelectObjectRequest;
        friend CreateSelectObjectMetaRequest;
        virtual int validate() const;
        virtual std::string toXML(int flag) const = 0;
        virtual std::string Type() const = 0;
        std::string RangeToString() const;
	private:
		CompressionType compressionType_;
        bool lineRangeIsSet_;
        int64_t lineRange_[2];
        bool splitRangeIsSet_;
        int64_t splitRange_[2];
	};

    class INSPURCLOUD_OSS_EXPORT CSVInputFormat : public InputFormat
    {
    public:
        CSVInputFormat();
        CSVInputFormat(CSVHeader headerInfo,
            const std::string& recordDelimiter,
            const std::string& fieldDelimiter,
            const std::string& quoteChar,
            const std::string& commentChar);

        void setHeaderInfo(CSVHeader headerInfo);
        void setRecordDelimiter(const std::string& recordDelimiter);
        void setFieldDelimiter(const std::string& fieldDelimiter);
        void setQuoteChar(const std::string& quoteChar);
        void setCommentChar(const std::string& commentChar);

        CSVHeader HeaderInfo() const;
        const std::string& RecordDelimiter() const;
        const std::string& FieldDelimiter() const;
        const std::string& QuoteChar() const;
        const std::string& CommentChar() const;

    protected:
        std::string Type() const;
        std::string toXML(int flag) const;
        
    private:
        CSVHeader headerInfo_;
        std::string recordDelimiter_;
        std::string fieldDelimiter_;
        std::string quoteChar_;
        std::string commentChar_;
    };

    class INSPURCLOUD_OSS_EXPORT JSONInputFormat : public InputFormat
    {
    public:
        JSONInputFormat();
        JSONInputFormat(JsonType jsonType);

        void setJsonType(JsonType jsonType);
        void setParseJsonNumberAsString(bool parseJsonNumberAsString);

        JsonType JsonInfo() const;
        bool ParseJsonNumberAsString() const;

    protected:
        std::string Type() const;
        std::string toXML(int flag) const;

    private:
        JsonType jsonType_;
        bool parseJsonNumberAsString_;
    };

}
}
