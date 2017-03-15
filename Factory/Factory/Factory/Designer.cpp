#include "stdafx.h"
#include "Designer.h"


CDesigner::CDesigner(IShapeFactory & factory)
	: m_factory(factory)
{
}


CPictureDraft CDesigner::CreateDraft(std::istream & data)
{
	CPictureDraft draft;
	std::string inputString;
	while (std::getline(data, inputString))
	{
		auto shape = m_factory.CreateShape(inputString);
		draft.AddShape(shape);
	}
	return draft;
}
