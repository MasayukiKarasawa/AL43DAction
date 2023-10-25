#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"Player.h"
#include"Skydome.h"
#include"Ground.h"
#include <memory>
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
	//ワールドトランスフォーム
	//WorldTransform worldTransform_;
	
	/// <summary>
	/// ゲームシーン用
	/// </summary>
	
	// ビュープロジェクション
	ViewProjection viewProjection_;
	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	//モデル
	std::unique_ptr<Model> modelSkydome_;
	//モデル
	std::unique_ptr<Model> modelGround_;
	// モデル
	std::unique_ptr<Model> modelFighter_;
	// プレイヤー
	std::unique_ptr<Player> player_;
	// 地面
	std::unique_ptr<Ground> ground_;
	// 天球
	std::unique_ptr<Skydome> skydome_;
	

	/// 
	/// 
};
