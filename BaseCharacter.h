#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
class BaseCharacter {
public:
	virtual void Initialize(const std::vector<Model*>& models);
	virtual void Update();
	virtual void Draw(const ViewProjection& viewProjection);
	//ローカル座標の設定
	void SetLocalPosition(const Vector3& position);
	//ローカル角度の設定
	void SetLocalRotation(const Vector3& rotation);
	//ローカル座標の取得
	const Vector3& GetLocalPosition() const { return worldTransform_.translation_; }
	//ワールド変換データを取得
	const WorldTransform& GetWorldTransform() { return worldTransform_; }

protected:
	//モデルデータ配列
	std::vector<Model*> models_;
	//ワールド変換データ
	WorldTransform worldTransform_;

};
