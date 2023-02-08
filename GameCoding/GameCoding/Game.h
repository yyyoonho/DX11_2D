#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	void RenderBegin();
	void RenderEnd();

private:
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();
	void SetViewport();

private:
	void CreateGeometry();
	void CreateInputLayout();
	void CreateVS();
	void CreatePS();

	void LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);

private:
	HWND _hwnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// Device & SwapChain
	ComPtr<ID3D11Device> _device = nullptr;
	ComPtr<ID3D11DeviceContext> _deviceContext = nullptr;
	ComPtr<IDXGISwapChain> _swapChain = nullptr;

	/// RTV
	ComPtr<ID3D11RenderTargetView> _renderTargetView;

	// Misc
	D3D11_VIEWPORT _viewport = {0};
	float _clearColor[4] = { 0.5f, 0.5f, 0.5f,0.5f };

private:
	// Geometry
	vector<Vertex> _vertices;
	ComPtr<ID3D11Buffer> _vertexBuffer = nullptr;

	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;
	
	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _psBlob = nullptr;

};