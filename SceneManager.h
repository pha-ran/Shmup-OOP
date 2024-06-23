#pragma once

#include "BaseScene.h"
#include <new>

class SceneManager
{
public:
	static SceneManager& GetInstance(void) noexcept;

private:
	class SceneChanger
	{
	public:
		virtual void Change(BaseScene*& scene) noexcept = 0;
	};

	template <typename T>
	class SceneType : public SceneChanger
	{
	public:
		void Change(BaseScene*& scene) noexcept override
		{
			delete scene;
			scene = new(std::nothrow) T;
		}
	};

public:
	template <typename T>
	void LoadScene(void) noexcept
	{
		delete _changer;
		_changer = new(std::nothrow) SceneType<T>;
	}

public:
	void Update(void) noexcept;
	void Render(void) noexcept;

private:
	SceneManager(void) noexcept;

private:
	BaseScene* _scene;
	SceneChanger* _changer;

	static SceneManager _sceneManager;
};
