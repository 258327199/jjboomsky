#pragma once
#include "IHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HttpDownloadManager.generated.h"
/*
�����ļ�������
*/
using namespace UF;
using namespace UP;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDownloadFileDelegate, FString, DestinationPath, float, DownloadPercent);

UCLASS()
class UHttpDownloadManager : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="Sanwu", meta = (BlueprintInternalUseOnly = "true"))
	static UHttpDownloadManager* DownloadFile(FString url,FString FileName,FString Dirctory);

	UPROPERTY(BlueprintAssignable)
	FDownloadFileDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FDownloadFileDelegate OnFail;

	UPROPERTY(BlueprintAssignable)
	FDownloadFileDelegate OnProgress;

	UHttpDownloadManager* ParentDownloader;

private:

	void GetFileSize();

	FString url;//�������ص��ļ���URL��ַ
	FString fileName;//���浽���ص��ļ���
	FString DirctoryPath;//����·�����ļ��У�
	//**************Parent************
	int32 FileTotalSize = 0;//�ļ��ܴ�С
	TArray<FString>MissionPool;
	FString CurrentMisson;
	
	//**************Child**************
	void HandChildMissonComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	//HTTP������ɻ��ж�
	void HandleGetFileSize(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	//�ѽ��յ��Ķ��������ݱ��浽ָ�����ļ���
	void SaveByteToFile(FHttpRequestPtr HttpRequest, int32 UploadTotal, int32 DownloadTotal);
};