#pragma once

#include "BaseScene.h"

class SceneManager
{
public:
	static SceneManager& GetInstance(void) noexcept;

private:
	class SceneChanger
	{
	public:
		virtual void Change(void) noexcept = 0;
	};

	template <typename T>
	class SceneType : public SceneChanger
	{
	public:
		void Change(void) noexcept override
		{
			delete _scene;
			_scene = new T;

			_changer = nullptr;
			delete this;
		}
	};

public:
	template <typename T>
	void LoadScene(void) noexcept
	{
		delete _changer;
		_changer = new SceneType<T>;
	}

public:
	void Update(void) noexcept;
	void Render(void) noexcept;

private:
	SceneManager() noexcept;

private:
	BaseScene* _scene;
	SceneChanger* _changer;

	static SceneManager _sceneManager;
};
