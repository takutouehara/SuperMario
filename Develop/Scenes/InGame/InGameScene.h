#pragma once

#include "../SceneBase.h"

class InGameScene : SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Initialize() override;			// 初期化処理
	virtual eSceneType Update(float) override;	// 更新処理
	virtual void Draw() const override;			// 描画処理
	virtual void Finalize() override;			// 終了時処理

	virtual eSceneType GetNowSceneType() const override;	// 現在のシーンタイプを取得する

};