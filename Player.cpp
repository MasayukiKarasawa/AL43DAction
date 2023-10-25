﻿#include "Player.h"
#include "Vector3.h"
#include"ImGuiManager.h"
#include <cassert>
void Player::Initialize(Model* model) { 
	//NULLポインタチェック
	assert(model); 

	//メンバ変数に受け取った値を代入
    //textureHandle_ = textureHandle;
	model_ = model;
	
	// ワールド初期化
	worldTransform_.Initialize();
}

void Player::Update() { 
	worldTransform_.TransferMatrix(); 
}

void Player::Draw(const ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection);
}
