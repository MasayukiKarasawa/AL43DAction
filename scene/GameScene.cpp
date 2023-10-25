#include "GameScene.h"
#include "TextureManager.h"
#include "MathUtilityForText.h"
#include<memory>
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	//delete modelSkydome_; 
}

void GameScene::Initialize() {
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
    //worldTransform_.Initialize();

	//ビュープロジェクション
	viewProjection_.farZ = 2000.0f;
	viewProjection_.translation_ = {0.0f, 2.0f, -10.0f};
	viewProjection_.Initialize();
	//テクスチャ読み込み
	textureHandle_ = TextureManager::Load("mario.jpg");
  
	//プレイヤー
	modelFighter_.reset(Model::CreateFromOBJ("float",true));
	player_ = std::make_unique<Player>();
	player_->Initialize(modelFighter_.get());
	//天球
	modelSkydome_.reset(Model::CreateFromOBJ("skydome", true));
	skydome_ = std::make_unique<Skydome>();
	skydome_->Initialize(modelSkydome_.get());
	// 地面
	modelGround_.reset(Model::CreateFromOBJ("ground", true));
	ground_ = std::make_unique<Ground>();
	ground_->Initialize(modelGround_.get());
}

void GameScene::Update() { 
	skydome_->Update();
	ground_->Update();
	player_->Update();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	
	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	player_->Draw(viewProjection_);
	skydome_->Draw(viewProjection_);
	ground_->Draw(viewProjection_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
