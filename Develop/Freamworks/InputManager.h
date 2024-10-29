#pragma once

#include "Vector2D.h"

// マクロ定義
#define	D_KEYCODE_MAX	(256)		// キーボード入力値最大数
#define D_BUTTON_MAX	(16)		// コントローラーの入力ボタン最大数

enum eInputState
{
	None,
	Pressed,
	Release,
	Held,
};

/// <summary>
/// 入力管理クラス（Singleton）
/// </summary>
class InputManager
{
	// 自クラスのポインタ（実体をアドレスの先で保有）
	static InputManager* instance;

	// キー入力情報
	char now_key[D_KEYCODE_MAX];		// 現在の入力値
	char old_key[D_KEYCODE_MAX];		// 前回の入力値

	// コントローラー入力情報
	bool now_button[D_BUTTON_MAX];		// 現在のボタン入力値
	bool old_button[D_BUTTON_MAX];		// 前回のボタン入力値
	float trigger[2];					// トリガー入力値（0.0f～1.0f）
	Vector2D stick[2];					// スティック入力値（-1.0f～1.0f）

private:
	// クラスの実体をメンバ関数内でしか生成できないようにする
	InputManager() = default;
	// コピーガード
	InputManager(const InputManager& v) = delete;
	InputManager& operator = (const InputManager& v) = delete;
	// ~コピーガード

public:
	~InputManager() = default;

public:
	/// <summary>
	/// インスタンス取得処理
	/// </summary>
	/// <returns>インスタンスのポインタを返却する</returns>
	static InputManager* GetInstance();

	/// <summary>
	/// インスタンス削除処理
	/// </summary>
	static void DeleteInstance();

public:
	/// <summary>
	/// 更新処理
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

