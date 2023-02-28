#pragma once
#include "Component.h"

enum class ProjectionType
{
	Perspective, // 원근투영
	Orthographic, // 직교투영
};

class Camera : public Component
{
	using Super = Component;
public:
	Camera();
	virtual ~Camera();

	virtual void Update() override;

	void SetProjectionType(ProjectionType type) { _type = type; }
	ProjectionType GetProjectionType() { return _type; }

	void UpdateMatrix();


private:
	ProjectionType _type = ProjectionType::Orthographic;

public:
	// 카메라는 왠만하면 하나만 만들어 줄 것이기에
	// static으로 view, projection 행렬을 만들어주자.
	// (어디서든 접근하기 편하게)
	static Matrix S_MatView;
	static Matrix S_MatProjection;
};

