
#pragma once
#include <inspurcloud/oss/OssRequest.h>
#include <inspurcloud/oss/model/GetObjectRequest.h>
#include <inspurcloud/oss/Types.h>
#include <inspurcloud/oss/model/InputFormat.h>
#include <inspurcloud/oss/model/OutputFormat.h>
#include <inspurcloud/oss/model/CreateSelectObjectMetaRequest.h>

namespace InspurCloud
{
namespace OSS
{
	enum ExpressionType
	{
		SQL,
	};
    class OssClientImpl;
	class INSPURCLOUD_OSS_EXPORT SelectObjectRequest : public GetObjectRequest
	{
	public:
		SelectObjectRequest(const std::string& bucket, const std::string& key);

		void setExpression(const std::string& expression, ExpressionType type = SQL);
        void setSkippedRecords(bool skipPartialDataRecord, uint64_t maxSkippedRecords);
        void setInputFormat(InputFormat& inputFormat);
        void setOutputFormat(OutputFormat& OutputFormat);

        uint64_t MaxSkippedRecordsAllowed() const;
        void setResponseStreamFactory(const IOStreamFactory& factory);

	protected:
        friend class OssClientImpl;
		virtual std::string payload() const;
		virtual int validate() const;
        virtual ParameterCollection specialParameters() const;
        int dispose() const;
	private:
		ExpressionType expressionType_;
		std::string expression_;
		bool skipPartialDataRecord_;
		uint64_t maxSkippedRecordsAllowed_;
		InputFormat *inputFormat_;
		OutputFormat *outputFormat_;

        mutable std::shared_ptr<std::streambuf> streamBuffer_;
        mutable std::shared_ptr<std::iostream> upperContent_;
        IOStreamFactory upperResponseStreamFactory_;
	};

}
}