#include "SanwuUMGExtenderPrivatePCH.h"
#include "SanwuUMGExtenderStyle.h"
#include "SAutoFolding.h"

void SAutoFolding::Construct(const FArguments& InArgs)
{
	const int32 NumSlots = InArgs.Slots.Num();
	contentMargin = InArgs._contentMargin.Get();
	for (int32 SlotIndex = 0; SlotIndex < NumSlots; ++SlotIndex)
	{
		Children.Add(InArgs.Slots[SlotIndex]);
	}
	//�жϳ�ʼ���Ƿ��������ӽڵ�
	if (this->NumSlots() > 0)
	{
		b_HaveChild = true;
	}
	InitFoldingTitle();
//	SAutoFolding::AddSlot().AttachWidget(SNew(SButton));
}

void SAutoFolding::InitFoldingTitle()
{
	TSharedRef<SHorizontalBox> Sp = SNew(SHorizontalBox);
	Sp->AddSlot()
		[
			SNew(SImage)
		//	._Image(FSanwuUMGExtenderStyle::Get().GetBrush("Widget.EmlargeIcon"))
		];
	SAutoFolding::AddSlot().AttachWidget(Sp);
}


void SAutoFolding::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	//���ﴦ����ӵ�content������߼������뷽ʽ����ʾ��ʽ
	areaSize = AllottedGeometry.GetLocalSize();
	
	float startX = contentMargin.Left;
	float startY = contentMargin.Top;
	for (int32 ChildIndex = 0; ChildIndex < Children.Num(); ++ChildIndex)
	{
		const SBoxPanel::FSlot& CurChild = Children[ChildIndex];
		const EVisibility ChildVisibility = CurChild.GetWidget()->GetVisibility();
		FVector2D size = CurChild.GetWidget()->GetDesiredSize();
		ArrangedChildren.AddWidget(ChildVisibility, AllottedGeometry.MakeChild(CurChild.GetWidget(), FVector2D(startX, startY), FVector2D(size.X, size.Y)));
	}
}

FVector2D SAutoFolding::ComputeDesiredSize(float) const
{
	return FVector2D(100, 50);
}

