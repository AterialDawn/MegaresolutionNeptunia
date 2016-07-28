#include "RenderInfo.h"
#include "Log.h"
#include <ostream>
#include <string>

using namespace std;

//Default is to do nothing if we can't find a config
float RenderInfo::o_w = 1920.0f;
float RenderInfo::o_h = 1080.0f;
float RenderInfo::u_w = 1920.0f;
float RenderInfo::u_h = 1080.0f;
float RenderInfo::u_wS = 1.0f;
float RenderInfo::u_hS = 1.0f;
float RenderInfo::bloom_s = 1.0f;

float RenderInfo::GetWidthScalar() {
	return u_wS;
}

float RenderInfo::GetHeightScalar() {
	return u_hS;
}

void RenderInfo::SetOriginalRenderSize(float originalWidth, float originalHeight) {
	o_w = originalWidth;
	o_h = originalHeight;

	stringstream sS;
	sS << "SetOriginalRenderSize W = " << o_w;
	sS << ", H = " << o_h;
	Logger::Log(sS.str());

	UpdateScalars();
}

void RenderInfo::SetUpscaledRenderSize(float upscaledWidth, float upscaledHeight) {
	u_w = upscaledWidth;
	u_h = upscaledHeight;

	stringstream sS;
	sS << "SetUpscaledRenderSize W = " << u_w;
	sS << ", H = " << u_h;
	Logger::Log(sS.str());

	UpdateScalars();
}

void RenderInfo::SetBloomTextureScalar(float newScalar) {
	bloom_s = newScalar;

	stringstream sS;
	sS << "SetBloomTextureScalar = " << bloom_s;
	Logger::Log(sS.str());
}

float RenderInfo::GetBloomScalar() {
	return bloom_s;
}

void RenderInfo::UpdateScalars() {
	u_wS = u_w / o_w;
	u_hS = u_h / o_h;

	stringstream sS;
	sS << "UpdateScalars WScalar = " << u_wS;
	sS << ", HScalar = " << u_hS;
	Logger::Log(sS.str());
}

float RenderInfo::GetRenderWidth() {
	return o_w;
}

float RenderInfo::GetRenderHeight() {
	return o_h;
}

float RenderInfo::GetUpscaledWidth() {
	return u_w;
}

float RenderInfo::GetUpscaledHeight() {
	return u_h;
}