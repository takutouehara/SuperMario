#include "SceneManager.h"
#include "../Scenes/SceneBase.h"
#include "../Scenes/SceneFactory.h"
#include "DxLib.h"

SceneManager::SceneManager() : current_scene(nullptr)
{

}

SceneManager::~SceneManager()
{
	// ����Y��h�~
	Finalize();
}

/// <summary>
/// ����������
/// </summary>
void SceneManager::Initialize()
{
	// �E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(640, 480, 32);

	// �E�B���h�E�^�C�g���̐ݒ�
	SetWindowText("Super Mario");

	// �����������s��Ȃ�
	SetWaitVSyncFlag(FALSE);

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		throw("DX���C�u�������������ł��܂���ł����B\n");
	}

	// ����ʂ���`����͂��߂�
	SetDrawScreen(DX_SCREEN_BACK);

	// �C���Q�[����ʂ���V�[�����J�n����
	ChangeScene(eSceneType::Title);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name=""></param>
void SceneManager::Update(float)
{
	// �J�n���Ԃ��擾
	LONGLONG start_time = GetNowHiPerformanceCount();

	// ���͏����擾����
	InputManager* input = InputManager::GetInstance();

	// ���C�����[�v
	while (ProcessMessage() == -1)
	{
		// 1�t���[��������̎��Ԃ��v�Z����
		float delta_second = static_cast<float>(GetNowHiPerformanceCount() - start_time) * 0.000001f;
		
		// ���͏��̍X�V
		input->Update();

		// �V�[���̍X�V
		eSceneType next_scene_type = current_scene->Update(delta_second);

		// �Q�[�����I�����邩�m�F����
		if ((next_scene_type == eSceneType::Exit) ||
			(input->GetButtonUp(XINPUT_BUTTON_BACK)) ||
			(input->GetKeyUp(KEY_INPUT_ESCAPE)))
		{
			break;
		}

		// ���݂̃V�[���^�C�v�����̃V�[���^�C�v�ƈ���Ă��邩�H
		if (current_scene->GetNowSceneType() != next_scene_type)
		{
			// �V�[���؂�ւ�����
			ChangeScene(next_scene_type);
		}
	}
}

/// <summary>
/// �I��������
/// </summary>
void SceneManager::Finalize()
{
	// �V�[����񂪐�������Ă���΁A�폜����
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
		current_scene = nullptr;
	}

	// Singleton�̃C���X�^���X���������
	InputManager::DeleteInstance();
	ResourceManager::DeleteInstance();

	// Dx���C�u�����̎g�p���I������
	DxLib_End();
}

/// <summary>
/// �V�[���؂�ւ�����
/// </summary>
/// <param name=""></param>
/// <returns></returns>
bool SceneManager::ChangeScene(eSceneType next_type)
{
	// ���̃V�[���𐶐�����
	SceneFactory* next_scene = CreateScene(next_type);

	// �G���[�`�F�b�N
	if (next_scene == nullptr)
	{
		throw ("�V�[���������ł��܂���ł���\n");
	}

	// �V�[����񂪊i�[����Ă�����A�폜����
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	// ���̃V�[���̏�����
	next_scene->Initialize();

	// ���݃V�[���̏㏑��
	current_scene = next_scene;
}

/// <summary>
/// �����蔻��m�F
/// </summary>
void SceneManager::CheckCollisiton()
{
}
