#include "pch.h"
#include "Device.h"

void Device::Init()
{
#ifdef _DEBUG
	// 추가 정보 정보를 할 수 있음
	::D3D12GetDebugInterface(IID_PPV_ARGS(&_debugController));
	_debugController->EnableDebugLayer();
#endif

	// DXGI(DirectX Graphics Infrastructure)
	// Direct3D와 함께 쓰이는 API
	// 전체 화면 모드 전환
	// 지원되는 디스플레이 모드 열거
	// CREATE
	::CreateDXGIFactory(IID_PPV_ARGS(&_dxgi));

	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&_device));
}