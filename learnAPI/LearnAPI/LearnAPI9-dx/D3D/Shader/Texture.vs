// GLOBALS
cbuffer MatrixBuffer
{
 matrix worldMatrix;
 matrix viewMatrix;
 matrix projectionMatrix;
};



// TYPEDEFS 
struct VertexInputType
{
 float4 position : POSITION;
 float2 tex : TEXCOORD0;
};


struct PixelInputType
{
 float4 position : SV_POSITION;
 float2 tex : TEXCOORD0;
};



// Vertex Shader 
PixelInputType TextureVertexShader(VertexInputType input)
{
 PixelInputType output;

 // 적절한 행렬 계산을 위해 위치 벡터를 4 단위로 변경하십시오.
 input.position.w = 1.0f;

 // 월드, 뷰 및 프로젝션 행렬에 대한 정점의 위치 계산.
 output.position = mul(input.position, worldMatrix);
 output.position = mul(output.position, viewMatrix);
 output.position = mul(output.position, projectionMatrix);

 // 픽셀 쉐이더의 텍스처 좌표를 저장한다.
 output.tex = input.tex;
 return output;
}
//=============================================================================================
