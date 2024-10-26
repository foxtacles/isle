#ifndef PIZZA_H
#define PIZZA_H

#include "actionsfwd.h"
#include "decomp.h"
#include "isleactor.h"
#include "legostate.h"

class Act1State;
class PizzeriaState;
class SkateBoard;

// VTABLE: LEGO1 0x100d7408
// SIZE 0xb4
class PizzaMissionState : public LegoState {
public:
	// SIZE 0x20
	struct Mission {
	public:
		MxResult WriteToFile(LegoFile* p_file)
		{
			Write(p_file, m_unk0x06);
			Write(p_file, m_unk0x14);
			Write(p_file, m_unk0x16);
			Write(p_file, m_score);
			return SUCCESS;
		}

		MxResult ReadFromFile(LegoFile* p_file)
		{
			Read(p_file, &m_unk0x06);
			Read(p_file, &m_unk0x14);
			Read(p_file, &m_unk0x16);
			Read(p_file, &m_score);
			return SUCCESS;
		}

		MxS16 m_numActions;            // 0x00
		MxU8 m_id;                     // 0x02
		undefined m_unk0x03[3];        // 0x03
		MxS16 m_unk0x06;               // 0x06
		undefined m_unk0x08[8];        // 0x08
		MxLong m_startTime;            // 0x10
		MxS16 m_unk0x14;               // 0x14
		MxS16 m_unk0x16;               // 0x16
		MxS16 m_score;                 // 0x18
		IsleScript::Script* m_actions; // 0x1c
	};

	PizzaMissionState();

	// FUNCTION: LEGO1 0x10039290
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x100f00d4
		return "PizzaMissionState";
	}

	// FUNCTION: LEGO1 0x100392a0
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, PizzaMissionState::ClassName()) || LegoState::IsA(p_name);
	}

	MxResult Serialize(LegoFile* p_file) override; // vtable+0x1c

	MxS16 GetHighScore(MxU8 p_id) { return GetState(p_id)->m_score; }

	// SYNTHETIC: LEGO1 0x10039350
	// PizzaMissionState::`scalar deleting destructor'

	Mission* GetState(MxU8 p_id);
	MxS16 FUN_10039540();

	PizzeriaState* m_pizzeriaState; // 0x08
	undefined4 m_unk0x0c;           // 0x0c
	Mission m_state[5];             // 0x10
	undefined4 m_unk0xb0;           // 0xb0
};

// VTABLE: LEGO1 0x100d7380
// SIZE 0x9c
class Pizza : public IsleActor {
public:
	Pizza();
	~Pizza() override;

	MxResult Tickle() override; // vtable+0x08

	// FUNCTION: LEGO1 0x10037f90
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x100f038c
		return "Pizza";
	}

	// FUNCTION: LEGO1 0x10037fa0
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, Pizza::ClassName()) || IsleActor::IsA(p_name);
	}

	MxResult Create(MxDSAction& p_dsAction) override;                   // vtable+0x18
	MxLong HandleClick() override;                                      // vtable+0x68
	MxLong HandleEndAction(MxEndActionNotificationParam&) override;     // vtable+0x74
	MxLong HandlePathStruct(LegoPathStructNotificationParam&) override; // vtable+0x80

	void CreateState();
	void FUN_10038220(MxU32 p_objectId);
	void FUN_100382b0();
	void StopActions();
	void FUN_10038fe0(MxU32 p_objectId, MxBool);

	void SetSkateboard(SkateBoard* p_skateBoard) { m_skateBoard = p_skateBoard; }

	// SYNTHETIC: LEGO1 0x100380e0
	// Pizza::`scalar deleting destructor'

private:
	PizzaMissionState* m_state;            // 0x7c
	PizzaMissionState::Mission* m_mission; // 0x80
	SkateBoard* m_skateBoard;              // 0x84
	Act1State* m_act1state;                // 0x88
	undefined4 m_unk0x8c;                  // 0x8c
	undefined4 m_unk0x90;                  // 0x90
	undefined4 m_unk0x94;                  // 0x94
	undefined m_unk0x98;                   // 0x98
};

#endif // PIZZA_H
