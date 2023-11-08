#include "Player.h"
#include "Vector3.h"
#include"ImGuiManager.h"
#include "MathUtilityForText.h"
#include"Input.h"
#include <cassert>
void Player::Initialize(Model* model) { 
	//NULLポインタチェック
	assert(model); 

	//メンバ変数に受け取った値を代入
    //textureHandle_ = textureHandle;
	model_ = model;
	
	// ワールド初期化
	worldTransform_.Initialize();
	//インプット
	input_ = Input::GetInstance();
}

void Player::Update() { 
	
	const float speed=0.3f;
	Vector3 move = {0.0f, 0.0f, 0.0f};
	if (input_->PushKey(DIK_RIGHT)) {
		move.x = 1.0f;
	}
	if (Input::GetInstance()->PushKey(DIK_LEFT)) {
		move.x = -1.0f;
	}
	if (Input::GetInstance()->PushKey(DIK_UP)) {
		move.z = 1.0f;
	}
	if (Input::GetInstance()->PushKey(DIK_DOWN)) {
		move.z = -1.0f;
	}
	move = Normalize(move) * speed;
	if (viewProjection_) {
		Matrix4x4 matRotX = MakeRotateXMatrix(viewProjection_->rotation_.x);
		Matrix4x4 matRotY = MakeRotateYMatrix(viewProjection_->rotation_.y);
		Matrix4x4 matRotZ = MakeRotateZMatrix(viewProjection_->rotation_.z);
	
		Matrix4x4 matRot = matRotZ * matRotX * matRotY;
		move = TransformNormal(move, matRot);

	}
	worldTransform_.translation_ += move;
	worldTransform_.rotation_.y = std::atan2(move.x, move.z);

	worldTransform_.matWorld_ = MakeAffineMatrix(
	    worldTransform_.scale_, 
		worldTransform_.rotation_, 
		worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Player::Draw(const ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection);
}

