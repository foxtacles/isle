#ifndef MXCOMPOSITEMEDIAPRESENTER_H
#define MXCOMPOSITEMEDIAPRESENTER_H

#include "mxcompositepresenter.h"

// VTABLE: LEGO1 0x100d96b0
// VTABLE: BETA10 0x101bf540
// SIZE 0x50
class MxCompositeMediaPresenter : public MxCompositePresenter {
public:
	MxCompositeMediaPresenter();
	~MxCompositeMediaPresenter() override;

	MxResult Tickle() override; // vtable+0x08

	// FUNCTION: LEGO1 0x10073f10
	// FUNCTION: BETA10 0x100ea920
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x100f02d4
		return "MxCompositeMediaPresenter";
	}

	// FUNCTION: LEGO1 0x10073f20
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, MxCompositeMediaPresenter::ClassName()) || MxCompositePresenter::IsA(p_name);
	}

	void StartingTickle() override;                                           // vtable+0x1c
	MxResult StartAction(MxStreamController*, MxDSAction* p_action) override; // vtable+0x3c
	MxResult PutData() override;                                              // vtable+0x4c

private:
	MxS16 m_unk0x4c;  // 0x4c
	MxBool m_unk0x4e; // 0x4e
};

// SYNTHETIC: LEGO1 0x10074000
// MxCompositeMediaPresenter::`scalar deleting destructor'

#endif // MXCOMPOSITEMEDIAPRESENTER_H
