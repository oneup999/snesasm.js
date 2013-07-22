#ifndef SNESCPU_OP_H
#define SNESCPU_OP_H

#include <stdint.h>

#define OP_ADC				1
#define OP_AND				2
#define OP_ASL				3
#define OP_BCC				4
#define OP_BCS				5
#define OP_BEQ				6
#define OP_BNE				7
#define OP_BMI				8
#define OP_BPL				9
#define OP_BVC				10
#define OP_BVS				11
#define OP_BRA				12
#define OP_BRL				13
#define OP_BIT				14
#define OP_BRK				15
#define OP_CLC				16
#define OP_CLD				17
#define OP_CLI				18
#define OP_CLV				19
#define OP_SEC				20
#define OP_SED				21
#define OP_SEI				22
#define OP_CMP				23
#define OP_COP				24
#define OP_CPX				25
#define OP_CPY				26
#define OP_DEC				27
#define OP_DEX				28
#define OP_DEY				29
#define OP_EOR				30
#define OP_INC				31
#define OP_INX				32
#define OP_INY				33
#define OP_JMP				34
#define OP_JSR				35
#define OP_LDA				36
#define OP_LDX				37
#define OP_LDY				38
#define OP_LSR				39
#define OP_MVP				40
#define OP_MVN				41
#define OP_NOP				42
#define OP_ORA				43
#define OP_PEA				44
#define OP_PEI				45
#define OP_PER				46
#define OP_PHA				47
#define OP_PHP				48
#define OP_PHX				49
#define OP_PHY				50
#define OP_PLA				51
#define OP_PLP				52
#define OP_PLX				53
#define OP_PLY				54
#define OP_PHB				55
#define OP_PHD				56
#define OP_PHK				57
#define OP_PLB				58
#define OP_PLD				59
#define OP_REP				60
#define OP_ROL				61
#define OP_ROR				62
#define OP_RTI				63
#define OP_RTL				64
#define OP_RTS				65
#define OP_SBC				66
#define OP_SEP				67
#define OP_STA				68
#define OP_STP				69
#define OP_STX				70
#define OP_STY				71
#define OP_STZ				72
#define OP_TAX				73
#define OP_TXA				74
#define OP_TAY				75
#define OP_TYA				76
#define OP_TSX				77
#define OP_TXS				78
#define OP_TCD				79
#define OP_TDC				80
#define OP_TCS				81
#define OP_TSC				82
#define OP_TRB				83
#define OP_TSB				84
#define OP_TXY				85
#define OP_TYX				86
#define OP_WAI				87
#define OP_WDM				88
#define OP_XBA				89
#define OP_XCE				90

#define AM_IMM				1
#define AM_ABS				2
#define AM_ABS_LONG			3
#define AM_DP				4
#define AM_DP_IND			5
#define AM_DP_IND_LONG		6
#define AM_ABS_X			7
#define AM_ABS_LONG_X		8
#define AM_ABS_Y			9
#define AM_DP_X				10
#define AM_DP_IND_X			11
#define AM_DP_Y				12
#define AM_DP_IND_Y			13
#define AM_DP_IND_LONG_Y	14
#define AM_SR				15
#define AM_SR_IND_Y			16
#define AM_A				17
#define AM_PC_REL			18
#define AM_PC_REL_LONG		19
#define AM_NONE				20
#define AM_ABS_IND			21
#define AM_ABS_IND_X		22
#define AM_ABS_IND_LONG		23
#define AM_BANKS			24

struct snescpu_op {
	uint8_t op;
	uint8_t am;
	uint8_t cycles;
};

struct snescpu_op snescpu_op_table[] = {
	//00
	{OP_BRK,	AM_NONE,			7},
	{OP_ORA,	AM_DP_IND_X,		6},
	{OP_COP,	AM_NONE,			7},
	{OP_ORA,	AM_SR,				4},
	{OP_TSB,	AM_DP,				5},
	{OP_ORA,	AM_DP,				3},
	{OP_ASL,	AM_DP,				5},
	{OP_ORA,	AM_DP_IND_LONG,		6},

	//08
	{OP_PHP,	AM_NONE,			3},
	{OP_ORA,	AM_IMM,				2},
	{OP_ASL,	AM_A,				2},
	{OP_PHD,	AM_NONE,			4},
	{OP_TSB,	AM_ABS,				6},
	{OP_ORA,	AM_ABS,				4},
	{OP_ASL,	AM_ABS,				6},
	{OP_ORA,	AM_ABS_LONG,		5},

