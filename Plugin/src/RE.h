#pragma once

#include "sfse_common/Utilities.h"

namespace RE
{
	class TESForm;
	class BGSLocation;
	class BGSScene;
	class NiAVObject;
	class TESFile;
	class TESTopicInfo;
	class TESRace;
	class TESObjectCELL;
	class CombatGroup;
	class TESBoundObject;
	class TESObjectREFR;
	class BGSKeyword;
	class NiNode;

	class NiPoint3
	{
	public:
		float x;
		float y;
		float z;
	};
	static_assert(sizeof(NiPoint3) == 0xC);

	class alignas(0x10) NiPoint3A :
		public NiPoint3
	{
	public:
	};
	static_assert(sizeof(NiPoint3A) == 0x10);

	class BaseFormComponent
	{
	public:
		virtual ~BaseFormComponent();  // 00

		// add
		virtual void InitializeDataComponent();                // 01
		virtual void ClearDataComponent();                     // 02
		virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03 - { return; }
		virtual void Unk_04();                                 // 04
		virtual void Unk_05();                                 // 05
		virtual void Unk_06();                                 // 06
		virtual void Unk_07();                                 // 07
	};

	struct TESFormRefCount
	{
	public:
		// members
		volatile std::uint64_t refCount;  // 00
	};

	namespace BSReflection
	{
		class IObject
		{
		public:
			virtual void Unk_00();  // 00

			virtual ~IObject();  // 01
		};
	}

	struct ACTIVATE_DATA
	{
		TESObjectREFR* activatedRef;
		TESObjectREFR* actionRef;
		TESForm*       objectToGet;
		std::int32_t   count;
		bool           unk1C;
	};

	class TESForm : public BaseFormComponent, public TESFormRefCount, public BSReflection::IObject
	{
	public:
		virtual ~TESForm();  // 00

