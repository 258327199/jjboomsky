#pragma once
#include "IHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SanwuHttpDownloaderThread.h"
#include "SanwuHttpDownloadManager.generated.h"
/*
�����ļ�������
*/
class UHttpDownloader;

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
public:
	FString GetMissionURL();
	FString GetMissonContent();
	FString GetDestinationPath();
	void HandlePieceDownload(int32 DownloadedByte);
	float DownloadPercent;
	void HandMissionPartComplete();
	TArray<FString>MissionPool;//�����
private:

	void GetFileSize();

	FString url;//�������ص��ļ���URL��ַ
	FString fileName;//���浽���ص��ļ���
	FString DirctoryPath;//����·�����ļ��У�
	FString DestinationPath;//����·��
	//**************Parent************
	int32 FileTotalSize = 0;//�ļ��ܴ�С
	int32 FileDownloadedSize = 0;
	

	static UHttpDownloadManager* Manager;
	//HTTP������ɻ��ж�
	void HandleGetFileSize(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	void UpdateTimer();
	FTimerHandle TimerHandle;

	UWorld* GameWorld;
	FCriticalSection MissionPoolCriticalSection;
	int32 MissionPartNum;
	int32 MissionPartCompleteNum;
	
};