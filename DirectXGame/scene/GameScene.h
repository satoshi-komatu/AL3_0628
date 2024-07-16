#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "Player.h"
#include "MapChipField.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DebugCamera.h"
#include "Skydome.h"


#include <vector>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	ViewProjection viewProjection_;

	uint32_t textureHandle_ = 0u;

	Player* player_ = nullptr;


	Sprite sprite_;
	bool isDebugCameraActive_ = false;
	DebugCamera* debugCamera_ = nullptr;
	Matrix4x4 cameraMarix_;
	Model* modelPlayer_ = nullptr;
	Model* modelBlock_ = nullptr;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
	Model* modelSkydome_ = nullptr;
	Skydome* skydome_ = nullptr;
	WorldTransform worldTransform_;
	MapChipField* mapChipField_;

	void GenerateBlocks();
};
