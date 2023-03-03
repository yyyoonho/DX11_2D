#include "pch.h"
#include "Animation.h"
#include "Texture.h"

Animation::Animation() : Super(ResourceType::Animation)
{
}

Animation::~Animation()
{
}

void Animation::Load(const wstring& path)
{
	tinyxml2::XMLDocument doc;

	string pathStr(path.begin(), path.end());
	XMLError error = doc.LoadFile(pathStr.c_str());
	assert(error == XMLError::XML_SUCCESS);

	XMLElement* root = doc.FirstChildElement();
	string nameStr = root->Attribute("Name");
	_name = wstring(nameStr.begin(), nameStr.end());
	_loop = root->BoolAttribute("Loop");
	_path = path;

	// TODO : Load Texture

	
}

void Animation::Save(const wstring& path)
{
	tinyxml2::XMLDocument doc;

	XMLElement* root = doc.NewElement("Animation");
	doc.LinkEndChild(root);

	string nameStr(GetName().begin(), GetName().end());
	root->SetAttribute("Name", nameStr.c_str());
	root->SetAttribute("Loop", _loop);
	root->SetAttribute("TexturePath", "TODO");

	for (const auto& Keyframe : _keyframes)
	{
		XMLElement* node = doc.NewElement("Keyframe");
		root->LinkEndChild(node);

		node->SetAttribute("OffsetX", Keyframe.offset.x);
		node->SetAttribute("OffsetY", Keyframe.offset.y);
		node->SetAttribute("SizeX", Keyframe.Size.x);
		node->SetAttribute("SizeY", Keyframe.Size.y);
		node->SetAttribute("Time", Keyframe.time);
	}

	string pathStr(path.begin(), path.end());
	auto result = doc.SaveFile(pathStr.c_str());
	assert(result == XMLError::XML_SUCCESS);
}

Vec2 Animation::GetTextureSize()
{
	return _texture->GetSize();
}

const Keyframe& Animation::GetKeyframe(int32 index)
{
	return _keyframes[index];
}

int32 Animation::GetKeyframeCount()
{
	return static_cast<int32>(_keyframes.size());
}

void Animation::AddKeyframe(const Keyframe& keyframe)
{
	_keyframes.push_back(keyframe);
}
