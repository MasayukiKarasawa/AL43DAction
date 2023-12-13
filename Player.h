#pragma once
#include"BaseCharacter.h"
#include "Input.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"MathUtilityForText.h"
#include<optional>
#include <memory>
class Player : public BaseCharacter {
public:
	enum {
		kModelIndexBody,
		kModelIndexHead,
		kModelIndexL_arm,
		kModelIndexR_arm,
		kModelIndexHammer,
	};
	//振る舞い
	enum class Behavior {
		kRoot,//通常状態
		kAttack,//攻撃中
	};
	void Initialize(const std::vector<Model*>& models)override;
	void Update() override;
	void Draw(const ViewProjection& viewProjection)override;
	void SetViewProjection(const ViewProjection* viewProjection) {
		viewProjection_ = viewProjection;
	}
private:
	//浮遊移動のサイクル
	int32_t floatingCycle_ = 90;
	//浮遊振幅
	float floatingAmplitude_ = 0.2f;
	//待機モーションの腕角度最大値
	float idleArmAngleMax_ = 30.0f;
	//予備動作の時間＜frame＞
	const uint32_t anticipationTime_ = 15;
	//ための時間＜frame＞
	const uint32_t chargeTime_ = 10;
	//ワールド変換データ
	WorldTransform worldTransformBody_;
	WorldTransform worldTransformHead_;
	WorldTransform worldTransformL_arm_;
	WorldTransform worldTransformR_arm_;
	WorldTransform worldTransformHammer_;
	//浮遊ギミックの媒介変数
	float floatingParameter_ = 0.0f;
	//攻撃ギミックの媒介変数
	float attackParameter_ = 0;
	//カメラのビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;
	//行動
	Behavior behavior_ = Behavior::kRoot;
	//行動リクエスト
	std::optional<Behavior> behaviorRequest_ = std::nullopt;
	//浮遊ギミック更新
	void UpdateFloatingGimmick();
	//通常ギミック更新
	void UpdateRootGimmick();
	//攻撃ギミック更新
	void UpdateAttackGimmick();
	//通常行動初期化
	void BehaviorRootInitialize();
	//通常行動更新
	void BehaviorRootUpdate();
	//攻撃行動初期化
	void BehaviorAttackInitialize();
	//攻撃行動更新
	void BehaviorAttackUpdate();
	//近接武器描画
	void DrawMeleeWeapon(const ViewProjection& viewProjection);
   
	
	
	//モデル
	Model* modelBody_ = nullptr;
	Model* modelHead_ = nullptr;
	Model* modelL_arm_ = nullptr;
	Model* modelR_arm_ = nullptr;
	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	//入力
	Input* input_ = nullptr;
};