	//10
	{OP_BPL,	AM_PC_REL,			2},
	{OP_ORA,	AM_DP_IND_Y,		5},
	{OP_ORA,	AM_DP_IND,			5},
	{OP_ORA,	AM_SR_IND_Y,		7},
	{OP_TRB,	AM_DP,				5},
	{OP_ORA,	AM_DP_X,			4},
	{OP_ASL,	AM_ABS_X,			6},
	{OP_ORA,	AM_DP_IND_LONG_Y,	6},

	//18
	{OP_CLC,	AM_NONE,			2},
	{OP_ORA,	AM_ABS_Y,			4},
	{OP_INC,	AM_A,				2},
	{OP_TCS,	AM_NONE,			2},
	{OP_TRB,	AM_ABS,				6},
	{OP_ORA,	AM_ABS_X,			4},
	{OP_ASL,	AM_ABS_X,			7},
	{OP_ORA,	AM_ABS_LONG_X,		5},

	//20
	{OP_JSR,	AM_ABS,				6},
	{OP_AND,	AM_DP_IND_X,		6},
	{OP_JSR,	AM_ABS_LONG,		8},
	{OP_AND,	AM_SR,				4},
	{OP_BIT,	AM_DP,				3},
	{OP_AND,	AM_DP,				3},
	{OP_ROL,	AM_DP,				5},
	{OP_AND,	AM_DP_IND_LONG,		6},

	//28
	{OP_PLP,	AM_NONE,			4},
	{OP_AND,	AM_IMM,				2},
	{OP_ROL,	AM_A,				2},
	{OP_PLD,	AM_NONE,			5},
	{OP_BIT,	AM_ABS,				4},
	{OP_AND,	AM_ABS,				4},
	{OP_ROL,	AM_ABS,				6},
	{OP_AND,	AM_ABS_LONG,		5},

	//30
	{OP_BMI,	AM_PC_REL,			2},
	{OP_AND,	AM_DP_IND_Y,		5},
	{OP_AND,	AM_DP_IND,			5},
	{OP_AND,	AM_SR_IND_Y,		7},
	{OP_BIT,	AM_DP_X,			4},
	{OP_AND,	AM_DP_X,			4},
	{OP_ROL,	AM_DP_X,			6},
	{OP_AND,	AM_DP_IND_LONG_Y,	6},

	//38
	{OP_SEC,	AM_NONE,			2},
	{OP_AND,	AM_ABS_Y,			4},
	{OP_DEC,	AM_A,				2},
	{OP_TSC,	AM_NONE,			2},
	{OP_BIT,	AM_ABS_X,			4},
	{OP_AND,	AM_ABS_X,			4},
	{OP_ROL,	AM_ABS_X,			7},
	{OP_AND,	AM_ABS_LONG_X,		5},

	//40
	{OP_RTI,	AM_NONE,			6},
	{OP_EOR,	AM_DP_IND_X,		6},
	{OP_WDM,	AM_NONE,			2},	//guessing at 2
	{OP_EOR,	AM_SR,				4},
	{OP_MVP,	AM_BANKS,			7},
	{OP_EOR,	AM_DP,				3},
	{OP_LSR,	AM_DP,				5},
	{OP_EOR,	AM_DP_IND_LONG,		6},

	//48
	{OP_PHA,	AM_NONE,			3},
	{OP_EOR,	AM_IMM,				2},
	{OP_LSR,	AM_A,				2},
	{OP_PHK,	AM_NONE,			3},
	{OP_JMP,	AM_ABS,				3},
	{OP_EOR,	AM_ABS,				4},
	{OP_LSR,	AM_ABS,				6},
	{OP_EOR,	AM_ABS_LONG,		5},

	//50
	{OP_BVC,	AM_PC_REL,			2},
	{OP_EOR,	AM_DP_IND_Y,		5},
	{OP_EOR,	AM_DP_IND,			5},
	{OP_EOR,	AM_SR_IND_Y,		7},
	{OP_MVN,	AM_BANKS,			7},
	{OP_EOR,	AM_DP_X,			4},
	{OP_LSR,	AM_DP_X,			6},
	{OP_EOR,	AM_DP_IND_LONG_Y,	6},

	//58
	{OP_CLI,	AM_NONE,			2},
	{OP_EOR,	AM_ABS_Y,			4},
	{OP_PHY,	AM_NONE,			3},
	{OP_TCD,	AM_NONE,			2},
	{OP_JMP,	AM_ABS_LONG,		4},
	{OP_EOR,	AM_ABS_X,			4},
	{OP_LSR,	AM_ABS_X,			7},
	{OP_EOR,	AM_ABS_LONG_X,		5},

