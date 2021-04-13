#include "pch.h"
#include "EnginePch.h"
#include "Engine.h"

// 전역으로 만듬
unique_ptr<Engine> GEngine = make_unique<Engine>();