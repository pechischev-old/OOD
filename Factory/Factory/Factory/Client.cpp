#include "stdafx.h"
#include "Client.h"
#include "Designer.h"
#include "PictureDraft.h"
#include "Painter.h"

#include "Canvas.h"


CClient::CClient(std::unique_ptr<IPainter> && painter, std::unique_ptr<IDesigner> && designer)
	: m_pPainter(std::move(painter))
	, m_pDesigner(std::move(designer))
	, m_pCanvas(std::make_unique<CCanvas>(std::cout))
{
}


CClient::~CClient()
{
}

void CClient::MakePictureOrder()
{
	auto draft = m_pDesigner->CreateDraft(std::cin);
	m_pPainter->DrawPicture(draft, *m_pCanvas);
}