		// add
		virtual void          Unk_08();                                                         // 08
		virtual void          Unk_09();                                                         // 09
		virtual void          Unk_0A();                                                         // 0A
		virtual void          Unk_0B();                                                         // 0B
		virtual void          Unk_0C();                                                         // 0C
		virtual void          Unk_0D();                                                         // 0D
		virtual void          Unk_0E();                                                         // 0E
		virtual void          Unk_0F();                                                         // 0F
		virtual void          Unk_10();                                                         // 10
		virtual void          Unk_11();                                                         // 11
		virtual void          Unk_12();                                                         // 12
		virtual void          Unk_13();                                                         // 13
		virtual void          Unk_14();                                                         // 14
		virtual void          Unk_15();                                                         // 15
		virtual void          Unk_16();                                                         // 16
		virtual bool          AddChange(std::uint32_t a_changeFlags);                           // 17
		virtual void          RemoveChange(std::uint32_t a_changeFlags);                        // 18
		virtual void          Unk_19();                                                         // 19
		virtual void          Unk_1A();                                                         // 1A
		virtual void          Unk_1B();                                                         // 1B
		virtual void          Unk_1C();                                                         // 1C
		virtual void          Unk_1D();                                                         // 1D
		virtual void          Unk_1E();                                                         // 1E
		virtual void          InitItemImpl();                                                   // 1F
		virtual TESFile*      GetRevertFile() const;                                            // 20
		virtual TESFile*      GetDescriptionOwnerFile() const;                                  // 21
		virtual std::uint8_t  GetSavedFormType();                                               // 22
		virtual void          GetFormDetailedString(char* a_dest, std::uint32_t a_size) const;  // 23
		virtual bool          GetKnown() const;                                                 // 24
		virtual bool          GetRandomAnim() const;                                            // 25
		virtual bool          GetPlayable() const;                                              // 26
		virtual void          SetPlayable(bool a_set);                                          // 27
		virtual void          Unk_28();                                                         // 28
		virtual void          Unk_29();                                                         // 29
		virtual bool          GetDangerous() const;                                             // 2A
		virtual bool          QHasCurrents() const;                                             // 2B
		virtual bool          GetObstacle() const;                                              // 2C
		virtual void          Unk_2D();                                                         // 2D
		virtual bool          GetOnLocalMap() const;                                            // 2E
		virtual bool          GetMustUpdate() const;                                            // 2F
		virtual void          SetOnLocalMap(bool a_val);                                        // 30
		virtual void          Unk_31();                                                         // 31 - new?
		virtual void          Unk_32();                                                         // 32 - GetIgnoredBySandbox()?
		virtual void          SetDelete(bool a_deleted);                                        // 33
		virtual void          SetAltered(bool a_altered);                                       // 34
		virtual void          Unk_35();                                                         // 35
		virtual void          Unk_36();                                                         // 36
		virtual void          Unk_37();                                                         // 37
		virtual void          Unk_38();                                                         // 38
		virtual void          Unk_39();                                                         // 39
		virtual void          Unk_3A();                                                         // 3A
		virtual void          Unk_3B();                                                         // 3B
		virtual void          Unk_3C();                                                         // 3C
		virtual void          Unk_3D();                                                         // 3D
		virtual void          Unk_3E();                                                         // 3E
		virtual void          Unk_3F();                                                         // 3F
		virtual bool          IsFurniture();                                                    // 40 - new
		virtual void          Unk_41();                                                         // 41
		virtual void          Unk_42();                                                         // 42
		virtual void          Unk_43();                                                         // 43
		virtual void          Unk_44();                                                         // 44
		virtual void          Unk_45();                                                         // 45
		virtual void          Unk_46();                                                         // 46
		virtual void          Unk_47();                                                         // 47
		virtual void          Unk_48();                                                         // 48
		virtual void          Unk_49();                                                         // 49
		virtual void          Unk_4A();                                                         // 4A
		virtual void          Unk_4B();                                                         // 4B
		virtual std::uint32_t GetFullNameLength() const;                                        // 4C - new
		virtual const char*   GetFullName() const;                                              // 4D - new
		virtual void          Unk_4E();                                                         // 4E
		virtual void          Unk_4F();                                                         // 4F
		virtual void          Unk_50();                                                         // 50
		virtual void          Unk_51();                                                         // 51
		virtual void          Unk_52();                                                         // 52
		virtual void          Unk_53();                                                         // 53
		virtual bool          Activate(const ACTIVATE_DATA& a_activateData);                    // 54
		virtual void          Unk_55();                                                         // 55
		virtual void          Unk_56();                                                         // 56
		virtual void          Unk_57();                                                         // 57
		virtual void          Unk_58();                                                         // 58
		virtual void          Unk_59();                                                         // 59
		virtual void          Unk_5A();                                                         // 5A
		virtual void          Unk_5B();                                                         // 5B
		virtual void          Unk_5C();                                                         // 5C
		virtual std::uint32_t GetFilledSlots() const;                                           // 5D
		virtual std::uint32_t GetFilledSlotsImpl() const;                                       // 5E
		virtual float         GetDesirability() const;                                          // 5F
		virtual void          Unk_60();                                                         // 60
		virtual void          Unk_61();                                                         // 61

		// members
		std::uint64_t sourceFiles;  // 18 - TESFileContainer
		std::uint32_t unk20;        // 20
		std::uint32_t unk24;        // 24
		std::uint32_t formFlags;    // 28
		std::uint32_t unk2C;        // 2C
		std::uint32_t formID;       // 30
		std::uint8_t  unk34;        // 34 - also flag
		std::uint8_t  unk35;        // 35
		std::uint8_t  formType;     // 36
	};
	static_assert(sizeof(TESForm) == 0x38);

	// more than a simple edid
	// has a destroy event??
	class BGSKeyword : public TESForm
	{
	public:
		//...
	};

