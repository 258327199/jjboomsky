#pragma once

#include "K2Node_LatentHttpHelperCall.generated.h"

//����������ѻ���HttpHelperCallProxyBase��������ĺ�����ʾ����ͼ��
UCLASS()
class SANWUUTILITESSUPPORT_API UK2Node_LatentHttpHelperCall : public UK2Node_BaseAsyncTask
{
	GENERATED_UCLASS_BODY()

	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
};