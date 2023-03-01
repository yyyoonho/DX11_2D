
struct VS_INPUT
{
	float4 position : POSITION;
	float2 uv : TEXCOORD;
};
 
struct VS_OUTPUT
{
	float4 position : SV_POSITION;
	float2 uv : TEXCOORD;
};

cbuffer CameraData : register(b0)
{
	row_major matrix matView;	
	row_major matrix matProjection;
}

cbuffer TransformData : register(b1)
{
	//float4 offset;
	row_major matrix matWorld;
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
	output.uv = input.uv;

	return output;
}

Texture2D texture0 : register(t0);
SamplerState sampler0 : register(s0);

// 픽셀 단위로 실행
float4 PS(VS_OUTPUT input) : SV_Target
{
	float4 color = texture0.Sample(sampler0,input.uv);

	return color;
}