	struct OBJ_REFR
	{
	public:
		// members
		NiPoint3A angle;            // 00
		NiPoint3A location;         // 10
		TESForm*  objectReference;  // 20 - TESBoundObject
	};
	static_assert(sizeof(OBJ_REFR) == 0x30);

	// TESHandleForm inherits from TESForm and doesn't seem to have any additional stuff
	class TESObjectREFR : public TESForm
	{
	public:
		~TESObjectREFR() override;  // 00

		// add
		virtual void         Predestroy();                                                                                                                      // 062
		virtual bool         Unk_63();                                                                                                                          // 063 - { return extraList.HasExtraData(14);};
		virtual bool         GetEditorLocation(NiPoint3& a_originalLocation, NiPoint3& a_originalAngle, TESForm*& a_locationFormOut);                           // 064 - new
		virtual void         Unk_65();                                                                                                                          // 065
		virtual BGSLocation* GetEditorLocation() const;                                                                                                         // 066
		virtual bool         GetEditorLocation(NiPoint3& a_originalLocation, NiPoint3& a_originalAngle, TESForm*& a_locationFormOut, TESForm* a_locationForm);  // 067
		virtual bool         IsTalking() const;                                                                                                                 // 068
		virtual void         ForceEditorLocation(BGSLocation* a_location);                                                                                      // 069
		virtual void         Unk_6A();                                                                                                                          // 06A
		virtual void         UpdateSoundCallBack(bool a_endSceneAction);                                                                                        // 06B
		virtual bool         SetDialoguewithPlayer(bool a_flag, bool a_forceGreet, TESTopicInfo* a_topicInfo);                                                  // 06C
		virtual void         Unk_6D();                                                                                                                          // 06D
		virtual void         Unk_6E();                                                                                                                          // 06E
		virtual void         Unk_6F();                                                                                                                          // 06F
		virtual void         Unk_70();                                                                                                                          // 070
		virtual void         Unk_71();                                                                                                                          // 071
		virtual void         Unk_72();                                                                                                                          // 072
		virtual void         Unk_73();                                                                                                                          // 073
		virtual void         Unk_74();                                                                                                                          // 074
		virtual void         Unk_75();                                                                                                                          // 075
		virtual void         Unk_76();                                                                                                                          // 076
		virtual void         Unk_77();                                                                                                                          // 077
		virtual void         Unk_78();                                                                                                                          // 078
		virtual void         Unk_79();                                                                                                                          // 079
		virtual BGSScene*    GetCurrentScene() const;                                                                                                           // 07A
		virtual void         Unk_7B();                                                                                                                          // 07B
		virtual void         Unk_7C();                                                                                                                          // 07C
		virtual void         Unk_7D();                                                                                                                          // 07D
		virtual void         Unk_7E();                                                                                                                          // 07E
		virtual void         Unk_7F();                                                                                                                          // 07F
		virtual void         Unk_80();                                                                                                                          // 080
		virtual void         Unk_81();                                                                                                                          // 081
		virtual void         Unk_82();                                                                                                                          // 082
		virtual void         Unk_83();                                                                                                                          // 083
		virtual void         Unk_84();                                                                                                                          // 084
		virtual void         Unk_85();                                                                                                                          // 085
		virtual void         Unk_86();                                                                                                                          // 086
		virtual void         Unk_87();                                                                                                                          // 087
		virtual void         Unk_88();                                                                                                                          // 088
		virtual void         Unk_89();                                                                                                                          // 089
		virtual void         Unk_8A();                                                                                                                          // 08A
		virtual void         Unk_8B();                                                                                                                          // 08B
		virtual void         Unk_8C();                                                                                                                          // 08C
		virtual void         Unk_8D();                                                                                                                          // 08D
		virtual void         Unk_8E();                                                                                                                          // 08E
		virtual void         Unk_8F();                                                                                                                          // 08F
		virtual void         Unk_90();                                                                                                                          // 090
		virtual void         Unk_91();                                                                                                                          // 091
		virtual void         Unk_92();                                                                                                                          // 092
		virtual void         Unk_93();                                                                                                                          // 093
		virtual void         Unk_94();                                                                                                                          // 094
		virtual void         Unk_95();                                                                                                                          // 095
		virtual void         Unk_96();                                                                                                                          // 096
		virtual void         Unk_97();                                                                                                                          // 097
		virtual float        GetGravityScale();                                                                                                                 // 098 - new
		virtual void         Unk_99();                                                                                                                          // 099
		virtual void         Unk_9A();                                                                                                                          // 09A
		virtual void         Unk_9B();                                                                                                                          // 09B
		virtual void         Unk_9C();                                                                                                                          // 09C
		virtual void         Unk_9D();                                                                                                                          // 09D
		virtual void         Unk_9E();                                                                                                                          // 09E
		virtual bool         IsChild() const;                                                                                                                   // 09F
		virtual void         Unk_A0();                                                                                                                          // 0A0
		virtual void         Unk_A1();                                                                                                                          // 0A1
		virtual void         Unk_A2();                                                                                                                          // 0A2
		virtual void         Unk_A3();                                                                                                                          // 0A3
		virtual void         Unk_A4();                                                                                                                          // 0A4
		virtual void         Unk_A5();                                                                                                                          // 0A5
		virtual void         Unk_A6();                                                                                                                          // 0A6
		virtual void         Unk_A7();                                                                                                                          // 0A7
		virtual void         Unk_A8();                                                                                                                          // 0A8
		virtual void         Unk_A9();                                                                                                                          // 0A9
		virtual void         Unk_AA();                                                                                                                          // 0AA
		virtual void         Unk_AB();                                                                                                                          // 0AB - { return Get3D(a_objectOut) };?
		virtual void         Unk_AC();                                                                                                                          // 0AC - Get3D(NiPointer<NiAVObject>&)?
		virtual void         Unk_AD();                                                                                                                          // 0AD
		virtual void         Unk_AE();                                                                                                                          // 0AE
		virtual void         Unk_AF();                                                                                                                          // 0AF
		virtual TESRace*     GetVisualsRace() const;                                                                                                            // 0B0
		virtual void         Unk_B1();                                                                                                                          // 0B1
		virtual void         Unk_B2();                                                                                                                          // 0B2
		virtual void         Unk_B3();                                                                                                                          // 0B3
		virtual NiPoint3     GetBoundMin() const;                                                                                                               // 0B4
		virtual NiPoint3     GetBoundMax() const;                                                                                                               // 0B5
		virtual void         Unk_B6();                                                                                                                          // 0B6
		virtual void         Unk_B7();                                                                                                                          // 0B7
		virtual void         Unk_B8();                                                                                                                          // 0B8
		virtual void         Unk_B9();                                                                                                                          // 0B9
		virtual void         Unk_BA();                                                                                                                          // 0BA
		virtual void         Unk_BB();                                                                                                                          // 0BB
		virtual void         Unk_BC();                                                                                                                          // 0BC
		virtual void         Unk_BD();                                                                                                                          // 0BD
		virtual void         Unk_BE();                                                                                                                          // 0BE
		virtual void         Unk_BF();                                                                                                                          // 0BF
		virtual void         Unk_C0();                                                                                                                          // 0C0
		virtual void         Unk_C1();                                                                                                                          // 0C1
		virtual void         Unk_C2();                                                                                                                          // 0C2
		virtual void         Unk_C3();                                                                                                                          // 0C3
		virtual void         Unk_C4();                                                                                                                          // 0C4
		virtual void         Unk_C5();                                                                                                                          // 0C5
		virtual void         Unk_C6();                                                                                                                          // 0C6
		virtual void         Unk_C7();                                                                                                                          // 0C7
		virtual void         Unk_C8();                                                                                                                          // 0C8
		virtual void         Unk_C9();                                                                                                                          // 0C9
		virtual void         Unk_CA();                                                                                                                          // 0CA
		virtual void         Unk_CB();                                                                                                                          // 0CB
		virtual void         Unk_CC();                                                                                                                          // 0CC
		virtual void         Unk_CD();                                                                                                                          // 0CD
		virtual void         Unk_CE();                                                                                                                          // 0CE
		virtual void         Unk_CF();                                                                                                                          // 0CF
		virtual void         Unk_D0();                                                                                                                          // 0D0
		virtual void         Unk_D1();                                                                                                                          // 0D1
		virtual void         Unk_D2();                                                                                                                          // 0D2
		virtual void         Unk_D3();                                                                                                                          // 0D3
		virtual void         Unk_D4();                                                                                                                          // 0D4
		virtual void         Unk_D5();                                                                                                                          // 0D5
		virtual void         Unk_D6();                                                                                                                          // 0D6
		virtual void         Unk_D7();                                                                                                                          // 0D7
		virtual void         Unk_D8();                                                                                                                          // 0D8
		virtual void         Unk_D9();                                                                                                                          // 0D9
		virtual void         Unk_DA();                                                                                                                          // 0DA
		virtual void         Unk_DB();                                                                                                                          // 0DB
		virtual void         Unk_DC();                                                                                                                          // 0DC
		virtual void         Unk_DD();                                                                                                                          // 0DD
		virtual void         Unk_DE();                                                                                                                          // 0DE
		virtual void         Unk_DF();                                                                                                                          // 0DF
		virtual void         Unk_E0();                                                                                                                          // 0E0
		virtual void         Unk_E1();                                                                                                                          // 0E1
		virtual void         Unk_E2();                                                                                                                          // 0E2
		virtual void         Unk_E3();                                                                                                                          // 0E3
		virtual void         Unk_E4();                                                                                                                          // 0E4
		virtual void         Unk_E5();                                                                                                                          // 0E5
		virtual void         Unk_E6();                                                                                                                          // 0E6
		virtual void         Unk_E7();                                                                                                                          // 0E7
		virtual void         Unk_E8();                                                                                                                          // 0E8
		virtual void         Unk_E9();                                                                                                                          // 0E9
		virtual void         Unk_EA();                                                                                                                          // 0EA
		virtual void         Unk_EB();                                                                                                                          // 0EB
		virtual void         Unk_EC();                                                                                                                          // 0EC
		virtual void         Unk_ED();                                                                                                                          // 0ED
		virtual void         Unk_EE();                                                                                                                          // 0EE
		virtual void         Unk_EF();                                                                                                                          // 0EF
		virtual void         Unk_F0();                                                                                                                          // 0F0
		virtual void         Unk_F1();                                                                                                                          // 0F1
		virtual void         Unk_F2();                                                                                                                          // 0F2
		virtual void         Unk_F3();                                                                                                                          // 0F3
		virtual void         Unk_F4();                                                                                                                          // 0F4
		virtual void         Unk_F5();                                                                                                                          // 0F5
		virtual void         Unk_F6();                                                                                                                          // 0F6
		virtual void         Unk_F7();                                                                                                                          // 0F7
		virtual void         Unk_F8();                                                                                                                          // 0F8
		virtual void         Unk_F9();                                                                                                                          // 0F9
		virtual void         Unk_FA();                                                                                                                          // 0FA
		virtual void         Unk_FB();                                                                                                                          // 0FB
		virtual void         Unk_FC();                                                                                                                          // 0FC
		virtual void         Unk_FD();                                                                                                                          // 0FD
		virtual void         Unk_FE();                                                                                                                          // 0FE
		virtual void         Unk_FF();                                                                                                                          // 0FF
		virtual void         Unk_100();                                                                                                                         // 100
		virtual void         Unk_101();                                                                                                                         // 101
		virtual void         Unk_102();                                                                                                                         // 102
		virtual void         Unk_103();                                                                                                                         // 103
		virtual void         Unk_104();                                                                                                                         // 104
		virtual void         Unk_105();                                                                                                                         // 105
		virtual void         Unk_106();                                                                                                                         // 106
		virtual void         Unk_107();                                                                                                                         // 107
		virtual void         Unk_108();                                                                                                                         // 108
		virtual void         Unk_109();                                                                                                                         // 109
		virtual void         Unk_10A();                                                                                                                         // 10A
		virtual void         Unk_10B();                                                                                                                         // 10B
		virtual void         Unk_10C();                                                                                                                         // 10C
		virtual bool         IsDead(bool a_notEssential) const;                                                                                                 // 10D
		virtual bool         ProcessInWater(std::uint32_t a_bodyID, float a_waterHeight, float a_deltaTime);                                                    // 10E
		virtual void         Unk_10F();                                                                                                                         // 10F
		virtual void         Unk_110();                                                                                                                         // 110
		virtual void         Unk_111();                                                                                                                         // 111
		virtual void         Unk_112();                                                                                                                         // 112
		virtual void         Unk_113();                                                                                                                         // 113
		virtual void         Unk_114();                                                                                                                         // 114
		virtual void         Unk_115();                                                                                                                         // 115
		virtual void         Unk_116();                                                                                                                         // 116
		virtual void         Unk_117();                                                                                                                         // 117
		virtual void         Unk_118();                                                                                                                         // 118
		virtual void         Unk_119();                                                                                                                         // 119
		virtual void         Unk_11A();                                                                                                                         // 11A
		virtual void         Unk_11B();                                                                                                                         // 11B
		virtual void         Unk_11C();                                                                                                                         // 11C
		virtual void         Unk_11D();                                                                                                                         // 11D
		virtual void         Unk_11E();                                                                                                                         // 11E
		virtual void         Unk_11F();                                                                                                                         // 11F
		virtual void         Unk_120();                                                                                                                         // 120
		virtual void         Unk_121();                                                                                                                         // 121
		virtual void         Unk_122();                                                                                                                         // 122
		virtual void         Unk_123();                                                                                                                         // 123
		virtual void         Unk_124();                                                                                                                         // 124
		virtual void         Unk_125();                                                                                                                         // 125
		virtual void         Unk_126();                                                                                                                         // 126
		virtual void         Unk_127();                                                                                                                         // 127
		virtual void         Unk_128();                                                                                                                         // 128
		virtual void         Unk_129();                                                                                                                         // 129
		virtual void         Unk_12A();                                                                                                                         // 12A
		virtual void         Unk_12B();                                                                                                                         // 12B
		virtual void         Unk_12C();                                                                                                                         // 12C
		virtual void         Unk_12D();                                                                                                                         // 12D
		virtual void         Unk_12E();                                                                                                                         // 12E
		virtual void         Unk_12F();                                                                                                                         // 12F

