#include "InputManager.h"
#include "DxLib.h"

// �ÓI�����o�ϐ���`
InputManager* InputManager::instance = nullptr;

InputManager* InputManager::GetInstance()
{
	// �C���X�^���X����������Ă��Ȃ��ꍇ�A��������
	if (instance == nullptr)
	{
		instance = new InputManager();
	}

	// �C���X�^���X�̃|�C���^��ԋp����
	return instance;
}

void InputManager::DeleteInstance()
{
	// �C���X�^���X�����݂��Ă���ꍇ�A�폜����
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputManager::Update()
{
	// �L�[���͒l�̍X�V
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	GetHitKeyStateAll(now_key);

	// �R���g���[���[���͒l�̍X�V
	XINPUT_STATE input = {};
	GetJoypadXInputState(DX_INPUT_PAD1, &input);
	for (int i = 0; i < D_BUTTON_MAX; i++)
	{
		old_button[i] = now_button[i];
		now_button[i] = static_cast<bool>(input.Buttons[i]);
	}
	trigger[0] = TriggerNormalize(input.LeftTrigger);
	trigger[1] = TriggerNormalize(input.RightTrigger);
	stick[0].x = StickNormalize(input.ThumbLX);
	stick[0].y = StickNormalize(input.ThumbLY);
	stick[1].x = StickNormalize(input.ThumbRX);
	stick[1].y = StickNormalize(input.ThumbRY);
}

eInputState InputManager::GetKeyState(int key_code) const
{
	return eInputState();
}

eInputState InputManager::GetButtonState(int button) const
{
	return eInputState();
}

eInputState InputManager::GetMouseButtonState(int mouse) const
{
	return eInputState();
}

float InputManager::GetLeftTrigger() const
{
	return 0.0f;
}

float InputManager::GetRightTrigger() const
{
	return 0.0f;
}

Vector2D& InputManager::GetleftStick() const
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}

Vector2D& InputManager::GetRightStick() const
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}

bool InputManager::CheckKeyCodeRange(int key_code) const
{
	return false;
}

bool InputManager::CheckButtonRange(int button) const
{
	return false;
}

float InputManager::TriggerNormalize(unsigned char value) const
{
	return 0.0f;
}

float InputManager::StickNormalize(unsigned char value) const
{
	return 0.0f;
}
