#include <inspurcloud/oss/OssClient.h>
#include <list>
#include <memory>
#include <fstream>
using namespace InspurCloud::OSS;


int main(void)
{
	/*��ʼ��OSS�˺���Ϣ*/
	/*std::string AccessKeyId = "LTAI4FjsuptZkC4h7X3Vp13S";
	std::string AccessKeySecret = "tvThQucHentwtyC21J26mAitqAhUqM";
	std::string Endpoint = "oss-cn-shanghai.aliyuncs.com";
	std::string BucketName = "tong-image3";*/

	std::string AccessKeyId = "inspur-zhangsm-oss";
	std::string AccessKeySecret = "inspur-zhangsm-oss";
	std::string Endpoint = "10.221.128.9";
	std::string BucketName = "sm-bucket00000";


	/*��ʼ���������Դ*/
	InitializeSdk();

	ClientConfiguration conf;
	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);

	/*ָ���´���bucket�����ơ��洢���ͺ�ACL*/
	CreateBucketRequest request(BucketName, StorageClass::IA, CannedAccessControlList::PublicReadWrite);
	/*����ͬ������洢����*/
	request.SetRegion("cn-north-3");
	//request.setDataRedundancyType(DataRedundancyType::ZRS);

	/*����bucket*/
	auto outcome = client.CreateBucket(request);

	if (!outcome.isSuccess()) {
		/* �쳣���� */
		std::cout << "CreateBucket fail" <<
			",code:" << outcome.error().Code() <<
			",message:" << outcome.error().Message() <<
			",requestId:" << outcome.error().RequestId() << std::endl;
		ShutdownSdk();
		return -1;
	}

	/*�ͷ��������Դ*/
	ShutdownSdk();
	return 0;
}