	//60
	{OP_RTS,	AM_NONE,			6},
	{OP_ADC,	AM_DP_IND_X,		6},
	{OP_PER,	AM_PC_REL_LONG,		6},
	{OP_ADC,	AM_SR,				4},
	{OP_STZ,	AM_DP,				3},
	{OP_ADC,	AM_DP,				3},
	{OP_ROR,	AM_DP,				5},
	{OP_ADC,	AM_DP_IND_LONG,		6},

	//68
	{OP_PLA,	AM_NONE,			4},
	{OP_ADC,	AM_IMM,				2},
	{OP_ROR,	AM_A,				2},
	{OP_RTL,	AM_NONE,			6},
	{OP_JMP,	AM_ABS_IND,			5},
	{OP_ADC,	AM_ABS,				3},
	{OP_ROR,	AM_ABS,				6},
	{OP_ADC,	AM_ABS_LONG,		5},

	//70
	{OP_BVS,	AM_PC_REL,			2},
	{OP_ADC,	AM_DP_IND_Y,		5},
	{OP_ADC,	AM_DP_IND,			5},
	{OP_ADC,	AM_SR_IND_Y,		7},
	{OP_STZ,	AM_DP_X,			4},
	{OP_ADC,	AM_DP_X,			4},
	{OP_ROR,	AM_DP_X,			6},
	{OP_ADC,	AM_DP_IND_LONG_Y,	6},

	//78
	{OP_SEI,	AM_NONE,			2},
	{OP_ADC,	AM_ABS_Y,			4},
	{OP_PLY,	AM_NONE,			4},
	{OP_TDC,	AM_NONE,			2},
	{OP_JMP,	AM_ABS_IND_X,		6},
	{OP_ADC,	AM_ABS_X,			4},
	{OP_ROR,	AM_ABS_X,			7},
	{OP_ADC,	AM_ABS_LONG_X,		5},

	//80
	{OP_BRA,	AM_PC_REL,			3},
	{OP_STA,	AM_DP_IND_X,		6},
	{OP_BRL,	AM_PC_REL_LONG,		4},
	{OP_STA,	AM_SR,				4},
	{OP_STY,	AM_DP,				3},
	{OP_STA,	AM_DP,				3},
	{OP_STX,	AM_DP,				3},
	{OP_STA,	AM_DP_IND_LONG,		6},

	//88
	{OP_DEY,	AM_NONE,			2},
	{OP_BIT,	AM_IMM,				2},
	{OP_TXA,	AM_NONE,			2},
	{OP_PHB,	AM_NONE,			3},
	{OP_STY,	AM_ABS,				4},
	{OP_STA,	AM_ABS,				4},
	{OP_STX,	AM_ABS,				4},
	{OP_STA,	AM_ABS_LONG,		5},

	//90
	{OP_BCC,	AM_PC_REL,			2},
	{OP_STA,	AM_DP_IND_Y,		6},
	{OP_STA,	AM_DP_IND,			5},
	{OP_STA,	AM_SR_IND_Y,		7},
	{OP_STY,	AM_DP_X,			4},
	{OP_STA,	AM_DP_X,			4},
	{OP_STX,	AM_DP_Y,			4},
	{OP_STA,	AM_DP_IND_LONG_Y,	6},

	//98
	{OP_TYA,	AM_NONE,			2},
	{OP_STA,	AM_ABS_Y,			5},
	{OP_TXS,	AM_NONE,			2},
	{OP_TXY,	AM_NONE,			2},
	{OP_STZ,	AM_ABS,				4},
	{OP_STA,	AM_ABS_X,			5},
	{OP_STZ,	AM_ABS_X,			5},
	{OP_STA,	AM_ABS_LONG_X,		5},

	//a0
	{OP_LDY,	AM_IMM,				2},
	{OP_LDA,	AM_DP_IND_X,		6},
	{OP_LDX,	AM_IMM,				2},
	{OP_LDA,	AM_SR,				4},
	{OP_LDY,	AM_DP,				3},
	{OP_LDA,	AM_DP,				3},
	{OP_LDX,	AM_DP,				3},
	{OP_LDA,	AM_DP_IND_LONG,		6},

	//a8
	{OP_TAY,	AM_NONE,			2},
	{OP_LDA,	AM_IMM,				2},
	{OP_TAX,	AM_NONE,			2},
	{OP_PLB,	AM_NONE,			4},
	{OP_LDY,	AM_ABS,				4},
	{OP_LDA,	AM_ABS,				4},
	{OP_LDX,	AM_ABS,				4},
	{OP_LDA,	AM_ABS_LONG,		5},

