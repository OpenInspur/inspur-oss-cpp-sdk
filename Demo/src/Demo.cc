#include <inspurcloud/oss/OssClient.h>
#include <list>
#include <memory>
#include <fstream>
using namespace InspurCloud::OSS;


int main(void)
{
	/*初始化OSS账号信息*/
	/*std::string AccessKeyId = "LTAI4FjsuptZkC4h7X3Vp13S";
	std::string AccessKeySecret = "tvThQucHentwtyC21J26mAitqAhUqM";
	std::string Endpoint = "oss-cn-shanghai.aliyuncs.com";
	std::string BucketName = "tong-image3";*/

	std::string AccessKeyId = "inspur-zhangsm-oss";
	std::string AccessKeySecret = "inspur-zhangsm-oss";
	std::string Endpoint = "10.221.128.9";
	std::string BucketName = "sm-bucket00000";


	/*初始化网络等资源*/
	InitializeSdk();

	ClientConfiguration conf;
	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);

	/*指定新创建bucket的名称、存储类型和ACL*/
	CreateBucketRequest request(BucketName, StorageClass::IA, CannedAccessControlList::PublicReadWrite);
	/*设置同城冗余存储属性*/
	request.SetRegion("cn-north-3");
	//request.setDataRedundancyType(DataRedundancyType::ZRS);

	/*创建bucket*/
	auto outcome = client.CreateBucket(request);

	if (!outcome.isSuccess()) {
		/* 异常处理 */
		std::cout << "CreateBucket fail" <<
			",code:" << outcome.error().Code() <<
			",message:" << outcome.error().Message() <<
			",requestId:" << outcome.error().RequestId() << std::endl;
		ShutdownSdk();
		return -1;
	}

	/*释放网络等资源*/
	ShutdownSdk();
	return 0;
}