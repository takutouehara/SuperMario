#pragma once

#include "Vector2D.h"

// �}�N����`
#define	D_KEYCODE_MAX	(256)		// �L�[�{�[�h���͒l�ő吔
#define D_BUTTON_MAX	(16)		// �R���g���[���[�̓��̓{�^���ő吔

enum eInputState
{
	None,
	Pressed,
	Release,
	Held,
};

/// <summary>
/// ���͊Ǘ��N���X�iSingleton�j
/// </summary>
class InputManager
{
	// ���N���X�̃|�C���^�i���̂��A�h���X�̐�ŕۗL�j
	static InputManager* instance;

	// �L�[���͏��
	char now_key[D_KEYCODE_MAX];		// ���݂̓��͒l
	char old_key[D_KEYCODE_MAX];		// �O��̓��͒l

	// �R���g���[���[���͏��
	bool now_button[D_BUTTON_MAX];		// ���݂̃{�^�����͒l
	bool old_button[D_BUTTON_MAX];		// �O��̃{�^�����͒l
	float trigger[2];					// �g���K�[���͒l�i0.0f�`1.0f�j
	Vector2D stick[2];					// �X�e�B�b�N���͒l�i-1.0f�`1.0f�j

private:
	// �N���X�̎��̂������o�֐����ł��������ł��Ȃ��悤�ɂ���
	InputManager() = default;
	// �R�s�[�K�[�h
	InputManager(const InputManager& v) = delete;
	InputManager& operator = (const InputManager& v) = delete;
	// ~�R�s�[�K�[�h

public:
	~InputManager() = default;

public:
	/// <summary>
	/// �C���X�^���X�擾����
	/// </summary>
	/// <returns>�C���X�^���X�̃|�C���^��ԋp����</returns>
	static InputManager* GetInstance();

	/// <summary>
	/// �C���X�^���X�폜����
	/// </summary>
	static void DeleteInstance();

public:
	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	eInputState GetKeyState(int key_code) const;

	eInputState GetButtonState(int button) const;

	eInputState GetMouseButtonState(int mouse) const;

	float GetLeftTrigger() const;

	float GetRightTrigger() const;

	Vector2D& GetleftStick() const;

	Vector2D& GetRightStick() const;

private:
	bool CheckKeyCodeRange(int key_code) const;

	bool CheckButtonRange(int button) const;

	float TriggerNormalize(unsigned char value) const;

	float StickNormalize(unsigned char value) const;















};

