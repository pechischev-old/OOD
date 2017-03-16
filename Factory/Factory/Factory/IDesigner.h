#pragma once
#include <istream>
#include <memory>

class CPictureDraft;

struct IDesigner
{
	virtual CPictureDraft CreateDraft(std::istream &data) = 0;
	virtual ~IDesigner() = default;
};