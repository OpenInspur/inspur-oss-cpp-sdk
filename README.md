# 浪潮云OSS C++ SDK
浪潮云对象存储服务（Object Storage Service，简称 OSS）提供海量、安全、低成本、高可靠的云存储服务。   
   
OSS C++版SDK提供了OSS丰富的接口，可以轻松的进行Bucket、Object的相关操作。本文档帮助您快速的安装并使用OSS C++ SDK。   
如果在使用过程中遇到任何问题，欢迎通过当前Github提交issue。

# 前提
在使用OSS C++ SDK前请确保安装支持C++ 11或更高版本的编译器：   
+ Visual Studio 2013 或以上版本
+ 或 GCC 4.8 或以上版本
+ 或 Clang 3.3 或以上版本

# 安装

提供inspur-oss-cpp-sdk在Windows及Linux系统的安装例程。

## 一、Windows系统

1. 安装CMake。然后打开cmd进入SDK文件目录，创建build文件夹，运行cmake .. 生成所需文件。

2. 以管理员身份运行VS开发人员命令提示符，进入build目录文件，运行以下命令进行编译安装：

```sh
msbuild ALL_BUILD.vcxproj
msbuild INSTALL.vcxproj
```
或直接用Visual Studio打开，生成及决方案。

## 二、Linux系统

1. 安装第三方库libcurl、openssl:

RedHat/Centos操作系统：

```sh
yum –y install libcurl-devel openssl-devel
```

Debian/Ubuntu基操作系统：

```sh
apt-get install libcurl4-openssl-dev libssl-dev 
```

2. 安装CMake，请安装CMake3.1及以上版本。进入SDK安装包，通过CMake编译生成所需文件。编译命令如下：

```sh
cd <path/to/inspur-oss-cpp-sdk>
mkdir build
cd build
cmake ..
```

3. 安装SDK

```sh
make && make install
```

# 使用例程

以下代码通过列举Bucket中所有Object为例，展示本SDK的使用。

```c++
#include <inspurcloud/oss/OssClient.h>
using namespace InspurCloud::OSS;
int main(void)
{
	//指定Bucket和账户信息
	std::string AccessKeyId = "AccessKeyId";
	std::string AccessKeySecret = "AccessKeySecret";
	std::string Endpoint = "Endpoint";
	std::string BucketName = "BucketName";

	//初始化资源
	InitializeSdk();
	ClientConfiguration conf;
	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);

	//列举文件
	ListObjectsRequest request(BucketName);
	auto outcome = client.ListObjects(request);

	//处理结果
	if (outcome.isSuccess()) {
		for (const auto& object : outcome.result().ObjectSummarys()) {
			std::cout << "object name：" << object.Key() <<",size:" << object.Size() <<
			",lastmodify time:" << object.LastModified() << std::endl;
		}
	}
	//异常处理
	else {
		std::cout << "ListObjects fail" << std::endl;
		std::cout << "error code:" << outcome.error().Code() << std::endl;
		std::cout << "error message:" << outcome.error().Message() << std::endl;
		std::cout << "requestId:" << outcome.error().RequestId() << std::endl;
		ShutdownSdk();
		return -1;
	}

	//释放资源
	ShutdownSdk();
}
```
关于Bucket、Object等的更多使用例程，详见[对象存储帮助文档](https://console1.cloud.inspur.com/document/oss/5-API/5.4-service/01-get-service.html)
中SDK使用中C++部分。