		// the following should be inherited when decoded properly
		void* BSTransformDeltaEvent;               // 38
		void* IMovementProcessMessageInterface;    // 40
		void* IPostAnimationChannelUpdateFunctor;  // 48
		void* BSAnimationGraphEvent;               // 50
		void* BGSInventoryListEvent;               // 58
		void* IAnimationGraphManagerHolder;        // 60
		void* IKeywordFormBase;                    // 68
		void* ActorValueOwner;                     // 70
		void* ActorValueChangedEvent;              // 78

		// members
		std::uint32_t  unk80;          // 80
		std::uint32_t  unk84;          // 84
		std::uint64_t  unk88;          // 88
		std::uint64_t  unk90;          // 90
		std::uint32_t  unk98;          // 98
		std::uint8_t   pad9C[4];       // 9C
		OBJ_REFR       data;           // A0
		std::uint64_t  unkD0;          // D0
		std::uint64_t  unkD8;          // D8
		TESObjectCELL* parentCell;     // E0
		void*          loadedData;     // E8
		std::uint64_t  unkF0;          // F0
		std::uint64_t  extraDataList;  // F8
		std::uint64_t  unk100;         // 100
		std::int16_t   scale;          // 108
		std::uint8_t   unk10A;         // 10A
		std::uint8_t   unk10B;         // 10B

