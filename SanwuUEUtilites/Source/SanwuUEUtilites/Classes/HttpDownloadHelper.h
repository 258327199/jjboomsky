#pragma once
#include "IHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HttpDownloadHelper.generated.h"
/*
�����ļ�������
*/
using namespace UF;
using namespace UP;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDownloadFileDelegate, FString, DestinationPath, float, DownloadPercent);

UCLASS()
class UHttpDownloadHelper : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Sanwu", meta = (BlueprintInternalUseOnly = "true"))
	static UHttpDownloadHelper* DownloadFile(FString url,FString FileName,FString Dirctory);

	void Start();

	UPROPERTY(BlueprintAssignable)
	FDownloadFileDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FDownloadFileDelegate OnFail;

	UPROPERTY(BlueprintAssignable)
	FDownloadFileDelegate OnProgress;
private:
	FString url;//�������ص��ļ���URL��ַ
	FString fileName;//���浽���ص��ļ���
	FString DirctoryPath;//����·�����ļ��У�

	int32 ByteDownloaded = 0;
	int32 ByteSaved = 0;
	

	//HTTP������ɻ��ж�
	void HandleFileRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	//������յ�Http���ص�����
	void HandleFileProgress(FHttpRequestPtr HttpRequest, int32 UploadTotal, int32 DownloadTotal);

	//�ѽ��յ��Ķ��������ݱ��浽ָ�����ļ���
	void SaveByteToFile(FHttpRequestPtr HttpRequest, int32 UploadTotal, int32 DownloadTotal);
};