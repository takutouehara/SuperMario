#pragma once

#include "../SceneBase.h"

class ResultScene : SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene();

	virtual void Initialize() override;			// ����������
	virtual eSceneType Update(float) override;	// �X�V����
	virtual void Draw() const override;			// �`�揈��
	virtual void Finalize() override;			// �I��������

	virtual eSceneType GetNowSceneType() const override;	// ���݂̃V�[���^�C�v���擾����

};