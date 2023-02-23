
struct VS_INPUT
{
	float4 position : POSITION;
	float4 color : COLOR;
};
 
struct VS_OUTPUT
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

cbuffer TransformData : register(b0)
{
	//float4 offset;
	row_major matrix matWorld;
	row_major matrix matView;	
	row_major matrix matProjection;
}

// 정점 단위로 실행
VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output;

	// WVP
	float4 position = mul(input.position, matWorld); // W
	position = mul(position, matView); // V
	position = mul(position, matProjection); // P

	output.position = position;
	output.color = input.color;

	return output;
}

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);

// 픽셀 단위로 실행
float4 PS(VS_OUTPUT input) : SV_Target
{
	return input.color;
}