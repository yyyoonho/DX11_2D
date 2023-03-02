#pragma once
#include "ResourceBase.h"
class Shader :public ResourceBase
{
	using Super = ResourceBase;
public:
	Shader();
	virtual ~Shader();

	shared_ptr<VertexShader> GetVertexShader() { return _vertexShader; }
	shared_ptr<PixelShader> GetPixelShader() { return _pixelShader; }
	shared_ptr<InputLayout> GetInputLayout() { return _inputLayout; }

private:
	friend class ResourceManager;

	// Material
	shared_ptr<InputLayout> _inputLayout;
	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;
};

