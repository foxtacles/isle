#ifndef MXDSANIM_H
#define MXDSANIM_H

#include "mxdsmediaaction.h"

// VTABLE: LEGO1 0x100dcd88
// VTABLE: BETA10 0x101c2b20
// SIZE 0xb8
class MxDSAnim : public MxDSMediaAction {
public:
	MxDSAnim();
	MxDSAnim(MxDSAnim& p_dsAnim);
	~MxDSAnim() override;

	void CopyFrom(MxDSAnim& p_dsAnim);
	MxDSAnim& operator=(MxDSAnim& p_dsAnim);

	// FUNCTION: LEGO1 0x100c9060
	// FUNCTION: BETA10 0x1015d890
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x101025d8
		return "MxDSAnim";
	}

	// FUNCTION: LEGO1 0x100c9070
	// FUNCTION: BETA10 0x1015d8b0
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, MxDSAnim::ClassName()) || MxDSMediaAction::IsA(p_name);
	}

	MxDSAction* Clone() override; // vtable+0x2c

	// SYNTHETIC: LEGO1 0x100c9180
	// SYNTHETIC: BETA10 0x1015d910
	// MxDSAnim::`scalar deleting destructor'
};

#endif // MXDSANIM_H
