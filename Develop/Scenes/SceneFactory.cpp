#include "SceneFactory.h"
#include "SceneBase.h"

SceneBase* SceneFactory::CreateScene(eSceneType scene)
{
	switch (scene)
	{
	case eSceneType::Title:
		break;
	case eSceneType::InGame:
		break;
	case eSceneType::Result:
		break;
	case eSceneType::Exit:
		break;
	default:
		break;
	}
	return nullptr;
}