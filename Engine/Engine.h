#pragma once
class Engine
{
public:
	void Init(const struct WindowInfo& window);
	void Render();

	// 일감들을 큐에 넣음
	void RenderBegin();

	// 일감들을 그리는 방법
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);
private:

	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	shared_ptr<class Device> _device;
	shared_ptr<class CommandQueue> _cmdQueue;
	shared_ptr<class SwapChain> _swapChain;
	shared_ptr<class DescriptorHeap> _descHeap;
};

