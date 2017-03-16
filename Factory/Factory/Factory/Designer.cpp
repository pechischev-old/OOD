#include "stdafx.h"
#include "Designer.h"
#include "PictureDraft.h"
#include <exception>


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
		try
		{
			auto stringStream = std::istringstream(inputString);
			auto shape = m_factory.CreateShape(stringStream);
			draft.AddShape(std::move(shape));
		}
		catch (std::exception & error)
		{
			std::cerr << error.what() << std::endl;
		}
	}
	return draft;
}
