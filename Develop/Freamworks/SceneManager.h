#pragma once

#include "../Scenes/SceneBase.h"
#include "../Scenes/SceneFactory.h"

class SceneManager
{
private:
	SceneBase* current_scene;	// 現在のシーン情報

public:
	SceneManager();
	~SceneManager();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name=""></param>
	void Update(float);

	/// <summary>
	/// 終了時処理
	/// </summary>
	void Finalize();

private:
	/// <summary>
	/// シーン切り替え処理
	/// </summary>
	/// <param name="">次のシーンタイプ</param>
	/// <returns></returns>
	bool ChangeScene(eSceneType next_type);

	/// <summary>
	/// 当たり判定確認処理
	/// </summary>
	void CheckCollisiton();
};