	//b0
	{OP_BCS,	AM_PC_REL,			2},
	{OP_LDA,	AM_DP_IND_Y,		5},
	{OP_LDA,	AM_DP_IND,			5},
	{OP_LDA,	AM_SR_IND_Y,		7},
	{OP_LDY,	AM_DP_X,			4},
	{OP_LDA,	AM_DP_X,			4},
	{OP_LDX,	AM_DP_Y,			4},
	{OP_LDA,	AM_DP_IND_LONG_Y,	6},

	//b8
	{OP_CLV,	AM_NONE,			2},
	{OP_LDA,	AM_ABS_Y,			4},
	{OP_TSX,	AM_NONE,			2},
	{OP_TYX,	AM_NONE,			2},
	{OP_LDY,	AM_ABS_X,			4},
	{OP_LDA,	AM_ABS_X,			4},
	{OP_LDX,	AM_ABS_Y,			4},
	{OP_LDA,	AM_ABS_LONG_X,		5},

	//c0
	{OP_CPY,	AM_IMM,				2},
	{},
	{OP_REP,	AM_IMM,				3},
	{OP_CMP,	AM_SR,				4},
	{OP_CPY,	AM_DP,				3},
	{OP_CMP,	AM_DP,				3},
	{OP_DEC,	AM_DP,				5},
	{OP_CMP,	AM_DP_IND_LONG,		6},

	//c8
	{OP_INY,	AM_NONE,			2},
	{OP_CMP,	AM_IMM,				2},
	{OP_DEX,	AM_NONE,			2},
	{OP_WAI,	AM_NONE,			3},
	{OP_CPY,	AM_ABS,				4},
	{OP_CMP,	AM_ABS,				4},
	{OP_DEC,	AM_ABS,				6},
	{OP_CMP,	AM_ABS_LONG,		5},

	//d0
	{OP_BNE,	AM_PC_REL,			2},
	{OP_CMP,	AM_DP_IND_Y,		5},
	{OP_CMP,	AM_DP_IND,			5},
	{OP_CMP,	AM_SR_IND_Y,		7},
	{OP_PEI,	AM_DP_IND,			6},
	{OP_CMP,	AM_DP_IND_X,		4},
	{OP_DEC,	AM_DP_X,			6},
	{OP_CMP,	AM_DP_IND_LONG_Y,	6},

	//d8
	{OP_CLD,	AM_NONE,			2},
	{OP_CMP,	AM_ABS_Y,			4},
	{OP_PHX,	AM_NONE,			3},
	{OP_STP,	AM_NONE,			3},
	{OP_JMP,	AM_ABS_IND_LONG,	6},
	{OP_CMP,	AM_ABS_X,			4},
	{OP_DEC,	AM_ABS_X,			7},
	{OP_CMP,	AM_ABS_LONG_X,		7},

	//e0
	{OP_CPX,	AM_IMM,				2},
	{OP_SBC,	AM_DP_IND_X,		6},
	{OP_SEP,	AM_IMM,				3},
	{OP_SBC,	AM_SR,				4},
	{OP_CPX,	AM_DP,				3},
	{OP_SBC,	AM_DP,				3},
	{OP_INC,	AM_DP,				5},
	{OP_SBC,	AM_DP_IND_LONG,		6},

	//e8
	{OP_INX,	AM_NONE,			2},
	{OP_SBC,	AM_IMM,				2},
	{OP_NOP,	AM_NONE,			2},
	{OP_XBA,	AM_NONE,			3},
	{OP_CPX,	AM_ABS,				4},
	{OP_SBC,	AM_ABS,				4},
	{OP_INC,	AM_ABS,				6},
	{OP_SBC,	AM_ABS_LONG,		5},

	//f0
	{OP_BEQ,	AM_PC_REL,			2},
	{OP_SBC,	AM_DP_IND_Y,		5},
	{OP_SBC,	AM_DP_IND,			5},
	{OP_SBC,	AM_SR_IND_Y,		7},
	{OP_PEA,	AM_ABS,				5},
	{OP_SBC,	AM_DP_X,			4},
	{OP_INC,	AM_DP_X,			6},
	{OP_SBC,	AM_DP_IND_LONG_Y,	6},

	//f8
	{OP_SED,	AM_NONE,			2},
	{OP_SBC,	AM_ABS_Y,			4},
	{OP_PLX,	AM_NONE,			4},
	{OP_XCE,	AM_NONE,			2},
	{OP_JSR,	AM_ABS_IND_X,		8},
	{OP_SBC,	AM_ABS_X,			4},
	{OP_INC,	AM_ABS_X,			7},
	{OP_SBC,	AM_ABS_LONG_X,		5}
};





#endif
