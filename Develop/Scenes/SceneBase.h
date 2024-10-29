#pragma once

#include "SceneFactory.h"
#include "../Freamworks/Vector2D.h"

/// <summary>
/// �V�[���^�C�v
/// </summary>
enum class eSceneType
{
	Title,
	InGame,
	Result,
	Exit,
};

/// <summary>
/// �V�[�����N���X
/// </summary>
class SceneBase
{
private:
	Vector2D screen_offset; //�X�N���[���I�t�Z�b�g

public:
	SceneBase() : 
		screen_offset(0.0f)
	{
		
	}
	virtual ~SceneBase()
	{
		Finalize();	// ����Y��h�~
	}

public:
	/// <summary>
	/// ����������
	/// </summary>
	virtual void Initialize()
	{

	}

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual eSceneType Update(float)
	{

	}

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw() const
	{

	}

	/// <summary>
	/// �I��������
	/// </summary>
	virtual void Finalize()
	{

	}

	/// <summary>
	/// ���݂̃V�[���^�C�v�擾����
	/// </summary>
	/// <returns>���݂̃V�[���^�C�v���</returns>
	virtual eSceneType GetNowSceneType() const
	{

	}
};