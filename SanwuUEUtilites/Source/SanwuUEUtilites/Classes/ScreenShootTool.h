#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScreenShootTool.generated.h"

/**
 * ����һ������ʵ����ͼ���ͼ���ܵ���չ
 *��ΪĿǰ��4.10��Ϊֹ����Ȼ��ʵ�ֽ�ͼ����ExecConsoleCommand�ڵ㡣 ���������ܻ�ȡ��ͼ�ķ���ֵ
 *���Ҳ����ֶ����ý�ͼ������
 *����д�˴˹���
 */
using namespace UF;

UCLASS()
class SANWUUEUTILITES_API UScreenShootTool : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	��ͼ������������
	*/
	UFUNCTION(BlueprintCallable, Category = "Sanwu|SanwuUEUtilites")
	static FString TakeScreenShoot(FString picName,bool bUnique=true);

	/**
	��ȡ��ͼĬ�ϱ����·��
	*/
	UFUNCTION(BlueprintCallable, Category = "Sanwu|SanwuUEUtilites")
	static FString GetBaseScreenShotPath();
};