		MEMBER_FN_PREFIX(TESObjectREFR);
		DEFINE_MEMBER_FN(IsInSpaceship, bool, 0x02B3A8D4)
		DEFINE_MEMBER_FN(IsInSpace, bool, 0x01A0E208)
		DEFINE_MEMBER_FN(HasKeyword, bool, 0x0139EE28, BGSKeyword*);
	};
	static_assert(sizeof(TESObjectREFR) == 0x110);

	class Actor : public TESObjectREFR
	{
	public:
		~Actor() override;  // 00

		// add
		virtual void         Unk_130();                                     // 130
		virtual void         Unk_131();                                     // 131
		virtual void         Unk_132();                                     // 132
		virtual void         Unk_133();                                     // 133
		virtual void         Unk_134();                                     // 134
		virtual void         Unk_135();                                     // 135
		virtual void         Unk_136();                                     // 136
		virtual void         Unk_137();                                     // 137
		virtual void         Unk_138();                                     // 138
		virtual void         Unk_139();                                     // 139
		virtual void         Unk_13A();                                     // 13A
		virtual void         Unk_13B();                                     // 13B
		virtual void         Unk_13C();                                     // 13C
		virtual void         Unk_13D();                                     // 13D
		virtual void         Unk_13E();                                     // 13E
		virtual void         Update(float a_delta);                         // 13F
		virtual void         Unk_140();                                     // 140
		virtual void         Unk_141();                                     // 141
		virtual void         Unk_142();                                     // 142
		virtual void         Unk_143();                                     // 143
		virtual void         Unk_144();                                     // 144
		virtual void         Unk_145();                                     // 145
		virtual void         Unk_146();                                     // 146
		virtual void         Unk_147();                                     // 147
		virtual void         Unk_148();                                     // 148
		virtual void         Unk_149();                                     // 149
		virtual void         Unk_14A();                                     // 14A
		virtual void         Unk_14B();                                     // 14B
		virtual void         Unk_14C();                                     // 14C
		virtual void         Unk_14D();                                     // 14D
		virtual void         Unk_14E();                                     // 14E
		virtual void         Unk_14F();                                     // 14F
		virtual void         Unk_150();                                     // 150
		virtual void         Unk_151();                                     // 151
		virtual void         Unk_152();                                     // 152
		virtual void         Unk_153();                                     // 153
		virtual void         Unk_154();                                     // 154
		virtual void         Unk_155();                                     // 155
		virtual void         Unk_156();                                     // 156
		virtual void         Unk_157();                                     // 157
		virtual void         Unk_158();                                     // 158
		virtual void         Unk_159();                                     // 159
		virtual void         Unk_15A();                                     // 15A
		virtual void         Unk_15B();                                     // 15B
		virtual void         Unk_15C();                                     // 15C
		virtual void         Unk_15D();                                     // 15D
		virtual void         Unk_15E();                                     // 15E
		virtual void         Unk_15F();                                     // 15F
		virtual CombatGroup* GetCombatGroup();                              // 160
		virtual void         SetCombatGroup(CombatGroup* a_group);          // 161
		virtual bool         CheckValidTarget(TESObjectREFR& a_ref) const;  // 162
		virtual void         Unk_163();                                     // 163
		virtual void         Unk_164();                                     // 164
		virtual void         Unk_165();                                     // 165
		virtual void         Unk_166();                                     // 166
		virtual void         Unk_167();                                     // 167
		virtual void         Unk_168();                                     // 168
		virtual void         Unk_169();                                     // 169
		virtual void         Unk_16A();                                     // 16A
		virtual void         Unk_16B();                                     // 16B
		virtual bool         IsInCombat() const;                            // 16C
		virtual void         Unk_16D();                                     // 16D
		virtual void         Unk_16E();                                     // 16E
		virtual void         Unk_16F();                                     // 16F
		virtual void         SetLifeState(std::uint32_t a_state);           // 170
		virtual void         Unk_171();                                     // 171
		virtual void         Unk_172();                                     // 172
		virtual void         Unk_173();                                     // 173
		virtual void         Unk_174();                                     // 174
		virtual void         Unk_175();                                     // 175
		virtual void         Unk_176();                                     // 176
		virtual void         Unk_177();                                     // 177
		virtual void         Unk_178();                                     // 178
		virtual void         Unk_179();                                     // 179
		virtual void         Unk_17A();                                     // 17A
		virtual void         Unk_17B();                                     // 17B
		virtual void         Unk_17C();                                     // 17C
		virtual void         Unk_17D();                                     // 17D
		virtual void         Unk_17E();                                     // 17E
		virtual void         Unk_17F();                                     // 17F
		virtual void         Unk_180();                                     // 180
		virtual void         Unk_181();                                     // 181
		virtual void         Unk_182();                                     // 182
		virtual void         Unk_183();                                     // 183
		virtual void         Unk_184();                                     // 184
		virtual void         Unk_185();                                     // 185
		virtual void         Unk_186();                                     // 186
		virtual void         Unk_187();                                     // 187
		virtual void         Unk_188();                                     // 188
		virtual void         Unk_189();                                     // 189
		virtual void         Unk_18A();                                     // 18A
		virtual void         Unk_18B();                                     // 18B
		virtual void         Unk_18C();                                     // 18C
		virtual void         Unk_18D();                                     // 18D
		virtual void         Unk_18E();                                     // 18E
		virtual void         Unk_18F();                                     // 18F
		virtual void         Unk_190();                                     // 190
		virtual void         Unk_191();                                     // 191
		virtual void         Unk_192();                                     // 192
		virtual void         Unk_193();                                     // 193
		virtual void         Unk_194();                                     // 194
		virtual void         Unk_195();                                     // 195
		virtual void         Unk_196();                                     // 196
		virtual void         Unk_197();                                     // 197
		virtual void         Unk_198();                                     // 198
		virtual void         Unk_199();                                     // 199
		virtual void         Unk_19A();                                     // 19A
		virtual void         Unk_19B();                                     // 19B
		virtual void         Unk_19C();                                     // 19C
		virtual void         Unk_19D();                                     // 19D
		virtual void         Unk_19E();                                     // 19E
		virtual void         Unk_19F();                                     // 19F
		virtual void         Unk_1A0();                                     // 1A0
		virtual void         Unk_1A1();                                     // 1A1
	};

