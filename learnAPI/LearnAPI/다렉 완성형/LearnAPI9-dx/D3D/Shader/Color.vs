/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
 matrix worldMatrix;
 matrix viewMatrix;
 matrix projectionMatrix;
};


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float4 color : COLOR;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};


////////////////////////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////////////////////////
PixelInputType ColorVertexShader(VertexInputType input)
{
    PixelInputType output;
    

 // Change the position vector to be 4 units for proper matrix calculations.
 // 적절한 행렬 계산을 위해 위치 벡터를 4단위로 변경하십시오.
    input.position.w = 1.0f;

 // Calculate the position of the vertex against the world, view, and projection matrices.
 // 월드 뷰에 대한
    output.position = mul(input.position, worldMatrix);
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);
    
 // Store the input color for the pixel shader to use.
    output.color = input.color;
    
    return output;
}