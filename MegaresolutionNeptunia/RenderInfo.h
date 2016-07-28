#pragma once

class RenderInfo
{
public:
	static void SetOriginalRenderSize(float originalWidth, float originalHeight);
	static void SetUpscaledRenderSize(float upscaledWidth, float upscaledHeight);
	static void SetBloomTextureScalar(float newScalar);
	static float GetWidthScalar();
	static float GetHeightScalar();
	static float GetBloomScalar();
	static float GetRenderWidth();
	static float GetRenderHeight();
	static float GetUpscaledWidth();
	static float GetUpscaledHeight();

private:
	RenderInfo();

	static void UpdateScalars();

	//Original Width
	static float o_w;
	//Original Height
	static float o_h;
	//Upscaled Width
	static float u_w;
	//Upscaled Height
	static float u_h;
	//Upscaled Width Scalar (u_w / o_w)
	static float u_wS;
	//Upscaled Height Scalar (u_h / o_h)
	static float u_hS;
	//Bloom texture scalar
	static float bloom_s;
};