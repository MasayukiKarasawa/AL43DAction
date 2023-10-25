#include "Skydome.h"
#include "Vector3.h"
#include"ImGuiManager.h"
#include <cassert>
void Skydome::Initialize(Model* model) {
	// NULLポインタチェック
	assert(model);

	// メンバ変数に受け取った値を代入
	//textureHandle_ = textureHandle;
	model_ = model;

	// ワールド初期化
	worldTransform_.Initialize();
}

void Skydome::Update() { 
	worldTransform_.TransferMatrix();
}

void Skydome::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_,viewProjection); 
}
