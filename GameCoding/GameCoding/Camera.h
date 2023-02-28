#pragma once
#include "Component.h"

enum class ProjectionType
{
	Perspective, // ��������
	Orthographic, // ��������
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
	// ī�޶�� �ظ��ϸ� �ϳ��� ����� �� ���̱⿡
	// static���� view, projection ����� ���������.
	// (��𼭵� �����ϱ� ���ϰ�)
	static Matrix S_MatView;
	static Matrix S_MatProjection;
};

