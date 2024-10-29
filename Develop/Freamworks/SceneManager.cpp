#include "SceneManager.h"
#include "../Scenes/SceneBase.h"
#include "../Scenes/SceneFactory.h"
#include "DxLib.h"

SceneManager::SceneManager() : current_scene(nullptr)
{

}

SceneManager::~SceneManager()
{
	// 解放忘れ防止
	Finalize();
}

/// <summary>
/// 初期化処理
/// </summary>
void SceneManager::Initialize()
{
	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// 画面サイズの設定
	SetGraphMode(640, 480, 32);

	// ウィンドウタイトルの設定
	SetWindowText("Super Mario");

	// 垂直同期を行わない
	SetWaitVSyncFlag(FALSE);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		throw("DXライブラリが初期化できませんでした。\n");
	}

	// 裏画面から描画をはじめる
	SetDrawScreen(DX_SCREEN_BACK);

	// インゲーム画面からシーンを開始する
	ChangeScene(eSceneType::Title);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name=""></param>
void SceneManager::Update(float)
{
	// 開始時間を取得
	LONGLONG start_time = GetNowHiPerformanceCount();

	// 入力情報を取得する
	InputManager* input = InputManager::GetInstance();

	// メインループ
	while (ProcessMessage() == -1)
	{
		// 1フレーム当たりの時間を計算する
		float delta_second = static_cast<float>(GetNowHiPerformanceCount() - start_time) * 0.000001f;
		
		// 入力情報の更新
		input->Update();

		// シーンの更新
		eSceneType next_scene_type = current_scene->Update(delta_second);

		// ゲームを終了するか確認する
		if ((next_scene_type == eSceneType::Exit) ||
			(input->GetButtonUp(XINPUT_BUTTON_BACK)) ||
			(input->GetKeyUp(KEY_INPUT_ESCAPE)))
		{
			break;
		}

		// 現在のシーンタイプが次のシーンタイプと違っているか？
		if (current_scene->GetNowSceneType() != next_scene_type)
		{
			// シーン切り替え処理
			ChangeScene(next_scene_type);
		}
	}
}

/// <summary>
/// 終了時処理
/// </summary>
void SceneManager::Finalize()
{
	// シーン情報が生成されていれば、削除する
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
		current_scene = nullptr;
	}

	// Singletonのインスタンスを解放する
	InputManager::DeleteInstance();
	ResourceManager::DeleteInstance();

	// Dxライブラリの使用を終了する
	DxLib_End();
}

/// <summary>
/// シーン切り替え処理
/// </summary>
/// <param name=""></param>
/// <returns></returns>
bool SceneManager::ChangeScene(eSceneType next_type)
{
	// 次のシーンを生成する
	SceneFactory* next_scene = CreateScene(next_type);

	// エラーチェック
	if (next_scene == nullptr)
	{
		throw ("シーンが生成できませんでした\n");
	}

	// シーン情報が格納されていたら、削除する
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	// 次のシーンの初期化
	next_scene->Initialize();

	// 現在シーンの上書き
	current_scene = next_scene;
}

/// <summary>
/// 当たり判定確認
/// </summary>
void SceneManager::CheckCollisiton()
{
}
