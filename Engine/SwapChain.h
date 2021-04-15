#pragma once

// ��ȯ �罽
// [���� ����]
// ���� ���� ���� �ִ� ��Ȳ�� ����
// � �������� ��� ������� ������
// �������� ������ ���(����)
// ����� �޾Ƽ� ȭ�鿡 �׷��ش�.

// [���� �����]�� ��� ����?
// � ����(����)�� �׷��� �ǳ��޶�� ��Ź�غ���
// - Ư�� ���̸� ���� => ó���� �ǳ��ְ� => ������� �ش� ���̿� �޴´� OK
// Ư������(���� �����) ����� �ش�.

// [?]
// �׷��� ȭ�鿡 ���� ����� ����ϴ� ���߿�, ���� ȭ�鵵 ���ָ� �ðܾ� ��
// ���� ȭ�� ������� �̹� ȭ�� ��¿� �����
// Ư�� ���̸� 2�� ����, �ϳ��� ���� ȭ���� �׷��פ� �ϳ���, ���� �ñ��
// ���� ���۸�

// [1] ~ [2]
// ���� ȭ�� [1] ~ gpu �۾��� [2] back buffer
class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<ID3D12Device> device, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void Present();
	void SwapIndex();

	void CreateRTV(ComPtr<ID3D12Device> device);


	ComPtr<IDXGISwapChain> GetSwapChain() { return _swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return _rtvBuffer[index]; }

	ComPtr<ID3D12Resource> GetBackRTVBuffer() { return _rtvBuffer[_backBufferIndex]; }
	D3D12_CPU_DESCRIPTOR_HANDLE GetBackRTV() { return _rtvHandle[_backBufferIndex]; }

	void CreateSwapChain(const WindowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
private:
	ComPtr<IDXGISwapChain> _swapChain;
	ComPtr<ID3D12Resource> _rtvBuffer[SWAP_CHAIN_BUFFER_COUNT];

	ComPtr<ID3D12DescriptorHeap> _rtvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE _rtvHandle[SWAP_CHAIN_BUFFER_COUNT];

	uint32 _backBufferIndex = 0;
};

