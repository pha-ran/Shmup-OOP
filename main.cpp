#include "Delegate.h"
#include "Engine.h"

int main(void)
{
	Delegate delegate;
	delegate.Initialize();

	return Engine::GetInstance().Run();
}
