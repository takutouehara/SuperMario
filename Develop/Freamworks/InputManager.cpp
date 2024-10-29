#include "InputManager.h"
#include "DxLib.h"

// 静的メンバ変数定義
InputManager* InputManager::instance = nullptr;

InputManager* InputManager::GetInstance()
{
	// インスタンスが生成されていない場合、生成する
	if (instance == nullptr)
	{
		instance = new InputManager();
	}

	// インスタンスのポインタを返却する
	return instance;
}

void InputManager::DeleteInstance()
{
	// インスタンスが存在している場合、削除する
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void InputManager::Update()
{
	// キー入力値の更新
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	GetHitKeyStateAll(now_key);

	// コントローラー入力値の更新
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
	// TODO: return ステートメントをここに挿入します
}

Vector2D& InputManager::GetRightStick() const
{
	// TODO: return ステートメントをここに挿入します
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
