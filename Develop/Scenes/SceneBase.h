#pragma once

#include "SceneFactory.h"
#include "../Freamworks/Vector2D.h"

/// <summary>
/// シーンタイプ
/// </summary>
enum class eSceneType
{
	Title,
	InGame,
	Result,
	Exit,
};

/// <summary>
/// シーン基底クラス
/// </summary>
class SceneBase
{
private:
	Vector2D screen_offset; //スクリーンオフセット

public:
	SceneBase() : 
		screen_offset(0.0f)
	{
		
	}
	virtual ~SceneBase()
	{
		Finalize();	// 解放忘れ防止
	}

public:
	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize()
	{

	}

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual eSceneType Update(float)
	{

	}

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() const
	{

	}

	/// <summary>
	/// 終了時処理
	/// </summary>
	virtual void Finalize()
	{

	}

	/// <summary>
	/// 現在のシーンタイプ取得処理
	/// </summary>
	/// <returns>現在のシーンタイプ情報</returns>
	virtual eSceneType GetNowSceneType() const
	{

	}
};