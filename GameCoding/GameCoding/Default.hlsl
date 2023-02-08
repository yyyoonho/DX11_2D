
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

// 정점 단위로 실행
VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output;
	output.position = input.position;
	output.color = input.color;

	return output;
}

// 픽셀 단위로 실행
float4 PS(VS_OUTPUT input) : SV_Target
{

	return input.color;
}