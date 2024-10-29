#pragma once

#include "../Scenes/SceneBase.h"
#include "../Scenes/SceneFactory.h"

class SceneManager
{
private:
	SceneBase* current_scene;	// ���݂̃V�[�����

public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name=""></param>
	void Update(float);

	/// <summary>
	/// �I��������
	/// </summary>
	void Finalize();

private:
	/// <summary>
	/// �V�[���؂�ւ�����
	/// </summary>
	/// <param name="">���̃V�[���^�C�v</param>
	/// <returns></returns>
	bool ChangeScene(eSceneType next_type);

	/// <summary>
	/// �����蔻��m�F����
	/// </summary>
	void CheckCollisiton();
};

