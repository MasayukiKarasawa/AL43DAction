#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"MathUtilityForText.h"
#include <memory>
class Player {
private:
	//浮遊移動のサイクル
	int32_t floatingCycle_ = 90;
	//浮遊振幅
	float floatingAmplitude_ = 0.2f;
	//待機モーションの腕角度最大値
	float idleArmAngleMax_ = 30.0f;

	//ワールド変換データ
	WorldTransform worldTransformBase_;
	WorldTransform worldTransformBody_;
	WorldTransform worldTransformHead_;
	WorldTransform worldTransformL_arm_;
	WorldTransform worldTransformR_arm_;
	//浮遊ギミックの媒介変数
	float floatingParameter_ = 0.0f;
	//モデル
	Model* modelBody_ = nullptr;
	Model* modelHead_ = nullptr;
	Model* modelL_arm_ = nullptr;
	Model* modelR_arm_ = nullptr;
	//カメラのビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;
	//ギミック初期化
	void InitializeFloatingGimmick();
	//ギミック更新
	void UpdateFloatingGimmick();

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	//入力
	Input* input_ = nullptr;
	

public:
	void Initialize(Model* modelBody,Model* modelHead,Model* modelL_arm,Model* modelR_arm);
	void Update();
	void Draw(const ViewProjection& viewProjection);
	const WorldTransform& GetWorldTransform() { return worldTransformBase_; }
	void SetViewProjection(const ViewProjection* viewProjection) {
		viewProjection_ = viewProjection;
	}
};
