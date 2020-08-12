
#pragma once
#include <inspurcloud/oss/Export.h>
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/Types.h>

namespace InspurCloud
{
namespace OSS
{
    class SelectObjectRequest;
	class INSPURCLOUD_OSS_EXPORT OutputFormat
	{
	public:
		void setKeepAllColumns(bool keepAllColumns);
		void setOutputRawData(bool outputRawData);
		void setEnablePayloadCrc(bool enablePayloadCrc);
		void setOutputHeader(bool outputHeader);

        bool OutputRawData() const;
        bool KeepAllColumns() const;
        bool EnablePayloadCrc() const;
        bool OutputHeader() const;
    protected:
        OutputFormat();
        friend SelectObjectRequest;
        virtual int validate() const;
        virtual std::string toXML() const = 0;
        virtual std::string Type() const = 0;
	private:
		bool keepAllColumns_;
		bool outputRawData_;
		bool enablePayloadCrc_;
		bool outputHeader_;
	};

    class INSPURCLOUD_OSS_EXPORT CSVOutputFormat : public OutputFormat
    {
    public:
        CSVOutputFormat();
        CSVOutputFormat(
            const std::string& recordDelimiter,
            const std::string& fieldDelimiter);

        void setRecordDelimiter(const std::string& recordDelimiter);
        void setFieldDelimiter(const std::string& fieldDelimiter);

        const std::string& RecordDelimiter() const;
        const std::string& FieldDelimiter() const;
    protected:
        virtual std::string toXML() const;
        virtual std::string Type() const;
    private:
        std::string recordDelimiter_;
        std::string fieldDelimiter_;
    };

    class INSPURCLOUD_OSS_EXPORT JSONOutputFormat : public OutputFormat
    {
    public:
        JSONOutputFormat();
        JSONOutputFormat(const std::string& recordDelimiter);

        void setRecordDelimiter(const std::string& recordDelimiter);
        const std::string& RecordDelimiter() const;
    protected:
        virtual std::string toXML() const;
        virtual std::string Type() const;
    private:
        std::string recordDelimiter_;
    };

}
}