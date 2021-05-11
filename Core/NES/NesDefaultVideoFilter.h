#pragma once

#include "stdafx.h"
#include "Shared/Video/BaseVideoFilter.h"
#include "NES/NesTypes.h"

class NesConsole;

class NesDefaultVideoFilter : public BaseVideoFilter
{
private:
	uint32_t _calculatedPalette[512] = {};
	VideoConfig _videoConfig = {};
	NesConfig _nesConfig = {};
	PpuModel _ppuModel = PpuModel::Ppu2C02;

	void InitLookupTable();

protected:
	void DecodePpuBuffer(uint16_t* ppuOutputBuffer, uint32_t* outputBuffer, bool displayScanlines);
	void OnBeforeApplyFilter();

public:
	NesDefaultVideoFilter(Emulator* emu);

	static void GenerateFullColorPalette(uint32_t paletteBuffer[512]);
	static void GetFullPalette(uint32_t palette[512], NesConfig& nesCfg, PpuModel model);

	void ApplyFilter(uint16_t* ppuOutputBuffer);
};