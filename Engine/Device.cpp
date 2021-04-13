#include "pch.h"
#include "Device.h"

void Device::Init()
{
#ifdef _DEBUG
	// �߰� ���� ������ �� �� ����
	::D3D12GetDebugInterface(IID_PPV_ARGS(&_debugController));
	_debugController->EnableDebugLayer();
#endif

	// DXGI(DirectX Graphics Infrastructure)
	// Direct3D�� �Բ� ���̴� API
	// ��ü ȭ�� ��� ��ȯ
	// �����Ǵ� ���÷��� ��� ����
	// CREATE
	::CreateDXGIFactory(IID_PPV_ARGS(&_dxgi));

	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&_device));
}