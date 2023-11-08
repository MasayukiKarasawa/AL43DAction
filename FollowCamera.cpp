#include "FollowCamera.h"
#include "MathUtilityForText.h"
#include"Input.h"
void FollowCamera::Initialize() 
{
	viewProjection_.farZ = 2000.0f;
	viewProjection_.Initialize();
}

void FollowCamera::Update() 
{ 
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		viewProjection_.rotation_.y += 0.03f;
	}
	if (target_) {
		Vector3 offset = {0.0f, 2.0f, -10.0f};

		Matrix4x4 matRotX = MakeRotateXMatrix(viewProjection_.rotation_.x);
		Matrix4x4 matRotY = MakeRotateYMatrix(viewProjection_.rotation_.y);
		Matrix4x4 matRotZ = MakeRotateZMatrix(viewProjection_.rotation_.z);

		Matrix4x4 matRot = matRotZ * matRotX * matRotY;
		offset = TransformNormal(offset, matRot);
		viewProjection_.translation_ = target_->translation_ + offset;
	}
	viewProjection_.UpdateViewMatrix();
}
