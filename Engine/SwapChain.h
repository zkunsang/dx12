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
	void Init(const WindowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
	void Present();
	void SwapIndex();

	ComPtr<IDXGISwapChain> GetSwapChain() { return _swapChain; }
	ComPtr<ID3D12Resource> GetRenderTarget(int32 index) { return _renderTargets[index]; }

	uint32 GetCurrentBackBufferIndex() {
		return _backBufferIndex;
	}

	ComPtr<ID3D12Resource> GetCurrentBackBufferResource() { return _renderTargets[_backBufferIndex]; }
private:
	ComPtr<IDXGISwapChain> _swapChain;
	ComPtr<ID3D12Resource> _renderTargets[SWAP_CHAIN_BUFFER_COUNT];
	uint32 _backBufferIndex = 0;
};