	class TESCamera
	{
	public:
		virtual ~TESCamera();

		// add
		virtual void SetCameraRoot(NiNode* a_cameraRoot);  // 01
		virtual void SetEnabled(bool a_enabled);           // 02
		virtual void Update();                             // 03
		virtual void Unk_04();                             // 04

		// members

		std::uint64_t unk08;        // 08
		void*         cameraState;  // 10 - smart ptr
	};

	using _LookupByEDID = TESForm* (*)(const char* a_edid);
	inline RelocAddr<_LookupByEDID> LookupByEDID(0x014D7F7C);

	using _ForceCameraState = void (*)(void* a_camera);
	inline RelocAddr<_ForceCameraState> ForceFirstPerson(0x0286A968);
	inline RelocAddr<_ForceCameraState> ForceThirdPerson(0x0286AA20);

	using _QCameraState = bool (*)(void* a_camera, std::uint32_t a_state);
	inline RelocAddr<_QCameraState> QCameraState(0x0286BF98);

	using _DebugNotification = void (*)(const char* text, const char* a_sound, bool, bool);
	inline RelocAddr<_DebugNotification> DebugNotification(0x02154878);

	inline RelocPtr<Actor*>     playerCharacter(0x05594D28);
	inline RelocPtr<TESCamera*> playerCamera(0x058F0B40);
}