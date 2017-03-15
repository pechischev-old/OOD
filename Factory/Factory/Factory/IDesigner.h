#pragma once
#include <istream>
#include <memory>
#include "PictureDraft.h"

class IDesigner
{
public:
	virtual CPictureDraft CreateDraft(std::istream &data) = 0;
};